# 本地 SDK 库

将你的 iHD SDK `hdKingAPI.dll` 和依赖 DLL 放入本目录，位数需与 Python 一致。SDK 二进制文件和运行日志被 Git 忽略。

也可设置 `IHD_SDK_LIBRARY_DIR` 指向已有 SDK 目录；PyInstaller 打包时请先在此目录准备 DLL。
