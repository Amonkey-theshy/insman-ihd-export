#ifndef RD_CONST_H_FILE
#define RD_CONST_H_FILE

#include "data_types.h"

#ifdef AIX
#include <stdlib.h>
#endif//AIX

#ifndef _HDHANDLE
typedef void* HDHANDLE;
#define _HDHANDLE
#endif

#ifndef WIN32
#ifndef SOCKET
#define SOCKET int
#endif
#else 
#ifndef SOCKET
//#include <winsock2.h>
//#include <windows.h>
#if defined(_WIN64)
typedef __int64 INT_PTR, *PINT_PTR;
typedef unsigned __int64 UINT_PTR, *PUINT_PTR;
#else
typedef _W64 int INT_PTR, *PINT_PTR;
typedef _W64 unsigned int UINT_PTR, *PUINT_PTR;
#endif
typedef UINT_PTR        SOCKET;
#endif
#endif


#define HD_INVALID_HANDLE					(HDHANDLE)0


// 页大小
#define RD_PAGE_SIZE						4096

#define HD_EPSILON							0.00001

#define DATA_QUALITY_VALUE_HALT				-1		/*停机记录，正常的数据质量不能用这个值*/
#define DATA_QUALITY_VALUE_IO_TIMEOUT		65534	// 无法连接设备

// 采集器状态点质量
#define DATA_QUALITY_VALUE_CT_MAX				65533
#define DATA_QUALITY_VALUE_CT_BOOTTING			65533
#define DATA_QUALITY_VALUE_CT_ACTIVE			65532
#define DATA_QUALITY_VALUE_CT_SHUTDOWN			65531
#define DATA_QUALITY_VALUE_CT_TIMEOUT			65530
#define DATA_QUALITY_VALUE_CT_MIN				65530
// 设备状态点质量
#define DATA_QUALITY_VALUE_DEVICE_MAX			65529
#define DATA_QUALITY_VALUE_DEVICE_CONN			65529
#define DATA_QUALITY_VALUE_DEVICE_DISCONN		65528
#define DATA_QUALITY_VALUE_DEVICE_MIN			65528

// 表达式过滤
#define DATA_QUALITY_VALUE_EXPR_FILTER			65527

#define DATA_QUALITY_VALUE_HALT_SHOW				"No Data"
#define DATA_QUALITY_VALUE_IO_TIMEOUT_SHOW			"I/O Timeout"

#define DATA_QUALITY_GOOD					0xC0		//一个典型的Good值, 192
#define DATA_QUALITY_BAD					0xFF3F		//质量为Bad
#define DATA_QUALITY_BAD_STATS_NO_GOOD_REC	0xFF3E		//统计记录用这个值来表示统计区域没有一条Good的原始记录，质量为bad

// license status
#define LICENSE_INVALID		0	//许可证无效，一般是2小时试用版过期
#define LICENSE_VALID		1	//有效许可证
#define LICENSE_VALID_TEMP	2	//临时许可证，2小时试用版

//tag点类型定义
#define TAG_TYPE_MIN						0
#define TAG_TYPE_INT8						0
#define TAG_TYPE_INT16						1
#define TAG_TYPE_INT32						2
#define TAG_TYPE_FLOAT32					3
#define TAG_TYPE_FLOAT64					4
#define TAG_TYPE_DIGITAL					5
#define TAG_TYPE_STRING						6
#define TAG_TYPE_BLOB						7
#define TAG_TYPE_MAX						7

//变更类型
#define CHANGE_TYPE_ADD						0
#define CHANGE_TYPE_MODIFY					1
#define CHANGE_TYPE_DELETE					2
#define CHANGE_TYPE_MAX						2

//变更的模块类型
#define CHANGE_MODULE_TYPE_COLLECTOR		0
#define CHANGE_MODULE_TYPE_CALC				1

// 通知对象类型
#define HD_NOTIFY_OBJ_TYPE_NORMAL_TAG		0
#define HD_NOTIFY_OBJ_TYPE_ALARM_TAG		1
#define HD_NOTIFY_OBJ_TYPE_STAT_TAG		2
#define HD_NOTIFY_OBJ_TYPE_EXPCALC_TAG	3
#define HD_NOTIFY_OBJ_TYPE_COLLECTOR		4
#define HD_NOTIFY_OBJ_TYPE_SCAN_GROUP		5
#define HD_NOTIFY_OBJ_TYPE_DEVICE			6
#define HD_NOTIFY_OBJ_TYPE_ALARM_GROUP	7
#define HD_NOTIFY_OBJ_TYPE_DIGITAL_SET	8
#define HD_NOTIFY_OBJ_TYPE_MAX			8

/*配置变更通知对象的掩码*/
#define HD_NOTIFY_OBJ_MASK_ALL				 0XFFFFFFFFFFFFFFFFLL
#define HD_NOTIFY_OBJ_MASK_NORMAL_TAG		(1 << HD_NOTIFY_OBJ_TYPE_NORMAL_TAG)
#define HD_NOTIFY_OBJ_MASK_ALARM_TAG		(1 << HD_NOTIFY_OBJ_TYPE_ALARM_TAG)
#define HD_NOTIFY_OBJ_MASK_STAT_TAG			(1 << HD_NOTIFY_OBJ_TYPE_STAT_TAG)
#define HD_NOTIFY_OBJ_MASK_EXPCALC_TAG		(1 << HD_NOTIFY_OBJ_TYPE_EXPCALC_TAG)
#define HD_NOTIFY_OBJ_MASK_COLLECTOR		(1 << HD_NOTIFY_OBJ_TYPE_COLLECTOR)
#define HD_NOTIFY_OBJ_MASK_SCAN_GROUP		(1 << HD_NOTIFY_OBJ_TYPE_SCAN_GROUP)
#define HD_NOTIFY_OBJ_MASK_DEVICE			(1 << HD_NOTIFY_OBJ_TYPE_DEVICE)
#define HD_NOTIFY_OBJ_MASK_ALARM_GROUP	(1 << HD_NOTIFY_OBJ_TYPE_ALARM_GROUP)
#define HD_NOTIFY_OBJ_MASK_DIGITAL_SET		(1 << HD_NOTIFY_OBJ_TYPE_DIGITAL_SET)

//采集器相关变更实体的类别
#define CHANGE_ENTRY_COLLECTOR				0
#define CHANGE_ENTRY_DEVICE					1
#define CHANGE_ENTRY_SCAN_GROUP				2 
#define CHANGE_ENTRY_TAG				    3

//报警变更类型
#define CHANGE_NEW_ALARM					0
#define CHANGE_ACK_ALARM					1
#define CHANGE_RESTORE_ALARM				2
#define CHANGE_COMMENT_ALARM				3

//扫描组类型
#define HD_CT_SCAN_TYPE_POLL				0 //轮询模式
#define HD_CT_SCAN_TYPE_ADVISE				1 //通知模式

//压缩类型定义
#define COMP_TYPE_MIN						0
#define COMP_TYPE_NO						0
#define COMP_TYPE_SDT						1
#define COMP_TYPE_MAX						1

//报警自动确认定义
#define ALARM_AUTO_ACK_MIN					0
#define ALARM_AUTO_ACK_NO					0
#define ALARM_AUTO_ACK_YES					1
#define ALARM_AUTO_ACK_MAX					1

//监视点的类型
#define MONITOR_TAG_TYPE_MIN				0
#define MONITOR_TAG_TYPE_ALARM				1
#define MONITOR_TAG_TYPE_MAX				1

//数据类型长度定义
#define DATA_LENGTH_INT8					1
#define DATA_LENGTH_INT16					2
#define DATA_LENGTH_INT32					4
#define DATA_LENGTH_FLOAT32					4
#define DATA_LENGTH_FLOAT64					8
#define DATA_LENGTH_DIGITAL					1

//数据块内部结构长度定义
#define LENGTH_TIME_STAMP					6
#define LENGTH_DATA_QUALITY					2

/*string blob类型相关长度定义*/
#define LENGTH_VAR_TYPE_VALUE				1000
#define LENGTH_VAR_TYPE_RECORD				(LENGTH_TIME_STAMP + LENGTH_DATA_QUALITY + sizeof(uint16) + LENGTH_VAR_TYPE_VALUE)


//各数据类型记录长度定义
#define REC_LENGTH_MIN						REC_LENGTH_INT8
#define REC_LENGTH_INT8						(DATA_LENGTH_INT8 + LENGTH_TIME_STAMP + LENGTH_DATA_QUALITY)
#define REC_LENGTH_INT16					(DATA_LENGTH_INT16 + LENGTH_TIME_STAMP + LENGTH_DATA_QUALITY)
#define REC_LENGTH_INT32					(DATA_LENGTH_INT32 + LENGTH_TIME_STAMP + LENGTH_DATA_QUALITY)
#define REC_LENGTH_FLOAT32					(DATA_LENGTH_FLOAT32 + LENGTH_TIME_STAMP + LENGTH_DATA_QUALITY)
#define REC_LENGTH_FLOAT64					(DATA_LENGTH_FLOAT64 + LENGTH_TIME_STAMP + LENGTH_DATA_QUALITY)
#define REC_LENGTH_DIGITAL					(DATA_LENGTH_DIGITAL + LENGTH_TIME_STAMP + LENGTH_DATA_QUALITY)
#define REC_LENGTH_MAX						(LENGTH_VAR_TYPE_RECORD)

#define	HD_MAX_LEN_TAG_PROP			        1024
#define	HD_LEN_TAG_NAME				        128		/* including '\0' */
#define	HD_LEN_TAG_TYPE				        16		/* including '\0' */
#define HD_LEN_TAG_DESC				        1024	/* including '\0' */
#define HD_LEN_USER_NAME			        32		/* including '\0' */
#define HD_LEN_ENG_UNITS			        32		/* including '\0' */
#define HD_LEN_INSTURMENT_POINT_VERSION_0		        64		/* including '\0' */  //API版本为0时的设备点长度，版本1修改为256
#define HD_LEN_INSTURMENT_POINT		        256		/* including '\0' */  //modify by yangqi; 长度从64修改为256
#define HD_LEN_INTERFACE_NAME		        64		/* including '\0' */
#define HD_LEN_IP_ADDR				        16
#define HD_LEN_IPHOST_ADDR				    256

#define HD_LEN_DIGITAL_SET_NAME		        32		/* including '\0' */
#define HD_LEN_DIGITAL_SET_STATE_NAME       32	    /* including '\0' */
#define HD_LEN_ALARM_TEST			        128		//报警点Test属性长度，包括szTest1,szTest2,szTest3,szTest4
#define HD_LEN_ALARM_ACTION			        128		//报警点ACTION属性长度，包括szAction1，szAction2，szAction3，szAction4
#define HD_LEN_ALARM_GROUP_NAME		        128		//报警点组名长度
#define HD_LEN_ALARM_GROUP_DESC		        128		//报警点组描述长度
#define HD_LEN_ALARM_COMMENT				256
#define	LENGTH_QUERY_ITEM_VALUE		        32
#define HD_LEN_QUERY_ALARM_REC_ITEM_VALUE   32	    //报警记录查询的记录项的长度
#define HD_LEN_COLLECTOR_NAME				64
#define HD_LEN_COLLECTOR_DESCRIPTION		128
#define HD_LEN_COLLECTOR_EXT_PARAM			512

#define HD_LEN_DEVICE_NAME					64
#define HD_LEN_DEVICE_ADDRESS				32
#define HD_LEN_DEVICE_DESCRIPTION			128
#define HD_LEN_DEVICE_EXT_PARAM				512

#define HD_LEN_SCANGROUP_NAME				64
#define HD_LEN_SCANGROUP_DESCRIPTION		128
#define HD_LEN_SCANGROUP_EXT_PARAM			512	

#define HD_LEN_FILTER_EXPR				128//过滤表达式长度
#define HD_LEN_CALC_EXPR				256//计算表达式的长度
#define HD_LEN_HD_SRV_NAME          64//iHyperDB数据源名称长度


#define MAC_ADDRESS_LEN 32

/* 权限管理约束 */
#define HD_LEN_SEC_PASSWORD			    64				
#define HD_LEN_SEC_GROUP_NAME		    32				
#define HD_LEN_SEC_TRUST_NAME		    64				
#define HD_LEN_SEC_USER_DESC		    64				
#define HD_LEN_SEC_GROUP_DESC		    64				
#define HD_LEN_SEC_IP_ADDRESS		    16	            
#define HD_LEN_SEC_AUTH_ITEM_NAME	    32
#define HD_LEN_SEC_AUTH_ITEM_DESC	    64

#define HD_SEC_AUTH_TYPE_DEFAUT_VALUE    1

/*普通点，报警点，统计点, 计算点，SPC报警点类型*/
#define HD_TAG_CLASS_BASIC				0
#define HD_TAG_CLASS_ALARM				1
#define HD_TAG_CLASS_STATS				2
#define HD_TAG_CLASS_CALC				3
#define HD_TAG_CLASS_SPC				4
#define HD_TAG_CLASS_SYS				5

//Tag类别掩码
#define HD_TAG_CLASS_MASK_NORMAL_TAG			 1
#define HD_TAG_CLASS_MASK_ALARM_TAG			((int64)1 << 1)
#define HD_TAG_CLASS_MASK_STATS_TAG			((int64)1 << 2)
#define HD_TAG_CLASS_MASK_CALC_TAG			((int64)1 << 3)
#define HD_TAG_CLASS_MASK_SPC_TAG				((int64)1 << 4)

#define HD_TAG_CLASS_MASK_ALL					0XFFFFFFFFFFFFFFFFLL

#define TAG_COL_TAGID				        0
#define TAG_COL_REC_OWNER			        1
#define TAG_COL_REC_GROUP			        2
#define TAG_COL_TAG_NAME			        3
#define TAG_COL_ARCHIVING			        4
#define TAG_COL_COMP_DEV			        5
#define TAG_COL_COMP_MAX			        6
#define TAG_COL_COMP_TYPE			        7
#define TAG_COL_REC_ACCESS			        8
#define TAG_COL_SCAN				        9
#define TAG_COL_SPAN				        10
#define TAG_COL_MIN_VALUE			        11
#define TAG_COL_TAG_TYPE			        12
#define TAG_COL_TAG_CLASS			        13
#define TAG_COL_DELETE				        14
#define TAG_COL_VERSION						15
#define TAG_COL_MAX					        15
//报警点特有的属性列
#define TAG_COL_TEST1				        16
#define TAG_COL_TEST2				        17
#define TAG_COL_TEST3				        18
#define TAG_COL_TEST4				        19
#define TAG_COL_ACTION1				        20
#define TAG_COL_ACTION2				        21
#define TAG_COL_ACTION3				        22
#define TAG_COL_ACTION4				        23
#define TAG_COL_SOURCE_TAG			        24
#define TAG_COL_ALARM_GROUP_ID		        25
#define TAG_COL_AUTOACK				        26
#define TAG_COL_TIME_DEADBAND				27
#define TAG_COL_VALUE_DEADBAND			    28

#define ALARM_TAG_COL_MAX			        28
//统计点特有的属性列
#define TAG_COL_STATS_SOURCE_TAG_NAME			16
#define TAG_COL_STATS_TYPE					    17
#define TAG_COL_STATS_SAMPLE_START_DATE	        18
#define TAG_COL_STATS_SAMPLE_MODE			        19
#define TAG_COL_STATS_SAMPLE_INTERVAL		        20
#define TAG_COL_STATS_SAMPLE_BEGIN_OFFSET	        21
#define TAG_COL_STATS_SAMPLE_END_OFFSET	            22
#define TAG_COL_STATS_SAMPLE_MONTH_BEGIN_DAY        23
#define TAG_COL_STATS_SAMPLE_MONTH_END_DAY	        24
#define TAG_COL_STATS_BEGIN_TIME_STAMP		        25
#define TAG_COL_STATS_TIME_STAMP_OFFSET		        26
#define TAG_COL_STATS_PERIOD				        27
#define TAG_COL_STATS_PCT_GOOD			            28
#define TAG_COL_STATS_FILTER_EXPR				    29
#define TAG_COL_STATS_DROP_BAD_MODE			        30
#define TAG_COL_STATS_COUNT_PARAM1		            31
#define TAG_COL_STATS_COUNT_PARAM2		            32

//V2
#define TAG_COL_STATS_SAMPLE_TYPE		        33
#define TAG_COL_STATS_INTERP_OFFSET		        34
#define TAG_COL_STATS_INTERP_PERIOD		        35	
#define TAG_COL_STATS_CONVER_TYPE		        36
#define TAG_COL_STATS_CONVERSION		        37
#define TAG_COL_STATS_FILTER_FAIL_MODE		        38
#define TAG_COL_STATS_CALC_PERIOD				39
#define TAG_COL_STATS_RESET				40
#define TAG_COL_STATS_USE_BAD_VALUE					41

#define STATS_TAG_COL_MAX			            41

/*计算点特有的属性列*/
#define TAG_COL_CALC_MODE							16
#define TAG_COL_CALC_PERIOD					        17
#define TAG_COL_CALC_EXPR							18
#define TAG_COL_CALC_CALCHISTORY                    19
#define TAG_COL_CALC_STARTDATE                      20
#define TAG_COL_CALC_HAVRENDDATE                    21
#define TAG_COL_CALC_ENDDATE                        22
#define TAG_COL_CALC_SOURCETAGNAME		23

#define CALC_TAG_COL_MAX							23

/*SPC报警点特有的属性列*/
#define TAG_COL_SPC_SOURCE_TAG_NAME				    16
#define TAG_COL_SPC_ALARM_GROUP_ID			        17
#define TAG_COL_SPC_CTRL_CHART_TYPE				    18
#define TAG_COL_SPC_TRIGGLE_MODE					19
#define TAG_COL_SPC_SAMPLE_SIZE					20
#define TAG_COL_SPC_SAMPLE_INTERVAL				21
#define TAG_COL_SPC_AUTO_ACK			                        22
#define TAG_COL_SPC_RULE				                        23

#define SPC_TAG_COL_MAX							23

#define TAG_PROP_ITEM_COUNT			       24		//外部可见的TagProp item个数

#define TAG_PROP_ALL				        0XFFFFFFFFFFFFFFFFLL //tag点属性的取值，表示Tag点的所有属性
//基本的Tag属性
#define TAG_PROP_TAG_NAME			        1
#define TAG_PROP_ARCHIVING			        ((int64)1 << TAG_COL_ARCHIVING)
#define TAG_PROP_COMP_DEV			        ((int64)1 << TAG_COL_COMP_DEV)
#define TAG_PROP_COMP_MAX			        ((int64)1 << TAG_COL_COMP_MAX)
#define TAG_PROP_COMP_TYPE			        ((int64)1 << TAG_COL_COMP_TYPE)
#define TAG_PROP_MIN_VALUE			        ((int64)1 << TAG_COL_MIN_VALUE)
#define TAG_PROP_REC_ACCESS			        ((int64)1 << TAG_COL_REC_ACCESS)
#define TAG_PROP_REC_GROUP			        ((int64)1 << TAG_COL_REC_GROUP)
#define TAG_PROP_REC_OWNER			        ((int64)1 << TAG_COL_REC_OWNER)
#define TAG_PROP_SCAN				        ((int64)1 << TAG_COL_SCAN)
#define TAG_PROP_SPAN				        ((int64)1 << TAG_COL_SPAN)
#define TAG_PROP_TAGID				        ((int64)1 << TAG_COL_TAGID)
#define TAG_PROP_TAG_TYPE			        ((int64)1 << TAG_COL_TAG_TYPE)
#define TAG_PROP_TAG_CLASS			        ((int64)1 << TAG_COL_TAG_CLASS)
#define TAG_PROP_DELETE					((int64)1 << TAG_COL_DELETE)

//报警点特有的属性
#define TAG_PROP_TEST1				        ((int64)1 << TAG_COL_TEST1)
#define TAG_PROP_TEST2				        ((int64)1 << TAG_COL_TEST2)
#define TAG_PROP_TEST3				        ((int64)1 << TAG_COL_TEST3)
#define TAG_PROP_TEST4				        ((int64)1 << TAG_COL_TEST4)
#define TAG_PROP_ACTION1			        ((int64)1 << TAG_COL_ACTION1)
#define TAG_PROP_ACTION2			        ((int64)1 << TAG_COL_ACTION2)
#define TAG_PROP_ACTION3			        ((int64)1 << TAG_COL_ACTION3)
#define TAG_PROP_ACTION4			        ((int64)1 << TAG_COL_ACTION4)
#define TAG_PROP_SOURCE_TAG			        ((int64)1 << TAG_COL_SOURCE_TAG)
#define TAG_PROP_ALARM_GROUP_ID		        ((int64)1 << TAG_COL_ALARM_GROUP_ID)
#define TAG_PROP_AUTOACK			        ((int64)1 << TAG_COL_AUTOACK)
#define TAG_PROP_TIME_DEADBAND	        ((int64)1 << TAG_COL_TIME_DEADBAND)
#define TAG_PROP_VALUE_DEADBAND	        ((int64)1 << TAG_COL_VALUE_DEADBAND)

//统计点特有属性
#define TAG_PROP_STATS_SOURCE_TAG_NAME		        ((int64)1 << TAG_COL_STATS_SOURCE_TAG_NAME)
#define TAG_PROP_STATS_TYPE					       ((int64)1 << TAG_COL_STATS_TYPE)
#define TAG_PROP_STATS_SAMPLE_START_DATE	        ((int64)1 << TAG_COL_STATS_SAMPLE_START_DATE)
#define TAG_PROP_STATS_SAMPLE_MODE		        ((int64)1 << TAG_COL_STATS_SAMPLE_MODE)
#define TAG_PROP_STATS_SAMPLE_INTERVAL	        ((int64)1 << TAG_COL_STATS_SAMPLE_INTERVAL)
#define TAG_PROP_STATS_SAMPLE_BEGIN_OFFSET      ((int64)1 << TAG_COL_STATS_SAMPLE_BEGIN_OFFSET)
#define TAG_PROP_STATS_SAMPLE_END_OFFSET	        ((int64)1 << TAG_COL_STATS_SAMPLE_END_OFFSET)
#define TAG_PROP_STATS_SAMPLE_MONTH_BEGIN_DAY	((int64)1 << TAG_COL_STATS_SAMPLE_MONTH_BEGIN_DAY)
#define TAG_PROP_STATS_SAMPLE_MONTH_END_DAY	        ((int64)1 << TAG_COL_STATS_SAMPLE_MONTH_END_DAY)
#define TAG_PROP_STATS_BEGIN_TIME_STAMP	        ((int64)1 << TAG_COL_STATS_BEGIN_TIME_STAMP)
#define TAG_PROP_STATS_TIME_STAMP_OFFSET	        ((int64)1 << TAG_COL_STATS_TIME_STAMP_OFFSET)
#define TAG_PROP_STATS_SCAN_PERIOD			        ((int64)1 << TAG_COL_STATS_PERIOD)
#define TAG_PROP_STATS_PCT_GOOD			        ((int64)1 << TAG_COL_STATS_PCT_GOOD)
#define TAG_PROP_STATS_FILTER_EXPR			        ((int64)1 << TAG_COL_STATS_FILTER_EXPR)
#define TAG_PROP_STATS_DROP_BAD_MODE			((int64)1 << TAG_COL_STATS_DROP_BAD_MODE)
#define TAG_PROP_STATS_COUNT_PARAM1		        ((int64)1 << TAG_COL_STATS_COUNT_PARAM1)
#define TAG_PROP_STATS_COUNT_PARAM2		        ((int64)1 << TAG_COL_STATS_COUNT_PARAM2)
#define TAG_PROP_STATS_SAMPLE_TYPE    ((int64)1 << TAG_COL_STATS_SAMPLE_TYPE)
#define TAG_PROP_STATS_INTERP_OFFSET    ((int64)1 << TAG_COL_STATS_INTERP_OFFSET)
#define TAG_PROP_STATS_INTERP_PERIOD    ((int64)1 << TAG_COL_STATS_INTERP_PERIOD)
#define TAG_PROP_STATS_CONVER_TYPE    ((int64)1 << TAG_COL_STATS_CONVER_TYPE)
#define TAG_PROP_STATS_CONVERSION    ((int64)1 << TAG_COL_STATS_CONVERSION)
#define TAG_PROP_STATS_FILTER_FAIL_MODE    ((int64)1 << TAG_COL_STATS_FILTER_FAIL_MODE)
#define TAG_PROP_STATS_CALC_PERIOD    ((int64)1 << TAG_COL_STATS_CALC_PERIOD)
#define TAG_PROP_STATS_RESET    ((int64)1 << TAG_COL_STATS_RESET)
#define TAG_PROP_STATS_USE_BAD_VALUE    ((int64)1 << TAG_COL_STATS_USE_BAD_VALUE)


/*计算点特有的属性*/
#define TAG_PROP_CALC_MODE		        ((int64)1 << TAG_COL_CALC_MODE)
#define TAG_PROP_CALC_PERIOD		        ((int64)1 << TAG_COL_CALC_PERIOD)
#define TAG_PROP_CALC_EXPR			        ((int64)1 << TAG_COL_CALC_EXPR)
#define TAG_PROP_CALC_STARTDATE             ((int64)1 << TAG_COL_CALC_STARTDATE)
#define TAG_PROP_CALC_ENDDATE             ((int64)1 << TAG_COL_CALC_ENDDATE)
#define TAG_PROP_CALC_CALCHISTORY         ((int64)1 << TAG_COL_CALC_CALCHISTORY)
#define TAG_PROP_CALC_HAVEENDTIME         ((int64)1 << TAG_COL_CALC_HAVRENDDATE)
#define TAG_PROP_CALC_SOURCE_TAG_NAME	((int64)1 << TAG_COL_CALC_SOURCETAGNAME)

/*SPC点特有的属性*/
#define TAG_PROP_SPC_SOURCE_TAG_NAME		        ((int64)1 << TAG_COL_SPC_SOURCE_TAG_NAME)
#define TAG_PROP_SPC_ALARM_GROUP_ID		        ((int64)1 << TAG_COL_SPC_ALARM_GROUP_ID)
#define TAG_PROP_SPC_CTRL_CHART_TYPE		        ((int64)1 << TAG_COL_SPC_CTRL_CHART_TYPE)
#define TAG_PROP_SPC_TRIGGLE_MODE				((int64)1 << TAG_COL_SPC_TRIGGLE_MODE)
#define TAG_PROP_SPC_SAMPLE_SIZE				((int64)1 << TAG_COL_SPC_SAMPLE_SIZE)
#define TAG_PROP_SPC_SAMPLE_INTERVAL			((int64)1 << TAG_COL_SPC_SAMPLE_INTERVAL)
#define TAG_PROP_SPC_AUTO_ACK					((int64)1 << TAG_COL_SPC_AUTO_ACK)
#define TAG_PROP_SPC_RULE						((int64)1 << TAG_COL_SPC_RULE)

#define SPC_RULE(NUM)\
	uint32 nUCLTagID;\
	uint32 nCLTagID;\
	uint32 nLCLTagID;\
	uint32 nUSLTagID;\
	uint32 nLSLTagID;\
	uint32 nResetTagID;\
	float64 dUCLDefaultValue;\
	float64 dCLDefaultVaule;\
	float64 dLCLDefaultValue;\
	bool bRule1;\
	bool bRule2;\
	bool bRule3;\
	bool bRule4;\
	bool bRule5;\
	bool bRule6;\
	bool bRule7;\
	bool bRule8;\
	uint32 nRule1M;\
	uint32 nRule2M;\
	uint32 nRule3M;\
	uint32 nRule4M;\
	uint32 nRule5M;\
	uint32 nRule6M;\
	uint32 nRule7M;\
	uint32 nRule8M;\
	uint32 nRule5N;\
	uint32 nRule6N;\
	bool bJudgeContinuous


//删除分布式版本不需要的属性
#define TAG_BASE_PROP(NUM)										\
	char	szTagName[HD_LEN_TAG_NAME * NUM];					\
	bool	bArchiving;											\
	float	fCompDev;											\
	int32	nCompMaxTime;										\
	uint8	nCompType;											\
	uint8	nRecAccess;											\
	uint32 nRecNormalGroupID;									\
	uint32 nRecOwnerGroupID;									\
	uint32	nTagID;												\
	uint8	nTagType;											\
	bool	bScan;												\
	float	fSpan;												\
	float	fMinValue;											\
	uint8	nTagClass;											\
	bool bDelete


#define TAG_EXT_PROP(NUM)										\
	char	szInstrumentPoint[HD_LEN_INSTURMENT_POINT * NUM];	\
	uint8	nInstrumentPointType;								\
	char	szCollectorName[HD_LEN_COLLECTOR_NAME * NUM];		\
	int32	nCollectorID;										\
	char	szDeviceName[HD_LEN_DEVICE_NAME * NUM];				\
	int32	nDeviceID;											\
	char	szScanGroupName[HD_LEN_SCANGROUP_NAME * NUM];		\
	int32	nScanGroupID;										\
	uint8	nParam1;											\
	uint8	nParam2;											\
	uint8	nParam3;											\
	uint8	nParam4;											\
	uint8	nParam5

#define ALARM_TAG_EXT_PROP(NUM)									\
	char szTest1[HD_LEN_ALARM_TEST * NUM];						\
	char szTest2[HD_LEN_ALARM_TEST * NUM];						\
	char szTest3[HD_LEN_ALARM_TEST * NUM];						\
	char szTest4[HD_LEN_ALARM_TEST * NUM];						\
	char szAction1[HD_LEN_ALARM_ACTION * NUM];					\
	char szAction2[HD_LEN_ALARM_ACTION * NUM];					\
	char szAction3[HD_LEN_ALARM_ACTION * NUM];					\
	char szAction4[HD_LEN_ALARM_ACTION * NUM];					\
	uint32 nSourceTagID;				\
	uint32 nAlarmGroupID;										\
	uint8 nAutoAck	;											\
	int32 nTimeDeadBand;										\
	float fValueDeadBand

#define STATS_TAG_EXT_PROP(NUM)									\
	char szSourceTagName[HD_LEN_TAG_NAME * NUM];			\
	uint8 nStatsType;										\
	int32 nSampleStartDate;									\
	uint8 nSampleMode;										\
	int32 nSampleInerval;									\
	int32 nSampleBeginOffset;									\
	int32 nSampleEndOffset;									\
	uint8 nSampleMonthBeginDay;								\
	uint8 nSampleMonthEndDay;								\
	bool bBeginTimeStamp;									\
	int32 nTimeStampOffset;									\
	int32 nScanPeriod;										\
	float fPctGood;											\
	char szFilterExpr[HD_LEN_FILTER_EXPR * NUM];			\
	uint8 nDropBadMode;									\
	double dCountParam1;									\
	double dCountParam2


#define STATS_TAG_EXT_PROP_V2(NUM)									\
	uint8 nSampleType;										\
	int32 nInterpOffset;										\
	int32 nInterpPeriod;										\
	uint8 nConverType;										\
	double dConversion;										\
	uint8 nFilterFailMode;									\
	int32 nCalcPeriod;										\
	bool bReset;											\
	bool bUseBadValue

#define Calc_TAG_EXT_PROP(NUM)							\
	uint8 nCalcMode;										\
	int32 nCalcPeriod;										\
	char szCalcExpr[HD_LEN_CALC_EXPR * NUM];                  \
	bool bCalcHistory;                                       \
	int32 nCalcStartDate;                                    \
	int32 nCalcEndDate;                                      \
	bool bHaveEndTime;						\
	char szSourceTagName[HD_LEN_TAG_NAME * NUM]

#define SPC_TAG_EXT_PROP(NUM)									\
	uint32 nSourceTagID;				\
	uint32 nAlarmGroupID;										\
	uint8 nCtrlChartType;											\
	uint8	nTriggleMode;											\
	int32 nSampleSize;											\
	int32 nSampleInerval;											\
	bool bAutoAck;											\
	SPC_RULE(NUM)



/*点属性结构 */
typedef struct _TagBaseProp
{
	TAG_BASE_PROP(1);
}TagBaseProp;

typedef struct _TagProp
{
	TAG_BASE_PROP(1);
}TagProp;

typedef struct _AlarmTagProp
{
	TAG_BASE_PROP(1);
	ALARM_TAG_EXT_PROP(1);
}AlarmTagProp;

typedef struct _SPCAlarmTagProp
{
	TAG_BASE_PROP(1);
	SPC_TAG_EXT_PROP(1);
}SPCAlarmTagProp;

typedef struct _StatsTagProp
{
	TAG_BASE_PROP(1);
	STATS_TAG_EXT_PROP(1);
}StatsTagProp;

typedef struct _StatsTagPropV2
{
	TAG_BASE_PROP(1);
	STATS_TAG_EXT_PROP(1);
	STATS_TAG_EXT_PROP_V2(1);
}StatsTagPropV2;

typedef struct _CalcTagProp
{
	TAG_BASE_PROP(1);
	Calc_TAG_EXT_PROP(1);
}CalcTagProp;

typedef struct _QueryTagPropItem
{
	uint8	nPropItemID;
	uint8	nRelation;
	char	szValue[LENGTH_QUERY_ITEM_VALUE];
}QueryTagPropItem;


//条件查询报警记录时的查询项ID
#define ALARM_REC_QUERY_ITEM_MIN			0
#define ALARM_REC_QUERY_ITEM_PRIORITY		0	//优先级
#define ALARM_REC_QUERY_ITEM_ACK			1	//确认状态
#define ALARM_REC_QUERY_ITEM_ALARM_TYPE		2	//报警类型
#define ALARM_REC_QUERY_ITEM_NORMAL			3	//是否查询正常的报警记录
#define ALARM_REC_QUERY_ITEM_MAX			3
typedef struct _QueryAlarmRecItem
{
	uint8	nItemID;
	uint8	nRelation;
	char	szValue[HD_LEN_QUERY_ALARM_REC_ITEM_VALUE];
}QueryAlarmRecItem;

/*用于历史报警记录查询，表明选中所有的可选项*/
#define MASK_ALARM_ALL						0XFF

/*报警记录的确认状态*/
#define ALARM_STATE_UNACK					0
#define ALARM_STATE_ACK						1

/*报警确认状态掩码，用于历史报警查询接口*/
#define MASK_ALARM_STATE_ACK				(1 << ALARM_STATE_ACK)
#define MASK_ALARM_STATE_UNACK				(1 << ALARM_STATE_UNACK)


/*恢复状态*/
#define ALARM_STATE_UNRESTORE				0
#define ALARM_STATE_RESTORE					1
/*掩码*/
#define MASK_ALARM_STATE_RESTORE			(1 << ALARM_STATE_RESTORE)
#define MASK_ALARM_STATE_UNRESTORE			(1 << ALARM_STATE_UNRESTORE)


/*注释状态*/
#define ALARM_STATE_UNCOMMENT				0
#define ALARM_STATE_COMMENT					1
/*掩码*/
#define MASK_ALARM_STATE_COMMENT			(1 << ALARM_STATE_COMMENT)
#define MASK_ALARM_STATE_UNCOMMENT			(1 << ALARM_STATE_UNCOMMENT)


/*报警记录的优先级,0为最低*/
#define ALARM_PRI_FIRST						1
#define ALARM_PRI_SECOND					2
#define ALARM_PRI_THIRD						3
#define ALARM_PRI_FORTH						4
#define ALARM_PRI_COUNT						4

/*报警优先级掩码，用于历史报警查询接口*/
#define MASK_ALARM_PRIORITY_LOW				(1 << ALARM_PRI_FIRST)
#define MASK_ALARM_PRIORITY_MID				(1 << ALARM_PRI_SECOND)
#define MASK_ALARM_PRIORITY_HIGH			(1 << ALARM_PRI_THIRD)
#define MASK_ALARM_PRIORITY_EMER			(1 << ALARM_PRI_FORTH)

/*报警记录的报警类型*/
#define ALARM_TYPE_LOLO						1
#define ALARM_TYPE_LOW						2
#define ALARM_TYPE_HIHI						3
#define ALARM_TYPE_HIGH						4
#define ALARM_TYPE_CHANGE					5
#define ALARM_TYPE_COUNT					5

/*报警类型的掩码，用于历史报警查询接口*/
#define MASK_ALARM_TYPE_LOLO				(1 << ALARM_TYPE_LOLO)
#define MASK_ALARM_TYPE_LOW					(1 << ALARM_TYPE_LOW)
#define MASK_ALARM_TYPE_HIHI				(1 << ALARM_TYPE_HIHI)
#define MASK_ALARM_TYPE_HIGH				(1 << ALARM_TYPE_HIGH)
#define MASK_ALARM_TYPE_CHANGE				(1 << ALARM_TYPE_CHANGE)

//报警记录属性掩码
#define ALARM_REC_PROP_ALARM_TAG_ID			1
#define ALARM_REC_PROP_START_TIME		    ((int64)1 << 1)
#define ALARM_REC_PROP_END_TIME				((int64)1 << 2)
#define ALARM_REC_PROP_ACK_TIME				((int64)1 << 3)
#define ALARM_REC_PROP_COMMENT_TIME			((int64)1 << 4)
#define ALARM_REC_PROP_ACKED		        ((int64)1 << 5)
#define ALARM_REC_PROP_RESTORED		        ((int64)1 << 6)
#define ALARM_REC_PROP_PRIORITY				((int64)1 << 7)
#define ALARM_REC_PROP_ACK_TYPE				((int64)1 << 8)
#define ALARM_REC_PROP_ALARM_TYPE			((int64)1 << 9)
#define ALARM_REC_PROP_SRC_VALUE			((int64)1 << 10)
#define ALARM_REC_PROP_TEST					((int64)1 << 11)
#define ALARM_REC_PROP_COMMENT				((int64)1 << 12)
#define ALARM_REC_PROP_ACKER				((int64)1 << 13)
#define ALARM_REC_PROP_COMMENTOR			((int64)1 << 14)
#define ALARM_REC_PROP_COMMENTED			((int64)1 << 15)

#define ALARM_REC_PROP_ALL					0xFFFF

#define ALARM_ACK_TYPE_MANUAL			1
#define ALARM_ACK_TYPE_AUTO				2
#define ALARM_ACK_TYPE_COUNT			2

#define ALARM_TAG_PROP_NUM_EXCEL_MAX    24



//条件查询记录时的查询项ID
#define REC_QUERY_ITEM_MIN			0
#define REC_QUERY_ITEM_QUALITY		0	//质量
#define REC_QUERY_ITEM_VALUE		1	//值
#define REC_QUERY_ITEM_MAX			1

typedef struct _QueryRecItem
{
	uint8 nItemID;
	uint8 nRelation;
	uint8 nItemValueLen;
	char* pItemValue;
}QueryRecItem;

#define RELATION_MIN						0
#define RELATION_EQUAL						0
#define RELATION_NON_EQUAL					1
#define RELATION_GREAT						2
#define RELATION_LESS						3
#define RELATION_GREAT_AND_EQUAL			4
#define RELATION_LESS_AND_EQUAL				5
#define RELATION_LIKE						6
#define RELATION_MAX						6



/** 时间从1970年1月0日00:00:01到2038年1月19日3:14:06 */
typedef struct _HDTimeStamp{
	int32 month;				/**< 1-12 */
	int32 year;					/**< four digit */
	int32 day;					/**< 1-31 */ 
	int32 hour;					/**< 0-23 */ 
	int32 minute;				/**< 0-59 */ 
	int32 second;				/**< 0-59*/ 
	int32 mSecond;				/**< 0-999*/
	int32 timezone;				/**< -12~12*/
}HDTimeStamp;

typedef struct
{
	int32 nSec;
	int16 nMsec;
}HDTime;

typedef struct _HDTimeRegion
{
	HDTime left;		//左区间
	HDTime right;		//右区间
	bool bLeftClosed;	//左区间开或是闭
	bool bRightClosed;  //右区间开或是闭
}HDTimeRegion;



#define API_CLIENT_MAX_SOCKET_NUM 100
typedef struct _HDClientConnInfo
{
	uint32 nClientIp;
	char szMac[32];
	int32 nSocketNum;
	SOCKET nSocket[API_CLIENT_MAX_SOCKET_NUM];
}HDClientConnInfo;

typedef struct _HDSocketNetInfo
{
	SOCKET nSocket;
	int32 nConnectTime;
	int32 nPackageRecvNum;
	int32 nPackageRecvTime;
	char szUserName[HD_LEN_USER_NAME*2];
}HDSocketNetInfo;

#define HD_LEN_HD_VERSION	128
// 节点配置信息
typedef struct  _HDServerCfg{
	int32 nPort;			//网络端口号
	int32 nArchFileSizeMB;	//单个归档文件的大小
	int32 nArchFileNum;		//归档文件个数
	int32 nSeqFileSizeMB;	//单个序列缓存文件的大小
	int32 nSeqCacheFlushPeriodSec; // 序列缓存刷新频率
	bool bAutoDisconn;				//是否自动断开无数据交互的连接
	int32 nAutoDisconnPeriodSec;		//自动无数据交互连接的超时时间
	bool bSysInfoCollect;				//是否采集系统信息
	int32 nSysInfoCollectPeriodSec;		//系统信息采集间隔
	bool bDiscardFutureData;				//是否丢弃超过服务器时间戳的未来数据
	int32 nDiscardFutureDataTimeDelterSec;		//超过服务器时间戳的时间偏差
	int64 nMachineTimeMs;				//服务端的相对时间(毫秒)
	int32 nEnableExportBigData;
	int32 nEnableRyBigData;
	int32 nEnableihdRT2ihd;
	char szHDVersion[HD_LEN_HD_VERSION];
}HDServerCfg;

// rest配置信息
//paramBody.put("name", dsName);
//  paramBody.put("hostip", hostip);
//  paramBody.put("port", port);
//  paramBody.put("user", user);
//  paramBody.put("password", pwd);
//  paramBody.put("hostname", "/");
//  paramBody.put("exchange", "v6-direct-exchange");
//  paramBody.put("routingrtalms", "CR_AL_00");
//  paramBody.put("routingclearalm", "CR_AL_01");
//  paramBody.put("routingrtrec", "CR_RT_00");
//  paramBody.put("routingcrs", "CR_RS_00");
//  */
#define HD_LEN_REST_CONFIG_COMMON	64
typedef struct  _HDRestCfg{
	char szDsName[HD_LEN_REST_CONFIG_COMMON];
	char szHostIP[HD_LEN_REST_CONFIG_COMMON];
	char szPort[HD_LEN_REST_CONFIG_COMMON];	
	char szPassword[HD_LEN_REST_CONFIG_COMMON];
	char szMaxTotal[HD_LEN_REST_CONFIG_COMMON];
	char szMaxWait[HD_LEN_REST_CONFIG_COMMON];
	char szMasterName[HD_LEN_REST_CONFIG_COMMON];
	char szRoutingrtalms[HD_LEN_REST_CONFIG_COMMON];
	char szRoutingclearalm[HD_LEN_REST_CONFIG_COMMON];
	char szRoutingrtrec[HD_LEN_REST_CONFIG_COMMON];
	char szRoutingcrs[HD_LEN_REST_CONFIG_COMMON];
	char szUser[HD_LEN_REST_CONFIG_COMMON];
	char szHostName[HD_LEN_REST_CONFIG_COMMON];
	char szExChange[HD_LEN_REST_CONFIG_COMMON];
	char szExtend1[HD_LEN_REST_CONFIG_COMMON];
	char szExtend2[HD_LEN_REST_CONFIG_COMMON];
	char szExtend3[HD_LEN_REST_CONFIG_COMMON];
	char szExtend4[HD_LEN_REST_CONFIG_COMMON];
}HDRestCfg;

/** iHyperDB 注册信息ID+域 */
typedef struct _HDRegInfo 
{
	uint32 nTagID;							/**< TAG点ID*/
	uint32 nFieldID;						/**< 域ID*/
} HDRegInfo;

typedef struct
{
	int32 nSec;
	int16 nMsec;
	uint16 nQuality;
	uint8 nTagType;
	struct
	{
		int8 nInt8;
		int16 nInt16;
		int32 nInt32;
		float32 fFloat32;
		float64 fFloat64;
		int8 nDigital;
		struct
		{
			char* pBuf;
			uint16 nLenBuf;
		}strBlob;
	}value;
}HDRecord;

//数据节点资源使用情况
typedef struct
{
	uint32 nServerId;								//数据节点id
	uint32 nCurrArcindex;							//当前使用归档文件编号
	int64 nArcfileNum;							//归档文件总数量
	int64 nAverTimeMin;								//归档文件平均使用时间（单位:分钟）
	int64 nArcfileSizeMb;                           //单个归档文件最大容量（单位：Mb）
}HD3Capacity;

// Driver types
#define DRIVER_TYPE_OPC			        1
#define DRIVER_TYPE_TCPMODBUS	        2

//统计类型
#define HD_STATS_TYPE_MAX						0		//最大值
#define HD_STATS_TYPE_MIN						1		//最小值
#define HD_STATS_TYPE_SUM						2		//求和
#define HD_STATS_TYPE_LAST						3		//最新值
#define HD_STATS_TYPE_PCT_GOOD					4		//可信度
#define HD_STATS_TYPE_ARITH_MEAN				5		//算术平均值
#define HD_STATS_TYPE_TIME_WEIGHTED_MEAN 		6		//时间加权平均值
#define HD_STATS_TYPE_INTEGRAL					7		//积分
#define HD_STATS_TYPE_COUNT_CHG_VALUE		8		//值变化
#define HD_STATS_TYPE_COUNT_CHG_FROM_LESS_TO_GREAT		9	//区间变化,从<=到>=
#define HD_STATS_TYPE_COUNT_CHG_FROM_GREAT_TO_LESS		10	//区间变化，从>=到<=
#define HD_STATS_TYPE_DIFF									11	//差值统计
#define HD_STATS_TYPE_COUNT_IN_RANGE						12	//值在区间
#define HD_STATS_TYPE_COUNT_NOT_IN_RANGE					13	//值不在区间
#define HD_STATS_TYPE_RANGE								14	//极差
#define HD_STATS_TYPE_STANDARD_DEVIATION					15	//标准差
#define HD_STATS_TYPE_TIME_GT								16	//大于某个值的时间
#define HD_STATS_TYPE_TIME_GE								17	//大于等于某个值的时间
#define HD_STATS_TYPE_TIME_EQ								18	//等于某个值的时间
#define HD_STATS_TYPE_TIME_NE								19	//不等于某个值的时间
#define HD_STATS_TYPE_TIME_LT								20	//小于某个值的时间
#define HD_STATS_TYPE_TIME_LE								21	//小于等于某个值的时间
#define HD_STATS_TYPE_TIME_IN_RANGE						22	//在某个值区间的时间
#define HD_STATS_TYPE_TIME_NOT_IN_RANGE					23	//不在某个值区间的时间
#define HD_STATS_TYPE_LIMIT_MAX							23	//统计类型值的最大值, 做校验用

//统计点采样模式
#define HD_STATS_SAMPLE_MODE_INTERVAL		0	//统计等间隔采样
#define HD_STATS_SAMPLE_MODE_EVERY_DAY	1	//统计每天同时段采样
#define HD_STATS_SAMPLE_MODE_EVERY_MONTH	2	//统计每月同时段采样
#define HD_STATS_SAMPLE_MODE_TIME_MOVING		3	//时间移动采样
#define HD_STATS_SAMPLE_MODE_FOREVER			4	//时间移动采样
#define HD_STATS_SAMPLE_MODE_MAX				5

//统计转换类型
#define HD_STATS_CONVERSION_TYPE_AMPLIFICATION		0 //统计值放大
#define HD_STATS_CONVERSION_TYPE_MINIFICATION			1 //统计值缩小

#define HD_STATS_CONVERSION_TYPE_MAX					1//最大值，做校验

//统计点采样类型
#define HD_STATS_SAMPLE_TYPE_RAW					0	//采样点都是原始值
#define HD_STATS_SAMPLE_TYPE_LINER_INTERP			1	//采样点都是线性插值
#define HD_STATS_SAMPLE_TYPE_PREV_INTERP			2	//采样点都是前向插值
#define HD_STATS_SAMPLE_TYPE_MAX					2	//最大采样类型值

//统计点弃坏点模式
#define HD_STATS_DROP_BAD_MODE_REC		0	//弃坏点模式——弃bad记录
#define HD_STATS_DROP_BAD_MODE_AREA		1	//弃坏点模式——弃bad记录相邻的区域
#define HD_STATS_DROP_BAD_MODE_MAX		1

// 求均值模式
#define HD_STATS_TIMED_WEIGHT_MODE			1		//以时间为权值
#define HD_STATS_RECORD_WEIGHT_MODE		2			// 无权值


// count计算模式，值变化模式和区间变化模式
#define HD_STATS_COUNT_MODE_CHANGE_VALUE				1
#define HD_STATS_COUNT_MODE_GREATER_CHANGE_TO_LESS		2
#define HD_STATS_COUNT_MODE_LESS_CHANGE_TO_GREATER		3
#define HD_STATS_COUNT_MODE_IN_RANGE							4
#define HD_STATS_COUNT_MODE_NOT_IN_RANGE					5

// 过滤表达式计算失败是否需过滤
#define HD_STATS_FILTER_FAIL_MODE_FIL			0
#define HD_STATS_FILTER_FAIL_MODE_NO_FIL				1
#define HD_STATS_FILTER_FAIL_MODE_LIMIT_MAX		1

/*计算点模式*/
#define HD_CALC_MODE_POLL				0	//计算模式——轮询
#define HD_CALC_MODE_NOTIFY			1	//计算模式——通知

#define HD_CALC_MODE_MAX				1	//计算模式的最大值，用来校验

//tag分组下载
#define  RES_TAG_NAME_SERVER_IP "服务器IP"
#define  RES_TAG_NAME_SERVER_PORT "端口号"
#define  RES_TAG_NAME_TAGID "TagID"
#define  RES_TAG_NAME_TAGNAME "Tag名称"
#define  RES_TAG_NAME_TAGTYPE "Tag类别"
#define  RES_TAG_NAME_TAG_DISC "Tag描述"
#define  RES_TAG_NAME_NODENAME "节点名称"
#define  RES_TAG_NAME_NODEID "节点ID"
#define  RES_TAG_NAME_GROUPPATH "分组路径"

//采集器类型
enum
{
	COLLECTOR_TYPE_INVALID = -1,
	COLLECTOR_TYPE_OPC,
	COLLECTOR_TYPE_MODBUS,
	COLLECTOR_TYPE_RDB,
	COLLECTOR_TYPE_IHD,
	COLLECTOR_TYPE_MAX
};

//记录的插值查询模式
#define  HD_REC_INTERP_QUERY_MODE_LINEAR		0		//线性插值
#define  HD_REC_INTERP_QUERY_MODE_PREV		1		//前向插值
#define  HD_REC_INTERP_QUERY_MODE_MAX		1		//最大值，用来校验

// 数据量状态集
#define HD_DIGITAL_SET_MAX_STATE_NUM		256
#define HD_DIGITAL_SET_MAX_STATE_VAL		127
#define HD_DIGITAL_SET_MIN_STATE_VAL		-128

// 采集器状态点类型
#define HD_CT_STATUS_TAG_TYPE_COLLECTOR		1
#define HD_CT_STATUS_TAG_TYPE_DEVICE		2

//SPC报警控制图类型对应于SPCBasicDef.h中的枚举类型 SPCChartType
#define HD_SPC_CTRL_CHART_TYPE_MIN	13	//控制图类型的最小值，用来做参数校验
#define HD_SPC_CTRL_CHART_TYPE_XBAR	13	//XBar类型
#define HD_SPC_CTRL_CHART_TYPE_R	14	//R图
#define HD_SPC_CTRL_CHART_TYPE_S	15	//S图
#define HD_SPC_CTRL_CHART_TYPE_MAX	15	//控制图类型的最大值，用来做参数校验

//SPC报警触发模式
#define HD_SPC_TRIGGLE_MODE_TRIGGLE	0
#define HD_SPC_TRIGGLE_MODE_MAX		0

//SPC报警记录属性掩码
#define SPC_ALARM_REC_PROP_SPC_TAG_ID			1
#define SPC_ALARM_REC_PROP_START_TIME		    ((int64)1 << 1)
#define SPC_ALARM_REC_PROP_END_TIME				((int64)1 << 2)
#define SPC_ALARM_REC_PROP_ACK_TIME				((int64)1 << 3)
#define SPC_ALARM_REC_PROP_COMMENT_TIME			((int64)1 << 4)
#define SPC_ALARM_REC_PROP_ACKED		        ((int64)1 << 5)
#define SPC_ALARM_REC_PROP_ACK_TYPE				((int64)1 << 6)
#define SPC_ALARM_REC_PROP_RESTORED		        ((int64)1 << 7)
#define SPC_ALARM_REC_PROP_COMMENTED			((int64)1 << 8)
#define SPC_ALARM_REC_PROP_ALARM_VALUE			((int64)1 << 9)
#define SPC_ALARM_REC_PROP_RULE					((int64)1 << 10)
#define SPC_ALARM_REC_PROP_SRC_VALUE			((int64)1 << 11)
#define SPC_ALARM_REC_PROP_COMMENT				((int64)1 << 12)
#define SPC_ALARM_REC_PROP_ACKER				((int64)1 << 13)
#define SPC_ALARM_REC_PROP_COMMENTOR			((int64)1 << 14)

#define SPC_ALARM_REC_PROP_ALL					0xFFFF

//SPC报警规则M，N值的最大值和最小值
#define SPC_ALARM_RULE_M_N_VALUE_MIN			1
#define SPC_ALARM_RULE_M_N_VALUE_MAX			99

//SPC报警值掩码
#define SPC_ALARM_VALUE_MASK_RULE1			 1
#define SPC_ALARM_VALUE_MASK_RULE2			 ((int8)1 << 1)
#define SPC_ALARM_VALUE_MASK_RULE3			 ((int8)1 << 2)
#define SPC_ALARM_VALUE_MASK_RULE4			 ((int8)1 << 3)
#define SPC_ALARM_VALUE_MASK_RULE5			 ((int8)1 << 4)
#define SPC_ALARM_VALUE_MASK_RULE6			 ((int8)1 << 5)
#define SPC_ALARM_VALUE_MASK_RULE7			 ((int8)1 << 6)
#define SPC_ALARM_VALUE_MASK_RULE8			 ((int8)1 << 7)

// 系统点前缀
#define HD_SYS_TAG_PREFIX	"hdsys"

//OPC发布状态
#define HD_TAG_OPC_STATE_UNRELEASE	0
#define HD_TAG_OPC_STATE_RELEASE	1

#define LICENSE_OEM_VCODE_MAXLEN	4

// API版本
#define HD_API_VER_0	0
#define HD_API_VER_1	1

//授权项的权限类型
#define HD_SEC_AUTH_READ_DISABLE	0
#define HD_SEC_AUTH_READ_ENABLE	1

#define HD_SEC_AUTH_MAX   1//用来校验

#define HD_INS_POINT_TYPE_BASE     1
//modbus data point type
#define HD_INS_POINT_TYPE_INT8     (HD_INS_POINT_TYPE_BASE + 0)
#define HD_INS_POINT_TYPE_UINT8   (HD_INS_POINT_TYPE_BASE + 1)
#define HD_INS_POINT_TYPE_INT16    (HD_INS_POINT_TYPE_BASE + 2)
#define HD_INS_POINT_TYPE_UINT16  (HD_INS_POINT_TYPE_BASE + 3)
#define HD_INS_POINT_TYPE_INT32    (HD_INS_POINT_TYPE_BASE + 4)
#define HD_INS_POINT_TYPE_UINT32  (HD_INS_POINT_TYPE_BASE + 5)
#define HD_INS_POINT_TYPE_FLOAT    (HD_INS_POINT_TYPE_BASE + 6)
#define HD_INS_POINT_TYPE_DOUBLE   (HD_INS_POINT_TYPE_BASE + 7)
#define HD_INS_POINT_TYPE_STRING   (HD_INS_POINT_TYPE_BASE + 8)
#define HD_INS_POINT_TYPE_BLOB     (HD_INS_POINT_TYPE_BASE + 9)
#define HD_INS_POINT_TYPE_DIGITAL  (HD_INS_POINT_TYPE_BASE + 10)
#define HD_INS_POINT_TYPE_MAX      (HD_INS_POINT_TYPE_BASE + 11)


#define HD_MODBUS_DATA_ORDER_BASE     1

#define HD_MODBUS_DATA_NO_ORDER   (HD_MODBUS_DATA_ORDER_BASE - 1)

#define HD_MODBUS_DATA_ORDER_12    (HD_MODBUS_DATA_ORDER_BASE + 0)
#define HD_MODBUS_DATA_ORDER_21    (HD_MODBUS_DATA_ORDER_BASE + 1)
#define HD_MODBUS_DATA_ORDER_1234   (HD_MODBUS_DATA_ORDER_BASE + 2)
#define HD_MODBUS_DATA_ORDER_2143    (HD_MODBUS_DATA_ORDER_BASE + 3)
#define HD_MODBUS_DATA_ORDER_3412    (HD_MODBUS_DATA_ORDER_BASE + 4)
#define HD_MODBUS_DATA_ORDER_4321    (HD_MODBUS_DATA_ORDER_BASE + 5)
#define HD_MODBUS_DATA_ORDER_12345678  (HD_MODBUS_DATA_ORDER_BASE + 6)
#define HD_MODBUS_DATA_ORDER_21436587  (HD_MODBUS_DATA_ORDER_BASE + 7)
#define HD_MODBUS_DATA_ORDER_34127856  (HD_MODBUS_DATA_ORDER_BASE + 8)  
#define HD_MODBUS_DATA_ORDER_43218765  (HD_MODBUS_DATA_ORDER_BASE + 9)
#define HD_MODBUS_DATA_ORDER_56781234  (HD_MODBUS_DATA_ORDER_BASE + 10)
#define HD_MODBUS_DATA_ORDER_65872143  (HD_MODBUS_DATA_ORDER_BASE + 11)
#define HD_MODBUS_DATA_ORDER_78563412  (HD_MODBUS_DATA_ORDER_BASE + 12)
#define HD_MODBUS_DATA_ORDER_87654321  (HD_MODBUS_DATA_ORDER_BASE + 13)

#define HD_MODBUS_CONNECT_TYPE_TCP  0
#define HD_MODBUS_CONNECT_TYPE_RTU  1
#define HD_MODBUS_CONNECT_TYPE_SERIAL 2

#define HD_MODBUS_SERIAL_CHECKPARITY_NONE  0   //不校验
#define HD_MODBUS_SERIAL_CHECKPARITY_ODD   1   //奇校验
#define HD_MODBUS_SERIAL_CHECKPARITY_EVEN  2   //偶校验

//REST注册点的域值 VTQ
#define HD_REST_REG_TAG_FIELD_VALUE 0
#define HD_REST_REG_TAG_FIELD_TIMESTAMP 1
#define HD_REST_REG_TAG_FIELD_QUALITY 2

#endif //#ifndef RD_CONST_H_FILE

