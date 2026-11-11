#!/usr/bin/env python
# -*- coding: utf-8 -*-

from ctypes import *
from ihdSDK import hyperdb
import sys

## Operator for a special user
# @note    Programmers needn't create a User object. Instead, User object
# can be accessed from UserMgr class
class User():
    def __init__(self, name, desc):     
        self.name = name
        self.desc = desc

    ## modify user's password
    # @param oldpas: previous password
    # @param newpsw: new password
    def modify_password(self, oldpsw, newpsw):
        if (type(newpsw) != str) or (type(oldpsw) != str):
            raise TypeError

        newpsw_buf = newpsw
        oldpsw_buf = oldpsw
        name_buf = self.name 
   
        hyperdb.api.sc3_modify_password.argtypes = [c_char_p, c_char_p, c_char_p]
        retcode = hyperdb.api.sc3_modify_password(name_buf, oldpsw_buf, newpsw_buf)
        if (hyperdb.hd_sucess != retcode):
            raise hyperdb.HDError(retcode)
    
    ## Reset user's password
    # @param param: user's new password
    def reset_password(self, newpsw): 
        if (type(newpsw) != str):
            raise TypeError
        
        name_buf = self.name 
        psw_buf = newpsw
        
        hyperdb.api.sc3_reset_password.argtypes = [c_char_p, c_char_p] 
        retcode = hyperdb.api.sc3_reset_password(name_buf, psw_buf)    
        if (hyperdb.hd_sucess != retcode):
            raise hyperdb.HDError(retcode)
    
    ## add the user to a group
    #@param groupname: group name which the user will be belong to
    def add_group_membership(self, groupname):
        if type(groupname) != str:
            raise TypeError

        name_buf = self.name         
        groupname_buf = groupname
        
        hyperdb.api.sc3_add_user_to_group.argtypes = [c_char_p, c_char_p]
        retcode = hyperdb.api.sc3_add_user_to_group(name_buf, groupname_buf)
        if (hyperdb.hd_sucess != retcode):
            raise hyperdb.HDError(retcode)
    
    ## delete the user from a group
    # @param groupname: the group name where the user will be deleted from
    def delete_group_membership(self, groupname): 
        if type(groupname) != str:
            raise TypeError

        name_buf = self.name         
        groupname_buf = groupname
        
        hyperdb.api.sc3_delete_user_from_group.argtypes = [c_char_p, c_char_p]
        retcode = hyperdb.api.sc3_delete_user_from_group(name_buf, groupname_buf)
        if (hyperdb.hd_sucess != retcode):
            raise hyperdb.HDError(retcode)
    
    ## Modify the description of the user
    # @param newdesc: new description of the user
    def modify_user_desc(self, newdesc):
        if type(newdesc) != str:
            raise TypeError
 
        name_buf = self.name        
        newdesc_buf = newdesc
        
        hyperdb.api.sc3_modify_user_desc.argtypes = [c_char_p, c_char_p]
        retcode = hyperdb.api.sc3_modify_user_desc(name_buf, newdesc_buf)
        if (hyperdb.hd_sucess != retcode):
            raise hyperdb.HDError(retcode)
        
    ## Get all groups which the user belongs to
    # @return: a List of Group objects
    def get_member_groups(self):         
        secgroup = hyperdb.HD3SecGroup()
        hditer = c_void_p()
        username_buf = self.name 
        
        hyperdb.api.sc3_query_groups_of_user.argtypes = [c_char_p, POINTER(c_void_p)]  
        retcode = hyperdb.api.sc3_query_groups_of_user(username_buf, byref(hditer))
        if (hyperdb.hd_sucess != retcode):
            raise hyperdb.HDError(retcode)
        
        iterate = hyperdb.Iterate(hditer, secgroup)
        return iterate        
        
    

        
        