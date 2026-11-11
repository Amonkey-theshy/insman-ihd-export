/**
*  @file		    hd3API.h
*  @brief		hd3 api
*  @author:    hd3 tream
*  @date		   03/02/2015
*  @version     initialize version
*  Copyright:   Shanghai Baosight Software Co., Ltd.
*/
#ifndef HD3_INCLUDE_GUARD_HD3API_H
#define HD3_INCLUDE_GUARD_HD3API_H

#include "hd3Struct.h"
#include "ihyperdb.h"

#ifdef _WIN32
#  ifdef HD3_API_EXPORTS
#    define HD3_API __declspec(dllexport)
#  else
#    define HD3_API __declspec(dllimport)
#  endif//HD3_API_EXPORTS
#else
#define HD3_API
#endif//_WIN32

#ifdef __cplusplus
extern "C"
{
#endif

/**
* @brief 注册报警记录回调，用于被动接收报警记录
* @param pfn [回调函数的指针]
*  nChange [报警变更类型]
*  pRecord [报警记录]
* @return RD_SUCCESS, if success; hd3 error, otherwise
* @version 05/14/2015 g.l. modified version
*/
typedef void (*HD3AlarmCallbackFUnc)(
	hd3_in enum HD3_AM_CHANGE nChange,
	hd3_in const HD3AlarmRecord* pRecord);
HD3_API
int32 am3_register_alarm_record_info(hd3_in HD3AlarmCallbackFUnc pfn);

HD3_API
/**
* @brief 将所有点的时间戳变化通知注销
*/
int32 am3_unregister_alarm_record_info();


/**
* @brief获取调用am3_get_callback_am订阅的点的快照，完成后需要调用am3_free_callback_am
* @param 
*  nRecNum 快照个数
*  pRecs 快照数据指针
* @return RD_SUCCESS, if success; hd3 error, otherwise
* @version 03/27/2018 y.q. init version
*/
HD3_API
int32 am3_get_callback_am(int32* pnRecNum , HD3AlarmRecord** ppRecs);

/**
* @brief获取调用am3_get_callback_am订阅的点的快照，完成后需要调用am3_free_callback_am
* @param 
*  pRecs 快照数据指针
* @return void
* @version 03/27/2018 y.q. init version
*/
HD3_API
void am3_free_callback_am(hd3_in int32 nRecNum, HD3AlarmRecord* pRecs);

/**
* @brief 添加报警点
* 添加报警点时，报警点名称必须添加，其它属性可以选择性的添加
* 添加哪些属性由属性掩码决定
* @param pTagProp [点属性]
* @param pMask [属性掩码]
* @param szDataNodeName 节点名称, 如果要求将点到指定的数据节点，传入该数据节点名称，如果不要求传入NULL或者""
* @param pnTagID [添加成功，该点对应的ID]
* @return RD_SUCCESS, if success; hd3 error, otherwise
* @version 03/13/2015 g.l. modified version
*/
HD3_API
int32 am3_add_tag(
	hd3_in const HD3AlarmTagProp* pTagProp,
	hd3_in const HD3Mask* pMask,
	hd3_in const char* szDataNodeName,
	hd3_out uint32* pnTagID
	);

/**
* @brief 添加报警点（批量接口）
* @param nTagNum [点个数]
* @param pTagPropArray [属性数组]
* @param pMaskArray [掩码数组]
* @param szDataNodeName 节点名称, 如果要求将点到指定的数据节点，传入该数据节点名称，如果不要求传入NULL或者""
* @param pTagIDArray [TagID数组]
* @param pErrCodeArray [错误码数组]
* @return RD_SUCCESS, if all success
*       EC_HD3_API_BATCH_REQUEST, if some failed
*       hd3 error, otherwise
* @version 03/13/2015 g.l. modified version
*/
HD3_API
int32 am3_add_tags(
	hd3_in int32 nTagNum,
	hd3_in const HD3AlarmTagProp* pTagPropArray,
	hd3_in const HD3Mask* pMaskArray,
	hd3_in const char* szDataNodeName,
	hd3_out uint32* pTagIDArray,
	hd3_out int32* pErrCodeArray
	);

/**
* @brief 修改报警点
* 不可修改项：[change date][change][tagid][creation date]
* [creator][tag type][tag class][source tag][autoack]
*
* @param nTagID [TagID]
* @param pProp [属性]
* @param pMask [掩码]
* @return RD_SUCCESS, if success; hd3 error, otherwise
* @version 03/13/2015 g.l. modified version
*/
HD3_API
int32 am3_modify_tag_prop(
	hd3_in uint32 nTagID,
	hd3_in const HD3AlarmTagProp* pProp,
	hd3_in const HD3Mask* pMask
	);

/**
* @brief 修改报警点（批量接口）
* @param nTagNum [点个数]
* @param pTagIDArray [TagID数组]
* @param pTagPropArray [属性数组]
* @param pMaskArray [掩码数组]
* @param pErrCodeArray [错误码数组]
* @return RD_SUCCESS, if all success
*       EC_HD3_API_BATCH_REQUEST, if some failed
*       hd3 error, otherwise
* @version 03/13/2015 g.l. modified version
*/
HD3_API
int32 am3_modify_tags_prop(
	hd3_in int32 nTagNum,
	hd3_in const uint32* pTagIDArray,
	hd3_in const HD3AlarmTagProp* pTagPropArray,
	hd3_in const HD3Mask* pMaskArray,
	hd3_out int32* pErrCodeArray
	);

/**
* @brief 根据TagID查询报警点属性
* @param nTagID [TagID]
* @param pTagProp [属性]
* @return RD_SUCCESS, if success; hd3 error, otherwise
* @version 03/13/2015 g.l. modified version
*/
HD3_API
int32 am3_query_tag_prop(
	hd3_in uint32 nTagID,
	hd3_out HD3AlarmTagProp* pProp
	);

/**
* @brief 条件查询满足过滤项的报警点的属性
* @param pSet [过滤项集合]
* @param pMask [属性掩码]
* @param phResultSet [结果集句柄]
*  取结果项: ut3_get_item_step(hdResultSet, HD3AlarmTagProp*)
*  请参阅本文件中ut3_get_item_step接口的说明
* @return RD_SUCCESS, if success; hd3 error, otherwise
* @version 03/13/2015 g.l. modified version
*/
HD3_API
int32 am3_query_tags_cond(
	hd3_in const HD3FilterItemSet* pSet,
	hd3_in const HD3Mask* pMask,
	hd3_out HD3HANDLE* phResultSet
	);

/**
* @brief 分页查询：条件查询满足过滤项的报警点的属性
* @param pParam [参数]
* @param phResultSet [结果集句柄]
*  取结果项: ut3_get_item_stemp(hdResultSet, HD3AlarmTagProp*)
*  请参阅本文件中ut3_get_item_step接口的说明
*  结果中的Tag按照TagID增序排序
* @return RD_SUCCESS, if success; hd3 error, otherwise
* @version 03/13/2015 g.l. modified version
*/
HD3_API
int32 am3_query_specify_page_tags_cond(
	hd3_in const HD3PageQueryTagParam* pParam,
	hd3_out HD3HANDLE* phResultSet
	);

/**
* @brief 添加报警组
* @param pGroup [报警组]
* @param pnGroupID [报警组ID]
* @return RD_SUCCESS, if success; hd3 error, otherwise
* @version 03/13/2015 g.l. modified version
*/
HD3_API
int32 am3_add_group(
	hd3_in const HD3AlarmGroup* pGroup,
	hd3_out uint32* pnGroupID
	);

/**
* @brief 根据报警组名称获取报警组ID
*  报警组的ID是唯一的，同一个父报警组下的报警组名称是不能重复的
*  根据父组ID和报警组名称可以唯一的查询到一个报警组ID
* @param szName [报警组名称]
* @param nParentID [父组ID]
* @param pnGroupID [报警组ID]
* @return RD_SUCCESS, if success; hd3 error, otherwise
* @version 03/13/2015 g.l. modified version
*/
HD3_API
int32 am3_query_group_id(
	hd3_in const char* szName,
	hd3_in uint32 nParentID,
	hd3_out uint32* pnGroupID
	);

/**
* @brief 删除报警组
*  当报警组下面有子报警组或者报警点时，该报警组不能被删除
* @param nGroupID [报警组ID]
* @return RD_SUCCESS, if success; hd3 error, otherwise
* @version 03/13/2015 g.l. modified version
*/
HD3_API
int32 am3_delete_group(hd3_in uint32 nGroupID);

/**
* @brief 修改报警组
*  同一个报警组下面的两个子报警组的名称不能相同
* @param nGroupID [报警组ID]
* @param pGroup [报警组]
* @return RD_SUCCESS, if success; hd3 error, otherwise
* @version 03/13/2015 g.l. modified version
*/
HD3_API
int32 am3_modify_group(
	hd3_in uint32 nGroupID,
	hd3_in const HD3AlarmGroup* pGroup);

/**
* @brief 查询报警组属性（批量接口）
* @param nGroupNum [报警组个数]
* @param pGroupIDArray [报警组ID数组]
* @param pGroupArray [报警组数组]
* @param pErrCodeArray [错误码数组]
* @return RD_SUCCESS, if success
*       EC_HD3_API_BATCH_REQUEST, if some failed
*       hd3 error, otherwise
* @version 03/13/2015 g.l. modified version
*/
HD3_API
int32 am3_query_group_props(
	hd3_in int32 nGroupNum,
	hd3_in const uint32* pGroupIDArray,
	hd3_out HD3AlarmGroup* pGroupArray,
	hd3_out int32* pErrCodeArray
	);

/**
* @brief 查询报警组下报警点
* @param nGroupID [报警组ID]
* @param phResultSet [结果集句柄]
*  取结果项: ut3_get_item_stemp(hResultSet, uint32*)
*  请参阅本文件中ut3_get_item_step接口的说明
*  结果中按照TagID增序排序
* @return RD_SUCCESS, if success; hd3 error, otherwise
* @version 03/13/2015 g.l. modified version
*/
HD3_API
int32 am3_query_group_child_tags(
	hd3_in uint32 nGroupID,
	hd3_out HD3HANDLE* phResultSet
	);

/**
* @brief 查询报警组子组
* @param nGroupID [父组ID]
* @param phResultSet [结果集句柄]
* 取结果项: ut3_get_item_stemp(hResultSet, uint32*)
*  请参阅本文件中ut3_get_item_step接口的说明
*  结果中按照报警组ID增序排序
* @return RD_SUCCESS, if success; hd3 error, otherwise
* @version 03/13/2015 g.l. modified version
*/
HD3_API
int32 am3_query_group_child_groups(
	hd3_in uint32 nGroupID,
	hd3_out HD3HANDLE* phResultSet
	);

/**
* @brief 获取实时报警
* @param nRecNum [报警个数]
* @param pTagIDArray [TagID数组]
* @param nMask [报警掩码]
* @param pRecArray [报警数组]
* @param pErrCodeArray [错误码数组]
* @return RD_SUCCESS, if success; hd3 error, otherwise
* @version 03/13/2015 g.l. modified version
*/
HD3_API
int32 am3_query_snapshots(
	hd3_in int32 nRecNum,
	hd3_in uint32* pTagIDArray,
	hd3_in int64 nMask,
	hd3_out HD3AlarmRecord* pRecArray,
	hd3_out int32* pErrCodeArray
	);

/**
* @brief 查询历史报警
* @param nTagID [TagID]
* @param pQuery [查询条件]
* @param nMask [报警掩码]
* @param phResultSet [结果集句柄]
*  取结果项: ut3_get_item_stemp(hResultSet, HD3AlarmRecord*)
*  请参阅本文件中ut3_get_item_step接口的说明
*  结果项按照报警记录开始时间的降序排序
* @return RD_SUCCESS, if success; hd3 error, otherwise
* @version 03/13/2015 g.l. modified version
*/
HD3_API
int32 am3_query_tag_records(
	hd3_in uint32 nTagID,
	hd3_in const HD3AlarmQuery* pQuery,
	hd3_in int64 nMask,
	hd3_out HD3HANDLE* phResultSet
	);

/**
* @brief 查询历史报警（批量接口）
* @param nTagNum [Tag个数]
* @param pTagIDArray [TagID数组]
* @param pQuery [查询条件]
* @param nMask [报警掩码]
* @param phResultSet [结果集句柄]
*  取结果项: ut3_get_item_stemp(hResultSet, HD3AlarmRecord*)
*  请参阅本文件中ut3_get_item_step接口的说明
*  结果项中首先按照数据节点ID增序分组TagID，然后按照报警记录开始时间的降序排序
* @return RD_SUCCESS, if success; hd3 error, otherwise
* @version 03/13/2015 g.l. modified version
*/
HD3_API
int32 am3_query_tags_all_records(
	hd3_in int32 nTagNum,
	hd3_in const uint32* pTagIDArray,
	hd3_in const HD3AlarmQuery* pQuery,
	hd3_in int64 nMask,
	hd3_out HD3HANDLE* phResultSet
	);

/**
* @brief 查询报警组下报警
* @param nAlarmGroupID [报警组ID]
* @param pQuery [查询条件]
* @param nMask [报警掩码]
* @param phResultSet [结果集句柄]
*  取结果项: ut3_get_item_stemp(hResultSet, HD3AlarmRecord*)
*  请参阅本文件中ut3_get_item_step接口的说明
*  结果项中按照数据节点ID增序排序
* @return RD_SUCCESS, if success; hd3 error, otherwise
* @version 03/13/2015 g.l. modified version
*/
HD3_API
int32 am3_query_group_records(
	hd3_in uint32 nAlarmGroupID,
	hd3_in const HD3AlarmQuery* pQuery,
	hd3_in int64 nMask,
	hd3_out HD3HANDLE* pResultSet
	);

/**
* @brief 确认报警（批量接口）
* 该报警点在指定时刻产生的报警记录的确认状态被修改为已确认
* @param nAckNum [报警个数]
* @param pTagIDArray [TagID数组]
* @param pTimeArray [时间数组]
* @param pErrCodeArray [错误码数组]
* @return RD_SUCCESS, if all success
*       EC_HD3_API_BATCH_REQUEST, if some failed
*       hd3 error, otherwise
* @version 03/13/2015 g.l. modified version
*/
HD3_API
int32 am3_acknowledge_alarms(
	hd3_in int32 nAckNum,
	hd3_in const uint32* pTagIDArray,
	hd3_in const HD3Time* pTimeArray,
	hd3_out int32* pErrCodeArray
	);

/**
* @brief 注释报警（批量接口）
* @param nCommentNum [报警个数]
* @param pTagIDArray [TagID数组]
* @param pTimeArray [时间数组]
* @param szComment [注释]
* @param pErrCodeArray [错误码数组]
* @return RD_SUCCESS, if success; hd3 error, otherwise
* @version 03/13/2015 g.l. modified version
*/
HD3_API
int32 am3_comment_alarms(
	hd3_in int32 nCommentNum,
	hd3_in const uint32* pTagIDArray,
	hd3_in const HD3Time* pTimeArray,
	hd3_in const char* szComment,
	hd3_out int32* pErrCodeArray
	);

/**
* @brief 归档数据：查询原始记录
*  该接口的时间戳精确到秒
*  例如：开始时间为“2001-1-1 08:08:08. 111”，
*  结束时间是为“2001-1-2 08:08:08. 222”，
*  查询到的记录是“2001-1-1 08:08:08. 000”到
*  “2001-1-2 08:08:08. 000”范围内的原始记录
* @param nTagID [TagID]
* @param pRegion [时间区间]
* @param pRecNum [记录个数；in：capacity；out：size]
* @param pRecArray [记录数组]
*  如果为string或blob类型的Tag，必须进行如下赋值
*  (a) 为HD3Record.value.strBlob.pBuf分配1000字节内存
*  (b) 赋值HD3Record.value.strBlob.nLenBuf = 1000
* @return RD_SUCCESS, if success;
*    return hd3 error, otherwise
* @version 03/13/2015 g.l. modified version
*/
HD3_API
int32 ar3_query_raw_records(
	hd3_in uint32 nTagID,
	hd3_in const HD3TimeRegion* pRegion,
	hd3_inout int32* pRecNum,
	hd3_out HD3Record* pRecArray
	);

/**
* @brief 归档数据：查询单点指定插值模式的插值记录
*  8种数据类型都支持插值查询。
*  插值时，选定的插值时刻，需要前后都有好的原始记录，方可插值，
*  此外如果插值时间点正好等于原始记录的时间戳，则此数据也能插值得到；
*  如果是最后一个点，那么在大于最后这点的时间戳的时刻进行插值是无法得到数据记录的，
*  因为此时后面的原始数据时没有的，这种原理类似于线性函数两个点之间的插值，
*  如果中间那个店（即插值点）的后一个点还没有原始数据，那么，这个点做插值，就无法插值成功。
*  对于普通点，如果要获取某一秒的数据，一般插值会使用这一秒的999毫秒来进行插值。
*  比如实际存储的两条记录时间戳为1'1ms, 2'1ms，如果用户想要获取2'时的数据，
*  那么传进来进行插值的时间戳使用2'999ms，
*  则基本上2'的数据都能被插值得到（在999ms之前的点都可以通过前点插值得到），
*  因此一般建议插值时ms取为999ms
* @param nMode [插值模式]
* @param nTagID [TagID]
* @param pRec [记录；in：Time]
*  如果为string或blob类型的Tag，必须进行如下赋值
*   (a) 为HD3Record.value.strBlob.pBuf分配1000字节内存
*   (b) 赋值HD3Record.value.strBlob.nLenBuf = 1000
* @return RD_SUCCESS, if success
*    hd3 error, otherwise
* @version 03/13/2015 g.l. modified version
*/
HD3_API
int32 ar3_query_interp_record_by_mode(
	hd3_in enum HD3_REC_INTERP_QUERY_MODE nMode,
	hd3_in uint32 nTagID,
	hd3_inout HD3Record* pRec
	);

/**
* @brief 归档数据：查询单点指定插值模式的插值记录（批量接口）
*  有关插值的概念请参见ar3_query_interp_record_by_mode()函数注释
* @param nMode [插值模式]
* @param nTagID [TagID]
* @param nRecNum [记录个数]
* @param pRecArray [记录数组；in：Time]
*  如果为string或blob类型的Tag，必须进行如下赋值
*   (a) 为HD3Record.value.strBlob.pBuf分配1000字节内存
*   (b) 赋值HD3Record.value.strBlob.nLenBuf = 1000
* @param pErrCodeArray [错误码数组]
* @return RD_SUCCESS, if all success
*       EC_HD3_API_BATCH_REQUEST, if some failed
*       hd3 error, otherwise
* @version 03/13/2015 g.l. modified version
*/
HD3_API
int32 ar3_query_interp_records_by_mode(
	hd3_in enum HD3_REC_INTERP_QUERY_MODE nMode,
	hd3_in uint32 nTagID,
	hd3_in int32 nRecNum,
	hd3_inout HD3Record* pRecArray,
	hd3_out int32* pErrCodeArray
	);

/**
* @brief 归档数据：查询多点指定插值模式的插值记录（批量接口）
*  有关插值的概念请参见ar3_query_interp_record_by_mode()函数注释
* @param nMode [插值模式]
* @param nRecNum [记录个数]
* @param pTagIDArray [TagID数组]
* @param pRecArray [记录数组；in：Time]
* @param pErrCodeArray [错误码数组]
* @return RD_SUCCESS, if all success
*       EC_HD3_API_BATCH_REQUEST, if some failed
*       hd3 error, otherwise
* @version 03/13/2015 g.l. modified version
*/
HD3_API
int32 ar3_query_tags_interp_records_by_mode(
	hd3_in enum HD3_REC_INTERP_QUERY_MODE nMode,
	hd3_in int32 nRecNum,
	hd3_in const uint32* pTagIDArray,
	hd3_inout HD3Record* pRecArray,
	hd3_out int32* pErrCodeArray
	);

/**
* @brief 归档数据：删除记录
*  一旦记录被删除就无法恢复
* @param nTagID [TagID]
* @param pTime [记录的时间]
* @return RD_SUCCESS, if success; hd3 error, otherwise
* @version 03/13/2015 g.l. modified version
*/
HD3_API
int32 ar3_delete_record(
	hd3_in uint32 nTagID,
	hd3_in const HD3Time* pTime
	);

/**
* @brief 归档数据：修改记录
*  一旦修改成功原来的归档记录无法恢复。 
* @param nTagID [TagID]
* @param pRec [记录]
* @return RD_SUCCESS, if success; hd3 error, otherwise
* @version 03/13/2015 g.l. modified version
*/
HD3_API
int32 ar3_modify_record(
	hd3_in uint32 nTagID,
	hd3_in const HD3Record* pRec
	);

/**
* @brief 归档数据：查询指定个数原始记录
* @param nTagID [TagID]
* @param pTime [起始时间]
* @param bHistorical [是否为历史方向]
* @param pQueryRecNum [记录个数；in：capacity, out: size]
* @param pRecArray [记录数组]
* @return RD_SUCCESS, if success; hd3 error, otherwise
* @version 03/13/2015 g.l. modified version
*/
HD3_API
int32 ar3_query_specify_num_raw_recs(
	hd3_in uint32 nTagID,
	hd3_in const HD3Time* pTime,
	hd3_in bool bHistorical,
	hd3_inout int32* pQueryRecNum,
	hd3_out HD3Record* pRecArray
	);

/**
* @brief 归档数据：查询指定范围的原始记录个数
* @param nTagID [TagID]
* @param pRegion [时间范围]
* @param pnRecNum [记录个数]
* @return RD_SUCCESS, if success; hd3 error, otherwise
* @version
*/
HD3_API
int32 ar3_query_raw_records_number(
	hd3_in uint32 nTagID,
	hd3_in const HD3TimeRegion* pRegion,
	hd3_out int32* pnRecNum
	);

/**
* @brief 添加计算点
* @param pTagProp [点属性]
* @param pMask [属性掩码]
* @param szDataNodeName 节点名称, 如果要求将点到指定的数据节点，传入该数据节点名称，如果不要求传入NULL或者""
* @param pnTagID [添加成功，该点对应的ID]
* @return RD_SUCCESS, if success; hd3 error, otherwise
* @version 03/13/2015 g.l. modified version
*/
HD3_API
int32 ca3_add_tag(
	hd3_in const HD3CalcTagProp* pTagProp,
	hd3_in const HD3Mask* pMask,
	hd3_in const char* szDataNodeName,
	hd3_out uint32* pnTagID
	);

/**
* @brief 添加计算点（批量接口）
* @param nTagNum [点个数]
* @param pTagPropArray [属性数组]
* @param pMaskArray [掩码数组]
* @param szDataNodeName 节点名称, 如果要求将点到指定的数据节点，传入该数据节点名称，如果不要求传入NULL或者""
* @param pTagIDArray [TagID数组]
* @param pErrCodeArray [错误码数组]
* @return RD_SUCCESS, if all success
*       EC_HD3_API_BATCH_REQUEST, if some failed
*       hd3 error, otherwise
* @version 03/13/2015 g.l. modified version
*/
HD3_API
int32 ca3_add_tags(
	hd3_in int32 nTagNum,
	hd3_in const HD3CalcTagProp* pTagPropArray,
	hd3_in const HD3Mask* pMaskArray,
	hd3_in const char* szDataNodeName,
	hd3_out uint32* pTagIDArray,
	hd3_out int32* pErrCodeArray
	);

/**
* @brief 修改计算点
* @param nTagID [TagID]
* @param pProp [属性]
* @param pMask [掩码]
* @return RD_SUCCESS, if success; hd3 error, otherwise
* @version 03/13/2015 g.l. modified version
*/
HD3_API
int32 ca3_modify_tag_prop(
	hd3_in uint32 nTagID,
	hd3_in const HD3CalcTagProp* pProp,
	hd3_in const HD3Mask* pMask
	);

/**
* @brief 修改计算点（批量接口）
* @param nTagNum [点个数]
* @param pTagIDArray [TagID数组]
* @param pTagPropArray [属性数组]
* @param pMaskArray [掩码数组]
* @param pErrCodeArray [错误码数组]
* @return RD_SUCCESS, if all success
*       EC_HD3_API_BATCH_REQUEST, if some failed
*       hd3 error, otherwise
* @version 03/13/2015 g.l. modified version
*/
HD3_API
int32 ca3_modify_tags_prop(
	hd3_in int32 nTagNum,
	hd3_in const uint32* pTagIDArray,
	hd3_in const HD3CalcTagProp* pTagPropArray,
	hd3_in const HD3Mask* pMaskArray,
	hd3_out int32* pErrCodeArray
	);

/**
* @brief 根据TagID查询计算点属性
* @param nTagID [TagID]
* @param pTagProp [属性]
* @return RD_SUCCESS, if success; hd3 error, otherwise
* @version 03/13/2015 g.l. modified version
*/
HD3_API
int32 ca3_query_tag_prop(
	hd3_in uint32 nTagID,
	hd3_out HD3CalcTagProp* pTagProp
	);

/**
* @brief 条件查询满足过滤项的计算点的属性
* @param pSet [过滤项集合]
* @param pMask [属性掩码]
* @param pResultSet [结果集句柄]
*   取结果项: ut3_get_item_step(hResultSet, HD3PCaTagProp*)
*  请参阅本文件中ut3_get_item_step接口的说明
*  结果中的Tag按照TagID增序排序
* @return RD_SUCCESS, if success; hd3 error, otherwise
* @version 03/13/2015 g.l. modified version
*/
HD3_API
int32 ca3_query_tags_cond(
	hd3_in const HD3FilterItemSet* pSet,
	hd3_in const HD3Mask* pMask,
	hd3_out HD3HANDLE* phResultSet
	);

/**
* @brief 分页查询：条件查询满足过滤项的普通点的属性
* @param pParam [参数]
* @param phResultSet [结果集句柄]
*  取结果项: ut3_get_item_step(hResultSet, HD3PCaTagProp*)
*  请参阅本文件中ut3_get_item_step接口的说明
*  结果中的Tag按照TagID增序排序
* @return RD_SUCCESS, if success; hd3 error, otherwise
* @version 03/13/2015 g.l. modified version
*/
HD3_API
int32 ca3_query_specify_page_tags_cond(
	hd3_in const HD3PageQueryTagParam* pParam,
	hd3_out HD3HANDLE* phResultSet
	);

/**
* @brief 添加采集器
* @param pCollector [采集器]
* @param pnID [采集器ID]
* @return RD_SUCCESS, if success; hd3 error, otherwise
* @version 03/13/2015 g.l. modified version
*/
HD3_API
int32 ct3_add_collector(
	hd3_in const HD3Collector* pCollector,
	hd3_out uint32* pnCollectorID);

/**
* @brief 删除采集器
* @param nCollectorID [采集器ID]
* @return RD_SUCCESS, if success; hd3 error, otherwise
* @version 03/13/2015 g.l. modified version
*/
HD3_API
int32 ct3_delete_collector(hd3_in uint32 nCollectorID);

/**
* @brief 查询所有采集器
* @param phResultSet [结果集句柄]
*  取结果项: ut3_get_item_step(hResultSet, HD3Collector*)
*  请参阅本文件中ut3_get_item_step接口的说明
*  结果中的采集器按照ID增序排序
* @return RD_SUCCESS, if success; hd3 error, otherwise
* @version 03/13/2015 g.l. modified version
*/
HD3_API
int32 ct3_query_all_collectors(hd3_out HD3HANDLE* phResultSet);

/**
* @brief 根据采集器ID获取采集器
* @param nCollectorID [采集器ID]
* @param pCollector [采集器]
* @return RD_SUCCESS, if success; hd3 error, otherwise
* @version 03/13/2015 g.l. modified version
*/
HD3_API
int32 ct3_query_collector(
	hd3_in uint32 nCollectorID,
	hd3_out HD3Collector* pCollector
	);

/**
* @brief 根据采集器名称获取采集器ID
* @param szCollectorName [采集器名称]
* @param pnCollectorID [采集器ID]
* @return RD_SUCCESS, if success; hd3 error, otherwise
* @version 03/13/2015 g.l. modified version
*/
HD3_API
int32 ct3_query_collector_id_by_name(
	hd3_in const char* szCollectorName,
	hd3_out uint32* pnCollecotrID
	);

/**
* @brief 修改采集器
* @param nCollectorID [采集器ID]
* @param pCollector [采集器]
* @return RD_SUCCESS, if success; hd3 error, otherwise
* @version 03/13/2015 g.l. modified version
*/
HD3_API
int32 ct3_modify_collector(
	hd3_in uint32 nCollectorID,
	hd3_in const HD3Collector* pCollector
	);

/**
* @brief 添加设备
* @param pDevice [设备]
* @param pnDeviceID [DeviceID]
* @return RD_SUCCESS, if success; hd3 error, otherwise
* @version 03/13/2015 g.l. modified version
*/
HD3_API
int32 ct3_add_device(
	hd3_in const HD3Device* pDevice,
	hd3_out uint32* pnDeviceID
	);

/**
* @brief 删除设备
* @param nDeviceID [DeviceID]
* @return RD_SUCCESS, if success; hd3 error, otherwise
* @version 03/13/2015 g.l. modified version
*/
HD3_API
int32 ct3_delete_device(hd3_in uint32 nDeviceID);

/**
* @brief 根据设备ID获取设备
* @param nDeviceID [DeviceID]
* @param pDevice [设备]
* @return RD_SUCCESS, if success; hd3 error, otherwise
* @version 03/13/2015 g.l. modified version
*/
HD3_API
int32 ct3_query_device(
	hd3_in uint32 nDeviceID,
	hd3_out HD3Device* pDevice
	);

/**
* @brief 根据设备名称获取设备ID
* @param nCollectorID [CollectorID]
* @param szDeviceName [设备名称]
* @param pnDeviceID [DeviceID]
* @return RD_SUCCESS, if success; hd3 error, otherwise
* @version 03/13/2015 g.l. modified version
*/
HD3_API
int32 ct3_query_device_id_by_name(
	hd3_in uint32 nCollectorID,
	hd3_in const char* szDeviceName,
	hd3_out uint32* pnDeviceID
	);

/**
* @brief 获取采集器下所有设备
* @param nCollectorID [CollectorID]
* @param phResultSet [结果集句柄]
*  取结果项: ut3_get_item_step(hResultSet, HD3Device*)
*  请参阅本文件中ut3_get_item_step接口的说明
*  结果中的设备按照ID增序排序
* @return RD_SUCCESS, if success; hd3 error, otherwise
* @version 03/13/2015 g.l. modified version
*/
HD3_API
int32 ct3_query_devices_of_collector(
	hd3_in uint32 nCollectorID,
	hd3_out HD3HANDLE* phResultSet
	);

/**
* @brief 修改设备
* @param nDeviceID [DeviceID]
* @param pDevice [设备]
* @return RD_SUCCESS, if success; hd3 error, otherwise
* @version 03/13/2015 g.l. modified version
*/
HD3_API
int32 ct3_modify_device(
	hd3_in uint32 nDeviceID,
	hd3_in const HD3Device* pDevice
	);

/**
* @brief 添加扫描组
* @param pScanGroup [扫描组]
* @param pnScanGroupID [ScanGroupID]
* @return RD_SUCCESS, if success; hd3 error, otherwise
* @version 03/13/2015 g.l. modified version
*/
HD3_API
int32 ct3_add_scan_group(
	hd3_in const HD3ScanGroup* pScanGroup,
	hd3_out uint32* pnScanGroupID
	);

/**
* @brief 删除扫描组
* @param nScanGroupID [ScanGroupID
* @return RD_SUCCESS, if success; hd3 error, otherwise
* @version 03/13/2015 g.l. modified version
*/
HD3_API
int32 ct3_delete_scan_group(hd3_in uint32 nScanGroupID);

/**
* @brief 根据扫描组ID获取扫描组
* @param nScanGroupID [ScanGroupID]
* @param pScanGroup [扫描组]
* @return RD_SUCCESS, if success; hd3 error, otherwise
* @version 03/13/2015 g.l. modified version
*/
HD3_API
int32 ct3_query_scan_group(
	hd3_in uint32 nScanGroupID,
	hd3_out HD3ScanGroup* pScanGroup
	);

/**
* @brief 根据扫描组名称查询扫描组ID
* @param nDeviceID [DeviceID]
* @param szScanGroupName [扫描组名称]
* @param pnScanGroupID [扫描组ID]
* @return RD_SUCCESS, if success; hd3 error, otherwise
* @version 03/13/2015 g.l. modified version
*/
HD3_API
int32 ct3_query_scan_group_id_by_name(
	hd3_in uint32 nDeviceID,
	hd3_in const char* szScanGroupName,
	hd3_out uint32* pnScanGroupID
	);

/**
* @brief 获取设备下所有扫描组
* @param nDeviceID [DeviceID]
* @param phResultSet [结果集句柄]
*  取结果项: ut3_get_item_stemp(hResultSet, HD3ScanGroup*)
*  请参阅本文件中ut3_get_item_step接口的说明
*  结果中的扫描组按照ID增序排序
* @return RD_SUCCESS, if success; hd3 error, otherwise
* @version 03/13/2015 g.l. modified version
*/
HD3_API
int32 ct3_query_scan_groups_of_device(
	hd3_in uint32 nDeviceID,
	hd3_out HD3HANDLE* phResultSet
	);

/**
* @brief 修改扫描组
* @param nScanGroupID [ScanGroupID]
* @param pScanGroup [扫描组]
* @return RD_SUCCESS, if success; hd3 error, otherwise
* @version 03/13/2015 g.l. modified version
*/
HD3_API
int32 ct3_modify_scan_group(
	hd3_in uint32 nScanGroupID,
	hd3_in const HD3ScanGroup* pScanGroup
	);

/**
* @brief 更新采集器状态点
* @param nCollectorID [采集器ID]
* @param nQuality [数据质量]
* @param nActiveTagNum [关联的活动Tag点个数]
* @param pTime [更新时刻]
* @return RD_SUCCESS, if success; hd3 error, otherwise
* @version 05/12/2015 g.l. modified version
*/
HD3_API
int32 ct3_update_collector_status(
								  hd3_in uint32 nCollectorID,
								  hd3_in uint16 nQuality,
								  hd3_in int32 nActiveTagNum,
								  hd3_in const HD3Time* pTime
								  );

/**
* @brief 更新设备状态点
* @param nDeviceID [设备ID]
* @param nQuality [数据质量]
* @param nActiveTagNum [关联的活动Tag点个数]
* @param pTime [更新时刻]
* @return RD_SUCCESS, if success; hd3 error, otherwise
* @version 05/12/2015 g.l. modified version
*/
HD3_API
int32 ct3_update_device_status(
							   hd3_in uint32 nDeviceID,
							   hd3_in uint16 nQuality,
							   hd3_in int32 nActiveTagNum,
							   hd3_in const HD3Time* pTime
							   );

/**
* @brief 查询多个采集器最新状态
* @param nNum [采集器个数]
* @param pCollectorIDArray [采集器ID数组]
* @param pStatusArray [状态数组]
* @param pErrArray [错误码数组]
* @return RD_SUCCESS, if success; hd3 error, otherwise
* @version 05/12/2015 g.l. modified version
*/
HD3_API
int32 ct3_query_collectors_status(
								  hd3_in int32 nNum,
								  hd3_in const uint32* pCollectorIDArray,
								  hd3_out HD3CtStatusInfo* pStatusArray,
								  hd3_out int32* pErrArray
								  );

/**
* @brief 查询多个设备最新状态
* @param nNum [设备个数]
* @param pDeviceIDArray [设备ID数组]
* @param pStatusArray [状态数组]
* @param pErrArray [错误码数组]
* @return RD_SUCCESS, if success; hd3 error, otherwise
* @version 05/12/2015 g.l. modified version
*/
HD3_API
int32 ct3_query_devices_status(
							   hd3_in int32 nNum,
							   hd3_in const uint32* pDeviceIDArray,
							   hd3_out HD3CtStatusInfo* pStatusArray,
							   hd3_out int32* pErrArray
								  );

/**
* @brief 获取采集器状态更新间隔（用户需要多久更新一次采集器相关状态）
* @param pnInterval [间隔时间，单位秒]
* @return RD_SUCCESS, if success; hd3 error, otherwise
* @version 05/12/2015 g.l. modified version
*/
HD3_API
int32 ct3_get_status_update_interval(hd3_out int32* pnInterval);

/**
* @brief 连接配置中心
*  连接成功后，若不再使用API，必须调用nt3_disconnect()
*  也就是说，连接和断开必须成对使用
* @param pInfo [连接参数]
* @return RD_SUCCESS, if success; hd3 error, otherwise
*    if success, user must call nt3_disconnect() to disconnect server
* @version 03/13/2015 g.l. modified version
*/
HD3_API
int32 nt3_connect(hd3_in const HD3Connection* pInfo);

/**
* @brief 断开连接
*  请参考nt3_connect()的注释
* @return RD_SUCCESS, if success; hd3 error, otherwise
* @version 03/13/2015 g.l. modified version
*/
HD3_API
int32 nt3_disconnect();

/**
* @brief 添加普通点
*  添加普通点时，点的名称和点的类型必须添加
* @param pTagProp [点属性]
* @param pMask [属性掩码]
* @param szDataNodeName 节点名称, 如果要求将点到指定的数据节点，传入该数据节点名称，如果不要求传入NULL或者""
* @param pnTagID [添加成功，该点对应的ID]
* @return RD_SUCCESS, if success; hd3 error, otherwise
* @version 03/13/2015 g.l. modified version
*/
HD3_API
int32 pt3_add_tag(
	hd3_in const HD3PtTagProp* pTagProp,
	hd3_in const HD3Mask* pMask,
	hd3_in const char* szDataNodeName,
	hd3_out uint32* pnTagID
	);

/**
* @brief 添加普通点（批量接口）
* @param nTagNum [点个数]
* @param pTagPropArray [属性数组]
* @param pMaskArray [掩码数组]
* @param szDataNodeName 节点名称, 如果要求将点到指定的数据节点，传入该数据节点名称，如果不要求传入NULL或者""
* @param pTagIDArray [TagID数组]
* @param pErrCodeArray [错误码数组]
* @return RD_SUCCESS, if all success
*       EC_HD3_API_BATCH_REQUEST, if some failed
*       hd3 error, otherwise
* @version 03/13/2015 g.l. modified version
*/
HD3_API
int32 pt3_add_tags(
	hd3_in int32 nTagNum, 
	hd3_in const HD3PtTagProp* pTagPropArray,
	hd3_in const HD3Mask* pMaskArray,
	hd3_in const char* szDataNodeName,
	hd3_out uint32* pTagIDArray,
	hd3_out int32* pErrCodeArray
	);

/**
* @brief 修改普通点
* @param nTagID [TagID]
* @param pProp [属性]
* @param pMask [掩码]
* @return RD_SUCCESS, if success; hd3 error, otherwise
* @version 03/13/2015 g.l. modified version
*/
HD3_API
int32 pt3_modify_tag_prop(
	hd3_in uint32 nTagID,
	hd3_in const HD3PtTagProp* pProp,
	hd3_in const HD3Mask* pMask
	);

/**
* @brief 修改普通点（批量接口）
* @param nTagNum [点个数]
* @param pTagIDArray [TagID数组]
* @param pTagPropArray [属性数组]
* @param pMaskArray [掩码数组]
* @param pErrCodeArray [错误码数组]
* @return RD_SUCCESS, if all success
*       EC_HD3_API_BATCH_REQUEST, if some failed
*       hd3 error, otherwise
* @version 03/13/2015 g.l. modified version
*/
HD3_API
int32 pt3_modify_tags_prop(
	hd3_in int32 nTagNum,
	hd3_in const uint32* pTagIDArray,
	hd3_in const HD3PtTagProp* pTagPropArray,
	hd3_in const HD3Mask* pMaskArray,
	hd3_out int32* pErrCodeArray
	);

/**
* @brief 根据TagID查询普通点属性
*  输出为Tag点的所有属性
* @param nTagID [TagID]
* @param pTagProp [属性]
* @return RD_SUCCESS, if success; hd3 error, otherwise
* @version 03/13/2015 g.l. modified version
*/
HD3_API
int32 pt3_query_tag_prop(
	hd3_in uint32 nTagID,
	hd3_out HD3PtTagProp* pTagProp
	);

/**
* @brief 条件查询满足过滤项的普通点的属性
* @param pSet [过滤项集合]
* @param pMask [属性掩码]
* @param pResultSet [结果集句柄]
*  取结果项: ut3_get_item_step(hResultSet, HD3PtTagProp*)
*  请参阅本文件中ut3_get_item_step接口的说明
*  结果中的Tag按照TagID增序排序
* @return RD_SUCCESS, if success; hd3 error, otherwise
* @version 03/13/2015 g.l. modified version
*/
HD3_API
int32 pt3_query_tags_cond(
	hd3_in const HD3FilterItemSet* pSet,
	hd3_in const HD3Mask* pMask,
	hd3_out HD3HANDLE* phResultSet
	);

/**
* @brief 分页查询：条件查询满足过滤项的普通点的属性
* @param pParam [参数]
* @param phResultSet [结果集句柄]
*  取结果项: ut3_get_item_step(hResultSet, HD3PtTagProp*)
*  请参阅本文件中ut3_get_item_step接口的说明
*  结果中的Tag按照TagID增序排序
* @return RD_SUCCESS, if success; hd3 error, otherwise
* @version 03/13/2015 g.l. modified version
*/
HD3_API
int32 pt3_query_specify_page_tags_cond(
	hd3_in const HD3PageQueryTagParam* pParam,
	hd3_out HD3HANDLE* phResultSet
	);

/**
* @brief 根据TagID查询Tag类型
* @param nTagID [TagID]
* @param pTagType [TagType]
* @return RD_SUCCESS, if success; hd3 error, otherwise
* @version 03/13/2015 g.l. modified version
*/
HD3_API
int32 pt3_query_tag_type(
	hd3_in uint32 nTagID,
	hd3_out enum HD3_TAG_TYPE* pTagType
	);

/**
* @brief 添加数字量状态集
*  数字量状态集名称惟一
*  本接口创建一个空的状态集，调用pt3_modify_digitalset可以给该状态集填充状态
* @param pDigitalSet [数字量状态集]
* @return RD_SUCCESS, if success; hd3 error, otherwise
* @version 05/11/2015 g.l. modified version
*/
HD3_API
int32 pt3_add_digitalset(hd3_in const HD3DigitalSet* pDigitalSet);

/**
* @brief 删除数字量状态集
* @param szDigitalSetName [数字量状态集名称]
* @return RD_SUCCESS, if success; hd3 error, otherwise
* @version 05/11/2015 g.l. modified version
*/
HD3_API
int32 pt3_delete_digitalset(hd3_in const char* szDigitalSetName);

/**
* @brief 修改数字量状态集状态
* @param pDigitalSet [数字量状态集]
* @param nStateNum [状态个数]
* @param pStateArray [数字量状态，in: szStateName, nStateValue]
* @return RD_SUCCESS, if success; hd3 error, otherwise
* @version 05/11/2015 g.l. modified version
*/
HD3_API
int32 pt3_modify_digitalset(
							 hd3_in const HD3DigitalSet* pDigitalSet,
							 hd3_in int32 nStateNum,
							 hd3_in const HD3DsStateInfo* pStateArray
							 );

/**
* @brief 查询数字量状态
* @param pDigitalSet [数字量状态集]
* @param phResultSet [结果集句柄]
* 取结果项: ut3_get_item_stemp(hdResultSet, HD3DsStateInfo*)
*  请参阅本文件中ut3_get_item_step接口的说明
*  结果中的状态按照ID增序排序
* @return RD_SUCCESS, if success; hd3 error, otherwise
* @version 05/11/2015 g.l. modified version
*/
HD3_API
int32 pt3_query_digitalset_all_state_infos(
									   hd3_in const HD3DigitalSet* pDigitalSet,
									   hd3_out HD3HANDLE* phResultSet
									   );

/**
* @brief 查询所有数字量状态集
* @param phResultSet [结果集句柄]
* 取结果项: ut3_get_item_stemp(hdResultSet, HD3DigitalSet*)
*  请参阅本文件中ut3_get_item_step接口的说明
*  结果中的状态集未定义顺序，须全部取完自行处理
* @return RD_SUCCESS, if success; hd3 error, otherwise
* @version 05/11/2015 g.l. modified version
*/
HD3_API
int32 pt3_query_all_digitalsets(hd3_out HD3HANDLE* phResultSet);

/**
* @brief 根据数字量状态值查状态名称
* @param szDSName [数字量状态集名称]
* @param nStateValue [状态值]
* @param szDSStateName [状态名称]
* @return RD_SUCCESS, if success; hd3 error, otherwise
* @version 05/11/2015 g.l. modified version
*/
HD3_API
int32 pt3_query_digitalset_state_name(hd3_in const char* szDSName, hd3_in int32 nStateValue, hd3_out char* szDSStateName);

/**
* @brief 获取采集器版本号
* @param nCollectorID [采集器ID]
* @param pnVersion [版本号]
* @return RD_SUCCESS, if success; hd3 error, otherwise
* @version 05/12/2015 g.l. modified version
*/
HD3_API
int32 pt3_get_collector_version(
								hd3_in uint32 nCollectorID,
								hd3_out uint32* pnVersion
								);

/**
* @brief 获取采集器变更记录
* @param nCollectorID [采集器ID]
* @param nStartSec [开始时间]
* @param nEndSec [结束时间]
* @param phResultSet [结果集句柄]
*  取结果项: ut3_get_item_step(hdResultSet, HD3AlterationReport*)
*  请参阅本文件中ut3_get_item_step接口的说明
*  结果中的变更记录按照ID增序排序
* @return RD_SUCCESS, if success; hd3 error, otherwise
* @version 05/12/2015 g.l. modified version
*/
HD3_API
int32 pt3_get_collector_alter_report(
									 hd3_in uint32 nCollectorID,
									 hd3_in uint32 nStartVersion,
									 hd3_in uint32 nEndVersion,
									 HD3HANDLE* phResultSet
									 );

/**
* @brief 报警服务向本数据节点hdKernel注册原始点数据推送 05/20/2015
* @param nDataNodeID [数据节点ID]
* @param nMonitorType [监视类型]
* @param nTagNum [Tag点个数]
* @param pTagIDArray [Tag点ID数组]
* @return RD_SUCCESS, if success; hd3 error, otherwise
* @version 05/20/2015 g.l. modified version
*/
HD3_API
int32 pt3_reg_monitored_tag(
							hd3_in uint32 nDataNodeID,
							hd3_in enum HD3_MONITOR_TYPE nMonitorType,
							hd3_in int32 nTagNum,
							hd3_in const uint32* pTagIDArray
							);

/**
* @brief 登录
* @param szUserName [用户]
* @param szPassword [密码]
* @return RD_SUCCESS, if success; hd3 error, otherwise
* @version 03/13/2015 g.l. modified version
*/
HD3_API
int32 sc3_login(
	hd3_in const char* szUserName,
	hd3_in const char* szPassword
	);

/**
* @brief 修改密码
* @param szUserName [用户]
* @param szOldPassword [老密码]
* @param szNewPassword [新密码]
* @return RD_SUCCESS, if success; hd3 error, otherwise
* @version 03/13/2015 g.l. modified version
*/
HD3_API
int32 sc3_modify_password(
	hd3_in const char* szUserName,
	hd3_in const char* szOldPassword,
	hd3_in const char* szNewPassword
	);

/**
* @brief 重置密码
* @param szUserName [用户]
* @param szNewPassword [新密码]
* @return RD_SUCCESS, if success; hd3 error, otherwise
* @version 03/13/2015 g.l. modified version
*/
HD3_API
int32 sc3_reset_password(
	hd3_in const char* szUserName,
	hd3_in const char* szNewPassword
	);

/**
* @brief 添加用户
* @param pUser [用户信息]
* @return RD_SUCCESS, if success; hd3 error, otherwise
* @version 03/13/2015 g.l. modified version
*/
HD3_API
int32 sc3_add_user(hd3_in const HD3SecUser* pUser);

/**
* @brief 删除用户
* @param szUserName [用户]
* @return RD_SUCCESS, if success; hd3 error, otherwise
* @version 03/13/2015 g.l. modified version
*/
HD3_API
int32 sc3_delete_user(hd3_in const char* szUserName);

/**
* @brief 添加权限组
* @param pGroup [权限组]
* @return RD_SUCCESS, if success; hd3 error, otherwise
* @version 03/13/2015 g.l. modified version
*/
HD3_API
int32 sc3_add_group(hd3_in const HD3SecGroup* pGroup);

/**
* @brief 删除权限组
* @param szGroupName [权限组]
* @return RD_SUCCESS, if success; hd3 error, otherwise
* @version 03/13/2015 g.l. modified version
*/
HD3_API
int32 sc3_delete_group(hd3_in const char* szGroupName);

/**
* @brief 关联用户与权限组
* @param szUserName [用户]
* @param szGroupName [权限组]
* @return RD_SUCCESS, if success; hd3 error, otherwise
* @version 03/13/2015 g.l. modified version
*/
HD3_API
int32 sc3_add_user_to_group(
	hd3_in const char* szUserName,
	hd3_in const char* szGroupName
	);

/**
* @brief 取消关联用户与权限组
* @param szUserName [用户]
* @param szGroupName [权限组]
* @return RD_SUCCESS, if success; hd3 error, otherwise
* @version 03/13/2015 g.l. modified version
*/
HD3_API
int32 sc3_delete_user_from_group(
	hd3_in const char* szUserName,
	hd3_in const char* szGroupName
	);

/**
* @brief 修改用户描述
* @param szUserName [用户]
* @param szNewUserDesc [描述]
* @return RD_SUCCESS, if success; hd3 error, otherwise
* @version 03/13/2015 g.l. modified version
*/
HD3_API
int32 sc3_modify_user_desc(
	hd3_in const char* szUserName,
	hd3_in const char* szNewUserDesc
	);

/**
* @brief 修改权限组描述
* @param szGroupName [权限组]
* @param szNewGroupDesc [描述]
* @return RD_SUCCESS, if success; hd3 error, otherwise
* @version 03/13/2015 g.l. modified version
*/
HD3_API
int32 sc3_modify_group_desc(
	hd3_in const char* szGroupName,
	hd3_in const char* szNewGroupDesc
	);

/**
* @brief 查询所有用户
* @param phResultSet [结果集句柄]
*  取结果项: ut3_get_item_stemp(hResultSet, HD3SecUser*)
*  请参阅本文件中ut3_get_item_step接口的说明
*  结果中的用户未定义顺序，须全部取完自行处理
* @return RD_SUCCESS, if success; hd3 error, otherwise
* @version 03/13/2015 g.l. modified version
*/
HD3_API
int32 sc3_query_all_users(hd3_out HD3HANDLE* phResultSet);

/**
* @brief 查询权限组关联的所有用户
* @param szGroupName [权限组]
* @param phResultSet [结果集句柄]
*  取结果项: ut3_get_item_step(hResultSet, HD3SecUser*)
*  请参阅本文件中ut3_get_item_step接口的说明
*  结果中的用户未定义顺序，须全部取完自行处理
* @return RD_SUCCESS, if success; hd3 error, otherwise
* @version 03/13/2015 g.l. modified version
*/
HD3_API
int32 sc3_query_members_of_group(
	hd3_in const char* szGroupName,
	hd3_out HD3HANDLE* phResultSet
	);

/**
* @brief 查询所有权限组
* @param phResultSet [结果集句柄]
*  取结果项: ut3_get_item_step(hResultSet, HD3SecGroup*)
*  请参阅本文件中ut3_get_item_step接口的说明
*  结果中的权限组未定义顺序，须全部取完自行处理
* @return RD_SUCCESS, if success; hd3 error, otherwise
* @version 03/13/2015 g.l. modified version
*/
HD3_API
int32 sc3_query_all_groups(hd3_in HD3HANDLE* phResultSet);

/**
* @brief 查询用户关联的所有权限组
* @param szUserName [用户]
* @param phResultSet [结果集句柄]
*  取结果项: ut3_get_item_step(hResultSet, HD3SecGroup*)
*  请参阅本文件中ut3_get_item_step接口的说明
*  结果中的权限组未定义顺序，须全部取完自行处理
* @return RD_SUCCESS, if success; hd3 error, otherwise
* @version 03/13/2015 g.l. modified version
*/
HD3_API
int32 sc3_query_groups_of_user(
	hd3_in const char* szUserName,
	hd3_out HD3HANDLE* phResultSet
	);

/**
* @brief 查询权限项
* @param nItemType [权限项类型]
* @param pSecItem [权限项]
* @return RD_SUCCESS, if success; hd3 error, otherwise
* @version 03/13/2015 g.l. modified version
*/
HD3_API
int32 sc3_query_manage_security(
	hd3_in enum HD3_SC_ITEM_TYPE nItemType,
	hd3_out HD3SecItem* pSecItem
	);

/**
* @brief 修改权限项
* @param nItemType [权限项类型]
* @param pSecItem [权限项]
* @return RD_SUCCESS, if success; hd3 error, otherwise
* @version 03/13/2015 g.l. modified version
*/
HD3_API
int32 sc3_modify_manage_security(
	hd3_in enum HD3_SC_ITEM_TYPE nItemType,
	hd3_in const HD3SecItem* pSecItem
	);

/**
* @brief 查询所有信任
* @param phResultSet [结果集句柄]
*  取结果项: ut3_get_item_step(hResultSet, HD3SecTrust*)
*  请参阅本文件中ut3_get_item_step接口的说明
*  结果中的信任未定义顺序，须全部取完自行处理
* @return RD_SUCCESS, if success; hd3 error, otherwise
* @version 03/13/2015 g.l. modified version
*/
HD3_API
int32 sc3_query_all_trusts(hd3_out HD3HANDLE* phResultSet);

/**
* @brief 添加信任
* @param pSecTrust [信任]
* @return RD_SUCCESS, if success; hd3 error, otherwise
* @version 03/13/2015 g.l. modified version
*/
HD3_API
int32 sc3_add_trust(hd3_in const HD3SecTrust* pSecTrust);

/**
* @brief 删除信任
* @param szTrustName [信任]
* @return RD_SUCCESS, if success; hd3 error, otherwise
* @version 03/13/2015 g.l. modified version
*/
HD3_API
int32 sc3_delete_trust(hd3_in const char* szTrustName);

/**
* @brief 查询当前用户
* @param nLen [字符串长度]
*  建议分配的字符串数组容量不小于HD3_LEN_USER_NAME * HD3_BASE
* @param szUserName [用户]
* @return RD_SUCCESS, if success
*    EC_HD3_API_USER_CHAR_LEN, if nLen <= userName.size()
*    hd3 error, otherwise
* @version 03/13/2015 g.l. modified version
*/
HD3_API
int32 sc3_query_current_user_name(
    hd3_in int32 nLen,
	hd3_out char* szUserName
);

/**
* @brief 添加授权项
* @param pAuthItem [授权项]
* @return RD_SUCCESS, if success; hd3 error, otherwise
* @version 03/13/2015 g.l. modified version
*/
HD3_API
int32 sc3_add_auth_item(hd3_in const HD3SecAuthItem* pAuthItem);

/**
* @brief 删除授权项
* @param szName [授权项]
* @return RD_SUCCESS, if success; hd3 error, otherwise
* @version 03/13/2015 g.l. modified version
*/
HD3_API
int32 sc3_delete_auth_item(hd3_in const char* szName);

/**
* @brief 修改授权项
* @param pAuthItem [授权项]
* @return RD_SUCCESS, if success; hd3 error, otherwise
* @version 03/13/2015 g.l. modified version
*/
HD3_API
int32 sc3_modify_auth_item(hd3_in const HD3SecAuthItem* pAuthItem);

/**
* @brief 关联授权项与权限组
* @param szAuthItemName [授权项]
* @param szGroupName [权限组]
* @return RD_SUCCESS, if success; hd3 error, otherwise
* @version 03/13/2015 g.l. modified version
*/
HD3_API
int32 sc3_add_auth_item_to_group(
	hd3_in const char* szAuthItemName,
	hd3_in const char* szGroupName
	);

/**
* @brief 取消关联授权项与权限组
* @param szAuthItemName [授权项]
* @param szGroupName [权限组]
* @return RD_SUCCESS, if success; hd3 error, otherwise
* @version 03/13/2015 g.l. modified version
*/
HD3_API
int32 sc3_delete_auth_item_from_group(
	hd3_in const char* szAuthItemName,
	hd3_in const char* szGroupName
	);

/**
* @brief 查询所有授权项
* @param phResultSet [结果集句柄]
*  取结果项: ut3_get_item_step(hResultSet, HD3SecAuthItem*)
*  请参阅本文件中ut3_get_item_step接口的说明
*  结果中的授权项未定义顺序，须全部取完自行处理
* @return RD_SUCCESS, if success; hd3 error, otherwise
* @version 03/13/2015 g.l. modified version
*/
HD3_API
int32 sc3_query_all_auth_items(hd3_out HD3HANDLE* phResultSet);

/**
* @brief 查询权限组关联的所有授权项
* @param szGroupName [权限组]
* @param phResultSet [结果集句柄]
*  取结果项: ut3_get_item_step(hResultSet, HD3SecAuthItem*)
*  请参阅本文件中ut3_get_item_step接口的说明
*  结果中的授权项未定义顺序，须全部取完自行处理
* @return RD_SUCCESS, if success; hd3 error, otherwise
* @version 03/13/2015 g.l. modified version
*/
HD3_API
int32 sc3_query_auth_items_of_group(
	hd3_in const char* szGroupName,
	hd3_out HD3HANDLE* phResultSet
	);

/**
* @brief 查询授权项关联的所有权限组
* @param szAuthItemName [授权项]
* @param phResultSet [结果集句柄]
*  取结果项: ut3_get_item_step(hResultSet, HD3SecGroup*)
*  请参阅本文件中ut3_get_item_step接口的说明
*  结果中的权限组未定义顺序，须全部取完自行处理
* @return RD_SUCCESS, if success; hd3 error, otherwise
* @version 03/13/2015 g.l. modified version
*/
HD3_API
int32 sc3_query_groups_of_auth_item(
	hd3_in const char* szAuthItemName,
	hd3_out HD3HANDLE* phResultSet
	);

/**
* @brief 查询用户的授权项权限
* @param szUserName [用户]
* @param szAuthItemName [授权项]
* @param pnAuth [权限]
* @return RD_SUCCESS, if success; hd3 error, otherwise
* @version 03/13/2015 g.l. modified version
*/
HD3_API
int32 sc3_query_auth_of_user(
	hd3_in const char* szUserName,
	hd3_in const char* szAuthItemName,
	hd3_out int32* pnAuth
	);

/**
* @brief 快照数据：保存单点快照记录
* @param nTagID [TagID]
* @param pRecord [记录]
* @return RD_SUCCESS, if success; hd3 error, otherwise
* @version 03/13/2015 g.l. modified version
*/
HD3_API
int32 sn3_save_snapshot(
	hd3_in uint32 nTagID,
	hd3_in const HD3Record* pRecord
	);

/**
* @brief 快照数据：保存多点快照记录（批量接口）
* @param nRecNum [记录个数]
* @param pTagIDArray [TagID数组]
* @param pRecArray [记录数组]
* @param pErrCodeArray [错误码数组]
* @return RD_SUCCESS, if all success
*       EC_HD3_API_BATCH_REQUEST, if some failed
*       hd3 error, otherwise
* @version 03/13/2015 g.l. modified version
*/
HD3_API
int32 sn3_save_snapshots(
	hd3_in int32 nRecNum,
	hd3_in const uint32* pTagIDArray,
	hd3_in const HD3Record* pRecArray,
	hd3_out int32* pErrCodeArray
	);

/**
* @brief 快照数据：保存单点乱序记录（批量接口）
* @param nRecNum [记录个数]
* @param nTagID [TagID]
* @param pRecArray [记录数组]
* @param pErrCodeArray [错误码数组]
* @return RD_SUCCESS, if all success
*       EC_HD3_API_BATCH_REQUEST, if some failed
*       hd3 error, otherwise
* @version 03/13/2015 g.l. modified version
*/
HD3_API
int32 sn3_save_disorder_snapshots(
	hd3_in int32 nRecNum,
	hd3_in uint32 nTagID,
	hd3_in const HD3Record* pRecArray,
	hd3_out int32* pErrCodeArray
	);

/**
* @brief 快照数据：保存多点乱序记录（批量接口）
* @param nRecNum [记录个数]
* @param pTagIDArray [TagID数组]
* @param pRecArray [记录数组]
* @param pErrCodeArray [错误码数组]
* @return RD_SUCCESS, if all success
*       EC_HD3_API_BATCH_REQUEST, if some failed
*       hd3 error, otherwise
* @version 03/13/2015 g.l. modified version
*/
HD3_API
int32 sn3_save_tags_disorder_snapshots(
	hd3_in int32 nRecNum,
	hd3_in const uint32* pTagIDArray,
	hd3_in const HD3Record* pRecArray,
	hd3_out int32* pErrCodeArray
	);

/**
* @brief 快照数据：查询单点实时记录
* @param nTagID [TagID]
* @param pRec [记录]
*  如果为string或blob类型的Tag，必须进行如下赋值
*   (a) 为HD3Record.value.strBlob.pBuf分配1000字节内存
*   (b) 赋值HD3Record.value.strBlob.nLenBuf = 1000
* @return RD_SUCCESS, if success; hd3 error, otherwise
* @version 03/13/2015 g.l. modified version
*/
HD3_API
int32 sn3_query_snapshot(
	hd3_in uint32 nTagID,
	hd3_out HD3Record* pRec
	);

/**
* @brief 快照数据：查询多点实时记录（批量接口）
* @param nRecNum [记录个数]
* @param pTagIDArray [TagID数组]
* @param pRecArray [记录数组]
*  如果为string或blob类型的Tag，必须进行如下赋值
*   (a) 为HD3Record.value.strBlob.pBuf分配1000字节内存
*   (b) 赋值HD3Record.value.strBlob.nLenBuf = 1000
* @param pErrCodeArray [错误码数组]
* @return RD_SUCCESS, if all success
*       EC_HD3_API_BATCH_REQUEST, if some failed
*       hd3 error, otherwise
* @version 03/13/2015 g.l. modified version
*/
HD3_API
int32 sn3_query_snapshots(
	hd3_in int32 nRecNum,
	hd3_in const uint32* pTagIDArray,
	hd3_out HD3Record* pRecordArray,
	hd3_out int32* pErrCodeArray
	);

/**
* @brief 注册SPC记录回调，用于被动接收SPC记录
* @param pfn [回调函数的指针]
*  nChange [SPC报警变更类型]
*  pRecord [SPC记录]
* @return RD_SUCCESS, if success; hd3 error, otherwise
* @version 05/14/2015 g.l. modified version
*/
typedef void (*HD3SpcCallbackFUnc)(
									 hd3_in enum HD3_AM_CHANGE nChange,
									 hd3_in const HD3SpcRecord* pRecord);
HD3_API
int32 spc3_register_alarm_record_info(hd3_in HD3SpcCallbackFUnc pfn);
HD3_API
int32 spc3_unregister_alarm_record_info();

/**
* @brief 添加SPC点
* @param pTagProp [点属性]
* @param pMask [属性掩码]
* @param szDataNodeName 节点名称, 如果要求将点到指定的数据节点，传入该数据节点名称，如果不要求传入NULL或者""
* @param pnTagID [添加成功，该点对应的ID]
* @return RD_SUCCESS, if success; hd3 error, otherwise
* @version 03/13/2015 g.l. modified version
*/
HD3_API
int32 spc3_add_tag(
	hd3_in const HD3SpcTagProp* pTagProp,
	hd3_in const HD3Mask* pMask,
	hd3_in const char* szDataNodeName,
	hd3_out uint32* pnTagID
	);

/**
* @brief 添加SPC点（批量接口）
* @param nTagNum [点个数]
* @param pTagPropArray [属性数组]
* @param pMaskArray [掩码数组]
* @param szDataNodeName 节点名称, 如果要求将点到指定的数据节点，传入该数据节点名称，如果不要求传入NULL或者""
* @param pTagIDArray [TagID数组]
* @param pErrCodeArray [错误码数组]
* @return RD_SUCCESS, if all success
*       EC_HD3_API_BATCH_REQUEST, if some failed
*       hd3 error, otherwise
* @version 03/13/2015 g.l. modified version
*/
HD3_API
int32 spc3_add_tags(
	hd3_in int32 nTagNum,
	hd3_in const HD3SpcTagProp* pTagPropArray,
	hd3_in const HD3Mask* pMaskArray,
	hd3_in const char* szDataNodeName,
	hd3_out uint32* pTagIDArray,
	hd3_out int32* pErrCodeArray
	);

/**
* @brief 修改SPC点
* @param nTagID [TagID]
* @param pProp [属性]
* @param pMask [掩码]
* @return RD_SUCCESS, if success; hd3 error, otherwise
* @version 03/13/2015 g.l. modified version
*/
HD3_API
int32 spc3_modify_tag_prop(
	hd3_in uint32 nTagID,
	hd3_in const HD3SpcTagProp* pProp,
	hd3_in const HD3Mask* pMask
	);

/**
* @brief 修改SPC点（批量接口）
* @param nTagNum [点个数]
* @param pTagIDArray [TagID数组]
* @param pTagPropArray [属性数组]
* @param pMaskArray [掩码数组]
* @param pErrCodeArray [错误码数组]
* @return RD_SUCCESS, if all success
*       EC_HD3_API_BATCH_REQUEST, if some failed
*       hd3 error, otherwise
* @version 03/13/2015 g.l. modified version
*/
HD3_API
int32 spc3_modify_tags_prop(
	hd3_in int32 nTagNum,
	hd3_in const uint32* pTagIDArray,
	hd3_in const HD3SpcTagProp* pTagPropArray,
	hd3_in const HD3Mask* pMaskArray,
	hd3_out int32* pErrCodeArray
	);

/**
* @brief 根据TagID查询SPC点属性
* @param nTagID [TagID]
* @param pTagProp [属性]
* @return RD_SUCCESS, if success; hd3 error, otherwise
* @version 03/13/2015 g.l. modified version
*/
HD3_API
int32 spc3_query_tag_prop(
	hd3_in uint32 nTagID,
	hd3_out HD3SpcTagProp* pTagProp
	);

/**
* @brief 条件查询满足过滤项的SPC点的属性
* @param pSet [过滤项集合]
* @param pMask [属性掩码]
* @param phResultSet [结果集句柄]
*  取结果项: ut3_get_item_stemp(hResultSet, HD3SpcTagProp*)
*  请参阅本文件中ut3_get_item_step接口的说明
*  结果中的Tag按照TagID增序排序
* @return RD_SUCCESS, if success; hd3 error, otherwise
* @version 03/13/2015 g.l. modified version
*/
HD3_API
int32 spc3_query_tags_cond(
	hd3_in const HD3FilterItemSet* pSet,
	hd3_in const HD3Mask* pMask,
	hd3_out HD3HANDLE* phResultSet
	);

/**
* @brief 分页查询：条件查询满足过滤项的SPC点的属性
* @param pParam [参数]
* @param phResultSet [结果集句柄]
*  取结果项: ut3_get_item_stemp(hResultSet, HD3SpcTagProp*)
*  请参阅本文件中ut3_get_item_step接口的说明
*  结果中的Tag按照TagID增序排序
* @return RD_SUCCESS, if success; hd3 error, otherwise
* @version 03/13/2015 g.l. modified version
*/
HD3_API
int32 spc3_query_specify_page_tags_cond(
	hd3_in const HD3PageQueryTagParam* pParam,
	hd3_out HD3HANDLE* phResultSet
	);

/**
* @brief 获取报警组下所有SPC点
* @param nGroupID [报警组ID]
* @param phResultSet [结果集句柄]
*  取结果项: ut3_get_item_step(hResultSet, uint32*)
*  请参阅本文件中ut3_get_item_step接口的说明
*  结果中TagID增序排序
* @return RD_SUCCESS, if success; hd3 error, otherwise
* @version 03/13/2015 g.l. modified version
*/
HD3_API
int32 spc3_query_group_child_tags(
	hd3_in uint32 nGroupID,
	hd3_out HD3HANDLE* phResultSet
	);

/**
* @brief 获取实时SPC报警
* @param nRecNum [SPC报警个数]
* @param pTagIDArray [TagID数组]
* @param nMask [SPC报警掩码]
* @param pRecArray [SPC报警数组]
* @param pErrCodeArray [错误码数组]
* @return RD_SUCCESS, if success; hd3 error, otherwise
* @version 05/13/2015 g.l. modified version
*/
HD3_API
int32 spc3_query_snapshots(
						  hd3_in int32 nRecNum,
						  hd3_in uint32* pTagIDArray,
						  hd3_in int64 nMask,
						  hd3_out HD3SpcRecord* pRecArray,
						  hd3_out int32* pErrCodeArray
						  );

/**
* @brief 查询历史SPC报警
* @param nTagID [TagID]
* @param pQuery [查询条件]
* @param nMask [SPC报警掩码]
* @param phResultSet [结果集句柄]
*  取结果项: ut3_get_item_stemp(hResultSet, HD3SpcRecord*)
*  请参阅本文件中ut3_get_item_step接口的说明
*  结果项按照SPC记录开始时间的降序排序
* @return RD_SUCCESS, if success; hd3 error, otherwise
* @version 05/13/2015 g.l. modified version
*/
HD3_API
int32 spc3_query_tag_records(
							hd3_in uint32 nTagID,
							hd3_in const HD3SPCQuery* pQuery,
							hd3_in int64 nMask,
							hd3_out HD3HANDLE* phResultSet
							);

/**
* @brief 查询历史SPC报警（批量接口）
* @param nTagNum [Tag个数]
* @param pTagIDArray [TagID数组]
* @param pQuery [查询条件]
* @param nMask [SPC报警掩码]
* @param phResultSet [结果集句柄]
*  取结果项: ut3_get_item_stemp(hResultSet, HD3SpcRecord*)
*  请参阅本文件中ut3_get_item_step接口的说明
*  结果项按照SPC记录开始时间的降序排序
* @return RD_SUCCESS, if success; hd3 error, otherwise
* @version 05/13/2015 g.l. modified version
*/
HD3_API
int32 spc3_query_tags_all_records(
								 hd3_in int32 nTagNum,
								 hd3_in const uint32* pTagIDArray,
								 hd3_in const HD3SPCQuery* pQuery,
								 hd3_in int64 nMask,
								 hd3_out HD3HANDLE* phResultSet
								 );

/**
* @brief 查询报警组下SPC报警
* @param nAlarmGroupID [报警组ID]
* @param pQuery [查询条件]
* @param nMask [SPC报警掩码]
* @param phResultSet [结果集句柄]
*  fetch: ut3_get_item_stemp(hResultSet, HD3SpcRecord*)
*  请参阅本文件中ut3_get_item_step接口的说明
*  结果项先按照Tag点增序，然后按照SPC记录开始时间的降序排序
* @return RD_SUCCESS, if success; hd3 error, otherwise
* @version 05/13/2015 g.l. modified version
*/
HD3_API
int32 spc3_query_group_records(
							  hd3_in uint32 nAlarmGroupID,
							  hd3_in const HD3SPCQuery* pQuery,
							  hd3_in int64 nMask,
							  hd3_out HD3HANDLE* pResultSet
							  );

/**
* @brief 确认SPC报警（批量接口）
* @param nAckNum [SPC报警个数]
* @param pTagIDArray [TagID数组]
* @param pTimeArray [时间数组]
* @param pErrCodeArray [错误码数组]
* @return RD_SUCCESS, if all success
*       EC_HD3_API_BATCH_REQUEST, if some failed
*       hd3 error, otherwise
* @version 05/13/2015 g.l. modified version
*/
HD3_API
int32 spc3_acknowledge_alarms(
							 hd3_in int32 nAckNum,
							 hd3_in const uint32* pTagIDArray,
							 hd3_in const HD3Time* pTimeArray,
							 hd3_out int32* pErrCodeArray
							 );

/**
* @brief 注释SPC报警（批量接口）
* @param nCommentNum [SPC报警个数]
* @param pTagIDArray [TagID数组]
* @param pTimeArray [时间数组]
* @param szComment [注释]
* @param pErrCodeArray [错误码数组]
* @return RD_SUCCESS, if success; hd3 error, otherwise
* @version 03/13/2015 g.l. modified version
*/
HD3_API
int32 spc3_comment_alarms(
						 hd3_in int32 nCommentNum,
						 hd3_in const uint32* pTagIDArray,
						 hd3_in const HD3Time* pTimeArray,
						 hd3_in const char* szComment,
						 hd3_out int32* pErrCodeArray
						 );

/**
* @brief 添加统计点
* @param pTagProp [点属性]
* @param pMask [属性掩码]
* @param szDataNodeName 节点名称, 如果要求将点到指定的数据节点，传入该数据节点名称，如果不要求传入NULL或者""
* @param pnTagID [添加成功，该点对应的ID]
* @return RD_SUCCESS, if success; hd3 error, otherwise
* @version 03/13/2015 g.l. modified version
*/
HD3_API
int32 st3_add_tag(
	hd3_in const HD3StatsTagProp* pTagProp,
	hd3_in const HD3Mask* pMask,
	hd3_in const char* szDataNodeName,
	hd3_out uint32* pnTagID
	);

/**
* @brief 添加统计点（批量接口）
* @param nTagNum [点个数]
* @param pTagPropArray [属性数组]
* @param pMaskArray [掩码数组]
* @param szDataNodeName 节点名称, 如果要求将点到指定的数据节点，传入该数据节点名称，如果不要求传入NULL或者""
* @param pTagIDArray [TagID数组]
* @param pErrCodeArray [错误码数组]
* @return RD_SUCCESS, if all success
*       EC_HD3_API_BATCH_REQUEST, if some failed
*       hd3 error, otherwise
* @version 03/13/2015 g.l. modified version
*/
HD3_API
int32 st3_add_tags(
	hd3_in int32 nTagNum,
	hd3_in const HD3StatsTagProp* pTagPropArray,
	hd3_in const HD3Mask* pMaskArray,
	hd3_in const char* szDataNodeName,
	hd3_out uint32* pTagIDArray,
	hd3_out int32* pErrCodeArray
	);

/**
* @brief 修改统计点
* @param nTagID [TagID]
* @param pProp [属性]
* @param pMask [掩码]
* @return RD_SUCCESS, if success; hd3 error, otherwise
* @version 03/13/2015 g.l. modified version
*/
HD3_API
int32 st3_modify_tag_prop(
	hd3_in uint32 nTagID,
	hd3_in const HD3StatsTagProp* pProp,
	hd3_in const HD3Mask* pMask
	);

/**
* @brief 修改统计点（批量接口）
* @param nTagNum [点个数]
* @param pTagIDArray [TagID数组]
* @param pTagPropArray [属性数组]
* @param pMaskArray [掩码数组]
* @param pErrCodeArray [错误码数组]
* @return RD_SUCCESS, if all success
*       EC_HD3_API_BATCH_REQUEST, if some failed
*       hd3 error, otherwise
* @version 03/13/2015 g.l. modified version
*/
HD3_API
int32 st3_modify_tags_prop(
	hd3_in int32 nTagNum,
	hd3_in const uint32* pTagIDArray,
	hd3_in const HD3StatsTagProp* pTagPropArray,
	hd3_in const HD3Mask* pMaskArray,
	hd3_out int32* pErrCodeArray
	);


/**
* @brief 根据TagID查询统计点属性
* @param nTagID [TagID]
* @param pTagProp [属性]
* @return RD_SUCCESS, if success; hd3 error, otherwise
* @version 03/13/2015 g.l. modified version
*/
HD3_API
int32 st3_query_tag_prop(
	hd3_in uint32 nTagID,
	hd3_out HD3StatsTagProp* pProp
	);

/**
* @brief 条件查询满足过滤项的统计点的属性
* @param pSet [过滤项集合]
* @param pMask [属性掩码]
* @param phResultSet [结果集句柄]
*  取结果项: ut3_get_item_stemp(hdResultSet, HD3StatsTagProp*)
*  请参阅本文件中ut3_get_item_step接口的说明
*  结果中的Tag按照TagID增序排序
* @return RD_SUCCESS, if success; hd3 error, otherwise
* @version 03/13/2015 g.l. modified version
*/
HD3_API
int32 st3_query_tags_cond(
	hd3_in const HD3FilterItemSet* pSet,
	hd3_in const HD3Mask* pMask,
	hd3_out HD3HANDLE* phResultSet
	);

/**
* @brief 分页查询：条件查询满足过滤项的统计点的属性
* @param pParam [参数]
* @param phResultSet [结果集句柄]
*  取结果项: ut3_get_item_stemp(hdResultSet, HD3StatsTagProp*)
*  请参阅本文件中ut3_get_item_step接口的说明
*  结果中的Tag按照TagID增序排序
* @return RD_SUCCESS, if success; hd3 error, otherwise
* @version 03/13/2015 g.l. modified version
*/
HD3_API
int32 st3_query_specify_page_tags_cond(
	hd3_in const HD3PageQueryTagParam* pParam,
	hd3_out HD3HANDLE* phResultSet
	);

/**
* @brief 执行统计点的统计
* @param nTagID [TagID]
* @param pParam [参数]
* @param pfValue [统计值]
* @return RD_SUCCESS, if success; hd3 error, otherwise
* @version 03/13/2015 g.l. modified version
*/
HD3_API
int32 st3_tag_stats_calc(
	hd3_in uint32 nTagID,
	hd3_in const HD3StRelatedParam* pParam,
	hd3_out double* pfValue
	);

/**
* @brief 删除Tag
* @param nTagID [TagID]
* @return RD_SUCCESS, if success; hd3 error, otherwise
* @version 03/13/2015 g.l. merged version
*/
HD3_API
int32 tag3_delete_tag(hd3_in uint32 nTagID);

/**
* @brief 删除Tag（批量接口）
* @param nTagNum [Tag个数]
* @param pTagIDArray [TagID数组；容量：nTagNum]
* @param pErrCodeArray [删除每个点时的错误码；容量：nTagNum]
* @return RD_SUCCESS, if all success
*       EC_HD3_API_BATCH_REQUEST, if some failed
*       hd3 error, otherwise
* @version 03/13/2015 g.l. initialize version
*/
HD3_API HD3_A
int32 tag3_delete_tags(
	hd3_in int32 nTagNum,
	hd3_in const uint32* pTagIDArray,
	hd3_out int32* pErrCodeArray
	);

/**
* @brief 根据名称查询TagID
* @param szName [Tag名称]
* @param pnTagID [TagID]
* @return RD_SUCCESS, if success; hd3 error, otherwise
* @version 03/13/2015 g.l. merged version
*/
HD3_API
int32 tag3_query_id_by_name(
	hd3_in const char* szName,
	hd3_out uint32* pnTagID
	);

/**
* @brief 根据名称查询TagID（批量接口）
* @param nTagNum [Tag个数]
* @param szTagNames [Tag名称数组；容量：nTagNum]
* @param nTagIDs [TagID数组；容量：nTagNum]
* @param nErrCodes [错误码数组；容量：nTagNum]
* @return RD_SUCCESS, if all success
*       EC_HD3_API_BATCH_REQUEST, if some failed
*       hd3 error, otherwise
* @version 03/13/2015 g.l. merged version
*/
HD3_API
int32 tag3_query_ids_by_names(
	hd3_in int32 nTagNum,
	hd3_in const char szTagNames[][HD3_LEN_TAG_NAME * HD3_BASE],
	hd3_out uint32* pTagIDArray,
	hd3_out int32* pErrCodeArray
	);

/**
* @brief 条件查询满足过滤项的指定类别的Tag点个数
* @param nTagClass [Tag类别]
* @param pSet [过滤项集合]
* @param pnTagNum [Tag个数]
* @return RD_SUCCESS, if success; hd3 error, otherwise
* @version 03/13/2015 g.l. modified version
*/
HD3_API
int32 tag3_query_tag_num_cond(
	hd3_in enum HD3_TAG_CLASS nTagClass,
	hd3_in const HD3FilterItemSet* pSet,
	hd3_out int32* pnTagNum
	);

/**
* @brief 根据Tag名称查询Tag身份（TagID，TagType，TagClass）
* @param nTagClassMask [TagClass掩码]
* @param nTagNum [Tag个数]
* @param pInfoArray [参数数组；in：TagName]
* @param pErrCodeArray [错误码数组]
* @return RD_SUCCESS, if all success
*       EC_HD3_API_BATCH_REQUEST, if some failed
*       hd3 error, otherwise
* @version
*/
HD3_API
int32 tag3_query_tags_basic_info_by_name(
	hd3_in int64 nTagClassMask,
	hd3_in int32 nTagNum,
	hd3_inout HD3TagBasicInfo* pInfoArray,
	hd3_out int32* pErrCodeArray
	);

/**
* @brief 条件查询满足过滤项的指定类别的Tag点的共有属性
* @param nTagClassMask [Tag类别掩码]
* @param pSet [过滤项集合]
* @param nPropMask [属性掩码（仅共有属性）]
* @param phResultSet [结果集句柄]
*   取结果项: ut3_get_item_step(hResultSet, HD3CommTagProp*)
*  请参阅本文件中ut3_get_item_step接口的说明
*  结果中的Tag按照TagID增序排序
* @return RD_SUCCESS, if success; hd3 error, otherwise
* @version 03/13/2015 g.l. modified version
*/
HD3_API
int32 tag3_query_tags_cond(
	hd3_in int64 nTagClassMask,
	hd3_in const HD3FilterItemSet* pSet,
	hd3_in int64 nPropMask,
	hd3_out HD3HANDLE* phResultSet
	);

/**
* @brief 翻页条件查询满足过滤项的指定类别的Tag点的共有属性
* @param nTagClassMask [Tag类别掩码]
* @param pParam [过滤项集合]
* @param phResultSet [结果集句柄]
*   取结果项: ut3_get_item_step(hResultSet, HD3CommTagProp*)
*  请参阅本文件中ut3_get_item_step接口的说明
*  结果中的Tag按照TagID增序排序
* @return RD_SUCCESS, if success; hd3 error, otherwise
* @version 03/13/2015 g.l. modified version
*/
HD3_API
	int32 tag3_query_specify_page_tags_cond(
	hd3_in int64 nTagClassMask,
	hd3_in const HD3PageQueryTagParam* pParam,
	hd3_out HD3HANDLE* phResultSet
	);


/**
* @brief 指定TagClass，根据TagID查询Tag公共属性
* @param nTagClassMask [Tag类别掩码]
* @param nTagNum [Tag个数]
* @param nPropMask [公共属性的掩码]
* @param pPropArray [属性数组；in：TagID]
* @param pErrCodeArray [错误码数组]
* @return RD_SUCCESS, if success; hd3 error, otherwise
* @version 03/13/2015 g.l. modified version
*/
HD3_API
int32 tag3_query_tags_common_prop(
	hd3_in int64 nTagClassMask,
	hd3_in int32 nTagNum,
	hd3_in int64 nPropMask,
	hd3_inout HD3CommTagProp* pPropArray,
	hd3_out int32* pErrCodeArray
	);

/**
* @brief  设置API字符集（表示API接受的字符编码、API输出的字符编码）
*  API中字符编码枚举值参见HD3_CHARSET
* @param charset [字符集枚举值]
* @version 05/18/2015 g.l. modified version
*/
HD3_API
void ut3_set_charset(hd3_in enum HD3_CHARSET charset);

/**
* @brief  获取API字符集（表示API接受的字符编码、API输出的字符编码）
*  API中字符编码枚举值参见HD3_CHARSET
* @return API字符集
* @version 05/18/2015 g.l. modified version
*/
HD3_API
enum HD3_CHARSET ut3_get_charset();

/**
* @brief	获取结果项
*  当取到了需要的结果项后，必须调用ut_free_iterator(hResultSet)释放结果集
* @param hResultSet [结果集句柄]
* @param pItem [结果项]
*  必须严格按照各个返回结果集句柄的接口注释中“取结果项”的要求调用本接口
* @return RD3_SUCCESS, if success
*    EC_HD_API_QUERY_END, 结果集已经取完（本次未取到结果项）
*    hd3 error, otherwise
* @version 03/02/2015 hd3 team initial version
*/ 
HD3_API
int32 ut3_get_item_step(
	hd3_in HD3HANDLE hResultSet,
	hd3_out void* pItem
	);

/**
* @brief	释放结果集
*  结果集释放后，再使用该结果集的句柄调用API则会返回错误
* @param hResultSet [结果集句柄]
* @version 03/02/2015 hd3 team initial version
*/ 
HD3_API
void ut3_free_handle(hd3_in HD3HANDLE hResultSet);


/**
* @brief 设置一次请求的缓存大小，对使用ut3_get_item_step的接口有效
* @param nCapacity [缓存大小]
* @version 03/02/2015 hd3 team initial version
*/
HD3_API
void ut3_set_request_cache_capacity(hd3_in int32 nCapacity); 

/**
* @brief 设置数据请求超时
* @param nTimeout [超时时间，单位为秒]
* @version 03/02/2015 hd3 team initial version
*/
HD3_API
void ut3_set_request_timeout(hd3_in int32 nTimeout);

/**
* @brief 设置间隔时间，用于定期检查API与后台服务的连接
* @param nInterval [检查周期]
* @version 03/24/2015 hd3 team initial version
*/
HD3_API
void ut3_set_connection_checking_cycle(hd3_in int32 nInterval);

/**
* @brief 设置数据订阅的缓存大小（记录条数），如果不设置缓存大小默认为1000000条，
该设置对接口sn3_register_callback, sn3_get_callback_sn有效
* @param nCapacity [缓存记录条数]
* @version 03/24/2018 hd3 team initial version
*/
HD3_API
void ut3_set_sn_callback_cache_capacity(hd3_in int32 nCapacity);

/**
* @brief 获取配置中心当前时间
* @param pMsTime [配置中心当前时间，单位为毫秒]
* @return RD_SUCCESS, if success; hd3 error, otherwise
* @version 03/02/2015 hd3 team initial version
*/
HD3_API
int32 ut3_get_server_ms_time(hd3_out int64* pMsTime);

/**
* @brief  获取所有数据节点信息
* @param phResultSet [结果集句柄]
*  取结果项: ut3_get_item_stemp(hResultSet, HD3DataNode*)
*  请参阅本文件中ut3_get_item_step接口的说明
*  结果中的数据节点按照ID增序排序
* @return RD_SUCCESS, if success; hd3 error, otherwise
* @version 03/16/2015 g.l. initialize version
*/
HD3_API
int32 ut3_query_all_datanodes(hd3_out HD3HANDLE* phResultSet);

/**
* @brief 添加数据节点
* @param pDataNode [数据节点]
* @param pnNodeID [节点ID]
* @return RD_SUCCESS, if success; hd3 error, otherwise
* @version 03/16/2015 g.l. initialize version
*/
HD3_API
int32 ut3_add_datanode(
	hd3_in const HD3DataNode* pDataNode,
	hd3_out uint32* pnNodeID);

/**
* @brief 删除数据节点
* @param nNodeID [数据节点ID]
* @return RD_SUCCESS, if success; hd3 error, otherwise
* @version 03/16/2015 g.l. initialize version
*/
HD3_API
int32 ut3_delete_datanode(
	hd3_in uint32 nNodeID
	);

/**
* @brief 修改数据节点
* @param nNodeID [节点ID]
* @param pDataNode [数据节点]
* @return RD_SUCCESS, if success; hd3 error, otherwise
* @version 03/16/2015 g.l. initialize version
*/
HD3_API
int32 ut3_modify_datanode(
	hd3_in uint32 nNodeID,
	hd3_in const HD3DataNode* pDataNode
	);

/**
* @brief 根据节点ID查询数据节点
* @param nNodeID [节点ID]
* @param pDataNode [数据节点]
* @return RD_SUCCESS, if success; hd3 error, otherwise
* @version 03/16/2015 g.l. initialize version
*/
HD3_API
int32 ut3_query_datanode(
	hd3_in uint32 nNodeID,
	hd3_out HD3DataNode* pDataNode
	);

/**
* @brief 根据节点名称查询节点ID
* @param szDataNodeName [节点名称]
* @param pnNodeID [节点ID]
* @return RD_SUCCESS, if success; hd3 error, otherwise
* @version 03/16/2015 g.l. initialize version
*/
HD3_API
int32 ut3_query_datanode_id_by_name(
	hd3_in const char* szDataNodeName,
	hd3_out uint32* pnNodeID
	);

/**
* @brief	获取许可状态
* @param nDataNodeID [数据节点ID]
* @param pLicStatus [许可状态，1：有许可；其它：无许可]
* @param pTimeValidSec [系统启动后运行时间（秒）]
* @param pClientConnected [
* @return RD_SUCCESS, if success; hd3 error, otherwise
* @version 05/19/2015 g.l. modified version
*/ 
HD3_API 
int32 ut3_get_license_info(
						   hd3_in uint32 nDataNodeID,
						   hd3_out uint8* pLicStatus,
						   hd3_out uint32* pTimeValidSec,
						   hd3_out uint32* pClientConnected
						   );

/**
* @brief 获取许可证信息
* @param nDataNodeID [数据节点ID]
* @param pLicStatus [许可状态，1：有许可；其它：无许可]
* @param pLicInfoAttrCount [许可证信息项属性个数]
* @param pLicInfo [许可证信息项具体内容]
* @return RD_SUCCESS, if success; hd3 error, otherwise
* @version 05/19/2015 g.l. modified version
*/
HD3_API
int32 ut3_get_license_info_all(
							   hd3_in uint32 nDataNodeID,
							   hd3_out uint8* pLicStatus,
							   hd3_out uint8* pLicInfoAttrCount,
							   hd3_out HD3LicInfo* pLicInfo
							   );

/**
* @brief 查询数据节点上所有连接个数
* @param nDataNodeID [数据节点ID]
* @param pConnectionNum [连接个数]
* @return RD_SUCCESS, if success; error code, otherwise
* @version 05/19/2015 g.l. modified version
*/
HD3_API
int32 ut3_get_all_client_num(
							hd3_in uint32 nDataNodeID, 
							hd3_out int32* pConnectionNum
							);

/**
* @brief 获取所有的连接信息
* @param nDataNodeId [数据节点ID]
* @param pInfoArray [连接信息数组]
* @param pnArraySize [数组长度；in: capacity; out: size]
*  nArraySize应当为ut3_get_all_client_num()返回的的连接个数
* @return RD_SUCCESS, if success; error code, otherwise
* @version 05/19/2015 g.l. modified version
*/
HD3_API
int32 ut3_get_all_client_info(
							 hd3_in uint32 nDataNodeID,
							 hd3_out HD3ClientConnInfo *pInfoArray,
							 hd3_in int32* pnArraySize
							 );
/**
* @brief 获取指定SOCKET的连接信息
* @param nDataNodeID [数据节点ID]
* @param socket [SOCKET ID]
* @param pSocketInfo [SOCKET信息]
* @return RD_SUCCESS, if success; error code, otherwise
* @version 05/19/2015 g.l. modified version
*/
HD3_API
int32 ut3_get_socket_net_info(
							 hd3_in uint32 nDataNodeID,
							 hd3_in SOCKET socket,
							 hd3_out HD3SocketNetInfo* pSocketInfo
							 );

/**
* @brief 获取指定客户端的所有SOCKET信息
* @param szMac [客户端MAC地址]
* @param pSocketArray [SOCKET数组]
*  数组大小应当不小于HD3_API_CLIENT_MAX_SOCKET_NUM
* @param pnSocketNum [数组长度；in: capacity; out: size]
* @return RD_SUCCESS, if success; error code, otherwise
* @version 05/19/2015 g.l. modified version
*/
HD3_API
int32 ut3_get_client_sockets(hd3_in uint32 nDataNodeID,
							hd3_in const char* szMac,
							hd3_out SOCKET * pSocketArray,
							hd3_inout int32 *pnSocketNum
							);

/**
* @brief 将时间从秒格式转换成HD时间戳
* @param nSec [秒]
* @param pRDTime [时间戳]
* @return RD_SUCCESS, if success; error code, otherwise
* @version 05/19/2015 g.l. modified version
*/
HD3_API
int32 ut3_convert_sec_to_rdtime(int32 nSec, HD3TimeStamp* pRDTime);

/**
* @brief 将HD时间戳转换成秒
* @param pTime [时间戳]
* @param pTime [秒]
* @return RD_SUCCESS, if success; error code, otherwise
* @version 05/19/2015 g.l. modified version
*/
HD3_API
int32 ut3_convert_rdtime_to_sec(const HD3TimeStamp* pTime, int32* pnSec);

/**
* @brief 获取节点的配置文件信息
* @param nNodeID 节点ID
* @param pNodeCfg 节点配置信息
* @return RD_SUCCESS, if success; error code, otherwise
* @version 05/19/2015 g.l. modified version
*/
HD3_API
int32 ut3_get_datanode_cfg(uint32 nNodeID, HD3DataNodeCfg* pNodeCfg);

/**
* @brief 获取节点的状态信息
* @param nNodeID 节点ID
* @param pNodeStatus 节点状态信息
* @return RD_SUCCESS, if success; error code, otherwise
* @version 11/112/2015 YQ init version
*/
HD3_API
int32 ut3_get_datanode_status(uint32 nNodeID, HD3DataNodeStatus* pNodeStatus);

/**
* @brief 获取配置节点的状态信息
* @param pCCStatus 配置节点状态信息
* @return RD_SUCCESS, if success; error code, otherwise
* @version 2017/03/06 YQ init version
*/
HD3_API
int32 ut3_get_cc_status(HD3ConfigCenterStatus* pCCStatus);

HD3_API
int32 ut3_send_rest_info(HDRestCfg hdRestCfg);

/**
* @brief 校验表达式
* @param szExpr [表达式]
* @return RD_SUCCESS, if success; hd3 error, otherwise
* @version 03/31/2015 g.l. initialize version
*/
HD3_API
int32 expr_verify(hd3_in const char* szExpr);

/**
* @brief 解析表达式
* @param szExpr [表达式]
* @param phParseResult [解析结果句柄指针]
* @return RD_SUCCESS, if success; hd3 error, otherwise
* @version 03/31/2015 g.l. initialize version
*/
HD3_API
int32 expr_parse(
				 hd3_in const char* szExpr,
				 hd3_out HD3HANDLE* phParseResult
				 );

/**
* @brief 释放解析结果句柄
*  解析结果句柄一旦释放，则不应当再被使用
* @param pParseHandle [解析结果句柄]
* @return RD_SUCCESS, if success; hd3 error, otherwise
* @version 03/31/2015 g.l. initialize version
*/
HD3_API
int32 expr_parse_free(hd3_in HD3HANDLE pParseResult);

/**
* @brief 获取表达式依赖的Tag点ID
* @param pParseResult [解析结果句柄]
* @param pnTagNum [Tag个数]
* @param pTagIDArray [TagID数组]
* @return RD_SUCCESS, if success; hd3 error, otherwise
* @version 03/31/2015 g.l. initialize version
*/
HD3_API
int32 expr_get_depend_tags(
						   hd3_in HD3HANDLE pParseResult,
						   hd3_out int32* pnTagNum,
						   hd3_out uint32** ppTagIDArray
						   );

/**
* @brief 释放TagID数组
* @param pTagIDArray [TagID数组]
* @return RD_SUCCESS, if success; hd3 error, otherwise
* @version 03/31/2015 g.l. initialize version
*/
HD3_API
int32 expr_get_depend_tags_free(hd3_in uint32* pTagIDArray);

/**
* @brief 根据Tag点数据，计算表达式结果
* @param caLastGood [计算点最近一条Good的记录]
* @param pParseResult [解析表达式结果句柄]
* @param nTagNum [Tag个数]
* @param pRecArray [记录数组]
* @param pValue [计算结果]
* @return RD_SUCCESS, if success; hd3 error, otherwise
* @version 03/31/2015 g.l. initialize version
*/
HD3_API
int32 expr_calc(
				hd3_in const HD3Record* caLastGood,
				hd3_in HD3HANDLE pParseResult,
				hd3_in int32 nTagNum,
				hd3_in const HD3Record* pRecArray,
				hd3_out float64* pValue);
/**
* @brief 注册数据订阅
* @param pfn [回调函数的指针] 指针可以为NULL，为NULL时需要调用sn3_get_callback_sn获取服务端推送过来的数据
*  nTagID TagID
*  pRecord [快照记录]
* @return RD_SUCCESS, if success; hd3 error, otherwise
* @version 07/14/2016 y.q. modified version
* @version 03/27/2018 y.q. modified version：pfn可以为NULL，为NULL时调用sn3_get_callback_sn取数据
*/
typedef void (*HD3SnapshotCallbackFunc)(hd3_in uint32 nTagID, hd3_in const HD3Record* pRecord);

HD3_API
int32 sn3_register_callback(hd3_in int32 nTagNum, hd3_in uint32* pTagIDArray, hd3_in HD3SnapshotCallbackFunc pfn);

/**
* @brief获取调用sn3_register_callback订阅的点的快照，完成后需要调用sn3_free_callback_sn
* @param 
*  pnRecNum 快照个数，没有推送过来的快照时传出值为0
*  ppTagIDs TagID数组指针
*  ppRecs 快照数据指针
* @return RD_SUCCESS, if success; hd3 error, otherwise
* @version 03/27/2018 y.q. init version
*/
HD3_API
int32 sn3_get_callback_sn(hd3_out int32* pnRecNum, hd3_out uint32** ppTagIDs, hd3_out HD3Record** ppRecs);


HD3_API
int32 sn3_get_callback_sn_value_change(int32* pnRecNum, uint32** ppTagIDs, HD3Record** ppRecs);

/**
* @brief获取调用sn3_register_callback订阅的点的快照，完成后需要调用sn3_free_callback_sn
* @param 
*  nRecNum 快照个数
*  pTagIDs TagID数组指针
*  pRecs 快照数据指针
* @return void
* @version 03/27/2018 y.q. init version
*/
HD3_API
void sn3_free_callback_sn(hd3_in int32 nRecNum, hd3_in uint32* pTagIDs, hd3_in HD3Record* pRecs);
/**
* @brief 将所有点的时间戳变化通知注销
*/
HD3_API
int32 sn3_unregister_callback();

/**
* @brief 将部分点的时间戳变化通知注销
* @param nTagNum 点个数
* @param pTagIDArray 点ID数组
*/
HD3_API
int32 sn3_unregister_callback_of_sometag(hd3_in int32 nTagNum, hd3_in uint32* pTagIDArray);

/**
* @brief 注册值变化数据订阅，当Tag的数据质量发生变化或者值发生变化时回调函数被调用
* @param pfn [回调函数的指针]
*  nTagID TagID
*  pRecord [快照记录]
* @return RD_SUCCESS, if success; hd3 error, otherwise
* @version 07/31/2017 y.q. modified version
*/
HD3_API
int32 sn3_register_value_change_callback(hd3_in int32 nTagNum, hd3_in uint32* pTagIDArray, hd3_in HD3SnapshotCallbackFunc pfn);

HD3_API
int32 sn3_unregister_value_change_callback();

HD3_API
int32 sn3_register_rest(hd3_in int32 nTagNum, hd3_in HDRegInfo* pRegInfoArray);

HD3_API
int32 sn3_unregister_callback_rest(hd3_in int32 nTagNum, hd3_in HDRegInfo* pRegInfoArray); 

/**
* @brief 配置中心执行一定的命令
* @param szCmdIn 
* 通知IMV代理服务重启		szCmdIn  "cmdtype = restart_imv;"
* 读取配置文件信息			szCmdIn  "cmdtype = read_imv_cfg;"		szCmdOut  "ip = 127.0.0.1; port = 5673; datasrc = ihd"
* 修改配置文件信息			szCmdIn  "cmdtype = write_imv_cfg; ip = 127.0.0.1; port = 5673; datasrc = ihd;"
* 获取云同步点配置变更的版本号 szCmdIn  "cmdtype = read_cloudsyn_version;"  szCmdOut  "1002" 
* 获取上云发送数据统计信息     szCmdIn  "cmdtype = read_clouddata_statistics;"  szCmdOut  "sendcount = 7890.23; sendbyte = 1902.78"
* @param szCmdOut, call cc3_cmd_free to free
* @return RD_SUCCESS, if success; hd3 error, otherwise
* @version 07/14/2016 y.q. modified version
*/
HD3_API
int32 cc3_cmd(hd3_in const char* szCmdIn, hd3_out char** szCmdOut);

/**
* @brief free 
* @param szCmdOut free cc3_cmd(hd3_in const char* szCmdIn, hd3_out char** szCmdOut) szCmdOut
* @return void
* @version 07/14/2016 y.q. modified version
*/
HD3_API
void cc3_cmd_free(hd3_in char* szCmdOut);

#define HD3M_API_OPTION_DISABLE_SAVE_SNAPSHOT_CHECK_TAG_TYPE (1)
#define HD3M_API_OPTION_DISABLE_SAVE_SNAPSHOT_REC_SORT (1<<1)
#define HD3M_API_OPTION_DISABLE_CONN_CHECK_RY (1<<2)
/**
* @brief 设置API的选项，如传入nOptionMask=HD3M_API_OPTION_DISABLE_SAVE_SNAPSHOT_CHECK表示去掉存数据接口的数据检查校验，可以提升存数据接口性能
* @param nOptionMask 选项掩码，HD3M_API_OPTION_DISABLE_SAVE_SNAPSHOT_CHECK等
* @return void
* @version 12/30/2016 y.q. modified version
*/
HD3_API
void ut3_set_api_option(hd3_in int64 nOptionMask);

HD3_API
int32 cloudsyn_add_tags(hd3_in HD3_CLOUD_SYN_TARGET target, hd3_in int32 nTagNum, hd3_in const void* pTagPropArray, hd3_in const HD3Mask* pMaskArray,
	hd3_out int32* pErrCodeArray);
HD3_API 
int32 cloudsyn_delete_tags(hd3_in HD3_CLOUD_SYN_TARGET target, hd3_in int32 nTagNum, hd3_in const char** pTagNameArray, hd3_out int32* pErrCodeArray);
HD3_API
int32 cloud_query_tags_cond(
	hd3_in HD3_CLOUD_SYN_TARGET target,
	hd3_in const HD3FilterItemSet* pSet,
	hd3_in const HD3Mask* pMask,
	hd3_out HD3HANDLE* phResultSet
);
HD3_API
int32 cloud_modify_tags_prop(
	hd3_in HD3_CLOUD_SYN_TARGET target,
	hd3_in int32 nTagNum,
	hd3_in const HD3BigDataTagProp* pTagPropArray,
	hd3_in const HD3Mask* pMaskArray,
	hd3_out int32* pErrCodeArray
);

HD3_API 
	int32 cs3_backup_config_file(const char* szBackupDir, const char* szBackupFileName);

HD3_API
int32 ut3_get_capacity(int32* nDataNodeNum, HD3Capacity** pRecArray, int32** pErrCodeArray);

HD3_API
void ut3_free_capacity();

HD3_API
int32 pt3_cache_digitalsets();

HD3_API
int32 pt3_query_digitalset_state_name_by_id(uint32 nTagID, int32 nStateValue,  char* szDSStateName);

HD3_API
int32 sn3_query_digitalset(hd3_in uint32 nTagID,hd3_inout char* szDSStateName);

HD3_API
int32 ar3_query_raw_digtialset_records(uint32 nTagID, const HD3TimeRegion* pRegion, int32* pRecNum, char szDSStateNames[][HD3_LEN_DIGITAL_SET_STATE_NAME]);

HD3_API
int32 ar3_query_interp_digitalset_records_by_mode( 
	hd3_in uint32 nTagID, 
	hd3_in const HD3TimeRegion* pRegion, 
	hd3_in uint32 nInterval,
	hd3_in int32* pRecNum, 
	hd3_out char szDSStateNames[][HD3_LEN_DIGITAL_SET_STATE_NAME], 
	hd3_out int32* pErrCodeArray);
/*************** 下面的是未处理的hdAPI ****************************/



#ifdef __cplusplus
}
#endif

#endif
