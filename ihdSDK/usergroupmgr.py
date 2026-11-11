#!/usr/bin/env python
# -*- coding: utf-8 -*-

from ctypes import *
from ihdSDK import hyperdb
import sys

## UserGroupMgr is a operator class through which programmers can use to do all
# operators about Group.
# @note Programmers needn't create a UserGroupMgr object. Instead, UserGroupMgr object
# can be accessed from Server class
class UserGroupMgr(object):
    
    ## Add a group to the server
    # @param name: group name
    # @param desc: description of a group
    def add_group(self, name, desc):
        if type(name) != str or type(desc) != str:
            raise TypeError
        if not name.strip():
            raise TypeError
        secgroup_buf = hyperdb.HD3SecGroup()
        secgroup_buf.szGroupName = name
        secgroup_buf.szGroupDesc = desc
        
        hyperdb.api.sc3_add_group.argtypes = [POINTER(hyperdb.HD3SecGroup)]
        retcode = hyperdb.api.sc3_add_group(secgroup_buf)
        if (hyperdb.hd_sucess != retcode):
            raise hyperdb.HDError(retcode)
        
    ## Delete a group from the server
    # @param name: group name
    def delete_group(self, name):
        if type(name) != str :
            raise TypeError
        
        hyperdb.api.sc3_delete_group.argtypes = [c_char_p]
        retcode = hyperdb.api.sc3_delete_group(name)
        if (hyperdb.hd_sucess != retcode):
            raise hyperdb.HDError(retcode)
    
    ## Get all groups from the server
    # @return: a List of group objects
    def get_all_groups(self):  
        secgroup = hyperdb.HD3SecGroup()
        hditer = c_void_p()
        
        hyperdb.api.sc3_query_all_groups.argtypes = [POINTER(c_void_p)]  
        retcode = hyperdb.api.sc3_query_all_groups(byref(hditer))
        if (hyperdb.hd_sucess != retcode):
            raise hyperdb.HDError(retcode)
        
        iterate = hyperdb.Iterate(hditer, secgroup)
        return iterate
    
    ## Get all users from a server
    # @return: return a iterate of users
    def get_all_users(self):
        secuser = hyperdb.HD3SecUser()
        hditer = c_void_p()
        
        hyperdb.api.sc3_query_all_users.argtypes = [POINTER(c_void_p)]  
        retcode = hyperdb.api.sc3_query_all_users(byref(hditer))
        if (hyperdb.hd_sucess != retcode):
            raise hyperdb.HDError(retcode)
        
        iterate = hyperdb.Iterate(hditer, secuser)
        return iterate
    
    ## Add a user to the server
    # @param name: user name
    # @param psw: password which must be more than 5 characters
    # @param desc: user description
    def add_user(self, name, psw, desc):
        if type(name) != str or type(psw) != str or type(desc) != str:
            raise TypeError
        
        user = hyperdb.HD3SecUser()
        user.szUserName = name
        user.szPassword = psw
        user.szUserDesc = desc
        
        hyperdb.api.sc3_add_user.argtypes = [c_void_p]
        retcode = hyperdb.api.sc3_add_user(byref(user))
        if (hyperdb.hd_sucess != retcode):
            raise hyperdb.HDError(retcode)
        
    ## Delete a user from a server
    # @param name: user name 
    def delete_user(self, name):
        if type(name) != str:
            raise TypeError
        
        hyperdb.api.sc3_delete_user.argtypes = [c_char_p]
        retcode = hyperdb.api.sc3_delete_user(name)
        if (hyperdb.hd_sucess != retcode):
            raise hyperdb.HDError(retcode)
    
    ## Get current user
    # @requires: current user object
    def get_current_user(self): 
        name_buf = (c_char * 64)()
        namesize = 64
        
        #hyperdb.api.sc3_query_current_user_name.argtypes = [c_int32, c_char_p]
        retcode = hyperdb.api.sc3_query_current_user_name(c_int32(namesize), name_buf)
        if (hyperdb.hd_sucess != retcode):
            raise hyperdb.HDError(retcode)
        
        name = name_buf.value
        return name
