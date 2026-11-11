# iHD SDK 库

本目录包含 Windows x64 的 iHD SDK DLL、导入库和原有 Java 库，供源码运行与打包使用。Python 和 SDK 位数需保持一致。已包含 `MSVCP100.dll`、`MSVCR100.dll`，用于满足原 SDK 的 VC 2010 运行库依赖。

可设置 `IHD_SDK_LIBRARY_DIR` 指向其他兼容 SDK 目录。SDK 运行日志不会纳入版本控制。

无需开发环境时，下载仓库 Release 的完整便携 ZIP，或运行 `portable/INSMAN/INSMAN.exe`。SDK、VC 和 Java 库保留各自供应方的原有权利；本仓库不将其重新授权。
