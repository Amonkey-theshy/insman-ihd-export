# INSMAN · iHD 历史数据导出

Windows 桌面工具，用于查询 iHD / iHyperDB 单个测点的历史数据，在本地进行线性插值，并按时间顺序写入 CSV。

## 下载后直接使用

**Windows 10/11 64 位便携版：[下载完整程序包](https://github.com/Amonkey-theshy/insman-ihd-export/releases/latest/download/INSMAN-Windows-x64.zip)**

1. 下载 ZIP 并完整解压到可写目录。
2. 双击 `INSMAN/INSMAN.exe`，无需安装 Python、Java 或单独安装 SDK。
3. 在“服务器连接”页填写现场服务器、端口、用户名和密码，在“导出参数”页填写测点、时间范围和保存位置。

也可以通过 GitHub 的 **Code → Download ZIP** 下载整个仓库，解压后运行 `portable/INSMAN/INSMAN.exe`。必须保留旁边完整的 `_internal` 目录，不能只复制 EXE，也不要在压缩包中直接运行。

程序包包含 Python 3.14 运行库、Tk 界面库、iHD SDK DLL 及所需 VC 运行库。不包含现场凭据或导出数据；首次运行需填写实际连接参数，并确保电脑能访问现场数据库。已验证 Windows 11 x64 本机的离线启动与 SDK 加载；Windows Server、32 位及 ARM 环境未验证。

解压后可在 PowerShell 中执行离线自检，不连接数据库：

```powershell
.\INSMAN.exe --self-test --report .\self_test_report.json
```

检查报告 `ok` 为 `true`。`MANIFEST.json` 提供各文件 SHA-256，Release 同时提供 ZIP 校验值。

## 功能

- Tkinter 图形界面，支持高 DPI、滚动表单和配置记忆。
- 主备服务器连接参数、时间快捷填充、采样间隔和查询线程配置。
- 有限并发分段查询，逐段写入临时文件，成功后原子替换正式 CSV。
- 显示进度、写入行数、完成分段、耗时和输出位置。
- 有限日志缓存、分批刷新、保留最近 1200 行，支持查看历史日志。
- 可协作停止导出，等待当前 SDK 调用返回后清理临时文件。
- 提供交互式及带参数命令行入口。

## 环境与 SDK

已在 Windows、Python 3.14 上验证。Python 需包含 Tkinter；运行与测试仅使用标准库。

仓库包含 Python 源码、SDK 接口封装、C 头文件、图标、打包配置、`library/` 中的 SDK 库和 `portable/INSMAN/` 完整便携版。数据库配置、日志、导出数据和历史构建备份不纳入版本控制。

源码运行可直接使用 `library/` 随附的 SDK DLL，也可通过 `IHD_SDK_LIBRARY_DIR` 指定其他兼容 SDK 目录。SDK 位数需与 Python / 打包程序一致。

## 运行

```powershell
python .\insman_gui.py
```

在“服务器连接”页填写实际地址与账号，在“导出参数”页填写测点、时间和保存位置，点击“开始导出”。默认连接地址仅为本机占位符，密码需自行输入。配置保存在程序旁的 `insman_config.json`，此文件包含凭据，应仅保留在本地。

可参考 `insman_config.example.json`，也可运行交互式命令行：

```powershell
python .\ihd_history_export_cli.py
```

带参数导出先配置环境变量，再执行：

```powershell
$env:IHD_SERVER="your-ihd-server"
$env:IHD_PORT="5673"
$env:IHD_USERNAME="your-user"
$env:IHD_PASSWORD="your-password"
python .\export_data_core2.py --tag YOUR_TAG --start "2026-01-01 00:00:00" --end "2026-01-01 00:05:00" --interval-seconds 1 --chunk-minutes 20 --max-workers 4 --output-dir .\exported_csv
```

CSV 为 UTF-8 BOM，列为 `Tag名`、`时间戳`、`数据质量`、`数据值`，默认浮点数保留六位小数。

## 测试

离线测试模拟 SDK 返回数据，无需 DLL 或数据库连接；GUI 测试需可用的 Windows 桌面及 Tkinter。

```powershell
python -B -m unittest -v test_streaming_export.py test_ui_refresh.py
```

覆盖插值兼容性、流式写入、有限查询窗口、失败保护、取消清理、日志缓存和异步界面更新。

现场连通性检查：`python test_connect.py`；当前值读取：`python test_read_once.py`（先按现场情况修改测试测点）。

## 打包

`library/` 已包含 SDK DLL 及依赖库，然后：

```powershell
python -m pip install -r requirements-dev.txt
python -m PyInstaller --noconfirm --workpath build/ui_refresh --distpath build/ui_refresh_release INSMAN.spec
```

结果位于 `build/ui_refresh_release/INSMAN/`。请分发整个目录，包含 `_internal`；配置文件需在部署时单独保留。

构建输出可通过以下命令整理为干净的便携包（目标目录必须不存在）：

```powershell
python tools/package_portable.py --source build/ui_refresh_release/INSMAN --destination build/portable-package/INSMAN --archive build/releases/INSMAN-Windows-x64.zip
```

打包工具自动排除本地账号配置、SDK 运行日志、导出数据及自检报告，并生成文件清单和 ZIP 校验值。

## 文件说明

| 文件 | 用途 |
| --- | --- |
| `insman_gui.py` | 桌面界面、任务控制、进度和日志 |
| `export_data_core2.py` | 分段查询、插值、流式导出 |
| `ihdb_manager.py` | 每线程连接与数据读取 |
| `get_from_ihdb.py` | 简化数据读取入口 |
| `ihd_history_export_cli.py` | 交互式命令行 |
| `ihdSDK/`、`include/` | SDK Python 封装与 C 接口 |
| `INSMAN.spec` | Windows PyInstaller 配置 |
| `portable/INSMAN/` | 下载后直接运行的完整 Windows x64 程序 |
| `library/` | SDK DLL、VC 依赖库、导入库及原有 Java 库 |
| `portable_check.py` | EXE 内置离线自检 |
| `tools/package_portable.py` | 便携包、校验清单及 ZIP 生成 |

## 当前限制

一次导出一个数值测点。时间使用运行电脑的本地时区，输出精确到秒；质量列目前固定为 `Good`，未传播 SDK 原始质量。插值在各分段内独立计算，边界采用首末值填充；单条记录分段会报错，空段会警告并跳过。采样间隔不能整除分段长度时，跨段间隔可能不同。

SDK 中大批量分页及区间边界标志存在已知问题，尚未修正；使用实际数据前应验证边界与数据完整性。当前测试不代表已完成现场数据库验收。
