import json
import os
import sys
from datetime import datetime


APP_NAME = "INSMAN"


def prompt_text(label, default=None, required=True):
    while True:
        if default not in (None, ""):
            value = input(f"{label} [{default}]: ").strip()
            if not value:
                return default
        else:
            value = input(f"{label}: ").strip()

        if value or not required:
            return value
        print("该项不能为空，请重新输入。")


def prompt_int(label, default):
    while True:
        value = prompt_text(label, str(default), required=True)
        try:
            return int(value)
        except ValueError:
            print("请输入整数。")


def prompt_time(label, default=""):
    while True:
        value = prompt_text(label, default, required=True)
        try:
            return parse_datetime_input(value)
        except Exception as exc:
            print(exc)


def setup_console_encoding():
    try:
        sys.stdout.reconfigure(encoding="utf-8")
        sys.stderr.reconfigure(encoding="utf-8")
    except Exception:
        pass


def parse_datetime_input(value):
    for fmt in ("%Y-%m-%d %H:%M:%S", "%Y/%m/%d %H:%M:%S"):
        try:
            return datetime.strptime(value, fmt)
        except ValueError:
            pass
    raise ValueError("时间格式必须是 'YYYY-MM-DD HH:MM:SS' 或 'YYYY/MM/DD HH:MM:SS'")


def get_app_dir():
    if getattr(sys, "frozen", False):
        return os.path.dirname(sys.executable)
    return os.path.dirname(os.path.abspath(__file__))


def get_config_path():
    return os.path.join(get_app_dir(), "insman_config.json")


def load_config():
    config_path = get_config_path()
    if not os.path.exists(config_path):
        return {}
    try:
        with open(config_path, "r", encoding="utf-8") as config_file:
            data = json.load(config_file)
        if isinstance(data, dict):
            return data
    except Exception as exc:
        print(f"[WARN] 读取配置失败，将使用默认值: {exc}")
    return {}


def save_config(config):
    config_path = get_config_path()
    try:
        with open(config_path, "w", encoding="utf-8") as config_file:
            json.dump(config, config_file, ensure_ascii=False, indent=2)
        print(f"[INFO] 已保存本次配置: {config_path}")
    except Exception as exc:
        print(f"[WARN] 保存配置失败: {exc}")


def config_value(config, key, env_key=None, default=""):
    if env_key and os.environ.get(env_key) not in (None, ""):
        return os.environ.get(env_key)
    return config.get(key, default)


def default_output_dir(config):
    configured = config.get("output_dir")
    if configured:
        return configured.replace("exported_excel", "exported_csv")
    return os.path.join(get_app_dir(), "exported_csv")


def main():
    setup_console_encoding()
    config = load_config()
    print("=" * 60)
    print(f"{APP_NAME} iHD 历史数据导出工具")
    print("=" * 60)
    print("时间格式支持：2026-06-29 09:00:00 或 2026/6/29 09:00:00")
    print(f"配置文件：{get_config_path()}")
    print()

    ihd_server = prompt_text("主 iHD 服务器 IP", config_value(config, "ihd_server", "IHD_SERVER", "127.0.0.1"))
    ihd_port = prompt_int("主 iHD 端口", int(config_value(config, "ihd_port", "IHD_PORT", "5673")))
    ihd_bak_server = prompt_text(
        "备 iHD 服务器 IP，可直接回车跳过",
        config_value(config, "ihd_bak_server", "IHD_BAK_SERVER", ""),
        required=False,
    )
    ihd_bak_port = 0
    if ihd_bak_server:
        ihd_bak_port = prompt_int("备 iHD 端口", int(config_value(config, "ihd_bak_port", "IHD_BAK_PORT", "5673")))

    ihd_username = prompt_text("用户名", config_value(config, "ihd_username", "IHD_USERNAME", "admin"))
    ihd_password = prompt_text("密码", config_value(config, "ihd_password", "IHD_PASSWORD", ""))

    tag_name = prompt_text("点名", config.get("tag_name", "EAF7_TNOS_WS_TP"))
    start_time = prompt_time("开始时间", config.get("start_time", ""))
    end_time = prompt_time("结束时间", config.get("end_time", ""))
    interval_seconds = prompt_int("插值间隔秒数", int(config.get("interval_seconds", 1)))
    chunk_minutes = prompt_int("每次查询分钟数", int(config.get("chunk_minutes", 20)))
    max_workers = prompt_int("并行查询线程数", int(config.get("max_workers", 4)))
    output_dir = prompt_text("导出目录", default_output_dir(config))

    os.environ["IHD_SERVER"] = ihd_server
    os.environ["IHD_PORT"] = str(ihd_port)
    os.environ["IHD_BAK_SERVER"] = ihd_bak_server
    os.environ["IHD_BAK_PORT"] = str(ihd_bak_port)
    os.environ["IHD_USERNAME"] = ihd_username
    os.environ["IHD_PASSWORD"] = ihd_password

    save_config({
        "ihd_server": ihd_server,
        "ihd_port": ihd_port,
        "ihd_bak_server": ihd_bak_server,
        "ihd_bak_port": ihd_bak_port,
        "ihd_username": ihd_username,
        "ihd_password": ihd_password,
        "tag_name": tag_name,
        "start_time": start_time.strftime("%Y-%m-%d %H:%M:%S"),
        "end_time": end_time.strftime("%Y-%m-%d %H:%M:%S"),
        "interval_seconds": interval_seconds,
        "chunk_minutes": chunk_minutes,
        "max_workers": max_workers,
        "output_dir": output_dir,
    })

    print()
    print("开始导出，请稍等...")
    print(f"主 iHD: {ihd_server}:{ihd_port}")
    if ihd_bak_server:
        print(f"备 iHD: {ihd_bak_server}:{ihd_bak_port}")
    print(f"点名: {tag_name}")
    print(f"时间段: {start_time} -> {end_time}")
    print(f"并行查询线程数: {max_workers}")
    print(f"导出目录: {output_dir}")
    print()

    from export_data_core2 import export_by_day_with_30min_chunks_parallel

    excel_file = export_by_day_with_30min_chunks_parallel(
        tag_name=tag_name,
        start_time=start_time,
        end_time=end_time,
        interval_seconds=interval_seconds,
        data_type="float",
        chunk_minutes=chunk_minutes,
        max_workers=max_workers,
        output_dir=output_dir,
    )

    print()
    if excel_file:
        print("[OK] 导出成功")
        print(os.path.abspath(excel_file))
    else:
        print("[ERROR] 导出失败")

    input("按回车键退出...")


if __name__ == "__main__":
    main()
