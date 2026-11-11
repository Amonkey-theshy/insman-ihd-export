#!/usr/bin/env python
# -*- coding: utf-8 -*-

from ctypes import *
from ihdSDK import hyperdb
from ihdSDK import tagmgr
from ihdSDK import usergroupmgr
from ihdSDK import securitymgr
from ihdSDK import alarmgroupmgr
import sys
from ihdSDK import collectormgr

## Each object derived from class Server should be corresponding to a 
#  iHyperDB Server
class Server(object):
    ## Construction function of class Server
    # @param ip: ip address with string formation, such as "168.2.4.7"
    # @param port: port number which small than 65535 and is not used by other program 
    def __init__(self, address, port, bakaddress='', bakport=0):
        if (type(address) != str) or (type(port) != int):
            raise TypeError
        if (type(bakaddress) != str) or (type(bakport)!=int):
            raise TypeError
        self.address = address    
        self.port = port
        self.bakaddress = bakaddress
        self.bakport = bakport
        hyperdb.load_library()
        self.tag_mgr = tagmgr.TagMgr(self)
        self.usergroup_mgr = usergroupmgr.UserGroupMgr()
        self.security_mgr = securitymgr.SecurityMgr()
        self.alarmgroup_mgr = alarmgroupmgr.AlarmGroupMgr()
        self.collector_mgr = collectormgr.CollectorMgr()

    ## Connect to a server
    # @param timeout: maximal time that connect operator is allowed
    def connect(self, timeout = 3):
        if (type(timeout) != int):
            raise TypeError
        conn_config = hyperdb.HD3Connection()
        conn_config.szAddress = bytes(self.address, encoding='utf8')
        conn_config.nPort = c_uint16(self.port)
        conn_config.nTimeout = c_int32(timeout)
        
        if self.bakaddress != '':
            conn_config.szBakAddress = bytes(self.bakaddress, encoding='utf8')
        else:
            conn_config.szBakAddress = b''
            
        if (self.bakport != 0):
            conn_config.nBakPort = c_uint16(self.bakport)
        else:
            conn_config.nBakPort = 0

        hyperdb.api.nt3_connect.argtypes = [POINTER(hyperdb.HD3Connection)]
        retcode = hyperdb.api.nt3_connect(byref(conn_config))
        
        if (retcode != hyperdb.hd_sucess):
            print (retcode)
            raise hyperdb.HDError(retcode)
    
    ## disconnect from a server        
    def disconnect(self):
        
        retcode = hyperdb.api.nt3_disconnect()
        
        if (hyperdb.hd_sucess != retcode):
            raise hyperdb.HDError(retcode)
        

    
    ## Set timeout for sending commands
    # @param timeout: timeout for sending commands except for connection
    #(set_timeout -> set_request_timeout)
    def set_request_timeout(self, timeout = 3):  
        if (type(timeout) != int):
            raise TypeError   
         
        timeout = c_int32(timeout) 
           
        hyperdb.api.ut3_set_request_timeout.argtypes = [c_int32]
        retcode = hyperdb.api.ut3_set_request_timeout(timeout)
        if (hyperdb.hd_sucess != retcode):
            raise hyperdb.HDError(retcode)
    
    ## Login a server
    # @param username: user name
    # @param password: user's password which should be longer than 5 characters
    def login(self, username, password):
        if (type(username) != str) or (type(password) != str):
            raise TypeError
         
        name_buf = bytes(username, encoding='gbk')  
        password_buf = bytes(password, encoding='gbk')    
        
        hyperdb.api.sc3_login.argtypes = [c_char_p, c_char_p]  
        retcode = hyperdb.api.sc3_login(name_buf, password_buf)
        if (hyperdb.hd_sucess != retcode):
            raise hyperdb.HDError(retcode)
            
    
    #===========================================================================
    # # �ַ���
    # def set_charset(self, charset):     
    #    ''' 
    #    ' @brief: ����API�����ַ�������ʾAPI���ܵ����ı��롢API��������ı��룩
    #    ' @param charset: �ַ���ö��
    #    ' @raise exception: TypeError, hyperdb.HDError(retcode)
    #    ' @version: 2014/03/19, xuminzhi initialize version
    #    '''     
    #    if (type(charset) is not int):
    #        raise TypeError
    #    
    #    hyperdb.api.ut3_set_charset.argtypes = [c_int32] 
    #    retcode = hyperdb.api.ut3_set_charset(charset)  
    #    if (hyperdb.hd_sucess != retcode):
    #        raise hyperdb.HDError(retcode)
    #    
    # def get_charset(self):
    #    ''' 
    #    ' @brief: ��ȡAPI�����ַ�������ʾAPI���ܵ����ı��롢API��������ı��룩
    #    ' @return charset: �ַ���ö��
    #    ' @raise exception: hyperdb.HDError(retcode)
    #    ' @version: 2014/03/19, xuminzhi initialize version
    #    '''
    #    charset = c_int32(0)
    #    
    #    hyperdb.api.ut3_get_charset.argtypes = [POINTER(c_int32)]
    #    retcode = hyperdb.api.ut3_get_charset(byref(charset))
    #    if (hyperdb.hd_sucess != retcode):
    #        raise hyperdb.HDError(retcode)
    #    return charset
    #===========================================================================
