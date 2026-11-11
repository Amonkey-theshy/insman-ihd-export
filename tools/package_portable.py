"""Build a clean portable tree/ZIP from a verified PyInstaller output directory."""
import argparse
import hashlib
import json
import shutil
from pathlib import Path
from zipfile import ZIP_DEFLATED, ZipFile


def publish(source, destination, archive_path):
    if destination.exists():
        raise FileExistsError(f"Use a new destination directory: {destination}")
    required = ["INSMAN.exe", "_internal/python314.dll", "_internal/library/hdKingAPI.dll"]
    for name in required:
        if not (source / name).is_file():
            raise FileNotFoundError(source / name)
    files = []
    for path in sorted(source.rglob("*")):
        if not path.is_file():
            continue
        relative = path.relative_to(source)
        if (path.name.endswith(("_config.json", "_KingAPI.txt", ".log"))
                or path.name == "self_test_report.json"
                or "exported_csv" in relative.parts or "exported_excel" in relative.parts):
            continue
        files.append((path, relative))
    destination.mkdir(parents=True)
    manifest = {"platform": "Windows 10/11 x64", "files": []}
    for path, relative in files:
        target = destination / relative
        target.parent.mkdir(parents=True, exist_ok=True)
        shutil.copy2(path, target)
        manifest["files"].append({"path": relative.as_posix(), "bytes": target.stat().st_size,
                                  "sha256": hashlib.sha256(target.read_bytes()).hexdigest()})
    readme = destination / "使用说明.txt"
    readme.write_text(
        "INSMAN · Windows 10/11 64 位便携版\n\n"
        "1. 将整个 INSMAN 文件夹解压到可写目录。不要在压缩包内直接运行。\n"
        "2. 双击 INSMAN.exe；无需安装 Python、Java 或单独安装 SDK。\n"
        "3. 在服务器连接页输入实际服务器、端口、用户名与密码。\n"
        "4. 在导出参数页填写测点与时间，选择保存位置，开始导出。\n\n"
        "_internal 包含 Python、界面和 SDK 运行库，必须与 EXE 一起保留。\n"
        "首次使用不附带现场凭据，配置将在首次导出时保存到程序旁。\n"
        "连接数据库需在能访问现场 iHD 的网络中运行。\n"
        "Windows Server、32 位 Windows 和 ARM Windows 尚未验证。\n\n"
        "离线自检（PowerShell，在本文件夹执行，不连接数据库）：\n"
        ".\\INSMAN.exe --self-test --report .\\self_test_report.json\n"
        "检查报告的 ok 为 true 表示界面、SDK 加载与模拟 CSV 导出正常。\n",
        encoding="utf-8-sig")
    manifest["files"].append({"path": readme.name, "bytes": readme.stat().st_size,
                              "sha256": hashlib.sha256(readme.read_bytes()).hexdigest()})
    (destination / "MANIFEST.json").write_text(json.dumps(manifest, ensure_ascii=False, indent=2), encoding="utf-8")
    archive_path.parent.mkdir(parents=True, exist_ok=True)
    with ZipFile(archive_path, "w", ZIP_DEFLATED, compresslevel=6) as archive:
        for path in sorted(destination.rglob("*")):
            if path.is_file():
                archive.write(path, Path("INSMAN") / path.relative_to(destination))
    with ZipFile(archive_path) as archive:
        if archive.testzip() is not None:
            raise RuntimeError("ZIP integrity check failed")
    digest = hashlib.sha256(archive_path.read_bytes()).hexdigest()
    archive_path.with_suffix(".zip.sha256").write_text(f"{digest}  {archive_path.name}\n", encoding="ascii")
    print(f"Packaged {len(files)} payload files: {archive_path} ({archive_path.stat().st_size:,} bytes)")


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("--source", type=Path, required=True)
    parser.add_argument("--destination", type=Path, default=Path("portable/INSMAN"))
    parser.add_argument("--archive", type=Path, default=Path("build/releases/INSMAN-Windows-x64.zip"))
    args = parser.parse_args()
    publish(args.source, args.destination, args.archive)
