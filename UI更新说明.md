# INSMAN 界面与响应优化

## 使用

运行 `dist/INSMAN/INSMAN.exe`。移动到其他电脑时复制整个 `INSMAN` 文件夹，或解压 `dist/INSMAN.zip`。

- 左侧切换导出参数和服务器连接；小窗口下可滚动表单。
- 支持近 1 小时、近 24 小时和昨天的时间快捷填充，时间使用运行电脑的本地时间。
- 右侧显示进度、写入行数、完成分段、耗时以及输出文件位置。
- 日志区显示最近 1200 行；大量消息采用限量缓存及分批刷新。向上滚动查看时不会强制跳回底部。
- 点击停止后，程序等待已运行的 SDK 查询返回，取消待执行任务并清理本次临时文件。此前的正式 CSV 不受影响。
- 导出期间参数锁定，防止画面中的参数与正在运行的任务不一致。

## 验证

`python -B -m unittest -v test_streaming_export.py test_ui_refresh.py`

12 项离线测试通过，覆盖采样结果、流式写入、缓存上限、异步界面更新、取消清理和旧文件保护。已验证 Windows 高 DPI 窗口、页签、启动及 SDK DLL 加载；未连接现场数据库。

插值区间查找由逐项扫描改为二分查找。1200 个原始点、1199 个目标点的本地样例中结果一致，计算耗时约从 0.062 秒降到 0.001 秒；实际总耗时仍取决于数据库查询与网络。

## 打包

`python -m PyInstaller --noconfirm --workpath build/ui_refresh --distpath build/ui_refresh_release INSMAN.spec`

SDK 从现有发行目录或根目录的 library 读取。先生成到 build 目录，验证后再部署，避免覆盖配置。

原版完整目录、压缩包和修改前源码备份于 `build/ui_refresh_backup_20261111_235530/`。
