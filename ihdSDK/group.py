#!/usr/bin/env python
# -*- coding: utf-8 -*-

from ctypes import *
from ihdSDK import hyperdb
import sys


## Operator for a special UserGroup
# @note: Programmers needn't create a UserGroup object. Instead, UserGroup object
# can be accessed from UserGroupMgr class
class UserGroup(object):
    def __init__(self, name, desc):              
        self.name = name
        self.desc = desc

    ## add a user to the group 
    # @note: the user must be in server
    # @param username: user name
    def add_user(self, username):
        if type(username) != str:
            raise  TypeError
        
        username_buf = username
        groupname_buf = self.name 
        
        hyperdb.api.sc3_add_user_to_group.argtypes = [c_char_p, c_char_p]
        retcode = hyperdb.api.sc3_add_user_to_group(username_buf, groupname_buf)
        if (hyperdb.hd_sucess != retcode):
            raise hyperdb.HDError(retcode)
    
    ## Remove a user from the group
    # @param username: user name
    def delete_user(self, username):
        if type(username) != str:
            raise  TypeError
        
        username_buf = username
        groupname_buf = self.name 
        
        hyperdb.api.sc3_delete_user_from_group.argtypes = [c_char_p, c_char_p]
        retcode = hyperdb.api.sc3_delete_user_from_group(username_buf, groupname_buf)
        if (hyperdb.hd_sucess != retcode):
            raise hyperdb.HDError(retcode)
    
    ## Modify group's description
    # @param newdesc: new description of the group
    def modify_desc(self, newdesc): 
        if type(newdesc) != str:
            raise  TypeError
        
        groupname_buf = self.name 
        newdesc_buf = newdesc
               
        hyperdb.api.sc3_modify_group_desc.argtypes = [c_char_p, c_char_p]
        retcode = hyperdb.api.sc3_modify_group_desc(groupname_buf, newdesc_buf)
        if (hyperdb.hd_sucess != retcode):
            raise hyperdb.HDError(retcode)
    
    ## Get all users belonging to the group
    # @return: a iterate
    def get_all_users(self): 
        secuser = hyperdb.HD3SecUser()
        groupname_buf = self.name 
        hditer = c_void_p()
        
        hyperdb.api.sc3_query_members_of_group.argtypes = [c_char_p, POINTER(c_void_p)]  
        retcode = hyperdb.api.sc3_query_members_of_group(groupname_buf, byref(hditer))
        if (hyperdb.hd_sucess != retcode):
            raise hyperdb.HDError(retcode)

        iterate = hyperdb.Iterate(hditer, secuser)
        return iterate

    
        