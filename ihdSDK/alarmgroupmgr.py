#!/usr/bin/env python
# -*- coding: utf-8 -*-

from ctypes import *
from ihdSDK import hyperdb
from ihdSDK import alarmgroup
import sys

class AlarmGroupMgr(object):
    
    # add a alarm group to server
    # @param name: alarm group name
    # @param desc: the description of the alarm group
    # @param parentid: the parent id, it's the group which you want add the alarm group under it
    # @note: when you won't give a value of parent id, the parent id is 0 by default, otherwise you should input the
    #  parent id,you also can access the top level group to get their child group to get parent group id.
    def add_alarmgroup(self, name, desc, parentid = 0):
        if type(name) != str or type(desc)!= str:
            raise TypeError
        
        if type(parentid) != int:
            raise TypeError
        
        group = hyperdb.HD3AlarmGroup()
        group.szName = name
        group.szDesc = desc
        group.nGroupID = c_uint32()
        group.nParentID = c_uint32(parentid)
        groupid = c_uint32
        
        
        hyperdb.api.am3_add_group.argtypes = [POINTER(hyperdb.HD3AlarmGroup), c_void_p]
        retcode = hyperdb.api.am3_add_group(byref(group), byref(groupid))
        if hyperdb.hd_sucess != retcode:
            raise hyperdb.HDError(retcode)
        
    def delete_alarmgroup(self, groupname, parentid):
        if type(parentid) != int or type(groupname) != str:
            raise TypeError
       
        groupid = c_uint32() 
        groupname_buf = groupname
        
        hyperdb.api.am3_query_group_id.argtypes = [c_char_p, c_uint32, POINTER(c_uint32)]
        retcode = hyperdb.api.am3_query_group_id(groupname_buf, parentid, byref(groupid))        
        if hyperdb.hd_sucess != retcode:
            raise hyperdb.HDError(retcode) 
                
        hyperdb.api.am3_delete_group.argtypes = [c_uint32]
        retcode = hyperdb.api.am3_delete_group(groupid)
        if hyperdb.hd_sucess != retcode:
            raise hyperdb.HDError(retcode)  
    
    def get_top_level_alarmgroups(self):
        groupids = []
        hditer = c_void_p()
        
        hyperdb.api.am3_query_group_child_groups.argtypes = [c_uint32, POINTER(c_void_p)]
        retcode = hyperdb.api.am3_query_group_child_groups(0, byref(hditer))
        if hyperdb.hd_sucess != retcode:
            raise hyperdb.HDError(retcode) 
        
        while(True):
            groupid = c_uint32()
            retcode = hyperdb.api.ut3_get_item_step(hditer, byref(groupid))
            if retcode == hyperdb.hd_sucess:
                groupids.append(groupid)
            elif (retcode == hyperdb.query_end_code):
                break
            else:
                raise hyperdb.HDError(retcode)
        hyperdb.api.ut_free_iterator(hditer)
        
        alarmgroups = []
        hdalarmgroup = hyperdb.HD3AlarmGroup() 

        error = c_int32()
        for id in groupids:
            hdalarmgroup.nGroupID = id
            hyperdb.api.am_query_group_props.argtypes = [c_int32, POINTER(c_uint32), POINTER(hyperdb.HD3AlarmGroup), POINTER(c_int32)]
            retcode = hyperdb.api.am_query_group_props(1, byref(id), byref(hdalarmgroup), byref(error))
            if hyperdb.hd_sucess != retcode:
                continue
            alarmgroup_buf = alarmgroup.AlarmGroup('', '', '', '')
            alarmgroup_buf.name = hdalarmgroup.szName
            alarmgroup_buf.description = hdalarmgroup.szDesc
            alarmgroup_buf.id = hdalarmgroup.nGroupID
            alarmgroup_buf.parentid = hdalarmgroup.nParentID
            alarmgroups.append(alarmgroup_buf) 
            
        return alarmgroups
            
           
        
        
                
            
                
        
               
        
        
        
        
    