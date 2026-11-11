#!/usr/bin/env python
# -*- coding: utf-8 -*-

## Operator for a special Security
# @note: Programmers needn't create a Security object. Instead, Trust object
# can be accessed from SecurityMgr class
class Security(object):
    def __init__(self, owngroupname, operategroupname, securitylevel):
        self.owngroupname = owngroupname
        self.operategroupname = operategroupname
        self.securitylevel = securitylevel
        
        
        
## Operator for a special trust
# @note: Programmers needn't create a Trust object. Instead, Trust object
# can be accessed from trustMgr class
class Trust(object):
    def __init__(self, name, startip, endip, username):
        self.name = name
        self.start_ip = startip
        self.end_ip = endip
        self.user_name = username
