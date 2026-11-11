#!/usr/bin/env python
# -*- coding: utf-8 -*-

from ctypes import *
from datetime import datetime, timedelta
import os
import sys

from ihdSDK.hdUser import User
from ihdSDK import group
from ihdSDK import record
import time
from ihdSDK import security
from ihdSDK import tag
from ihdSDK import alarmgroup
from ihdSDK import collectormgr


##global variances 
api = ''
_dll_dir_handle = None
hd_sucess = 0
query_end_code = 119626
maxnum_query_records = 65535
EC_HD_API_SAVE_SNAPSHOTS_FAILED = 119609
EC_HD_API_QUERY_SNAPSHOTS_FAILED = 119610
EC_HD_API_QUERY_INTERP_REC_FAILED = 119611


## a class inherited from Exception,which is used to raising errors api return
class HDError(Exception):
    def __init__(self, errcode, errinfo = ''):
        Exception.__init__(self, errcode, errinfo)
        self.errcode = errcode
        self.errinfo = errinfo
        
class HDParaError(Exception):
    def __init__(self, errcode = 0, errinfo = ''):
        Exception.__init__(self, errcode, errinfo)
        self.errcode = errcode
        self.errinfo = errinfo

## ���Ӳ���
class HD3Connection(Structure):
    _fields_ = [
        ('szAddress',    c_char*(256*2)),
        ('nPort',        c_uint16),
        ('szBakAddress', c_char*(256*2)),
        ('nBakPort',     c_uint16),
        ('nTimeout',     c_int32),
    ]

## a class for query records by conditions  (QueryTagPropItem->HD3FilterItem)
class HD3FilterItem(Structure):
    _fields_ = [('nPropItemID', c_int32),
                ('nRelation', c_int32),
                ('szValue', c_char*(128*2))
                ]

class HD3FilterItemSet(Structure):
    _fields_ = [('nSize', c_int32),
                ('pItem', POINTER(HD3FilterItem))
                ]

## a class saved record information
class HD3Record(Structure):    
    class _Value(Structure):
        class _StrBlob(Structure):
            _fields_ = [
                ("pBuf",        c_char_p),
                ("nLenBuf",     c_uint16)
            ]
        _fields_ = [
            ("nInt8",       c_int8),
            ("nInt16",      c_int16),
            ("nInt32",      c_int32),
            ("fFloat32",    c_float),
            ('fFloat64',    c_double),
            ('nDigital',    c_int8),  
            ('strBlob',    _StrBlob),    
        ]
    _fields_ = [
        ("nSec",        c_int32),
        ("nMsec",       c_int16), 
        ("nQuality",    c_uint16), 
        ("nTagType",    c_uint8),
        ("value",       _Value)
    ]

## a dictionary for describing tag's type as digital format   
tag_type_dict = {'int8'    : 0,
                 'int16'   : 1,
                 'int32'   : 2,
                 'float32' : 3,
                 'float64' : 4,
                 'digital' : 5,
                 'string'  : 6,
                 'blob'    : 7,
                 }

## a dictionary for describing tag's type as string format
tag_type_trans_dict = {0 : 'int8',
                       1 : 'int16',
                       2 : 'int32',
                       3 : 'float32',
                       4 : 'float64',
                       5 : 'digital',
                       6 : 'string',
                       7 : 'blob',
                 }

## a class for save time    
class HD3Time(Structure):
    _fields_=[
        ('nSec',    c_int32),
        ('nMsec',   c_int16),
    ]

## ʱ������
class HD3TimeRegion(Structure):
    _fields_ = [
          ('left',          HD3Time),        #������
          ('right',         HD3Time),        #������
          ('leftclosed',    c_bool),         #�����俪���
          ('rightclosed',   c_bool),         #�����俪���
    ]

## define a user by ctypes
class HD3SecUser(Structure):
    _fields_ = [
        ('szUserName',      c_char*(32*2)),
        ('szPassword',      c_char*(64*2)),
        ('szUserDesc',      c_char*(64*2)),
    ]

## define a usergroup by ctypes
class HD3SecGroup(Structure):
    _fields_ = [
        ('szGroupName',     c_char*(32*2)),
        ('szGroupDesc',     c_char*(64*2)),
    ]

## define a trust by ctypes
class HD3SecTrust(Structure):
    _fields_ = [
        ('szTrustName',     c_char*(64*2)),
        ('szStartIp',       c_char*(16*2)),
        ('szEndIp',         c_char*(16*2)),
        ('szUserName',      c_char*(32*2)),        
    ]

## security item
class HD3SecItem(Structure):
    _fields_ = [
        ('szOwnGroupName',      c_char*(32*2)),
        ('szOperateGroupName',  c_char*(32*2)),
        ('nSecurity',           c_int8),
    ]

##a alarm record    
class HD3AlarmRecord(Structure):
    _fields_ = [
        ('nAlarmTagID',       c_uint32),
        ('tvStartTime',       HD3Time),
        ('tvEndTime',         HD3Time),
        ('tvAckTime',         HD3Time),
        ('tvCommentTime',     HD3Time),
        ('nAcked',            c_uint8),
        ('nRestored',         c_uint8),
        ('nCommented',        c_uint8),
        ('nPriority',         c_uint8),
        ('nAckType',          c_uint8),
        ('nAlarmType',        c_uint8),
        ('szSrcValue',        c_char*(1000*2)), 
        ('szTest',            c_char*(128*2)),
        ('szComment',         c_char*(256*2)),
        ('szAcker',           c_char*(32*2)),
        ('szCommentor',       c_char*(32*2)),   
    ]

##a group for describing alarm group
class HD3AlarmGroup(Structure):
    _fields_ = [
        ('szName',    c_char*(128*2)),
        ('szDesc',    c_char*(128*2)),
        ('nGroupID',  c_uint32),
        ('nParentID', c_uint32),
        ]

##a scan group for device    
class HD3ScanGroup(Structure):
    _fields_ = [
        ('nID',       c_uint32),
        ('szName',   c_char*(64*2)),
        ('nPeriod',  c_int32),
        ('nPhase',    c_int32),
        ('nScanType', c_int8),
        ('nDeviceID', c_uint32),
        ('nDataAddr', c_int32),
        ('nDataLen',  c_int32),
        ('szDescrption', c_char*(128*2)),
        ('szExtParam', c_char*(512*2)),
        ]

#device
class HD3Device(Structure):
    _fields_ = [
        ('nID',       c_uint32),
        ('nCollectorID', c_uint32),
        ('nPort',    c_int32),
        ('nTimeout', c_int32),
        ('nStatusTagID', c_uint32),
        ('nTryTime', c_int16),
        ('bIsPrimary',  c_bool),
        ('szName',   c_char*(64*2)),
        ('szDescription', c_char*(128*2)),
        ('szAddr',  c_char*(32*2)), 
        ('szExtParam', c_char*(512*2)),
        ]

#collector
class HD3Collector(Structure):
    _fields_ = [
        ('nID',       c_uint32),
        ('nStatusTagID', c_uint32),
        ('nType',  c_int8),
        ('szName',   c_char*(64*2)),        
        ('szDescription', c_char*(128*2)),
        ('szExtParam', c_char*(512*2)),
        ]    

#digital set (HDDigitalSetState->HD3DsStateInfo)
class HD3DsStateInfo(Structure):
    _fields_ = [
        ('nStateID',       c_uint32),
        ('szStateName',   c_char*(32*2)),
        ('nStateValue', c_int32),
        ]    
          

## a class be used to describe tag properties
class TagProp(Structure):                      
    _fields_= [('szTagName',     c_char*(128*2)),     
              ('bArchiving',    c_bool),  
                     
              ('nChangeDate',   c_uint32),        
              ('szChanger',     c_char*(32*2)), 
              
              ('fCompDev',      c_float),     
              ('nCompMaxTime',  c_int32), 
              ('nCompType',     c_int32),                       
           
              ('nCreationDate', c_uint32),       
              ('szCreator',     c_char*(32*2)), 
              
              ('nRecAccess',    c_uint8), 
              ('szRecNormalGroup',  c_char*(32*2)),
              ('szRecOwnerGroup',    c_char*(32*2)), 
                               
              ('szDescriptor',  c_char*(1024*2)),   
              ('szDigitalSet',  c_char*(32*2)),      
              ('szEngUnits',    c_char*(32*2)),  
              ('nExcMaxTime',   c_int32),        
              ('fExcDev',       c_float),
              
              ('nTagID',        c_uint32),           
              ('nTagType',      c_int32),  
              ('nTagAccess',    c_uint8), 
              ('szTagNormalGroup', c_char*(32*2)),
              ('szTagOwnerGroup',  c_char*(32*2)),
              
              ('bScan',            c_bool),
              ('fSpan',            c_float),
              ('fMinValue',        c_float),
              ('nTagClass',        c_int32),
              ('nTagAvaliable',    c_int32),

              ('nParam1',       c_uint8),        
              ('nParam2',       c_uint8),        
              ('nParam3',       c_uint8),        
              ('nParam4',       c_uint8),        
              ('nParam5',       c_uint8),
              ('nOpcRelease',      c_int32),
              
              ('szImvString',      c_char*(512*2)),
              ('szExtString1',      c_char*(512*2)),
              ('szExtString2',      c_char*(512*2)),
              
              ('szInstrumentAddress', c_char*(256*2)), 
              ('nInstrumentAddressType',  c_uint8),               
              ('szCollectorName',   c_char*(64*2)),
              ('nCollectorID',       c_int32),              
              ('szDeviceName',   c_char*(64*2)),
              ('nDeviceID',       c_uint32),              
              ('szScanGroupName',   c_char*(64*2)),
              ('nScanGroupID',       c_uint32),     
              ('nDataOrder',       c_int32)
            ]

class CalcTagProp(Structure):
    _fields_ = [('szTagName',     c_char*(128*2)),     
              ('bArchiving',    c_bool),  
                     
              ('nChangeDate',   c_uint32),        
              ('szChanger',     c_char*(32*2)), 
              
              ('fCompDev',      c_float),     
              ('nCompMaxTime',  c_int32), 
              ('nCompType',     c_int32),                       
           
              ('nCreationDate', c_uint32),       
              ('szCreator',     c_char*(32*2)), 
              
              ('nRecAccess',    c_uint8), 
              ('szRecNormalGroup',  c_char*(32*2)),
              ('szRecOwnerGroup',    c_char*(32*2)), 
                               
              ('szDescriptor',  c_char*(1024*2)),   
              ('szDigitalSet',  c_char*(32*2)),      
              ('szEngUnits',    c_char*(32*2)),  
              ('nExcMaxTime',   c_int32),        
              ('fExcDev',       c_float),
              
              ('nTagID',        c_uint32),           
              ('nTagType',      c_int32),  
              ('nTagAccess',    c_uint8), 
              ('szTagNormalGroup', c_char*(32*2)),
              ('szTagOwnerGroup',  c_char*(32*2)),
              
              ('bScan',            c_bool),
              ('fSpan',            c_float),
              ('fMinValue',        c_float),
              ('nTagClass',        c_int32),
              ('nTagAvaliable',    c_int32),
              
              ('nParam1',       c_uint8),        
              ('nParam2',       c_uint8),        
              ('nParam3',       c_uint8),        
              ('nParam4',       c_uint8),        
              ('nParam5',       c_uint8),
              ('nOpcRelease',   c_int32),
              
              ('szImvString',      c_char*(512*2)),
              ('szExtString1',      c_char*(512*2)),
              ('szExtString2',      c_char*(512*2)),
              
              ('nCalcMode', c_int32),
              ('nCalcPeriod',c_int32),
              ('szCalcExpr',c_char*(256*2)),
              ('bCalcHistory',c_bool),
              ('nCalcStartDate',c_int32),
              ('nCalcEndDate',c_int32),
              ('bHaveEndTime',c_bool),
              ('szSourceTagName',c_char*(128*2))
                
                ]


class StatsTagProp(Structure):
    _fields_ = [('szTagName',     c_char*(128*2)),     
              ('bArchiving',    c_bool),  
                     
              ('nChangeDate',   c_uint32),        
              ('szChanger',     c_char*(32*2)), 
              
              ('fCompDev',      c_float),     
              ('nCompMaxTime',  c_int32), 
              ('nCompType',     c_int32),                       
           
              ('nCreationDate', c_uint32),       
              ('szCreator',     c_char*(32*2)), 
              
              ('nRecAccess',    c_uint8), 
              ('szRecNormalGroup',  c_char*(32*2)),
              ('szRecOwnerGroup',    c_char*(32*2)), 
                               
              ('szDescriptor',  c_char*(1024*2)),   
              ('szDigitalSet',  c_char*(32*2)),      
              ('szEngUnits',    c_char*(32*2)),  
              ('nExcMaxTime',   c_int32),        
              ('fExcDev',       c_float),
              
              ('nTagID',        c_uint32),           
              ('nTagType',      c_int32),  
              ('nTagAccess',    c_uint8), 
              ('szTagNormalGroup', c_char*(32*2)),
              ('szTagOwnerGroup',  c_char*(32*2)),
              
              ('bScan',            c_bool),
              ('fSpan',            c_float),
              ('fMinValue',        c_float),
              ('nTagClass',        c_int32),
              ('nTagAvaliable',    c_int32),
              
              ('nParam1',       c_uint8),        
              ('nParam2',       c_uint8),        
              ('nParam3',       c_uint8),        
              ('nParam4',       c_uint8),        
              ('nParam5',       c_uint8),
              ('nOpcRelease',   c_int32),
              
              ('szImvString',      c_char*(512*2)),
              ('szExtString1',      c_char*(512*2)),
              ('szExtString2',      c_char*(512*2)),
 
              ('szSourceTagName', c_char*(128*2)),
              ('nStatsType', c_int32),
              ('nSampleStartDate',c_int32),
              ('nSampleMode',c_int32),
              ('nSampleInterval',c_int32),
              ('nSampleBeginOffset',c_int32),
              ('nSampleEndOffset',c_int32),
              ('nSampleMonthBeginDay',c_uint8),
              ('nSampleMonthEndDay',c_uint8),
              ('bBeginTimeStamp',c_bool),
              ('nTimeStampOffset',c_int32),
              ('nScanPeriod',c_int32),
              ('fPctGood',c_float),
              ('szFilterExpr',c_char*(128*2)),
              ('nDropBadMode',c_int32),
              ('dCountParam1',c_double),
              ('dCountParam2',c_double),
              ('nSampleType',c_int32),
              ('nInterpOffset',c_int32),
              ('nInterpPeriod',c_int32),
              ('nConversionType',c_int32),
              ('dConversion',c_double),
              ('nFilterFailMode',c_int32),
              ('nCalcPeriod',c_int32),
              ('bReset',c_bool),
              ('bUseBadValue',c_bool)
                ]

## a class be used to describe Alarmtag properties    
class AlarmTagProp(Structure):
    _fields_ = [('szTagName',     c_char*(128*2)),     
              ('bArchiving',    c_bool),  
                     
              ('nChangeDate',   c_uint32),        
              ('szChanger',     c_char*(32*2)), 
              
              ('fCompDev',      c_float),     
              ('nCompMaxTime',  c_int32), 
              ('nCompType',     c_int32),                       
           
              ('nCreationDate', c_uint32),       
              ('szCreator',     c_char*(32*2)), 
              
              ('nRecAccess',    c_uint8), 
              ('szRecNormalGroup',  c_char*(32*2)),
              ('szRecOwnerGroup',    c_char*(32*2)), 
                               
              ('szDescriptor',  c_char*(1024*2)),   
              ('szDigitalSet',  c_char*(32*2)),      
              ('szEngUnits',    c_char*(32*2)),  
              ('nExcMaxTime',   c_int32),        
              ('fExcDev',       c_float),
              
              ('nTagID',        c_uint32),           
              ('nTagType',      c_int32),  
              ('nTagAccess',    c_uint8), 
              ('szTagNormalGroup', c_char*(32*2)),
              ('szTagOwnerGroup',  c_char*(32*2)),
              
              ('bScan',            c_bool),
              ('fSpan',            c_float),
              ('fMinValue',        c_float),
              ('nTagClass',        c_int32),
              ('nTagAvaliable',    c_int32),
              
              ('nParam1',       c_uint8),        
              ('nParam2',       c_uint8),        
              ('nParam3',       c_uint8),        
              ('nParam4',       c_uint8),        
              ('nParam5',       c_uint8),
              ('nOpcRelease',   c_int32),
              
              ('szImvString',      c_char*(512*2)),
              ('szExtString1',      c_char*(512*2)),
              ('szExtString2',      c_char*(512*2)),
              
              
              ('szTest1',       c_char*(128*2)),
              ('szTest2',       c_char*(128*2)),
              ('szTest3',       c_char*(128*2)),
              ('szTest4',       c_char*(128*2)),  
              ('szAction1',      c_char*(128*2)), 
              ('szAction2',      c_char*(128*2)), 
              ('szAction3',      c_char*(128*2)), 
              ('szAction4',      c_char*(128*2)), 
              ('szSourceTagName',c_char*(128*2)),
              ('nAlarmGroupID',  c_uint32),
              ('nAutoAck',       c_int32),
              ('nTimeDeadBand',  c_int32),
              ('fValueDeadBand', c_float)  
              ]              
  
## a dictionary for describing the mask of comm tag properties
comm_prop_maskdict = {'tagname'      : 0,
                    'archiving'      : 1,
                    'changedate'     : 2, 
                    'changer'        : 3,   
                    'compdev'        : 4, 
                    'compmaxtime'    : 5,  
                    'comptype'       : 6, 
                    'creationdate'   : 7,      
                    'creator'        : 8,                     
                    'recaccess'      : 9,  
                    'recnormalgroup' : 10,  
                    'recownergroup'  : 11, 
                    'descriptor'     : 12,             
                    'digitalset'     : 13,           
                    'engunit'        : 14,      
                    'excmaxtime'     : 15,     
                    'excdev'         : 16,      
                    'tagid'          : 17,    
                    'tagtype'        : 18,
                    'tagaccess'      : 19,  
                    'tagnormalgroup' : 20,                       
                    'tagownergroup'  : 21,  
                    'scan'           : 22,
                    'span'           : 23,  
                    'minvalue'       : 24,
                    'tagclass'       : 25,  
                    'tagavaliable'   : 26,
                    'param1'         : 27,  
                    'param2'         : 28,  
                    'param3'         : 29,  
                    'param4'         : 30,  
                    'param5'         : 31, 
                    'opcstate'       : 32,       
                    'imvstring'      : 33,
                    'extstring1'     : 34,
                    'extstring2'     : 35,
                  }

## ��ͨ�����е�����
tag_ext_prop_maskdict = {'instrumentaddress'    : 0,
                         'instrumentaddresstype': 1,
                         'collectorname'        : 2,
                         'collectorid'          : 3,
                         'devicename'           : 4,
                         'deviceid'             : 5,
                         'scangroupname'        : 6,
                         'scangroupid'          : 7,
                         'dataorder'            : 8,
                         }

ca_ext_prop_maskdict = {'nCalcMode' :0,
                        'nCalcPeriod':1,
                        'szCalcExpr':2,
                        'bCalcHistory':3,
                        'nCalcStartDate':4,
                        'nCalcEndDate':5,
                        'bHaveEndTime':6,
                        'SourceTagName':7,
                        }


st_ext_prop_maskdict = {'SourceTagName': 0,
                        'nStatsType':1,
                        'nSampleStartDate':2,
                        'nSampleMode':3,
                        'nSampleInterval':4,
                        'nSampleBeginOffset':5,
                        'nSampleEndOffset':6,
                        'nSampleMonthBeginDay':7,
                        'nSampleMonthEndDay':8,
                        'bBeginTimeStamp':9,
                        'nTimeStampOffset':10,
                        'nScanPeriod':11,
                        'fPctGood':12,
                        'szFilterExpr':13,
                        'nDropBadMode':14,
                        'dCountParam1':15,
                        'dCountParam2':16,
                        'nSampleType':17,
                        'nInterpOffset':18,
                        'nInterpPeriod':19,
                        'nConversionType':20,
                        'dConversion':21,
                        'nFilterFailMode':22,
                        'nCalcPeriod':23,
                        'bReset':24,
                        'bUseBadValue':25
                        }

##��������������
am_ext_prop_maskdict = {'test1'         : 0,
                        'test2'         : 1,
                        'test3'         : 2,
                        'test4'         : 3,
                        'action1'       : 4,
                        'action2'       : 5,
                        'action3'       : 6,
                        'action4'       : 7,
                        'sourcetagname' : 8,
                        'alarmgroupid'  : 9,
                        'autoack'       : 10,
                        'timedeadband'  : 11,
                        'valuedeadband' : 12,
                        }

## ��ѯ����������(��δ���壩
tag_col_dict = {    'tagname'        : 0,
                    'archiving'      : 1,
                    'changedate'     : 2, 
                    'changer'        : 3,   
                    'compdev'        : 4, 
                    'compmaxtime'    : 5,  
                    'comptype'       : 6, 
                    'creationdate'   : 7,      
                    'creator'        : 8,                     
                    'recaccess'      : 9,  
                    'recnormalgroup' : 10,  
                    'recownergroup'  : 11, 
                    'descriptor'     : 12,             
                    'digitalset'     : 13,           
                    'engunit'        : 14,      
                    'excmaxtime'     : 15,     
                    'excdev'         : 16,      
                    'tagid'          : 17,    
                    'tagtype'        : 18,
                    'tagaccess'      : 19,  
                    'tagnormalgroup' : 20,                       
                    'tagownergroup'  : 21,  
                    'scan'           : 22,
                    'span'           : 23,  
                    'minvalue'       : 24,
                    'tagclass'       : 25,  
                    'tagavaliable'   : 26,
                    'param1'         : 27,  
                    'param2'         : 28,  
                    'param3'         : 29,  
                    'param4'         : 30,  
                    'param5'         : 31,  
                    'opcstate'       : 32,   
                    'imvstring'      : 33,
                    'extstring1'     : 34,
                    'extstring2'     : 35,
                    
                    'instrumentaddress'    : 100,
                    'instrumentaddresstype': 101,
                    'collectorname'        : 102,
                    'collectorid'          : 103,
                    'devicename'           : 104,
                    'deviceid'             : 105,
                    'scangroupname'        : 106,
                    'scangroupid'          : 107,
                    'dataorder'            : 108,
                    
                    'test1'         : 200,
                    'test2'         : 201,
                    'test3'         : 202,
                    'test4'         : 203,
                    'action1'       : 204,
                    'action2'       : 205,
                    'action3'       : 206,
                    'action4'       : 207,
                    'sourcetag'     : 208,
                    'alarmgroupid'  : 209,
                    'autoack'       : 230,
                    'timedeadband'  : 231,
                    'valuedeadband' : 232,
                    
                    'spc_sourcetagname' : 300,
                    'spc_alarmgroupid'  : 301,
                    'ctrlcharttype'     : 302,
                    'triggermode'       : 303,
                    'spc_samplesize'    : 304,
                    'spc_sampleinterval': 305,
                    'spc_autoack'       : 306,
                    'rule'              : 307,
                    
                    'st_sourcetagname'      : 400,
                    'statetype'             : 401,
                    'st_samplestartdate'    : 402,
                    'st_samplemode'         : 403,
                    'st_sampleinterval'     : 404,
                    'st_samplebeginoffset'  : 405,
                    'st_sampleendoffset'    : 406,
                    'st_samplemonthbeginday': 407,
                    'st_samplemonthendday'  : 408,
                    'begintimestamp'        : 409,
                    'timestampoffset'       : 410,
                    'scanperiod'            : 411,
                    'pctgood'               : 412,
                    'filterexpr'            : 413,
                    'dropbadmode'           : 414,
                    'countparam1'           : 415,
                    'countparam2'           : 416,
                    'st_sampletype'         : 417,
                    'interpoffset'          : 418,
                    'interpperiod'          : 419,
                    'convertype'            : 420,
                    'conversion'            : 421,
                    'filterfailmode'        : 422,
                    
                    'calcmode'      : 500,
                    'calcperiod'    : 501,
                    'calcexpr'      : 502,
                    'calchistory'   : 503,
                    'calcstartdate' : 504,
                    'calcenddate'   : 505,
                    'haveendtime'   : 506,
                    
                }

## a dictionary for describing the relations in conditions
relation_dict = {"="  : 0,
                 "<>" : 1,
                 ">"  : 2,
                 "<"  : 3,
                 ">=" : 4,
                 "<=" : 5,
                 "like" : 6,
                 }

#���ò�ѯʱ�����䣬Ĭ�����ұ�  
def querytime(starttime, endtime, leftclosed = False, rightclosed = True):
    timeregion = HD3TimeRegion()
    timeregion.left = starttime
    timeregion.right = endtime
    timeregion.bLeftClosed = leftclosed
    timeregion.bRightClosed = rightclosed
    return timeregion


##load api library from fixed path 
def load_library():
    global api, _dll_dir_handle
    if type(api) != str:
        return
    if getattr(sys, 'frozen', False) and hasattr(sys, '_MEIPASS'):
        sdk_root = sys._MEIPASS
    else:
        sdk_root = os.path.abspath(os.path.join(os.path.dirname(__file__), os.pardir))
    library_dir = os.environ.get('IHD_SDK_LIBRARY_DIR', os.path.join(sdk_root, 'library'))
    dll_path = os.path.join(library_dir, 'hdKingAPI.dll')
    if not os.path.exists(dll_path):
        raise FileNotFoundError("iHD SDK DLL not found: " + dll_path)
    if hasattr(os, 'add_dll_directory'):
        _dll_dir_handle = os.add_dll_directory(library_dir)
    else:
        os.environ['PATH'] = library_dir + os.pathsep + os.environ.get('PATH', '')
    api = cdll.LoadLibrary(dll_path)

       
## a iterate for querying user, usergroup, digitalset, trust and tag  
class Iterate():
    def __init__(self, cursor, object):
        self.cursor = cursor
        self.object = object    
    
    ## this function is used to get a new object which wanted to query
    #@return: a instance of the object you want to get    
    def get_next(self):
        if True == isinstance(self.object, alarmgroup.AlarmGroup):
            
            id_buf = c_uint32()
            retcode = api.ut3_get_item_step(self.cursor, byref(id_buf))
            if hd_sucess == retcode:
                error = c_int32()
                hdalarmgroup = HD3AlarmGroup() 
                hdalarmgroup.nGroupID = id_buf.value
                api.am3_query_group_props.argtypes = (c_int32, POINTER(c_uint32), POINTER(HD3AlarmGroup), POINTER(c_int32))
                retcode = api.am3_query_group_props(1, byref(id_buf), byref(hdalarmgroup), byref(error))
                if hd_sucess != retcode:
                    raise HDError(retcode)
                self.object.name = hdalarmgroup.szName
                self.object.description = hdalarmgroup.szDesc
                self.object.id = hdalarmgroup.nGroupID
                self.object.parentid = hdalarmgroup.nParentID
                
                return self.object
     
            elif retcode == query_end_code:
                api.ut3_free_iterator(self.cursor)
                return None
            else:
                api.ut3_free_iterator(self.cursor)
                raise HDError(retcode)
                      
        else:
            retcode = api.ut3_get_item_step(self.cursor, byref(self.object))
            
            if hd_sucess == retcode:
                if True == isinstance(self.object, HD3SecUser):
                    
                    name_buf = self.object.szUserName
                    userdesc_buf = self.object.szUserDesc
                    user_buf = User(name_buf, userdesc_buf)  
                    return user_buf
                
                elif True == isinstance(self.object, HD3SecGroup):
                    groupname_buf = self.object.szGroupName
                    groupdesc_buf = self.object.szGroupDesc
                    group_buf = group.UserGroup(groupname_buf, groupdesc_buf)  
                    return group_buf
                
                #elif True == isinstance(self.object, (c_char*32)):
                #    resultdigitalset = digitalset.DigitalSet(self.object.value) 
                #    return resultdigitalset
                
                elif True == isinstance(self.object, HD3SecTrust):
                    trust_name = self.object.szTrustName
                    trust_startip = self.object.szStartIp
                    trust_endip = self.object.szEndIp
                    user_name = self.object.szUserName
                    trust_buf = security.Trust(trust_name, trust_startip, trust_endip, user_name)  
                    return trust_buf
                
                elif True == isinstance(self.object, HD3ScanGroup): 
                    scangroup_buf = collectormgr.ScanGroup()

                    scangroup_buf.id = self.object.nID
                    scangroup_buf.name = self.object.szName  
                    scangroup_buf.period = self.object.nPeriod             
                    scangroup_buf.phase = self.object.nPhase
                    scangroup_buf.scantype = self.object.nScanType
                    scangroup_buf.deviceid = self.object.nDeviceID
                    scangroup_buf.dataaddr = self.object.nDataAddr
                    scangroup_buf.datalen = self.object.nDataLen
                    scangroup_buf.description = self.object.szDescrption
                    scangroup_buf.extparam = self.object.szExtParam
                                    
                    return scangroup_buf 
                            
                elif True == isinstance(self.object, HD3Device):                   
                    id = self.object.nID
                    collectorid = self.object.nCollectorID
                    port = self.object.nPort 
                    timeout = self.object.nTimeout
                    statustagid = self.object.nStatusTagID
                    trytime = self.object.nTryTime
                    isprimary = self.object.bIsPrimary
                    name = self.object.szName
                    description = self.object.szDescription
                    addr = self.object.szAddr                                       
                    extparam = self.object.szExtParam
                    device_buf = collectormgr.Device(id, collectorid, name, addr,
                                                     port, trytime, timeout, extparam, isprimary, description)  
                    return device_buf
      
                elif True == isinstance(self.object, HD3Collector):                    
                    collectorid = self.object.nID
                    collectorstatustagid = self.object.nStatusTagID
                    collectortype = self.object.nType
                    collectorname = self.object.szName
                    collectordesc = self.object.szDescription
                    collectorextparam = self.object.szExtParam
                    collector_buf = collectormgr.Collector(collectorid, collectorname, collectortype, collectordesc, collectorextparam)
                    
                    return collector_buf
                
                elif True == isinstance(self.object, TagProp):
                    tag_buf = tag.Tag()  
                    tag_buf.tagname = self.object.szTagName
                    tag_buf.archiving = self.object.bArchiving      
                    tag_buf.changedate = self.object.nChangeDate
                    tag_buf.changer = self.object.szChanger
                    
                    tag_buf.compdev = self.object.fCompDev   
                    tag_buf.compmaxtime = self.object.nCompMaxTime
                    tag_buf.comptype = self.object.nCompType          
                    tag_buf.creationdate = self.object.nCreationDate 
                    tag_buf.creator = self.object.szCreator   
                           
                    tag_buf.recaccess = self.object.nRecAccess 
                    tag_buf.recnormalgroup = self.object.szRecNormalGroup   
                    tag_buf.recownergroup = self.object.szRecOwnerGroup 
                    
                    tag_buf.descriptor = self.object.szDescriptor          
                    tag_buf.digitalset = self.object.szDigitalSet  
                    tag_buf.engunit = self.object.szEngUnits         
                    tag_buf.excmaxtime = self.object.nExcMaxTime  
                    tag_buf.excdev = self.object.fExcDev
                           
                    tag_buf.tagid = self.object.nTagID  
                    tag_buf.tagtype = self.object.nTagType 
                    tag_buf.tagaccess = self.object.nTagAccess          
                    tag_buf.tagnormalgroup = self.object.szTagNormalGroup  
                    tag_buf.tagownergroup = self.object.szTagOwnerGroup 
                             
                    tag_buf.scan = self.object.bScan
                    tag_buf.span = self.object.fSpan 
                    tag_buf.minvalue = self.object.fMinValue
                    tag_buf.tagclass = self.object.nTagClass
                    tag_buf.tagavaliable = self.object.nTagAvaliable
                    
                    tag_buf.param1 = self.object.nParam1
                    tag_buf.param2 = self.object.nParam2      
                    tag_buf.param3 = self.object.nParam3
                    tag_buf.param4 = self.object.nParam4  
                    tag_buf.param5 = self.object.nParam5
                    
                    tag_buf.imvstring = self.object.szImvString
                    tag_buf.extstring1 = self.object.szExtString1
                    tag_buf.extstring2 = self.object.szExtString2
                     
                    tag_buf.instrumentaddress = self.object.szInstrumentAddress 
                    tag_buf.instrumentaddresstype =  self.object.nInstrumentAddressType    
                    tag_buf.collectorname = self.object.szCollectorName
                    tag_buf.collectorid = self.object.nCollectorID                    
                    tag_buf.devicename = self.object.szDeviceName
                    tag_buf.deviceid = self.object.nDeviceID
                    tag_buf.scangroupname = self.object.szScanGroupName
                    tag_buf.scangroupid = self.object.nScanGroupID
                    return tag_buf
                
                elif True == isinstance(self.object, CalcTagProp):
                    tag_buf = tag.CalcTag()  
                    tag_buf.tagname = self.object.szTagName
                    tag_buf.archiving = self.object.bArchiving      
                    tag_buf.changedate = self.object.nChangeDate
                    tag_buf.changer = self.object.szChanger
                    
                    tag_buf.compdev = self.object.fCompDev   
                    tag_buf.compmaxtime = self.object.nCompMaxTime
                    tag_buf.comptype = self.object.nCompType          
                    tag_buf.creationdate = self.object.nCreationDate 
                    tag_buf.creator = self.object.szCreator   
                           
                    tag_buf.recaccess = self.object.nRecAccess 
                    tag_buf.recnormalgroup = self.object.szRecNormalGroup   
                    tag_buf.recownergroup = self.object.szRecOwnerGroup 
                    
                    tag_buf.descriptor = self.object.szDescriptor          
                    tag_buf.digitalset = self.object.szDigitalSet  
                    tag_buf.engunit = self.object.szEngUnits         
                    tag_buf.excmaxtime = self.object.nExcMaxTime  
                    tag_buf.excdev = self.object.fExcDev
                           
                    tag_buf.tagid = self.object.nTagID  
                    tag_buf.tagtype = self.object.nTagType 
                    tag_buf.tagaccess = self.object.nTagAccess          
                    tag_buf.tagnormalgroup = self.object.szTagNormalGroup  
                    tag_buf.tagownergroup = self.object.szTagOwnerGroup 
                             
                    tag_buf.scan = self.object.bScan
                    tag_buf.span = self.object.fSpan 
                    tag_buf.minvalue = self.object.fMinValue
                    tag_buf.tagclass = self.object.nTagClass
                    tag_buf.tagavaliable = self.object.nTagAvaliable
                    
                    tag_buf.param1 = self.object.nParam1
                    tag_buf.param2 = self.object.nParam2      
                    tag_buf.param3 = self.object.nParam3
                    tag_buf.param4 = self.object.nParam4  
                    tag_buf.param5 = self.object.nParam5
                    
                    tag_buf.imvstring = self.object.szImvString
                    tag_buf.extstring1 = self.object.szExtString1
                    tag_buf.extstring2 = self.object.szExtString2
                    
                    tag_buf.nCalcMode = self.object.nCalcMode
                    tag_buf.nCalcPeriod = self.object.nCalcPeriod
                    tag_buf.szCalcExpr = self.object.szCalcExpr
                    tag_buf.bCalcHistory = self.object.bCalcHistory
                    tag_buf.nCalcStartDate = self.object.nCalcStartDate
                    tag_buf.nCalcEndDate = self.object.nCalcEndDate
                    tag_buf.bHaveEndTime = self.object.bHaveEndTime
                    tag_buf.szSourceTagName = self.object.szSourceTagName
                    return tag_buf
                
                elif True == isinstance(self.object, StatsTagProp):
                    tag_buf = tag.CalcTag()  
                    tag_buf.tagname = self.object.szTagName
                    tag_buf.archiving = self.object.bArchiving      
                    tag_buf.changedate = self.object.nChangeDate
                    tag_buf.changer = self.object.szChanger
                    
                    tag_buf.compdev = self.object.fCompDev   
                    tag_buf.compmaxtime = self.object.nCompMaxTime
                    tag_buf.comptype = self.object.nCompType          
                    tag_buf.creationdate = self.object.nCreationDate 
                    tag_buf.creator = self.object.szCreator   
                           
                    tag_buf.recaccess = self.object.nRecAccess 
                    tag_buf.recnormalgroup = self.object.szRecNormalGroup   
                    tag_buf.recownergroup = self.object.szRecOwnerGroup 
                    
                    tag_buf.descriptor = self.object.szDescriptor          
                    tag_buf.digitalset = self.object.szDigitalSet  
                    tag_buf.engunit = self.object.szEngUnits         
                    tag_buf.excmaxtime = self.object.nExcMaxTime  
                    tag_buf.excdev = self.object.fExcDev
                           
                    tag_buf.tagid = self.object.nTagID  
                    tag_buf.tagtype = self.object.nTagType 
                    tag_buf.tagaccess = self.object.nTagAccess          
                    tag_buf.tagnormalgroup = self.object.szTagNormalGroup  
                    tag_buf.tagownergroup = self.object.szTagOwnerGroup 
                             
                    tag_buf.scan = self.object.bScan
                    tag_buf.span = self.object.fSpan 
                    tag_buf.minvalue = self.object.fMinValue
                    tag_buf.tagclass = self.object.nTagClass
                    tag_buf.tagavaliable = self.object.nTagAvaliable
                    
                    tag_buf.param1 = self.object.nParam1
                    tag_buf.param2 = self.object.nParam2      
                    tag_buf.param3 = self.object.nParam3
                    tag_buf.param4 = self.object.nParam4  
                    tag_buf.param5 = self.object.nParam5
                    
                    tag_buf.imvstring = self.object.szImvString
                    tag_buf.extstring1 = self.object.szExtString1
                    tag_buf.extstring2 = self.object.szExtString2
                     
                    tag_buf.szSourceTagName=self.object.szSourceTagName
                    tag_buf.nStatsType=self.object.nStatsType
                    tag_buf.nSampleStartDate=self.object.nSampleStartDate
                    tag_buf.nSampleMode=self.object.nSampleMode
                    tag_buf.nSampleInterval=self.object.nSampleInterval
                    tag_buf.nSampleBeginOffset=self.object.nSampleBeginOffset
                    tag_buf.nSampleEndOffset=self.object.nSampleEndOffset
                    tag_buf.nSampleMonthBeginDay=self.object.nSampleMonthBeginDay
                    tag_buf.nSampleMonthEndDay=self.object.nSampleMonthEndDay
                    tag_buf.bBeginTimeStamp=self.object.bBeginTimeStamp
                    tag_buf.nTimeStampOffset=self.object.nTimeStampOffset
                    tag_buf.nScanPeriod=self.object.nScanPeriod
                    tag_buf.fPctGood=self.object.fPctGood
                    tag_buf.szFilterExpr=self.object.szFilterExpr
                    tag_buf.nDropBadMode=self.object.nDropBadMode
                    tag_buf.dCountParam1=self.object.dCountParam1
                    tag_buf.dCountParam2=self.object.dCountParam2
                    tag_buf.nSampleType=self.object.nSampleType
                    tag_buf.nInterpOffset=self.object.nInterpOffset
                    tag_buf.nInterpPeriod=self.object.nInterpPeriod
                    tag_buf.nConversionType=self.object.nConversionType
                    tag_buf.dConversion=self.object.dConversion
                    tag_buf.nFilterFailMode=self.object.nFilterFailMode
                    tag_buf.nCalcPeriod=self.object.nCalcPeriod
                    tag_buf.bReset=self.object.bReset
                    tag_buf.bUseBadValue=self.object.bUseBadValue
                    return tag_buf
                
                elif True == isinstance(self.object, AlarmTagProp):
                    tag_buf = tag.AlarmTag()   
                    
                    tag_buf.tagname = self.object.szTagName
                    tag_buf.archiving = self.object.bArchiving      
                    tag_buf.changedate = self.object.nChangeDate
                    tag_buf.changer = self.object.szChanger
                    
                    tag_buf.compdev = self.object.fCompDev   
                    tag_buf.commaxtime = self.object.nCompMaxTime
                    tag_buf.comtype = self.object.nCompType          
                    tag_buf.creationdate = self.object.nCreationDate 
                    tag_buf.creator = self.object.szCreator   
                           
                    tag_buf.recaccess = self.object.nRecAccess 
                    tag_buf.recnormalgroup = self.object.szRecNormalGroup   
                    tag_buf.recownergroup = self.object.szRecOwnerGroup 
                    
                    tag_buf.descriptor = self.object.szDescriptor          
                    tag_buf.digitalset = self.object.szDigitalSet  
                    tag_buf.engunit = self.object.szEngUnits         
                    tag_buf.excmaxtime = self.object.nExcMaxTime  
                    tag_buf.excdev = self.object.fExcDev
                           
                    tag_buf.tagid = self.object.nTagID  
                    tag_buf.tagtype = self.object.nTagType 
                    tag_buf.tagaccess = self.object.nTagAccess          
                    tag_buf.tagnormalgroup = self.object.szTagNormalGroup  
                    tag_buf.tagownergroup = self.object.szTagOwnerGroup 
                             
                    tag_buf.scan = self.object.bScan
                    tag_buf.span = self.object.fSpan 
                    
                    tag_buf.minvalue = self.object.fMinValue
                    tag_buf.tagclass = self.object.nTagClass
                    tag_buf.tagavaliable = self.object.nTagAvaliable
                    
                    tag_buf.param1 = self.object.nParam1
                    tag_buf.param2 = self.object.nParam2
                    tag_buf.param3 = self.object.nParam3
                    tag_buf.param4 = self.object.nParam4
                    tag_buf.param5 = self.object.nParam5
                    
                    tag_buf.imvstring = self.object.szImvString
                    tag_buf.extstring1 = self.object.szExtString1
                    tag_buf.extstring2 = self.object.szExtString2
                    
                    tag_buf.test1 = self.object.szTest1 
                    tag_buf.test2 = self.object.szTest2         
                    tag_buf.test3 = self.object.szTest3 
                    tag_buf.test4 = self.object.szTest4  
                    
                    tag_buf.action1 = self.object.szAction1  
                    tag_buf.action2 = self.object.szAction2  
                    tag_buf.action3 = self.object.szAction3  
                    tag_buf.action4 = self.object.szAction4          
                     
                    tag_buf.sourcetagname = self.object.szSourceTagName
                    tag_buf.alarmgroupid = self.object.nAlarmGroupID      
                    tag_buf.autoack = self.object.nAutoAck
                    tag_buf.timedeadband = self.object.nTimeDeadBand
                    tag_buf.valuedeadband = self.object.fValueDeadBand
                    
                    return tag_buf
                    
                elif True == isinstance(self.object, c_uint32): #query alarm tag
                    alarmtag_buf = tag.AlarmTag()   
                    alarmtag_buf.tagid = self.object.value
                    alarmtagprop = AlarmTagProp()
                    
                    error = c_int32()
                    
                    api.am3_quey_tag_prop.argtypes = (c_uint32, POINTER(HD3AlarmGroup))
                    retcode = api.am3_quey_tag_prop(alarmtag_buf.tagid, byref(alarmtagprop))   
                    if retcode != hd_sucess:
                        raise HDError(retcode)
                    
                    alarmtag_buf.tagname = alarmtagprop.szTagName
                    alarmtag_buf.archiving = alarmtagprop.bArchiving      
                    alarmtag_buf.changedate = alarmtagprop.nChangeDate
                    alarmtag_buf.changer = alarmtagprop.szChanger
                    
                    alarmtag_buf.compdev = alarmtagprop.fCompDev   
                    alarmtag_buf.commaxtime = alarmtagprop.nCompMaxTime
                    alarmtag_buf.comtype = alarmtagprop.nCompType          
                    alarmtag_buf.creationdate = alarmtagprop.nCreationDate 
                    alarmtag_buf.creator = alarmtagprop.szCreator   
                           
                    alarmtag_buf.recaccess = alarmtagprop.nRecAccess 
                    alarmtag_buf.recnormalgroup = alarmtagprop.szRecNormalGroup   
                    alarmtag_buf.recownergroup = alarmtagprop.szRecOwnerGroup 
                    
                    alarmtag_buf.descriptor = alarmtagprop.szDescriptor          
                    alarmtag_buf.digitalset = alarmtagprop.szDigitalSet  
                    alarmtag_buf.engunit = alarmtagprop.szEngUnits         
                    alarmtag_buf.excmaxtime = alarmtagprop.nExcMaxTime  
                    alarmtag_buf.excdev = alarmtagprop.fExcDev
                           
                    alarmtag_buf.tagid = alarmtagprop.nTagID  
                    alarmtag_buf.tagtype = alarmtagprop.nTagType 
                    alarmtag_buf.tagaccess = alarmtagprop.nTagAccess          
                    alarmtag_buf.tagnormalgroup = alarmtagprop.szTagNormalGroup  
                    alarmtag_buf.tagownergroup = alarmtagprop.szTagOwnerGroup 
                             
                    alarmtag_buf.scan = alarmtagprop.bScan
                    alarmtag_buf.span = alarmtagprop.fSpan                     
                    alarmtag_buf.minvalue = alarmtagprop.fMinValue
                    alarmtag_buf.tagclass = alarmtagprop.nTagClass
                    alarmtag_buf.tagavaliable = alarmtagprop.nTagAvaliable
                    
                    alarmtag_buf.param1 = alarmtagprop.nParam1
                    alarmtag_buf.param2 = alarmtagprop.nParam2
                    alarmtag_buf.param3 = alarmtagprop.nParam3
                    alarmtag_buf.param4 = alarmtagprop.nParam4
                    alarmtag_buf.param5 = alarmtagprop.nParam5
                    
                    alarmtag_buf.imvstring = self.object.szImvString
                    alarmtag_buf.extstring1 = self.object.szExtString1
                    alarmtag_buf.extstring2 = self.object.szExtString2
                     
                    alarmtag_buf.test1 = alarmtagprop.szTest1 
                    alarmtag_buf.test2 =  alarmtagprop.szTest2         
                    alarmtag_buf.test3 = alarmtagprop.szTest3 
                    alarmtag_buf.test4 = alarmtagprop.szTest4  
                     
                    alarmtag_buf.action1 = alarmtagprop.szAction1
                    alarmtag_buf.action2 = alarmtagprop.szAction2     
                    alarmtag_buf.action3 = alarmtagprop.szAction3
                    alarmtag_buf.action4 = alarmtagprop.szAction4 
                    alarmtag_buf.sourcetagname = alarmtagprop.szSourceTagName  
                    alarmtag_buf.alarmgroupid = alarmtagprop.nAlarmGroupID 
                    alarmtag_buf.autoack = alarmtagprop.nAutoAck 
                    alarmtag_buf.timedeadband = alarmtagprop.nTimeDeadBand
                    alarmtag_buf.valuedeadband = alarmtagprop.fValueDeadBand
                    
                    return alarmtag_buf
                                         
                else:
                    pass  
                    
            elif retcode == query_end_code:
                api.ut3_free_handle(self.cursor)
                return None
            else:
                api.ut3_free_handle(self.cursor)
                raise HDError(retcode)
        

## a class inherited from Iterate, which be used to get record
## tagtype is string ,such as 'int8'
class RecordIterate(Iterate):
    def __init__(self, tagid, tagtype, querytime):  
        self.tag_id = tagid
        self.tagtype = tagtype    
        
        self.querytime = querytime
        
        self.cursor = 0
        self.records = [] 
        self.bQueryEnd = False

        
    ## get a new record by this function
    #@return:   a instance of HDRecord 
    def get_next_record(self):
        base_num = 65534     #record number's default value is 65534
        nCount = len(self.records)
        
        # ��û�в�ѯ����������в�ѯ
        if(self.cursor >= nCount and self.bQueryEnd != True):
            hdRecords = (base_num * HD3Record)()

            # construct hdrecord according to tag type
            for index in range(base_num):
                hdrecord_buf = HD3Record()
                hdrecord_buf.nTagType = tag_type_dict[self.tagtype]
                if(self.tagtype == 'string' or self.tagtype == 'blob'):
                    temp_buf = create_string_buffer(1000)
                    hdrecord_buf.value.strBlob.pBuf = temp_buf.raw
                    hdrecord_buf.value.strBlob.nLenBuf = 1000
                hdRecords[index] = hdrecord_buf
            hdQuerNum = c_int32(base_num)
            
            api.ar3_query_raw_records.argtypes = (c_uint32, POINTER(HD3TimeRegion), POINTER(c_int32), POINTER(HD3Record))
            retCode = api.ar3_query_raw_records(self.tag_id, byref(self.querytime), byref(hdQuerNum), hdRecords)
            if hd_sucess != retCode:
                raise HDError(retCode)  
           
            nCount = hdQuerNum.value
            del self.records[:]
            for i in range (nCount):
                result_record_buf = HD3RecordToPyRecord(hdRecords[i])            
                self.records.append(result_record_buf)
            if(nCount < base_num):
                self.bQueryEnd = True
            else:
                self.endtime.nSec = hdRecords[base_num-1].nSec
                self.endtime.nMsec = hdRecords[base_num-1].nMsec
                if(self.endtime.nMsec == 0):
                    self.endtime.nMsec = 999
                    self.endtime.nSec -= 1
                else:
                    self.endtime.nMsec -= 1
            self.cursor = 0
            
        if (self.cursor < nCount):
            self.cursor = self.cursor + 1
            return self.records[self.cursor-1]
        else:
            #�������ȫ������û�в�ѯ�������
            return None

## ����
class HD3Mask(Structure):
    _fields_= [
        ('commmask',     c_int64),
        ('extmask',     c_int64),
    ]


##get tag properties's comm mask code
def get_comm_mask(prop, comm_mask):
    index = comm_prop_maskdict[prop]
    if type(index) != int:
        raise TypeError
    a = c_int64(1).value << index
    comm_mask  |=  a
    return comm_mask

def get_tag_ext_mask(prop, ext_mask):
    index = tag_ext_prop_maskdict[prop]
    if type(index) != int:
        raise TypeError
    a = c_int64(1).value << index
    ext_mask  |=  a
    return ext_mask

def get_calc_ext_mask(prop, calc_ext_mask):
    index = ca_ext_prop_maskdict[prop]
    if type(index)!=int:
        raise TypeError
    a = c_int64(1).value << index
    calc_ext_mask |= a
    return calc_ext_mask

def get_stats_ext_mask(prop, stats_ext_mask):
    index = st_ext_prop_maskdict[prop]
    if type(index)!=int:
        raise TypeError
    a = c_int64(1).value << index
    stats_ext_mask |= a
    return stats_ext_mask

def get_alarm_ext_mask(prop, alarm_ext_mask):
    index = am_ext_prop_maskdict[prop]
    if type(index) != int:
        raise TypeError
    a = c_int64(1).value << index
    alarm_ext_mask  |=  a
    return alarm_ext_mask


def display_alarm_record(alarmrec):
    print('��ʼ��ӡ��¼')
    print('id:', alarmrec.tagid,'start sec:', alarmrec.startsec, 'start msec:', alarmrec.startmsec)
    print('endsec:',alarmrec.endsec, 'endmsec:', alarmrec.endmsec, 'restored:', alarmrec.restored)
    print('acked:',alarmrec.acked, 'acktime:', alarmrec.acktime, 'acker:', alarmrec.acker)
    print('commented:',alarmrec.commented, 'commenttime:', alarmrec.commenttime, 'comment:', alarmrec.comment, 'commentor:', alarmrec.commentor)
    print('priority:',alarmrec.priority, 'acktype:', alarmrec.acktype, 'alarmtype:', alarmrec.alarmtype)
    print('srcvalue:',alarmrec.srcvalue, 'test:', alarmrec.test)
    print('������ӡ��¼')
        
def receive_alarm_record(notifytype, hdalarm_record):      
    record_buf = record.AlarmRecord()
    record_buf.tagid = hdalarm_record[0].nAlarmTagID
    record_buf.startsec = hdalarm_record[0].tvStartTime.nSec
    record_buf.startmsec = hdalarm_record[0].tvStartTime.nMsec
    record_buf.endsec = hdalarm_record[0].tvEndTime.nSec
    record_buf.endmsec = hdalarm_record[0].tvEndTime.nMsec
    record_buf.acktime = hdalarm_record[0].tvAckTime.nSec
    record_buf.commenttime = hdalarm_record[0].tvCommentTime.nSec   
    record_buf.priority = hdalarm_record[0].nPriority
    record_buf.restored = hdalarm_record[0].nRestored
    record_buf.commented = hdalarm_record[0].nCommented
    record_buf.acked = hdalarm_record[0].nAcked
    record_buf.acktype = hdalarm_record[0].nAckType
    record_buf.alarmtype = hdalarm_record[0].nAlarmType
    record_buf.srcvalue = hdalarm_record[0].szSrcValue
    record_buf.acker = hdalarm_record[0].szAcker
    record_buf.comment = hdalarm_record[0].szComment
    record_buf.commentor = hdalarm_record[0].szCommentor        
        
    # print('֪ͨ����', notifytype)
    display_alarm_record(record_buf)
    return 0

def HD3RecordToPyRecord(hdrecord):
    result_record = record.Record(hdrecord.nSec, hdrecord.nMsec)
    result_record.quality = hdrecord.nQuality                
    result_record.tagtype = tag_type_trans_dict[hdrecord.nTagType]
    if result_record.tagtype == 'int8':
        result_record.value = str(hdrecord.value.nInt8) 
    elif result_record.tagtype == 'int16':
        result_record.value = str(hdrecord.value.nInt16) 
    elif result_record.tagtype == 'int32':
        result_record.value = str(hdrecord.value.nInt32) 
    elif result_record.tagtype == 'float32':
        result_record.value = str(hdrecord.value.fFloat32) 
    elif result_record.tagtype == 'float64':
        result_record.value = str(hdrecord.value.fFloat64)
    elif result_record.tagtype == 'digital':
        result_record.value = str(hdrecord.value.nDigital)
    elif result_record.tagtype == 'string':
        result_record.value = hdrecord.value.strBlob.pBuf
    elif result_record.tagtype == 'blob':
        result_record.value = hdrecord.value.strBlob.pBuf
    else:
        raise HDError(0, 'get value failed!')
    return  result_record

def PyRecordToHD3Record(record):
    record_buf = HD3Record()
    record_buf.nSec = record.sec
    record_buf.nMsec = record.msec
    record_buf.nQuality = record.quality
    record_buf.nTagType = tag_type_dict[record.tagtype]
    if record.tagtype == 'int8':
        record_buf.value.nInt8 = int(record.value)
    elif record.tagtype == 'int16':
        record_buf.value.nInt16 = int(record.value)  
    elif record.tagtype == 'int32':
        record_buf.value.nInt32 = int(record.value) 
    elif record.tagtype == 'float32':
        record_buf.value.fFloat32 = float(record.value) 
    elif record.tagtype == 'float64':
        record_buf.value.fFloat64 = float(record.value) 
    elif record.tagtype == 'digital':
        record_buf.value.nDigital = int(record.value)       
    elif record.tagtype == 'string':
        value_buf = record.value
        record_buf.value.strBlob.pBuf = value_buf
        record_buf.value.strBlob.nLenBuf = len(value_buf) + 1 
    elif record.tagtype == 'blob':
        value_buf = record.value
        record_buf.value.strBlob.pBuf = value_buf
        record_buf.value.strBlob.nLenBuf = len(value_buf) 
    else:
        raise HDError(errinfo = 'unknown record type')
    return  record_buf


# CALLBACKFUNC = CFUNCTYPE(None, c_void_p, c_uint8, POINTER(HD3AlarmRecord))
# func = CALLBACKFUNC(receive_alarm_record)
