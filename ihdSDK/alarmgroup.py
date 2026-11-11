#!/usr/bin/env python
# -*- coding: utf-8 -*-

from ctypes import *
from ihdSDK import hyperdb
import sys
from ihdSDK import tag

class AlarmGroup(object):
    def __init__(self, name, id, description, parentid):
        self.name = name
        self.description = description
        self.id = id
        self.parentid = parentid
        
    def get_alarm_childgroups(self):
        if type(self.id) != int:
            raise TypeError
        
        hditer = c_void_p()
        
        hyperdb.api.am3_query_group_child_groups.argtypes = [c_uint32, POINTER(c_void_p)]
        retcode = hyperdb.api.am3_query_group_child_groups(self.id, byref(hditer))
        if hyperdb.hd_sucess != retcode:
            raise hyperdb.HDError(retcode)
        
        alarmgroup_buf = AlarmGroup('', '', '', '')
        iterate = hyperdb.Iterate(hditer, alarmgroup_buf)
        return iterate
    
    def get_alarm_tags(self):
        if type(self.id) != int:
            raise TypeError
        hditer = c_void_p()
        
        hyperdb.api.am3_query_group_child_tags.argtypes = [c_uint32, POINTER(c_void_p)]
        retcode = hyperdb.api.am3_query_group_child_tags(self.id, byref(hditer))  
        if hyperdb.hd_sucess != retcode:
            raise hyperdb.HDError(retcode)   
        
        tagid = c_uint32()          
        iterate = hyperdb.Iterate(hditer, tagid)
        return iterate
    
    def modify_description(self, newdesc):
        if type(newdesc) != str:
            raise TypeError
        
        groupnum = 1
        groupid = self.id
        group = hyperdb.HD3AlarmGroup()
        errors = c_int32()
        
        hyperdb.am3_query_group_props.argtypes = [c_int32, POINTER(c_uint32), POINTER(hyperdb.HD3AlarmGroup), POINTER(c_int32)]
        retcode = hyperdb.api.am3_query_group_props(groupnum, groupid, byref(group), byref(errors))
        if hyperdb.hd_sucess != retcode:
            raise hyperdb.HDError(retcode) 
        
        group.szDesc = newdesc
        
        hyperdb.am3_modify_group.argtypes = [c_uint32, POINTER(hyperdb.HD3AlarmGroup)]
        retcode = hyperdb.api.am3_modify_group(groupid, group)
        if hyperdb.hd_sucess != retcode:
            raise hyperdb.HDError(retcode) 
    
    def modify_name(self, newname):
        if type(newname) != str:
            raise TypeError
        
        groupnum = 1
        groupid = self.id
        group = hyperdb.HD3AlarmGroup()
        errors = c_int32() 
        
        hyperdb.am3_query_group_props.argtypes = [c_int32, POINTER(c_uint32), POINTER(hyperdb.HD3AlarmGroup), POINTER(c_int32)]
        retcode = hyperdb.api.am3_query_group_props(groupnum, groupid, byref(group), byref(errors))
        if hyperdb.hd_sucess != retcode:
            raise hyperdb.HDError(retcode)
        
        group.szName = newname
        
        hyperdb.am3_modify_group.argtypes = [c_uint32, POINTER(hyperdb.HD3AlarmGroup)]
        retcode = hyperdb.api.am3_modify_group(groupid, group)
        if hyperdb.hd_sucess != retcode:
            raise hyperdb.HDError(retcode) 
    
    def modify_parentgroup(self, parentid):
        if type(parentid) != int:
            raise TypeError
        
        groupnum = 1
        groupid = self.id
        group = hyperdb.HD3AlarmGroup()
        errors = c_int32() 
        
        hyperdb.am3_query_group_props.argtypes = [c_int32, POINTER(c_uint32), POINTER(hyperdb.HD3AlarmGroup), POINTER(c_int32)]
        retcode = hyperdb.api.am3_query_group_props(groupnum, groupid, byref(group), byref(errors))
        if hyperdb.hd_sucess != retcode:
            raise hyperdb.HDError(retcode)
        
        group.nParentID = parentid
        
        hyperdb.am3_modify_group.argtypes = [c_uint32, POINTER(hyperdb.HD3AlarmGroup)]
        retcode = hyperdb.api.am3_modify_group(groupid, group)
        if hyperdb.hd_sucess != retcode:
            raise hyperdb.HDError(retcode)   
