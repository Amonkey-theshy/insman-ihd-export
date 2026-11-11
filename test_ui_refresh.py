import tempfile
import threading
import time
import unittest
from datetime import datetime, timedelta
from pathlib import Path
from unittest.mock import patch

import export_data_core2 as core
import insman_gui as gui


class ExportRefreshTests(unittest.TestCase):
    def test_interpolation_matches_linear_scan_with_duplicates_and_unordered_targets(self):
        base = datetime(2026, 1, 1)
        times = [base + timedelta(seconds=s) for s in (0, 2, 2, 5, 10)]
        values = [1., 3., 8., 4., 9.]
        targets = [base + timedelta(seconds=s) for s in (6, -1, 2, 3, 0, 11, 1)]
        expected = []
        for target in targets:
            if target <= times[0]:
                expected.append(values[0])
            elif target >= times[-1]:
                expected.append(values[-1])
            else:
                for i in range(len(times) - 1):
                    if times[i] <= target <= times[i + 1]:
                        expected.append(core.linear_interpolation(times[i], values[i], times[i + 1], values[i + 1], target))
                        break
        self.assertEqual(core.interpolate_data(times, values, targets), expected)

    def test_cancel_cleans_temporary_file_and_preserves_existing_export(self):
        event = threading.Event()
        base = datetime(2026, 1, 1)
        with tempfile.TemporaryDirectory() as directory:
            target = Path(directory) / 'TEST_20260101_0000_20260101_0003.csv'
            target.write_bytes(b'previous export')
            def query(tag, start, end, *args):
                return [{'Tag名': tag, '时间戳': str(start), '数据质量': 'Good', '数据值': '1'}]
            def progress(done, total, message):
                if done == 1:
                    event.set()
            with patch.object(core, 'build_interpolated_rows', query):
                result = core.export_by_day_with_30min_chunks_parallel('TEST', base, base + timedelta(minutes=3), chunk_minutes=1, max_workers=1, output_dir=directory, cancel_event=event, progress_func=progress, log_func=lambda _: None)
            self.assertIsNone(result)
            self.assertEqual(target.read_bytes(), b'previous export')
            self.assertFalse(list(Path(directory).glob('*.tmp')))

    def test_cancel_waits_for_running_sdk_call_before_returning(self):
        event, started, release = threading.Event(), threading.Event(), threading.Event()
        result = []
        def query(*args):
            started.set()
            release.wait(3)
            return []
        base = datetime(2026, 1, 1)
        with tempfile.TemporaryDirectory() as directory, patch.object(core, 'build_interpolated_rows', query):
            thread = threading.Thread(target=lambda: result.append(core.export_by_day_with_30min_chunks_parallel('TEST', base, base + timedelta(minutes=1), output_dir=directory, cancel_event=event, log_func=lambda _: None)))
            thread.start()
            try:
                self.assertTrue(started.wait(2))
                event.set()
                thread.join(.15)
                self.assertTrue(thread.is_alive())
            finally:
                release.set()
                thread.join(3)
            self.assertEqual(result, [None])
            self.assertFalse(list(Path(directory).iterdir()))

    def test_query_timeout_is_reported_instead_of_spinning(self):
        base = datetime(2026, 1, 1)
        logs = []
        with tempfile.TemporaryDirectory() as directory, patch.object(core, 'build_interpolated_rows', side_effect=TimeoutError('SDK timeout')):
            self.assertIsNone(core.export_by_day_with_30min_chunks_parallel('TEST', base, base + timedelta(minutes=1), output_dir=directory, log_func=logs.append))
        self.assertTrue(any('SDK timeout' in entry for entry in logs))

    def test_mailbox_is_bounded_and_preserves_completion_and_latest_progress(self):
        box = gui.ExportMailbox(capacity=50)
        for index in range(10000):
            box.put(('log', str(index)))
            box.put(('progress', index))
        box.put(('done', 'success'))
        logs, latest, done, dropped, pending = box.drain(20)
        self.assertEqual(len(logs), 20)
        self.assertEqual(dropped, 9950)
        self.assertEqual(latest['progress'], 9999)
        self.assertIsNone(done)
        logs, latest, done, dropped, pending = box.drain(100)
        self.assertEqual(logs[-1], '9999')
        self.assertEqual(done, 'success')
        self.assertFalse(pending)


class GuiRefreshTests(unittest.TestCase):
    def setUp(self):
        self.config_patch = patch.object(gui, 'load_config', return_value={"ihd_password": "offline-test-only"})
        self.config_patch.start()
        self.app = gui.INSMANApp()
        self.app.withdraw()
        self.app.update_idletasks()

    def tearDown(self):
        self.app.after_cancel(self.app._poll_id)
        self.app.after_cancel(self.app._clock_id)
        self.app.destroy()
        self.config_patch.stop()

    def test_log_retention_and_user_scroll_position(self):
        self.app.append_logs([f'[OK] line {i}\n' for i in range(2000)])
        self.assertLessEqual(int(self.app.log_text.index('end-1c').split('.')[0]), gui.MAX_LOG_LINES)
        self.assertNotIn('line 0\n', self.app.log_text.get('1.0', 'end'))
        self.assertEqual(str(self.app.log_text['state']), 'disabled')

    def test_invalid_range_is_rejected_before_start(self):
        self.app.vars['start_time'].set('2026-01-01 12:00:00')
        self.app.vars['end_time'].set('2026-01-01 11:00:00')
        with self.assertRaisesRegex(ValueError, '结束时间'):
            self.app.get_form_config()
        self.assertFalse(self.app.running)

    def test_async_export_updates_ui_without_database(self):
        with tempfile.TemporaryDirectory() as directory:
            self.app.vars['start_time'].set('2026-01-01 00:00:00')
            self.app.vars['end_time'].set('2026-01-01 00:01:00')
            self.app.vars['output_dir'].set(directory)
            def source(tag, start, end):
                time.sleep(.03)
                return [str(start), str(end)], [1., 9.]
            with patch.object(gui, 'save_config'), patch.object(core, 'get_ihd_datas_with_time', source):
                self.app.start_export()
                self.assertTrue(self.app.running)
                deadline = time.monotonic() + 4
                while self.app.running and time.monotonic() < deadline:
                    self.app.update()
                    time.sleep(.005)
            self.assertFalse(self.app.running)
            self.assertEqual(self.app.status_var.get(), '已完成')
            self.assertEqual(self.app.progress_var.get(), 100)
            self.assertEqual(self.app.current_rows, 61)
            self.assertTrue(Path(self.app.output_file).exists())
            self.assertFalse(self.app.export_button.instate(['disabled']))


if __name__ == '__main__':
    unittest.main()
