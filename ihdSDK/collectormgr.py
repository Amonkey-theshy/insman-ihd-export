#!/usr/bin/env python
# -*- coding: utf-8 -*-

from ctypes import *
from . import hyperdb
import sys
        
        
class CollectorMgr(object):        
    
    def add_collector(self, name, collectortype, description, extparam):
        if type(name) != str or type(collectortype) != int:
            raise TypeError
        
        if type(description) != str or type(extparam) != str:
            raise TypeError
        
        collector_name = name
        collector_desc = description
        collector_extparam = extparam       
        collector = hyperdb.HD3Collector(0, collector_name, collectortype, collector_desc, collector_extparam)
        collectorid = c_uint32()
              
        hyperdb.api.ct3_add_collector.argtypes = [POINTER(hyperdb.HD3Collector), c_void_p]
        retcode = hyperdb.api.ct3_add_collector(byref(collector), byref(collectorid))
        if hyperdb.hd_sucess != retcode:
            raise hyperdb.HDError(retcode)
        
    def delete_collector(self, name):
        if type(name) != str:
            raise TypeError
        
        collector_name = name
        collector_id = c_uint32() 
        hyperdb.api.ct3_query_collector_id_by_name.argtypes = [c_char_p, POINTER(c_uint32)]
        retcode = hyperdb.api.ct3_query_collector_id_by_name(byref(collector_name), byref(collector_id))
        if hyperdb.hd_sucess != retcode:
            raise hyperdb.HDError(retcode)   
        
        hyperdb.api.ct3_delete_collector.argtypes = [c_uint32]
        retcode = hyperdb.api.ct3_delete_collector(collector_id)  
        if hyperdb.hd_sucess != retcode:
            raise hyperdb.HDError(retcode)              
        
        
    def get_all_collectors(self):
        collector = hyperdb.HD3Collector()
        hditer = c_void_p()
        
        hyperdb.api.ct3_query_all_collectors.argtypes = [POINTER(c_void_p)]  
        retcode = hyperdb.api.ct3_query_all_collectors(byref(hditer))
        if hyperdb.hd_sucess != retcode:
            raise hyperdb.HDError(retcode)
        
        iterate = hyperdb.Iterate(hditer, collector)
        return iterate
        
    def get_collector(self, name):
        if type(name) != str:
            raise TypeError
 
        collector_name = name       
        hdcollector = hyperdb.HD3Collector()   
        
        collector_id = c_uint32() 
        hyperdb.api.ct3_query_collector_id_by_name.argtypes = [c_char_p, POINTER(c_uint32)]
        retcode = hyperdb.api.ct3_query_collector_id_by_name(byref(collector_name), byref(collector_id))
        if hyperdb.hd_sucess != retcode:
            raise hyperdb.HDError(retcode)  
        
        hyperdb.api.ct3_query_collector.argtypes = [c_uint32, POINTER(hyperdb.HD3Collector)]  
        retcode = hyperdb.api.ct3_query_collector(collector_id, byref(hdcollector))
        if hyperdb.hd_sucess != retcode:
            raise hyperdb.HDError(retcode)  
        
        id = hdcollector.nID
        name = hdcollector.szName 
        type = hdcollector.nType
        description = hdcollector.szDescription
        extparam = hdcollector.szExtParam
        collector_buf = Collector(id, name, type, description, extparam)  
          
        return collector_buf
    
    def modify_collector(self, id, name, collectortype, description, extparam):
        if type(name) != str or type(collectortype) != int:
            raise TypeError
        if type(id) != int:
            raise TypeError
        if type(description) != str or type(extparam) != str:
            raise TypeError 
               
        hdcollector = hyperdb.HD3Collector()
        hdcollector.nID = id
        hdcollector.szName = name
        hdcollector.nType = collectortype
        hdcollector.szDescription = description
        hdcollector.szExtParam = extparam
        
        hyperdb.api.ct3_modify_collector.argtypes = [c_uint32, POINTER(hyperdb.HD3Collector)]
        retcode = hyperdb.api.ct3_modify_collector(id, byref(hdcollector))
        if hyperdb.hd_sucess != retcode:
            raise hyperdb.HDError(retcode)  
        
#!/usr/bin/env python
# -*- coding: utf-8 -*-

from ctypes import *
from ihdSDK import hyperdb
import sys



class ScanGroup(object):
    def __init__(self):
        self.id = ''
        self.name = ''
        self.period = ''
        self.phase = ''  
        self.scantype = ''
        self.deviceid = ''
        self.dataaddr = ''
        self.datalen = ''
        self.description = ''
        self.extparam = ''
        
        
class Device(object):
    def __init__(self, id, collectorid, name, addr, port, trytime, timeout, extparam, isprimary, description):
        self.id = id
        self.collectorid = collectorid
        self.name = name
        self.addr = addr
        self.port = port
        self.trytime = trytime
        self.timeout = timeout
        self.extparam = extparam
        self.isprimary = isprimary
        self.description = description
        
    def add_scan_group(self, name, period, phase, scantype, dataaddr, datalen, description, extparam):
        if type(period) != int or type(phase) != int:
            raise TypeError
        if type(scantype) != int or type(description) != str:
            raise TypeError             
        if type(dataaddr) != int or type(datalen) != int:
            raise TypeError  
        if type(name) != str or type(extparam) != str:
            raise TypeError          

        sacn_group_name = name 
        hdscangroup = hyperdb.HD3ScanGroup()
        hdscangroup.nID = 0
        hdscangroup.szName = sacn_group_name
        hdscangroup.nPeriod = period
        hdscangroup.nPhase = phase
        hdscangroup.nScanType = scantype
        hdscangroup.nDeviceID = self.id
        hdscangroup.nDataAddr = dataaddr
        hdscangroup.nDataLen = datalen
        hdscangroup.szDescription = description 
        hdscangroup.szExtParam = extparam 
        
        scangroupid = c_uint32
        
        hyperdb.api.ct3_add_scan_group.argtypes = [POINTER(hyperdb.HD3ScanGroup), POINTER(c_uint32)]
        retcode = hyperdb.api.ct3_add_scan_group(byref(hdscangroup), byref(scangroupid))
        if hyperdb.hd_sucess != retcode:
            raise hyperdb.HDError(retcode)        

    
    def delete_scan_group(self, scangroupname):
        if type(scangroupname) != str:
            raise TypeError
        
        scan_group_name = scangroupname 
        
        group_id = c_uint32()
        hyperdb.api.ct3_query_scan_group_id_by_name.argtypes = [c_uint32, c_char_p, POINTER(c_uint32)]
        retcode = hyperdb.api.ct3_query_scan_group_id_by_name(self.id, byref(scan_group_name), byref(group_id))
        if hyperdb.hd_sucess != retcode:
            raise hyperdb.HDError(retcode)  

        hyperdb.api.ct3_delete_scan_group.argtypes = [c_uint32]  
        retcode = hyperdb.api.ct3_delete_scan_group(group_id)
        if hyperdb.hd_sucess != retcode:
            raise hyperdb.HDError(retcode)        
    
    def get_scan_groups(self):
        scangroup = hyperdb.HD3ScanGroup()
        hditer = c_void_p()
               
        hyperdb.api.ct3_query_scan_groups_of_device.argtypes = [c_uint32, POINTER(c_void_p)]  
        retcode = hyperdb.api.ct_query_scan_groups_of_device(self.id, byref(hditer))
        if hyperdb.hd_sucess != retcode:
            raise hyperdb.HDError(retcode)
        
        iterate = hyperdb.Iterate(hditer, scangroup)
        
        return iterate
    
    def get_scan_group(self, name):
        if type(name) != str:
            raise TypeError
        
        scan_group_name = name 
        group_id = c_uint32()
        hyperdb.api.ct3_query_scan_group_id_by_name.argtypes = [c_uint32, c_char_p, POINTER(c_uint32)]
        retcode = hyperdb.api.ct3_query_scan_group_id_by_name(self.id, byref(scan_group_name), byref(group_id))
        if hyperdb.hd_sucess != retcode:
            raise hyperdb.HDError(retcode)  
        
        hdscangroup = hyperdb.HD3ScanGroup()
        hyperdb.api.ct3_query_scan_group.argtypes = [c_uint32, POINTER(hyperdb.HD3ScanGroup)]
        retcode = hyperdb.api.ct3_query_scan_group(group_id, byref(hdscangroup))
        if hyperdb.hd_sucess != retcode:
            raise hyperdb.HDError(retcode) 
                
        scangroup = ScanGroup() 
        scangroup.id = hdscangroup.nID
        scangroup.name = hdscangroup.szName
        scangroup.period = hdscangroup.nPeriod
        scangroup.phase = hdscangroup.nPhase
        scangroup.scantype = hdscangroup.nScanType
        scangroup.deviceid = hdscangroup.nDeviceID
        scangroup.dataaddr = hdscangroup.nDataAddr
        scangroup.datalen = hdscangroup.nDataLen
        scangroup.description = hdscangroup.szDescrption
        scangroup.extparam = hdscangroup.szExtParam  
        
        return scangroup    
    
    def modify_scan_group(self, id, name, period, phase, scantype, dataaddr, datalen, description, extparam):
        if type(period) != int or type(phase) != int:
            raise TypeError
        if type(scantype) != int or type(description) != str:
            raise TypeError             
        if type(dataaddr) != int or type(datalen) != int:
            raise TypeError  
        if type(name) != str or type(extparam) != str:
            raise TypeError  
        if type(id) != int:
            raise TypeError
           
        scangroup = hyperdb.HD3ScanGroup()
        scangroup.nID = id
        scangroup.szName = name 
        scangroup.nPeriod = period
        scangroup.nPhase = phase
        scangroup.nScanType = scantype
        scangroup.nDeviceID = self.id
        scangroup.nDataAddr = dataaddr
        scangroup.nDataLen = datalen 
        scangroup.szDescrption = description 
        scangroup.szExtParam = extparam 

        hyperdb.api.ct3_modify_scan_group.argtypes = [c_uint32, POINTER(hyperdb.HD3ScanGroup)]
        retcode = hyperdb.api.ct_modify_scan_group(id, byref(scangroup))
        if hyperdb.hd_sucess != retcode:
            raise hyperdb.HDError(retcode) 
        
        
class Collector(object):
    def __init__(self, server, id, name, type, description, extparam):
        self.server = server
        self.id = id
        self.name = name
        self.type = type
        self.description = description
        self.extparam = extparam  
            
        
    def add_device(self, name, addr, port, trytime, timeout, extparam, isprimary, description):
        if type(description) != str or type(name) != str:
            raise TypeError
        if type(addr) != str or type(port) != int:
            raise TypeError             
        if type(trytime) != int or type(timeout) != int:
            raise TypeError  
        if type(extparam) != str or type(isprimary) != bool:
            raise TypeError                     
        
        device_name = name 
        hddevice = hyperdb.HD3Device()
        hddevice.nID = 0
        hddevice.nCollectorID = self.id
        hddevice.szName = device_name
        hddevice.szAddr = addr 
        hddevice.nPort = port
        hddevice.nTryTime = trytime
        hddevice.nTimeout = timeout
        hddevice.szExtParam = extparam 
        hddevice.bIsPrimary = isprimary
        hddevice.szDescription = description 
        
        deviceid = c_uint32()
        
        hyperdb.api.ct3_add_device.argtypes = [POINTER(hyperdb.HD3Device), c_void_p]
        retcode = hyperdb.api.ct_add_device(byref(hddevice), deviceid)
        if hyperdb.hd_sucess != retcode:
            raise hyperdb.HDError(retcode)        

    
    def delete_device(self, name):
        if type(name) != str:
            raise TypeError
        
        device_name = name 
        
        device_id = c_uint32()
        hyperdb.api.ct3_query_device_id_by_name.argtypes = [c_uint32, c_char_p, POINTER(c_uint32)]
        retcode = hyperdb.api.ct3_query_device_id_by_name(self.id, byref(device_name), byref(device_id))
        if hyperdb.hd_sucess != retcode:
            raise hyperdb.HDError(retcode)  
        
        hyperdb.api.ct3_delete_device.argtypes = [c_uint32]  
        retcode = hyperdb.api.ct3_delete_device(device_id)
        if hyperdb.hd_sucess != retcode:
            raise hyperdb.HDError(retcode)  

    def get_device(self, name):
        if type(name) != str:
            raise TypeError
        
        device_name = name 
        device_id = c_uint32()
        
        hyperdb.api.ct3_query_device_id_by_name.argtypes = [c_uint32, c_char_p, POINTER(c_uint32)]
        retcode = hyperdb.api.ct3_query_device_id_by_name(self.id, byref(device_name), byref(device_id))
        if hyperdb.hd_sucess != retcode:
            raise hyperdb.HDError(retcode) 
        
        hddevice = hyperdb.HD3Device()
        hyperdb.api.ct3_query_device.argtypes = [c_uint32, POINTER(hyperdb.HD3Device)]
        retcode = hyperdb.api.ct3_query_device(device_id, byref(hddevice))
        if hyperdb.hd_sucess != retcode:
            raise hyperdb.HDError(retcode)
        
        device_id = hddevice.nID
        device_collectorid = hddevice.nCollectorID
        device_name = hddevice.szName
        device_addr = hddevice.szAddr
        device_port = hddevice.nPort
        device_trytime = hddevice.nTryTime
        device_timeout = hddevice.nTimeout
        device_extparam = hddevice.szExtParam
        device_isprimary = hddevice.bIsPrimary
        device_description = hddevice.szDescription
        
        device_buf = Device(device_id, device_collectorid, device_name, device_addr, device_port,
                            device_trytime, device_timeout, device_extparam, device_isprimary, device_description)
        
        return device_buf
        
    def get_all_devices(self):
        hddevice = hyperdb.HD3Device()
        hditer = c_void_p()
              
        hyperdb.api.ct3_query_devices_of_collector.argtypes = [c_uint32, POINTER(c_void_p)]  
        retcode = hyperdb.api.ct3_query_devices_of_collector(self.id, byref(hditer))
        if hyperdb.hd_sucess != retcode:
            raise hyperdb.HDError(retcode)
        
        iterate = hyperdb.Iterate(hditer, hddevice)
        
        return iterate
    
    def modify_device(self, id, name, addr, port,trytime, timeout, extparam, isprimary, description):
        if type(description) != str or type(name) != str:
            raise TypeError
        if type(addr) != str or type(port) != int:
            raise TypeError             
        if type(trytime) != int or type(timeout) != int:
            raise TypeError  
        if type(extparam) != str or type(isprimary) != bool:
            raise TypeError  
        if type(id) != int:
            raise TypeError 
        
        hddevice = hyperdb.HD3Device()
        hddevice.nID = id
        hddevice.nCollectorID = self.id
        hddevice.szName = name 
        hddevice.szAddr = addr 
        hddevice.nPort = port
        hddevice.nTryTime = trytime
        hddevice.nTimeout = timeout
        hddevice.szExtParam = extparam 
        hddevice.bIsPrimary = isprimary
        hddevice.szDescription = description       
         
        hyperdb.api.ct3_modify_device.argtypes = [c_uint32, POINTER(hyperdb.HD3Device)] 
        retcode = hyperdb.api.ct3_modify_device(id, byref(hddevice))
        if hyperdb.hd_sucess != retcode:
            raise hyperdb.HDError(retcode)       
    
 
