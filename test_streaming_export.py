import csv
import importlib.util
import tempfile
import threading
import unittest
from datetime import datetime, timedelta
from pathlib import Path
from unittest.mock import patch
import export_data_core2 as core


class StreamingExportTests(unittest.TestCase):
    # 模拟 SDK 数据，验证真实插值和 CSV 输出，不连接现场数据库。
    start = datetime(2026, 9, 20)

    def run_export(self, directory, **kwargs):
        options = dict(tag_name='TEST', start_time=self.start,
                       end_time=self.start + timedelta(minutes=12),
                       chunk_minutes=1, interval_seconds=7, max_workers=2,
                       output_dir=directory, log_func=lambda message: None)
        options.update(kwargs)
        return core.export_by_day_with_30min_chunks_parallel(**options)

    @staticmethod
    def source(tag, start, end):
        return ([start.strftime('%Y-%m-%d %H:%M:%S'), end.strftime('%Y-%m-%d %H:%M:%S')], [1.0, 9.0])

    def test_output_matches_existing_algorithm(self):
        # 包括不能整除分段时长的间隔，确保此次优化不改变采样规则。
        with tempfile.TemporaryDirectory() as directory, patch.object(core, 'get_ihd_datas_with_time', self.source):
            for interval in (1, 7, 60):
                expected = []
                for start, end in core.split_time_chunks(self.start, self.start + timedelta(minutes=12), 1):
                    for row in core.build_interpolated_rows('TEST', start, end, interval, 'float'):
                        if not expected or row['时间戳'] != expected[-1]['时间戳']:
                            expected.append(row)
                events = []
                path = self.run_export(directory, interval_seconds=interval,
                                       progress_func=lambda *args: events.append(args))
                with open(path, encoding='utf-8-sig', newline='') as file:
                    self.assertEqual(list(csv.DictReader(file)), expected)
                self.assertTrue(all(done < total for done, total, _ in events[:-1]))
                self.assertEqual(events[-1][0], events[-1][1])

    def test_slow_first_chunk_bounds_window_and_streams(self):
        release = threading.Event()
        window_full = threading.Event()
        lock = threading.Lock()
        started = []
        checks = []
        def query(tag, start, end, *args):
            index = int((start - self.start).total_seconds() / 60)
            with lock:
                started.append(index)
                if len(started) == 4:
                    window_full.set()
            if index == 0:
                self.assertTrue(release.wait(5))
            return [{'Tag名': tag, '时间戳': str(start), '数据质量': 'Good', '数据值': '1'}]
        with tempfile.TemporaryDirectory() as directory, patch.object(core, 'build_interpolated_rows', query):
            def progress(done, total, text):
                if done == 1:
                    files = list(Path(directory).glob('*.tmp'))
                    checks.append(len(files) == 1 and files[0].stat().st_size > 0)
                    checks.append(not list(Path(directory).glob('*.csv')))
            result = []
            worker = threading.Thread(target=lambda: result.append(self.run_export(directory, progress_func=progress)))
            worker.start()
            try:
                self.assertTrue(window_full.wait(5))
                # 第一段阻塞时只提交四段，不因后续段完成继续扩大缓存。
                self.assertEqual(sorted(started), [0, 1, 2, 3])
            finally:
                release.set()
                worker.join(10)
            self.assertFalse(worker.is_alive())
            self.assertTrue(result[0])
            self.assertEqual(checks, [True, True])

    def test_failures_preserve_existing_file_and_clean_temp(self):
        with tempfile.TemporaryDirectory() as directory:
            target = Path(directory) / 'TEST_20260920_0000_20260920_0012.csv'
            target.write_bytes(b'original')
            for failure in ('query', 'replace', 'empty'):
                with patch.object(core, 'get_ihd_datas_with_time', self.source):
                    if failure == 'query':
                        context = patch.object(core, 'build_interpolated_rows', side_effect=RuntimeError('query failed'))
                    elif failure == 'replace':
                        context = patch.object(core.os, 'replace', side_effect=OSError('file locked'))
                    else:
                        context = patch.object(core, 'build_interpolated_rows', return_value=[])
                    with context:
                        self.assertIsNone(self.run_export(directory))
                self.assertEqual(target.read_bytes(), b'original')
                self.assertFalse(list(Path(directory).glob('*.tmp')))

    def test_invalid_parameters_fail_before_query(self):
        with tempfile.TemporaryDirectory() as directory, patch.object(core, 'build_interpolated_rows') as query:
            for name in ('chunk_minutes', 'interval_seconds', 'max_workers'):
                for value in (0, -1):
                    self.assertIsNone(self.run_export(directory, **{name: value}))
            query.assert_not_called()


if __name__ == '__main__':
    unittest.main()
