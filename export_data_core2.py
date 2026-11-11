# 单点长时间海量数据导出
# 程序并行分段查询 iHD，最终保存为 CSV 文件
import os
import argparse
from datetime import datetime, timedelta
from concurrent.futures import ThreadPoolExecutor, TimeoutError as FutureTimeoutError
from bisect import bisect_left
from collections import deque
import tempfile
from get_from_ihdb import *
import csv


class ExportCancelled(Exception):
    """在查询返回后协作停止，不发布未完成的 CSV。"""


def parse_datetime(value):
    for fmt in ("%Y-%m-%d %H:%M:%S", "%Y/%m/%d %H:%M:%S"):
        try:
            return datetime.strptime(value, fmt)
        except ValueError:
            pass
    raise argparse.ArgumentTypeError(
        "时间格式必须是 'YYYY-MM-DD HH:MM:SS' 或 'YYYY/MM/DD HH:MM:SS'"
    )

def linear_interpolation(x1, y1, x2, y2, x):
    """
    线性插值函数
    x1, y1: 第一个数据点的时间和值
    x2, y2: 第二个数据点的时间和值
    x: 要插值的时间点
    返回: 插值结果
    """
    if x1 == x2:
        return y1
    return y1 + (y2 - y1) * (x - x1) / (x2 - x1)

def generate_time_points(start_time, end_time, interval_seconds):
    """
    生成等时间间隔的时间点序列
    start_time: 开始时间
    end_time: 结束时间
    interval_seconds: 时间间隔（秒）
    返回: 时间点列表
    """
    time_points = []
    current_time = start_time
    while current_time <= end_time:
        time_points.append(current_time)
        current_time += timedelta(seconds=interval_seconds)
    return time_points

def interpolate_data(original_times, original_values, target_times):
    """
    对原始数据进行插值处理
    original_times: 原始时间点列表
    original_values: 原始数值列表
    target_times: 目标时间点列表（需要插值的时间点）
    返回: 插值后的数值列表
    """
    if len(original_times) < 2:
        raise ValueError("至少需要两个数据点才能进行插值")

    interpolated_values = []

    for target_time in target_times:
        # 找到目标时间点在原始数据中的位置
        if target_time <= original_times[0]:
            # 如果目标时间早于第一个数据点，使用第一个数据点的值
            interpolated_values.append(original_values[0])
        elif target_time >= original_times[-1]:
            # 如果目标时间晚于最后一个数据点，使用最后一个数据点的值
            interpolated_values.append(original_values[-1])
        else:
            # 二分查找保留原有边界/重复时间戳规则，避免每个采样点从头扫描。
            i = bisect_left(original_times, target_time) - 1
            interpolated_values.append(linear_interpolation(
                original_times[i], original_values[i],
                original_times[i + 1], original_values[i + 1], target_time
            ))

    return interpolated_values

def export_interpolated_data_to_csv(tag_name, start_time, end_time, interval_seconds=60, csv_filename=None, data_type=None):
    """
    导出插值数据到CSV文件
    tag_name: 标签名称
    start_time: 开始时间
    end_time: 结束时间
    interval_seconds: 插值时间间隔（秒），默认60秒
    csv_filename: CSV文件名，如果为None则自动生成
    """
    # 获取原始数据
    print(f"正在获取标签 '{tag_name}' 的原始数据...")
    original_times_str, original_values = get_ihd_datas_with_time(tag_name, start_time, end_time)

    if not original_times_str or not original_values:
        print(f"警告: 标签 '{tag_name}' 在指定时间范围内没有数据")
        return None

    # 将时间字符串转换为datetime对象
    original_times = [datetime.strptime(time_str, "%Y-%m-%d %H:%M:%S") for time_str in original_times_str]

    # 生成目标时间点
    target_times = generate_time_points(start_time, end_time, interval_seconds)

    # 进行插值
    print(f"正在进行插值计算，时间间隔: {interval_seconds}秒...")
    interpolated_values = interpolate_data(original_times, original_values, target_times)

    # 生成CSV文件名
    if csv_filename is None:
        csv_filename = f"{tag_name}_{start_time.strftime('%Y%m%d_%H%M%S')}_{end_time.strftime('%Y%m%d_%H%M%S')}_interval{interval_seconds}s.csv"

    # 写入CSV文件
    print(f"正在写入CSV文件: {csv_filename}")
    with open(csv_filename, 'w', newline='', encoding='utf-8') as csvfile:
        writer = csv.writer(csvfile)
        # 写入表头 - 四列标题
        writer.writerow(['Tag名', '时间戳', '数据质量', '数据值'])

        # 写入数据 - 只填写时间戳和数据值列，其他列留空
        for time_point, value in zip(target_times, interpolated_values):
            # A列(标签名)留空，B列(时间戳)，C列(数据质量)留空，D列(数据值)
            if data_type is not None:
                if data_type == 'float':
                    value = float(value)
                    value = f"{value:.6f}"
            writer.writerow([tag_name, time_point.strftime("%Y-%m-%d %H:%M:%S"), 'Good', value])

    print(f"数据导出完成！共导出 {len(target_times)} 个数据点")
    print(f"原始数据点数量: {len(original_times)}")
    print(f"插值后数据点数量: {len(target_times)}")
    print(f"CSV文件保存路径: {csv_filename}")

    return csv_filename


def build_interpolated_rows(tag_name, start_time, end_time, interval_seconds=60, data_type=None):
    original_times_str, original_values = get_ihd_datas_with_time(tag_name, start_time, end_time)
    if not original_times_str or not original_values:
        return []

    original_times = [datetime.strptime(time_str, "%Y-%m-%d %H:%M:%S") for time_str in original_times_str]
    target_times = generate_time_points(start_time, end_time, interval_seconds)
    interpolated_values = interpolate_data(original_times, original_values, target_times)

    rows = []
    for time_point, value in zip(target_times, interpolated_values):
        if data_type == 'float':
            value = f"{float(value):.6f}"
        rows.append({
            'Tag名': tag_name,
            '时间戳': time_point.strftime("%Y-%m-%d %H:%M:%S"),
            '数据质量': 'Good',
            '数据值': value
        })
    return rows


def split_time_chunks(start_time, end_time, chunk_minutes):
    chunks = []
    chunk_delta = timedelta(minutes=chunk_minutes)
    current = start_time
    while current < end_time:
        chunk_end = min(current + chunk_delta, end_time)
        chunks.append((current, chunk_end))
        current = chunk_end
    return chunks











# 保留原函数名兼容 GUI/命令行；实际输出单个 CSV，不按天分 Sheet。
def export_by_day_with_30min_chunks_parallel(
    tag_name: str,
    start_time: datetime,
    end_time: datetime,
    interval_seconds: int = 1,
    data_type: str = 'float',
    chunk_minutes: int = 20,
    output_dir: str = "./exported_csv",
    max_workers: int = 4,
    log_func=None,
    progress_func=None,
    stats_func=None,
    cancel_event=None
):
    """有限并发查询，按时间顺序写临时 CSV，全部成功后替换正式文件。"""
    log_func = log_func or print
    progress_func = progress_func or (lambda completed, total, message='': None)
    stats_func = stats_func or (lambda stats: None)

    def check_cancelled():
        if cancel_event is not None and cancel_event.is_set():
            raise ExportCancelled()

    if end_time <= start_time or interval_seconds <= 0 or chunk_minutes <= 0 or max_workers <= 0:
        log_func("[ERROR] 时间范围无效，或间隔、分段分钟数、线程数不是正数")
        return None

    chunk_delta = timedelta(minutes=chunk_minutes)
    # 不预建整个时间段列表；窗口同时限制运行中和已完成待写入的分段数量。
    total_chunks, remainder = divmod(end_time - start_time, chunk_delta)
    total_chunks += bool(remainder)
    max_workers = min(max_workers, total_chunks)
    window_size = min(max_workers * 2, total_chunks)
    pending = deque()
    temp_filename = None
    total_rows = 0
    empty_chunks = 0
    last_timestamp = None
    # 为最终关闭文件和替换文件保留一步，只有正式文件就绪才显示 100%。
    progress_total = total_chunks + 1
    try:
        check_cancelled()
        os.makedirs(output_dir, exist_ok=True)
        csv_filename = os.path.join(
            output_dir,
            f"{tag_name}_{start_time.strftime('%Y%m%d_%H%M')}_{end_time.strftime('%Y%m%d_%H%M')}.csv"
        )
        progress_func(0, progress_total, "准备查询")
        log_func(f"[INFO] 流式导出：共 {total_chunks} 段，每段 {chunk_minutes} 分钟，{max_workers} 个线程，最多 {window_size} 段在途")
        # 临时文件与正式文件同目录，独立命名避免覆盖其他任务的临时结果。
        with tempfile.NamedTemporaryFile(mode="w", newline="", encoding="utf-8-sig",
                                         dir=output_dir, prefix=".ihd_export_", suffix=".tmp", delete=False) as csvfile:
            temp_filename = csvfile.name
            writer = csv.DictWriter(csvfile, fieldnames=['Tag名', '时间戳', '数据质量', '数据值'])
            writer.writeheader()
            with ThreadPoolExecutor(max_workers=max_workers) as executor:
                next_start = start_time
                next_index = 1

                def submit_next():
                    nonlocal next_start, next_index
                    check_cancelled()
                    chunk_end = min(next_start + chunk_delta, end_time)
                    future = executor.submit(build_interpolated_rows, tag_name, next_start,
                                             chunk_end, interval_seconds, data_type)
                    pending.append((next_index, next_start, chunk_end, future))
                    next_start = chunk_end
                    next_index += 1

                try:
                    for _ in range(window_size):
                        submit_next()
                    while pending:
                        check_cancelled()
                        index, chunk_start, chunk_end, future = pending.popleft()
                        try:
                            while True:
                                check_cancelled()
                                try:
                                    rows = future.result(timeout=0.1)
                                    break
                                except FutureTimeoutError:
                                    # 已结束的任务也可能自身抛出 TimeoutError。
                                    if future.done():
                                        rows = future.result()
                                        break
                            check_cancelled()
                        except ExportCancelled:
                            raise
                        except Exception as exc:
                            raise RuntimeError(f"第 {index} 段查询失败: {chunk_start} -> {chunk_end}: {exc}") from exc
                        # 仅按最早分段等待和写入；后续段即使先完成，也不能无限提交新查询。
                        rows.sort(key=lambda row: row['时间戳'])
                        if not rows:
                            empty_chunks += 1
                            log_func(f"[WARN] 第 {index} 段无数据: {chunk_start} -> {chunk_end}")
                        for row in rows:
                            timestamp = row['时间戳']
                            if timestamp == last_timestamp:
                                continue
                            writer.writerow(row)
                            total_rows += 1
                            last_timestamp = timestamp
                        # 每段写完后刷新缓冲并释放列表及 Future，再补充一个新任务。
                        # 不逐行刷盘；内存上限取决于窗口和单段数据量，不累计整个导出结果。
                        csvfile.flush()
                        log_func(f"[OK] 已写入 {index}/{total_chunks} 段，本段 {len(rows)} 行，累计 {total_rows} 行")
                        rows.clear()
                        del rows, future
                        progress_func(index, progress_total, f"已写入 {index}/{total_chunks} 段")
                        stats_func({"completed": index, "total": total_chunks,
                                    "rows": total_rows, "empty_chunks": empty_chunks})
                        if next_start < end_time:
                            submit_next()
                finally:
                    # 失败后取消尚未开始的查询；运行中的 SDK 调用等待返回，不强制中断连接。
                    for _, _, _, queued_future in pending:
                        queued_future.cancel()
            if total_rows == 0:
                raise ValueError("无有效数据")
        check_cancelled()
        os.replace(temp_filename, csv_filename)
        temp_filename = None
    except ExportCancelled:
        log_func("[INFO] 已停止导出，临时数据已撤销")
        return None
    except Exception as exc:
        log_func(f"[ERROR] 导出失败，未替换正式 CSV: {exc}")
        return None
    finally:
        pending.clear()
        # 失败时只清理本次临时文件，保留已有正式 CSV；不留下冒充成功的部分数据。
        if temp_filename is not None:
            try:
                os.remove(temp_filename)
            except OSError as exc:
                log_func(f"[WARN] 临时文件清理失败: {temp_filename}: {exc}")

    if empty_chunks:
        log_func(f"[WARN] 有 {empty_chunks} 段无数据，CSV 未覆盖这些空段，请核对上述时间范围")
    log_func(f"[OK] 完成！共 {total_rows} 行数据，文件: {csv_filename}")
    progress_func(progress_total, progress_total, "导出完成")
    return csv_filename

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="导出 iHD 单点历史数据到 CSV")
    parser.add_argument("--tag", default="EAF7_TNOS_WS_TP", help="点名")
    parser.add_argument("--start", type=parse_datetime, default=parse_datetime("2026/6/18 00:00:00"), help="开始时间")
    parser.add_argument("--end", type=parse_datetime, default=parse_datetime("2026/6/29 16:30:00"), help="结束时间")
    parser.add_argument("--interval-seconds", type=int, default=1, help="插值间隔，单位秒")
    parser.add_argument("--chunk-minutes", type=int, default=20, help="每次查询的时间块，单位分钟")
    parser.add_argument("--max-workers", type=int, default=4, help="并行查询线程数")
    parser.add_argument("--output-dir", default="./exported_csv", help="导出目录")
    parser.add_argument("--data-type", default="float", help="数据类型，目前常用 float")
    args = parser.parse_args()

    print("=" * 60)
    print("多线程版：有限并发分段查询 + 按序流式写入 CSV")
    print("=" * 60)

    output_file = export_by_day_with_30min_chunks_parallel(
        tag_name=args.tag,
        start_time=args.start,
        end_time=args.end,
        interval_seconds=args.interval_seconds,
        data_type=args.data_type,
        chunk_minutes=args.chunk_minutes,
        output_dir=args.output_dir,
        max_workers=args.max_workers
    )

    if output_file:
        print(f"\n[OK] 成功！文件: {os.path.abspath(output_file)}")
    else:
        print("\n[ERROR] 失败！")
