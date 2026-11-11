#!/usr/bin/env python
# -*- coding: utf-8 -*-

from ctypes import *
from ihdSDK import hyperdb
from ihdSDK import security
import sys


## SecurityMgr is a operator class through which programmers can use to do all
# operators about trust and security.
# @note Programmers needn't create a SecurityMgr object. Instead, SecurityMgr object
# can be accessed from Server class
class SecurityMgr(object):

    #get tag security
    #@return: return a instance of the Security class
    def get_tag_security(self):
        itemtype = 2     # 2 means query tag
        secitem_buf = hyperdb.HD3SecItem()
        hyperdb.api.sc3_query_manage_security.argtypes = [c_int32, POINTER(hyperdb.HD3SecItem)]
        retcode = hyperdb.api.sc3_query_manage_security(itemtype, byref(secitem_buf))
        if hyperdb.hd_sucess != retcode:
            raise hyperdb.HDError(retcode)
        
        ownergroupname = secitem_buf.szOwnGroupName.decoding(sys.stdin.encoding)
        operategroupname = secitem_buf.szOperateGroupName.decoding(sys.stdin.encoding)
        secitem = security.Security(ownergroupname, operategroupname, secitem_buf.nSecurity)
        
        return secitem
    
    #get group security
    #@return: return a instance of the Security class
    def get_group_security(self):
        itemtype = 3     # 3 means query group
        secitem_buf = hyperdb.HD3SecItem()
        hyperdb.api.sc3_query_manage_security.argtypes = [c_int32, POINTER(hyperdb.HD3SecItem)]
        retcode = hyperdb.api.sc3_query_manage_security(itemtype, byref(secitem_buf))
        if hyperdb.hd_sucess != retcode:
            raise hyperdb.HDError(retcode)
        
        ownergroupname = secitem_buf.szOwnGroupName.decoding(sys.stdin.encoding)
        operategroupname = secitem_buf.szOperateGroupName.decoding(sys.stdin.encoding)
        secitem = security.Security(ownergroupname, operategroupname, secitem_buf.nSecurity)
        
        return secitem    
    
    #modify a tag security
    #@param secitem: input a instance of the Security class
    def modify_tag_security(self, secitem):
        itemtype = 0     # 0 means modify tag
        if True != isinstance(secitem, security.Security):
            raise TypeError
        
        hdsecitem = hyperdb.HD3SecItem()
        hdsecitem.szOwnGroupName = secitem.owngroupname 
        hdsecitem.szOperateGroupName = secitem.operategroupname 
        hdsecitem.nSecurity = secitem.securitylevel
        
        hyperdb.api.sc3_modify_manage_security.argtypes = [c_int32, POINTER(hyperdb.HD3SecItem)]
        retcode = hyperdb.api.sc3_modify_manage_security(itemtype, byref(hdsecitem))
        if hyperdb.hd_sucess != retcode:
            raise hyperdb.HDError(retcode)

    #modify a group security
    #@param secitem: input a instance of the Security class        
    def modify_group_security(self, secitem):
        itemtype = 1     # 1 means modify group
        if True != isinstance(secitem, security.Security):
            raise TypeError
        
        hdsecitem = hyperdb.HD3SecItem()
        hdsecitem.szOwnGroupName = secitem.owngroupname 
        hdsecitem.szOperateGroupName = secitem.operategroupname 
        hdsecitem.nSecurity = secitem.securitylevel
        
        hyperdb.api.sc3_modify_manage_security.argtypes = [c_int32, POINTER(hyperdb.HD3SecItem)]
        retcode = hyperdb.api.sc3_modify_manage_security(itemtype, byref(hdsecitem))
        if hyperdb.hd_sucess != retcode:
            raise hyperdb.HDError(retcode)


    ## add a new trust to the server
    # @param name    trust name
    # @param startip     start ip 
    # @param endip       endip
    # @param username    the user which trust mappped
    # @note the range between the start ip and end ip cann't be across with other trusts
    def add_trust(self, name, startip, endip, username):       
        if type(name) != str or type(startip) != str:
            raise TypeError
        if type(endip) != str or type(username) != str:
            raise TypeError
            
        name_buf = name
        startip_buf = startip
        endip_buf = endip
        username_buf = username
        sectrust_buf = hyperdb.HD3SecTrust(name_buf, startip_buf, endip_buf, username_buf)
        
        hyperdb.api.sc3_add_trust.argtypes = [POINTER(hyperdb.HD3SecTrust)]
        retcode = hyperdb.api.sc3_add_trust(byref(sectrust_buf))
        if (hyperdb.hd_sucess != retcode):
            raise hyperdb.HDError(retcode)
    
    ## Delete a trust from the server
    # @param name  trust name
    def delete_trust(self, name): 
        if type(name) != str:
            raise TypeError

        name_buf = name
        
        hyperdb.api.sc3_delete_trust.argtypes = [c_char_p]
        retcode = hyperdb.api.sc3_delete_trust(name_buf)
        if (hyperdb.hd_sucess != retcode):
            raise hyperdb.HDError(retcode)       

    ## Get all trusts from a server
    # @return  a iterate of trusts
    def get_all_trusts(self):
        hdsectrust = hyperdb.HD3SecTrust()
        hditer = c_void_p()
        
        hyperdb.api.sc3_query_all_trusts.argtypes = [POINTER(c_void_p)]  
        retcode = hyperdb.api.sc3_query_all_trusts(byref(hditer))
        if (hyperdb.hd_sucess != retcode):
            raise hyperdb.HDError(retcode)

        iterate = hyperdb.Iterate(hditer, hdsectrust)
        return iterate
        
        