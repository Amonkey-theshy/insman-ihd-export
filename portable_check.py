"""Check a portable installation without connecting to an iHD server."""
import argparse
import csv
import json
import platform
import sys
import tempfile
from datetime import datetime, timedelta
from pathlib import Path


def run_self_test(app_class, arguments):
    parser = argparse.ArgumentParser(description="Check the portable runtime offline")
    parser.add_argument("--self-test", action="store_true")
    parser.add_argument("--report", default="self_test_report.json")
    options = parser.parse_args(arguments)
    report = {"ok": False, "python": platform.python_version(),
              "architecture": platform.machine(), "frozen": bool(getattr(sys, "frozen", False)),
              "database_connected": False, "checks": {}}
    app = None
    try:
        app = app_class()
        app.withdraw()
        app.update()
        report["checks"]["tk_window"] = True
        from ihdSDK import hyperdb
        hyperdb.load_library()
        report["checks"]["sdk_load"] = True
        import export_data_core2 as core
        previous_query = core.get_ihd_datas_with_time
        try:
            def source(tag, start, end):
                return [str(start), str(end)], [1., 9.]
            core.get_ihd_datas_with_time = source
            with tempfile.TemporaryDirectory() as directory:
                start = datetime(2026, 1, 1)
                path = core.export_by_day_with_30min_chunks_parallel(
                    "PORTABLE_TEST", start, start + timedelta(minutes=2),
                    chunk_minutes=1, max_workers=2, output_dir=directory,
                    log_func=lambda message: None)
                if not path:
                    raise RuntimeError("Offline CSV export failed")
                with open(path, encoding="utf-8-sig", newline="") as exported:
                    rows = list(csv.DictReader(exported))
                if len(rows) != 121 or rows[0]["数据值"] != "1.000000" or rows[-1]["数据值"] != "9.000000":
                    raise RuntimeError("Unexpected offline export values")
                report["checks"]["offline_csv_export"] = True
                report["checks"]["exported_rows"] = len(rows)
        finally:
            core.get_ihd_datas_with_time = previous_query
        report["ok"] = True
    except Exception as exc:
        report["error"] = f"{type(exc).__name__}: {exc}"
    finally:
        if app is not None:
            app.destroy()
    Path(options.report).write_text(json.dumps(report, ensure_ascii=False, indent=2), encoding="utf-8")
    return 0 if report["ok"] else 1
