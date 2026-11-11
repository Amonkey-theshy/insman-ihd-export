#!/usr/bin/env python
# -*- coding: utf-8 -*-

## the class of a record
class Record():
    def __init__(self, sec, msec):
        self.sec = sec
        self.msec = msec
        self.quality = ''
        self.tagtype = ''
        self.value = ''
        
class AlarmRecord():
    def __init__(self):
        self.tagid = ''
        self.startsec = ''
        self.startmsec = ''
        self.endsec = ''
        self.endmsec = ''
        self.acktime = ''
        self.commenttime = ''
        self.acked = ''
        self.restored = ''
        self.commented = ''
        self.test = ''
        self.priority = ''
        self.acktype = ''
        self.alarmtype = ''
        self.srcvalue = ''
        self.acker = ''
        self.commentor = ''
        self.comment = ''
        
        

        


    
