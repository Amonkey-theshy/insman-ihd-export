/**
*  @file		    hd3Struct.h
*  @brief		hd3 struct
*  @author:    hd3 tream
*  @date		   03/02/2015
*  @version     initialize version
*  Copyright:   Shanghai Baosight Software Co., Ltd.
*/
#ifndef HD3_INCLUDE_GUARD_HD3STRUCT_H
#define HD3_INCLUDE_GUARD_HD3STRUCT_H

#include "data_types.h"
#include "hd3Enum.h"
#include "hd3MaskDefine.h"

#ifndef HD3_DEFINE_GUARD_HD3HANDLE
#define HD3_DEFINE_GUARD_HD3HANDLE
typedef void* HD3HANDLE;
#endif

// HD3_SOCKET 定义
#ifndef WIN32
#    ifndef SOCKET
#    define SOCKET int
#    endif
#else 
#    ifndef SOCKET
#        if defined(_WIN64)
             typedef __int64 INT_PTR, *PINT_PTR;
             typedef unsigned __int64 UINT_PTR, *PUINT_PTR;
#       else
             typedef _W64 int INT_PTR, *PINT_PTR;
             typedef _W64 unsigned int UINT_PTR, *PUINT_PTR;
#       endif
     typedef UINT_PTR        SOCKET;
#   endif
#endif

// epsilon of compare double with 0
#define HD3_EPSILON (double)0.00001

// 所有Tag点共有属性
#define HD3_COMM_TAG_PROP										\
	char	szTagName[HD3_LEN_TAG_NAME * HD3_BASE];					\
	bool	bArchiving;											\
	uint32	nChangeDate;										\
	char	szChanger[HD3_LEN_USER_NAME * HD3_BASE];					\
	float	fCompDev;											\
	int32	nCompMaxTime;										\
	enum HD3_COMP_TYPE	nCompType;											\
	uint32	nCreationDate;										\
	char	szCreator[HD3_LEN_USER_NAME * HD3_BASE];					\
	uint8 nRecAccess;											\
	char	szRecNormalGroup[HD3_LEN_USER_NAME * HD3_BASE];			\
	char	szRecOwnerGroup[HD3_LEN_USER_NAME * HD3_BASE];			\
	char	szDescriptor[HD3_LEN_TAG_DESC * HD3_BASE];				\
	char	szDigitalSet[HD3_LEN_DIGITAL_SET_NAME * HD3_BASE];		\
	char	szEngUnits[HD3_LEN_ENG_UNITS * HD3_BASE];					\
	int32	nExcMaxTime;										\
	float	fExcDev;											\
	uint32	nTagID;												\
	enum HD3_TAG_TYPE	nTagType;											\
	uint8	nTagAccess;											\
	char	szTagNormalGroup[HD3_LEN_USER_NAME * HD3_BASE];			\
	char	szTagOwnerGroup[HD3_LEN_USER_NAME * HD3_BASE];			\
	bool	bScan;												\
	float	fSpan;												\
	float	fMinValue;											\
	enum HD3_TAG_CLASS	nTagClass;                     \
	enum HD3_TAG_AVALIABLE nTagAvaliable;              \
	uint8	nParam1;											\
	uint8	nParam2;											\
	uint8	nParam3;											\
	uint8	nParam4;											\
	uint8	nParam5;                                            \
	enum HD3_TAG_OPC_STATE nOpcState;							\
	char  szIMVString[HD3_LEN_EXT_STRING * HD3_BASE];			\
	char  szExtString1[HD3_LEN_EXT_STRING * HD3_BASE];			\
	char  szExtString2[HD3_LEN_EXT_STRING * HD3_BASE]

// 普通点特有属性
#define HD3_PT_TAG_EXT_PROP										\
	HD3_M char	szInstrumentAddress[HD3_LEN_INSTRUMENT_ADDRESS * HD3_BASE];	\
	uint8	nInstrumentAddressType;								\
	char	szCollectorName[HD3_LEN_COLLECTOR_NAME * HD3_BASE];		\
	int32	nCollectorID;										\
	char	szDeviceName[HD3_LEN_DEVICE_NAME * HD3_BASE];				\
	HD3_M uint32	nDeviceID;											\
	char	szScanGroupName[HD3_LEN_SCANGROUP_NAME * HD3_BASE];		\
	HD3_M uint32	nScanGroupID;                                   \
	enum HD3_DATA_ORDER nDataOrder

// 报警点特有属性
#define HD3_ALARM_TAG_EXT_PROP									\
	char szTest1[HD3_LEN_ALARM_TEST * HD3_BASE];						\
	char szTest2[HD3_LEN_ALARM_TEST * HD3_BASE];						\
	char szTest3[HD3_LEN_ALARM_TEST * HD3_BASE];						\
	char szTest4[HD3_LEN_ALARM_TEST * HD3_BASE];						\
	char szAction1[HD3_LEN_ALARM_ACTION * HD3_BASE];					\
	char szAction2[HD3_LEN_ALARM_ACTION * HD3_BASE];					\
	char szAction3[HD3_LEN_ALARM_ACTION * HD3_BASE];					\
	char szAction4[HD3_LEN_ALARM_ACTION * HD3_BASE];					\
	char szSourceTagName[HD3_LEN_TAG_NAME * HD3_BASE];				\
	uint32 nAlarmGroupID;										\
	enum HD3_AM_ACK_TYPE nAutoAck;											\
	int32 nTimeDeadBand;										\
	float fValueDeadBand

// 统计点特有属性
#define HD3_STATS_TAG_EXT_PROP								\
	char szSourceTagName[HD3_LEN_TAG_NAME * HD3_BASE];			\
	enum HD3_STATS_TYPE nStatsType;										\
	int32 nSampleStartDate;									\
	enum HD3_STATS_SAMPLE_MODE nSampleMode;										\
	HD3_M int32 nSampleInterval;									\
	int32 nSampleBeginOffset;									\
	int32 nSampleEndOffset;									\
	/*TT*/uint8 nSampleMonthBeginDay;								\
	/*TT*/uint8 nSampleMonthEndDay;								\
	bool bBeginTimeStamp;									\
	int32 nTimeStampOffset;									\
	int32 nScanPeriod;										\
	float fPctGood;											\
	char szFilterExpr[HD3_LEN_FILTER_EXPR * HD3_BASE];			\
	enum HD3_STATS_DROP_BAD_MODE nDropBadMode;									\
	double dCountParam1;									\
	double dCountParam2;                               \
	enum HD3_STATS_SAMPLE_TYPE nSampleType;										\
	int32 nInterpOffset;										\
	int32 nInterpPeriod;										\
	enum HD3_STATS_CONVERSION_TYPE nConversionType;										\
	double dConversion;										\
	enum HD3_STATS_FILTER_FAIL_MODE nFilterFailMode;		\
	int32 nCalcPeriod;										\
	bool bReset;\
	bool bUseBadValue

// 计算点特有属性
#define HD3_CALC_TAG_EXT_PROP						\
	enum HD3_CALC_MODE nCalcMode;										\
	int32 nCalcPeriod;										\
	char szCalcExpr[HD3_LEN_CALC_EXPR * HD3_BASE];                  \
	bool bCalcHistory;                                       \
	int32 nCalcStartDate;                                    \
	int32 nCalcEndDate;                                      \
	bool bHaveEndTime;						\
	char szSourceTagName[HD3_LEN_TAG_NAME * HD3_BASE]

// SPC规则
#define HD3_SPC_RULE \
	char szUCLTagName[HD3_LEN_TAG_NAME * HD3_BASE];\
	char szCLTagName[HD3_LEN_TAG_NAME* HD3_BASE];\
	char szLCLTagName[HD3_LEN_TAG_NAME* HD3_BASE];\
	char szUSLTagName[HD3_LEN_TAG_NAME* HD3_BASE];\
	char szLSLTagName[HD3_LEN_TAG_NAME* HD3_BASE];\
	char szResetTagName[HD3_LEN_TAG_NAME* HD3_BASE];\
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

// SPC点特有属性
#define HD3_SPC_TAG_EXT_PROP									\
	char szSourceTagName[HD3_LEN_TAG_NAME * HD3_BASE];				\
	uint32 nAlarmGroupID;										\
	enum HD3_SPC_CTRL_CHART_TYPE nCtrlChartType;											\
	enum HD3_SPC_TRIGGER_MODE	nTriggerMode;											\
	int32 nSampleSize;											\
	int32 nSampleInterval;											\
	bool bAutoAck;											\
	HD3_SPC_RULE

/* Tag点属性结构 */
HD3_M;
typedef struct {
	HD3_COMM_TAG_PROP;
}HD3CommTagProp;

// 普通点
HD3_M;
typedef struct {
	HD3_COMM_TAG_PROP;
	HD3_PT_TAG_EXT_PROP;
}HD3PtTagProp;


//云同步点
typedef struct {
	char	szTagName[HD3_LEN_TAG_NAME * HD3_BASE];
	uint32  sync;
	uint32	period;
	float	comp_dev;
	uint32  changeversion;
}HD3CloudTagProp;

//大数据同步点
typedef struct {
	char	szTagName[HD3_LEN_TAG_NAME * HD3_BASE];
	uint32  sync;
	uint32	period;
	float	comp_dev;
	uint32  changeversion;
	uint32 synchroTime;
	uint32 integerNumber;
	uint32 effectiveNumber;
	float coefficient;
	uint32 collectInterval;
	uint32 sendFrequency;
	char    szSendMode[HD3_LEN_TAG_NAME * HD3_BASE];
	char    szEquipment[HD3_LEN_TAG_NAME * HD3_BASE];
	char	szCloudEnName[HD3_LEN_TAG_NAME * HD3_BASE];
	char	szCloudChName[HD3_LEN_TAG_NAME * HD3_BASE];
	char	szReferenceEnName[HD3_LEN_TAG_NAME * HD3_BASE];
	char	szReferenceChName[HD3_LEN_TAG_NAME * HD3_BASE];
	char	szReferenceSourceIdentifier[HD3_LEN_TAG_NAME * HD3_BASE];
	char    szUnitNumber[HD3_LEN_TAG_NAME];
	char	szFactory[HD3_LEN_TAG_NAME * HD3_BASE];
	char	szArea[HD3_LEN_TAG_NAME * HD3_BASE];
}HD3BigDataTagProp;

// 报警点
typedef struct {
	HD3_COMM_TAG_PROP;
	HD3_ALARM_TAG_EXT_PROP;
}HD3AlarmTagProp;

// SPC点
typedef struct {
	HD3_COMM_TAG_PROP;
	HD3_SPC_TAG_EXT_PROP;
}HD3SpcTagProp;

// 统计点
typedef struct {
	HD3_COMM_TAG_PROP;
	HD3_STATS_TAG_EXT_PROP;
}HD3StatsTagProp;

// 计算点
typedef struct {
	HD3_COMM_TAG_PROP;
	HD3_CALC_TAG_EXT_PROP;
}HD3CalcTagProp;

// 许可证信息
typedef struct {
	enum HD3_LICENSE nLicense;
	int32 nValidSec;
	uint32 nClientNum;	
}HD3LicenseInfo;

/** 时间从1970年1月0日00:00:01到2038年1月19日3:14:06 */
typedef struct {
	int32 month;				/**< 1-12 */
	int32 year;					/**< four digit */
	int32 day;					/**< 1-31 */ 
	int32 hour;					/**< 0-23 */ 
	int32 minute;				/**< 0-59 */ 
	int32 second;				/**< 0-59*/ 
	int32 mSecond;				/**< 0-999*/
	int32 timezone;				/**< -12~12*/
}HD3TimeStamp;

// 时间
typedef struct {
	int32 nSec;
	int16 nMsec;
}HD3Time;

// 时间区间
typedef struct {
	HD3Time left;		// 左区间
	HD3Time right;		// 右区间
	bool bLeftClosed;	// 左区间开或是闭
	bool bRightClosed;  // 右区间开或是闭
}HD3TimeRegion;

// //单一客户端连接信息
// typedef struct {
// 	HD3_M uint32 nClientIP;
// 	char szMac[32];
// 	int32 nSocketNum;
// 	HD3_SOCKET nSocket[HD3_CLIENT_SOCKET_MAX];
// }HD3ClientConnInfo;
// 
// typedef struct {
// 	HD3_SOCKET nSocket;
// 	int32 nConnectTime;
// 	int32 nPackageRecvNum;
// 	int32 nPackageRecvTime;
// 	char szUserName[HD3_LEN_USER_NAME * HD3_BASE];
// }HD3SocketNetInfo;

// 数据
typedef struct {
	int32 nSec;
	int16 nMsec;
	uint16 nQuality;
	enum HD3_TAG_TYPE nTagType;
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
}HD3Record;

// 查询条件（Tag点查询，数据查询，报警记录查询，SPC记录查询）
typedef struct {
	int32 nItemID;
	enum HD3_RELATION nRelation;
	char szValue[HD3_LEN_QUERY_ITEM_VALUE * HD3_BASE];
}HD3FilterItem;

// 报警
typedef struct {
	uint32 nAlarmTagID;						/**< 报警点ID*/
	HD3Time tvStartTime;						/**< 报警开始时间*/
	HD3Time tvEndTime;						/**< 报警终止时间*/
	HD3Time tvAckTime;						/**< 报警确认时间*/
	HD3Time tvCommentTime;					/**< 报警注释时间*/

	enum HD3_AM_REC_ACK_STATE nAcked;							/**< 确认状态*/
	enum HD3_AM_REC_RESTORE_STATE nRestored;						/**< 恢复状态*/
	enum HD3_AM_REC_PRIORITY nPriority;						/**< 优先级*/
	enum HD3_AM_ACK_TYPE nAckType;							/**< 报警确认类型*/
	enum HD3_AM_REC_TYPE nAlarmType;						/**< 报警类型*/

	char szSrcValue[HD3_LEN_VAR_TYPE_VALUE * HD3_BASE];	/**< 源值*/
	char szTest[HD3_LEN_ALARM_TEST * HD3_BASE];			/**< 违反规则*/
	char szComment[HD3_LEN_ALARM_COMMENT * HD3_BASE];	/**< 注释*/
	char szAcker[HD3_LEN_USER_NAME * HD3_BASE];			/**< 确认者*/
	char szCommentor[HD3_LEN_USER_NAME * HD3_BASE];		/**< 注释者*/
}HD3AlarmRecord;

// SPC
typedef struct {
	uint32 nSPCTagID;							/**< SPC报警点ID*/
	HD3Time tvStartTime;							/**< 报警开始时间*/
	HD3Time tvEndTime;							/**< 报警终止时间*/
	HD3Time tvAckTime;							/**< 报警确认时间*/
	HD3Time tvCommentTime;						/**< 报警注释时间*/
	enum HD3_AM_REC_ACK_STATE nAcked;								/**< 确认状态*/
	enum HD3_AM__REC_ACK_TYPE nAckType;							/**< 确认类型，手动还是自动*/
	enum HD3_AM_REC_RESTORE_STATE nRestored;							/**< 恢复状态*/
	int8 nValue;								/**< 报警值*/
	uint32 nRule1M;							/**< 判异规则1的M值*/
	uint32 nRule2M;							/**< 判异规则2的M值*/
	uint32 nRule3M;							/**< 判异规则3的M值*/
	uint32 nRule4M;							/**< 判异规则4的M值*/
	uint32 nRule5M;							/**< 判异规则5的M值*/
	uint32 nRule5N;							/**< 判异规则5的N值*/
	uint32 nRule6M;							/**< 判异规则6的M值*/
	uint32 nRule6N;							/**< 判异规则6的N值*/
	uint32 nRule7M;							/**< 判异规则7的M值*/
	uint32 nRule8M;							/**< 判异规则8的M值*/
	char szSrcValue[HD3_LEN_VAR_TYPE_VALUE * HD3_BASE];	/**< 源值*/
	char szComment[HD3_LEN_ALARM_COMMENT * HD3_BASE];	/**< 注释*/
	char szAcker[HD3_LEN_USER_NAME * HD3_BASE];			/**< 确认者*/
	char szCommentor[HD3_LEN_USER_NAME * HD3_BASE];		/**< 注释者*/
}HD3SpcRecord;

// iHyperDB 报警组
typedef struct {
	char szName[HD3_LEN_ALARM_GROUP_NAME * HD3_BASE];	/**< 报警组的名字 */
	char szDesc[HD3_LEN_ALARM_GROUP_DESC * HD3_BASE];	/**< 报警组的描述 */
	uint32 nGroupID;						/**< 报警组的ID */
	uint32 nParentID;						/**< 报警组的上一级组名，第一级组的组名为空即 "" */
}HD3AlarmGroup;

// iHyperDB 历史报警查询条件
typedef struct {
	HD3Time tvStart;
	HD3Time tvEnd;
	int64 nAckMask;  // HD3AmAckStateMask
	int64 nTypeMask;  // HD3AmTypeMask
	int64 nPriorMask;  // HD3AmPriorityMask
	int64 nRestoreMask;  // HD3AmRestoreStateMask
}HD3AlarmQuery;

// iHyperDB SPC报警查询条件
typedef struct {
	HD3Time tvStart;
	HD3Time tvEnd;
	int64 nAckMask;  // HD3AmAckStateMask
	int64 nRestoreMask;  // HD3AmRestoreStateMask
}HD3SPCQuery;

// iHyperDB 权限管理: 用户
typedef struct {
	char szUserName[HD3_LEN_USER_NAME * HD3_BASE];
	char szPasswd[HD3_LEN_PASSWORD * HD3_BASE];
	char szUserDesc[HD3_LEN_USER_DESC * HD3_BASE];
}HD3SecUser;

// iHyperDB 权限管理: 组
typedef struct {
	char szGroupName[HD3_LEN_GROUP_NAME * HD3_BASE];
	char szGroupDesc[HD3_LEN_GROUP_DESC * HD3_BASE];
}HD3SecGroup;

// iHyperDB 权限管理: 授权项
typedef struct {
	char szName[HD3_LEN_AUTH_NAME * HD3_BASE];
	char szDesc[HD3_LEN_AUTH_DESC * HD3_BASE];
	int32 nAuth;
}HD3SecAuthItem;

// iHyperDB 权限管理: 信任
typedef struct {
	char szTrustName[HD3_LEN_TRUST_NAME * HD3_BASE];
	HD3_M char szStartIP[HD3_LEN_IP * HD3_BASE];
	HD3_M char szEndIP[HD3_LEN_IP * HD3_BASE];
	char szUserName[HD3_LEN_USER_NAME * HD3_BASE];
}HD3SecTrust;

// iHyperDB 权限管理: 安全数据库项:如Tag点、用户组等
typedef struct {
	char szOwnGroupName[HD3_LEN_GROUP_NAME * HD3_BASE];
	char szOperateGroupName[HD3_LEN_GROUP_NAME * HD3_BASE];
	int8 nSecurity;
}HD3SecItem;

// 采集器
typedef struct {
	uint32 nID;
	uint32 nStatusTagID;
	enum HD3_COLLECTOR_TYPE nType;
	char szName[HD3_LEN_COLLECTOR_NAME * HD3_BASE];
	char szDescription[HD3_LEN_COLLECTOR_DESC * HD3_BASE];
	char szExtParam[HD3_LEN_COLLECTOR_EXT_PARAM * HD3_BASE];

}HD3Collector;

// 设备
typedef struct {
	uint32 nID;							 /**<Device ID. */
	uint32 nCollectorID;				 /**<Collector ID. */
	uint16 nPort;
	int32 nTimeout;
	uint32 nStatusTagID;
	int16 nTryTime;
	bool bIsPrimary;
	char szName[HD3_LEN_DEVICE_NAME * HD3_BASE];
	char szDescription[HD3_LEN_DEVICE_DESC * HD3_BASE];
	char szAddr[HD3_LEN_DEVICE_ADDRESS * HD3_BASE];
	char szExtParam[HD3_LEN_DEVICE_EXT_PARAM * HD3_BASE];
}HD3Device;

// 扫描组
typedef struct {
	uint32 nID;							/**<Group ID. */
	char szName[HD3_LEN_SCANGROUP_NAME * HD3_BASE];
	char szDescrption[HD3_LEN_SCANGROUP_DESC * HD3_BASE];
	int32 nPeriod;
	int32 nPhase;
	enum HD3_SCAN_TYPE  nScanType;					/**<advise mode or not */
	uint32 nDeviceID;					/**<Device ID. */
	int32 nDataAddr;
	int32 nDataLen;
	char szExtParam[HD3_LEN_SCANGROUP_EXT_PARAM * HD3_BASE];
}HD3ScanGroup;

// 许可证信息项
typedef struct {
	uint32 nTagNumber;		//nMaxTagNum
	uint32 nClientNumber;	//nMaxConNum
	char szVCODE[HD3_LEN_LICENSE_OEM_VCODE * HD3_BASE];
	uint8 nSupportSPC;
	uint8 nSupportZT;
	char szTempAlian[2];	//4字节倍数补齐
}HD3LicInfo;

// 数字量状态集
typedef struct {
	char szName[HD3_LEN_DIGITAL_SET_NAME * HD3_BASE];
}HD3DigitalSet;

// 数据量状态信息
typedef struct {
	uint32 nStateID;
	char szStateName[HD3_LEN_DIGITAL_SET_STATE_NAME * HD3_BASE];
	int32 nStateValue;
}HD3DsStateInfo;

// 采集器状态信息
typedef struct {
	uint16 nQuality;
	int32 nTotalTagNum;
	int32 nActiveTagNum;
}HD3CtStatusInfo;

// Tag基本信息
typedef struct {
	uint32 nTagID;
	char szTagName[HD3_LEN_TAG_NAME * HD3_BASE];
	enum HD3_TAG_TYPE nTagType;
	enum HD3_TAG_CLASS nTagClass;
} HD3TagBasicInfo;

// 统计相关参数
typedef struct {	
	enum HD3_STATS_TYPE nStatsType;			//统计类型
	int32 nTimeRegionNum;		//统计时间区间个数，最小值为1，最大值为128
	HD3TimeRegion* pTimeRegions;//统计时间区间，支持多个统计时间区间
	float fPercentGood;			//信任度(Good的数据个数百分比大于或等于该比例时认为计算出的结果是可信的)，0-100
	enum HD3_STATS_SAMPLE_TYPE nSampleType;			//采样方式
	char szFilterExpr[HD3_LEN_FILTER_EXPR * HD3_BASE];		//数据过滤表达式, 传入空字符串表示不过滤
	enum HD3_STATS_FILTER_FAIL_MODE nFilterFailMode;		//过滤表达式执行失败时对采样数据的处理，过滤还是不过滤
	double dExtParam1;			//计数和计时的参数, 值变化的参数，区间变化的第一个参数，在区间不在区间的第一个参数区间为[dExtParam1, dExtParam2]
	double dExtParam2;			//计数和计时的参数，区间变化的第二个参数，在区间不在区间的第二个参数
	int32 nOffset;				//采样模式为插值时，第一个插值点为startTime+nOffset, 单位为秒
	int32 nPeriod;				//采样模式为插值时，插值点的间隔为nPeriod, 单位为秒
	bool bUseBadValue;			//bad值是否参与统计，true表示bad值参与统计
}HD3StRelatedParam;

// 变更的报告
typedef struct {
	uint32	nChangeID;
	enum HD3_MODULE_TYPE nModuleType;
	uint32 	nModuleID;
	enum HD3_ALTERATION_ENTRY nEntry;  // nChangeCategory
	enum HD3_ALTERATION_TYPE nAlterationType;
	uint32	nSourceID;
	int32 	nVersion;
}HD3AlterationReport;  //HDChangeHis

// Tag点掩码
typedef struct {
	int64 nCommMask;  // 公共属性的掩码
	int64 nExtMask;
}HD3Mask;

// 查询过滤项数组
typedef struct {
	int32 nSize;
	HD3FilterItem* pItem;  // array
}HD3FilterItemSet;

// 查询指定页Tag点的参数
typedef struct {
	HD3FilterItemSet itemSet;
	HD3Mask mask;
	uint32 nStartID;
	int32 nCapacity;
}HD3PageQueryTagParam;

// iHyperDB节点信息（配置节点、数据节点）
typedef struct {
	uint32 nID;
	char szName[HD3_LEN_NODE_NAME * HD3_BASE];
	char szDesc[HD3_LEN_NODE_DESC * HD3_BASE];
	char szAddress[HD3_LEN_ADDRESS * HD3_BASE];
	char szMachineName[HD3_LEN_ADDRESS * HD3_BASE];
	uint16 nPort;
	char szBakAddress[HD3_LEN_ADDRESS * HD3_BASE];
	char szBakMachineName[HD3_LEN_ADDRESS * HD3_BASE];
	uint16 nBakPort;
	int32 nTagCapacity;
}HD3DataNode;

// 统计通用参数
typedef struct {
	HD3TimeRegion timeRegion;
	float fPercentGood;
}HD3StFuncComm;

// API连接参数
typedef struct {
	char szAddress[HD3_LEN_ADDRESS * HD3_BASE];
	uint16 nPort;
	char szBakAddress[HD3_LEN_ADDRESS * HD3_BASE];
	uint16 nBakPort;
	int32 nTimeout;
}HD3Connection;

// 客户端连接信息
typedef struct {
	uint32 nClientIp;
	char szMac[32];
	int32 nSocketNum;
	SOCKET nSocket[HD3_API_CLIENT_MAX_SOCKET_NUM];
}HD3ClientConnInfo;

// 网络SOCKET信息
typedef struct {
	SOCKET nSocket;
	int32 nConnectTime;
	int32 nPackageRecvNum;
	int32 nPackageRecvTime;
	char szUserName[HD3_LEN_USER_NAME * HD3_BASE];
}HD3SocketNetInfo;

// 节点配置信息
typedef struct {
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
	int64 nMachineTimeMs;
	char szHDVersion[HD3_LEN_HD_VERSION * HD3_BASE];
}HD3DataNodeCfg;

// 节点冗余状态
typedef struct {
	char szHostIP[HD3_LEN_ADDRESS* HD3_BASE];			//主机IP
	char szBackIP[HD3_LEN_ADDRESS* HD3_BASE];			//备机IP
	enum HD3_RY_STATUS nHostStatus;							//主机状态
	enum HD3_RY_STATUS nBackupStatus;							//备机状态
}HD3DataNodeStatus;

typedef struct {
	uint32 nID;					//ack id
	uint32 nAlarmTagID;				// alarm tag id
	uint32 nServerID;				//serverid
	uint32 nOrginalTagID;			//alarm tag orginal tag id
	HD3Time alarmTime;				//alarm time
	HD3Time ackTime;				//ack time
	uint32 nAckerID;				//acker id
	char szAcker[HD3_LEN_USER_NAME * HD3_BASE];				//acker
}HD3Ack;

typedef struct {
	uint32 nID;					//comment id
	uint32 nAlarmTagID;				// alarm tag id
	uint32 nServerID;				//serverid
	uint32 nOrginalTagID;			//alarm tag orginal tag id
	HD3Time alarmTime;				//alarm time
	HD3Time commentTime;				//comment time
	uint32 nCommentorID;				//commentor id
	char szCommentor[HD3_LEN_USER_NAME * HD3_BASE];				//commentor
	char szComment[HD3_LEN_ALARM_COMMENT * HD3_BASE];		//comment
}HD3Comment;

// 配置节点冗余状态
typedef struct {
	char szHostIP[HD3_LEN_ADDRESS* HD3_BASE];			//主机IP
	char szBackIP[HD3_LEN_ADDRESS* HD3_BASE];			//备机IP
	enum HD3_RY_STATUS nHostStatus;							//主机状态
	enum HD3_RY_STATUS nBackupStatus;							//备机状态
}HD3ConfigCenterStatus;



#endif
