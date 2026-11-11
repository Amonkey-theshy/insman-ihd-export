import ihdb_manager

# 每次读取时获取模块中的当前管理器，确保界面修改连接配置后使用新连接。

def stamp_to_time_str(objStamp):
    return ihdb_manager.ihd_manager._stamp_to_time_str(objStamp)

def get_current_value(tag_name):
    return ihdb_manager.ihd_manager.get_current_value(tag_name)

def get_current_time_value(tag_name):
    return ihdb_manager.ihd_manager.get_current_time_value(tag_name)

def get_ihd_datas(tag_name, start_time, end_time):
    return ihdb_manager.ihd_manager.get_ihd_datas(tag_name, start_time, end_time)

def get_ihd_datas_with_time(tag_name, start_time, end_time):
    return ihdb_manager.ihd_manager.get_ihd_datas_with_time(tag_name, start_time, end_time)

def get_values_by_tags(tags_list):
    return ihdb_manager.ihd_manager.get_values_by_tags(tags_list)
