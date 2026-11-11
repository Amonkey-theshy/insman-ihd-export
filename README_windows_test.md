# Windows 测试

安装、SDK 配置、运行与打包请参阅 [README](README.md)。

离线验证（不连接现场数据库）：

```powershell
python -B -m unittest -v test_streaming_export.py test_ui_refresh.py
```

现场检查需自行设置 `IHD_SERVER`、`IHD_PORT`、`IHD_USERNAME`、`IHD_PASSWORD`，准备好 SDK DLL 后再运行：

```powershell
python .\test_connect.py
python .\test_read_once.py
```

`test_read_once.py` 中的测点需按现场情况填写。导出格式为 CSV。
