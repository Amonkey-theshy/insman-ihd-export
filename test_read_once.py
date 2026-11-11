from get_from_ihdb import get_current_time_value


if __name__ == "__main__":
    tag_name = "EAF7_TNOS_WS_TP"
    time_str, value = get_current_time_value(tag_name)
    print(f"{tag_name}: time={time_str}, value={value}")
