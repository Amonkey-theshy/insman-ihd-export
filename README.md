# INSMAN · iHD 历史数据导出

Windows 桌面工具，用于查询 iHD / iHyperDB 单个测点的历史数据，在本地进行线性插值，并按时间顺序写入 CSV。

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

仓库提供 Python 源码、SDK 接口封装、C 头文件、图标和打包配置。SDK DLL、EXE、构建产物、数据库配置、日志及导出数据不纳入版本控制。

连接实际数据库前，请从自己的 iHD SDK 安装中准备 `hdKingAPI.dll` 及其依赖库，放入项目根目录 `library/`。也可通过 `IHD_SDK_LIBRARY_DIR` 指定 DLL 目录。SDK 位数需与 Python / 打包程序一致。

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

将 SDK DLL 及依赖库放入 `library/`，然后：

```powershell
python -m pip install -r requirements-dev.txt
python -m PyInstaller --noconfirm --workpath build/ui_refresh --distpath build/ui_refresh_release INSMAN.spec
```

结果位于 `build/ui_refresh_release/INSMAN/`。请分发整个目录，包含 `_internal`；配置文件需在部署时单独保留。

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

## 当前限制

一次导出一个数值测点。时间使用运行电脑的本地时区，输出精确到秒；质量列目前固定为 `Good`，未传播 SDK 原始质量。插值在各分段内独立计算，边界采用首末值填充；单条记录分段会报错，空段会警告并跳过。采样间隔不能整除分段长度时，跨段间隔可能不同。

SDK 中大批量分页及区间边界标志存在已知问题，尚未修正；使用实际数据前应验证边界与数据完整性。当前测试不代表已完成现场数据库验收。
