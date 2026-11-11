/**
*  @file	ExcComp.h
*  @brief	Define Exception Compress used in collector

*  @author:     Qi Yang
* @date		2014/11/11
*  @version     Initial version
*  
*  Copyright:   Shanghai Baosight Software Co., Ltd.
*/

#ifndef _BUFFER_API_H_
#define _BUFFER_API_H_

#include "data_types.h"
#include "hd3Struct.h"

#ifdef _WIN32
#	ifdef BUFFER_API_DLL
#		define BUFFER_API_EXPORTS __declspec(dllexport)
#	else
#       ifdef UNITTEST
#			define BUFFER_API_EXPORTS
#		else
#			define BUFFER_API_EXPORTS __declspec(dllimport)
#		endif
#	endif
#else
#	define BUFFER_API_EXPORTS
#endif


#ifdef __cplusplus
extern "C"
{
#endif

#define DEFAULT_SEND_QUEUE_ID			1 //连接时发送给Buffer的QueueID
#define BUFFER							"hdBuffer"
#define BUFFER_SEMA_NAME				"buffer_sema"

BUFFER_API_EXPORTS
int32 buffer_init(const char* szIP, uint16 nPort, const char* szBakIP, uint16 nBakPort,  HD3HANDLE* pBufferHandle);

BUFFER_API_EXPORTS
int32 buffer_release(HD3HANDLE hBuffer);

BUFFER_API_EXPORTS
int32 buffer_login(HD3HANDLE hBuffer, const char* szUser, const char* szPwd);

BUFFER_API_EXPORTS
int32 buffer_send_records(HD3HANDLE hBuffer, int32 nRecNum, uint32 nTagIDs[], HD3Record records[], int32 nErrCodes[]);

BUFFER_API_EXPORTS
void buffer_set_charset(HD3HANDLE hBuffer, enum HD3_CHARSET charset);

#ifdef __cplusplus
}
#endif

#endif//_EXC_COMP_H_
