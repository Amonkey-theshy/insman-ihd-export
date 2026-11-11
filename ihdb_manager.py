# ihd_manager.py
import os
import threading
from ihdSDK import server
import time
from datetime import datetime

class IHDConnectionManager:
    """
    IHD SDK 连接管理器（线程安全）
    - 每个线程自动创建并复用自己的 Server 连接
    - 支持自动重连（可选）
    - 提供便捷的数据读取接口
    """

    def __init__(
        self,
        username: str = "admin",
        password: str = "",
        ip1: str = "127.0.0.1",
        port1: int = 5673,
        ip2: str = "127.0.0.1",
        port2: int = 5673,
    ):
        self.username = username
        self.password = password
        self.ip1 = ip1
        self.port1 = port1
        self.ip2 = ip2
        self.port2 = port2
        # 使用 threading.local() 实现线程隔离
        self._local = threading.local()

    def _get_or_create_connection(self):
        """获取当前线程的连接，若无则创建"""
        if not hasattr(self._local, "server"):
            print(f"[INFO] Thread {threading.current_thread().name}: creating IHD connection...")
            try:
                self._local.server = server.Server(
                    self.ip1, self.port1, self.ip2, self.port2
                )
                self._local.server.connect()
                self._local.server.login(self.username, self.password)
                print(f"[OK] Thread {threading.current_thread().name}: connected")
            except Exception as e:
                print(f"[ERROR] Thread {threading.current_thread().name}: connection failed - {e}")
                raise
        return self._local.server

    def get_tag_mgr(self):
        """获取当前线程的 TagManager"""
        server_obj = self._get_or_create_connection()
        return server_obj.tag_mgr

    # ------------------ 你的原始功能封装 ------------------

    def get_current_value(self, tag_name: str):
        """获取单个标签当前值"""
        tag_mgr = self.get_tag_mgr()
        tag = tag_mgr.get_tag(tag_name)
        snapshot = tag.get_snapshot()
        return snapshot.value

    def get_current_time_value(self, tag_name: str):
        """获取标签当前值及时间字符串"""
        tag_mgr = self.get_tag_mgr()
        tag = tag_mgr.get_tag(tag_name)
        snapshot = tag.get_snapshot()
        time_str = self._stamp_to_time_str(snapshot.sec * 1000 + snapshot.msec)
        return time_str, snapshot.value

    def get_ihd_datas(self, tag_name: str, start_time, end_time):
        """按时间范围获取数值列表（倒序）"""
        tag_mgr = self.get_tag_mgr()
        tag = tag_mgr.get_tag(tag_name)
        iterator = tag.get_rawRecords_Iterate_ByTimeScope(start_time, end_time)
        record = iterator.get_next_record()

        src_records = []
        while record:
            src_records.append(record)
            record = iterator.get_next_record()

        result_data = []
        if src_records:
            for i in range(len(src_records)):
                result_data.append(float(src_records[-i - 1].value))
        return result_data

    def get_ihd_datas_with_time(self, tag_name: str, start_time, end_time):
        """按时间范围获取时间和数值列表（倒序）"""
        tag_mgr = self.get_tag_mgr()
        tag = tag_mgr.get_tag(tag_name)
        iterator = tag.get_rawRecords_Iterate_ByTimeScope(start_time, end_time)
        record = iterator.get_next_record()

        src_records = []
        while record:
            src_records.append(record)
            record = iterator.get_next_record()

        result_time = []
        result_data = []
        if src_records:
            for i in range(len(src_records)):
                current_record = src_records[-i - 1]
                time_str = self._stamp_to_time_str(
                    current_record.sec * 1000 + current_record.msec
                )
                result_time.append(time_str)
                result_data.append(float(current_record.value))
        return result_time, result_data

    def get_values_by_tags(self, tags_list):
        """批量获取多个标签当前值"""
        return {tag: self.get_current_value(tag) for tag in tags_list}

    # ------------------ 工具方法 ------------------

    @staticmethod
    def _stamp_to_time_str(objStamp):
        timeStamp = float(objStamp / 1000)
        timeArray = time.localtime(timeStamp)
        return time.strftime("%Y-%m-%d %H:%M:%S", timeArray)

    # ------------------ 可选：清理当前线程连接 ------------------
    # def close_current_thread_connection(self):
    #     """手动关闭当前线程的连接（通常不需要，线程结束自动释放）"""
    #     if hasattr(self._local, "server"):
    #         try:
    #             self._local.server.disconnect()
    #         except:
    #             pass
    #         del self._local.server
    #         print(f"[INFO] 线程 {threading.current_thread().name}: 连接已关闭")


def create_manager_from_env():
    return IHDConnectionManager(
        username=os.environ.get("IHD_USERNAME", "admin"),
        password=os.environ.get("IHD_PASSWORD", ""),
        ip1=os.environ.get("IHD_SERVER", "127.0.0.1"),
        port1=int(os.environ.get("IHD_PORT", "5673")),
        ip2=os.environ.get("IHD_BAK_SERVER", ""),
        port2=int(os.environ.get("IHD_BAK_PORT", "0")),
    )


def configure_ihd_manager(username, password, ip1, port1, ip2="", port2=0):
    global ihd_manager
    ihd_manager = IHDConnectionManager(
        username=username,
        password=password,
        ip1=ip1,
        port1=int(port1),
        ip2=ip2 or "",
        port2=int(port2 or 0),
    )
    return ihd_manager


# 全局单例（进程内共享）
ihd_manager = create_manager_from_env()
