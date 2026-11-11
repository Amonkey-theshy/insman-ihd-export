import json
import os
import sys
import threading
import time
import tkinter as tk
from collections import deque
from datetime import datetime, timedelta
from tkinter import filedialog, messagebox, ttk

from ihdb_manager import configure_ihd_manager

APP_NAME = "INSMAN"
FIXED_CHUNK_MINUTES = 20
MAX_LOG_LINES = 1200


class ExportMailbox:
    """后台只保存有限日志和最新进度；任何生产速度都不会撑大 UI 队列。"""
    def __init__(self, capacity=2000):
        self._lock = threading.Lock()
        self._logs = deque(maxlen=capacity)
        self._latest = {}
        self._done = None
        self._dropped = 0

    def put(self, event):
        kind, payload = event
        with self._lock:
            if kind == "log":
                if len(self._logs) == self._logs.maxlen:
                    self._dropped += 1
                self._logs.append(payload)
            elif kind == "done":
                self._done = payload
            else:
                self._latest[kind] = payload

    def drain(self, limit=100):
        with self._lock:
            logs = [self._logs.popleft() for _ in range(min(limit, len(self._logs)))]
            dropped, self._dropped = self._dropped, 0
            latest, self._latest = self._latest, {}
            done = None
            if not self._logs:
                done, self._done = self._done, None
            return logs, latest, done, dropped, bool(self._logs)


def parse_datetime_input(value):
    for fmt in ("%Y-%m-%d %H:%M:%S", "%Y/%m/%d %H:%M:%S"):
        try:
            return datetime.strptime(value, fmt)
        except ValueError:
            pass
    raise ValueError("请输入完整时间，例如 2026-11-11 08:00:00")


def get_app_dir():
    if getattr(sys, "frozen", False):
        return os.path.dirname(sys.executable)
    return os.path.dirname(os.path.abspath(__file__))


def get_config_path():
    return os.path.join(get_app_dir(), "insman_config.json")


def get_icon_path():
    for base in (get_app_dir(), getattr(sys, "_MEIPASS", get_app_dir())):
        for relative in ("assets/INSMAN.ico", "_internal/assets/INSMAN.ico", "INSMAN.ico"):
            path = os.path.join(base, relative)
            if os.path.isfile(path):
                return path
    return None


def load_config():
    try:
        with open(get_config_path(), encoding="utf-8") as source:
            data = json.load(source)
            return data if isinstance(data, dict) else {}
    except (OSError, ValueError):
        return {}


def save_config(config):
    with open(get_config_path(), "w", encoding="utf-8") as destination:
        json.dump(config, destination, ensure_ascii=False, indent=2)


class INSMANApp(tk.Tk):
    def __init__(self):
        super().__init__()
        self.title("INSMAN · iHD 历史数据导出")
        self.configure(bg="#f1f4f9")
        self.scale = max(1.0, float(self.tk.call("tk", "scaling")) / (96 / 72))
        width = min(self.px(1160), int(self.winfo_screenwidth() * .92))
        height = min(self.px(790), int(self.winfo_screenheight() * .90))
        self.geometry(f"{width}x{height}")
        self.minsize(min(width, self.px(920)), min(height, self.px(640)))
        self.config_data = load_config()
        self.vars = {}
        self.entries = {}
        self.form_controls = []
        self.mailbox = ExportMailbox()
        self.worker_thread = None
        self.cancel_event = threading.Event()
        self.running = False
        self.close_when_done = False
        self.started_at = None
        self.output_file = None
        self.current_rows = 0
        self.progress_var = tk.DoubleVar(value=0)
        self.percent_var = tk.StringVar(value="0%")
        self.progress_text_var = tk.StringVar(value="填写参数，开始一次数据导出")
        self.status_var = tk.StringVar(value="就绪")
        self.rows_var = tk.StringVar(value="0")
        self.chunks_var = tk.StringVar(value="—")
        self.elapsed_var = tk.StringVar(value="00:00")
        self.error_var = tk.StringVar()
        self.result_var = tk.StringVar(value="导出完成后，文件位置将显示在这里。")
        self.follow_var = tk.BooleanVar(value=True)
        icon = get_icon_path()
        if icon:
            try:
                self.iconbitmap(icon)
            except tk.TclError:
                pass
        self._setup_style()
        self._build_ui()
        self.protocol("WM_DELETE_WINDOW", self._on_close)
        self.bind_all("<MouseWheel>", self._scroll_form, add="+")
        self._poll_id = self.after(100, self._poll_log_queue)
        self._clock_id = self.after(1000, self._tick_clock)

    def px(self, value):
        return max(1, round(value * self.scale))

    def _setup_style(self):
        s = ttk.Style(self)
        s.theme_use("clam")
        s.configure(".", font=("Microsoft YaHei UI", 10), foreground="#24334a", background="#f1f4f9")
        s.configure("TFrame", background="#f1f4f9")
        s.configure("Card.TFrame", background="white")
        s.configure("TLabel", background="#f1f4f9")
        s.configure("Card.TLabel", background="white")
        s.configure("Muted.TLabel", background="white", foreground="#7b879a", font=("Microsoft YaHei UI", 9))
        s.configure("Title.TLabel", background="white", font=("Microsoft YaHei UI", 13, "bold"), foreground="#192b46")
        s.configure("Error.TLabel", background="white", foreground="#c54b49", font=("Microsoft YaHei UI", 9))
        s.configure("TEntry", padding=(self.px(10), self.px(5)), fieldbackground="#f7f9fc", bordercolor="#dce3ed", lightcolor="#dce3ed", darkcolor="#dce3ed", insertcolor="#24334a")
        s.map("TEntry", bordercolor=[("focus", "#326bed")], lightcolor=[("focus", "#326bed")], darkcolor=[("focus", "#326bed")])
        s.configure("TButton", padding=(self.px(12), self.px(8)), background="#edf2f9", foreground="#425c7e", borderwidth=0)
        s.map("TButton", background=[("disabled", "#f1f3f7"), ("pressed", "#d7e2f5"), ("active", "#e2eaf7")], foreground=[("disabled", "#a4adbb")])
        s.configure("Primary.TButton", background="#326bed", foreground="white", font=("Microsoft YaHei UI", 10, "bold"))
        s.map("Primary.TButton", background=[("disabled", "#c3d3f2"), ("pressed", "#2054c5"), ("active", "#245ed9")], foreground=[("disabled", "white")])
        s.configure("Small.TButton", padding=(self.px(9), self.px(5)), font=("Microsoft YaHei UI", 9))
        s.configure("Page.TRadiobutton", background="#f0f3f8", foreground="#6a7890", padding=(self.px(14), self.px(10)), font=("Microsoft YaHei UI", 10, "bold"))
        s.layout("Page.TRadiobutton", s.layout("TButton"))
        s.map("Page.TRadiobutton", background=[("selected", "#e8efff"), ("active", "#edf2fc")], foreground=[("selected", "#326bed")])
        s.configure("TCheckbutton", background="white", foreground="#7b879a", font=("Microsoft YaHei UI", 9))
        s.configure("Horizontal.TProgressbar", background="#326bed", troughcolor="#edf2fa", borderwidth=0, thickness=self.px(8), lightcolor="#326bed", darkcolor="#326bed")
        s.configure("Vertical.TScrollbar", background="#d8e1ee", troughcolor="#f7f9fc", borderwidth=0, arrowsize=self.px(11))

    def _build_ui(self):
        self.columnconfigure(0, weight=1)
        self.rowconfigure(1, weight=1)
        header = ttk.Frame(self, padding=(self.px(26), self.px(20), self.px(26), self.px(18)))
        header.grid(row=0, column=0, sticky="ew")
        header.columnconfigure(1, weight=1)
        tk.Label(header, text="IN", bg="#326bed", fg="white", font=("Segoe UI", 17, "bold"), padx=self.px(10), pady=self.px(6)).grid(row=0, column=0, rowspan=2, padx=(0, self.px(12)))
        ttk.Label(header, text="INSMAN", font=("Segoe UI", 21, "bold"), foreground="#192b46").grid(row=0, column=1, sticky="w")
        ttk.Label(header, text="历史数据工作台  /  iHD → CSV", foreground="#7b879a", font=("Microsoft YaHei UI", 9)).grid(row=1, column=1, sticky="w")
        tk.Label(header, text="单点历史数据导出", fg="#326bed", bg="#e6edfb", padx=self.px(12), pady=self.px(7), font=("Microsoft YaHei UI", 9)).grid(row=0, column=2, rowspan=2)
        body = ttk.Frame(self)
        body.grid(row=1, column=0, sticky="nsew", padx=self.px(22))
        body.rowconfigure(0, weight=1)
        body.columnconfigure(0, weight=5, uniform="body")
        body.columnconfigure(1, weight=6, uniform="body")
        form = ttk.Frame(body, style="Card.TFrame", padding=self.px(20))
        form.grid(row=0, column=0, sticky="nsew", padx=(0, self.px(14)))
        form.columnconfigure(0, weight=1)
        form.rowconfigure(2, weight=1)
        task = ttk.Frame(body, style="Card.TFrame", padding=self.px(22))
        task.grid(row=0, column=1, sticky="nsew")
        task.columnconfigure(0, weight=1)
        task.rowconfigure(4, weight=1)
        self._build_form(form)
        self._build_task(task)
        footer = ttk.Frame(self, padding=(self.px(24), self.px(10), self.px(24), self.px(12)))
        footer.grid(row=2, column=0, sticky="ew")
        footer.columnconfigure(0, weight=1)
        ttk.Label(footer, text="CSV · UTF-8  /  配置自动记忆", foreground="#8894a5", font=("Microsoft YaHei UI", 9)).grid(row=0, column=0, sticky="w")
        ttk.Label(footer, text="INSMAN  /  历史数据导出", foreground="#8894a5", font=("Microsoft YaHei UI", 9)).grid(row=0, column=1)

    def _build_form(self, parent):
        title = ttk.Frame(parent, style="Card.TFrame")
        title.grid(row=0, column=0, sticky="ew", pady=(0, self.px(16)))
        ttk.Label(title, text="导出配置", style="Title.TLabel").pack(anchor="w")
        ttk.Label(title, text="选择测点与时间范围", style="Muted.TLabel").pack(anchor="w", pady=(self.px(4), 0))
        switcher = ttk.Frame(parent, style="Card.TFrame")
        switcher.grid(row=1, column=0, sticky="ew", pady=(0, self.px(14)))
        switcher.columnconfigure((0, 1), weight=1, uniform="tab")
        self.page_var = tk.IntVar(value=0)
        for index, text in enumerate(("导出参数", "服务器连接")):
            ttk.Radiobutton(switcher, text=text, variable=self.page_var, value=index, style="Page.TRadiobutton", command=self._show_page).grid(row=0, column=index, sticky="ew", padx=(0, self.px(5)) if index == 0 else (self.px(5), 0))
        container = ttk.Frame(parent, style="Card.TFrame")
        container.grid(row=2, column=0, sticky="nsew")
        container.rowconfigure(0, weight=1)
        container.columnconfigure(0, weight=1)
        self.form_canvas = tk.Canvas(container, background="white", highlightthickness=0, width=1)
        self.form_canvas.grid(row=0, column=0, sticky="nsew")
        scrollbar = ttk.Scrollbar(container, orient="vertical", command=self.form_canvas.yview)
        scrollbar.grid(row=0, column=1, sticky="ns")
        self.form_canvas.configure(yscrollcommand=scrollbar.set)
        self.form_inner = ttk.Frame(self.form_canvas, style="Card.TFrame", padding=(0, 0, self.px(7), 0))
        self.form_inner.columnconfigure(0, weight=1)
        self._canvas_item = self.form_canvas.create_window((0, 0), window=self.form_inner, anchor="nw")
        self.form_canvas.bind("<Configure>", lambda e: self.form_canvas.itemconfigure(self._canvas_item, width=e.width))
        self.form_inner.bind("<Configure>", lambda e: self.form_canvas.configure(scrollregion=self.form_canvas.bbox("all")))
        self.pages = [ttk.Frame(self.form_inner, style="Card.TFrame") for _ in range(2)]
        for page in self.pages:
            page.columnconfigure(0, weight=1)
        export, connection = self.pages
        self._field(export, 0, "测点名称", "tag_name", "EAF7_TNOS_WS_TP")
        presets = ttk.Frame(export, style="Card.TFrame")
        presets.grid(row=1, column=0, sticky="ew", pady=(0, self.px(8)))
        ttk.Label(presets, text="快捷时间", style="Muted.TLabel").pack(side="left", padx=(0, self.px(8)))
        for text, hours in (("近 1 小时", 1), ("近 24 小时", 24), ("昨天", 0)):
            button = ttk.Button(presets, text=text, style="Small.TButton", command=lambda h=hours: self.set_time_range(h))
            button.pack(side="left", padx=(0, self.px(5)))
            self.form_controls.append(button)
        self._field(export, 2, "开始时间", "start_time", "")
        self._field(export, 3, "结束时间", "end_time", "")
        ttk.Label(export, text="格式：2026-11-11 08:00:00", style="Muted.TLabel").grid(row=4, column=0, sticky="w", pady=(0, self.px(12)))
        pair = ttk.Frame(export, style="Card.TFrame")
        pair.grid(row=5, column=0, sticky="ew")
        pair.columnconfigure((0, 1), weight=1, uniform="pair")
        for index, (label, key, default) in enumerate((("采样间隔 / 秒", "interval_seconds", "1"), ("查询线程数", "max_workers", "4"))):
            cell = ttk.Frame(pair, style="Card.TFrame", padding=(0 if index == 0 else self.px(6), 0, self.px(6) if index == 0 else 0, 0))
            cell.grid(row=0, column=index, sticky="ew")
            cell.columnconfigure(0, weight=1)
            self._field(cell, 0, label, key, default)
        self._field(export, 6, "保存位置", "output_dir", self._default_output_dir(), browse=True)
        for row, (label, key, default) in enumerate((("主服务器", "ihd_server", "127.0.0.1"), ("主端口", "ihd_port", "5673"), ("备用服务器（可选）", "ihd_bak_server", ""), ("备用端口", "ihd_bak_port", "0"), ("用户名", "ihd_username", "admin"), ("密码", "ihd_password", ""))):
            self._field(connection, row, label, key, default, show="●" if key == "ihd_password" else None)
        ttk.Label(connection, text="连接参数将在开始导出时保存。", style="Muted.TLabel").grid(row=6, column=0, sticky="w")
        self._show_page()
        error = ttk.Label(parent, textvariable=self.error_var, style="Error.TLabel", wraplength=self.px(350))
        error.grid(row=3, column=0, sticky="ew", pady=(self.px(8), self.px(8)))
        actions = ttk.Frame(parent, style="Card.TFrame")
        actions.grid(row=4, column=0, sticky="ew")
        actions.columnconfigure(0, weight=1)
        self.export_button = ttk.Button(actions, text="开始导出", style="Primary.TButton", command=self.start_export)
        self.export_button.grid(row=0, column=0, sticky="ew", padx=(0, self.px(8)))
        self.cancel_button = ttk.Button(actions, text="停止", command=self.stop_export, state="disabled")
        self.cancel_button.grid(row=0, column=1, sticky="ew")

    def _field(self, parent, row, label, key, default, show=None, browse=False):
        frame = ttk.Frame(parent, style="Card.TFrame")
        frame.grid(row=row, column=0, sticky="ew", pady=(0, self.px(8)))
        frame.columnconfigure(0, weight=1)
        ttk.Label(frame, text=label, style="Card.TLabel", font=("Microsoft YaHei UI", 9)).grid(row=0, column=0, columnspan=2, sticky="w", pady=(0, self.px(5)))
        value = self.config_data.get(key, default)
        if key == "output_dir":
            value = str(value).replace("exported_excel", "exported_csv") if value else default
        var = tk.StringVar(value=str(value))
        self.vars[key] = var
        entry = ttk.Entry(frame, textvariable=var, show=show, width=10)
        entry.grid(row=1, column=0, columnspan=1 if browse else 2, sticky="ew")
        self.entries[key] = entry
        self.form_controls.append(entry)
        if browse:
            button = ttk.Button(frame, text="选择", style="Small.TButton", command=self.choose_output_dir)
            button.grid(row=1, column=1, padx=(self.px(6), 0), sticky="ns")
            self.form_controls.append(button)

    def _show_page(self):
        for index, page in enumerate(self.pages):
            if index == self.page_var.get():
                page.grid(row=0, column=0, sticky="ew")
            else:
                page.grid_remove()
        self.form_canvas.yview_moveto(0)

    def _scroll_form(self, event):
        widget = event.widget
        while widget is not None:
            if widget == self.form_canvas or widget == self.form_inner:
                if self.form_canvas.bbox("all") and self.form_canvas.bbox("all")[3] > self.form_canvas.winfo_height():
                    self.form_canvas.yview_scroll(-int(event.delta / 120), "units")
                return "break"
            widget = getattr(widget, "master", None)

    def _build_task(self, parent):
        top = ttk.Frame(parent, style="Card.TFrame")
        top.grid(row=0, column=0, sticky="ew")
        top.columnconfigure(0, weight=1)
        ttk.Label(top, text="导出任务", style="Title.TLabel").grid(row=0, column=0, sticky="w")
        self.status_badge = tk.Label(top, textvariable=self.status_var, font=("Microsoft YaHei UI", 9), bg="#edf2f9", fg="#6a7890", padx=self.px(10), pady=self.px(4))
        self.status_badge.grid(row=0, column=1)
        progress = ttk.Frame(parent, style="Card.TFrame")
        progress.grid(row=1, column=0, sticky="ew", pady=(self.px(16), self.px(20)))
        progress.columnconfigure(0, weight=1)
        ttk.Label(progress, textvariable=self.percent_var, style="Card.TLabel", foreground="#243d68", font=("Segoe UI", 34, "bold")).grid(row=0, column=0, sticky="w")
        ttk.Label(progress, textvariable=self.progress_text_var, style="Muted.TLabel", wraplength=self.px(400)).grid(row=1, column=0, sticky="ew", pady=(0, self.px(12)))
        self.progress_bar = ttk.Progressbar(progress, variable=self.progress_var, maximum=100)
        self.progress_bar.grid(row=2, column=0, sticky="ew")
        stats = tk.Frame(parent, background="#f6f8fc")
        stats.grid(row=2, column=0, sticky="ew", pady=(0, self.px(20)))
        for index, (label, variable) in enumerate((("已写入 / 行", self.rows_var), ("完成分段", self.chunks_var), ("已用时间", self.elapsed_var))):
            stats.columnconfigure(index, weight=1, uniform="stat")
            cell = tk.Frame(stats, bg="#f6f8fc", padx=self.px(12), pady=self.px(12))
            cell.grid(row=0, column=index, sticky="ew")
            tk.Label(cell, textvariable=variable, font=("Segoe UI", 16, "bold"), fg="#314967", bg="#f6f8fc", anchor="w").pack(fill="x")
            tk.Label(cell, text=label, font=("Microsoft YaHei UI", 8), fg="#8390a4", bg="#f6f8fc", anchor="w").pack(fill="x", pady=(self.px(4), 0))
        log_top = ttk.Frame(parent, style="Card.TFrame")
        log_top.grid(row=3, column=0, sticky="ew", pady=(0, self.px(9)))
        log_top.columnconfigure(0, weight=1)
        ttk.Label(log_top, text="运行日志", style="Card.TLabel", font=("Microsoft YaHei UI", 10, "bold")).grid(row=0, column=0, sticky="w")
        ttk.Checkbutton(log_top, text="跟随最新", variable=self.follow_var).grid(row=0, column=1, padx=(0, self.px(8)))
        ttk.Button(log_top, text="清空", style="Small.TButton", command=self.clear_log).grid(row=0, column=2)
        log_frame = ttk.Frame(parent, style="Card.TFrame")
        log_frame.grid(row=4, column=0, sticky="nsew")
        log_frame.rowconfigure(0, weight=1)
        log_frame.columnconfigure(0, weight=1)
        self.log_text = tk.Text(log_frame, bg="#f7f9fc", fg="#62728a", relief="flat", highlightthickness=0, wrap="word", height=5, width=10, padx=self.px(12), pady=self.px(10), font=("Microsoft YaHei UI", 9), state="disabled")
        self.log_text.grid(row=0, column=0, sticky="nsew")
        for name, color in (("info", "#62728a"), ("ok", "#20846c"), ("warn", "#b0782a"), ("error", "#cb5454")):
            self.log_text.tag_configure(name, foreground=color)
        scrollbar = ttk.Scrollbar(log_frame, orient="vertical", command=self.log_text.yview)
        scrollbar.grid(row=0, column=1, sticky="ns")
        self.log_text.configure(yscrollcommand=scrollbar.set)
        result = ttk.Frame(parent, style="Card.TFrame")
        result.grid(row=5, column=0, sticky="ew", pady=(self.px(14), 0))
        result.columnconfigure(0, weight=1)
        label = ttk.Label(result, textvariable=self.result_var, style="Muted.TLabel", wraplength=self.px(300))
        label.grid(row=0, column=0, sticky="ew", padx=(0, self.px(10)))
        result.bind("<Configure>", lambda e: label.configure(wraplength=max(self.px(80), e.width - self.px(125))))
        ttk.Button(result, text="打开文件夹", style="Small.TButton", command=self.open_output_dir).grid(row=0, column=1)

    def _default_output_dir(self):
        configured = self.config_data.get("output_dir")
        return str(configured).replace("exported_excel", "exported_csv") if configured else os.path.join(get_app_dir(), "exported_csv")

    def choose_output_dir(self):
        path = self.vars["output_dir"].get()
        selected = filedialog.askdirectory(parent=self, initialdir=path if os.path.isdir(path) else get_app_dir())
        if selected:
            self.vars["output_dir"].set(selected)

    def set_time_range(self, hours):
        end = datetime.now().replace(microsecond=0)
        if hours:
            start = end - timedelta(hours=hours)
        else:
            end = end.replace(hour=0, minute=0, second=0)
            start = end - timedelta(days=1)
        self.vars["start_time"].set(start.strftime("%Y-%m-%d %H:%M:%S"))
        self.vars["end_time"].set(end.strftime("%Y-%m-%d %H:%M:%S"))
        self.error_var.set("")

    def clear_log(self):
        self.log_text.configure(state="normal")
        self.log_text.delete("1.0", "end")
        self.log_text.configure(state="disabled")

    def append_logs(self, messages):
        if not messages:
            return
        at_bottom = self.log_text.yview()[1] >= .995
        args = []
        for text in messages:
            tag = "error" if "[ERROR]" in text else "warn" if "[WARN]" in text else "ok" if "[OK]" in text else "info"
            args.extend((text, (tag,)))
        self.log_text.configure(state="normal")
        self.log_text.insert("end", *args)
        lines = int(self.log_text.index("end-1c").split(".")[0])
        if lines > MAX_LOG_LINES:
            self.log_text.delete("1.0", f"{lines - MAX_LOG_LINES + 1}.0")
        self.log_text.configure(state="disabled")
        if self.follow_var.get() and at_bottom:
            self.log_text.see("end")

    def _invalid(self, key, message):
        self.page_var.set(1 if key.startswith("ihd_") else 0)
        self._show_page()
        self.entries[key].focus_set()
        self.form_canvas.yview_moveto(0 if key in ("tag_name", "ihd_server", "ihd_port") else 1)
        raise ValueError(message)

    def get_form_config(self):
        config = {key: var.get().strip() for key, var in self.vars.items()}
        for key, label in (("tag_name", "测点名称"), ("ihd_server", "主服务器"), ("ihd_username", "用户名"), ("ihd_password", "密码"), ("output_dir", "保存位置")):
            if not config[key]:
                self._invalid(key, f"请填写{label}")
        # 密码中的首尾空格属于凭据的一部分。
        config["ihd_password"] = self.vars["ihd_password"].get()
        for key, label in (("start_time", "开始时间"), ("end_time", "结束时间")):
            try:
                parse_datetime_input(config[key])
            except ValueError:
                self._invalid(key, f"{label}格式有误，例如 2026-11-11 08:00:00")
        if parse_datetime_input(config["end_time"]) <= parse_datetime_input(config["start_time"]):
            self._invalid("end_time", "结束时间必须晚于开始时间")
        for key, label in (("ihd_port", "主端口"), ("ihd_bak_port", "备用端口"), ("interval_seconds", "采样间隔"), ("max_workers", "查询线程数")):
            try:
                config[key] = int(config[key] or 0)
            except ValueError:
                self._invalid(key, f"{label}必须是整数")
        if not 1 <= config["ihd_port"] <= 65535:
            self._invalid("ihd_port", "主端口范围为 1–65535")
        if config["ihd_bak_server"] and not 1 <= config["ihd_bak_port"] <= 65535:
            self._invalid("ihd_bak_port", "填写备用服务器后，备用端口范围为 1–65535")
        if config["interval_seconds"] <= 0:
            self._invalid("interval_seconds", "采样间隔必须大于 0 秒")
        if not 1 <= config["max_workers"] <= 32:
            self._invalid("max_workers", "查询线程数范围为 1–32，建议使用 4")
        config["chunk_minutes"] = FIXED_CHUNK_MINUTES
        return config

    def _set_running(self, running):
        self.running = running
        for widget in self.form_controls:
            widget.configure(state="disabled" if running else "normal")
        self.export_button.configure(state="disabled" if running else "normal", text="导出中…" if running else "开始导出")
        self.cancel_button.configure(state="normal" if running else "disabled")

    def _set_status(self, text, tone="idle"):
        colors = {"idle": ("#edf2f9", "#6a7890"), "running": ("#e8efff", "#326bed"), "ok": ("#e7f5ef", "#25846a"), "error": ("#fff0ef", "#c54b49"), "warn": ("#fff5e5", "#a7752b")}
        bg, fg = colors[tone]
        self.status_var.set(text)
        self.status_badge.configure(bg=bg, fg=fg)

    def start_export(self):
        if self.running or (self.worker_thread and self.worker_thread.is_alive()):
            return
        try:
            config = self.get_form_config()
            save_config(config)
        except Exception as exc:
            self.error_var.set(str(exc))
            return
        self.error_var.set("")
        self.clear_log()
        self.mailbox = ExportMailbox()
        self.cancel_event = threading.Event()
        self.output_file = None
        self.current_rows = 0
        self.progress_var.set(0)
        self.percent_var.set("0%")
        self.progress_text_var.set("正在连接服务器并准备查询…")
        self.rows_var.set("0")
        self.chunks_var.set("—")
        self.elapsed_var.set("00:00")
        self.result_var.set("正在导出，完成后可打开文件所在目录。")
        self.started_at = time.monotonic()
        self._set_running(True)
        self._set_status("导出中", "running")
        self.worker_thread = threading.Thread(target=self._run_export, args=(config, self.mailbox, self.cancel_event), daemon=True)
        self.worker_thread.start()

    def stop_export(self):
        if self.running:
            self.cancel_event.set()
            self.cancel_button.configure(state="disabled")
            self._set_status("正在停止", "warn")
            self.progress_text_var.set("等待当前查询返回，正在清理临时数据…")

    def _run_export(self, config, mailbox, cancel_event):
        try:
            configure_ihd_manager(username=config["ihd_username"], password=config["ihd_password"], ip1=config["ihd_server"], port1=config["ihd_port"], ip2=config["ihd_bak_server"], port2=config["ihd_bak_port"])
            from export_data_core2 import export_by_day_with_30min_chunks_parallel
            mailbox.put(("log", f"[INFO] 测点：{config['tag_name']}\n[INFO] 时间：{config['start_time']} → {config['end_time']}\n"))
            mailbox.put(("log", f"[INFO] 采样间隔 {config['interval_seconds']} 秒 · {config['max_workers']} 个查询线程\n"))
            def progress(completed, total, message=""):
                mailbox.put(("progress", (completed * 100 / total if total else 0, message)))
            result = export_by_day_with_30min_chunks_parallel(tag_name=config["tag_name"], start_time=parse_datetime_input(config["start_time"]), end_time=parse_datetime_input(config["end_time"]), interval_seconds=config["interval_seconds"], data_type="float", chunk_minutes=config["chunk_minutes"], max_workers=config["max_workers"], output_dir=config["output_dir"], log_func=lambda text: mailbox.put(("log", str(text) + "\n")), progress_func=progress, stats_func=lambda stats: mailbox.put(("stats", stats)), cancel_event=cancel_event)
            state = "success" if result else "cancelled" if cancel_event.is_set() else "error"
            mailbox.put(("done", {"state": state, "path": os.path.abspath(result) if result else None, "elapsed": time.monotonic() - self.started_at}))
        except Exception as exc:
            mailbox.put(("log", f"[ERROR] {exc}\n"))
            mailbox.put(("done", {"state": "error", "path": None, "elapsed": time.monotonic() - self.started_at}))

    @staticmethod
    def _duration(seconds):
        seconds = int(seconds)
        hours, remainder = divmod(seconds, 3600)
        minutes, seconds = divmod(remainder, 60)
        return f"{hours:02}:{minutes:02}:{seconds:02}" if hours else f"{minutes:02}:{seconds:02}"

    def _tick_clock(self):
        if self.running and self.started_at is not None:
            self.elapsed_var.set(self._duration(time.monotonic() - self.started_at))
        self._clock_id = self.after(1000, self._tick_clock)

    def _finish(self, result):
        self._set_running(False)
        self.elapsed_var.set(self._duration(result["elapsed"]))
        self.output_file = result["path"]
        state = result["state"]
        if state == "success":
            self._set_status("已完成", "ok")
            self.progress_var.set(100)
            self.percent_var.set("100%")
            self.progress_text_var.set(f"导出完成 · 共 {self.current_rows:,} 行")
            self.result_var.set(self.output_file)
        elif state == "cancelled":
            self._set_status("已停止", "warn")
            self.progress_text_var.set("任务已停止，可以修改参数重新导出")
            self.result_var.set("本次临时数据已撤销。")
        else:
            self._set_status("导出失败", "error")
            self.progress_text_var.set("导出未完成，请查看下方错误日志")
            self.result_var.set("请检查服务器连接、测点名称与保存位置。")
        if self.close_when_done:
            self.after_idle(self.destroy)

    def _poll_log_queue(self):
        logs, latest, done, dropped, pending = self.mailbox.drain()
        if dropped:
            logs.insert(0, f"[WARN] 日志过多，已省略 {dropped} 条较早日志。\n")
        self.append_logs(logs)
        if "progress" in latest and not self.cancel_event.is_set():
            percent, text = latest["progress"]
            percent = max(0, min(100, percent))
            self.progress_var.set(percent)
            self.percent_var.set(f"{percent:.0f}%" if percent in (0, 100) else f"{percent:.1f}%")
            self.progress_text_var.set(text)
        if "stats" in latest:
            stats = latest["stats"]
            self.current_rows = stats["rows"]
            self.rows_var.set(f"{self.current_rows:,}")
            self.chunks_var.set(f"{stats['completed']} / {stats['total']}")
        if done is not None:
            self._finish(done)
        self._poll_id = self.after(30 if pending else 80 if self.running else 180, self._poll_log_queue)

    def open_output_dir(self):
        path = os.path.dirname(self.output_file) if self.output_file else self.vars["output_dir"].get().strip() or get_app_dir()
        try:
            os.makedirs(path, exist_ok=True)
            os.startfile(path)
        except OSError as exc:
            self.error_var.set(f"无法打开文件夹：{exc}")

    def _on_close(self):
        if self.running:
            if messagebox.askyesno(APP_NAME, "导出正在进行。停止任务并在清理完成后关闭？", parent=self):
                self.close_when_done = True
                self.stop_export()
        else:
            self.destroy()


if __name__ == "__main__":
    if "--self-test" in sys.argv:
        from portable_check import run_self_test
        raise SystemExit(run_self_test(INSMANApp, sys.argv[1:]))
    INSMANApp().mainloop()
