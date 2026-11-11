#!/usr/bin/env python
# -*- coding: utf-8 -*-

from ctypes import *
from ihdSDK import record
from ihdSDK import hyperdb
import sys
from datetime import datetime
import time

## Properties for a special BaseTag
class COMMTag(object):
    def __init__(self):
        self.tagname = ''         #name
        self.archiving = ''       #state of archive      
        self.changedate = ''      #the time of the Tag be modified
        self.changer = ''         #the people who modified the tag  //
        
        self.compdev = ''         #the deviate of compress
        self.compmaxtime = ''     #the time of producing record over 'compmax'will be archived
        self.comptype = ''        #the type of compress

        self.creationdate = ''    #the date of tag be created
        self.creator = ''         #the tag creator
        
        self.recaccess = ''       #the right of accessing record
        self.recnormalgroup = ''  #the group of accessing record
        self.recownergroup = ''   #the owner of record
                
        self.descriptor = ''      #the descriptor of tag 
        self.digitalset = ''      #digital set
        self.engunit = ''         #engine unit
        self.excmaxtime = ''      #upper limit of alarm
        self.excdev = ''          #lower limit of alarm
        
        self.tagid = ''           #tag id
        self.tagtype = ''         #the type of tag
        self.tagaccess = ''        #the right of accessing tag
        self.tagnormalgroup = '' #tag group
        self.tagownergroup = ''  #the group which tag belong to 
        
        self.scan = ''            #the state of scan
        self.span = ''            #the scope of the record                                          
        self.minvalue = ''        #minimize of the record
        self.tagclass = ''        #a sign used to indicate tag type
        self.tagavaliable = ''    #�Ƿ����
        self.opcstate = ''      #�Ƿ񷢲�
        
        self.imvstring = ''
        self.extstring1 = ''
        self.extstring2 = ''
        
        self.param1 = ''          #keep parameter 1
        self.param2 = ''          #keep parameter 2
        self.param3 = ''          #keep parameter 3
        self.param4 = ''          #keep parameter 4
        self.param5= ''           #keep parameter 5

## The Tag object represents a tag on a Server.
# @note: The Tag is the primary access point to data on the Server 
class Tag(COMMTag):
    def __init__(self):
        COMMTag.__init__(self)
        #the name of instrument point 
        self.instrumentaddress = ''      #the name of instrument point 
        #the type of instrument point
        self.instrumentaddresstype = '' #the type of instrument point
        
        self.collectorname = ''   #name of collector
        self.collectorid = ''      #id of collector
        self.devicename = ''      #name of device
        self.deviceid = ''          #id of device
        self.scangroupname = ''      #name of scangroup
        self.scangroupid = ''      #id of scangroup
        self.dataorder = ''        #
        
    
    def delete_record(self, createtime): 
        hdtime = hyperdb.HD3Time()
        if True == isinstance(createtime, datetime):       
            hdtime.nSec = c_int32(int(time.mktime(createtime.timetuple())))
            hdtime.nMsec = c_int16(int(createtime.microsecond/1000))
        elif True == isinstance(createtime, hyperdb.HD3Time):
            hdtime.nSec = createtime.nSec
            hdtime.nMsec = createtime.nMsec
        else:
            raise ArgumentError
        
        hdTagID = c_uint32(self.tagid)
        hyperdb.api.ar3_delete_record.argytypes = [c_uint32, POINTER(hyperdb.HD3Time)]        
        retcode = hyperdb.api.ar3_delete_record(hdTagID , byref(hdtime))
        if hyperdb.hd_sucess != retcode:
            raise hyperdb.HDError(retcode)
        return hyperdb.hd_sucess
     
    ## Get raw records's iterate from a server according to the query time scope
    # @param starttime: the start time of querying(datetime or HDTime type)
    # @param endtime: the end time of querying(datetime or HDTime type)
    # @return: a iterate of records    
    def get_rawRecords_Iterate_ByTimeScope(self, starttime, endtime):       
        starttime_buf = hyperdb.HD3Time()
        endtime_buf = hyperdb.HD3Time()
        
        if True == isinstance(starttime, datetime):       
            starttime_buf.nSec = c_int32(int(time.mktime(starttime.timetuple())))
            starttime_buf.nMsec = c_int16(int(starttime.microsecond/1000))
        elif True == isinstance(starttime, hyperdb.HD3Time):
            starttime_buf.nSec = starttime.nSec
            starttime_buf.nMsec = starttime.nMsec
        else:
            raise ArgumentError

        if True == isinstance(endtime, datetime):       
            endtime_buf.nSec = c_int32(int(time.mktime(endtime.timetuple())))
            endtime_buf.nMsec = c_int16(int(endtime.microsecond/1000))
        elif True == isinstance(endtime, hyperdb.HD3Time):
            endtime_buf.nSec = endtime.nSec
            endtime_buf.nMsec = endtime.nMsec
        else:
            raise ArgumentError

        timescope = hyperdb.querytime(starttime_buf, endtime_buf)
        iterate = hyperdb.RecordIterate(self.tagid, self.tagtype,timescope)
        return iterate

    ## Get raw records from a server according to the time , specify number(<=65535), orientation
    # @param timestamp: the start time of querying(datetime or HDTime type)
    # @param bLessThanQueryTime: true, the queried record's timestamp is less than the specified query timestamp;
    #                            false,the queried record's timestamp is larger than the specified query timestamp;
    # @return: a tuple of (count,records)   
    def get_rawRecords_BySpecifyNum(self, timestamp, nQueryNum, bLessThanQueryTime):
        querytime = hyperdb.HD3Time()
        if True == isinstance(timestamp, datetime):       
            querytime.nSec = c_int32(int(time.mktime(timestamp.timetuple())))
            querytime.nMsec = c_int16(int(timestamp.microsecond/1000))
        elif True == isinstance(timestamp, hyperdb.HD3Time):
            querytime.nSec = timestamp.nSec
            querytime.nMsec = timestamp.nMsec
        else:
            raise hyperdb.HDParaError('error time type')
        
        if (nQueryNum <= 0 or nQueryNum > hyperdb.maxnum_query_records):
            raise hyperdb.HDParaError('the querid count of records beyond the allowed scope')
        
        hdRecords = (nQueryNum * hyperdb.HD3Record)()

        # construct hdrecord according to tag type
        for index in range(nQueryNum):
            hdrecord_buf = hyperdb.HD3Record()
            hdrecord_buf.nTagType = hyperdb.tag_type_dict[self.tagtype]
            if(self.tagtype == 'string' or self.tagtype == 'blob'):
                temp_buf = create_string_buffer(1000)
                hdrecord_buf.value.strBlob.pBuf = temp_buf.raw
                hdrecord_buf.value.strBlob.nLenBuf = 1000
            hdRecords[index] = hdrecord_buf
        hdQuerNum = c_int32(nQueryNum)
        
        hyperdb.api.ar3_query_specify_num_raw_recs.argytypes = [c_uint32, POINTER(hyperdb.HD3Time), POINTER(c_int32), c_void_p, POINTER(hyperdb.HD3Record)]
        retCode = hyperdb.api.ar3_query_specify_num_raw_recs(c_uint32(self.tagid), byref(querytime), bLessThanQueryTime, byref(hdQuerNum), hdRecords)
        if hyperdb.hd_sucess != retCode:
            raise hyperdb.HDError(retCode)  

        rtnRecList = []
        for i in range(hdQuerNum.value):
            result_record = hyperdb.HD3RecordToPyRecord(hdRecords[i])
            rtnRecList.append(result_record)                    
        return (hdQuerNum.value,rtnRecList)    
    
    ## Get one intervene record from a server by mode
    # @param mode: set mode of query interp record: LINEAR or PREV
    # @return:  a instance of the record
    # @version: 2012/10/30 Xu Minzhi 
    def get_inter_record_by_mode(self, mode, timestamp):
        record_buf = hyperdb.HD3Record()
        if True == isinstance(timestamp, datetime):       
            record_buf.nSec = c_int32(int(time.mktime(timestamp.timetuple())))
            record_buf.nMsec = c_int16(int(timestamp.microsecond/1000))
        elif True == isinstance(timestamp, hyperdb.HD3Time):
            record_buf.nSec = timestamp.nSec
            record_buf.nMsec = timestamp.nMsec
        else:
            raise ArgumentError
        if(self.tagtype == 'string' or self.tagtype == 'blob'):
            temp_buf = create_string_buffer(1000)
            record_buf.value.strBlob.pBuf = temp_buf.raw
            record_buf.value.strBlob.nLenBuf = 1000
            
        hyperdb.api.ar3_query_interp_record_by_mode.argytypes = [c_uint8, c_uint32, POINTER(hyperdb.HD3Record)]
        retcode = hyperdb.api.ar3_query_interp_record_by_mode(c_int8(mode), c_uint32(self.tagid), byref(record_buf))
        if (hyperdb.hd_sucess != retcode):
            raise hyperdb.HDError(retcode)
        
        result_record = hyperdb.HD3RecordToPyRecord(record_buf)       
        return  result_record
    
    ## Get all intervene records from a server by mode
    # @param mode: set mode of query interp record: LINEAR or PREV
    # @param times: the times will produce a intervene record
    # @return: a tuple includinga totalErrcode and two lists, one is recordsList another is errorcodeList
    #          the totalErrCode can be hyperdb.hd_sucess or hyperdb.EC_HD_API_QUERY_INTERP_REC_FAILED
    # @version: 2012/10/30 Xu Minzhi 
    def get_inter_records_by_mode(self, mode, times):
        num = len(times)
        if (num <= 0 or num > hyperdb.maxnum_query_records):
            raise hyperdb.HDParaError('the querid count of records beyond the allowed scope')
        hdRecords = (num * hyperdb.HD3Record)()
        index = 0
        
        for time_buf in times:
            hdrecord_buf = hyperdb.HD3Record()
            if True == isinstance(time_buf, datetime):       
                hdrecord_buf.nSec = c_int32(int(time.mktime(time_buf.timetuple())))
                hdrecord_buf.nMsec = c_int16(time_buf.microsecond)
            elif True == isinstance(time_buf, hyperdb.HD3Time):
                hdrecord_buf.nSec = time_buf.nSec
                hdrecord_buf.nMsec = time_buf.nMsec
            else:
                raise ArgumentError
            hdrecord_buf.nTagType = hyperdb.tag_type_dict[self.tagtype]
            if(self.tagtype == 'string' or self.tagtype == 'blob'):
                temp_buf = create_string_buffer(1000)
                hdrecord_buf.value.strBlob.pBuf = temp_buf.raw
                hdrecord_buf.value.strBlob.nLenBuf = 1000
            hdRecords[index] = hdrecord_buf
            index +=1

        
        errors = (num * c_int32)() 
        number = c_int32(num)   
        
        hyperdb.api.ar3_query_interp_records_by_mode.argtypes = [c_uint8, c_uint32, c_int32, POINTER(hyperdb.HD3Record), POINTER(c_int32)]
        retCode = hyperdb.api.ar3_query_interp_records_by_mode(mode, self.tagid, number, hdRecords, errors)
        if hyperdb.hd_sucess != retCode and hyperdb.EC_HD_API_QUERY_INTERP_REC_FAILED != retCode:
            raise hyperdb.HDError(retCode) 
          
        recordsList = []
        errCodeList = []
        for record_buf in hdRecords:
            result_record = hyperdb.HD3RecordToPyRecord(record_buf)
            recordsList.append(result_record)
        for errcode in errors:
            errCodeList.append(errcode)   
        
        return (retCode, recordsList, errCodeList)
        
    
    ## Get the number of the records on a server
    # @param starttime: the start time of the first record produced
    # @param endtime: the end time of the last record produced
    # @return: the number of records
    def get_raw_records_number(self, starttime, endtime):
        starttime_buf = hyperdb.HD3Time()
        endtime_buf = hyperdb.HD3Time()
        
        if True == isinstance(starttime, datetime):       
            starttime_buf.nSec = c_int32(int(time.mktime(starttime.timetuple())))
            starttime_buf.nMsec = c_int16(int(starttime.microsecond/1000))
        elif True == isinstance(starttime, hyperdb.HD3Time):
            starttime_buf.nSec = starttime.nSec
            starttime_buf.nMsec = starttime.nMsec
        else:
            raise ArgumentError

        if True == isinstance(endtime, datetime):       
            endtime_buf.nSec = c_int32(int(time.mktime(endtime.timetuple())))
            endtime_buf.nMsec = c_int16(int(endtime.microsecond/1000))
        elif True == isinstance(endtime, hyperdb.HD3Time):
            endtime_buf.nSec = endtime.nSec
            endtime_buf.nMsec = endtime.nMsec
        else:
            raise ArgumentError
        
        timeregion = hyperdb.HD3TimeRegion()
        timeregion.left = starttime_buf
        timeregion.right = endtime_buf
        timeregion.leftclosed = False
        timeregion.rightclosed = True
        
        record_number = c_int32()
        hyperdb.api.ar3_query_raw_records_number.argtypes = [c_uint32, POINTER(hyperdb.HD3TimeRegion), c_void_p]
        retcode = hyperdb.api.ar3_query_raw_records_number(self.tagid, timeregion, byref(record_number))
        if (hyperdb.hd_sucess != retcode):
            raise hyperdb.HDError(retcode)

        return record_number.value
    
    ## modify a record on a server
    # @param new_record: the new record which will update the old one
    # @note: only 'quality' and  'value' can be modified
    def modify_record(self, new_record):
        record_buf = hyperdb.PyRecordToHD3Record(new_record)     
        hyperdb.api.ar3_modify_record.argtypes = [c_uint32, POINTER(hyperdb.HD3Record)]
        retcode = hyperdb.api.ar3_modify_record(self.tagid, byref(record_buf))
        if (hyperdb.hd_sucess != retcode):
            raise hyperdb.HDError(retcode) 
        return  hyperdb.hd_sucess   
    
    ## save the newest record to a server
    # @param snapshot: the newest record 
    def save_snapshot(self, snapshot):
        record_buf = hyperdb.PyRecordToHD3Record(snapshot)           
        hyperdb.api.sn3_save_snapshot.argtypes = [c_uint32, POINTER(hyperdb.HD3Record)]
        retcode = hyperdb.api.sn3_save_snapshot(c_uint32(self.tagid), byref(record_buf))
        if (hyperdb.hd_sucess != retcode):
            raise hyperdb.HDError(retcode) 
        return hyperdb.hd_sucess
    
    ## get the latest record on a server
    # @return: a instance of the record        
    def get_snapshot(self): 
        hdrecord_buf = hyperdb.HD3Record()
        if(self.tagtype == 'string' or self.tagtype == 'blob'):
            temp_buf = create_string_buffer(1000)
            hdrecord_buf.value.strBlob.pBuf = temp_buf.raw
            hdrecord_buf.value.strBlob.nLenBuf = 1000
        
        hyperdb.api.sn3_query_snapshot.argtypes = [c_uint32, POINTER(hyperdb.HD3Record)]
        retcode = hyperdb.api.sn3_query_snapshot(self.tagid, byref(hdrecord_buf))
        if (hyperdb.hd_sucess != retcode):
            raise hyperdb.HDError(retcode)
        
        result_record = hyperdb.HD3RecordToPyRecord(hdrecord_buf)      
        return  result_record


    
    ## add snapshots to tags
    #@param snapshots_list: list of snapshots, [(tagid, snapshot), ...],  snapshot's type  is record.Record
    # for digitalset ,Record's value should be digitalset's state id
    #@return: hyperdb.hd_sucess or hyperdb.EC_HD_API_SAVE_SNAPSHOTS_FAILED
    def save_snapshots(self, snapshots_list):
        nRecNum = len(snapshots_list)
        if (nRecNum <= 0 or nRecNum > hyperdb.maxnum_query_records):
            raise hyperdb.HDParaError('the count of tag beyond the allowed scope')
        nTagIDs = (nRecNum * c_uint32)()
        hdRecords = (nRecNum * hyperdb.HD3Record)()
        nErrCodes = (nRecNum * c_int32)()      
        count = 0
        for snapshot in snapshots_list:
            nTagIDs[count] = c_uint32(snapshot[0])
            if True == isinstance(snapshot[1], record.Record):
                hdRecords[count] = hyperdb.PyRecordToHD3Record(snapshot[1])
            else:
                raise ArgumentError
            count = count + 1
            
        hyperdb.api.sn3_save_snapshots.argtypes = [c_int32, POINTER(c_uint32), POINTER(hyperdb.HD3Record), POINTER(c_int32)]    
        retCode = hyperdb.api.sn3_save_snapshots(nRecNum, nTagIDs, hdRecords,nErrCodes)
        if hyperdb.hd_sucess != retCode and hyperdb.EC_HD_API_SAVE_SNAPSHOTS_FAILED != retCode:
            raise hyperdb.HDError(retCode)  
        return retCode
        
        
    ## get snapshots from the tags (max number is 65535)
    #@param nTagIDs: list of tagID,tagType(str type)
    # @return: a tuple including a totalErrcode and two lists, one is snapshotsList(type is record.Record) another is errorcodeList
    #          the totalErrCode can be hyperdb.hd_sucess or hyperdb.EC_HD_API_QUERY_SNAPSHOTS_FAILED
    def get_snapshots(self, nTagIDs,strTagTypes):
        nRecNum = len(nTagIDs)
        if (nRecNum !=len(strTagTypes) or nRecNum <= 0 or nRecNum > hyperdb.maxnum_query_records):
            raise hyperdb.HDParaError('the count of tag beyond the allowed scope')
        
        hdRecords = (nRecNum * hyperdb.HD3Record)()
        hdTagIDs = (nRecNum * c_uint32)()
        nErrCodes = (nRecNum * c_int32)()
        # construct hdrecord according to tag type
        for index in range(nRecNum):
            hdrecord_buf = hyperdb.HD3Record()
            hdrecord_buf.nTagType = hyperdb.tag_type_dict[strTagTypes[index]]
            if(strTagTypes[index] == 'string' or strTagTypes[index] == 'blob'):
                temp_buf = create_string_buffer(1000)
                hdrecord_buf.value.strBlob.pBuf = temp_buf.raw
                hdrecord_buf.value.strBlob.nLenBuf = 1000
            hdRecords[index] = hdrecord_buf
            hdTagIDs[index] = c_uint32(nTagIDs[index])
       
        hyperdb.api.sn3_query_snapshots.argtypes = [c_int32, POINTER(c_uint32), POINTER(hyperdb.HD3Record), POINTER(c_int32)]    
        retCode = hyperdb.api.sn3_query_snapshots(nRecNum, hdTagIDs, hdRecords, nErrCodes)
        if hyperdb.hd_sucess != retCode and hyperdb.EC_HD_API_QUERY_SNAPSHOTS_FAILED != retCode:
            raise hyperdb.HDError(retCode)  
        rtnRecList = []
        errCodeList = []
        for record_buf in hdRecords:
            result_record = hyperdb.HD3RecordToPyRecord(record_buf)
            rtnRecList.append(result_record)  
        for errcode in nErrCodes:
            errCodeList.append(errcode)                 
        return (retCode,rtnRecList,errCodeList)
    
    ## Get all interp records from a server by mode according to the tags and times(max number is 65535)
    # @param mode: set mode of query interp record: LINEAR or PREV
    # @param times: a list of the time needed to get interp record(time can be datetime,or HDTime)
    # @param nTagIDs: a list of tagID
    # @param strTagTypes: a list of tagtype(string type,such as 'int8')
    # @return: a tuple including a totalErrcode and two lists, one is recordsList(element is HDRecord type) another is errorcodeList
    #          the totalErrCode can be hyperdb.hd_sucess or hyperdb.EC_HD_API_QUERY_INTERP_REC_FAILED
    def get_inter_records_multitags_by_mode(self, mode, nTagIDs,strTagTypes,times):
        num = len(times)
        if(num != len(nTagIDs) or num != len(strTagTypes) or num <= 0 or num > hyperdb.maxnum_query_records):
            raise hyperdb.HDParaError('invalid length of array')
        records_buf = (num * hyperdb.HD3Record)()
        hdTagIDs = (num * c_uint32)()
        nErrCodes = (num * c_int32)()
        index = 0
        for time_buf in times:
            hdrecord_buf = hyperdb.HD3Record()
            if True == isinstance(time_buf, datetime):       
                hdrecord_buf.nSec = c_int32(int(time.mktime(time_buf.timetuple())))
                hdrecord_buf.nMsec = c_int16(int(time_buf.microsecond/1000))
            elif True == isinstance(time_buf, hyperdb.HD3Time):
                hdrecord_buf.nSec = time_buf.nSec
                hdrecord_buf.nMsec = time_buf.nMsec
            else:
                raise ArgumentError
            if(strTagTypes[index] == 'string' or strTagTypes[index] == 'blob'):
                temp_buf = create_string_buffer(1000)
                hdrecord_buf.value.strBlob.pBuf = temp_buf.raw
                hdrecord_buf.value.strBlob.nLenBuf = 1000
            
            hdrecord_buf.nTagType =  c_uint8(hyperdb.tag_type_dict[strTagTypes[index]])  
            records_buf[index] = hdrecord_buf
            hdTagIDs[index] = c_uint32(nTagIDs[index])
            index = index +1
        
        hdNumber = c_int32(num)
        hdMode = c_int8(mode)   
        
        hyperdb.api.ar3_query_tags_interp_records_by_mode.argtypes = [c_int8, c_int32, POINTER(c_uint32), POINTER(hyperdb.HD3Record), POINTER(c_int32)]    
        retCode = hyperdb.api.ar3_query_tags_interp_records_by_mode(hdMode, hdNumber, hdTagIDs, records_buf, nErrCodes)
        if hyperdb.hd_sucess != retCode and hyperdb.EC_HD_API_QUERY_INTERP_REC_FAILED != retCode:
            raise hyperdb.HDError(retCode)            
        recordsList = []
        errCodeList = []
        for record_buf in records_buf:
            result_record = hyperdb.HD3RecordToPyRecord(record_buf)
            recordsList.append(result_record)
        for errcode in nErrCodes:
            errCodeList.append(errcode)             
        return (retCode,recordsList, errCodeList)
        
    
    ## save disorder snapshots for one tag
    # @param snapshots: disorder records
    def save_disorder_snapshots(self, snapshots):
        nRecNum = len(snapshots)
        records_buf = (nRecNum * hyperdb.HD3Record)()
        count = 0
        for snapshot in snapshots:
            record_buf = hyperdb.PyRecordToHD3Record(snapshot)
            records_buf[count] = record_buf
            count = count + 1

        errors = (nRecNum * c_int32)() 
        
        hyperdb.api.sn3_save_disorder_snapshots.argtypes = [c_int32, c_uint32, POINTER(hyperdb.HD3Record), POINTER(c_int32)]
        retcode = hyperdb.api.sn3_save_disorder_snapshots(nRecNum, self.tagid, records_buf, errors)
        if (hyperdb.hd_sucess != retcode):
            raise hyperdb.HDError(retcode) 
        return retcode
    
class CalcTag(COMMTag):
    def __init__(self):
        COMMTag.__init__(self)
        self.nCalcMode = ''
        self.nCalcPeriod = ''
        self.szCalcExpr = ''
        self.bCalcHistory = ''
        self.nCalcStartDate = ''
        self.nCalcEndDate = ''
        self.bHaveEndTime = ''
        self.SourceTagName = ''
        
class StatsTag(COMMTag):
    def __init__(self):
        COMMTag.__init__(self)
        self.szSourceTagName=''
        self.nStatsType=''
        self.nSampleStartDate=''
        self.nSampleMode=''
        self.nSampleInterval=''
        self.nSampleBeginOffset=''
        self.nSampleEndOffset=''
        self.nSampleMonthBeginDay=''
        self.nSampleMonthEndDay=''
        self.bBeginTimeStamp=''
        self.nTimeStampOffset=''
        self.nScanPeriod=''
        self.fPctGood=''
        self.szFilterExpr=''
        self.nDropBadMode=''
        self.dCountParam1=''
        self.dCountParam2=''
        self.nSampleType=''
        self.nInterpOffset=''
        self.nInterpPeriod=''
        self.nConversionType=''
        self.dConversion=''
        self.nFilterFailMode=''
        self.nCalcPeriod=''
        self.bReset=''
        self.bUseBadValue=''
        
class AlarmTag(COMMTag):
    def __init__(self):
        COMMTag.__init__(self) 
        self.test1 = ''
        self.test2 = ''
        self.test3 = ''
        self.test4 = ''
        self.action1 = ''
        self.action2 = ''       
        self.action3 = ''
        self.action4 = ''    
        self.sourcetag = ''
        self.alarmgroupid = ''
        self.autoack = ''
        self.timedeadband = ''
        self.valuedeadband = ''
        
    def acknowledge_alarm_record(self, time):
        id = c_uint32(self.tagid)
        nAckNum = 1
        errors = nAckNum * c_int32
        hyperdb.api.am3_acknowledge_alarms.argtypes = [c_int32, POINTER(c_uint32), POINTER(hyperdb.HD3Time), POINTER(c_int32)]
        retcode = hyperdb.api.am3_acknowledge_alarms(c_int32(nAckNum), byref(id), byref(time), byref(errors))
        if (hyperdb.hd_sucess != retcode):
            raise hyperdb.HDError(retcode)

    def comment_alarm_record(self, time, comment):
        id = c_uint32(self.tagid)
        nCommentNum = 1
        errors = nCommentNum * c_int32
        hyperdb.api.am3_comment_alarms.argtypes = [c_int32, POINTER(c_uint32), POINTER(hyperdb.HD3Time), c_char_p, c_void_p]
        retcode = hyperdb.api.am3_comment_alarms(c_int32(nCommentNum), byref(id), byref(time), byref(comment), byref(errors))
        if (hyperdb.hd_sucess != retcode):
            raise hyperdb.HDError(retcode)
        
    def get_alarm_snapshot(self):
        hdalarm_record = hyperdb.HD3AlarmRecord()
        tag_prop_mask_all = c_longlong(0XFFFFFFFFFFFFFFFF)
        id = c_uint32(self.tagid)
        nRecNum = 1
        errors = nRecNum * c_int32()
        
        hyperdb.api.am3_query_snapshots.argtypes = [c_int32, POINTER(c_uint32), c_int64, POINTER(hyperdb.HD3AlarmRecord), POINTER(c_int32)]
        retcode = hyperdb.api.am3_query_snapshots(c_int32(nRecNum), byref(id), tag_prop_mask_all, byref(hdalarm_record), byref(errors))
        if (hyperdb.hd_sucess != retcode):
            raise hyperdb.HDError(retcode)
        
        record_buf = record.AlarmRecord()
        record_buf.tagid = hdalarm_record.nAlarmTagID
        record_buf.startsec = hdalarm_record.tvStartTime.nSec
        record_buf.startmsec = hdalarm_record.tvStartTime.nMsec
        record_buf.endsec = hdalarm_record.tvEndTime.nSec
        record_buf.endmsec = hdalarm_record.tvEndTime.nMsec
        record_buf.acktime = hdalarm_record.tvAckTime.nSec        
        record_buf.commenttime = hdalarm_record.tvCommentTime.nSec 
        record_buf.acked = hdalarm_record.nAcked
        record_buf.restored = hdalarm_record.nRestored
        record_buf.commented = hdalarm_record.nCommented  
        record_buf.priority = hdalarm_record.nPriority
        record_buf.acktype = hdalarm_record.nAckType
        record_buf.alarmtype = hdalarm_record.nAlarmType
        record_buf.srcvalue = hdalarm_record.szSrcValue
        record_buf.test = hdalarm_record.szTest
        record_buf.comment = hdalarm_record.szComment
        record_buf.acker = hdalarm_record.szAcker
        record_buf.commentor = hdalarm_record.szCommentor
        return  record_buf
    
        
        

           
        
