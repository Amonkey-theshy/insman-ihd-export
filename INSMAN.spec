# Build: python -m PyInstaller --noconfirm --workpath build/ui_refresh INSMAN.spec
from pathlib import Path

root = Path(SPECPATH)
# Prefer the SDK shipped with the repository; support older local releases too.
sdk = root / 'library'
if not (sdk / 'hdKingAPI.dll').exists():
    sdk = root / 'dist' / 'INSMAN' / '_internal' / 'library'
if not (sdk / 'hdKingAPI.dll').exists():
    raise FileNotFoundError('Restore the iHD SDK DLLs before building INSMAN')
icon = root / 'assets' / 'INSMAN.ico'
if not icon.exists():
    icon = root / 'dist' / 'INSMAN' / '_internal' / 'assets' / 'INSMAN.ico'

a = Analysis([str(root / 'insman_gui.py')], pathex=[str(root)],
             binaries=[(str(p), 'library') for p in sdk.glob('*.dll')],
             datas=[(str(icon), 'assets')] if icon.exists() else [],
             hiddenimports=[], hookspath=[], hooksconfig={}, runtime_hooks=[],
             excludes=[], noarchive=False, optimize=0)
pyz = PYZ(a.pure)
exe = EXE(pyz, a.scripts, [], exclude_binaries=True, name='INSMAN',
          debug=False, bootloader_ignore_signals=False, strip=False, upx=False,
          console=False, disable_windowed_traceback=False,
          icon=str(icon) if icon.exists() else None)
coll = COLLECT(exe, a.binaries, a.datas, strip=False, upx=False, name='INSMAN')
