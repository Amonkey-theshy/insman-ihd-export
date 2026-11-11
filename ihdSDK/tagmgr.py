#!/usr/bin/env python
# -*- coding: utf-8 -*-

from ctypes  import *
from ihdSDK import hyperdb
from ihdSDK import tag
import sys
from ihdSDK import record
from datetime import datetime
import time

## TagMgr is a operator class through which programmers can use to do all
# operators about tag.
# @note: Programmers needn't create a TagMgr object. Instead, TagMgr object
# can be accessed from Server class
class TagMgr(object):
    def __init__(self, server):
        self.server = server
       
    # add a new tag to server
    # @param attributes: attributes is dictionary, such as 'tagname = 'testtag', tagtype = 'int8'
    # @note: the input attributes should include 'tagname' and 'tagtype', the attributes'names can be
    # seen in tag.py
    def add_tag(self, **attributes): 
        tag_prop_buf = hyperdb.TagProp()
        if 'tagname' not in attributes or 'tagtype' not in attributes:
            raise ArgumentError
        
        comm_mask = 0
        tag_ext_mask = 0
        
        tag_prop_buf.szTagName = bytes(attributes['tagname'], encoding='gbk')  
        if not tag_prop_buf.szTagName.strip():
            raise ArgumentError
        comm_mask = hyperdb.get_comm_mask('tagname', comm_mask)
        
        try:
            tag_prop_buf.nTagType = hyperdb.tag_type_dict[attributes['tagtype']]
        except:
            raise ArgumentError
        comm_mask = hyperdb.get_comm_mask('tagtype', comm_mask)
        
        if 'archiving' in attributes:
            tag_prop_buf.bArchiving = attributes['archiving'] 
            comm_mask = hyperdb.get_comm_mask('archiving', comm_mask)

        if 'compdev' in attributes:
            tag_prop_buf.fCompDev = attributes['compdev']
            comm_mask = hyperdb.get_comm_mask('compdev', comm_mask)
        if 'compmaxtime' in attributes:
            tag_prop_buf.nCompMaxTime = attributes['compmaxtime']
            comm_mask = hyperdb.get_comm_mask('compmaxtime', comm_mask)          
        if 'comptype' in attributes:
            tag_prop_buf.nCompType = attributes['comptype']
            comm_mask = hyperdb.get_comm_mask('comptype', comm_mask)
            
        if 'recaccess' in attributes:
            tag_prop_buf.nRecAccess = attributes['recaccess'] 
            comm_mask = hyperdb.get_comm_mask('recaccess', comm_mask)
        if 'recnormalgroup' in attributes:
            tag_prop_buf.szRecNormalGroup = attributes['recnormalgroup']  
            comm_mask = hyperdb.get_comm_mask('recnormalgroup', comm_mask)
        if 'recownergroup' in attributes:
            tag_prop_buf.szRecOwnerGroup = attributes['recownergroup']  
            comm_mask = hyperdb.get_comm_mask('recownergroup', comm_mask)
            
        if 'descriptor' in attributes:
            tag_prop_buf.szDescriptor = bytes(attributes['descriptor'], encoding='gbk')
            comm_mask = hyperdb.get_comm_mask('descriptor', comm_mask)
        if 'digitalset' in attributes:
            tag_prop_buf.szDigitalSet = bytes(attributes['digitalset'], encoding='gbk') 
            comm_mask = hyperdb.get_comm_mask('digitalset', comm_mask)
        if 'engunit' in attributes:
            tag_prop_buf.szEngUnits = bytes(attributes['engunit'], encoding='gbk')    
            comm_mask = hyperdb.get_comm_mask('engunit', comm_mask)    
        if 'excmaxtime' in attributes:
            tag_prop_buf.fExcMaxTime = attributes['excmaxtime']
            comm_mask = hyperdb.get_comm_mask('excmaxtime', comm_mask)
        if 'excdev' in attributes:
            tag_prop_buf.fExcDev = attributes['excdev']
            comm_mask = hyperdb.get_comm_mask('excdev', comm_mask)
            
        if 'tagaccess' in attributes:
            tag_prop_buf.nTagAccess = attributes['tagaccess']
            comm_mask = hyperdb.get_comm_mask('tagaccess', comm_mask)
        if 'tagnormalgroup' in attributes:
            tag_prop_buf.szTagNormalGroup = attributes['tagnormalgroup']  
            comm_mask = hyperdb.get_comm_mask('tagnormalgroup', comm_mask)
        if 'tagownergroup' in attributes:
            tag_prop_buf.szTagOwnerGroup = attributes['tagownergroup']  
            comm_mask = hyperdb.get_comm_mask('tagownergroup', comm_mask)
                
            
        if 'scan' in attributes:
            tag_prop_buf.bScan = attributes['scan']
            comm_mask = hyperdb.get_comm_mask('scan', comm_mask)
        if 'span' in attributes:
            tag_prop_buf.fSpan = attributes['span']
            comm_mask = hyperdb.get_comm_mask('span', comm_mask)  
        if 'minvalue' in attributes:
            tag_prop_buf.fMinValue = attributes['minvalue'] 
            comm_mask = hyperdb.get_comm_mask('minvalue', comm_mask)
        if 'tagavaliable' in attributes:
            tag_prop_buf.nTagAvaliable = attributes['tagavaliable']
            comm_mask = hyperdb.get_comm_mask('tagavaliable', comm_mask)   
        if 'opcstate' in attributes:
            tag_prop_buf.nOpcRelease = attributes['opcstate']
            comm_mask = hyperdb.get_comm_mask('opcstate', comm_mask)  

        if 'imvstring' in attributes:
            tag_prop_buf.szImvString = bytes(attributes['imvstring'], encoding='gbk')  
            comm_mask = hyperdb.get_comm_mask('imvstring', comm_mask)
        if 'extstring1' in attributes:
            tag_prop_buf.szExtString1 = bytes(attributes['extstring1'], encoding='gbk')  
            comm_mask = hyperdb.get_comm_mask('extstring1', comm_mask)
        if 'extstring2' in attributes:
            tag_prop_buf.szExtString2 = bytes(attributes['extstring2'], encoding='gbk')  
            comm_mask = hyperdb.get_comm_mask('extstring2', comm_mask)
            
            
        if 'param1' in attributes:
            tag_prop_buf.nParam1 = attributes['param1']
            comm_mask = hyperdb.get_comm_mask('param1', comm_mask)
        if 'param2' in attributes:
            tag_prop_buf.nParam2 = attributes['param2']
            comm_mask = hyperdb.get_comm_mask('param2', comm_mask)
        if 'param3' in attributes:
            tag_prop_buf.nParam3 = attributes['param3']
            comm_mask = hyperdb.get_comm_mask('param3', comm_mask)
        if 'param4' in attributes:
            tag_prop_buf.nParam4 = attributes['param4']
            comm_mask = hyperdb.get_comm_mask('param4', comm_mask)
        if 'param5' in attributes:
            tag_prop_buf.nParam5 = attributes['param5']
            comm_mask = hyperdb.get_comm_mask('param5', comm_mask) 

                             
        if 'instrumentaddress' in attributes:
            tag_prop_buf.szInstrumentPoint = bytes(attributes['instrumentaddress'], encoding='gbk')  
            tag_ext_mask = hyperdb.get_tag_ext_mask('instrumentaddress', tag_ext_mask)  
        if 'instrumentaddresstype' in attributes:
            tag_prop_buf.szInstrumnetPointtype = bytes(attributes['instrumentaddresstype'], encoding='gbk') 
            tag_ext_mask = hyperdb.get_tag_ext_mask('instrumentaddresstype', tag_ext_mask)
        if 'collectorname' in attributes:
            tag_prop_buf.szCollectorName = bytes(attributes['collectorname'], encoding='gbk')  
            tag_ext_mask = hyperdb.get_tag_ext_mask('collectorname', tag_ext_mask)
            
        if 'devicename' in attributes:
            tag_prop_buf.szDeviceName = bytes(attributes['devicename'], encoding='gbk')    
            tag_ext_mask = hyperdb.get_tag_ext_mask('devicename', tag_ext_mask)

        if 'scangroupname' in attributes:
            tag_prop_buf.szScanGroupName = bytes(attributes['scangroupname'], encoding='gbk')    
            tag_ext_mask = hyperdb.get_tag_ext_mask('scangroupname', tag_ext_mask)
            
        if 'dataorder' in attributes:
            tag_prop_buf.szScanGroupName = bytes(attributes['dataorder'], encoding='gbk')    
            tag_ext_mask = hyperdb.get_tag_ext_mask('dataorder', tag_ext_mask)
        
        mask = hyperdb.HD3Mask()
        mask.commmask = c_int64(comm_mask)
        mask.extmask = c_int64(tag_ext_mask)
        
        tagid = c_uint32()
        
        hyperdb.api.pt3_add_tag.argtypes = [POINTER(hyperdb.TagProp), POINTER(hyperdb.HD3Mask), c_void_p]
        retcode = hyperdb.api.pt3_add_tag(byref(tag_prop_buf), byref(mask), byref(tagid))
        if (hyperdb.hd_sucess != retcode):
            raise hyperdb.HDError(retcode)
        return tagid


    ## modify Tag's properties
    # @param attributes: attributes is a dictionary including attributes be set to a tag 
    # @note: the dictionary must follow special formation,such as 'tagname = 'python',tagtype = 'int8', descriptor = 'pythontest',
    # some properties cann't be modified,such as 'tagname','tagid'
    def modify_tag_attributes(self,  **attributes):       
        tag_prop_buf = hyperdb.TagProp()
        comm_mask = 0
        ext_mask = 0        

        #comm attributes
        if 'archiving' in attributes:
            tag_prop_buf.bArchiving = int(attributes['archiving']) 
            comm_mask = hyperdb.get_comm_mask('archiving', comm_mask)
            
        if 'compdev' in attributes:
            tag_prop_buf.fCompDev = attributes['compdev']
            comm_mask = hyperdb.get_comm_mask('compdev', comm_mask)
        if 'compmaxtime' in attributes:
            tag_prop_buf.nCompMaxTime = attributes['compmaxtime']
            comm_mask = hyperdb.get_comm_mask('compmaxtime', comm_mask)          
        if 'comptype' in attributes:
            tag_prop_buf.nCompType = attributes['comptype']
            comm_mask = hyperdb.get_comm_mask('comptype', comm_mask)
            
        if 'recaccess' in attributes:
            tag_prop_buf.nRecAccess = attributes['recaccess'] 
            comm_mask = hyperdb.get_comm_mask('recaccess', comm_mask)
        if 'recnormalgroup' in attributes:
            tag_prop_buf.szRecNormalGroup = attributes['recnormalgroup']  
            comm_mask = hyperdb.get_comm_mask('recnormalgroup', comm_mask)
        if 'recownergroup' in attributes:
            tag_prop_buf.szRecOwnerGroup = attributes['recownergroup']  
            comm_mask = hyperdb.get_comm_mask('recownergroup', comm_mask)
            
        if 'descriptor' in attributes:
            tag_prop_buf.szDescriptor = bytes(attributes['descriptor'], encoding='gbk')   
            comm_mask = hyperdb.get_comm_mask('descriptor', comm_mask)
        if 'digitalset' in attributes:
            tag_prop_buf.szDigitalSet = bytes(attributes['digitalset'], encoding='gbk')   
            comm_mask = hyperdb.get_comm_mask('digitalset', comm_mask)
        if 'engunit' in attributes:
            tag_prop_buf.szEngUnits = bytes(attributes['engunit'], encoding='gbk')   
            comm_mask = hyperdb.get_comm_mask('engunit', comm_mask)    
        if 'excmaxtime' in attributes:
            tag_prop_buf.fExcMaxTime = attributes['excmaxtime']
            comm_mask = hyperdb.get_comm_mask('excmaxtime', comm_mask)
        if 'excdev' in attributes:
            tag_prop_buf.fExcDev = attributes['excdev']
            comm_mask = hyperdb.get_comm_mask('excdev', comm_mask)
            
        if 'tagaccess' in attributes:
            tag_prop_buf.nTagAccess = attributes['tagaccess']
            comm_mask = hyperdb.get_comm_mask('tagaccess', comm_mask)
        if 'tagnormalgroup' in attributes:
            tag_prop_buf.szTagNormalGroup = attributes['tagnormalgroup']  
            comm_mask = hyperdb.get_comm_mask('tagnormalgroup', comm_mask)
        if 'tagownergroup' in attributes:
            tag_prop_buf.szTagOwnerGroup = attributes['tagownergroup']  
            comm_mask = hyperdb.get_comm_mask('tagownergroup', comm_mask)
            
        if 'scan' in attributes:
            tag_prop_buf.bScan = attributes['scan']
            comm_mask = hyperdb.get_comm_mask('scan', comm_mask)
        if 'span' in attributes:
            tag_prop_buf.fSpan = attributes['span']
            comm_mask = hyperdb.get_comm_mask('span', comm_mask)  
        if 'minvalue' in attributes:
            tag_prop_buf.fMinValue = attributes['minvalue'] 
            comm_mask = hyperdb.get_comm_mask('minvalue', comm_mask)
            
        if 'tagavaliable' in attributes:
            tag_prop_buf.nTagAvaliable = attributes['tagavaliable']
            comm_mask = hyperdb.get_comm_mask('tagavaliable', comm_mask)  
        if 'opcstate' in attributes:
            tag_prop_buf.nOpcRelease = attributes['opcstate'] 
            comm_mask = hyperdb.get_comm_mask('opcstate', comm_mask)
        
        if 'imvstring' in attributes:
            tag_prop_buf.szImvString = bytes(attributes['imvstring'], encoding='gbk') 
            comm_mask = hyperdb.get_comm_mask('imvstring', comm_mask)
            
        if 'extstring1' in attributes:
            tag_prop_buf.szExtString1 = bytes(attributes['extstring1'], encoding='gbk') 
            comm_mask = hyperdb.get_comm_mask('extstring1', comm_mask)
        
        if 'extstring2' in attributes:
            tag_prop_buf.szExtString2 = bytes(attributes['extstring2'], encoding='gbk') 
            comm_mask = hyperdb.get_comm_mask('extstring2', comm_mask)
            
        if 'param1' in attributes:
            tag_prop_buf.nParam1 = attributes['param1']
            comm_mask = hyperdb.get_comm_mask('param1', comm_mask)
        if 'param2' in attributes:
            tag_prop_buf.nParam2 = attributes['param2']
            comm_mask = hyperdb.get_comm_mask('param2', comm_mask)
        if 'param3' in attributes:
            tag_prop_buf.nParam3 = attributes['param3']
            comm_mask = hyperdb.get_comm_mask('param3', comm_mask)
        if 'param4' in attributes:
            tag_prop_buf.nParam4 = attributes['param4']
            comm_mask = hyperdb.get_comm_mask('param4', comm_mask)
        if 'param5' in attributes:
            tag_prop_buf.nParam5 = attributes['param5']
            comm_mask = hyperdb.get_comm_mask('param5', comm_mask)
        
        
        # ext attributes            
        if 'instrumentaddress' in attributes:
            tag_prop_buf.szInstrumentPoint = attributes['instrumentaddress']  
            ext_mask = hyperdb.get_tag_ext_mask('instrumentaddress', ext_mask)  
        if 'instrumentaddresstype' in attributes:
            tag_prop_buf.szInstrumnetPointtype = attributes['instrumentaddresstype'] 
            ext_mask = hyperdb.get_tag_ext_mask('instrumentaddresstype', ext_mask)
        if 'collectorname' in attributes:
            tag_prop_buf.szCollectorName = attributes['collectorname']  
            ext_mask = hyperdb.get_tag_ext_mask('collectorname', ext_mask)
            
        if 'devicename' in attributes:
            tag_prop_buf.szDeviceName = bytes(attributes['devicename'], encoding='gbk')   
            ext_mask = hyperdb.get_tag_ext_mask('devicename', ext_mask)
            
        if 'scangroupname' in attributes:
            tag_prop_buf.szScanGroupName = bytes(attributes['scangroupname'], encoding='gbk')   
            ext_mask = hyperdb.get_tag_ext_mask('scangroupname', ext_mask)
            
        if 'dataorder' in attributes:
            tag_prop_buf.szDataOrder = bytes(attributes['dataorder'], encoding='gbk')   
            ext_mask = hyperdb.get_tag_ext_mask('dataorder', ext_mask)
        
        mask = hyperdb.HD3Mask()
        mask.commmask = c_int64(comm_mask)
        mask.extmask = c_int64(ext_mask)
        
        hyperdb.api.pt3_modify_tag_prop.argtypes = [c_int32, POINTER(hyperdb.TagProp), POINTER(hyperdb.HD3Mask)]
        retcode = hyperdb.api.pt3_modify_tag_prop(self.tagid, byref(tag_prop_buf), mask)
        if (hyperdb.hd_sucess != retcode):
            raise hyperdb.HDError(retcode)
        return hyperdb.hd_sucess
    
    ''' 
    # add a list of new normal tags to server
    # @param props: a list of dictionary, such as 
                    [{'tagname': 'tag0',
                      'tagtype': 'int32'
                     },{'tagname': 'tag1',
                      'tagtype': 'int32'
                     }]
    # @note: the input dictionary attributes should include param of TagProp
    # seen in tag.py
    '''
    def add_tags(self, props): 
        number = len(props)
        tag_prop_buf = (number *hyperdb.TagProp)()
        
        count=0
        mask = (number * hyperdb.HD3Mask)()
        for attributes in props:
            if 'tagname' not in attributes or 'tagtype' not in attributes:
                raise ArgumentError
        
            comm_mask = 0
            tag_ext_mask = 0
        
            tag_prop_buf[count].szTagName = bytes(attributes['tagname'], encoding='gbk')
            if not tag_prop_buf[count].szTagName.strip():
                raise ArgumentError
            comm_mask = hyperdb.get_comm_mask('tagname', comm_mask)
        
            tag_prop_buf[count].nTagType = hyperdb.tag_type_dict[attributes['tagtype']] 
            comm_mask = hyperdb.get_comm_mask('tagtype', comm_mask)
        
            if 'archiving' in attributes:
                tag_prop_buf[count].bArchiving = attributes['archiving'] 
                comm_mask = hyperdb.get_comm_mask('archiving', comm_mask)

            if 'compdev' in attributes:
                tag_prop_buf[count].fCompDev = attributes['compdev']
                comm_mask = hyperdb.get_comm_mask('compdev', comm_mask)
            if 'compmaxtime' in attributes:
                tag_prop_buf[count].nCompMaxTime = attributes['compmaxtime']
                comm_mask = hyperdb.get_comm_mask('compmaxtime', comm_mask)          
            if 'comptype' in attributes:
                tag_prop_buf[count].nCompType = attributes['comptype']
                comm_mask = hyperdb.get_comm_mask('comptype', comm_mask)
            
            if 'recaccess' in attributes:
                tag_prop_buf[count].nRecAccess = attributes['recaccess'] 
                comm_mask = hyperdb.get_comm_mask('recaccess', comm_mask)
            if 'recnormalgroup' in attributes:
                tag_prop_buf[count].szRecNormalGroup = attributes['recnormalgroup']  
                comm_mask = hyperdb.get_comm_mask('recnormalgroup', comm_mask)
            if 'recownergroup' in attributes:
                tag_prop_buf[count].szRecOwnerGroup = attributes['recownergroup']  
                comm_mask = hyperdb.get_comm_mask('recownergroup', comm_mask)
            
            if 'descriptor' in attributes:
                tag_prop_buf[count].szDescriptor = attributes['descriptor']  
                comm_mask = hyperdb.get_comm_mask('descriptor', comm_mask)
            if 'digitalset' in attributes:
                tag_prop_buf[count].szDigitalSet = attributes['digitalset']  
                comm_mask = hyperdb.get_comm_mask('digitalset', comm_mask)
            if 'engunit' in attributes:
                tag_prop_buf[count].szEngUnits = attributes['engunit']  
                comm_mask = hyperdb.get_comm_mask('engunit', comm_mask)    
            if 'excmaxtime' in attributes:
                tag_prop_buf[count].fExcMaxTime = attributes['excmaxtime']
                comm_mask = hyperdb.get_comm_mask('excmaxtime', comm_mask)
            if 'excdev' in attributes:
                tag_prop_buf[count].fExcDev = attributes['excdev']
                comm_mask = hyperdb.get_comm_mask('excdev', comm_mask)
            
            if 'tagaccess' in attributes:
                tag_prop_buf[count].nTagAccess = attributes['tagaccess']
                comm_mask = hyperdb.get_comm_mask('tagaccess', comm_mask)
            if 'tagnormalgroup' in attributes:
                tag_prop_buf[count].szTagNormalGroup = attributes['tagnormalgroup']  
                comm_mask = hyperdb.get_comm_mask('tagnormalgroup', comm_mask)
            if 'tagownergroup' in attributes:
                tag_prop_buf[count].szTagOwnerGroup = attributes['tagownergroup']  
                comm_mask = hyperdb.get_comm_mask('tagownergroup', comm_mask)
                
            
            if 'scan' in attributes:
                tag_prop_buf[count].bScan = attributes['scan']
                comm_mask = hyperdb.get_comm_mask('scan', comm_mask)
            if 'span' in attributes:
                tag_prop_buf[count].fSpan = attributes['span']
                comm_mask = hyperdb.get_comm_mask('span', comm_mask)  
            if 'minvalue' in attributes:
                tag_prop_buf[count].fMinValue = attributes['minvalue'] 
                comm_mask = hyperdb.get_comm_mask('minvalue', comm_mask)
            if 'tagavaliable' in attributes:
                tag_prop_buf[count].nTagAvaliable = attributes['tagavaliable']
                comm_mask = hyperdb.get_comm_mask('tagavaliable', comm_mask)   
            if 'opcstate' in attributes:
                tag_prop_buf[count].nOpcRelease = attributes['opcstate']
                comm_mask = hyperdb.get_comm_mask('opcstate', comm_mask)  

            if 'imvstring' in attributes:
                tag_prop_buf[count].szImvString = attributes['imvstring']
                comm_mask = hyperdb.get_comm_mask('imvstring', comm_mask)
            if 'extstring1' in attributes:
                tag_prop_buf[count].szExtString1 = attributes['extstring1']
                comm_mask = hyperdb.get_comm_mask('extstring1', comm_mask)
            if 'extstring2' in attributes:
                tag_prop_buf[count].szExtString2 = attributes['extstring2']
                comm_mask = hyperdb.get_comm_mask('extstring2', comm_mask)
            
            
            if 'param1' in attributes:
                tag_prop_buf[count].nParam1 = attributes['param1']
                comm_mask = hyperdb.get_comm_mask('param1', comm_mask)
            if 'param2' in attributes:
                tag_prop_buf[count].nParam2 = attributes['param2']
                comm_mask = hyperdb.get_comm_mask('param2', comm_mask)
            if 'param3' in attributes:
                tag_prop_buf[count].nParam3 = attributes['param3']
                comm_mask = hyperdb.get_comm_mask('param3', comm_mask)
            if 'param4' in attributes:
                tag_prop_buf[count].nParam4 = attributes['param4']
                comm_mask = hyperdb.get_comm_mask('param4', comm_mask)
            if 'param5' in attributes:
                tag_prop_buf[count].nParam5 = attributes['param5']
                comm_mask = hyperdb.get_comm_mask('param5', comm_mask) 

            if 'instrumentaddress' in attributes:
                tag_prop_buf[count].szInstrumentPoint = attributes['instrumentaddress']  
                tag_ext_mask = hyperdb.get_tag_ext_mask('instrumentaddress', tag_ext_mask)  
            if 'instrumentaddresstype' in attributes:
                tag_prop_buf[count].szInstrumnetPointtype = attributes['instrumentaddresstype'] 
                tag_ext_mask = hyperdb.get_tag_ext_mask('instrumentaddresstype', tag_ext_mask)
            if 'collectorname' in attributes:
                tag_prop_buf[count].szCollectorName = attributes['collectorname']  
                tag_ext_mask = hyperdb.get_tag_ext_mask('collectorname', tag_ext_mask)
            
            if 'devicename' in attributes:
                tag_prop_buf[count].szDeviceName = attributes['devicename']  
                tag_ext_mask = hyperdb.get_tag_ext_mask('devicename', tag_ext_mask)

            if 'scangroupname' in attributes:
                tag_prop_buf[count].szScanGroupName = attributes['scangroupname']  
                tag_ext_mask = hyperdb.get_tag_ext_mask('scangroupname', tag_ext_mask)
            
            if 'dataorder' in attributes:
                tag_prop_buf[count].szScanGroupName = attributes['dataorder']  
                tag_ext_mask = hyperdb.get_tag_ext_mask('dataorder', tag_ext_mask)
        
            # mask = hyperdb.HD3Mask()
            mask[count].commmask = c_int64(comm_mask)
            mask[count].extmask = c_int64(tag_ext_mask)
            # tagmask.append(mask)
            count +=1
              
        tagids = (number *c_uint32)()
        errorcode = (number * c_int32)()
        hyperdb.api.pt3_add_tags.argtypes = [c_int32,POINTER(hyperdb.TagProp), POINTER(hyperdb.HD3Mask), c_char_p,POINTER(c_uint32),POINTER(c_int32)]
        retcode = hyperdb.api.pt3_add_tags(number,tag_prop_buf, mask,None,tagids,errorcode)
        if (hyperdb.hd_sucess != retcode):
            raise hyperdb.HDError(retcode)
        return tagids
    
    '''  
    def modify_comm_tag_attributes(self,props):
        number = len(props)
        tag_prop_buf = (number *hyperdb.TagProp)()
        tagids = (number *c_uint32)()
        count=0
        mask = (number * hyperdb.HD3Mask)()
        for attributes in props:
            comm_mask = 0
            tag_ext_mask = 0
            if 'tagid' in attributes:
                tagids[count] = attributes['tagid']
            if 'tagname' in attributes:
                tagname = attributes['tagname']
                tagids[count]=self.get_tag(tagname).tagid
            if tagids[count] == '':
                continue
            
            
            if 'archiving' in attributes:
                tag_prop_buf[count].bArchiving = attributes['archiving'] 
                comm_mask = hyperdb.get_comm_mask('archiving', comm_mask)

            if 'compdev' in attributes:
                tag_prop_buf[count].fCompDev = attributes['compdev']
                comm_mask = hyperdb.get_comm_mask('compdev', comm_mask)
            if 'compmaxtime' in attributes:
                tag_prop_buf[count].nCompMaxTime = attributes['compmaxtime']
                comm_mask = hyperdb.get_comm_mask('compmaxtime', comm_mask)          
            if 'comptype' in attributes:
                tag_prop_buf[count].nCompType = attributes['comptype']
                comm_mask = hyperdb.get_comm_mask('comptype', comm_mask)
            
            if 'recaccess' in attributes:
                tag_prop_buf[count].nRecAccess = attributes['recaccess'] 
                comm_mask = hyperdb.get_comm_mask('recaccess', comm_mask)
            if 'recnormalgroup' in attributes:
                tag_prop_buf[count].szRecNormalGroup = attributes['recnormalgroup']  
                comm_mask = hyperdb.get_comm_mask('recnormalgroup', comm_mask)
            if 'recownergroup' in attributes:
                tag_prop_buf[count].szRecOwnerGroup = attributes['recownergroup']  
                comm_mask = hyperdb.get_comm_mask('recownergroup', comm_mask)
            
            if 'descriptor' in attributes:
                tag_prop_buf[count].szDescriptor = attributes['descriptor']  
                comm_mask = hyperdb.get_comm_mask('descriptor', comm_mask)
            if 'digitalset' in attributes:
                tag_prop_buf[count].szDigitalSet = attributes['digitalset']  
                comm_mask = hyperdb.get_comm_mask('digitalset', comm_mask)
            if 'engunit' in attributes:
                tag_prop_buf[count].szEngUnits = attributes['engunit']  
                comm_mask = hyperdb.get_comm_mask('engunit', comm_mask)    
            if 'excmaxtime' in attributes:
                tag_prop_buf[count].fExcMaxTime = attributes['excmaxtime']
                comm_mask = hyperdb.get_comm_mask('excmaxtime', comm_mask)
            if 'excdev' in attributes:
                tag_prop_buf[count].fExcDev = attributes['excdev']
                comm_mask = hyperdb.get_comm_mask('excdev', comm_mask)
            
            if 'tagaccess' in attributes:
                tag_prop_buf[count].nTagAccess = attributes['tagaccess']
                comm_mask = hyperdb.get_comm_mask('tagaccess', comm_mask)
            if 'tagnormalgroup' in attributes:
                tag_prop_buf[count].szTagNormalGroup = attributes['tagnormalgroup']  
                comm_mask = hyperdb.get_comm_mask('tagnormalgroup', comm_mask)
            if 'tagownergroup' in attributes:
                tag_prop_buf[count].szTagOwnerGroup = attributes['tagownergroup']  
                comm_mask = hyperdb.get_comm_mask('tagownergroup', comm_mask)
                
            
            if 'scan' in attributes:
                tag_prop_buf[count].bScan = attributes['scan']
                comm_mask = hyperdb.get_comm_mask('scan', comm_mask)
            if 'span' in attributes:
                tag_prop_buf[count].fSpan = attributes['span']
                comm_mask = hyperdb.get_comm_mask('span', comm_mask)  
            if 'minvalue' in attributes:
                tag_prop_buf[count].fMinValue = attributes['minvalue'] 
                comm_mask = hyperdb.get_comm_mask('minvalue', comm_mask)
            if 'tagavaliable' in attributes:
                tag_prop_buf[count].nTagAvaliable = attributes['tagavaliable']
                comm_mask = hyperdb.get_comm_mask('tagavaliable', comm_mask)   
            if 'opcstate' in attributes:
                tag_prop_buf[count].nOpcRelease = attributes['opcstate']
                comm_mask = hyperdb.get_comm_mask('opcstate', comm_mask)  

            if 'imvstring' in attributes:
                tag_prop_buf[count].szImvString = attributes['imvstring']
                comm_mask = hyperdb.get_comm_mask('imvstring', comm_mask)
            if 'extstring1' in attributes:
                tag_prop_buf[count].szExtString1 = attributes['extstring1']
                comm_mask = hyperdb.get_comm_mask('extstring1', comm_mask)
            if 'extstring2' in attributes:
                tag_prop_buf[count].szExtString2 = attributes['extstring2']
                comm_mask = hyperdb.get_comm_mask('extstring2', comm_mask)
            
            
            if 'param1' in attributes:
                tag_prop_buf[count].nParam1 = attributes['param1']
                comm_mask = hyperdb.get_comm_mask('param1', comm_mask)
            if 'param2' in attributes:
                tag_prop_buf[count].nParam2 = attributes['param2']
                comm_mask = hyperdb.get_comm_mask('param2', comm_mask)
            if 'param3' in attributes:
                tag_prop_buf[count].nParam3 = attributes['param3']
                comm_mask = hyperdb.get_comm_mask('param3', comm_mask)
            if 'param4' in attributes:
                tag_prop_buf[count].nParam4 = attributes['param4']
                comm_mask = hyperdb.get_comm_mask('param4', comm_mask)
            if 'param5' in attributes:
                tag_prop_buf[count].nParam5 = attributes['param5']
                comm_mask = hyperdb.get_comm_mask('param5', comm_mask) 
                
           # mask = hyperdb.HD3Mask()
            mask[count].commmask = c_int64(comm_mask)
            mask[count].extmask = c_int64(tag_ext_mask)
           # tagmask.append(mask)
            count +=1
        errorcode = (number * c_int32)()
        hyperdb.api.pt3_modify_tags_prop.argtypes = [c_int32,POINTER(c_uint32),POINTER(hyperdb.TagProp), POINTER(hyperdb.HD3Mask),POINTER(c_int32)]
        retcode = hyperdb.api.pt3_modify_tags_prop(number,tagids,tag_prop_buf, mask,errorcode)
        if (hyperdb.hd_sucess != retcode):
            raise hyperdb.HDError(retcode)
        return tagids    
    '''
    # get a instance of tag from server by tagname
    # @param tagname: the name of the tag which will be get  
    # @return: return a instance of tag
    def get_tag(self, tagname):
        if type(tagname) != str:
            raise TypeError
        
        tagid = c_uint32()
        tagname_buf = bytes(tagname, encoding='gbk')
        tag_prop_buf = hyperdb.TagProp()
        
        hyperdb.api.tag3_query_id_by_name.argtypes = (c_char_p, c_void_p)
        retcode = hyperdb.api.tag3_query_id_by_name(tagname_buf, byref(tagid))
        if (hyperdb.hd_sucess != retcode):
            raise hyperdb.HDError(retcode)
        
        hyperdb.api.pt3_query_tag_prop.argtypes = [c_uint32, POINTER(hyperdb.TagProp)]
        retcode = hyperdb.api.pt3_query_tag_prop(tagid, byref(tag_prop_buf))
        if (hyperdb.hd_sucess != retcode):
            raise hyperdb.HDError(retcode)  
              
        tag_buf = tag.Tag()
        tag_buf.tagname = tag_prop_buf.szTagName
        tag_buf.archiving = tag_prop_buf.bArchiving      
        tag_buf.changedate = tag_prop_buf.nChangeDate
        tag_buf.changer = tag_prop_buf.szChanger
        
        tag_buf.compdev = tag_prop_buf.fCompDev   
        tag_buf.compmaxtime = tag_prop_buf.nCompMaxTime
        tag_buf.comptype = tag_prop_buf.nCompType          
        tag_buf.creationdate = tag_prop_buf.nCreationDate 
        tag_buf.creator = tag_prop_buf.szCreator   
               
        tag_buf.recaccess = tag_prop_buf.nRecAccess 
        tag_buf.recnormalgroup = tag_prop_buf.szRecNormalGroup   
        tag_buf.recownergroup = tag_prop_buf.szRecOwnerGroup 
        
        tag_buf.descriptor = tag_prop_buf.szDescriptor          
        tag_buf.digitalset = tag_prop_buf.szDigitalSet  
        tag_buf.engunit = tag_prop_buf.szEngUnits         
        tag_buf.excmaxtime = tag_prop_buf.nExcMaxTime  
        tag_buf.excdev = tag_prop_buf.fExcDev
               
        tag_buf.tagid = tag_prop_buf.nTagID  
        
        for value in hyperdb.tag_type_dict:
            if hyperdb.tag_type_dict[value] == tag_prop_buf.nTagType:
                tag_buf.tagtype = value 
                
        tag_buf.tagaccess = tag_prop_buf.nTagAccess          
        tag_buf.tagnormalgroup = tag_prop_buf.szTagNormalGroup  
        tag_buf.tagownergroup = tag_prop_buf.szTagOwnerGroup 
                 
        tag_buf.scan = tag_prop_buf.bScan
        tag_buf.span = tag_prop_buf.fSpan 
        
        tag_buf.minvalue = tag_prop_buf.fMinValue
        tag_buf.tagclass = tag_prop_buf.nTagClass
        tag_buf.tagavaliable = tag_prop_buf.nTagAvaliable
         
        tag_buf.param1 = tag_prop_buf.nParam1
        tag_buf.param2 = tag_prop_buf.nParam2      
        tag_buf.param3 = tag_prop_buf.nParam3
        tag_buf.param4 = tag_prop_buf.nParam4  
        tag_buf.param5 = tag_prop_buf.nParam5
        tag_buf.opcstate = tag_prop_buf.nOpcRelease
        
        tag_buf.imvstring = tag_prop_buf.szImvString
        tag_buf.extstring1 = tag_prop_buf.szExtString1
        tag_buf.extstring2 = tag_prop_buf.szExtString2
        
        tag_buf.instrumentaddress = tag_prop_buf.szInstrumentAddress 
        tag_buf.instrumentaddresstype =  tag_prop_buf.nInstrumentAddressType         
        
        tag_buf.collectorname = tag_prop_buf.szCollectorName 
        tag_buf.collectorid = tag_prop_buf.nCollectorID

        tag_buf.devicename = tag_prop_buf.szDeviceName 
        tag_buf.deviceid = tag_prop_buf.nDeviceID

        tag_buf.scangroupname = tag_prop_buf.szScanGroupName 
        tag_buf.scangroupid = tag_prop_buf.nScanGroupID 
        tag_buf.dataorder = tag_prop_buf.nDataOrder

        return tag_buf

    # get tag's type from server by tagID
    # @param tagID: the ID of the tag   
    # @return: return the type of tag(such as 'int8')
    def get_tagType(self, tagID):
    
        hdTagID = c_uint32(tagID)
        nTagType = c_uint8()
        
        hyperdb.api.pt3_query_tag_type.argtypes = [c_uint32, POINTER(c_uint8)]
        retcode = hyperdb.api.pt3_query_tag_type(hdTagID, nTagType)
        if (hyperdb.hd_sucess != retcode):
            raise hyperdb.HDError(retcode)
        
        rtnTagType = hyperdb.tag_type_trans_dict[nTagType.value]
        return rtnTagType   
      
    # delete a tag from server by its name
    # @param tagname: the name of the tag
    def delete_tag(self, tagname):
        "delete a tag by name"
        if type(tagname) != str:
            raise TypeError
        
        tagid = c_uint32()
        tagname_buf = bytes(tagname, encoding='gbk')        
        hyperdb.api.tag3_query_id_by_name.argtypes = [c_char_p, c_void_p]
        retcode = hyperdb.api.tag3_query_id_by_name(tagname_buf, byref(tagid))
        if (hyperdb.hd_sucess != retcode):
            raise hyperdb.HDError(retcode)
        
        hyperdb.api.tag3_delete_tag.argtypes = [c_uint32]
        retcode = hyperdb.api.tag3_delete_tag(tagid)
        if (hyperdb.hd_sucess != retcode):
            raise hyperdb.HDError(retcode)
        return hyperdb.hd_sucess
    
    # query tags which satisfy the conditions
    # @param conds: the conditions used to query tags which satisfied with 
    # @return: return a iterator of tags
    def query_tags_cond(self, conds):
        number = len(conds)
        conds_buf = (number * hyperdb.HD3FilterItem)()
        condset = hyperdb.HD3FilterItemSet()
       
        count = 0
        for cond in conds:
            try:
                conds_buf[count].nPropItemID = hyperdb.tag_col_dict[cond[0]]
                conds_buf[count].nRelation = hyperdb.relation_dict[cond[1]]
                if cond[0] == 'tagtype':
                    conds_buf[count].szValue = bytes(str(hyperdb.tag_type_dict[cond[2]]), encoding='gbk')  
                else:
                    conds_buf[count].szValue = bytes(cond[2] , encoding='gbk')
                print(conds_buf[count].szValue)
            except KeyError:
                raise hyperdb.HDError(errcode = 0, errinfo = 'the key is not exist!')

            count = count + 1

        condset.nSize = c_int32(number)
        condset.pItem = conds_buf
        
        hditer = c_void_p()   
        mask = hyperdb.HD3Mask()
        mask.commmask = c_int64(0XFFFFFFFFFFFFFFFF)
        mask.extmask = c_int64(0XFFFFFFFFFFFFFFFF)
        
        hyperdb.api.pt3_query_tags_cond.argtypes = [POINTER(hyperdb.HD3FilterItemSet), POINTER(hyperdb.HD3Mask), POINTER(c_void_p)]
        retcode = hyperdb.api.pt3_query_tags_cond(byref(condset), byref(mask), byref(hditer))
        if hyperdb.hd_sucess != retcode:
            raise hyperdb.HDError(retcode)
        
        tag_prop = hyperdb.TagProp()
        iterate = hyperdb.Iterate(hditer, tag_prop)
        return iterate
    
    ''' 
    # add a list of new calctags to server
    # @param props: a list of dictionary, such as 
                    [{'tagname': 'catag0',
                      'tagtype': 'int32',
                      'szCalcExpr': '\'srctag\'+1',
                     'szSourceTagName':'srctag',
                     'nCalcMode' : 0,
                     'nCalcPeriod' :5
                     },{'tagname': 'catag1',
                      'tagtype': 'int32',
                      'szCalcExpr': '\'srctag\'+1',
                     'szSourceTagName':'srctag',
                     'nCalcMode' : 0,
                     'nCalcPeriod' :5
                     }]
    # @note: the input dictionary attributes should include para of CalcTagProp
    # seen in tag.py
    '''
    def add_calc_tags(self, props): 
        number = len(props)
        tag_prop_buf = (number *hyperdb.CalcTagProp)()
        
        count=0
        mask = (number * hyperdb.HD3Mask)()
        for attributes in props:
            if 'tagname' not in attributes or 'tagtype' not in attributes:
                raise ArgumentError
        
            comm_mask = 0
            tag_ext_mask = 0
        
            tag_prop_buf[count].szTagName = bytes(attributes['tagname'], encoding='gbk')
            if not tag_prop_buf[count].szTagName.strip():
                raise ArgumentError
            comm_mask = hyperdb.get_comm_mask('tagname', comm_mask)
        
            tag_prop_buf[count].nTagType = hyperdb.tag_type_dict[attributes['tagtype']] 
            comm_mask = hyperdb.get_comm_mask('tagtype', comm_mask)
        
            if 'archiving' in attributes:
                tag_prop_buf[count].bArchiving = attributes['archiving'] 
                comm_mask = hyperdb.get_comm_mask('archiving', comm_mask)

            if 'compdev' in attributes:
                tag_prop_buf[count].fCompDev = attributes['compdev']
                comm_mask = hyperdb.get_comm_mask('compdev', comm_mask)
            if 'compmaxtime' in attributes:
                tag_prop_buf[count].nCompMaxTime = attributes['compmaxtime']
                comm_mask = hyperdb.get_comm_mask('compmaxtime', comm_mask)          
            if 'comptype' in attributes:
                tag_prop_buf[count].nCompType = attributes['comptype']
                comm_mask = hyperdb.get_comm_mask('comptype', comm_mask)
            
            if 'recaccess' in attributes:
                tag_prop_buf[count].nRecAccess = attributes['recaccess'] 
                comm_mask = hyperdb.get_comm_mask('recaccess', comm_mask)
            if 'recnormalgroup' in attributes:
                tag_prop_buf[count].szRecNormalGroup = attributes['recnormalgroup']  
                comm_mask = hyperdb.get_comm_mask('recnormalgroup', comm_mask)
            if 'recownergroup' in attributes:
                tag_prop_buf[count].szRecOwnerGroup = attributes['recownergroup']  
                comm_mask = hyperdb.get_comm_mask('recownergroup', comm_mask)
            
            if 'descriptor' in attributes:
                tag_prop_buf[count].szDescriptor = attributes['descriptor']  
                comm_mask = hyperdb.get_comm_mask('descriptor', comm_mask)
            if 'digitalset' in attributes:
                tag_prop_buf[count].szDigitalSet = attributes['digitalset']  
                comm_mask = hyperdb.get_comm_mask('digitalset', comm_mask)
            if 'engunit' in attributes:
                tag_prop_buf[count].szEngUnits = attributes['engunit']  
                comm_mask = hyperdb.get_comm_mask('engunit', comm_mask)    
            if 'excmaxtime' in attributes:
                tag_prop_buf[count].fExcMaxTime = attributes['excmaxtime']
                comm_mask = hyperdb.get_comm_mask('excmaxtime', comm_mask)
            if 'excdev' in attributes:
                tag_prop_buf[count].fExcDev = attributes['excdev']
                comm_mask = hyperdb.get_comm_mask('excdev', comm_mask)
            
            if 'tagaccess' in attributes:
                tag_prop_buf[count].nTagAccess = attributes['tagaccess']
                comm_mask = hyperdb.get_comm_mask('tagaccess', comm_mask)
            if 'tagnormalgroup' in attributes:
                tag_prop_buf[count].szTagNormalGroup = attributes['tagnormalgroup']  
                comm_mask = hyperdb.get_comm_mask('tagnormalgroup', comm_mask)
            if 'tagownergroup' in attributes:
                tag_prop_buf[count].szTagOwnerGroup = attributes['tagownergroup']  
                comm_mask = hyperdb.get_comm_mask('tagownergroup', comm_mask)
                
            
            if 'scan' in attributes:
                tag_prop_buf[count].bScan = attributes['scan']
                comm_mask = hyperdb.get_comm_mask('scan', comm_mask)
            if 'span' in attributes:
                tag_prop_buf[count].fSpan = attributes['span']
                comm_mask = hyperdb.get_comm_mask('span', comm_mask)  
            if 'minvalue' in attributes:
                tag_prop_buf[count].fMinValue = attributes['minvalue'] 
                comm_mask = hyperdb.get_comm_mask('minvalue', comm_mask)
            if 'tagavaliable' in attributes:
                tag_prop_buf[count].nTagAvaliable = attributes['tagavaliable']
                comm_mask = hyperdb.get_comm_mask('tagavaliable', comm_mask)   
            if 'opcstate' in attributes:
                tag_prop_buf[count].nOpcRelease = attributes['opcstate']
                comm_mask = hyperdb.get_comm_mask('opcstate', comm_mask)  

            if 'imvstring' in attributes:
                tag_prop_buf[count].szImvString = attributes['imvstring']
                comm_mask = hyperdb.get_comm_mask('imvstring', comm_mask)
            if 'extstring1' in attributes:
                tag_prop_buf[count].szExtString1 = attributes['extstring1']
                comm_mask = hyperdb.get_comm_mask('extstring1', comm_mask)
            if 'extstring2' in attributes:
                tag_prop_buf[count].szExtString2 = attributes['extstring2']
                comm_mask = hyperdb.get_comm_mask('extstring2', comm_mask)
            
            
            if 'param1' in attributes:
                tag_prop_buf[count].nParam1 = attributes['param1']
                comm_mask = hyperdb.get_comm_mask('param1', comm_mask)
            if 'param2' in attributes:
                tag_prop_buf[count].nParam2 = attributes['param2']
                comm_mask = hyperdb.get_comm_mask('param2', comm_mask)
            if 'param3' in attributes:
                tag_prop_buf[count].nParam3 = attributes['param3']
                comm_mask = hyperdb.get_comm_mask('param3', comm_mask)
            if 'param4' in attributes:
                tag_prop_buf[count].nParam4 = attributes['param4']
                comm_mask = hyperdb.get_comm_mask('param4', comm_mask)
            if 'param5' in attributes:
                tag_prop_buf[count].nParam5 = attributes['param5']
                comm_mask = hyperdb.get_comm_mask('param5', comm_mask) 

                             
            if 'nCalcMode' in attributes:
                tag_prop_buf[count].nCalcMode = attributes['nCalcMode']  
                tag_ext_mask = hyperdb.get_calc_ext_mask('nCalcMode', tag_ext_mask)  
            if 'nCalcPeriod' in attributes:
                tag_prop_buf[count].nCalcPeriod = attributes['nCalcPeriod'] 
                tag_ext_mask = hyperdb.get_calc_ext_mask('nCalcPeriod', tag_ext_mask)
            if 'szCalcExpr' in attributes:
                tag_prop_buf[count].szCalcExpr = bytes(attributes['szCalcExpr'], encoding='gbk')
                tag_ext_mask = hyperdb.get_calc_ext_mask('szCalcExpr', tag_ext_mask)
            
            if 'bCalcHistory' in attributes:
                tag_prop_buf[count].bCalcHistory = attributes['bCalcHistory']  
                tag_ext_mask = hyperdb.get_calc_ext_mask('bCalcHistory', tag_ext_mask)

            if 'nCalcStartDate' in attributes:
                tag_prop_buf[count].nCalcStartDate = attributes['nCalcStartDate']  
                tag_ext_mask = hyperdb.get_calc_ext_mask('nCalcStartDate', tag_ext_mask)
            
            if 'nCalcEndDate' in attributes:
                tag_prop_buf[count].nCalcEndDate = attributes['nCalcEndDate']  
                tag_ext_mask = hyperdb.get_calc_ext_mask('nCalcEndDate', tag_ext_mask)
        
            if 'bHaveEndTime' in attributes:
                tag_prop_buf[count].bHaveEndTime = attributes['bHaveEndTime']
                tag_ext_mask = hyperdb.get_calc_ext_mask('bHaveEndTime', tag_ext_mask)
        
            if 'szSourceTagName' in attributes:
                tag_prop_buf[count].szSourceTagName = bytes(attributes['szSourceTagName'], encoding='gbk')  
                tag_ext_mask = hyperdb.get_calc_ext_mask('SourceTagName', tag_ext_mask)
        
            # mask = hyperdb.HD3Mask()
            mask[count].commmask = c_int64(comm_mask)
            mask[count].extmask = c_int64(tag_ext_mask)
            # tagmask.append(mask)
            count +=1
              
        tagids = (number *c_uint32)()
        errorcode = (number * c_int32)()
        hyperdb.api.ca3_add_tags.argtypes = [c_int32,POINTER(hyperdb.CalcTagProp), POINTER(hyperdb.HD3Mask), c_char_p,POINTER(c_uint32),POINTER(c_int32)]
        retcode = hyperdb.api.ca3_add_tags(number,tag_prop_buf, mask,None,tagids,errorcode)
        if (hyperdb.hd_sucess != retcode):
            raise hyperdb.HDError(retcode)
        return tagids
    
    '''
    ## modify CalcTags' properties
    # @param attributes: props is a list of dictionary including attributes be set to a calctag 
    # @note: the dictionary must follow special formation,such as
                    [{'tagname':'catag0',
                       'nCalcPeriod' :6,
                       'szCalcExpr': '\'srctag\'+2',
                       'descriptor':'123321'
                       },
                      {'tagname':'catag1',
                       'nCalcPeriod' :7,
                       'szCalcExpr': '\'srctag\'+3',
                       'descriptor':'234432'
                       }]
      tagname is used to confirm which tag is needed to modify
    # some properties cann't be modified,such as 'tagname'
    '''
    def modify_calc_tag_attributes(self,props):
        number = len(props)
        tag_prop_buf = (number *hyperdb.CalcTagProp)()
        tagids = (number *c_uint32)()
        count=0
        mask = (number * hyperdb.HD3Mask)()
        for attributes in props:
            comm_mask = 0
            tag_ext_mask = 0
            if 'tagid' in attributes:
                tagids[count] = attributes['tagid']
            if 'tagname' in attributes:
                tagname = attributes['tagname']
                tagids[count]=self.get_tag(tagname).tagid
            if tagids[count] == '':
                continue
            if 'descriptor' in attributes:
                tag_prop_buf[count].szDescriptor = bytes(attributes['descriptor'], encoding='utf8')  
                comm_mask = hyperdb.get_comm_mask('descriptor', comm_mask)
            
            if 'nCalcPeriod' in attributes:
                tag_prop_buf[count].nCalcPeriod = attributes['nCalcPeriod'] 
                tag_ext_mask = hyperdb.get_calc_ext_mask('nCalcPeriod', tag_ext_mask)
            if 'szCalcExpr' in attributes:
                tag_prop_buf[count].szCalcExpr = bytes(attributes['szCalcExpr'], encoding='utf8')
                tag_ext_mask = hyperdb.get_calc_ext_mask('szCalcExpr', tag_ext_mask)
                
            #mask = hyperdb.HD3Mask()
            mask[count].commmask = c_int64(comm_mask)
            mask[count].extmask = c_int64(tag_ext_mask)
            #tagmask.append(mask)
            count +=1
        errorcode = (number * c_int32)()
        hyperdb.api.ca3_modify_tags_prop.argtypes = [c_int32,POINTER(c_uint32),POINTER(hyperdb.CalcTagProp), POINTER(hyperdb.HD3Mask),POINTER(c_int32)]
        retcode = hyperdb.api.ca3_modify_tags_prop(number,tagids,tag_prop_buf, mask,errorcode)
        if (hyperdb.hd_sucess != retcode):
            raise hyperdb.HDError(retcode)
        return  hyperdb.hd_sucess
    
    
    '''
    ## modify PtTags' properties
    # @param attributes: props is a list of dictionary including attributes be set to a pt tag 
    # @note: the dictionary must follow special formation,such as
                    [{'tagname':'tag0',
                       'descriptor':'123321'
                       },
                      {'tagname':'tag1',
                       'descriptor':'234432'
                       }]
      tagname is used to confirm which tag is needed to modify
    # some properties cann't be modified,such as 'tagname'
    '''
    def modify_tags_attributes(self,props):
        number = len(props)
        tag_prop_buf = (number *hyperdb.TagProp)()
        tagids = (number *c_uint32)()
        count=0
        mask = (number * hyperdb.HD3Mask)()
        for attributes in props:
            comm_mask = 0
            tag_ext_mask = 0
            if 'tagid' in attributes:
                tagids[count] = attributes['tagid']
            if 'tagname' in attributes:
                tagname = attributes['tagname']
                tagids[count]=self.get_tag(tagname).tagid
            if  tagids[count] == '':
                continue
            #comm attributes
            if 'archiving' in attributes:
                tag_prop_buf[count].bArchiving = int(attributes['archiving']) 
                comm_mask = hyperdb.get_comm_mask('archiving', comm_mask)
                
            if 'compdev' in attributes:
                tag_prop_buf[count].fCompDev = attributes['compdev']
                comm_mask = hyperdb.get_comm_mask('compdev', comm_mask)
            if 'compmaxtime' in attributes:
                tag_prop_buf[count].nCompMaxTime = attributes['compmaxtime']
                comm_mask = hyperdb.get_comm_mask('compmaxtime', comm_mask)          
            if 'comptype' in attributes:
                tag_prop_buf[count].nCompType = attributes['comptype']
                comm_mask = hyperdb.get_comm_mask('comptype', comm_mask)
                
            if 'recaccess' in attributes:
                tag_prop_buf[count].nRecAccess = attributes['recaccess'] 
                comm_mask = hyperdb.get_comm_mask('recaccess', comm_mask)
            if 'recnormalgroup' in attributes:
                tag_prop_buf[count].szRecNormalGroup = attributes['recnormalgroup']  
                comm_mask = hyperdb.get_comm_mask('recnormalgroup', comm_mask)
            if 'recownergroup' in attributes:
                tag_prop_buf[count].szRecOwnerGroup = attributes['recownergroup']  
                comm_mask = hyperdb.get_comm_mask('recownergroup', comm_mask)
                
            if 'descriptor' in attributes:
                tag_prop_buf[count].szDescriptor = bytes(attributes['descriptor'], encoding='gbk')    
                comm_mask = hyperdb.get_comm_mask('descriptor', comm_mask)
            if 'digitalset' in attributes:
                tag_prop_buf[count].szDigitalSet = attributes['digitalset']  
                comm_mask = hyperdb.get_comm_mask('digitalset', comm_mask)
            if 'engunit' in attributes:
                tag_prop_buf[count].szEngUnits = bytes(attributes['engunit'], encoding='gbk')  
                comm_mask = hyperdb.get_comm_mask('engunit', comm_mask)    
            if 'excmaxtime' in attributes:
                tag_prop_buf[count].fExcMaxTime = attributes['excmaxtime']
                comm_mask = hyperdb.get_comm_mask('excmaxtime', comm_mask)
            if 'excdev' in attributes:
                tag_prop_buf[count].fExcDev = attributes['excdev']
                comm_mask = hyperdb.get_comm_mask('excdev', comm_mask)
                
            if 'tagaccess' in attributes:
                tag_prop_buf[count].nTagAccess = attributes['tagaccess']
                comm_mask = hyperdb.get_comm_mask('tagaccess', comm_mask)
            if 'tagnormalgroup' in attributes:
                tag_prop_buf[count].szTagNormalGroup = attributes['tagnormalgroup']  
                comm_mask = hyperdb.get_comm_mask('tagnormalgroup', comm_mask)
            if 'tagownergroup' in attributes:
                tag_prop_buf[count].szTagOwnerGroup = attributes['tagownergroup']  
                comm_mask = hyperdb.get_comm_mask('tagownergroup', comm_mask)
                
            if 'scan' in attributes:
                tag_prop_buf[count].bScan = attributes['scan']
                comm_mask = hyperdb.get_comm_mask('scan', comm_mask)
            if 'span' in attributes:
                tag_prop_buf[count].fSpan = attributes['span']
                comm_mask = hyperdb.get_comm_mask('span', comm_mask)  
            if 'minvalue' in attributes:
                tag_prop_buf[count].fMinValue = attributes['minvalue'] 
                comm_mask = hyperdb.get_comm_mask('minvalue', comm_mask)
                
            if 'tagavaliable' in attributes:
                tag_prop_buf[count].nTagAvaliable = attributes['tagavaliable']
                comm_mask = hyperdb.get_comm_mask('tagavaliable', comm_mask)  
            if 'opcstate' in attributes:
                tag_prop_buf[count].nOpcRelease = attributes['opcstate'] 
                comm_mask = hyperdb.get_comm_mask('opcstate', comm_mask)
            
            if 'imvstring' in attributes:
                tag_prop_buf[count].szImvString = attributes['imvstring'] 
                comm_mask = hyperdb.get_comm_mask('imvstring', comm_mask)
                
            if 'extstring1' in attributes:
                tag_prop_buf[count].szExtString1 = attributes['extstring1'] 
                comm_mask = hyperdb.get_comm_mask('extstring1', comm_mask)
            
            if 'extstring2' in attributes:
                tag_prop_buf[count].szExtString2 = attributes['extstring2'] 
                comm_mask = hyperdb.get_comm_mask('extstring2', comm_mask)
                
            if 'param1' in attributes:
                tag_prop_buf[count].nParam1 = attributes['param1']
                comm_mask = hyperdb.get_comm_mask('param1', comm_mask)
            if 'param2' in attributes:
                tag_prop_buf[count].nParam2 = attributes['param2']
                comm_mask = hyperdb.get_comm_mask('param2', comm_mask)
            if 'param3' in attributes:
                tag_prop_buf[count].nParam3 = attributes['param3']
                comm_mask = hyperdb.get_comm_mask('param3', comm_mask)
            if 'param4' in attributes:
                tag_prop_buf[count].nParam4 = attributes['param4']
                comm_mask = hyperdb.get_comm_mask('param4', comm_mask)
            if 'param5' in attributes:
                tag_prop_buf[count].nParam5 = attributes['param5']
                comm_mask = hyperdb.get_comm_mask('param5', comm_mask)
            
            
            # ext attributes            
            if 'instrumentaddress' in attributes:
                tag_prop_buf[count].szInstrumentPoint = attributes['instrumentaddress']  
                tag_ext_mask = hyperdb.get_tag_ext_mask('instrumentaddress', tag_ext_mask)  
            if 'instrumentaddresstype' in attributes:
                tag_prop_buf[count].szInstrumnetPointtype = attributes['instrumentaddresstype'] 
                tag_ext_mask = hyperdb.get_tag_ext_mask('instrumentaddresstype', tag_ext_mask)
            if 'collectorname' in attributes:
                tag_prop_buf[count].szCollectorName = attributes['collectorname']  
                tag_ext_mask = hyperdb.get_tag_ext_mask('collectorname', tag_ext_mask)
                
            if 'devicename' in attributes:
                tag_prop_buf[count].szDeviceName = attributes['devicename']  
                tag_ext_mask = hyperdb.get_tag_ext_mask('devicename', tag_ext_mask)
                
            if 'scangroupname' in attributes:
                tag_prop_buf[count].szScanGroupName = attributes['scangroupname']  
                tag_ext_mask = hyperdb.get_tag_ext_mask('scangroupname', tag_ext_mask)
                
            if 'dataorder' in attributes:
                tag_prop_buf[count].szScanGroupName = attributes['dataorder']  
                tag_ext_mask = hyperdb.get_tag_ext_mask('dataorder', tag_ext_mask)
                
                
            #mask = hyperdb.HD3Mask()
            mask[count].commmask = c_int64(comm_mask)
            mask[count].extmask = c_int64(tag_ext_mask)
            #tagmask.append(mask)
            count +=1
        errorcode = (number * c_int32)()
        hyperdb.api.pt3_modify_tags_prop.argtypes = [c_int32,POINTER(c_uint32),POINTER(hyperdb.TagProp), POINTER(hyperdb.HD3Mask),POINTER(c_int32)]
        retcode = hyperdb.api.pt3_modify_tags_prop(number,tagids,tag_prop_buf, mask,errorcode)
        if (hyperdb.hd_sucess != retcode):
            raise hyperdb.HDError(retcode)
        return hyperdb.hd_sucess
    
    
    '''
    # query calctags which satisfy the conditions
    # @param conds: the conditions used to query calctags which satisfied with ,such as
    [('tagname','like','*')]
    # @return: return a iterator of calctags
    '''
    def query_calc_tags_cond(self, conds):
        number = len(conds)
        conds_buf = (number * hyperdb.HD3FilterItem)()
        condset = hyperdb.HD3FilterItemSet()
       
        count = 0
        for cond in conds:
            try:
                conds_buf[count].nPropItemID = hyperdb.tag_col_dict[cond[0]]
                conds_buf[count].nRelation = hyperdb.relation_dict[cond[1]]
                if cond[0] == 'tagtype':
                    conds_buf[count].szValue = bytes(str(hyperdb.tag_type_dict[cond[2]]), encoding='utf8')  
                else:
                    conds_buf[count].szValue = bytes(cond[2], encoding='utf8')
            except KeyError:
                raise hyperdb.HDError(errcode = 0, errinfo = 'the key is not exist!')

            count = count + 1

        condset.nSize = c_int32(number)
        condset.pItem = conds_buf
        
        hditer = c_void_p()   
        mask = hyperdb.HD3Mask()
        mask.commmask = c_int64(0XFFFFFFFFFFFFFFFF)
        mask.extmask = c_int64(0XFFFFFFFFFFFFFFFF)
        
        hyperdb.api.ca3_query_tags_cond.argtypes = [POINTER(hyperdb.HD3FilterItemSet), POINTER(hyperdb.HD3Mask), POINTER(c_void_p)]
        retcode = hyperdb.api.ca3_query_tags_cond(byref(condset), byref(mask), byref(hditer))
        if hyperdb.hd_sucess != retcode:
            raise hyperdb.HDError(retcode)
        
        tag_prop = hyperdb.CalcTagProp()
        iterate = hyperdb.Iterate(hditer, tag_prop)
        return iterate
    
    
    ''' 
    # add a list of new statstags to server
    # @param props: a list of dictionary, such as 
                    [{'tagname': 'sttag0',
                      'tagtype': 'float64',
                     'szSourceTagName':'srctag',
                     'nSampleStartDate': 0,
                     'nSampleInterval':10,
                     'nSampleMode':0,
                     'nStatsType': 0,
                     'nCalcPeriod':1,
                     'nScanPeriod':10,
                     'nSampleType':0,
                     'nSampleStartDate':1
                     },{'tagname': 'sttag1',
                      'tagtype': 'float64',
                     'szSourceTagName':'srctag',
                     'nSampleStartDate': 0,
                     'nSampleInterval':10,
                     'nSampleMode':0,
                     'nStatsType': 0,
                     'nCalcPeriod':2,
                     'nScanPeriod':10,
                     'nSampleType':0,
                     'nSampleStartDate':1
                     }]
    # @note: the input dictionary attributes should include para of StatsTagProp
    # seen in tag.py
    '''
    def add_stats_tags(self, props): 
        number = len(props)
        tag_prop_buf = (number *hyperdb.StatsTagProp)()
        
        count=0
        mask = (number * hyperdb.HD3Mask)()
        for attributes in props:
            if 'tagname' not in attributes or 'tagtype' not in attributes:
                raise ArgumentError
        
            comm_mask = 0
            tag_ext_mask = 0
        
            tag_prop_buf[count].szTagName = bytes(attributes['tagname'], encoding='utf8')  
            if not tag_prop_buf[count].szTagName.strip():
                raise ArgumentError
            comm_mask = hyperdb.get_comm_mask('tagname', comm_mask)
        
            tag_prop_buf[count].nTagType = hyperdb.tag_type_dict[attributes['tagtype']] 
            comm_mask = hyperdb.get_comm_mask('tagtype', comm_mask)
        
            if 'archiving' in attributes:
                tag_prop_buf[count].bArchiving = attributes['archiving'] 
                comm_mask = hyperdb.get_comm_mask('archiving', comm_mask)

            if 'compdev' in attributes:
                tag_prop_buf[count].fCompDev = attributes['compdev']
                comm_mask = hyperdb.get_comm_mask('compdev', comm_mask)
            if 'compmaxtime' in attributes:
                tag_prop_buf[count].nCompMaxTime = attributes['compmaxtime']
                comm_mask = hyperdb.get_comm_mask('compmaxtime', comm_mask)          
            if 'comptype' in attributes:
                tag_prop_buf[count].nCompType = attributes['comptype']
                comm_mask = hyperdb.get_comm_mask('comptype', comm_mask)
            
            if 'recaccess' in attributes:
                tag_prop_buf[count].nRecAccess = attributes['recaccess'] 
                comm_mask = hyperdb.get_comm_mask('recaccess', comm_mask)
            if 'recnormalgroup' in attributes:
                tag_prop_buf[count].szRecNormalGroup = attributes['recnormalgroup']  
                comm_mask = hyperdb.get_comm_mask('recnormalgroup', comm_mask)
            if 'recownergroup' in attributes:
                tag_prop_buf[count].szRecOwnerGroup = attributes['recownergroup']  
                comm_mask = hyperdb.get_comm_mask('recownergroup', comm_mask)
            
            if 'descriptor' in attributes:
                tag_prop_buf[count].szDescriptor = bytes(attributes['descriptor'], encoding='utf8')  
                comm_mask = hyperdb.get_comm_mask('descriptor', comm_mask)
            if 'digitalset' in attributes:
                tag_prop_buf[count].szDigitalSet = attributes['digitalset']  
                comm_mask = hyperdb.get_comm_mask('digitalset', comm_mask)
            if 'engunit' in attributes:
                tag_prop_buf[count].szEngUnits = attributes['engunit']  
                comm_mask = hyperdb.get_comm_mask('engunit', comm_mask)    
            if 'excmaxtime' in attributes:
                tag_prop_buf[count].fExcMaxTime = attributes['excmaxtime']
                comm_mask = hyperdb.get_comm_mask('excmaxtime', comm_mask)
            if 'excdev' in attributes:
                tag_prop_buf[count].fExcDev = attributes['excdev']
                comm_mask = hyperdb.get_comm_mask('excdev', comm_mask)
            
            if 'tagaccess' in attributes:
                tag_prop_buf[count].nTagAccess = attributes['tagaccess']
                comm_mask = hyperdb.get_comm_mask('tagaccess', comm_mask)
            if 'tagnormalgroup' in attributes:
                tag_prop_buf[count].szTagNormalGroup = attributes['tagnormalgroup']  
                comm_mask = hyperdb.get_comm_mask('tagnormalgroup', comm_mask)
            if 'tagownergroup' in attributes:
                tag_prop_buf[count].szTagOwnerGroup = attributes['tagownergroup']  
                comm_mask = hyperdb.get_comm_mask('tagownergroup', comm_mask)
                
            
            if 'scan' in attributes:
                tag_prop_buf[count].bScan = attributes['scan']
                comm_mask = hyperdb.get_comm_mask('scan', comm_mask)
            if 'span' in attributes:
                tag_prop_buf[count].fSpan = attributes['span']
                comm_mask = hyperdb.get_comm_mask('span', comm_mask)  
            if 'minvalue' in attributes:
                tag_prop_buf[count].fMinValue = attributes['minvalue'] 
                comm_mask = hyperdb.get_comm_mask('minvalue', comm_mask)
            if 'tagavaliable' in attributes:
                tag_prop_buf[count].nTagAvaliable = attributes['tagavaliable']
                comm_mask = hyperdb.get_comm_mask('tagavaliable', comm_mask)   
            if 'opcstate' in attributes:
                tag_prop_buf[count].nOpcRelease = attributes['opcstate']
                comm_mask = hyperdb.get_comm_mask('opcstate', comm_mask)  

            if 'imvstring' in attributes:
                tag_prop_buf[count].szImvString = attributes['imvstring']
                comm_mask = hyperdb.get_comm_mask('imvstring', comm_mask)
            if 'extstring1' in attributes:
                tag_prop_buf[count].szExtString1 = attributes['extstring1']
                comm_mask = hyperdb.get_comm_mask('extstring1', comm_mask)
            if 'extstring2' in attributes:
                tag_prop_buf[count].szExtString2 = attributes['extstring2']
                comm_mask = hyperdb.get_comm_mask('extstring2', comm_mask)
            
            
            if 'param1' in attributes:
                tag_prop_buf[count].nParam1 = attributes['param1']
                comm_mask = hyperdb.get_comm_mask('param1', comm_mask)
            if 'param2' in attributes:
                tag_prop_buf[count].nParam2 = attributes['param2']
                comm_mask = hyperdb.get_comm_mask('param2', comm_mask)
            if 'param3' in attributes:
                tag_prop_buf[count].nParam3 = attributes['param3']
                comm_mask = hyperdb.get_comm_mask('param3', comm_mask)
            if 'param4' in attributes:
                tag_prop_buf[count].nParam4 = attributes['param4']
                comm_mask = hyperdb.get_comm_mask('param4', comm_mask)
            if 'param5' in attributes:
                tag_prop_buf[count].nParam5 = attributes['param5']
                comm_mask = hyperdb.get_comm_mask('param5', comm_mask) 

            if 'szSourceTagName' in attributes:
                tag_prop_buf[count].szSourceTagName = bytes(attributes['szSourceTagName'], encoding='utf8')  
                tag_ext_mask = hyperdb.get_stats_ext_mask('SourceTagName', tag_ext_mask)
                             
            if 'nStatsType' in attributes:
                tag_prop_buf[count].nStatsType = attributes['nStatsType']  
                tag_ext_mask = hyperdb.get_stats_ext_mask('nStatsType', tag_ext_mask)  
                
            if 'nSampleStartDate' in attributes:
                tag_prop_buf[count].nSampleStartDate = attributes['nSampleStartDate']  
                tag_ext_mask = hyperdb.get_stats_ext_mask('nSampleStartDate', tag_ext_mask)  
                
            if 'nSampleMode' in attributes:
                tag_prop_buf[count].nSampleMode = attributes['nSampleMode']
                tag_ext_mask = hyperdb.get_stats_ext_mask('nSampleMode', tag_ext_mask)
                
            if 'nSampleInterval' in attributes:
                tag_prop_buf[count].nSampleInterval = attributes['nSampleInterval']
                tag_ext_mask = hyperdb.get_stats_ext_mask('nSampleInterval', tag_ext_mask)
                
            if 'nSampleBeginOffset' in attributes:
                tag_prop_buf[count].nSampleBeginOffset = attributes['nSampleBeginOffset']
                tag_ext_mask = hyperdb.get_stats_ext_mask('nSampleBeginOffset', tag_ext_mask)
                
            if 'nSampleEndOffset' in attributes:
                tag_prop_buf[count].nSampleEndOffset = attributes['nSampleEndOffset']
                tag_ext_mask = hyperdb.get_stats_ext_mask('nSampleEndOffset', tag_ext_mask)
                
            if 'nSampleMonthBeginDay' in attributes:
                tag_prop_buf[count].nSampleMonthBeginDay = attributes['nSampleMonthBeginDay']
                tag_ext_mask = hyperdb.get_stats_ext_mask('nSampleMonthBeginDay', tag_ext_mask)
                
            if 'nSampleMonthEndDay' in attributes:
                tag_prop_buf[count].nSampleMonthEndDay = attributes['nSampleMonthEndDay']
                tag_ext_mask = hyperdb.get_stats_ext_mask('nSampleMonthEndDay', tag_ext_mask)
                
            if 'bBeginTimeStamp' in attributes:
                tag_prop_buf[count].bBeginTimeStamp = attributes['bBeginTimeStamp']
                tag_ext_mask = hyperdb.get_stats_ext_mask('bBeginTimeStamp', tag_ext_mask)
                
            if 'nTimeStampOffset' in attributes:
                tag_prop_buf[count].nTimeStampOffset = attributes['nTimeStampOffset']
                tag_ext_mask = hyperdb.get_stats_ext_mask('nTimeStampOffset', tag_ext_mask)
                
            if 'nScanPeriod' in attributes:
                tag_prop_buf[count].nScanPeriod = attributes['nScanPeriod']
                tag_ext_mask = hyperdb.get_stats_ext_mask('nScanPeriod', tag_ext_mask)
                
            if 'fPctGood' in attributes:
                tag_prop_buf[count].fPctGood = attributes['fPctGood']
                tag_ext_mask = hyperdb.get_stats_ext_mask('fPctGood', tag_ext_mask)
                
            if 'szFilterExpr' in attributes:
                tag_prop_buf[count].szFilterExpr = bytes(attributes['szFilterExpr'], encoding='utf8')
                tag_ext_mask = hyperdb.get_stats_ext_mask('szFilterExpr', tag_ext_mask)
                
            if 'nDropBadMode' in attributes:
                tag_prop_buf[count].nDropBadMode = attributes['nDropBadMode']
                tag_ext_mask = hyperdb.get_stats_ext_mask('nDropBadMode', tag_ext_mask)
                
            if 'dCountParam1' in attributes:
                tag_prop_buf[count].dCountParam1 = attributes['dCountParam1']
                tag_ext_mask = hyperdb.get_stats_ext_mask('dCountParam1', tag_ext_mask)
                
            if 'dCountParam2' in attributes:
                tag_prop_buf[count].dCountParam2 = attributes['dCountParam2']
                tag_ext_mask = hyperdb.get_stats_ext_mask('dCountParam2', tag_ext_mask)    
                
            if 'nSampleType' in attributes:
                tag_prop_buf[count].nSampleType = attributes['nSampleType']
                tag_ext_mask = hyperdb.get_stats_ext_mask('nSampleType', tag_ext_mask)    
                
            if 'nInterpOffset' in attributes:
                tag_prop_buf[count].nInterpOffset = attributes['nInterpOffset']
                tag_ext_mask = hyperdb.get_stats_ext_mask('nInterpOffset', tag_ext_mask)    
           
            if 'nInterpPeriod' in attributes:
                tag_prop_buf[count].nInterpPeriod = attributes['nInterpPeriod']
                tag_ext_mask = hyperdb.get_stats_ext_mask('nInterpPeriod', tag_ext_mask)    
            
            if 'nConversionType' in attributes:
                tag_prop_buf[count].nConversionType = attributes['nConversionType']
                tag_ext_mask = hyperdb.get_stats_ext_mask('nConversionType', tag_ext_mask)    
                
            if 'dConversion' in attributes:
                tag_prop_buf[count].dConversion = attributes['dConversion']
                tag_ext_mask = hyperdb.get_stats_ext_mask('dConversion', tag_ext_mask)    
           
            if 'nFilterFailMode' in attributes:
                tag_prop_buf[count].nFilterFailMode = attributes['nFilterFailMode']
                tag_ext_mask = hyperdb.get_stats_ext_mask('nFilterFailMode', tag_ext_mask)    
           
            if 'nCalcPeriod' in attributes:
                tag_prop_buf[count].nCalcPeriod = attributes['nCalcPeriod']
                tag_ext_mask = hyperdb.get_stats_ext_mask('nCalcPeriod', tag_ext_mask)    
           
            if 'bReset' in attributes:
                tag_prop_buf[count].bReset = attributes['bReset']
                tag_ext_mask = hyperdb.get_stats_ext_mask('bReset', tag_ext_mask) 
                
            if 'bUseBadValue' in attributes:
                tag_prop_buf[count].bUseBadValue = attributes['bUseBadValue']
                tag_ext_mask = hyperdb.get_stats_ext_mask('bUseBadValue', tag_ext_mask) 
           
            # mask = hyperdb.HD3Mask()
            mask[count].commmask = c_int64(comm_mask)
            mask[count].extmask = c_int64(tag_ext_mask)
            # tagmask.append(mask)
            count +=1
              
        tagids = (number *c_uint32)()
        errorcode = (number * c_int32)()
        hyperdb.api.st3_add_tags.argtypes = [c_int32,POINTER(hyperdb.StatsTagProp), POINTER(hyperdb.HD3Mask), c_char_p,POINTER(c_uint32),POINTER(c_int32)]
        retcode = hyperdb.api.st3_add_tags(number,tag_prop_buf, mask,None,tagids,errorcode)
        if (hyperdb.hd_sucess != retcode):
            raise hyperdb.HDError(retcode)
        return tagids
    
     
    
    '''
    ## modify StatsTags' properties
    # @param attributes: props is a list of dictionary including attributes be set to a statstag 
    # @note: the dictionary must follow special formation,such as
                    [{'tagname':'sttag0',
                       'descriptor' :'123',
                       },
                      {'tagname':'sttag1',
                       'descriptor' :'234',
                       }]
      tagname is used to confirm which tag is needed to modify
    # some properties cann't be modified,such as 'tagname'
    '''
    def modify_stats_tag_attributes(self,props):
        number = len(props)
        tag_prop_buf = (number *hyperdb.StatsTagProp)()
        tagids = (number *c_uint32)()
        count=0
        mask = (number * hyperdb.HD3Mask)()
        for attributes in props:
            comm_mask = 0
            tag_ext_mask = 0
            if 'tagid' in attributes:
                tagids[count] = attributes['tagid']
            if 'tagname' in attributes:
                tagname = attributes['tagname']
                tagids[count]=self.get_tag(tagname).tagid
            if tagids[count] == '':
                continue
            
            if 'descriptor' in attributes:
                tag_prop_buf[count].szDescriptor = bytes(attributes['descriptor'], encoding='utf8')  
                comm_mask = hyperdb.get_comm_mask('descriptor', comm_mask)

            #mask = hyperdb.HD3Mask()
            mask[count].commmask = c_int64(comm_mask)
            mask[count].extmask = c_int64(tag_ext_mask)
            #tagmask.append(mask)
            count +=1
        errorcode = (number * c_int32)()
        hyperdb.api.st3_modify_tags_prop.argtypes = [c_int32,POINTER(c_uint32),POINTER(hyperdb.StatsTagProp), POINTER(hyperdb.HD3Mask),POINTER(c_int32)]
        retcode = hyperdb.api.st3_modify_tags_prop(number,tagids,tag_prop_buf, mask,errorcode)
        if (hyperdb.hd_sucess != retcode):
            raise hyperdb.HDError(retcode)
        return hyperdb.hd_sucess
    
    
    '''
    # query statstags which satisfy the conditions
    # @param conds: the conditions used to query statstags which satisfied with ,such as
    [('tagname','like','*')]
    # @return: return a iterator of statstags
    '''
    def query_stats_tags_cond(self, conds):
        number = len(conds)
        conds_buf = (number * hyperdb.HD3FilterItem)()
        condset = hyperdb.HD3FilterItemSet()
       
        count = 0
        for cond in conds:
            try:
                conds_buf[count].nPropItemID = hyperdb.tag_col_dict[cond[0]]
                conds_buf[count].nRelation = hyperdb.relation_dict[cond[1]]
                if cond[0] == 'tagtype':
                    conds_buf[count].szValue = bytes(str(hyperdb.tag_type_dict[cond[2]]), encoding='utf8')
                else:
                    conds_buf[count].szValue = bytes(cond[2], encoding='utf8')
            except KeyError:
                raise hyperdb.HDError(errcode = 0, errinfo = 'the key is not exist!')

            count = count + 1

        condset.nSize = c_int32(number)
        condset.pItem = conds_buf
        
        hditer = c_void_p()   
        mask = hyperdb.HD3Mask()
        mask.commmask = c_int64(0XFFFFFFFFFFFFFFFF)
        mask.extmask = c_int64(0XFFFFFFFFFFFFFFFF)
        
        hyperdb.api.st3_query_tags_cond.argtypes = [POINTER(hyperdb.HD3FilterItemSet), POINTER(hyperdb.HD3Mask), POINTER(c_void_p)]
        retcode = hyperdb.api.st3_query_tags_cond(byref(condset), byref(mask), byref(hditer))
        if hyperdb.hd_sucess != retcode:
            raise hyperdb.HDError(retcode)
        
        tag_prop = hyperdb.StatsTagProp()
        iterate = hyperdb.Iterate(hditer, tag_prop)
        return iterate
     
    ''' 
    # add a list of new alarm tags to server
    # @param props: a list of dictionary, such as 
                    [{'tagname': 'amtag0',
                      'tagtype': 'int32',
                      'sourcetagname': 'int8'
                     },{'tagname': 'amtag1',
                      'tagtype': 'int32',
                      'sourcetagname': 'int8'
                     }]
    # @note: the input dictionary attributes should include param of AlarmTagProp
    # seen in tag.py
    '''
    def add_alarm_tags(self, props): 
        number = len(props)
        tag_prop_buf = (number *hyperdb.AlarmTagProp)()
        
        count=0
        mask = (number * hyperdb.HD3Mask)()
        for attributes in props:
            if 'tagname' not in attributes:
                raise ArgumentError
        
            comm_mask = 0
            tag_ext_mask = 0
        
            tag_prop_buf[count].szTagName = bytes(attributes['tagname'], encoding='utf8')
            if not tag_prop_buf[count].szTagName.strip():
                raise ArgumentError
            comm_mask = hyperdb.get_comm_mask('tagname', comm_mask)
        
            tag_prop_buf[count].nTagType = 5 #digital
            comm_mask = hyperdb.get_comm_mask('tagtype', comm_mask)
        
            if 'archiving' in attributes:
                tag_prop_buf[count].bArchiving = attributes['archiving'] 
                comm_mask = hyperdb.get_comm_mask('archiving', comm_mask)

            if 'compdev' in attributes:
                tag_prop_buf[count].fCompDev = attributes['compdev']
                comm_mask = hyperdb.get_comm_mask('compdev', comm_mask)
            if 'compmaxtime' in attributes:
                tag_prop_buf[count].nCompMaxTime = attributes['compmaxtime']
                comm_mask = hyperdb.get_comm_mask('compmaxtime', comm_mask)          
            if 'comptype' in attributes:
                tag_prop_buf[count].nCompType = attributes['comptype']
                comm_mask = hyperdb.get_comm_mask('comptype', comm_mask)
            
            if 'recaccess' in attributes:
                tag_prop_buf[count].nRecAccess = attributes['recaccess'] 
                comm_mask = hyperdb.get_comm_mask('recaccess', comm_mask)
            if 'recnormalgroup' in attributes:
                tag_prop_buf[count].szRecNormalGroup = attributes['recnormalgroup']  
                comm_mask = hyperdb.get_comm_mask('recnormalgroup', comm_mask)
            if 'recownergroup' in attributes:
                tag_prop_buf[count].szRecOwnerGroup = attributes['recownergroup']  
                comm_mask = hyperdb.get_comm_mask('recownergroup', comm_mask)
            
            if 'descriptor' in attributes:
                tag_prop_buf[count].szDescriptor = bytes(attributes['descriptor'], encoding='utf8')  
                comm_mask = hyperdb.get_comm_mask('descriptor', comm_mask)
            if 'digitalset' in attributes:
                tag_prop_buf[count].szDigitalSet = attributes['digitalset']  
                comm_mask = hyperdb.get_comm_mask('digitalset', comm_mask)
            if 'engunit' in attributes:
                tag_prop_buf[count].szEngUnits = attributes['engunit']  
                comm_mask = hyperdb.get_comm_mask('engunit', comm_mask)    
            if 'excmaxtime' in attributes:
                tag_prop_buf[count].fExcMaxTime = attributes['excmaxtime']
                comm_mask = hyperdb.get_comm_mask('excmaxtime', comm_mask)
            if 'excdev' in attributes:
                tag_prop_buf[count].fExcDev = attributes['excdev']
                comm_mask = hyperdb.get_comm_mask('excdev', comm_mask)
            
            if 'tagaccess' in attributes:
                tag_prop_buf[count].nTagAccess = attributes['tagaccess']
                comm_mask = hyperdb.get_comm_mask('tagaccess', comm_mask)
            if 'tagnormalgroup' in attributes:
                tag_prop_buf[count].szTagNormalGroup = attributes['tagnormalgroup']  
                comm_mask = hyperdb.get_comm_mask('tagnormalgroup', comm_mask)
            if 'tagownergroup' in attributes:
                tag_prop_buf[count].szTagOwnerGroup = attributes['tagownergroup']  
                comm_mask = hyperdb.get_comm_mask('tagownergroup', comm_mask)
                
            
            if 'scan' in attributes:
                tag_prop_buf[count].bScan = attributes['scan']
                comm_mask = hyperdb.get_comm_mask('scan', comm_mask)
            if 'span' in attributes:
                tag_prop_buf[count].fSpan = attributes['span']
                comm_mask = hyperdb.get_comm_mask('span', comm_mask)  
            if 'minvalue' in attributes:
                tag_prop_buf[count].fMinValue = attributes['minvalue'] 
                comm_mask = hyperdb.get_comm_mask('minvalue', comm_mask)
            if 'tagavaliable' in attributes:
                tag_prop_buf[count].nTagAvaliable = attributes['tagavaliable']
                comm_mask = hyperdb.get_comm_mask('tagavaliable', comm_mask)   
            if 'opcstate' in attributes:
                tag_prop_buf[count].nOpcRelease = attributes['opcstate']
                comm_mask = hyperdb.get_comm_mask('opcstate', comm_mask)  

            if 'imvstring' in attributes:
                tag_prop_buf[count].szImvString = attributes['imvstring']
                comm_mask = hyperdb.get_comm_mask('imvstring', comm_mask)
            if 'extstring1' in attributes:
                tag_prop_buf[count].szExtString1 = attributes['extstring1']
                comm_mask = hyperdb.get_comm_mask('extstring1', comm_mask)
            if 'extstring2' in attributes:
                tag_prop_buf[count].szExtString2 = attributes['extstring2']
                comm_mask = hyperdb.get_comm_mask('extstring2', comm_mask)
            
            # ������չ����    
            if 'test1' in attributes:
                tag_prop_buf[count].szTest1 = bytes(attributes['test1'] , encoding='utf8')   
                tag_ext_mask = hyperdb.get_alarm_ext_mask('test1', tag_ext_mask)  
            if 'test2' in attributes:
                tag_prop_buf[count].szTest2 = bytes(attributes['test2'], encoding='utf8')    
                tag_ext_mask = hyperdb.get_alarm_ext_mask('test2', tag_ext_mask)
            if 'test3' in attributes:
                tag_prop_buf[count].szTest3 = bytes(attributes['test3'], encoding='utf8')    
                tag_ext_mask = hyperdb.get_alarm_ext_mask('test3', tag_ext_mask)
            if 'test4' in attributes:
                tag_prop_buf[count].szTest4 = bytes(attributes['test4'], encoding='utf8')    
                tag_ext_mask = hyperdb.get_alarm_ext_mask('test4', tag_ext_mask)
            
            if 'action1' in attributes:
                tag_prop_buf[count].szAction1 = bytes(attributes['action1'], encoding='utf8')    
                tag_ext_mask = hyperdb.get_alarm_ext_mask('action1', tag_ext_mask)
            if 'action2' in attributes:
                tag_prop_buf[count].szAction2 = bytes(attributes['action2'], encoding='utf8')    
                tag_ext_mask = hyperdb.get_alarm_ext_mask('action2', tag_ext_mask)
            if 'action3' in attributes:
                tag_prop_buf[count].szAction3 = bytes(attributes['action3'], encoding='utf8')    
                tag_ext_mask = hyperdb.get_alarm_ext_mask('action3', tag_ext_mask)
            if 'action4' in attributes:
                tag_prop_buf[count].szAction4 = bytes(attributes['action4'], encoding='utf8')   
                tag_ext_mask = hyperdb.get_alarm_ext_mask('action4', tag_ext_mask)            
            
            if 'sourcetagname' in attributes:
                tag_prop_buf[count].szSourceTagName = bytes(attributes['sourcetagname'], encoding='utf8')  
                tag_ext_mask = hyperdb.get_alarm_ext_mask('sourcetagname', tag_ext_mask)
            if 'alarmgroupid' in attributes:
                tag_prop_buf[count].nAlarmGroupID = attributes['alarmgroupid']
                tag_ext_mask = hyperdb.get_alarm_ext_mask('alarmgroupid', tag_ext_mask)
            if 'autoack' in attributes:
                tag_prop_buf[count].nAutoAck = attributes['autoack']
                tag_ext_mask = hyperdb.get_alarm_ext_mask('autoack', tag_ext_mask)  
            if 'timedeadband' in attributes:
                tag_prop_buf[count].nTimeDeadBand = attributes['timedeadband']
                tag_ext_mask = hyperdb.get_alarm_ext_mask('timedeadband', tag_ext_mask)  
            if 'valuedeadband' in attributes:
                tag_prop_buf[count].fValueDeadBand = attributes['valuedeadband']
                tag_ext_mask = hyperdb.get_alarm_ext_mask('valuedeadband', tag_ext_mask) 
               
            # mask = hyperdb.HD3Mask()
            mask[count].commmask = c_int64(comm_mask)
            mask[count].extmask = c_int64(tag_ext_mask)
            # tagmask.append(mask)
            count +=1
              
        tagids = (number *c_uint32)()
        errorcode = (number * c_int32)()
        hyperdb.api.am3_add_tags.argtypes = [c_int32,POINTER(hyperdb.AlarmTagProp), POINTER(hyperdb.HD3Mask), c_char_p,POINTER(c_uint32),POINTER(c_int32)]
        retcode = hyperdb.api.am3_add_tags(number,tag_prop_buf, mask,None,tagids,errorcode)
        if (hyperdb.hd_sucess != retcode):
            raise hyperdb.HDError(retcode)
        return tagids
    
    
    def modify_alarm_tags_attributes(self,props):
        number = len(props)
        tag_prop_buf = (number *hyperdb.AlarmTagProp)()
        tagids = (number *c_uint32)()
        count=0
        mask = (number * hyperdb.HD3Mask)()
        for attributes in props:
            comm_mask = 0
            ext_mask = 0
            if 'tagid' in attributes:
                tagids[count] = attributes['tagid']
            if 'tagname' in attributes:
                tagname = attributes['tagname']
                tagids[count]=self.get_tag(tagname).tagid
            if tagids[count] == '':
                continue
            
                
            if 'recaccess' in attributes:
                tag_prop_buf[count].nRecAccess = attributes['recaccess'] 
                comm_mask = hyperdb.get_comm_mask('recaccess', comm_mask)
            if 'recnormalgroup' in attributes:
                tag_prop_buf[count].szRecNormalGroup = attributes['recnormalgroup']  
                comm_mask = hyperdb.get_comm_mask('recnormalgroup', comm_mask)
            if 'recownergroup' in attributes:
                tag_prop_buf[count].szRecOwnerGroup = attributes['recownergroup']  
                comm_mask = hyperdb.get_comm_mask('recownergroup', comm_mask)
                
            if 'descriptor' in attributes:
                tag_prop_buf[count].szDescriptor = bytes(attributes['descriptor'], encoding='utf8')    
                comm_mask = hyperdb.get_comm_mask('descriptor', comm_mask)
           
            if 'engunit' in attributes:
                tag_prop_buf[count].szEngUnits = attributes['engunit']  
                comm_mask = hyperdb.get_comm_mask('engunit', comm_mask)    
            if 'excmaxtime' in attributes:
                tag_prop_buf[count].fExcMaxTime = attributes['excmaxtime']
                comm_mask = hyperdb.get_comm_mask('excmaxtime', comm_mask)
            if 'excdev' in attributes:
                tag_prop_buf[count].fExcDev = attributes['excdev']
                comm_mask = hyperdb.get_comm_mask('excdev', comm_mask)
                
            if 'tagaccess' in attributes:
                tag_prop_buf[count].nTagAccess = attributes['tagaccess']
                comm_mask = hyperdb.get_comm_mask('tagaccess', comm_mask)
            if 'tagnormalgroup' in attributes:
                tag_prop_buf[count].szTagNormalGroup = attributes['tagnormalgroup']  
                comm_mask = hyperdb.get_comm_mask('tagnormalgroup', comm_mask)
            if 'tagownergroup' in attributes:
                tag_prop_buf[count].szTagOwnerGroup = attributes['tagownergroup']  
                comm_mask = hyperdb.get_comm_mask('tagownergroup', comm_mask)
                
            if 'imvstring' in attributes:
                tag_prop_buf[count].szImvString = attributes['imvstring'] 
                comm_mask = hyperdb.get_comm_mask('imvstring', comm_mask)
            if 'extstring1' in attributes:
                tag_prop_buf[count].szExtString1 = attributes['extstring1'] 
                comm_mask = hyperdb.get_comm_mask('extstring1', comm_mask)
            if 'extstring2' in attributes:
                tag_prop_buf[count].szExtString2 = attributes['extstring2'] 
                comm_mask = hyperdb.get_comm_mask('extstring2', comm_mask)                
                
            
            #��������չ����    
            if 'test1' in attributes:
                tag_prop_buf[count].szTest1 = bytes(attributes['test1'], encoding='utf8')    
                ext_mask = hyperdb.get_alarm_ext_mask('test1', ext_mask)  
            if 'test2' in attributes:
                tag_prop_buf[count].szTest2 = bytes(attributes['test2'], encoding='utf8')   
                ext_mask = hyperdb.get_alarm_ext_mask('test2', ext_mask)
            if 'test3' in attributes:
                tag_prop_buf[count].szTest3 = bytes(attributes['test3'], encoding='utf8')    
                ext_mask = hyperdb.get_alarm_ext_mask('test3', ext_mask)
            if 'test4' in attributes:
                tag_prop_buf[count].szTest4 = bytes(attributes['test4'], encoding='utf8')    
                ext_mask = hyperdb.get_alarm_ext_mask('test4', ext_mask)
                
            if 'action1' in attributes:
                tag_prop_buf[count].szAction1 = bytes(attributes['action1'], encoding='utf8')    
                ext_mask = hyperdb.get_alarm_ext_mask('action1', ext_mask) 
            if 'action2' in attributes:
                tag_prop_buf[count].szAction2 = bytes(attributes['action2'], encoding='utf8')    
                ext_mask = hyperdb.get_alarm_ext_mask('action2', ext_mask)               
            if 'action3' in attributes:
                tag_prop_buf[count].szAction3 = bytes(attributes['action3'], encoding='utf8')    
                ext_mask = hyperdb.get_alarm_ext_mask('action3', ext_mask)            
            if 'action4' in attributes:
                tag_prop_buf[count].szAction4 = bytes(attributes['action4'], encoding='utf8')    
                ext_mask = hyperdb.get_alarm_ext_mask('action4', ext_mask)
                
            if 'alarmgroupid' in attributes:
                tag_prop_buf[count].nAlarmGroupID = attributes['alarmgroupid']
                ext_mask = hyperdb.get_alarm_ext_mask('alarmgroupid', ext_mask)
            if 'autoack' in attributes:
                tag_prop_buf[count].nAutoAck = attributes['autoack']
                ext_mask = hyperdb.get_alarm_ext_mask('autoack', ext_mask)  
            if 'timedeadband' in attributes:
                tag_prop_buf[count].timedeadband = attributes['timedeadband']
                ext_mask = hyperdb.get_alarm_ext_mask('timedeadband', ext_mask)  
            if 'valuedeadband' in attributes:
                tag_prop_buf[count].valuedeadband = attributes['valuedeadband']
                ext_mask = hyperdb.get_alarm_ext_mask('valuedeadband', ext_mask)            

            #mask = hyperdb.HD3Mask()
            mask[count].commmask = c_int64(comm_mask)
            mask[count].extmask = c_int64(ext_mask)
            #tagmask.append(mask)
            count +=1
        errorcode = (number * c_int32)()
        hyperdb.api.am3_modify_tags_prop.argtypes = [c_int32,POINTER(c_uint32),POINTER(hyperdb.AlarmTagProp), POINTER(hyperdb.HD3Mask),POINTER(c_int32)]
        retcode = hyperdb.api.am3_modify_tags_prop(number,tagids,tag_prop_buf, mask,errorcode)
        if (hyperdb.hd_sucess != retcode):
            raise hyperdb.HDError(retcode)
        return hyperdb.hd_sucess
    
          
    def query_alarm_tags_cond(self, conds):
        number = len(conds)
        conds_buf = (number * hyperdb.HD3FilterItem)()
        condset = hyperdb.HD3FilterItemSet()
        
        count = 0
        for cond in conds:
            try:
                conds_buf[count].nPropItemID = hyperdb.tag_col_dict[cond[0]]
                conds_buf[count].nRelation = hyperdb.relation_dict[cond[1]]
                conds_buf[count].szValue = bytes(cond[2], encoding='utf8')  
            except KeyError:
                raise hyperdb.HDError(errcode = 0, errinfo = 'the key is not exist!')            
            count = count + 1
        condset.nSize = c_int32(number)
        condset.pItem = conds_buf
        
        hditer = c_void_p() 
        mask = hyperdb.HD3Mask()
        mask.commmask = c_int64(0XFFFFFFFFFFFFFFFF)
        mask.extmask = c_int64(0XFFFFFFFFFFFFFFFF)
          
        hyperdb.api.am3_query_tags_cond.argtypes = [POINTER(hyperdb.HD3FilterItemSet), POINTER(hyperdb.HD3Mask), POINTER(c_void_p)]
        retcode = hyperdb.api.am3_query_tags_cond(byref(condset),byref(mask), byref(hditer))
        if hyperdb.hd_sucess != retcode:
            raise hyperdb.HDError(retcode)
        
        tag_prop = hyperdb.AlarmTagProp()
        iterate = hyperdb.Iterate(hditer, tag_prop)
        return iterate
    
#    def register_client(self):
#        retcode = hyperdb.api.am3_register_alarm_record_info(hyperdb.func)
#        if hyperdb.hd_sucess != retcode:
#            raise hyperdb.HDError(retcode)        

    
        
