/** 
* @file
* @brief		Error code definition of Real-time Database (110000~119999)
* @author		Chunfeng Shen
* @date		2009/05/10
* @version		Initial Version
*
* Copyright: Shanghai Baosight Software Co, Ltd
*/

#ifndef ERROR_CODE_H_
#define ERROR_CODE_H_

#define RD_SUCCESS 						0		//success code 

#define EC_RD_BASENO					110000
#define EC_RD_SYSTEM_MAX_NO				20000


/************************************************************************/
/*                 Beagle ErrorCode                                     */
/************************************************************************/
#define EC_LM_ERROR_CODE_BASE (EC_RD_BASENO +(-20000))	//beagle错误码起始90000 //Beagle  starting error code 
#define EC_LM_INVALID_LICENSE  (EC_LM_ERROR_CODE_BASE + 1 )  //许可证不合法 //Invalid license 
#define EC_LM_LICENSE_NOT_OPEN  (EC_LM_ERROR_CODE_BASE + 2 )  //许可证没有打开 //License not opened
#define EC_LM_KEY_NOT_FOUND  (EC_LM_ERROR_CODE_BASE + 3 )  //信息项不存在   //License key not found
#define EC_LM_INVALID_LICENSE_CODE  (EC_LM_ERROR_CODE_BASE + 4 )  //产品代码不合法   //invalid license code
#define EC_LM_CANT_FIND_LICENSE_CODE  (EC_LM_ERROR_CODE_BASE + 5 )  //许可证文件中不存在匹配的产品代码  //Can not find license code
#define EC_LM_INVALID_CHECK_MODE  (EC_LM_ERROR_CODE_BASE + 6 )  //错误的许可证检查模式   //Invalid license check mode
#define EC_LM_INVALID_PARAMETER  (EC_LM_ERROR_CODE_BASE + 7 )  //错误的输入参数   //Invalid parameter
#define EC_LM_NOT_ENOUGH_MEMORY  (EC_LM_ERROR_CODE_BASE + 8 )  //内存不足   //Insufficient memory
#define EC_LM_CANT_OPEN_LICENSE_FILE  (EC_LM_ERROR_CODE_BASE + 10 )  //无法打开许可证文件  //Can not open license file 
#define EC_LM_CANT_READ_LICENSE_ROOT  (EC_LM_ERROR_CODE_BASE + 11 )  //无法读取许可证文件的根节点  //Can not read license file root 
#define EC_LM_INVALID_KEY_FORMAT  (EC_LM_ERROR_CODE_BASE + 12 )  //错误的密钥格式   //Invalid license key format
#define EC_LM_INVALID_SIGNATURE_FORMAT  (EC_LM_ERROR_CODE_BASE + 13 )  //错误的签名格式   //Invalid license signature format
#define EC_LM_INVALID_SERIAL_NUMBER  (EC_LM_ERROR_CODE_BASE + 14 )  //错误的序列号   //Invalid license serial number
#define EC_LM_LICENSE_NOT_START  (EC_LM_ERROR_CODE_BASE + 15 )  //许可证尚未开始   //License not started
#define EC_LM_LICENSE_EXPIRED  (EC_LM_ERROR_CODE_BASE + 16 )  //许可证已过期   //License expired
#define EC_LM_INVALID_PROJECT_NAME  (EC_LM_ERROR_CODE_BASE + 20 )  //加密狗内的项目名称不匹配   //Mismatched project name of dongle
#define EC_LM_INVALID_PUBLIC_KEY  (EC_LM_ERROR_CODE_BASE + 21 )  //加密狗内的密钥不匹配   //Mismatched encryption key of dongle
#define EC_LM_INVALID_HOST_MAC  (EC_LM_ERROR_CODE_BASE + 22 )  //主机MAC地址不匹配   //Mismatched host MAC
#define EC_LM_GET_MAC_FAILED  (EC_LM_ERROR_CODE_BASE + 23 )  //获取主机MAC地址失败   //Get host MAC failed
#define EC_LM_NO_ROOT_PRIVILEGE  (EC_LM_ERROR_CODE_BASE + 24 )  //没有root权限   //No root permission
#define EC_LM_SOCKET_OPERATE_ERROR  (EC_LM_ERROR_CODE_BASE + 25 )  //Socket操作失败   //Socket operation failed
#define EC_LM_WRONG_OS_TYPE  (EC_LM_ERROR_CODE_BASE + 30 )  //非授权的操作系统   //Unauthorized operating system
#define EC_LM_NOT_IMPLEMENTED_YET  (EC_LM_ERROR_CODE_BASE + 90)  //功能未实现   //Unfulfilled function

#define EC_LM_ERROR_FROM_SENTINEL  (EC_RD_BASENO +(-19800))  //来自圣天狗的错误码LM_ERROR_FROM_SENTINEL90200	// error codes from sentinel 90200
#define EC_LM_SENTINEL_INVALID_LICENSE  (EC_LM_ERROR_FROM_SENTINEL + 3)  //找不到硬件许可证 //Sentinel license not found
#define EC_LM_SENTINEL_UNIT_NOT_FOUND  (EC_LM_ERROR_FROM_SENTINEL + 226)  //找不到指定的硬件许可证键值 //Sentinel license key not found
#define EC_LM_HASP_LOGIN_FAILED (EC_LM_ERROR_FROM_SENTINEL+ 9001)		//hasp_login failed //Login hasp failed
#define EC_LM_HASP_GETSIZE_FAILED (EC_LM_ERROR_FROM_SENTINEL+ 9002)		//hasp_get_size failed   //Get hasp size failed
#define EC_LM_HASP_READ_FAILED (EC_LM_ERROR_FROM_SENTINEL+ 9003)	//hasp_read failed  //Read hasp failed
#define EC_LM_HASP_LOGOUT_FAILED (EC_LM_ERROR_FROM_SENTINEL+ 9004)	//hasp_logout failed   //logout hasp failed		
#define EC_LM_HASP_INVALID_LICTEMP	(EC_LM_ERROR_FROM_SENTINEL+ 9005)	//硬件狗许可证模板文件不存在或打开失败 //Sentinel license template file does not exist or opened failed
#define EC_LM_EC_BASIC_DOG_NOMEMORY	(EC_LM_ERROR_FROM_SENTINEL+ 9902)	//硬件狗内存异常 //Sentinel memory error


/************************************************************************/
/*                 operator system error (110001 ~ 110500)              */
/************************************************************************/
#define EC_RD_OS_BASENO					(EC_RD_BASENO + 0)
/* System error */
#define EC_RD_SYS_BASE					(EC_RD_BASENO + 0)
#define EC_RD_SYS_NO_FILE_OR_DIR		(EC_RD_SYS_BASE + 2)//文件不存在 //File does not exsit
#define EC_RD_INVALID_INPUT_ARGUMENT	(EC_RD_SYS_BASE + 3)//无效的输入参数 //Invalid input parameter
#define EC_RD_SYS_PERMISSION_DENY		(EC_RD_SYS_BASE + 13)//无访问权限 //No visit permission
#define EC_RD_SYS_INVALID_ARGUMENT		(EC_RD_SYS_BASE + 22)//无效的文件访问参数 //Invalid file access parameter
#define EC_RD_SYS_FATAL_EXCEPTION		(EC_RD_SYS_BASE + 25)//发生异常 //Exception occurred

/*time*/
#define EC_HD_TIME_BASENO							(EC_RD_BASENO + 190)
#define EC_HD_TIME_INVALID_PONTER					(EC_HD_TIME_BASENO + 1)//不合法的指针，指针为空 //Invalid pointer,pointer is null
#define EC_HD_TIME_INVALID_SECOND					(EC_HD_TIME_BASENO + 2)//不合法的时间参数秒，秒小于零 //Invalid time parameter, second is less than zero
#define EC_HD_TIME_CONVET_SEC_TO_RDTIME				(EC_HD_TIME_BASENO + 3)//转化秒到时间戳失败 //Convert seconds to timestamp failed
#define EC_HD_TIME_CONVET_RDTIME_TO_SEC				(EC_HD_TIME_BASENO + 4)//转化时间戳到秒失败 //Convert timestamp to seconds failed
#define EC_HD_TIME_GET_LOCAL_TIMEZONE_FAILED		(EC_HD_TIME_BASENO + 5)//获取本地时区失败 //Get local timezone failed

/* File */
#define EC_RD_OS_FILE_BASE				(EC_RD_BASENO + 200)
#define EC_RD_OS_FILE_OPEN				(EC_RD_OS_FILE_BASE + 1)//打开文件失败 //Open file failed
#define EC_RD_OS_FILE_CREATE			(EC_RD_OS_FILE_BASE + 2)//创建文件失败 //Create file failed
#define EC_RD_OS_FILE_CLOSE				(EC_RD_OS_FILE_BASE + 3)//关闭文件失败 //Close file failed
#define EC_RD_OS_FILE_DELETE			(EC_RD_OS_FILE_BASE + 4)//删除文件失败 //Delete file failed
#define	EC_RD_OS_FILE_SEEK				(EC_RD_OS_FILE_BASE + 5)//磁头寻址失败 //Head addressing failed
#define	EC_RD_OS_FILE_READ				(EC_RD_OS_FILE_BASE + 6)//读取文件失败 //Read file failed
#define	EC_RD_OS_FILE_WRITE				(EC_RD_OS_FILE_BASE + 7)//写入文件失败 //Write file failed
#define EC_RD_OS_FILE_FLUSH				(EC_RD_OS_FILE_BASE + 8)//刷新文件失败 //Flush file failed
#define EC_RD_OS_FILE_TRUNC				(EC_RD_OS_FILE_BASE + 9)//截断文件失败 //Truncate file failed

#define EC_RD_OS_FILE_CREATE_MAP		(EC_RD_OS_FILE_BASE + 10)//创建内存映射失败 //Create memory map file failed
#define EC_RD_OS_FILE_CLOSE_MAP			(EC_RD_OS_FILE_BASE + 11)//关闭内存映射失败 //Close memory map file failed
#define EC_RD_OS_FILE_MAP_VIEW			(EC_RD_OS_FILE_BASE + 12)//内存映射失败 //Memory map failed
#define EC_RD_OS_FILE_UNMAP				(EC_RD_OS_FILE_BASE + 13)//解除内存映射失败 //Relieve map file failed
/* Directory */
#define EC_RD_OS_DIR_BASENO				(EC_RD_BASENO + 220)
#define EC_RD_OS_DIR_INVALID_PATH_NAME	(EC_RD_OS_DIR_BASENO + 1)//目录路径名无效 //Invalid directory path name
#define EC_RD_OS_DIR_CREATE				(EC_RD_OS_DIR_BASENO + 2)//创建目录失败 //Create directory failed
#define EC_RD_OS_DIR_REMOVE				(EC_RD_OS_DIR_BASENO + 3)//删除目录失败 //Delete directory failed
#define EC_RD_OS_DIR_FIND_FILE			(EC_RD_OS_DIR_BASENO + 4)//枚举文件失败 //Enumerate files failed
#define EC_RD_OS_DIR_FIND_NO_FILE		(EC_RD_OS_DIR_BASENO + 5)//枚举文件完成 //Enumerate files finished

/* Memory */
#define EC_RD_OS_MEM_BASENO				(EC_RD_BASENO + 240)
#define EC_RD_OS_MEM_MALLOC				(EC_RD_OS_MEM_BASENO + 1)//分配内存失败 //Malloc failed
#define	EC_RD_OS_MEM_SHAREMEM_CREATE	(EC_RD_OS_MEM_BASENO + 2)//创建共享内存失败 //Create shared memory failed
#define EC_RD_OS_MEM_SHAREMEM_CLOSE		(EC_RD_OS_MEM_BASENO + 3)//关闭共享内存失败 //Close shared memory failed
#define EC_RD_OS_MEM_SHAREMEM_MAP		(EC_RD_OS_MEM_BASENO + 4)//映射共享内存失败 //map shared memory failed
#define	EC_RD_OS_MEM_SHAREMEM_UNMAP		(EC_RD_OS_MEM_BASENO + 5)//解除共享内存映射失败 //Relieve shared memory map failed
#define EC_RD_OS_MEM_NOT_ENOUGH			(EC_RD_OS_MEM_BASENO + 6)//内存不足 //Insufficient memory

/* thread */
#define EC_RD_THREAD_BASENO				(EC_RD_BASENO + 260)
#define EC_RD_THREAD_CREATE				(EC_RD_THREAD_BASENO + 1)//创建线程失败 //Create thread failed
#define EC_RD_THREAD_JOIN				(EC_RD_THREAD_BASENO + 2)//等待线程结束失败 //Wait for the end of thread failed
#define EC_RD_THREAD_TEST_ACTIVE		(EC_RD_THREAD_BASENO + 3)//测试线程活动状态失败 //Test thread activity state failed
#define EC_RD_THREAD_TERMINATE			(EC_RD_THREAD_BASENO + 4)//终止线程失败 //Terminate thread failed
/* lock */
#define EC_RD_OS_LOCK_BASENO			(EC_RD_BASENO + 280)
#define EC_RD_OS_LOCK_INIT				(EC_RD_OS_LOCK_BASENO + 1)//初始化锁失败 //Initialize the lock failed
#define EC_RD_OS_LOCK_TIMEOUT			(EC_RD_OS_LOCK_BASENO + 2)//申请读写锁超时 //Apply read-write lock timeout
#define EC_RD_LOCK_ACQUIRE_READ			(EC_RD_OS_LOCK_BASENO + 3)//申请读锁失败 //Apply read lock failed
#define EC_RD_LOCK_ACQUIRE_WRITE		(EC_RD_OS_LOCK_BASENO + 4)//申请写锁失败 //Apply write lock failed
#define EC_RD_SEMA_INIT					(EC_RD_OS_LOCK_BASENO + 5)//信号量初始化失败 //Initialize semaphore failed
#define EC_RD_SEMA_DESTROY				(EC_RD_OS_LOCK_BASENO + 6)//信号量销毁失败 //Destroy semaphore failed
#define EC_RD_SEMA_ACQUIRE				(EC_RD_OS_LOCK_BASENO + 7)//申请信号量失败 //Apply semaphore failed
#define EC_RD_SEMA_RELEASE				(EC_RD_OS_LOCK_BASENO + 8)//释放信号量失败 //Release semaphore failed
#define EC_RD_SEMA_TRYACQUIRE			(EC_RD_OS_LOCK_BASENO + 9)//尝试申请信号量失败 //Try to apply semaphore failed
#define EC_RD_PROC_MUTEX_INIT					(EC_RD_OS_LOCK_BASENO + 10)//mutex初始化失败 //Initialize mutex failed
#define EC_RD_PROC_MUTEX_DESTROY				(EC_RD_OS_LOCK_BASENO + 11)//mutex销毁失败 //Destroy mutex failed
#define EC_RD_PROC_MUTEX_ACQUIRE				(EC_RD_OS_LOCK_BASENO + 12)//申请mutex失败 //Apply mutex failed
#define EC_RD_PROC_MUTEX_RELEASE				(EC_RD_OS_LOCK_BASENO + 13)//释放mutex失败 //Release mutex failed
#define EC_RD_PROC_MUTEX_NULL					(EC_RD_OS_LOCK_BASENO + 14)//mutex为NULL //Mutex is null
/* Process */
#define EC_RD_PROCESS_BASENO			(EC_RD_BASENO + 300)
#define EC_RD_PROCESS_SPAWN				(EC_RD_PROCESS_BASENO + 1)//创建进程失败 //Create process failed
#define EC_RD_PROCESS_WAIT_TIMEOUT		(EC_RD_PROCESS_BASENO + 2)//等待进程结束超时 //Wait for the end of process timeout
#define EC_RD_PROCESS_WAIT_ERROR		(EC_RD_PROCESS_BASENO + 3)//等待进程结束失败 //Wait for the end of process failed
#define EC_RD_PROCESS_TERMINATE			(EC_RD_PROCESS_BASENO + 4)//结束进程失败 //Terminate process failed
#define EC_RD_PROCESS_PROCESS_NOT_EXIST	(EC_RD_PROCESS_BASENO + 5)//进程不存在 //Process does not exist
#define EC_RD_PROCESS_WCSTOMBS_FAILED	(EC_RD_PROCESS_BASENO + 6)//宽字节转换为多字节失败 //Convert wide bytes to multi bytes failed

/*Language*/
#define EC_RD_LANGUAGE_BASENO			(EC_RD_BASENO + 310)
#define EC_RD_LANGUAGE_ICONV_OPEN		(EC_RD_LANGUAGE_BASENO + 1)//编码转换接口打开失败 //Failed to open the code conversion interface
#define EC_RD_LANGUAGE_ICONV			(EC_RD_LANGUAGE_BASENO + 2)//编码转换失败 //Failed to conver code
#define EC_RD_LANGUAGE_ILLEGAL_INPUT	(EC_RD_LANGUAGE_BASENO + 3)//编码转换无效参数 //Illegal parameter for code conversion

/* event */
#define EC_RD_EVENT_BASENO				(EC_RD_BASENO + 320)
#define EC_RD_EVENT_RELEASE				(EC_RD_EVENT_BASENO + 1)//释放事件失败 //Release event failed
#define EC_RD_EVENT_INIT				(EC_RD_EVENT_BASENO + 2)//初始化事件失败 //Initialize event failed
#define EC_RD_EVENT_WAIT_TIMEOUT		(EC_RD_EVENT_BASENO + 3)//等待事件超时 //Wait for the event timeout
#define EC_RD_EVENT_MUTEX_NOT_RELEASE	(EC_RD_EVENT_BASENO + 4)//事件对应锁没有释放 //The mutex of event not released
#define EC_RD_EVENT_GET_CLOCK_TIME		(EC_RD_EVENT_BASENO + 5)//获取系统时间错误 //Get system time failed

/* Network */
#define EC_RD_NETWORK_BASENO			(EC_RD_BASENO + 330)
#define EC_RD_NET_SOCKET_VERSION		(EC_RD_NETWORK_BASENO + 1)//套接字版本不兼容 //Sockets version is not compatible
#define EC_RD_NET_CREATE_SOCKET			(EC_RD_NETWORK_BASENO + 2)//创建套接字失败 //Create socket failed
#define EC_RD_NET_SOCKET_BIND			(EC_RD_NETWORK_BASENO + 3)//套接字绑定失败 //Bind socket failed
#define EC_RD_NET_CREATE_COMPLETE_PORT	(EC_RD_NETWORK_BASENO + 4)//创建完成端口失败 //Create completion port failed
#define EC_RD_NET_SOCKET_LISTEN			(EC_RD_NETWORK_BASENO + 5)//套接字监听失败 //Listen to socket failed
#define EC_RD_NET_SOCKET_ACCEPT			(EC_RD_NETWORK_BASENO + 6)//套接字接收连接失败 //Receive the connection of socket failed
#define EC_RD_NET_SOCKET_RECEIVE		(EC_RD_NETWORK_BASENO + 7)//套接字接受数据失败 //Receive the data of socket failed
#define EC_RD_NET_SOCKET_SEND			(EC_RD_NETWORK_BASENO + 8)//套接字发送数据失败 //Send the data of socket failed
#define EC_RD_NET_SOLARIS_ASSOCIATE		(EC_RD_NETWORK_BASENO + 9)//Solaris下联合端口失败 //Associate port in solaris failed
#define EC_RD_PROACTOR_EPOLL_CREATE		(EC_RD_NETWORK_BASENO + 10)//Epoll端口创建失败 //Create Epoll port failed
#define EC_RD_PROACTOR_EPOLL_CTL		(EC_RD_NETWORK_BASENO + 11)//Epoll控制失败 //Control Epoll port failed
#define EC_RD_NET_INVALID_INPUT			(EC_RD_NETWORK_BASENO + 12)//网络函数不合法输入 //Invalid input of net functions
#define EC_RD_NET_BLOCK					(EC_RD_NETWORK_BASENO + 13)//网络阻塞错误 //Network blocking
#define EC_RD_NET_SHUTDOWN				(EC_RD_NETWORK_BASENO + 14)//ShutDown网络失败 //Shutdown the network failed
#define EC_RD_NET_CONN_RESET			(EC_RD_NETWORK_BASENO + 15)//连接重置错误 //Reset the connection failed
#define EC_RD_NET_SELECT_DETECT_ERR		(EC_RD_NETWORK_BASENO + 16)//Select探察到错误 //Select detected error
#define EC_RD_NET_SELECT_TIMEOUT		(EC_RD_NETWORK_BASENO + 17)//Select超时 //Select timeout
#define EC_RD_NET_CONNECT_TIMEOUT		(EC_RD_NETWORK_BASENO + 18)//网络连接超时  //Network connection timeout
#define EC_RD_NET_SEND_TIMEOUT			(EC_RD_NETWORK_BASENO + 19)//网络发送超时 //Network send timeout
#define EC_RD_NET_RECV_TIMEOUT			(EC_RD_NETWORK_BASENO + 20)//网络接收超时 //Network receive timeout
#define EC_RD_NET_NOT_CONNECT			(EC_RD_NETWORK_BASENO + 21)//网络连接不通 //Network not connected
#define EC_RD_NET_SEND_NOTSOCK			(EC_RD_NETWORK_BASENO + 22)//网络发送套接字无效 //Invalid socket in network sending 
#define EC_RD_NET_SERVER_BUFFER_FULL	(EC_RD_NETWORK_BASENO + 23)//网络发送缓冲区已满 //The server buffer of network is full
#define EC_RD_NET_WORKTHREAD_NUM		(EC_RD_NETWORK_BASENO + 24)//工作线程个数不合法 //The number of work threads is invalid
#define EC_RD_NET_INIT_INVALID_PARAM	(EC_RD_NETWORK_BASENO + 25)//初始化参数非法 //Initialization parameters are invalid
#define EC_RD_NET_INVALID_PACKAGE		(EC_RD_NETWORK_BASENO + 26)//网络服务器接收数据包不合法 //The package received by the network server is invalid
#define EC_RD_NET_WRONG_IO_COUNT		(EC_RD_NETWORK_BASENO + 27)//网络数据收发消息计数值不一致 //The count of data sending and the count of data receiving in network are not consistent
#define EC_RD_SOCK_CLOSED				(EC_RD_NETWORK_BASENO + 28)//socket已经被关闭 //Socket already closed
#define EC_RD_NET_GET_MAC				(EC_RD_NETWORK_BASENO + 29)//获取MAC地址失败 //Get MAC address failed
#define EC_RD_NET_GETSOCKETIFNO_NOT_EXSIST	(EC_RD_NETWORK_BASENO + 30)//查询socket信息不存在 //Get MAC address failed
#define EC_RD_NET_GET_HOST_BY_NAME		(EC_RD_NETWORK_BASENO + 31)//获取域名IP失败//Get Host Addresss by name  failed
#define EC_RD_NET_QUIT				(EC_RD_NETWORK_BASENO + 32)//网络退出//network quit
#define EC_RD_NET_ALARMNOTIFY_OVERMAX	(EC_RD_NETWORK_BASENO + 33)//报警通知注册超出上限 //alarm notify over max limit

/*sig*/
#define EC_RD_SIGNAL_BASENO			(EC_RD_BASENO + 360)
#define EC_RD_SIGNAL_REG_FAIL		(EC_RD_NETWORK_BASENO + 1)//注册信号量失败 // Register semaphore failed


/************************************************************************/
/*                      NetClient                                       */
/************************************************************************/
#define EC_RD_NETCLIENT_BASENO				(EC_RD_BASENO + 370)
#define EC_RD_NETCLIENT_SEND_PARTIAL		(EC_RD_NETCLIENT_BASENO + 1)//网络客户端发送数据不完整 //The data sent by network client is partial
#define EC_RD_NETCLIENT_NOT_CONNECT			(EC_RD_NETCLIENT_BASENO + 2)//网络客户端未连接 //Network client is not connected
#define EC_RD_NETCLIENT_INVALID_IP			(EC_RD_NETCLIENT_BASENO + 3)//网络客户端验证IP错误 //Verify IP of network client failed
#define EC_RD_NETCLIENT_INVALID_TIMEOUT		(EC_RD_NETCLIENT_BASENO + 4)//网络客户端验证超时错误 //Verify network client timeout failed
#define EC_RD_NETCLIENT_INVALID_PARAM		(EC_RD_NETCLIENT_BASENO + 5)//网络客户端验证错误 //Verify network client failed
#define EC_RD_NDK_CONNECT				    (EC_RD_NETCLIENT_BASENO + 6)//网络连接失败 //Network connection failed


#define EC_RD_NDK_BASENO				            (EC_RD_BASENO + 330)
#define EC_RD_NETWORK_MAX				             EC_RD_NDK_CONNECT//网络最大错误码 //Maximum error code for network



/************************************************************************/
/*                      NetMgr  (110400 ~ 111600)                                        */
/************************************************************************/
#define EC_RD_NETRBTREE_BASENO			(EC_RD_BASENO + 400)
#define EC_RD_NETRBTREE_INSERT		(EC_RD_NETRBTREE_BASENO + 1)//网络红黑树插入失败 //Insert into the network red-black tree failed
#define EC_RD_NETRBTREE_MODIFY		(EC_RD_NETRBTREE_BASENO + 2)//网络红黑树修改失败 //Modify the network red-black tree failed
#define EC_RD_NETRBTREE_NODE_EXIST	(EC_RD_NETRBTREE_BASENO + 3)//网络红黑树插入失败，节点己存在 //Insert into the network red-black tree failed, the node already existed

#define EC_RD_CLINET_MAC_CHECK			(EC_RD_NETRBTREE_BASENO + 4)//客户端MAC地址校验失败 //Verify the MAC address of client failed
#define EC_RD_NET_CONNECT_NUMBER_LIMIT	(EC_RD_NETRBTREE_BASENO + 5)//客户端连接数目超过服务端许可证限制 //The number of connected clients exceeds the limit of license

#define EC_RD_LIC_SUPPORTZT_LIMIT			(EC_RD_NETRBTREE_BASENO + 6)//缺少组态许可证 //No configuration license
#define EC_RD_LIC_SUPPORTSPC_LIMIT			(EC_RD_NETRBTREE_BASENO + 7)//缺少SPC许可证 //No SPC license

#define EC_RD_NET_CLIENT_SOCKET_LIMIT	(EC_RD_NETRBTREE_BASENO + 8)//单个客户端连接数超过上限 //The socket number of single client is bigger than the upper limit

/************************************************************************/
/*                   Kernel    (110600 ~ 111600)                        */
/************************************************************************/

/* tag index */
#define EC_RD_TAG_INDEX_BASENO					(EC_RD_BASENO + 600)
#define EC_RD_TAG_INDEX_MEM_PROP_LINK			(EC_RD_TAG_INDEX_BASENO + 2)//tag点内存属性链表无效 //The list of tag memory properties is invalid
#define EC_RD_TAG_TYPE_REC_LEN_NOT_ACCORDING    (EC_RD_TAG_INDEX_BASENO + 3)//tag类型和记录长度对应关系不正确 //The tag type does not accord with the length of record
#define EC_RD_TAG_INDEX_TAG_ID_ZERO			(EC_RD_TAG_INDEX_BASENO + 4)//tag点ID为0 //tag id is zero
#define EC_RD_TAG_INDEX_TAG_ID_GREATER_THAN_MAXID		(EC_RD_TAG_INDEX_BASENO + 5)//tag点ID大于最大TagID //tag id is greater then max tag id
#define EC_RD_TAG_INDEX_TAG_DELETE				(EC_RD_TAG_INDEX_BASENO + 6)//tag点已经被删除 //tag is deleted

/* Kernel Global*/
#define EC_RD_KERNEL_GLOBAL_BASENO		(EC_RD_BASENO + 650)
#define EC_RD_KERNEL_QUIT				(EC_RD_KERNEL_GLOBAL_BASENO + 1)//内核退出 //The kernel server quited
#define EC_RD_LICENSE_TAG_NUMBER_LIMIT	(EC_RD_KERNEL_GLOBAL_BASENO + 2)//Tag点数超过许可证文件限制或者数据节点配置的最大许可证点数 //The number of tags exceeds the limit of license
#define EC_RD_KERNEL_INVALID_TAG_TYPE	(EC_RD_KERNEL_GLOBAL_BASENO + 3)//无效的tag类型 //Invalid tag type
#define EC_RD_KERNEL_INVALID_VALUE_LEN	(EC_RD_KERNEL_GLOBAL_BASENO + 4)//无效的记录值长度 //Invalid length of record value
#define EC_RD_INVALID_LICENSE			(EC_RD_KERNEL_GLOBAL_BASENO + 5)//产品许可证无效或试用版到期 //The license is invalid or the trial version is expired
#define EC_RD_FAILED_SET_MAX_FD		(EC_RD_KERNEL_GLOBAL_BASENO + 6)//设置进程可打开的最大句柄数失败 //Set the maximum number of process handles failed
#define EC_RD_QUERY_COND_NO_MEET	(EC_RD_KERNEL_GLOBAL_BASENO + 7)//查询条件不满足 //The query condition is not satisfied
#define EC_RD_NO_PERMIT_DEL_MODIFY_SYS_TAG	(EC_RD_KERNEL_GLOBAL_BASENO + 8)//不可删除或修改系统点 //The system tag can not be deleted or modified

/* Sequential cache */
#define EC_RD_SEQ_CACHE_BASENO			(EC_RD_BASENO + 700)
#define EC_RD_SEQ_CACHE_FILE_POS		(EC_RD_SEQ_CACHE_BASENO + 1)//序列文件读写位置无效 //The read-write position of sequence cache file is invalid
#define EC_RD_SEQ_CACHE_FILE_COUNT		(EC_RD_SEQ_CACHE_BASENO + 2)//序列缓存文件数目无效 //The count of sequence cache files is invalid
#define EC_RD_SEQ_CACHE_FILE_SIZE		(EC_RD_SEQ_CACHE_BASENO + 3)//序列缓存文件大小无效 //The size of sequence cache file is invalid
#define EC_RD_SEQ_CACHE_FILE_STATUS		(EC_RD_SEQ_CACHE_BASENO + 4)//序列缓存文件状态无效 //The status of sequence cache files is invalid
#define EC_RD_SEQ_CACHE_INVALID_POINTER	(EC_RD_SEQ_CACHE_BASENO + 5)//序列缓存文件指针无效 //The pointer of sequence cache files is invalid
#define EC_RD_SEQ_CACHE_INVALID_TAG_ID	(EC_RD_SEQ_CACHE_BASENO + 6)//无效的tagID //Invalid tag ID
#define EC_RD_SEQ_CACHE_NO_FREE_FILE	(EC_RD_SEQ_CACHE_BASENO + 7)//序列缓存文件已满，磁盘写入速度赶不上数据存入速度 //The sequence cache file is full. The speed of disk writing is lower than the speed of data saving

/*sqlite Configure */
#define EC_RD_CONFIGURE_BASENO			(EC_RD_BASENO + 750)
#define EC_RD_CFG_DB_FORMAT				(EC_RD_CONFIGURE_BASENO + 1)//从sqlite数据库读取的数据错误 //The data read from sqlite is wrong
#define EC_RD_CFG_DB_QUERY_NULL			(EC_RD_CONFIGURE_BASENO + 3)//sqlite数据库查询到得字段为空 //The filed found in sqlite is null
#define	EC_RD_DEL_DEFAULT_ITEM			(EC_RD_CONFIGURE_BASENO + 4)//从sqlite数据库中删除默认的字段 //Delete the default field from sqlite
#define EC_RD_HAS_DEPEND_TAG			(EC_RD_CONFIGURE_BASENO + 5)//存在依赖的点 //Point with dependency exsits
#define EC_RD_CFG_DB_COLLECTOR_DEVICE_SCANGROUP_NOT_EXIST	(EC_RD_CONFIGURE_BASENO + 6) //采集器、设备或者扫描组不存在	//The collector, device or scan group does not exist
#define EC_RD_CFG_DB_TAG_NOT_EXIST		(EC_RD_CONFIGURE_BASENO + 7)//Tag点不存在	//The tag does not exist
#define EC_RD_CFG_DB_GROUP_NOT_EXIST		(EC_RD_CONFIGURE_BASENO + 8)//用户组不存在	//The user group does not exist
#define EC_RD_CFG_DB_DIGITALSET_NOT_EXIST		(EC_RD_CONFIGURE_BASENO + 9)//数字量状态集不存在	//The digital set does not exist
#define EC_RD_CFG_DB_COLLECTOR_NOT_EXIST		(EC_RD_CONFIGURE_BASENO + 10)//采集器不存在	//The collector does not exist
#define EC_RD_CFG_DB_DEVICE_NOT_EXIST		(EC_RD_CONFIGURE_BASENO + 11)//设备不存在	//The device does not exist
#define EC_RD_CFG_DB_SCANGROUP_NOT_EXIST		(EC_RD_CONFIGURE_BASENO + 12)//扫描组不存在 //The scan group  does not exist

#define EC_RD_SQLITE_BASENO				(EC_RD_BASENO + 800)
#define EC_RD_SQLITE_ERROR				(EC_RD_SQLITE_BASENO + 1)  //SQL错误或者数据库错误 //SQL error or database error
#define EC_RD_SQLITE_INTERNAL			(EC_RD_SQLITE_BASENO + 2)  //内部逻辑错误 //Sqlite internal logic error
#define EC_RD_SQLITE_PERM				(EC_RD_SQLITE_BASENO + 3)  //访问权限不足 //No sqlite authority
#define EC_RD_SQLITE_ABORT				(EC_RD_SQLITE_BASENO + 4)  //回调请求中断 //The callback request aborted
#define EC_RD_SQLITE_BUSY				(EC_RD_SQLITE_BASENO + 5)   //数据库文件锁定 //The database file is locked
#define EC_RD_SQLITE_LOCKED				(EC_RD_SQLITE_BASENO + 6)   //数据库表锁定 //The database table is locked
#define EC_RD_SQLITE_NOMEM				(EC_RD_SQLITE_BASENO + 7)   //申请内存失败 //Apply for memory failed
#define EC_RD_SQLITE_READONLY			(EC_RD_SQLITE_BASENO + 8)   //试图写一个只读的表 //Try to write a readonly table
#define EC_RD_SQLITE_INTERRUPT			(EC_RD_SQLITE_BASENO + 9)   //sqlite3_interrupt调用中止了当前操作 //The call of sqlite3_interrupt interrupted current operation
#define EC_RD_SQLITE_IOERR				(EC_RD_SQLITE_BASENO + 10)   //磁盘IO错误 //Disk IO error
#define EC_RD_SQLITE_CORRUPT			(EC_RD_SQLITE_BASENO + 11)   //数据库硬盘镜像不完整 //The database disk mirror is incomplete
#define EC_RD_SQLITE_NOTFOUND			(EC_RD_SQLITE_BASENO + 12)   //不使用，找不到表或者记录 //Not used, can not find table or record
#define EC_RD_SQLITE_FULL				(EC_RD_SQLITE_BASENO + 13)   //数据库已满插入失败 //Database is full, insert failed
#define EC_RD_SQLITE_CANTOPEN			(EC_RD_SQLITE_BASENO + 14)   //不能打开数据库文件 //Can not open sqlite file
#define EC_RD_SQLITE_PROTOCOL			(EC_RD_SQLITE_BASENO + 15)  //不使用，数据库锁定协议错误 //Not used, database locking protocol error
#define EC_RD_SQLITE_EMPTY				(EC_RD_SQLITE_BASENO + 16)   //数据库为空 //Database is null
#define EC_RD_SQLITE_SCHEMA				(EC_RD_SQLITE_BASENO + 17)  //数据库框架改变 //Database schema is changed
#define EC_RD_SQLITE_TOOBIG				(EC_RD_SQLITE_BASENO + 18)   //String或BLOB类型超出了长度限制 //The length exceeds the limit of string or blob
#define EC_RD_SQLITE_CONSTRAINT			(EC_RD_SQLITE_BASENO + 19)   //由于违反约束而中止执行 //Execution aborted because of database constraint violation
#define EC_RD_SQLITE_MISMATCH			(EC_RD_SQLITE_BASENO + 20)   //数据类型不匹配 //The data type is not matched
#define EC_RD_SQLITE_MISUSE				(EC_RD_SQLITE_BASENO + 21)   //静态库使用不正确 //Static libraries are uesd incorrectly
#define EC_RD_SQLITE_NOLFS				(EC_RD_SQLITE_BASENO + 22)   //使用了主机不支持的操作系统特性 //Unsupported operating system characteristics of host are used
#define EC_RD_SQLITE_AUTH				(EC_RD_SQLITE_BASENO + 23)   //权限不足 //No enough authority
#define EC_RD_SQLITE_FORMAT				(EC_RD_SQLITE_BASENO + 24)   //备用数据库格式错误 //Standby database format error
#define EC_RD_SQLITE_RANGE				(EC_RD_SQLITE_BASENO + 25)   //sqlite3_bind的第二个参数超出范围 //The second parameter of sqlite3_bind exceeds range
#define EC_RD_SQLITE_NOTADB				(EC_RD_SQLITE_BASENO + 26)   //打开的文件不是数据库文件 //The file opened is not a database file


/*xml Configure*/
#define EC_RD_XML_BASENO			(EC_RD_BASENO + 850)
#define EC_RD_XML_LOAD_FILE			(EC_RD_XML_BASENO + 1)//加载配置文件失败 //Load  configuration file failed
#define EC_RD_XML_FIND_ELEMENT		(EC_RD_XML_BASENO + 2)//查找配置文件元素失败 //Find configuration file element failed
#define EC_RD_XML_GET_ATTR			(EC_RD_XML_BASENO + 3)//获取配置文件元素属性失败 //Get attribute of configuration file element failed
#define EC_RD_XML_INVALID_VALUE		(EC_RD_XML_BASENO + 4)//配置文件元素属性值无效 //The attribute value of configuration file element is invalid
#define EC_RD_XML_ITME_VALUE_LEN	(EC_RD_XML_BASENO + 5)//配置项的值的长度超过4096 //The length of configuration value is bigger than 4096
#define EC_RD_XML_FIND_DECLARE      (EC_RD_XML_BASENO + 6)//查找配置文件声明失败 //Find the declaration of configuration file failed
#define EC_RD_XML_WRITE_FAILED      (EC_RD_XML_BASENO + 7)//写入XML文件失败 //Write xml file failed
#define EC_RD_XML_ADD_ELEMNET_FAILED (EC_RD_XML_BASENO + 8)//xml文件添加结点失败 //Add element into xml file failed
#define EC_RD_XML_ADD_ATTRIBUTE_FAILED (EC_RD_XML_BASENO + 9)//xml文件添加属性失败 //Add attribute into xml file failed

/* Block cache file */
#define EC_RD_BLOCK_CACHE_FILE_BASENO	(EC_RD_BASENO + 900)
#define EC_RD_BLOCK_CACHE_FILE_READ		(EC_RD_BLOCK_CACHE_FILE_BASENO + 1)//读取块缓存文件失败 //Read block cache file failed
#define EC_RD_BLOCK_CACHE_FILE_WRITE	(EC_RD_BLOCK_CACHE_FILE_BASENO + 2)//写块缓存文件失败 //Write block cache file failed
#define EC_RD_ARCHIVE_LOG_FILE_CREATE	(EC_RD_BLOCK_CACHE_FILE_BASENO + 3)//系统日志文件创建失败 //Create system log file failed
#define EC_RD_ARCHIVE_LOG_FILE_READ		(EC_RD_BLOCK_CACHE_FILE_BASENO + 4)//系统日志文件读取失败 //Read system log file failed
#define EC_RD_ARCHIVE_LOG_FILE_WRITE	(EC_RD_BLOCK_CACHE_FILE_BASENO + 5)//系统日志文件写失败 //Write system log file failed
#define EC_RD_TAGNUM_IN_WINDOW_OVERFLOW	(EC_RD_BLOCK_CACHE_FILE_BASENO + 6)//窗口中的Tag点个数不正确 //The number of tags in window is wrong
/* Block */
#define EC_RD_BLOCK_PARSE				(EC_RD_BLOCK_CACHE_FILE_BASENO + 7)//文件块解析错误 //Parse file block failed

/* Archive */
#define EC_RD_ARCHIVE_BASENO					(EC_RD_BASENO + 950)
#define EC_RD_ARCHIVE_FILE_READ					(EC_RD_ARCHIVE_BASENO + 1)//读取归档文件失败 //Read archive file failed
#define EC_RD_ARCHIVE_FILE_WRITE				(EC_RD_ARCHIVE_BASENO + 2)//写归档文件失败 //Write achive file failed
#define EC_RD_ARCHIVE_INVALID_FILE_INDEX		(EC_RD_ARCHIVE_BASENO + 3)//无效的归档文件index //The index of archive file is invalid
#define EC_RD_ARCHIVE_LIST_FILE_NUM				(EC_RD_ARCHIVE_BASENO + 4)//归档文件个数不正确 //The number of archive files is wrong
#define EC_RD_ARCHIVE_REMOVE_FILE_FROM_LIST		(EC_RD_ARCHIVE_BASENO + 5)//从归档文件队列中移除文件失败 //Remove file from the list of archive files failed
#define EC_RD_ARCHIVE_ADD_FILE_TO_LIST			(EC_RD_ARCHIVE_BASENO + 6)//归档文件添加到队列中失败 //Add file into the list of archive files failed
#define EC_RD_ARCHIVE_FILENO_NOT_COMPATIBLE		(EC_RD_ARCHIVE_BASENO + 7)//归档文件中插入记录时FileNo不匹配 //When inserting record into archive file, the FileNo is not matched
#define EC_RD_ARCHIVE_FILE_NO_SPACE_TO_INSERT	(EC_RD_ARCHIVE_BASENO + 8)//归档文件没有足够的空间进行记录的插入 //No enough space to insert record into archive file
#define EC_RD_ARCHIVE_FILE_LOG_PARSE_ERROR		(EC_RD_ARCHIVE_BASENO + 9)//归档文件初始化的时候解析日志中记录内容的格式不正确 //The content format recorded in parse log When initializing the archive file is incorrect

/* log File */
#define EC_RD_LOG_FILE_BASENO			(EC_RD_BASENO + 1000)
#define EC_RD_NO_SUCH_OBJECT			(EC_RD_LOG_FILE_BASENO + 1)//日志对象不存在 //The log object does not exist
#define EC_RD_NO_SUCH_PROCESS			(EC_RD_LOG_FILE_BASENO + 2)//日志流程不存在 //The log process does not exist
#define EC_RD_LOG_INVALID_READ			(EC_RD_LOG_FILE_BASENO + 3)//Tag点恢复时读取内容不正确 //When recovering tag, the content read is not correct
#define EC_RD_LOG_CATEGORY_NOT_FOUND	(EC_RD_LOG_FILE_BASENO + 4)//日志中的category无法找到 //Can not find category in log file

/* B+ tree */
#define EC_RD_BTREE_BASENO				(EC_RD_BASENO + 1050)
#define EC_RD_BTREE_INIT			    (EC_RD_BTREE_BASENO + 1)//btree初始化失败 //Btree initialization failed
#define EC_RD_BTREE_CREATE_FILE			(EC_RD_BTREE_BASENO + 2)//Btree创建文件失败 //Btree failed in creating file
#define EC_RD_BTREE_READ_NODE			(EC_RD_BTREE_BASENO + 3)//Btree读取节点失败 //Btree failed in reading node
#define EC_RD_BTREE_WRITE_NODE			(EC_RD_BTREE_BASENO + 4)//Btree写节点失败 //Btree failed in writing node
#define EC_RD_BTREE_SPLIT				(EC_RD_BTREE_BASENO + 5)//Btree分裂失败 //Btree split failed
#define EC_RD_BTREE_BINARY_QUERY		(EC_RD_BTREE_BASENO + 6)//Btree二分查找失败 //Btree binary search failed
#define EC_RD_BTREE_TAGNUM_OVERFLOW		(EC_RD_BTREE_BASENO + 7)//Btree中Tag点个数不正确 //The number of tags in btree is incorrect
#define EC_RD_BTREE_INSERT_DUPLICATE	(EC_RD_BTREE_BASENO + 8)//Btree插入重复 //Inserting into btree is duplicated
#define EC_RD_DS_RBTREE_NODE_EXIST		(EC_RD_BTREE_BASENO + 9)//Btree节点不存在 //The node of btree does not exist
/* Data source manager */
#define EC_RD_DATA_SOURCE_BASENO				(EC_RD_BASENO + 1100)
#define EC_RD_DATA_SOURCE_ADD_TAG_DUPLICATE		(EC_RD_DATA_SOURCE_BASENO + 1)//新增的数据源名称重复 //The name of the new added data source is duplicated
#define EC_RD_DATA_SOURCE_DEL_TAG_NO_EXIST		(EC_RD_DATA_SOURCE_BASENO + 2)//删除的数据源不存在 //The data source to be deleted does not exist
#define EC_RD_DATA_SOURCE_MODIFY_TAG_NO_EXIST	(EC_RD_DATA_SOURCE_BASENO + 3)//修改的数据源不存在 //The data source to be modified does not exist
#define EC_RD_DATA_SOURCE_INVALID_OPER_TYPE		(EC_RD_DATA_SOURCE_BASENO + 4)//系统恢复过程中操作类型无效 //When recovering system, the operation type is invalid
#define EC_RD_DATA_SOURCE_INVALID_OPER_STATE	(EC_RD_DATA_SOURCE_BASENO + 5)//系统恢复过程中操作状态无效 //When recovering system, the operation status is invalid
#define EC_RD_DATA_SOURCE_ADD_TAG_INVALID_TAG_ID	(EC_RD_DATA_SOURCE_BASENO + 6)//新增的数据源TagID不合法，小于或等于最大TagID //The new added tag ID of data source is invalid. It should be less than or equal to maximum tag ID
#define EC_RD_DATA_SOURCE_INVALID_TAG_PREFIX		(EC_RD_DATA_SOURCE_BASENO + 7)//新增数据源名前缀与实时数据库系统点相同，不合法 //It is invald that The prefix of new added data source is the same as the system tag


/* Record manager */
#define EC_RD_DATA_BASENO						(EC_RD_BASENO + 1150)
#define EC_RD_DATA_MODIFY_NO_EXIST				(EC_RD_DATA_BASENO + 1)//要修改的记录不存在 //The record to be modified does not exist
#define EC_RD_DATA_DELETE_NO_EXIST				(EC_RD_DATA_BASENO + 2)//要删除的记录不存在 //The record to be deleted does not exist
#define EC_RD_DATA_QUERY_NO_EXIST				(EC_RD_DATA_BASENO + 3)//插值查询记录不存在 //The record for interpolation query do not exist
#define EC_RD_DATA_QUERY_SNAPSHOT_NO_EXIST		(EC_RD_DATA_BASENO + 4)//查询的内存快照不存在 //The queried memory snapshot does not exist
#define EC_RD_DATA_QUERY_SNAPSHOT_FAILED 		(EC_RD_DATA_BASENO + 5)//查询内存快照失败 //Query memory snapshot failed
#define EC_RD_DATA_QUERY_HALT_RECORD			(EC_RD_DATA_BASENO + 6)//插值查询点为停机记录 //The records for interpolation query are halt records
#define EC_RD_DATA_SAVE_SNAPSHOT_FAILED			(EC_RD_DATA_BASENO + 7)//存储数据失败 //Save snapshot failed
#define EC_RD_DATA_INTERVAL_NO_SUPPORT			(EC_RD_DATA_BASENO + 8)//string或blob类型不支持插值查询 //The interpolation query is not supported in string or blob
#define EC_RD_DATA_QUERY_INTERVAL_FAILED		(EC_RD_DATA_BASENO + 9)//插值查询失败 //Interpolation query failed
#define EC_RD_DATA_SAVE_TIME_DISORDER			(EC_RD_DATA_BASENO + 10)//存储数据时间乱序 //The time of saving data is disorder
#define EC_RD_DATA_QUERY_TIME_DISORDER			(EC_RD_DATA_BASENO + 11)//查询起始时间混乱 //The query starting time chaos
#define EC_RD_DATA_TIME_STAMP_EXCEED			(EC_RD_DATA_BASENO + 12)//记录时间戳超过允许的最大偏差 //Record timestamp exceeds max time devation
#define EC_RD_DATA_TIME_STAMP_TOO_OLD			(EC_RD_DATA_BASENO + 13)//记录时间戳太老，记录被丢弃 //Record timestamp too old, discard it

/*kernel msg input param check*/
#define EC_RD_KERNEL_MSG_BASENO					(EC_RD_BASENO + 1200)
#define EC_RD_KERNEL_MSG_POINT_ID				(EC_RD_KERNEL_MSG_BASENO + 1)//内核消息解析数据源ID无效 //When parsing message in kernel, the tag ID is invalid
#define EC_RD_KERNEL_MSG_REC_TIME				(EC_RD_KERNEL_MSG_BASENO + 2)//内核消息解析时间值错误 //When parsing message in kernel, the time is wrong
#define EC_RD_KERNEL_MSG_COMP_TYPE				(EC_RD_KERNEL_MSG_BASENO + 3)//输入的压缩类型错误 //When parsing message in kernel, the compression type is wrong
#define EC_RD_KERNEL_MSG_COLLECT_STATUS			(EC_RD_KERNEL_MSG_BASENO + 4)//内核消息解析向不采集的点存储数据 //When parsing message in kernel, try to save data into a non-archived tag
#define EC_RD_KERNEL_MSG_LEN_STRING				(EC_RD_KERNEL_MSG_BASENO + 5)//内核消息解析字符串长度错误 //When parsing message in kernel, the length of string is wrong
#define EC_RD_KERNEL_MSG_LEN_MSG				(EC_RD_KERNEL_MSG_BASENO + 6)//内核消息解析消息长度错误 //When parsing message in kernel, the length of message is wrong
#define EC_RD_KERNEL_MSG_POINT_TYPE				(EC_RD_KERNEL_MSG_BASENO + 7)//输入的数据源类型无效 //When parsing message in kernel, the tag type is invalid
#define EC_RD_KERNEL_MSG_COUNT					(EC_RD_KERNEL_MSG_BASENO + 8)//内核消息解析数目无效 //When parsing message in kernel, the count is invalid
#define EC_RD_KERNEL_MSG_INVALID_PARAM			(EC_RD_KERNEL_MSG_BASENO + 9)//内核消息解析无效参数 //When parsing message in kernel, the parameter is invalid
#define EC_RD_KERNEL_MSG_INTERP_QUERY_MODE		(EC_RD_KERNEL_MSG_BASENO + 10)//输入的插值查询模式不合法 //When parsing message in kernel, the mode of interpolation query is invalid


/*digital set for kernel*/
#define EC_RD_DIGITALSET_KERNEL_BASENO			(EC_RD_BASENO + 1250)
#define EC_RD_DIGITALSET_NAME_DUPLICATE			(EC_RD_DIGITALSET_KERNEL_BASENO + 1)//数字量状态集名称重复 //The name of digital set is duplicated
#define EC_RD_DIGITALSET_NO_ENOUGH_SPACE		(EC_RD_DIGITALSET_KERNEL_BASENO + 2)//数字量状态集分配空间不足 //No enough space for digital set
#define EC_RD_DIGITALSET_STATE_COUNT_OVER		(EC_RD_DIGITALSET_KERNEL_BASENO + 3)//数字量状态集状态个数超限 //The status count of digital set exceeds the upper limit
#define EC_RD_DIGITALSET_DEFAULT_DIGITALSET		(EC_RD_DIGITALSET_KERNEL_BASENO + 4)//默认数字量状态集不可被修改或删除 //The default digital set can not be modified or deleted

/************************************************************************/
/*                  SDKDialog  (111600 ~ 112000)                                          */
/************************************************************************/
#define EC_HD_SDK_BASENO					(EC_RD_BASENO + 1600)

#define  EC_RD_ADDSERVER_IP_NULL			(EC_HD_SDK_BASENO + 1)//添加服务器，IP为null //When adding server, the IP is null
#define	 EC_RD_ADDSERVER_IP_INVALID			(EC_HD_SDK_BASENO + 2)//添加服务器，IP不合法 //When adding server, the IP is invalid
#define  EC_RD_ADDSERVER_PORT_INVALID		(EC_HD_SDK_BASENO + 3)//添加服务器，端口不合法 //When adding server, the port is invalid
#define  EC_RD_ADDSERVER_FAILED				(EC_HD_SDK_BASENO + 4)//添加服务器失败 //Add server failed
#define  EC_RD_DELETESERVER_IP_NULL			(EC_HD_SDK_BASENO + 5)//删除服务器，IP为NULL //When deleting server, the IP is null
#define	 EC_RD_DELETESERVER_IP_INVALID		(EC_HD_SDK_BASENO + 6)//删除服务器，IP不合法 //When deleting server, the IP is invalid
#define  EC_RD_DELETESERVER_PORT_INVALID    (EC_HD_SDK_BASENO + 7)//删除服务器，端口不合法 //When deleting server, the port is invalid
#define  EC_RD_DELETESERVER_QUERY_FAILED	(EC_HD_SDK_BASENO + 8)//删除服务器，未查询到该服务器 //When deleting server, the server does not exist
#define  EC_RD_CHECKBOX_QUERY_IPPORT		(EC_HD_SDK_BASENO + 9)//查询IP和端口失败 //Query IP and port failed
#define  EC_RD_DELETESERVER_FAILED			(EC_HD_SDK_BASENO + 10)//删除服务器失败 //Delete server failed
#define  EC_RD_CONNECTINFO_QUERY			(EC_HD_SDK_BASENO + 11)//连接信息查询失败 //Query connection information failed
#define  EC_RD_SETTING_QUERY				(EC_HD_SDK_BASENO + 12)//服务器设置，查询不到服务器 //When setting the server information, the server does not exist
#define  EC_RD_SETTING_SRVNAMELEN_INVALID   (EC_HD_SDK_BASENO + 13)//服务器设置，服务器名长度不合法 //When setting the server information, the length of server name is invalid
#define  EC_RD_SETTING_TIMEOUT_INVALID      (EC_HD_SDK_BASENO + 14)//服务器设置，超时设置不合法 //When setting the server information, the value of timeout is invalid
#define  EC_RD_VERIFY_IP_INVALID			(EC_HD_SDK_BASENO + 15)//IP校验不合法 //The IP is invalid
#define  EC_RD_VERIFY_PORT_INVALID			(EC_HD_SDK_BASENO + 16)//端口校验不合法 //The port is invalid
#define  EC_RD_TESTCONNECT_DISCONNECT		(EC_HD_SDK_BASENO + 17)//测试连接未连接 //The result of testing connection is disconnected
#define  EC_RD_SETTING_SRVNAMELEN_NULL      (EC_HD_SDK_BASENO + 18)//服务器设置，服务器名为空 //When setting the server information, the server name is null
#define  EC_RD_SETTING_SRVNAME_DUPLICATE	(EC_HD_SDK_BASENO + 19)//服务器设置，服务器名重复 //When setting the server information, the server name is duplicated
#define  EC_RD_ADDSERVER_SRVNAME_LEN		(EC_HD_SDK_BASENO + 20)//添加服务器，服务器名长度不合法 //When adding server, the length of server name is invalid
#define  EC_RD_ADDSERVER_DUPLICATE			(EC_HD_SDK_BASENO + 21)//添加服务器重复 //The added server is duplicated
#define  EC_RD_DELETESERVER_NOT_EXSIST		(EC_HD_SDK_BASENO + 22)//不存在要删除的服务器 //The server to be deleted does not exist
#define  EC_RD_SET_CURR_SERVER				(EC_HD_SDK_BASENO + 24)//设置当前服务器失败 //Set current server information failed
#define  EC_RD_GET_SERVERS					(EC_HD_SDK_BASENO + 25)//获取所有的服务器失败 //Get all servers failed
#define  EC_RD_GET_SERVERS_OVER_NUM			(EC_HD_SDK_BASENO + 26)//服务器数目超过内存限制 //The number of servers exceeds the limit of memory
#define  EC_RD_FINDSERVER_FAILED			(EC_HD_SDK_BASENO + 27)//查询服务器失败,服务器可能已经断开 //Query server failed, perhaps it is already disconnected
#define  EC_RD_PARAM_NULL_PTR			(EC_HD_SDK_BASENO + 28)//参数不能为NULL  //Param can not be null
#define  EC_RD_OPC_NORMAL_FAILED			(EC_HD_SDK_BASENO + 29)//获取OPC接口失败  //Get OPC interface failed

/************************************************************************/
/*              SpreadSheet (112000 ~ 112200)                                                         */
/************************************************************************/
/*Driver spreadsheet*/
#define EC_RD_SPRSHEET_BASENO					(EC_RD_BASENO + 2000)
#define EC_RD_SPRSHEET_INIT						(EC_RD_SPRSHEET_BASENO + 1)//初始化Excel驱动失败 //Initialize the Excel driver failed
#define EC_RD_SPRSHEET_RELEASE					(EC_RD_SPRSHEET_BASENO + 2)//释放Excel驱动失败 //Release the Excel driver failed
#define EC_RD_SPRSHEET_CREATE					(EC_RD_SPRSHEET_BASENO + 3)//创建Excel驱动失败 //Create the Excel driver failed
#define EC_RD_SPRSHEET_CLOSE					(EC_RD_SPRSHEET_BASENO + 4)//关闭Excel驱动失败 //Close the Excel driver failed
#define EC_RD_SPRSHEET_CLEAR_ACTIVE_SHEET		(EC_RD_SPRSHEET_BASENO + 5)//Excel驱动 清除当前Sheet失败 //Excel driver: clear active sheet failed
#define EC_RD_SPRSHEET_WRITE_CELL				(EC_RD_SPRSHEET_BASENO + 6)//Excel驱动 写单元格失败 //Excel driver: write a cell failed
#define EC_RD_SPRSHEET_READ_CELL				(EC_RD_SPRSHEET_BASENO + 7)//Excel驱动 读单元格失败 //Excel driver: read a cell failed
#define EC_RD_SPRSHEET_SET_CELL_COLOR			(EC_RD_SPRSHEET_BASENO + 8)//Excel驱动 设置单元格颜色失败 //Excel driver: set a cell color failed
#define EC_RD_SPRSHEET_GET_APPLICATION			(EC_RD_SPRSHEET_BASENO + 9)//Excel驱动 获取程序指针失败 //Excel driver: get the application pointer failed
#define EC_RD_SPRSHEET_GET_ACTIVE_OBJECT		(EC_RD_SPRSHEET_BASENO + 10)//Excel驱动 获取活动对象失败 //Excel driver: get active object failed
#define EC_RD_SPRSHEET_QUERY_INTERFACE			(EC_RD_SPRSHEET_BASENO + 11)//Excel驱动 查询接口失败 //Excel driver: query interface failed
#define EC_RD_SPRSHEET_GET_ACTIVE_WORKBOOK		(EC_RD_SPRSHEET_BASENO + 12)//Excel驱动 获取当前工作簿失败 //Excel driver: get active workbook failed
#define EC_RD_SPRSHEET_GET_ACTIVE_SHEET			(EC_RD_SPRSHEET_BASENO + 13)//Excel驱动 获取当前Sheet失败 //Excel driver: get active sheet failed
#define EC_RD_SPRSHEET_GET_CELLS				(EC_RD_SPRSHEET_BASENO + 14)//Excel驱动 在范围中获取某项失败 //Excel driver: get cells in a range failed
#define EC_RD_SPRSHEET_RANGE_GET_ITEM			(EC_RD_SPRSHEET_BASENO + 15)//Excel驱动 在范围中获取信息失败 //Excel driver: get items in a range failed
#define EC_RD_SPRSHEET_WITHOUT_ACTIVE_SHEET		(EC_RD_SPRSHEET_BASENO + 16)//Excel驱动 找不到当前Sheet //Excel driver: can not find active sheet
#define EC_RD_SPRSHEET_INPUTBOX_ERROR			(EC_RD_SPRSHEET_BASENO + 17)//Excel驱动 输入框错误 //Excel driver: input box error
#define EC_RD_SPRSHEET_SET_FOMULAARRAY			(EC_RD_SPRSHEET_BASENO + 18)//Excel驱动 添加数组公式失败 //Excel driver: add formula array failed

/*SDK spreadsheet*/
#define EC_RD_SDK_SPRSHEET_BASENO								(EC_RD_BASENO + 2100)
#define EC_RD_SDK_SPRSHEET_INVALID_TAGPROP_NAME				    (EC_RD_SDK_SPRSHEET_BASENO + 1)//不合法的Tag属性名 //Invalid tag property name
#define EC_RD_SDK_SPRSHEET_INVALID_TAGPROP_VALUE				(EC_RD_SDK_SPRSHEET_BASENO + 2)//不合法的Tag属性值 //Invalid tag property value
#define EC_RD_SDK_SPRSHEET_INVALID_QUERYCOND_TAGNAME		    (EC_RD_SDK_SPRSHEET_BASENO + 3)//条件查询，不合法的Tag名 //Invalid tag name in query condition
#define EC_RD_SDK_SPRSHEET_INVALID_QUERYCOND_INTERFACENAME		(EC_RD_SDK_SPRSHEET_BASENO + 4)//条件查询，不合法的接口名 //Invalid interface name in query condition
#define EC_RD_SDK_SPRSHEET_INVALID_TAGNAME_COLNO				(EC_RD_SDK_SPRSHEET_BASENO + 5)//Tag名不在第二列 //Tag name is not in the second column
#define EC_RD_SDK_SPRSHEET_INVALID_QUERY_ITEM					(EC_RD_SDK_SPRSHEET_BASENO + 6)//不合法的查询项 //Invalid query item
#define EC_RD_SDK_SPRSHEET_QUERY_ITEM_NUM_OVER					(EC_RD_SDK_SPRSHEET_BASENO + 7)//查询条件个数超限 //The number of query conditions exceeds the upper limit
#define EC_RD_SDK_SPRSHEET_INVALID_QUERYCOND_DESCRIPTOR		    (EC_RD_SDK_SPRSHEET_BASENO + 8)//条件查询，不合法的描述 //Invalid description in query condition
#define EC_RD_SDK_SPRSHEET_INVALID_ADDRESS						(EC_RD_SDK_SPRSHEET_BASENO + 9)//不合法的地址 //Invalid address
#define EC_RD_SDK_SPRSHEET_INVALID_TAGNAME						(EC_RD_SDK_SPRSHEET_BASENO + 10)//不合法的Tag名 //Invalid tag name
#define EC_RD_SDK_SPRSHEET_INVALID_ABSTIMEFORMAT				(EC_RD_SDK_SPRSHEET_BASENO + 11)//绝对时间格式错误 //The absolute time format is wrong
#define EC_RD_SDK_SPRSHEET_SPACE_ABSTIMEFORMAT					(EC_RD_SDK_SPRSHEET_BASENO + 12)//绝对时间前包含了空格 //The absolute time starts with space
#define EC_RD_SDK_SPRSHEET_INVALID_RELTIMEFORMAT				(EC_RD_SDK_SPRSHEET_BASENO + 13)//相对时间格式错误 //The relative time format is wrong
#define EC_RD_SDK_SPRSHEET_SPACE_RELTIMEFORMAT					(EC_RD_SDK_SPRSHEET_BASENO + 14)//相对时间前包含了空格 //The relative time starts with space
#define EC_RD_SDK_SPRSHEET_INVALID_TIMESPACE					(EC_RD_SDK_SPRSHEET_BASENO + 15)//不合法的时间间隔 //Invalid time interval
#define EC_RD_SDK_SPRSHEET_SPACE_TIMESPACE						(EC_RD_SDK_SPRSHEET_BASENO + 16)//时间间隔前包含了空格 //Time interval starts with space
#define EC_RD_SDK_SPRSHEET_INVALID_TIMESTAMP					(EC_RD_SDK_SPRSHEET_BASENO + 17)//不合法的时间戳 //Invalid timestamp
#define EC_RD_SDK_SPRSHEET_SPACE_TIMESTAMP					    (EC_RD_SDK_SPRSHEET_BASENO + 18)//时间戳前包含了空格 //Timestamp starts with space
#define EC_RD_SDK_SPRSHEET_GETTAG_FROM_QUERY					(EC_RD_SDK_SPRSHEET_BASENO + 19)//需要从Tag查询界面导入Tag点 //Need to import tags from tag query interface
#define EC_RD_SDK_SPRSHEET_GETTAG_FROM_QUERY_ERROR				(EC_RD_SDK_SPRSHEET_BASENO + 20)//从Tag查询界面导入Tag点错误 //Import tags from tag query interface failed
#define EC_RD_SDK_SPRSHEET_STARTTIME_ERROR						(EC_RD_SDK_SPRSHEET_BASENO + 21)//起始时间错误 //Start time error
#define EC_RD_SDK_SPRSHEET_ENDTIME_ERROR						(EC_RD_SDK_SPRSHEET_BASENO + 22)//终止时间错误 //End time error
#define EC_RD_SDK_SPRSHEET_OUTPUTCELL_ERROR						(EC_RD_SDK_SPRSHEET_BASENO + 23)//输出单元格错误 //Output cell error
#define EC_RD_SDK_SPRSHEET_CANNOT_FIND_TAGNAME					(EC_RD_SDK_SPRSHEET_BASENO + 24)//不能查询到Tag名 //can not find tag name
#define EC_RD_SDK_SPRSHEET_ONEROWONECOL							(EC_RD_SDK_SPRSHEET_BASENO + 25)//单元格地址只能为一行或一列 //The cell address must be one row or one column
#define EC_RD_SDK_SPRSHEET_RECNUM								(EC_RD_SDK_SPRSHEET_BASENO + 26)//记录条数错误 //The record number is wrong
#define EC_RD_SDK_SPRSHEET_STARTTIMEOVERENDTIME					(EC_RD_SDK_SPRSHEET_BASENO + 27)//起始时间不能大于终止时间 //Start time can not be later than end time
#define EC_RD_SDK_SPRSHEET_TIMECOUNT_OVER_MAX					(EC_RD_SDK_SPRSHEET_BASENO + 28)//时间点数超限 //The number of timestamps exceeds the upper limit
#define EC_RD_SDK_SPRSHEET_GET_REC_NUM							(EC_RD_SDK_SPRSHEET_BASENO + 29)//获取记录条数失败 //Get the number of records failed
#define EC_RD_SDK_SPRSHEET_INVALID_DATE							(EC_RD_SDK_SPRSHEET_BASENO + 30)//不合法的日期 //Invalid date
#define EC_RD_SDK_SPRSHEET_OVER_MAX_REC_NUM						(EC_RD_SDK_SPRSHEET_BASENO + 31)//超过了最大的记录条数限制 //Exceed the upper limit of record number
#define EC_RD_SDK_SPRSHEET_RANGE_NO_REC							(EC_RD_SDK_SPRSHEET_BASENO + 32)//时间区间内没有记录 //No records in the time range
#define EC_RD_SDK_SPRSHEET_NO_ACTIVE_SHEET						(EC_RD_SDK_SPRSHEET_BASENO + 33)//ActiveSheet没有找到 //No active sheet
#define EC_RD_SDK_SPRSHEET_OVER_MAX_TAG_NUM						(EC_RD_SDK_SPRSHEET_BASENO + 34)//超过了最大的Tag数 //Exceed the upper limit of tag number
#define EC_RD_SDK_SPRSHEET_INTERQUERY_TAGTYPE					(EC_RD_SDK_SPRSHEET_BASENO + 35)//插值查询Tag类型不对 //The tag type of interpolation query is wrong
#define EC_RD_SDK_SPRSHEET_DATAUPLOAD_INVALID_PARAM				(EC_RD_SDK_SPRSHEET_BASENO + 36)//数据上传参数错误 //Invalid parameter in data upload

/************************************************************************/
/*                Collector (112200 ~ 113000)                           */
/************************************************************************/
//采集器
#define	 EC_HD_COLLECT_PLAT_NO                      (EC_RD_BASENO + 2200)
#define  EC_HD_COLLECT_PLAT_NO_TAG                  (EC_HD_COLLECT_PLAT_NO + 1)//已经不存在数据源 //No data source available
#define	 EC_HD_COLLECT_PLAT_INVALID_PARAM           (EC_HD_COLLECT_PLAT_NO + 2)//参数无效 //Invalid parameter
#define  EC_HD_COLLECT_PLAT_UNKNOWN_EXCEPTION       (EC_HD_COLLECT_PLAT_NO + 3)//捕获到未能识别的异常 //Unknown exception
#define	 EC_HD_COLLECT_PLAT_TAG_DUPLICATE           (EC_HD_COLLECT_PLAT_NO + 4)//数据源重复 //Duplicated data source
#define	 EC_HD_COLLECT_PLAT_TAG_ID_NO_EXIST         (EC_HD_COLLECT_PLAT_NO + 5)//数据源ID不存在 //The data source ID does not exist
#define  EC_HD_COLLECT_PLAT_FILTER_PROP_NOT_EXIST   (EC_HD_COLLECT_PLAT_NO + 6)//死区压缩属性不存在 //Deadband compression property does not exist
#define  EC_HD_COLLECT_PLAT_DLL_LOAD				(EC_HD_COLLECT_PLAT_NO + 7)//Dll动态加载错误 //Dynamic Load dll failed
#define	 EC_HD_COLLECT_PLAT_DLL_FUN					(EC_HD_COLLECT_PLAT_NO + 8)//Dll函数解析错误 //Parse dll function failed
#define  EC_HD_COLLECT_PLAT_DLL_UNLOAD				(EC_HD_COLLECT_PLAT_NO + 9)//Dll卸载错误 //Unload dll failed
#define  EC_HD_COLLECT_PLAT_GROUP_FULL				(EC_HD_COLLECT_PLAT_NO + 10)//采集Group已满 //Collecting group is full
#define  EC_HD_COLLECT_PLAT_FIND_NO_GROUP			(EC_HD_COLLECT_PLAT_NO + 11)//找不到所属组 //can not find group
#define	 EC_HD_COLLECT_PLAT_INVALID_OPC_COM         (EC_HD_COLLECT_PLAT_NO + 12)//OPC COM接口无效 //Invalid OPC COM interface
#define	 EC_HD_COLLECT_PLAT_INVALID_OPC_SRVID		(EC_HD_COLLECT_PLAT_NO + 13)//OPC服务器ID无效 //Invalid OPC Server ID
#define	 EC_HD_COLLECT_PLAT_INVALID_TAG             (EC_HD_COLLECT_PLAT_NO + 14)//数据源无效 //Invalid data source
#define	 EC_HD_COLLECT_PLAT_OPC_ASYN_IO2_NO_SUPPORT (EC_HD_COLLECT_PLAT_NO + 15)//OPC不支持异步操作版本2 //The OPC Server does not support asynchronous operation of version 2
#define  EC_HD_COLLECT_PLAT_TAG_DEVICE_ADDR			(EC_HD_COLLECT_PLAT_NO + 16)//无效的Tag设备地址 //Invalid device address of the tag
#define  EC_HD_COLLECT_PLAT_GROUP_DUP				(EC_HD_COLLECT_PLAT_NO + 17)//已存在该组 //The group already exists
#define  EC_HD_COLLECT_PLAT_FIND_NO_DEVICE 			(EC_HD_COLLECT_PLAT_NO + 18)//不存在该设备或找不到该设备 //can not find the device or it does not exist
#define  EC_HD_COLLECT_PLAT_QUERY_GROUP 			(EC_HD_COLLECT_PLAT_NO + 19)//查询组失败 //Query group failed
#define  EC_HD_COLLECT_PLAT_CREATE_GROUP 			(EC_HD_COLLECT_PLAT_NO + 20)//创建组失败 //Create group failed
#define  EC_HD_COLLECT_PLAT_QUERY_DEVICE			(EC_HD_COLLECT_PLAT_NO + 21)//查询设备失败 //Query device failed
#define  EC_HD_COLLECT_PLAT_DEVICE_DUP 				(EC_HD_COLLECT_PLAT_NO + 22)//已存在该设备 //The device already exists
#define  EC_HD_COLLECT_PLAT_TIMESTAMP_MS			(EC_HD_COLLECT_PLAT_NO + 23)//得到的时间戳毫秒错误 //The millisecond in the timestamp is wrong
#define  EC_HD_COLLECT_PLAT_COM_OBJECT_GROUP		(EC_HD_COLLECT_PLAT_NO + 24)//组采集失败,可能由于错误的设备信息 //OPCGroup read faild, perhaps because of wrong device
#define  EC_HD_COLLECT_PLAT_INACTIVE				(EC_HD_COLLECT_PLAT_NO + 25)//采集器冗余状态非活动，不采集数据 //The collector redundant state is inactive, so it does not work
#define  EC_HD_COLLECT_ADD_EXIST_NAME				(EC_HD_COLLECT_PLAT_NO + 26)//同名采集器已添加 //The collector name already exists

#define EC_HD_CCT_GET_COLLECTOR_BY_DEVICE_FAILED    (EC_HD_COLLECT_PLAT_NO + 27)//获取相关的采集器信息失败，是否强制删除//Get information of related collector failed, Whether to forcibly delete
#define EC_HD_CCT_DEVICE_IN_USE                     (EC_HD_COLLECT_PLAT_NO + 28)//该设备正在使用中，是否强制删除//The device is in use, Whether to forcibly delete
#define EC_HD_CCT_GET_DEVICE_BY_SCANGROUP_FAILED    (EC_HD_COLLECT_PLAT_NO + 29)//获取相关的设备信息失败，是否强制删除//Get information of related device failed, Whether to forcibly delete
#define EC_HD_CCT_GET_TAG_INFO_OF_SCANGROUP_FAILED  (EC_HD_COLLECT_PLAT_NO + 30)//获取改扫描组下的Tag点失败，是否强制删除//Get tags under this scan group failed, Whether to forcibly delete
#define EC_HD_CCT_SCAN_GROUP_IN_USE                 (EC_HD_COLLECT_PLAT_NO + 31)//该扫描组正在使用中，是否强制删除//The scan group is in use, Whether to forcibly delete
#define EC_HD_CCT_GET_SCAN_GROUP_UNDER_DEVICE       (EC_HD_COLLECT_PLAT_NO + 32)//获取该设备下的扫描组失败，是否强制删除//Get scan group under this device failed,Whether to forcibly delete
#define EC_HD_CCT_COLLECTOR_IN_USE                  (EC_HD_COLLECT_PLAT_NO + 33)//该采集器正在使用中，是否强制删除//The collector is in use, Whether to forcibly delete

//下面几个备用
#define EC_HD_OPC_INVALID_TAG						(EC_HD_COLLECT_PLAT_NO + 30)//备用1230 //Reserved
#define EC_HD_OPC_SERVER_NOT_CONNECTED				(EC_HD_COLLECT_PLAT_NO + 31)//OPC Server未连接 //The OPC Server is not connected
#define EC_HD_OPC_INVALID_PARAM						(EC_HD_COLLECT_PLAT_NO + 32)//备用1678 //Reserved
#define EC_HD_OPC_FIND_NO_GROUP						(EC_HD_COLLECT_PLAT_NO + 33)//备用1990 //Reserved
#define EC_HD_OPC_INVALID_COM_INTERFACE				(EC_HD_COLLECT_PLAT_NO + 34)//备用1488 //Reserved
#define EC_HD_COLLECT_PLAT_INVALID_DRVTYPE			(EC_HD_COLLECT_PLAT_NO + 35)//备用3457 //Reserved

//OPC Server Config
#define EC_HD_OPCSVRINFO_ADD_GROUP_FAILED						(EC_HD_COLLECT_PLAT_NO + 50)//添加组失败 //Failed to add group
#define EC_HD_OPCSVRINFO_QUERY_ITEM_INTERFACE_FAILED				(EC_HD_COLLECT_PLAT_NO + 51)//查询Item接口失败 //Failed to query item interface
#define EC_HD_OPCSVRINFO_QUERY_SYNCIO_INTERFACE_FAILED						(EC_HD_COLLECT_PLAT_NO + 52)//查询同步读接口失败 //Faild to query sync interface
#define EC_HD_OPCSVRINFO_QUERY_ASYNCIO_INTERFACE_FAILED						(EC_HD_COLLECT_PLAT_NO + 53)//查询异步读接口失败 //Faild to query async interface
#define EC_HD_OPCSVRINFO_ADD_ITEMS_FAILED				(EC_HD_COLLECT_PLAT_NO +54)//添加items失败 //Failed to add items
#define EC_HD_OPCSVRINFO_CANNOT_READ_INVALID_ITEM			(EC_HD_COLLECT_PLAT_NO + 55)//OPC Item 不可用，不能用同步读功能 //Can not read invalid items 
#define EC_HD_OPCSVRINFO_READ_FAILED	(EC_HD_COLLECT_PLAT_NO + 56)//读值失败 //Failed to read items
#define EC_HD_OPCSVRINFO_SERVER_NAME_EMPTY	(EC_HD_COLLECT_PLAT_NO + 57)//服务名不能为空 //Invalid server name
#define EC_HD_OPCSVRINFO_GET_COMPUTER_NAME_FAILED	(EC_HD_COLLECT_PLAT_NO + 58)//获取机器名失败 //Failed to get computer name
#define EC_HD_OPCSVRINFO_REG_FAILED	(EC_HD_COLLECT_PLAT_NO + 59)//注册键值失败 //Failed to register key
#define EC_HD_OPCSVRINFO_GET_SERVER_NAME_FAILED	(EC_HD_COLLECT_PLAT_NO + 60)//获取服务名失败 //Failed to get server name
#define EC_HD_OPCSVRINFO_INIT_COM_FAILED	(EC_HD_COLLECT_PLAT_NO + 61)//初始化COM失败 //Failed to initialize COM
#define EC_HD_OPCSVRINFO_INVALID_OPC_SERVER	(EC_HD_COLLECT_PLAT_NO + 62)//不合法的OPC Server //Invalid OPC Server
#define EC_HD_OPCSVRINFO_QUERY_OPC_SERVER_INTERFACE_FAILED	(EC_HD_COLLECT_PLAT_NO + 63)//查询OPC Server接口失败 //Faild to query opc server interface
#define EC_HD_OPCSVRINFO_GET_OPC_STAUTS_FAILED	(EC_HD_COLLECT_PLAT_NO + 64)//获取OPC Server状态失败 //Failed to get OPC Server status
#define EC_HD_OPCSVRINFO_BROWSE_ITEM_FAILED	(EC_HD_COLLECT_PLAT_NO + 65)//浏览点失败 //Failed to browse OPC items
#define EC_HD_OPCSVRINFO_INVALID_BROWSE_HANDLE 	(EC_HD_COLLECT_PLAT_NO + 66)//不合法的浏览点句柄 //Invalid browse opc handle
#define EC_HD_OPCSVRINFO_GET_ITEMID_FAILED 	(EC_HD_COLLECT_PLAT_NO + 67)//获取item id失败 //Failed to get item ID
#define EC_HD_OPCSVRINFO_CHANGE_POSITION_FAILED 	(EC_HD_COLLECT_PLAT_NO + 68)//ChangeBrowsePosition()失败 //Failed to change browse position
#define EC_HD_OPCSVRINFO_CREATE_INSTANCE_FAILED 	(EC_HD_COLLECT_PLAT_NO + 69)//创建COM实例失败 //Failed to create instance


//ICV驱动配置
#define	 EC_HD_ICVDRV_XML_NO						(EC_RD_BASENO + 3000)
#define  EC_HD_ICVDRV_XML_FILE_LENGTH				(EC_HD_ICVDRV_XML_NO + 1)//配置文件名长度错误 //The length of configuration file name is wrong
#define  EC_HD_ICVDRV_XML_SAVE_FILE					(EC_HD_ICVDRV_XML_NO + 2)//配置保存失败 //Save configuration failed
#define  EC_HD_ICVDRV_XML_INVILD_PARAM				(EC_HD_ICVDRV_XML_NO + 3)//输入参数错误 //Invalid input parameter
#define  EC_HD_ICVDRV_XML_DOC_ERROR					(EC_HD_ICVDRV_XML_NO + 4)//配置文件加载失败或错误 //Load configuration file failed or with error
#define  EC_HD_ICVDRV_XML_FORMAT_ERROR				(EC_HD_ICVDRV_XML_NO + 5)//配置文件格式错误 //The configuration file format is wrong
#define  EC_HD_ICVDRV_XML_INSERT_DUP_DEVGRP			(EC_HD_ICVDRV_XML_NO + 6)//设备组重复 //The device group is duplicated
#define  EC_HD_ICVDRV_XML_FIND_NO_DEVGRP			(EC_HD_ICVDRV_XML_NO + 7)//找不到设备组 //Can not find the device group
#define  EC_HD_ICVDRV_XML_INSERT_DUP_DEV 			(EC_HD_ICVDRV_XML_NO + 8)//设备重复 //The device is duplicated
#define  EC_HD_ICVDRV_XML_FIND_NO_DEV				(EC_HD_ICVDRV_XML_NO + 9)//找不到设备 //Can not find the device
#define  EC_HD_ICVDRV_XML_INSERT_DUP_DATABLK 		(EC_HD_ICVDRV_XML_NO + 10)//数据块重复 //The data block is duplicated
#define  EC_HD_ICVDRV_XML_PARAM_VERIFY 				(EC_HD_ICVDRV_XML_NO + 11)//参数校验失败 //Verify parameter failed
#define  EC_HD_ICVDRV_XML_NO_ATTRIBUTE 				(EC_HD_ICVDRV_XML_NO + 12)//配置文件找不到该节点属性 //No attribute of this point found in configuration file

/************************************************************************/
/*                  Buffer  (113200 ~ 113300)                           */
/************************************************************************/
#define EC_HD_BUFFER_NO						(EC_RD_BASENO + 3200)
#define EC_HD_BUFFER_LEN_CACHE_FILE_NAME	(EC_HD_BUFFER_NO + 1)//缓存文件路径太长，超过了256个字节 //The length of cache file name exceeds 256 bytes
#define EC_HD_BUFFER_PROCCOMM_RECV_LEN		(EC_HD_BUFFER_NO + 2)//Buffer与API进程间通讯接收的数据长度不正确 //The data length is incorrect in the interprocess communication between buffer and API
#define EC_HD_BUFFER_FILE_NO_DATA			(EC_HD_BUFFER_NO + 3)//缓存文件没有数据 //There is no data in cache file
#define EC_HD_BUFFER_FILE_BUFFER_LEN		(EC_HD_BUFFER_NO + 4)//读取缓存文件记录时分配的缓冲区长度太小 //When reading records from cache file, the allocated buffer length is too small
#define EC_HD_BUFFER_FILE_INVALID_RECORD_LEN	(EC_HD_BUFFER_NO + 6)//记录长度错误 //Invalid length of record
#define EC_HD_BUFFER_INVALID_INPUT_PARAM	(EC_HD_BUFFER_NO + 7)//不合法的输入参数 //Invalid input parameter
#define EC_HD_BUFFER_NO_IDLE_BLOCK			(EC_HD_BUFFER_NO + 8)//缓存文件没有空闲块 //There is no idle block in cache file
#define EC_HD_BUFFER_INVALID_FILE_SIZE		(EC_HD_BUFFER_NO + 9)//缓存文件的实际大小大于配置文件中的最大值 //The size of cache file is bigger than the maximum value in the configuration file
#define EC_HD_BUFFER_LEN_RECV				(EC_HD_BUFFER_NO + 10)//Buffer从服务端接收的长度不正确 //Invalid length of data that buffer received from the server
#define EC_HD_BUFFER_INVALID_BASE_PARAM		(EC_HD_BUFFER_NO + 11)//缓存文件头部数据不正确 //The head data in cache file is wrong
#define EC_HD_BUFFER_INVALID_SRV_COUNT		(EC_HD_BUFFER_NO + 12)//缓存文件中存储的服务器个数不正确 //The count of servers in cache file is wrong
#define EC_HD_BUFFER_INVALID_COMP_TAG_TYPE	(EC_HD_BUFFER_NO + 13)//不合法的用于压缩的TAG类型 //Invalid tag type used for compression
#define EC_HD_BUFFER_INVALID_TIME_ORDER		(EC_HD_BUFFER_NO + 14)//记录时序不合法 //Invalid time sequence of records
#define EC_HD_BUFFER_INVALID_RECORD_LEN		(EC_HD_BUFFER_NO + 15)//记录长度不合法 //Invalid length of records
#define EC_HD_BUFFER_POINTER_NULL			(EC_HD_BUFFER_NO + 16)//函数传入空指针 //Null pointer in function

/************************************************************************/
/*                  SysMgrtool  (113300 ~ 114800)                */
/************************************************************************/

/*****TaskPanel******/
#define EC_HD_TASKPANEL_BASE                    (EC_RD_BASENO + 3300)
#define EC_HD_TASKPANEL_CREATE_TREE_FAIL        (EC_HD_TASKPANEL_BASE + 1)//生成树节点失败 //Create tree node failed
#define EC_HD_TASKPANEL_FIND_TREEELEMENT_FAIL   (EC_HD_TASKPANEL_BASE + 2)//读取配置文件中树元素失败 //Read tree element in configuration file failed
#define EC_HD_TASKPANEL_FIND_TREEATTRIBUTE_FAIL (EC_HD_TASKPANEL_BASE + 3)//读取配置文件中树元素属性失败 //Read attribute of tree element in configuration file failed
#define EC_HD_TASKPANEL_REPEAT_TREENAME         (EC_HD_TASKPANEL_BASE + 4)//树节点名字重复 //The tree node name is duplicated
#define EC_HD_TASKPANEL_FIND_NODEELEMENT_FAIL   (EC_HD_TASKPANEL_BASE + 5)//读取配置文件中子节点元素失败 //Read child node element in configuration file failed
#define EC_HD_TASKPANEL_FIND_NODEATRRIBUTE_FAIL (EC_HD_TASKPANEL_BASE + 6)//读取配置文件中子节点元素属性失败 //Read attribute of child node element in configuration file failed
#define EC_HD_TASKPANEL_OVER_NODE_LEVELS        (EC_HD_TASKPANEL_BASE + 7)//超过可增加的最深节点个数 //More than the allowed deepest node number
#define EC_HD_TASKPANEL_REPEAT_NODENAME         (EC_HD_TASKPANEL_BASE + 8)//子节点名字重复 //The child node name is duplicated
#define EC_HD_TASKPANEL_FIND_FUNCAREA			(EC_HD_TASKPANEL_BASE + 9)//无法找到功能域 //Can not find the function area
#define EC_HD_TASKPANEL_NEW						(EC_HD_TASKPANEL_BASE + 10)//新建失败 //Create failed
#define EC_HD_MAINFRAM_LOAD_TASKPANEL			(EC_HD_TASKPANEL_BASE + 11)//加载任务面板失败 //Load task panel failed
#define EC_HD_MAINFRAM_LOAD_TASKPANEL_RESOLVE	(EC_HD_TASKPANEL_BASE + 12)//Resolve面板错误 //Analyze task panel failed
#define EC_HD_MAINFRAM_LOAD_DLL					(EC_HD_TASKPANEL_BASE + 13)//加载dll失败 //Load dll failed
#define EC_HD_MAINFRAM_UNLOAD_DLL				(EC_HD_TASKPANEL_BASE + 14)//Unload dll失败 //Unload dll failed
#define EC_HD_MAINFRAM_DLL_FUN_RESOLVE			(EC_HD_TASKPANEL_BASE + 15)//获取dll中方法失败 //Get dll method failed
#define EC_HD_MAINFRAM_LOAD_MESSAGEPANEL		(EC_HD_TASKPANEL_BASE + 16)//LOAD消息面板失败 //Load message panel failed
#define EC_HD_MAINFRAM_RESOLVE_ACTION			(EC_HD_TASKPANEL_BASE + 17)//处理action对象失败 //Deal with action object failed
#define EC_HD_MAINFRAM_LOGMESSAGE_TOOLONG		(EC_HD_TASKPANEL_BASE + 18)//消息字符串太长 //The message length is too long
#define EC_HD_MAINFRAM_INVALID_DLLPATH			(EC_HD_TASKPANEL_BASE + 19)//非法的dll路径 //Invalid dll path
#define EC_HD_MAINFRAM_SETMENUSTATE				(EC_HD_TASKPANEL_BASE + 20)//设置菜单状态错误 //Set menu state failed
#define EC_HD_MAINFRAM_SETTOOLBARSTATE			(EC_HD_TASKPANEL_BASE + 21)//设置工具栏状态错误 //Set toolbar state failed
#define EC_HD_MAINFRAM_ADDMENU_FAILED			(EC_HD_TASKPANEL_BASE + 22)//添加菜单错误 //Add menu failed
#define EC_HD_MAINFRAM_MENUNAME_RESLOVE_FAILED	(EC_HD_TASKPANEL_BASE + 23)//处理菜单名错误 //Deal with the menu name failed
#define EC_HD_MAINFRAM_ADDTOOLBAR_FAILED		(EC_HD_TASKPANEL_BASE + 24)//添加工具栏错误 //Add toolbar failed
#define EC_HD_MAINFRAM_FINDTREEITEM				(EC_HD_TASKPANEL_BASE + 25)//查找树item失败 //Find tree item failed
#define EC_HD_MAINFRAM_INVALID_STRLEN			(EC_HD_TASKPANEL_BASE + 26)//不合法的字符串长度 //Invalid length of string
#define EC_HD_MAINFRAM_SERVER_DISCONNECT        (EC_HD_TASKPANEL_BASE + 27)//服务器没连接 //The server is not connected
#define EC_HD_MAINFRAM_SERVER_NO_EXIST        (EC_HD_TASKPANEL_BASE + 28)//服务器不存在 //The server does not exist




/*buffercfg*/
#define EC_HD_BUFFERCFG_BASE                 (EC_RD_BASENO + 3400)
#define EC_HD_BUFFERCFG_FILE_NOEXISTING      (EC_HD_BUFFERCFG_BASE + 13)//配置文件不存在 //The configuration file does not exist
#define EC_HD_BUFFERCFG_FILE_NOREAD          (EC_HD_BUFFERCFG_BASE + 14)//配置文件属性不可读 //The properties of configuration file can not be read
#define EC_HD_BUFFERCFG_FILE_NOWRITING       (EC_HD_BUFFERCFG_BASE + 15)//配置文件属性为不可写 //The properties of configuration file can not be written
#define EC_HD_BUFFERCFG_FILE_READFAILTURE    (EC_HD_BUFFERCFG_BASE + 16)//读取配置文件失败 //Read configuration file failed
#define EC_HD_BUFFERCFG_FILE_WRITEFAILTURE   (EC_HD_BUFFERCFG_BASE + 17)//将数据写入配置文件失败 //Write data into the configuraion file failed
#define EC_HD_BUFFERCFG_FILE_OPENEFAILTURE   (EC_HD_BUFFERCFG_BASE + 18)//配置文件打开失败 //Open the configuration file failed
#define EC_HD_BUFFERCFG_IVALID_PARAM		 (EC_HD_BUFFERCFG_BASE + 19)//输入数据不合法 //Invalid input parameter

/* RDB Config */
#define EC_HD_RDBCONFIG_BASE					(EC_RD_BASENO + 3500)
#define EC_HD_RDBCONFIG_SQLTYPECONVERT			(EC_HD_RDBCONFIG_BASE + 1) //sql server转换不支持该数据类型 //The data type is not supported in the transformation of SQL Server
#define EC_HD_RDBCONFIG_RDBCONNECT				(EC_HD_RDBCONFIG_BASE + 2) //连接关系数据库失败 //Connect to the relational database failed
#define EC_HD_RDBCONFIG_RDBGETALLTABLES			(EC_HD_RDBCONFIG_BASE + 3) //获取关系数据库表名失败 //Get table names in the relational database failed
#define EC_HD_RDBCONFIG_RDBCREATTABLE			(EC_HD_RDBCONFIG_BASE + 4) //创建关系数据库表失败 //Create table in the relational database failed
#define EC_HD_RDBCONFIG_RDBCREATTABLE_DUPLICATE	(EC_HD_RDBCONFIG_BASE + 5) //创建关系数据库表重复 //The table in the ralational database is duplicated
#define EC_HD_RDBCONFIG_RDBQUERYFIELD			(EC_HD_RDBCONFIG_BASE + 6) //查询关系数据库表字段失败 //Query table fields in the ralational database failed
#define EC_HD_RDBCONFIG_RDBQUERYFIELDTYPE		(EC_HD_RDBCONFIG_BASE + 7) //查询关系数据库表字段数据类型失败 //Query the data type of table fields in the ralational database failed
#define EC_HD_RDBCONFIG_RDBDISCONNECT			(EC_HD_RDBCONFIG_BASE + 8) //断开关系数据库失败 //Disconnect to the relational database failed
#define EC_HD_RDBCONFIG_RDBDROPTABLE			(EC_HD_RDBCONFIG_BASE + 9) //删除表失败 //Delete table in the relational database failed
#define EC_HD_RDBCONFIG_XML_NO_ATTRIBUTE		(EC_HD_RDBCONFIG_BASE + 10) //配置文件中属性缺失 //No attribute in configuraion file
#define EC_HD_RDBCONFIG_XML_FORMAT_ERROR		(EC_HD_RDBCONFIG_BASE + 11) //配置文件格式错误 //The configuraion file format is wrong
#define EC_HD_RDBCONFIG_XML_FIND_NO_IHYPERDB	(EC_HD_RDBCONFIG_BASE + 12) //配置文件中未找到iHyperDB //can not find iHyperDB in configuraion file
#define EC_HD_RDBCONFIG_XML_INSERT_DUP_IHYPERDB	(EC_HD_RDBCONFIG_BASE + 13) //配置文件中插入iHyperDB时，服务器名重复 //When inserting iHyperDB server into configuraion file, the server name is duplicated
#define EC_HD_RDBCONFIG_XML_INSERT_DUP_RDB		(EC_HD_RDBCONFIG_BASE + 14) //配置文件中插入关系数据库时，关系数据库名重复 //When inserting relational database configuration into configuraion file, the database name is duplicated
#define EC_HD_RDBCONFIG_XML_FIND_NO_RDB			(EC_HD_RDBCONFIG_BASE + 15) //配置文件中未找到RDB //can not find relational database in configuraion file
#define EC_HD_RDBCONFIG_XML_FIND_NO_TABLE		(EC_HD_RDBCONFIG_BASE + 16) //配置文件中未找到表 //Can not find table in configuraion file
#define EC_HD_RDBCONFIG_XML_INSERT_DUP_TABLE	(EC_HD_RDBCONFIG_BASE + 17) //配置文件中插入表时，表名重复 //When inserting table into configuraion file, the table name is duplicated
#define EC_HD_RDBCONFIG_XML_INSERT_DUP_RULE		(EC_HD_RDBCONFIG_BASE + 18) //配置文件中插入规则时，规则名重复 //When inserting rule into configuraion file, the rule name is duplicated
#define EC_HD_RDBCONFIG_XML_FIND_NO_RULE		(EC_HD_RDBCONFIG_BASE + 19) //配置文件中未找到规则 //Can not find rule in configuraion file
#define EC_HD_RDBCONFIG_XML_INSERT_DUP_TAG		(EC_HD_RDBCONFIG_BASE + 20) //配置文件中插入Tag时，Tag名重复 //When inserting tag into configuraion file, the tag name is duplicated
#define EC_HD_RDBCONFIG_XML_FIND_NO_TAG			(EC_HD_RDBCONFIG_BASE + 21) //配置文件中未找到TAG //Can not find tag in configuraion file
#define EC_HD_RDBCONFIG_XML_DOC_ERROR			(EC_HD_RDBCONFIG_BASE + 22) //配置文件文档指针为空 //The document pointer of configuraion file is null
#define EC_HD_RDBCONFIG_XML_SAVE_FILE			(EC_HD_RDBCONFIG_BASE + 23) //配置文件保存失败，文件可能为只读 //Save configuraion file failed, perhaps it is readonly
#define EC_HD_RDBCONFIG_XML_PARAM_VERIFY		(EC_HD_RDBCONFIG_BASE + 24) //配置文件参数校验错误 //Verify parameter of configuraion file failed
#define EC_HD_RDBCONFIG_XML_OPEN_LOADFILE		(EC_HD_RDBCONFIG_BASE + 25) //配置文件打开时加载失败 //When opening configuraion file, load failed
#define EC_HD_RDB_CONFIG_XML_GETALLTABLE_NULL  (EC_HD_RDBCONFIG_BASE + 26) //配置文件获取所有表时指针为空 //When getting all tables in configuraion file, the pointer is null
#define EC_HD_RDB_CONFIG_XML_MODIFYRDB_NULL  (EC_HD_RDBCONFIG_BASE + 27) //配置文件修改关系数据库连接时指针为空 //When modifying the connection of relational database in configuraion file, the pointer is null
#define EC_HD_RDB_CONFIG_XML_MODIFYTABLE_NULL  (EC_HD_RDBCONFIG_BASE + 28) //配置文件修改表信息时指针为空 //When modifying the table info in configuraion file, the pointer is null
#define EC_HD_RDB_CONFIG_XML_INSERTRDB_NULL  (EC_HD_RDBCONFIG_BASE + 29)  //配置文件插入关系数据库连接时指针为空 //When inserting the connection of relational database into configuraion file, the pointer is null
#define EC_HD_RDB_CONFIG_XML_MODIFYHDB_NULL (EC_HD_RDBCONFIG_BASE + 30)  //配置文件修改实时数据库连接时名字为空 //When modifying the connection of iHyperDB in configuraion file, the name is null
#define EC_HD_RDBCONFIG_XML_NULL_POINTER  (EC_HD_RDBCONFIG_BASE + 31) //操作配置文件时指针为空 //When operating the configuraion file, the pointer is null
#define EC_HD_RDBCONFIG_XML_INSERT_DUP_TABLE_ALIAS  (EC_HD_RDBCONFIG_BASE + 32) //表别名重复 //The table alias is duplicated
#define EC_HD_RDBCONFIG_XML_RULE_100_TAG           (EC_HD_RDBCONFIG_BASE + 33) //规则中添加Tag点不能超过100个 //The count of tags in one rule can not be more than 100
#define EC_HD_RDBCONFIG_UNCERTAIN_EXCEPTION  (EC_HD_RDBCONFIG_BASE + 34) //捕获到未能识别的异常 //Unknown exception
#define EC_HD_RDBCONFIG_UNKNOWN_RDB           (EC_HD_RDBCONFIG_BASE + 35) //不支持的关系数据库 //Unsupported relational database

#define EC_HD_RDBCONFIG_BUF_MODIFY_RDB	(EC_HD_RDBCONFIG_BASE + 36) //缓存中修改RDB失败 //Modify rdb into buffer failed
#define EC_HD_RDBCONFIG_BUF_GET_ALL_TABLE	(EC_HD_RDBCONFIG_BASE + 37) //缓存中获取所有的表失败 //Get all table from buffer failed
#define EC_HD_RDBCONFIG_BUF_INSERT_TABLE		(EC_HD_RDBCONFIG_BASE + 38) //缓存中插入表失败 //Insert table to buffer failed
#define EC_HD_RDBCONFIG_BUF_MODIFY_TABLE		(EC_HD_RDBCONFIG_BASE + 39) //缓存中修改表失败 //Modify table into buffer failed
#define EC_HD_RDBCONFIG_BUF_GET_ALL_RULE		(EC_HD_RDBCONFIG_BASE + 40) //缓存中获取所有规则失败 //Get all rules from buffer failed
#define EC_HD_RDBCONFIG_BUF_INSERT_RULE			(EC_HD_RDBCONFIG_BASE + 41) //缓存中插入规则失败//Insert rule tobuffer failed
#define EC_HD_RDBCONFIG_BUF_QUERY_RULE			(EC_HD_RDBCONFIG_BASE + 42) //缓存中查询规则失败 //Query rule from buffer failed
#define EC_HD_RDBCONFIG_BUF_DEL_RULE			(EC_HD_RDBCONFIG_BASE + 43) //缓存中删除规则失败 //Delete rule from buffer failed
#define EC_HD_RDBCONFIG_BUF_MODIFY_RULE		(EC_HD_RDBCONFIG_BASE + 44) //缓存中修改规则失败 //Modify rule into buffer failed
#define EC_HD_RDBCONFIG_BUF_INSERT_TAG		(EC_HD_RDBCONFIG_BASE + 45) //缓存中插入点失败 //Insert tag to buffer failed
#define EC_HD_RDB_CONFIG_BUF_GET_ALL_TAG  (EC_HD_RDBCONFIG_BASE + 46) //缓存中获取所有点失败 //Get all tag from buffer failed
#define EC_HD_RDB_CONFIG_BUF_DELETE_TAG  (EC_HD_RDBCONFIG_BASE + 47) //缓存中删除点失败 //Delete tag from buffer failed
#define EC_HD_RDB_CONFIG_BUF_MODIFY_TAG  (EC_HD_RDBCONFIG_BASE + 48) //缓存中修改点失败 //Modify tag from buffer failed
#define EC_HD_RDB_CONFIG_BUF_NULL  (EC_HD_RDBCONFIG_BASE + 49) //缓存中操作时参数是空指针 //Null pointer when operating buffer 

/* OPC Config */
#define EC_HD_OPCCFG_BASE					    (EC_RD_BASENO + 3550)
#define EC_HD_OPCCFG_FILE_NO_EXIST              (EC_HD_OPCCFG_BASE + 1)//OPC配置文件不存在 //The OPC configuration file does not exist
#define EC_HD_OPCCFG_FILE_NO_READ               (EC_HD_OPCCFG_BASE + 2)//OPC配置文件不可读 //The OPC configuration file can not be read
#define EC_HD_OPCCFG_FILE_NO_WRITE              (EC_HD_OPCCFG_BASE + 3)//OPC配置文件不可写 //The OPC configuration file can not be written
#define EC_HD_OPCCFG_FILE_OPEN                  (EC_HD_OPCCFG_BASE + 4)//打开OPC配置文件失败 //Open OPC configuration file failed
#define EC_HD_OPCCFG_SET_INTERFACE_CFG          (EC_HD_OPCCFG_BASE + 5)//OPC采集接口参数不合法 //Invalid parameter for the OPC collection interface
#define EC_HD_OPCCFG_SET_DBSERVER_CFG           (EC_HD_OPCCFG_BASE + 6)//OPC采集HD参数不合法 //Invalid parameter of iHyperDB for the OPC collection
#define EC_HD_OPCCFG_SET_OPCSRV_CFG             (EC_HD_OPCCFG_BASE + 7)//OPC采集OPC Server参数不合法 //Invalid parameter of OPC Server for the OPC collection
#define EC_HD_OPCCFG_LOAD_FILE                  (EC_HD_OPCCFG_BASE + 8)//加载OPC配置文件失败 //Load OPC configuration file failed
#define EC_HD_OPCCFG_READ_XML                   (EC_HD_OPCCFG_BASE + 9)//读取OPC配置文件错误 //Read OPC configuration file failed


/************************************************************************/
/*                  RDB   (114800 ~ 115000)                             */
/************************************************************************/


/*****RDB IMPORTER*******/
#define EC_HD_IMPORTER_BASE						(EC_RD_BASENO + 4800)
#define EC_HD_IMPORTER_RDB_CONNECT				(EC_HD_IMPORTER_BASE + 1)//RDB连接失败 //Connect to the relational database failed
#define EC_HD_IMPORTER_RDB_DISCONNECT			(EC_HD_IMPORTER_BASE + 2)//RDB断开失败 //Disconnect to the relational database failed
#define EC_HD_IMPORTER_QUERY_REC				(EC_HD_IMPORTER_BASE + 3)//查询记录失败 //Query records failed
#define EC_HD_IMPORTER_TAG_TYPE					(EC_HD_IMPORTER_BASE + 4)//Tag类型错误 //Wrong tag type
#define EC_HD_IMPORTER_INVALID_HD				(EC_HD_IMPORTER_BASE + 5)//iHyperDB无效或不存在 //Invalid or not existed iHyperDB
#define EC_HD_IMPORTER_TAG_SNAPTIME				(EC_HD_IMPORTER_BASE + 7)//获取Tag快照时间失败 //Query tag snapshot timestamp failed
#define EC_HD_IMPORTER_ERROR_TIME				(EC_HD_IMPORTER_BASE + 8)//错误的字符串时间 //Wrong time in the format of string
#define EC_HD_IMPORTER_INVALID_TAG				(EC_HD_IMPORTER_BASE + 9)//Tag 无效 //Invalid tag
#define EC_HD_IMPORTER_ADD_RULE_ARG				(EC_HD_IMPORTER_BASE + 10)//添加Rule参数错误 //When adding rule, the parameter is wrong
#define EC_HD_IMPORTER_SQLAPI_EXCEPTION			(EC_HD_IMPORTER_BASE + 11)//SQLAPI异常 //SQLAPI exception
#define EC_HD_IMPORTER_RDB_READ_ALLOC			(EC_HD_IMPORTER_BASE + 12)//内存分配错误:读取RDB //Memory allocation error when reading relational database
#define EC_HD_IMPORTER_TABLE_READ_ALLOC			(EC_HD_IMPORTER_BASE + 13)//内存分配错误:读取RDB Table //Memory allocation error when reading tables in relational database
#define EC_HD_IMPORTER_TAG_READ_ALLOC			(EC_HD_IMPORTER_BASE + 14)//内存分配错误:读取Tag //Memory allocation error when reading tags
#define EC_HD_IMPORTER_RULE_READ_ALLOC			(EC_HD_IMPORTER_BASE + 15)//内存分配错误:读取Rule //Memory allocation error when reading rules
#define EC_HD_IMPORTER_CFG_ALLOC				(EC_HD_IMPORTER_BASE + 16)//内存分配错误:读取Config File //Memory allocation error when reading configuration file
#define EC_HD_IMPORTER_HD_READ_ALLOC			(EC_HD_IMPORTER_BASE + 17)//内存分配错误:读取iHyperDB //Memory allocation error when reading iHyperDB
#define EC_HD_IMPORTER_QUALITY_WITHOUT_VALUE  (EC_HD_IMPORTER_BASE + 18)//采集数据质量但未采集数据值 //Data quality was collected while value was not
#define EC_HD_IMPORTER_EMPTY_TIME                 (EC_HD_IMPORTER_BASE + 19)//关系数据库表中时间字段空值 //The value of time column is empty in relationsl database
#define EC_HD_IMPORTER_RDB_TYPE                     (EC_HD_IMPORTER_BASE + 20)//不合法的关系数据库类型 //Invalid type of relational database
#define EC_HD_IMPORTER_VALUE_CONVERT         (EC_HD_IMPORTER_BASE + 21)//数据值转换异常 //Data value conversion exception

/* RDBExporter  110000 + 13650 = 123650 ~ */
#define EC_HD_EXPORTER_BASE									(EC_RD_BASENO + 4850)
#define EC_HD_EXPORTER_RECORD_LENGTH_NOT_MATCH              (EC_HD_EXPORTER_BASE + 1)//记录长度不匹配 //The length of record is not matched
#define EC_HD_EXPORTER_NULL_TABLE_POINTER                   (EC_HD_EXPORTER_BASE + 2)//表指针为空 //The table pointer is null
#define EC_HD_EXPORTER_NULL_RDB_POINTER						(EC_HD_EXPORTER_BASE + 3)//关系数据库指针为空 //The pointer of relational database is null
#define EC_HD_EXPORTER_SACOMMAND_SETCOMMANDTEXT				(EC_HD_EXPORTER_BASE + 4)//SQLAPI设置命令错误 //Set command failed in SQLAPI
#define EC_HD_EXPORTER_SACOMMAND_SET_PARAM					(EC_HD_EXPORTER_BASE + 5)//SQLAPI设置命令参数错误 //Set command parameter failed in SQLAPI
#define EC_HD_EXPORTER_SACOMMAND_COMMIT                     (EC_HD_EXPORTER_BASE + 6)//SQLAPI提交事务出错 //Commit failed in SQLAPI
#define EC_HD_EXPORTER_SACONNECTION_ROLLBACK				(EC_HD_EXPORTER_BASE + 7)//SQLAPI连接回滚出错 //Rollback failed in SQLAPI
#define EC_HD_EXPORTER_SACONNECTION_IS_NULL					(EC_HD_EXPORTER_BASE + 8)//SQLAPI连接为空 //The connection is null in SQLAPI
#define EC_HD_EXPORTER_RULE_IS_NULL							(EC_HD_EXPORTER_BASE + 9)//规则指针为空 //The rule pointer is null
#define EC_HD_EXPORTER_SQLAPI_ERROR                         (EC_HD_EXPORTER_BASE + 10)//SQLAPI一般性异常错误 //Normal exception of SQLAPI
#define EC_HD_EXPORTER_TIME_FORMAT_INVALID                  (EC_HD_EXPORTER_BASE + 11)//时间格式错误 //Invalid time format
#define EC_HD_EXPORTER_TIME_LENGTH_INVALID                  (EC_HD_EXPORTER_BASE + 12)//时间长度错误 //Invalid length of time
#define EC_HD_EXPORTER_GENERAL_PARAMETER_ERROR              (EC_HD_EXPORTER_BASE + 13)//参数错误 //Invalid parameter
#define EC_HD_EXPORTER_HD_NOT_CONNECTED                     (EC_HD_EXPORTER_BASE + 14)//没有连接 //Not connected to iHyperDB
#define EC_HD_EXPORTER_UNKNOWN_EXCEPTION					(EC_HD_EXPORTER_BASE + 15)//捕获到未能识别的异常 //Unknown exception
#define EC_HD_EXPORTER_SCRIPT_NAME_NULL                         (EC_HD_EXPORTER_BASE + 16)//脚本名称为空 //The script name is null
#define EC_HD_EXPORTER_FILE_NOT_FOUND                               (EC_HD_EXPORTER_BASE + 17)//脚本文件未找到 //The script file can not be found
#define EC_HD_EXPORTER_FILE_INVALID                                       (EC_HD_EXPORTER_BASE + 18)//脚本文件名非法 //Invalid script file name
#define EC_HD_EXPORTER_MEMORY_LIMITED                             (EC_HD_EXPORTER_BASE + 19)//无法分配空间 //No memory to allocate
#define EC_HD_EXPORTER_EMPTY_POINTER                                (EC_HD_EXPORTER_BASE + 20)//使用指针为空 //Null pointer
#define EC_HD_EXPORTER_PYTHON_EXCEPTION                        (EC_HD_EXPORTER_BASE + 21)//执行Python函数异常 //Execute python function with exception
#define EC_HD_EXPORTER_INIT_PYTHON                                     (EC_HD_EXPORTER_BASE + 22)//启动Python环境异常 //Start python with exception
#define EC_HD_EXPORTER_IMPORT_PYTHON                              (EC_HD_EXPORTER_BASE + 23)//导入Python文件异常 //Import python file with exception
#define EC_HD_EXPORTER_DELETE_MODULE                               (EC_HD_EXPORTER_BASE + 24)//待删除脚本规则不存在 //The script rule to be deleted does not exist
#define EC_HD_EXPORTER_NULL_HDINFO                                    (EC_HD_EXPORTER_BASE + 25)//回调注册规则hdInfo为空 //IHyperDB Infomation is null in registering rules callback
#define EC_HD_EXPORTER_NULL_RDBINFO                                   (EC_HD_EXPORTER_BASE + 26)//回调注册规则rdbInfo为空 //Relational database Infomation is null in registering rules callback
#define EC_HD_EXPORTER_NULL_SCRIPTINFO                              (EC_HD_EXPORTER_BASE + 27)//回调注册规则scriptInfo为空 //Script Infomation is null in registering rules callback
#define EC_HD_EXPORTER_NULL_TAG                                            (EC_HD_EXPORTER_BASE + 28)//回调添加空Tag至脚本 //No tag was added into script in callback
#define EC_HD_EXPORTER_NULL_EXECSQL_RDBINFO                 (EC_HD_EXPORTER_BASE + 29)//回调执行SQL传入空的rdbInfo //When executing SQL in callback, null relational database infomation was passed in
#define EC_HD_EXPORTER_REG_HD                                                (EC_HD_EXPORTER_BASE + 30)//脚本注册实时数据库信息失败 //Register iHyperDB information failed in script
#define EC_HD_EXPORTER_REG_RDB                                              (EC_HD_EXPORTER_BASE + 31)//脚本注册关系数据库信息失败 //Register relational database information failed in script
#define EC_HD_EXPORTER_EXTRACT_BOOST_PYTHON              (EC_HD_EXPORTER_BASE + 32)//转换BoostPython类型失败 //Transform the type of boost python failed
#define EC_HD_EXPORTER_INCONSISTENT_INFO                         (EC_HD_EXPORTER_BASE + 33)//脚本提供上下不一致信息 //The informations in script are inconsistent
#define EC_HD_EXPORTER_NOT_REG                                              (EC_HD_EXPORTER_BASE + 34)//脚本未注册不能运行 //The script is not registered, so it can not be executed
#define EC_HD_EXPORTER_WRONG_SCRIPT_TYPE                       (EC_HD_EXPORTER_BASE + 35)//脚本转储方式非法 //Invalid dump mode in script
#define EC_HD_EXPORTER_REDUPLICATE_TAG                             (EC_HD_EXPORTER_BASE + 36)//脚本重复添加Tag //Duplicated tags were added into script
#define EC_HD_EXPORTER_SCRIPT_HD_IP                                      (EC_HD_EXPORTER_BASE + 37)//脚本注册实时数据库IP错误 //Script registered iHyperDB IP failed
#define EC_HD_EXPORTER_SCRIPT_HD_PORT                               (EC_HD_EXPORTER_BASE + 38)//脚本注册实时数据库端口号错误 //Script registered iHyperDB port failed
#define EC_HD_EXPORTER_SCRIPT_RDB_DIRECTION                    (EC_HD_EXPORTER_BASE + 39)//脚本注册转储方向非法 //Script registered invalid dump direction
#define EC_HD_EXPORTER_SCRIPT_RDB_DSN                                (EC_HD_EXPORTER_BASE + 40)//脚本注册关系数据库DSN非法 //Script registered invalid DSN of relational database
#define EC_HD_EXPORTER_SCRIPT_RDB_TYPE                              (EC_HD_EXPORTER_BASE + 41)//脚本注册关系数据库类型错误 //Script registered wrong type of relational database
#define EC_HD_EXPORTER_SCRIPT_RDB_OPTION                         (EC_HD_EXPORTER_BASE + 42)//脚本注册关系数据库连接选项非法 //Script registered invalid connection options of relational database
#define EC_HD_EXPORTER_SCRIPT_RDB_USER                              (EC_HD_EXPORTER_BASE + 43)//脚本注册关系数据库用户名错误 //Script registered wrong username of relational database
#define EC_HD_EXPORTER_SCRIPT_RDB_PASSWORD                   (EC_HD_EXPORTER_BASE + 44)//脚本注册关系数据库密码错误 //Script registered wrong password of relational database
#define EC_HD_EXPORTER_SCRIPT_REC_START                            (EC_HD_EXPORTER_BASE + 45)//脚本注册记录起始时间错误 //Script registered wrong start time of records
#define EC_HD_EXPORTER_SCRIPT_REC_INTERVAL                      (EC_HD_EXPORTER_BASE + 46)//脚本注册记录间隔时间错误 //Script registered wrong interval time of records
#define EC_HD_EXPORTER_SCRIPT_EXEC_START                          (EC_HD_EXPORTER_BASE + 47)//脚本注册转储开始时间错误 //Script registered wrong start time of dump
#define EC_HD_EXPORTER_SCRIPT_EXEC_CIRCLE                          (EC_HD_EXPORTER_BASE + 48)//脚本注册转储间隔时间错误 //Script registered wrong interval time of dump
#define EC_HD_EXPORTER_SCRIPT_TRANSFER_TYPE                   (EC_HD_EXPORTER_BASE + 49)//脚本注册转储类型错误 //Script registered wrong type of dump
#define EC_HD_EXPORTER_SCRIPT_GET_MAX_TIME                    (EC_HD_EXPORTER_BASE + 50)//获取上一次转储最大时间戳失败 //Get the maximum timestamp of last time failed
#define EC_HD_EXPORTER_SCRIPT_CONNECT_RDB                     (EC_HD_EXPORTER_BASE + 51)//脚本连接关系数据库失败 //Script connected to the relational database failed
#define EC_HD_EXPORTER_SCRIPT_INVALID_TAG                        (EC_HD_EXPORTER_BASE + 52)//实时数据库中不存在该Tag //The tag does not exist in iHyperDB
#define EC_HD_EXPORTER_SCRIPT_HD_DISCONNECT                 (EC_HD_EXPORTER_BASE + 53)//未连接实时数据库 //Not connected to iHyperDB
#define EC_HD_EXPORTER_SCRIPT_GET_HD_DATA                      (EC_HD_EXPORTER_BASE + 54)//获取Tag点数据失败 //Get tags values from iHyperDB failed
#define EC_HD_EXPORTER_SCRIPT_TAG_NUM                             (EC_HD_EXPORTER_BASE + 55)//脚本未注册Tag点 //Tags was not registered in script
#define EC_HD_EXOPRTER_SCRIPT_TAG_CLASS                           (EC_HD_EXPORTER_BASE + 56)//脚本添加的Tag点的类别和脚本用途不一致 //The classification of tag added into script was inconsistent with the use of script
#define EC_HD_EXPORTER_SCRIPT_ON_TIMER                             (EC_HD_EXPORTER_BASE + 57)//脚本定时处理数据函数返回脚本定义错误码 //The timing function in script returned error code defined in script
#define EC_HD_EXPORTER_SCRIPT_TAG_MODE                            (EC_HD_EXPORTER_BASE + 58)//脚本添加Tag点插值模式非法 //The interpolation mode of tag added into script was invalid
#define EC_HD_EXPORTER_SCRIPT_RETURN                                  (EC_HD_EXPORTER_BASE + 59) //脚本函数返回重要错误，暂停当前执行任务 //Crucial error was returned by script function, so the currently executing task was paused 
#define EC_HD_EXPORTER_RULE_TAG_MISMATCH                     (EC_HD_EXPORTER_BASE + 60) //Tag点和规则用途不匹配 //The tag and the use of rule are inconsistent

/************************************************************************/
/*                 security   (115000 ~ 115500)                             */
/************************************************************************/


#define EC_HD_TRUSTMGR_BASE                          (EC_RD_BASENO + 5000)
#define EC_HD_TRUSTMGR_SERVER_NOT_FOUND			     (EC_HD_TRUSTMGR_BASE + 1)//服务器没找到 //The server was not found


#define EC_HD_USER_GROUP_BASE						(EC_RD_BASENO + 5050)
#define EC_HD_USER_GROUP_BLANK_ARGUMENT		        (EC_HD_USER_GROUP_BASE + 1)//参数为空 //Blank parameter
#define EC_HD_USER_GROUP_PASSWORD_INPUT				(EC_HD_USER_GROUP_BASE + 2)//密码错误 //Wrong password
#define EC_HD_USER_GROUP_USER_NAME_INPUT			(EC_HD_USER_GROUP_BASE + 3)//用户名错误 //Wrong username
#define EC_HD_USER_GROUP_USER_DESC_INPUT			(EC_HD_USER_GROUP_BASE + 4)//用户描述错误 //Wrong user description
#define EC_HD_USER_GROUP_GROUP_NAME_INPUT			(EC_HD_USER_GROUP_BASE + 5)//组名错误 //Wrong group name
#define EC_HD_USER_GROUP_GROUP_DESC_INPUT			(EC_HD_USER_GROUP_BASE + 6)//组描述错误 //Wrong group description
#define EC_HD_USER_GROUP_SERVER_INFO_INPUT		    (EC_HD_USER_GROUP_BASE + 7)//服务器错误 //Wrong server information
#define EC_HD_USER_GROUP_GET_ALL_GROUPS				(EC_HD_USER_GROUP_BASE + 8)//获取所有组错误 //Get all groups failed
#define EC_HD_USER_GROUP_GET_ALL_USERS				(EC_HD_USER_GROUP_BASE + 9)//获取所有用户错误 //Get all users failed
#define EC_HD_USER_GROUP_ADD_USER_TO_GROUP			(EC_HD_USER_GROUP_BASE + 10)//添加用户到组错误 //Add an user into a group failed
#define EC_HD_USER_GROUP_DELETE_USER_FROM_GROUP		(EC_HD_USER_GROUP_BASE + 11)//组中删除用户错误 //Delete users from a group failed

#define EC_HD_USER_GROUP_AUTHORITY_NAME_INPUT			(EC_HD_USER_GROUP_BASE + 12)//授权项命名错误 //Wrong authority name
#define EC_HD_USER_GROUP_AUTHORITY_DESC_INPUT			(EC_HD_USER_GROUP_BASE + 13)//授权项描述错误 //Wrong authority description
#define EC_HD_USER_GROUP_GET_ALL_AUTHORITIES			(EC_HD_USER_GROUP_BASE + 14)//获取所有授权项错误 //Get all authorites failed
#define EC_HD_USER_GROUP_DELETE_AUTH_FROM_GROUP		(EC_HD_USER_GROUP_BASE + 15)//组中删除授权项错误 //Delete authority from a group failed
#define EC_HD_USER_GROUP_ADD_AUTHORITY_TO_GROUP			(EC_HD_USER_GROUP_BASE + 16)//添加授权项到组错误 //Add an authority into a group failed


#define EC_HD_SCSERVER_BASE						    (EC_RD_BASENO + 5100)
#define EC_HD_SCSERVER_INVALID_INPUT			    (EC_HD_SCSERVER_BASE + 1)//参数输入错误 //Invalid parameter
#define EC_HD_SCSERVER_GET_IHYPERDB_USR			    (EC_HD_SCSERVER_BASE + 2)//获取iHyperDBUsr信息失败 //Get user information of iHyperDB failed
#define EC_HD_SCSERVER_GET_IHYPERDB_TAG			    (EC_HD_SCSERVER_BASE + 3)//获取iHyperDBTag信息失败 //Get tag information of iHyperDB failed
#define EC_HD_SCSERVER_USR_PWD_CHECK			    (EC_HD_SCSERVER_BASE + 4)//用户名或密码错误，或无权限 //Wrong username, password, or no authority
#define EC_HD_SCSERVER_INSERT_TRUST				    (EC_HD_SCSERVER_BASE + 5)//插入信任失败，IP地址或有交集 //Insert a trust failed, maybe the IP is intersected
#define EC_HD_SCSERVER_DELETE_TRUST_NOT_FIND	    (EC_HD_SCSERVER_BASE + 6)//删除信任失败，未找到对应信任 //Delete a trust failed, because the trust was not found
#define EC_HD_SCSERVER_MODIFY_TAGINDEX_MEM_NULL     (EC_HD_SCSERVER_BASE + 7)//修改tag索引，内存为空 //When modifying the tag index, the memory is null
#define EC_HD_SCSERVER_CREATE_TRUST_NAME_DUP	    (EC_HD_SCSERVER_BASE + 8)//创建信任，信任名重复 //When creating a trust, the trust name is duplicated
#define EC_HD_SCSERVER_CREATE_TRUST_FIND_USR	    (EC_HD_SCSERVER_BASE + 9)//创建信任，没有找到对应的用户 //When creating a trust, the user is not found
#define EC_HD_SCSERVER_DELETE_TRUST_NAME_NOEXSIST	(EC_HD_SCSERVER_BASE + 10)//删除信任，信任名不存在 //When deleting a trust, the trust name does not exist
#define EC_HD_SCSERVER_GET_USR_BY_IP			    (EC_HD_SCSERVER_BASE + 11)//通过IP获取对应的用户ID失败 //Get user ID by IP failed
#define EC_HD_SCSERVER_CANNOT_FIND_USR			    (EC_HD_SCSERVER_BASE + 12)//找不到用户 //Can not find the user
#define EC_HD_SCSERVER_CANNOT_FIND_GROUP		    (EC_HD_SCSERVER_BASE + 13)//找不到组 //Can not find the group
#define EC_HD_SCSERVER_ADMIN_ADD_GROUP			    (EC_HD_SCSERVER_BASE + 14)//admin用户不可添加到其他组 //The user of admin can not be added into other group
#define EC_HD_SCSERVER_USR_DUP					    (EC_HD_SCSERVER_BASE + 15)//用户名已经存在或重复 //The user name already exists or is duplicated
#define EC_HD_SCSERVER_ADMIN_DELETE				    (EC_HD_SCSERVER_BASE + 16)//admin用户不可删除 //The user of admin can not be deleted
#define EC_HD_SCSERVER_GROUP_DUP				    (EC_HD_SCSERVER_BASE + 17)//组名已经存在或重复 //The group name already exists or is duplicated
#define EC_HD_SCSERVER_ADMIN_ERASE_FROM_GROUP	    (EC_HD_SCSERVER_BASE + 18)//admin用户不可从admin组中移除 //The user of admin can not be removed from the group of admin
#define EC_HD_SCSERVER_ADD_USR_GROUP_OVERMAX	    (EC_HD_SCSERVER_BASE + 19)//添加用户到组，组中成员数目超限 //When adding a user into a group, the count of users in the group exceeds the upper limit
#define EC_HD_SCSERVER_ARRAY_INDEX_GET_VALUE	    (EC_HD_SCSERVER_BASE + 20)//数据组索引获取值失败 //Get the value of data array index failed
#define EC_HD_SCSERVER_USR_GROUP_DUP			    (EC_HD_SCSERVER_BASE + 21)//用户已经属于该组 //The user already belongs to the group
#define EC_HD_SCSERVER_ADMIN_GROUP_DELETE		    (EC_HD_SCSERVER_BASE + 22)//admin组不可删除 //The group of admin can not be deleted
#define EC_HD_SCSERVER_SC_OVER_LIMITS			    (EC_HD_SCSERVER_BASE + 23)//权限设置应按照拥有组大于等于操作组，操作组大于等于其他 //When setting authority, the owned group must be bigger than or euqal to the operation group, and the operation group must be bigger than or equal to other group
#define EC_HD_SCSERVER_STARTIP_OVER_ENDIP		    (EC_HD_SCSERVER_BASE + 24)//起始IP超过终止IP //The start IP is bigger than the end IP
#define EC_HD_SCSERVER_NO_SECURITY				    (EC_HD_SCSERVER_BASE + 25)//权限不够 //No enough authority
#define EC_HD_SCSERVER_DELETE_LOCALTRUST			(EC_HD_SCSERVER_BASE + 26)//不能删除本地IP信任 //The trust of local IP can not be deleted
#define EC_HD_FIND_SOCKET_SC_INFO					(EC_HD_SCSERVER_BASE + 27)//不能找到客户端连接对应的用户信息 //The user information related to the client socket can not be found
#define EC_HD_SCSERVER_GET_IHYPERDB_DISPATCH		(EC_HD_SCSERVER_BASE + 28)//获取iHyperDBDispatch信息失败 //Get iHyperDB dispatch information failed

#define EC_HD_SCSERVER_AUTH_ITEM_DUP				 (EC_HD_SCSERVER_BASE + 29)//授权项已经存在 //The auth item name already exists
#define EC_HD_SCSERVER_GROUP_AUTH_ITEM_DUP			 (EC_HD_SCSERVER_BASE + 30)//授权项已经属于该组 //The auth item already belongs to the group
#define EC_HD_SCSERVER_CANNOT_FIND_AUTH_ITEM         (EC_HD_SCSERVER_BASE + 31)//找不到授权项 //Can not find the auth item name
#define EC_HD_SCSERVER_USR_IN_TEN_GROUPS			    (EC_HD_SCSERVER_BASE + 32)//用户已经属于10个组 //The user already belongs to 10 groups

/************************************************************************/
/*                 alarm   (115500 ~ 115800)                             */
/************************************************************************/

#define EC_HD_ALARMGROUPMGR_BASENO				(EC_RD_BASENO + 5500)
#define EC_HD_ALARMGROUPMGR_GROUPNAME_LEN		(EC_HD_ALARMGROUPMGR_BASENO + 1) //报警组名长度超过限制 //The length of alarm group name exceeds the limit
#define EC_HD_ALARMGROUPMGR_GROUPDESC_LEN		(EC_HD_ALARMGROUPMGR_BASENO + 2) //报警组描述长度超过限制 //The length of alarm group description exceeds the limit
#define EC_HD_ALARMGROUPMGR_NO_SRV_CONN			(EC_HD_ALARMGROUPMGR_BASENO + 3) //没有已连接的服务器 //No connected server

#define EC_HD_AMSVC_BASENO							(EC_RD_BASENO + 5550)
#define EC_HD_AMSVC_GROUP_EXIST						(EC_HD_AMSVC_BASENO + 1)	//报警组已经存在 //The alarm group already exists
#define EC_HD_AMSVC_GROUP_NON_EXIST					(EC_HD_AMSVC_BASENO + 2)	//报警组不存在 //The alarm group does not exist
#define EC_HD_AMSVC_DEL_ORPHAN_GROUP				(EC_HD_AMSVC_BASENO + 3)	//删除孤儿组 //Delete the orphan group
#define EC_HD_AMSVC_MODIFY_ORPHAN_GROUP				(EC_HD_AMSVC_BASENO + 4)	//修改孤儿组 //Modify the orphan group
#define EC_HD_AMSVC_DEL_GROUP_HAS_SUB_GROUP			(EC_HD_AMSVC_BASENO + 5)	//删除的组下面有子组 //The group to be deleted has child groups
#define EC_HD_AMSVC_DEL_GROUP_HAS_SUB_POINT			(EC_HD_AMSVC_BASENO + 6)	//删除的组下面有点 //The group to be deleted has tags
#define EC_HD_AMSVC_MODIFY_GROUP_DECODE				(EC_HD_AMSVC_BASENO + 7)	//修改组命令参数解析错误 //The command parameters of modifying group were parsed wrongly
#define EC_HD_AMSVC_MODIFY_GROUP_FATHER_NONEXIST	(EC_HD_AMSVC_BASENO + 8)	//修改组组的父组不存在 //The group to be modified has no parent
#define EC_HD_AMSVC_MODIFY_GROUP_HASEXIST			(EC_HD_AMSVC_BASENO + 9)	//修改组组的父组下已经有这样的一个组 //The parent of the group to be modified already has such a group 
#define EC_HD_AMSVC_POINT_NONEXIST					(EC_HD_AMSVC_BASENO + 10)	//点不存在 //The tag does not exist
#define EC_HD_AMSVC_POINT_HASEXIST					(EC_HD_AMSVC_BASENO + 11)	//点已经存在 //The tag already exists
#define EC_HD_AMSVC_DECODE_POINT_PROP				(EC_HD_AMSVC_BASENO + 12)	//报警点属性解析失败 //The properties of alarm tag were parsed failed
#define EC_HD_AMSVC_INVALID_ACTION_TYPE				(EC_HD_AMSVC_BASENO + 13)	//无效的Action类型 //Invalid action type
#define EC_HD_AMSVC_INVALID_ACTION_ACK_STATE			(EC_HD_AMSVC_BASENO + 14)	//无效的Action确认状态 //Invalid action acknowledgement state

#define EC_HD_AMSVC_INVALID_ACTION					(EC_HD_AMSVC_BASENO + 15)	//无效的Action //Invalid action
#define EC_HD_AMSVC_INVALID_ACTION_PRI				(EC_HD_AMSVC_BASENO + 16)	//无效的Action优先级 //Invalid action priority
#define EC_HD_AMSVC_INVALID_TEST_TYPE					(EC_HD_AMSVC_BASENO + 17)	//无效的Test类型 //Invalid test type
#define EC_HD_AMSVC_INVALID_TEST						(EC_HD_AMSVC_BASENO + 18)	//无效的TEST //Invalid test
#define EC_HD_AMSVC_INVALID_AUTO_ACK					(EC_HD_AMSVC_BASENO + 19)	//无效的AUTO_ACK //Invalid auto acknowledgement
#define EC_HD_AMSVC_SN_HAS_NO_REC					(EC_HD_AMSVC_BASENO + 20)	//snapshot中没有报警记录 //The snapshot has no alarm record
#define EC_HD_AMSVC_SOURCE_TAG_NONEXIST				(EC_HD_AMSVC_BASENO + 21)	//报警点源不存在 //The source tag of alarm tag does not exist
#define EC_HD_AMSVC_MAP_FILE_NO_SPACE					(EC_HD_AMSVC_BASENO + 22)	//内存映射文件没有剩余空间 //The memory mapped file has no remained space
#define EC_HD_AMSVC_FILE_NAME_LEN						(EC_HD_AMSVC_BASENO + 23)	//文件长度超限 //The length of file exceeds
#define EC_HD_AMSVC_QUERY_GROUP_NONEXIST			(EC_HD_AMSVC_BASENO + 24)	//查询的组不存在 //The queried group does not exist
#define EC_HD_AMSVC_QUERY_POINT_NONEXIST				(EC_HD_AMSVC_BASENO + 25)	//查询的点不存在 //The queried tag does not exist
#define EC_HD_AMSVC_QUERY_SOURCE_POINT_NONEXIST	(EC_HD_AMSVC_BASENO + 26)	//报警点的源点不存在 //The source tag of alarm tag does not exist
#define EC_HD_AMSVC_CANNOT_ADD_SUBGROUP_IN_ORPAHN		(EC_HD_AMSVC_BASENO + 27)	//不能添加报警组在默认报警组下 //The sub alarm group can not be added in the default orphan alarm group
#define EC_HD_AMSVC_CANNOT_MOVE_SUBGROUP_TO_ORPAHN		(EC_HD_AMSVC_BASENO + 28)	//不能将报警组移动到默认报警组下 //The sub alarm group can not be moved to the default orphan alarm group
#define EC_HD_AMSVC_ALARM_TEST_NONEXIST                          (EC_HD_AMSVC_BASENO + 29)   //报警条件不存在 //The alarm test does not exist
#define EC_HD_AMSVC_USER_NONEXIST						(EC_HD_AMSVC_BASENO + 30)   //用户名不存在 //The user name does not exist
#define EC_HD_AMSVC_INVALID_CHANGE_TYPE				(EC_HD_AMSVC_BASENO + 31)   //不合法的变更类型 //Invalid changing type
#define EC_HD_AMSVC_ALARM_ACK_INFO_NONEXIST			(EC_HD_AMSVC_BASENO + 32)//报警确认信息不存在 //The alarm acknowledgment message does not exist
#define EC_HD_AMSVC_ALARM_COMMENT_INFO_NONEXIST    (EC_HD_AMSVC_BASENO + 33)//报警注释信息不存在 //The alarm annotation information does  not exist
#define EC_HD_AMSVC_SPC_ALARM_JUDGE_FAILED			(EC_HD_AMSVC_BASENO + 34)//SPC报警判异失败 //The SPC alarm judged abnormals failed
#define EC_HD_AMSVC_SPC_TAG_NOT_EXIST				(EC_HD_AMSVC_BASENO + 35)//SPC报警点不存在 //The SPC alarm tag does not exist
#define EC_HD_AMSVC_ALARM_TAG_NOT_EXIST				(EC_HD_AMSVC_BASENO + 36)//报警点不存在 //The alarm tag does not exist
#define EC_HD_AMSVC_ALARM_TEST_NOT_EXIST			(EC_HD_AMSVC_BASENO + 37)//报警条件不存在 //The alarm test does not exist
#define EC_HD_AMSVC_SPC_RULE_NOT_EXIST				(EC_HD_AMSVC_BASENO + 38)//SPC报警规则不存在 //The judge rules of the SPC alarm tag do not exist




/************************************************************************/
/*                       Redundancy  (115800 ~ 116000)                         */
/************************************************************************/
#define EC_HD_RY_BASENO									(EC_RD_BASENO + 5800)
#define EC_HD_RY_LOCAL_CFG_IP						(EC_HD_RY_BASENO + 1)//本地配置的IP不合法 //Invalid IP of local configuration
#define EC_HD_RY_LOCAL_CFG_PORT				(EC_HD_RY_BASENO + 2)//本地配置的端口不合法 //Invalid port of local configuration
#define EC_HD_RY_REMOTE_CFG_IP					(EC_HD_RY_BASENO + 3)//远程配置的IP不合法 //Invalid IP of remote configuration
#define EC_HD_RY_REMOTE_CFG_PORT			(EC_HD_RY_BASENO + 4)//远程配置的端口不合法 //Invalid port of remote configuration
#define EC_HD_RY_NOT_SUPPORT				(EC_HD_RY_BASENO + 5)//服务器不支持冗余 //The server does not support redundancy
#define EC_HD_RY_INVALID_PARAM				(EC_HD_RY_BASENO + 6)//不合法的参数 //Invalid parameter
#define EC_HD_RY_TAG_NAME_DIFF				(EC_HD_RY_BASENO + 7)//Tag同步时ID相同而名字不一样 //When synchronizing tags, the IDs are the same but the names are not
#define EC_HD_RY_SRV_NOT_HOST				(EC_HD_RY_BASENO + 8)//服务器不是主机 //The server is not the host
#define EC_HD_RY_SRV_IS_SYNCHRONIZING		(EC_HD_RY_BASENO + 9)//服务器正在同步 //The server is now synchronizing


/************************************************************************/
/*                   timer    (116000 ~ 116050)                         */
/************************************************************************/
#define EC_HD_TIMER_BASE				(EC_RD_BASENO + 6000)
#define EC_HD_TIMER_POINTER_NULL		(EC_HD_TIMER_BASE + 1)//指针为空 //Null pointer
#define EC_HD_TIMER_CYCLE				(EC_HD_TIMER_BASE + 2)//定时器的周期小于等于0 //The timer period is less than or equals to zero
#define EC_HD_TIMER_MUTEX_INIT			(EC_HD_TIMER_BASE + 3)//Mutex初始化失败 //Initialize Mutex failed
#define EC_HD_TIMER_EVENT_INTI			(EC_HD_TIMER_BASE + 4)//Event初始化失败 //Initialize Event failed
#define EC_HD_TIMER_THREAD_CREAT		(EC_HD_TIMER_BASE + 5)//启动定时器管理线程失败 //Start the thread of timer management failed
#define EC_HD_TIMER_INVALID_START_TIME	(EC_HD_TIMER_BASE + 6)//定时器启动时间小于0  //The timer start time is less than zero





/************************************************************************/
/*                   LogC    (116050 ~ 116100)                         */
/************************************************************************/
#define EC_RD_LOG_BASENO					(EC_RD_BASENO + 6050)
#define EC_RD_LOG_INVALID_PARAM				(EC_RD_LOG_BASENO + 1)//日志参数无效 //Invalid parameter of log
#define EC_RD_GET_LOG_CATEGORY				(EC_RD_LOG_BASENO + 2)//日志类别无效 //Invalid category of log


/************************************************************************/
/*                   ProcComm    (116100 ~ 116200)                      */
/************************************************************************/
#define EC_RD_PROCCOMM_BASENO			(EC_RD_BASENO + 6100)
#define EC_RD_PROCCOMM_NO_IDLE			(EC_RD_PROCCOMM_BASENO + 1)//进程通信没有空闲块 //There is no free block for inter process communication
#define EC_RD_PROCCOMM_SHAREMEM_CREATE	(EC_RD_PROCCOMM_BASENO + 2)//进程通信创建共享内存失败 //Create shared memory failed for inter process communication
#define EC_RD_PROCCOMM_REG_FAIL			(EC_RD_PROCCOMM_BASENO + 3)//进程通信注册失败 //Register inter process communication failed
#define EC_RD_PROCCOMM_MEM_MALLOC		(EC_RD_PROCCOMM_BASENO + 4)//进程通信malloc内存失败 //Malloc memory failed for inter process communication
#define EC_RD_PROCCOMM_NO_SHAREMEM		(EC_RD_PROCCOMM_BASENO + 5)//进程通信不存在共享内存 //There is no shared memory for inter process communication
#define EC_RD_PROCCOMM_NO_MEMSPACE		(EC_RD_PROCCOMM_BASENO + 6)//进程通信没有空闲内存空间 //There is no free memory space for inter process communication
#define EC_RD_PROCCOMM_RECV_QUIT		(EC_RD_PROCCOMM_BASENO + 7)//进程通信接收退出 //The inter process communication received quit message
#define EC_RD_PROCCOMM_RECV_TIMEOUT		(EC_RD_PROCCOMM_BASENO + 8)//进程通信接收时间超时 //The inter process communication received timeout
#define EC_RD_PROCCOMM_INVALID_SHAREMEM_NAME		(EC_RD_PROCCOMM_BASENO + 9)//进程通信不合法的共享内存名 //Invalid shared memory name for inter process communication
#define EC_RD_PROCCOMM_COMMONBLOCK_WRITE		(EC_RD_PROCCOMM_BASENO + 10)//进程通信写入公共块失败 //Write common block failed for inter process communication
#define EC_RD_PROCCOMM_COMMONBLOCK_READ		(EC_RD_PROCCOMM_BASENO + 11)//进程通信读取公共块失败 //Read common block failed for inter process communication
#define EC_RD_PROCCOMM_INVALID_INPUT		(EC_RD_PROCCOMM_BASENO + 12)//进程通信输入参数错误 //Invalid input parameter for inter process communication


/************************************************************************/
/*                   proto unpack    (116200 ~ 116300)                   */
/************************************************************************/
#define EC_HD_PROTOCAL_BASENO					    (EC_RD_BASENO + 6200)
#define EC_HD_PROTOCAL_MSG_LEN					    (EC_HD_PROTOCAL_BASENO + 1)//消息的长度不正确 //Wrong length of message
#define EC_HD_PROTOCAL_MSG_VALUE				    (EC_HD_PROTOCAL_BASENO + 2)//消息的值不正确 //Wrong value of message
#define EC_HD_PROTOCAL_PROTOBUF_SERILIZATION			(EC_HD_PROTOCAL_BASENO + 3)//Google Protobuf序列化失败 //Google protobuf serialized failed
#define EC_HD_PROTOCAL_PROTOBUF_PARSE				(EC_HD_PROTOCAL_BASENO + 4)//Google Protobuf Parse失败 //Google protobuf parsed failed
#define EC_HD_PROTOCAL_INVALID_POINTER				(EC_HD_PROTOCAL_BASENO + 5) // 输入参数为空指针	// The input parameter is null pointer
#define EC_HD_PROTOCAL_INVALID_STR_LEN				(EC_HD_PROTOCAL_BASENO + 6) // 无效的字符串长度	//Invalid string leng
/************************************************************************/
/*                   statistic scheduler    (116300 ~ 116400)                   */
/************************************************************************/
#define EC_HD_STATSSCHE_BASENO								(EC_RD_BASENO + 6300)
#define EC_HD_STATSSCHE_TAG_NO_EXIST						(EC_HD_STATSSCHE_BASENO + 1)	//统计点不存在	 //The statistical tag does not exist
#define EC_HD_STATSSCHE_INVALID_STATS_TAG_TYPE				(EC_HD_STATSSCHE_BASENO + 2)	//无效的统计点类型	 //Invalid type of statistical tag
#define EC_HD_STATSSCHE_DECODE_TAG_PROP						(EC_HD_STATSSCHE_BASENO + 3)//解析统计点属性失败 //Parse properties of statistical tag failed
#define EC_HD_STATSSCHE_SOURCE_TAG_NO_EXIST					(EC_HD_STATSSCHE_BASENO + 4)//统计点监控的点不存在 //The source tag of the statistical tag does not exist
#define EC_HD_STATSSCHE_STAGS_TAG_EXIST					(EC_HD_STATSSCHE_BASENO + 5)//统计点已经存在 //The statistical tag already exists
#define EC_HD_STATSSCHE_INVALID_SOURCE_TAG_TYPE			(EC_HD_STATSSCHE_BASENO + 6)//不合法的统计点的监控点类型 //Invalid source tag type of statistical tag
#define EC_HD_STATSSCHE_BASIC_TAG_NO_EXIST				(EC_HD_STATSSCHE_BASENO + 7)//普通点不存在 //The basic tag does not exist
#define EC_HD_STATSSCHE_SOURCE_TAG						(EC_HD_STATSSCHE_BASENO + 8)//源点不能是统计点本身 //source tag can not be stat tag itself

/*****************************************************************************************/
/*         Resource Management:  ResMgr_API   (116400 ~ 116500)        */
/*****************************************************************************************/
#define EC_HD_RESMGR_BASENO							(EC_RD_BASENO + 6400)
#define EC_HD_RESMGR_INVALID_NODE_ID				(EC_HD_RESMGR_BASENO + 1)   //传入不合法的节点ID //Invalid node ID
#define EC_HD_RESMGR_INVALID_POINTER				(EC_HD_RESMGR_BASENO + 2)   //传入为NULL的指针 //Null pointer
#define EC_HD_RESMGR_INVALID_NULL_STRING		(EC_HD_RESMGR_BASENO + 3)   //传入空的字符串 //Null string
#define EC_HD_RESMGR_INVALID_IP						(EC_HD_RESMGR_BASENO + 4)   //传入不合法的IP //Invalid IP
#define EC_HD_RESMGR_INVALID_PORT					(EC_HD_RESMGR_BASENO + 5)   //传入不合法的端口号 //Invalid port
#define EC_HD_RESMGR_INVALID_TAG_ID				(EC_HD_RESMGR_BASENO + 6)   //传入不合法的Tag id //Invalid tag ID
#define EC_HD_RESMGR_INVALID_DB_SRV_ID			(EC_HD_RESMGR_BASENO + 7)   //传入不合法的srv id //Invalid server ID
#define EC_HD_RESMGR_NOT_CONNECT					(EC_HD_RESMGR_BASENO + 8)   //未连接分组管理服务或连接已断开 //Not connected to the group management server or disconnected
#define EC_HD_RESMGR_CONNECT_FAILED				(EC_HD_RESMGR_BASENO + 9)   //连接失败 //Connect failed
#define EC_HD_RESMGR_NODE_NOT_EXIST				(EC_HD_RESMGR_BASENO + 10) //节点不存在 //The node does not exist
#define EC_HD_RESMGR_NOT_STRING_NODE			(EC_HD_RESMGR_BASENO + 11) //不是字符串变量节点 //Not a string node
#define EC_HD_RESMGR_NOT_TAG_NODE				(EC_HD_RESMGR_BASENO + 12) //不是Tag点节点 //Not a tag node
#define EC_HD_RESMGR_NOT_GROUP_NODE			(EC_HD_RESMGR_BASENO + 13) //不是分组节点 //Not a group node
#define EC_HD_RESMGR_DB_SRV_NOT_EXIST			(EC_HD_RESMGR_BASENO + 14) //ihyperdb服务器不存在 //The iHyperDB server does not exist
#define EC_HD_RESMGR_FILE_NAME_LEN						(EC_HD_RESMGR_BASENO + 15) //文件长度超限 //The length of file name exceeds the limit
#define EC_HD_RESMGR_INVALID_PARAMETER               (EC_HD_RESMGR_BASENO + 16) //不合法的参数 //Invalid parameter
#define EC_HD_RESMGR_EXIST_DB_SRV                           (EC_HD_RESMGR_BASENO + 17) //已经存在iHyperDB服务器 //The iHyperDB server already exists
#define EC_HD_RESMGR_INVALID_ARRAY_SIZE               (EC_HD_RESMGR_BASENO + 18) //不合法或过短的数组长度 //Invalid or too short size of array
#define EC_HD_RESMGR_RECORD_EXIST                          (EC_HD_RESMGR_BASENO + 19) //数据库中已存在相同记录 //The same record already exists in database
#define EC_HD_RESMGR_NODE_SAME_PARENT              (EC_HD_RESMGR_BASENO + 20) //新父节点与旧父节点相同 //The new parent node is the same to the old one
#define EC_HD_RESMGR_WRONG_NODE_TYPE              (EC_HD_RESMGR_BASENO + 21) //错误的节点类型 //Wrong node type
#define EC_HD_RESMGR_QUERY_RET_EMPTY                  (EC_HD_RESMGR_BASENO + 22) //查询结果为空 //Queried result is empty
#define EC_HD_RESMGR_MOVE_TO_CHILD                    (EC_HD_RESMGR_BASENO + 23) //移动节点到子节点失败 //Move a node to child node failed
#define EC_HD_RESMGR_DELETE_ROOT                          (EC_HD_RESMGR_BASENO + 24) //不能删除根节点 //The root node can not be deleted
#define EC_HD_RESMGR_OVER_LEN                                (EC_HD_RESMGR_BASENO + 25) //传入的字符串超长 //The string length is too long
#define EC_HD_RESMGR_PARENT_ROOT                         (EC_HD_RESMGR_BASENO + 26) //不能在虚拟根节点下添加非分组节点 //The non group node can not be added to a vitual root node
#define EC_HD_RESMGR_OVERLENGTH_ARR_SIZE          (EC_HD_RESMGR_BASENO + 27) //数组大小超长，无法为其分配空间 //The size of array is too long, so its space can not be allocated
#define EC_HD_RESMGR_MOVE_TAG_TO_ROOT             (EC_HD_RESMGR_BASENO + 28) //不能移动Tag节点到根节点下 //The tag node can not be moved to the root node
#define EC_HD_RESMGR_MOVE_TO_SELF                       (EC_HD_RESMGR_BASENO + 29) //不能移动节点到自身 //The node can not be moved to itself
#define EC_HD_RESMGR_GROUP_DEPTH                        (EC_HD_RESMGR_BASENO + 30) //分组已经到达最大深度 //The group has already reached the the maximum depth
#define EC_HD_RESMGR_INVALID_NODE_NAME           (EC_HD_RESMGR_BASENO + 31) //传入不合法的节点名称 //Invalid node name
#define EC_HD_RESMGR_2HDSRV_COMMTAG             (EC_HD_RESMGR_BASENO + 32) //已导入两个服务器中相同ID的Tag点 //The tags with the same ID in two servers have been imported
#define EC_HD_RESMGR_TAG_CLASS_MASK                 (EC_HD_RESMGR_BASENO + 33)//查询参数中TagClass掩码错误 //The mask of tag class in queried parameter is wrong
#define EC_HD_RESMGR_QUERY_NODE_NAME            (EC_HD_RESMGR_BASENO + 34)//查询参数中节点名称非法 //The node name in query parameter is invalid
#define EC_HD_RESMGR_QUERY_TAG_NAME               (EC_HD_RESMGR_BASENO + 35)//查询参数中Tag名称非法 //The tag name in query parameter is invalid
#define EC_HD_RESMGR_QUERY_TAG_DESC                  (EC_HD_RESMGR_BASENO + 36)//查询参数中Tag描述非法 //The tag description in query parameter is invalid
#define EC_HD_RESMGR_QUERY_LIMIT                           (EC_HD_RESMGR_BASENO + 37)//查询参数中限额非法 //The limit in query parameter is invalid
#define EC_HD_RESMGR_NO_ENOUGH_BUF               (EC_HD_RESMGR_BASENO + 38) //buf空间太小 //No enough buffer
#define EC_HD_RESMGR_INVALID_CMD_TYPE			(EC_HD_RESMGR_BASENO + 39)  //非法的命令类型 //Invalid command type
#define EC_HD_RESMGR_PKG_NOT_FULL				(EC_HD_RESMGR_BASENO + 40)  //请求消息包不完整 //The request message package is incomplete
#define EC_HD_RESMGR_PARSE_PKG_FAILED			(EC_HD_RESMGR_BASENO + 41)  //解析消息包失败 //Parse the message package failed
#define EC_HD_RESMGR_SEREAL_PKG_FAILED			(EC_HD_RESMGR_BASENO + 42)  //序列化消息包失败 //Serialize the message package failed
#define EC_HD_RESMGR_BATCH_NUM_OVERFLOW     (EC_HD_RESMGR_BASENO + 43)  //批量接口数量超限 //The number is too big for batch interface
#define EC_HD_RESMGR_RUNNING_SYNC                     (EC_HD_RESMGR_BASENO + 44)  //正在进行同步 //It is now synchronizing
#define EC_HD_RESMGR_AUTO_SYNC_TIME                  (EC_HD_RESMGR_BASENO + 45)  //自动同步时刻非法 //Invalid time of auto synchronization
#define EC_HD_RESMGR_SYNC_TOKEN                           (EC_HD_RESMGR_BASENO + 46) //同步任务令牌错误 //Wrong token of synchronization task
#define EC_HD_RESMGR_SQLITE_LOCK                           (EC_HD_RESMGR_BASENO + 47) //数据库端被锁定，请稍候 //Sqlite is locked Please wait a moment
#define EC_HD_RESMGR_SRVIP_NOT_EXIST                           (EC_HD_RESMGR_BASENO + 48) //IP不存在 //IP does not exist
#define EC_HD_RESMGR_SRVID_NOT_EXIST                           (EC_HD_RESMGR_BASENO + 49) //服务器不存在 //The server does not exist


#define EC_HD_RES_EXCEL_UPLOAD_HAS_NODEID			(EC_HD_RESMGR_BASENO + 50)	//创建分组Tag时不可输入节点ID //When uploading tags of one group, the node ID can not be inputted
#define EC_HD_RES_EXCEL_UPLOAD_NO_GROUPPATH		(EC_HD_RESMGR_BASENO + 51)	//分组路径为空 //The group path is null
#define EC_HD_RES_EXCEL_UPLOAD_CREATE_GROUP_NODE_FAIL		(EC_HD_RESMGR_BASENO + 52)	//创建组节点失败 //Create group node failed
#define EC_HD_RES_EXCEL_UPLOAD_CONVERT_TO_UINT		(EC_HD_RESMGR_BASENO + 53)	//类型转换为uint时失败 //Convert type to unit failed
#define EC_HD_RES_EXCEL_UPLOAD_GET_SRVID				(EC_HD_RESMGR_BASENO + 54)	//获取服务ID失败 //Get server ID failed
#define EC_HD_RES_EXCEL_UPLOAD_WRONG_TAGTYPE			(EC_HD_RESMGR_BASENO + 55)	//错误的tag类别 //Wrong tag type
#define EC_HD_RES_EXCEL_UPLOAD_NO_NODEID					(EC_HD_RESMGR_BASENO + 56)	//无分组ID //No group node ID
#define EC_HD_RES_EXCEL_UPLOAD_INVALID_NODENAME					(EC_HD_RESMGR_BASENO + 57)	//节点名不合法 //Invalid node name
#define EC_HD_RES_EXCEL_UPLOAD_INVALID_GROUPPATH					(EC_HD_RESMGR_BASENO + 58)	//分组路径不合法 //Invalid group path
#define EC_HD_RES_EXCEL_UPLOAD_INVALID_TAGID				(EC_HD_RESMGR_BASENO + 59)	//TagID不合法 //Invalid tag ID
#define EC_HD_RES_EXCEL_UPLOAD_INVALID_TAGID_ZERO				(EC_HD_RESMGR_BASENO + 60)	//TagID不能是0 //The tag ID can not be zero
#define EC_HD_RES_EXCEL_UPLOAD_INVALID_PORT_NULL				(EC_HD_RESMGR_BASENO + 61)	//端口号不能为空 //The port can not be null
#define EC_HD_RES_EXCEL_UPLOAD_INVALID_IP				(EC_HD_RESMGR_BASENO + 62)	//IP不合法 //Invalid IP
#define EC_HD_RES_EXCEL_UPLOAD_INVALID_PORT				(EC_HD_RESMGR_BASENO + 63)	//端口号不合法 //Invalid port
#define EC_HD_RES_EXCEL_UPLOAD_INVALID_TAGNAME				(EC_HD_RESMGR_BASENO + 64)	//Tag名不合法 //Invalid tag name
#define EC_HD_RES_EXCEL_UPLOAD_INVALID_DESC				(EC_HD_RESMGR_BASENO + 65)	//Tag描述不合法 //Invalid tag description
#define EC_HD_RES_EXCEL_UPLOAD_INVALID_NODEID_ZERO				(EC_HD_RESMGR_BASENO + 66)	//节点ID不能是0 //The node ID can not be zero
#define EC_HD_RES_EXCEL_UPLOAD_INVALID_NODEID				(EC_HD_RESMGR_BASENO + 67)	//节点ID不合法 //Invalid node ID


/*****************************************************************************************/
/*         Config server:  ConfigServer   (116500 ~ 116600)        */
/*****************************************************************************************/
#define EC_HD_CFGSRV_BASENO							(EC_RD_BASENO + 6500)
#define EC_HD_CFGSRV_UNKNOWN_CMD_TYPE				(EC_HD_CFGSRV_BASENO + 1)   //传入不合法的命令类型 //Invalid command type
#define EC_HD_CFGSRV_TAG_EXIST						(EC_HD_CFGSRV_BASENO + 2)   //点己存在，无法完成操作 //The tag already existsCannot complete action
#define EC_HD_CFGSRV_ADJUST_EXPR_TOO_LONG						(EC_HD_CFGSRV_BASENO + 3)   //修正后的表达式超长 //The adjusted expression is too long

/*****************************************************************************************/
/*         ExpCalc:     (116600 ~ 116700)        */
/*****************************************************************************************/
#define EC_HD_EXPCALC_BASENO							(EC_RD_BASENO + 6600)
#define EC_HD_EXPCALC_TAG_ID_NOT_EXIST					(EC_HD_EXPCALC_BASENO + 1)  //计算点id不存在 //The calculated tag ID does not exist
#define EC_HD_EXPCALC_TAG_GROUP_NOT_EXIST				(EC_HD_EXPCALC_BASENO + 2)  //计算点分组不存在 //The group of calculated tags does not exist
#define EC_HD_EXPCALC_TAG_NO_DATA				        (EC_HD_EXPCALC_BASENO + 3)  //普通点没有数据 //The basic tag has no data
#define EC_HD_EXPCALC_DENOM_IS_ZERO                     (EC_HD_EXPCALC_BASENO + 4)  //表达式中分母为0 //The denominator in expression is zero
#define EC_HD_EXPCALC_EXPR_UNKNOW_TOKEN                 (EC_HD_EXPCALC_BASENO + 5)  //表达式非法字符 //The expression has illegal characters
#define EC_HD_EXPCALC_EXP_PAREN_MISMATCH                (EC_HD_EXPCALC_BASENO + 6)  //表达式括号不匹配 //The parentheses in expression are mismatched
#define EC_HD_EXPCALC_EXP_SYNTAX_ERROR                  (EC_HD_EXPCALC_BASENO + 7)  //表达式语法错误 //Syntax error in expression
#define EC_HD_EXPCALC_EXP_VAR_FLAG_MISMATCH             (EC_HD_EXPCALC_BASENO + 8)  //表达式变量标识符不匹配 //The variable flags in expression are mismatched
#define EC_HD_EXPCALC_EXP_VAR_NULL                      (EC_HD_EXPCALC_BASENO + 9)  //表达式变量为空 //The variable in expression is null
#define EC_HD_EXPCALC_EXP_MUST_HAVE_A_VAR               (EC_HD_EXPCALC_BASENO + 10)  //表达式至少有一个普通点 //The expression must at least have one basic tag
#define EC_HD_EXPCALC_EXP_UNCLAC_TYPE                   (EC_HD_EXPCALC_BASENO + 11)  //表达式包含不支持的类型 //The expression contains unsupported type
#define EC_HD_EXPCALC_EXPR_UNKNOW_OP                    (EC_HD_EXPCALC_BASENO + 12)  //表达式存在未知操作符 //The expression contains unknown operator
#define EC_HD_EXPCALC_CALC_BREAK						(EC_HD_EXPCALC_BASENO + 13)  //表达式计算中断 //The caculation of expression broke
#define EC_HD_EXPCALC_REC_LESS_THAN_HIS_START_TIME		(EC_HD_EXPCALC_BASENO + 14)  //查到的历史记录时间早于历史记录开始时间 //The timestamp of queried history record is earlier than the start time of history record
#define EC_HD_EXPCALC_EXP_IFTHENELSE_MISMATCH           (EC_HD_EXPCALC_BASENO + 15)  //表达式中if else不配对  //The identifiers if, then and else in expression are mismatched
#define EC_HD_EXPCALC_EXP_IFTHENELSE_NEED_PAREN         (EC_HD_EXPCALC_BASENO + 16)  //条件表达式中标识符后缺少括号 //There is no parentheses after the identifier in the conditional expression
#define EC_HD_EXPCALC_TAG_NOT_EXIST         (EC_HD_EXPCALC_BASENO + 17)  //计算点不存在 //The calculated tag does not exist
#define EC_HD_EXPCALC_EXP_MISMATCH_FUNCTION_ARGS		(EC_HD_EXPCALC_BASENO + 18)  //表达式内置函数参数错误 //The inner function parameters of expression error
#define EC_HD_EXPCALC_EXP_UNKNOW_FUNCTION				(EC_HD_EXPCALC_BASENO + 19)	 //表达式内置函数未找到 //Can not find inner function
#define EC_HD_EXPCALC_FILEXTREAM_FAIL					(EC_HD_EXPCALC_BASENO + 20)	 //极大值过滤条件判断错误 //The filter condition of inner function error
#define EC_HD_EXPCALC_NO_OUTPUT					(EC_HD_EXPCALC_BASENO + 21)	 //不保存计算结果 //Do not save calc result


/*****************************************************************************************/
/*         Hdrda:     (116700 ~ 116800)        */
/*****************************************************************************************/
#define EC_HD_HDRDA_BASENO						(EC_RD_BASENO + 6700)
#define EC_HD_HDRDA_INVALID_PARAM				(EC_HD_HDRDA_BASENO + 1)//接口传入不合法的参数 //Invalid parameter from interface
#define EC_HD_HDRDA_MEM_MALLOC					(EC_HD_HDRDA_BASENO + 2)//内存分配失败 //Malloc memory failed
#define EC_HD_HDRDA_TAG_NAME					(EC_HD_HDRDA_BASENO + 3)//TagName长度超长 //The length of tag name is too long
#define EC_HD_HDRDA_TAG_NO_REC					(EC_HD_HDRDA_BASENO + 4)//Tag点没有记录 //The tag has no records
#define EC_HD_HDRDA_TAG_UNREG					(EC_HD_HDRDA_BASENO + 5)//Tag点没有注册 //The tag is not registered
#define EC_HD_HDRDA_NODE_UNREG					(EC_HD_HDRDA_BASENO + 6)//节点未注册 //The node is not registered
#define EC_HD_HDRDA_NO_LIC						(EC_HD_HDRDA_BASENO + 7)//没有组态license //No license of configuration
#define EC_HD_HDRDA_NOT_INIT						(EC_HD_HDRDA_BASENO + 8)//hdrda没有初始化 //Hdrda is not initialized
#define EC_HD_HDRDA_EMPTY_RESULT_SET			(EC_HD_HDRDA_BASENO + 9)//查询结果为空 //Queried result is empty
#define EC_HD_HDRDA_ENUM_END_OF_ARRAY			(EC_HD_HDRDA_BASENO + 10)//已达到查询结果队列尾端 //Enumeration has reached the end of queried result array

/*****************************************************************************************/
/*         Backup:     (116800 ~ 116860)        */
/*****************************************************************************************/
#define EC_HD_BACKUP_BASENO							(EC_RD_BASENO + 6800)
#define EC_HD_BACKUP_DB_PATH_BUILD_FAILED			(EC_HD_BACKUP_BASENO + 1)//生成备份文件路径失败 //Generate the directory of backup files failed 
#define EC_HD_BACKUP_DB_OPEN_FAILED					(EC_HD_BACKUP_BASENO + 2)//打开备份索引文件失败 //Open the backup index file failed
#define EC_HD_BACKUP_DB_CLOSE_FAILED				(EC_HD_BACKUP_BASENO + 3)//关闭备份索引文件失败 //Close the backup index file failed
#define EC_HD_BACKUP_DB_TABLE_CREATE_FAILED			(EC_HD_BACKUP_BASENO + 4)//创建备份索引表失败 //Create the backup index table failed
#define EC_HD_BACKUP_DB_ADD_LOG_FAILED				(EC_HD_BACKUP_BASENO + 5)//添加备份日志失败 //Add the backup log failed
#define EC_HD_BACKUP_DB_INPUT_DATA_INVALID			(EC_HD_BACKUP_BASENO + 6)//非法输入参数 //Invalid input parameter
#define EC_HD_BACKUP_DB_UPDATE_LOG_FAILED			(EC_HD_BACKUP_BASENO + 7)//更新备份日志失败 //Update the backup log failed
#define EC_HD_BACKUP_DB_QUERY_LOG_FAILED			(EC_HD_BACKUP_BASENO + 8)//查询备份日志失败 //Query the backup log failed
#define EC_HD_BACKUP_INVALID_IP						(EC_HD_BACKUP_BASENO + 9)//无效IP地址 //Invalid IP
#define EC_HD_BACKUP_INVALID_TIME_REGION			(EC_HD_BACKUP_BASENO + 10)//无效时间区间 //Invalid time interval
#define EC_HD_BACKUP_FAILED_READ_BYTES				(EC_HD_BACKUP_BASENO + 11)//读取文件失败 //Read file failed
#define EC_HD_BACKUP_INVALID_HD_TYPE				(EC_HD_BACKUP_BASENO + 12)//无效的实时数据库类型 //Invalid iHyperDB type
#define EC_HD_BACKUP_NO_TAG_INDEX					(EC_HD_BACKUP_BASENO + 13)	//查找的数据块索引不存在 //The index of queried data block does not exist
#define EC_HD_BACKUP_NO_ENOUGH_MEM					(EC_HD_BACKUP_BASENO + 14)	//缓存空间不足 //No enough memory
#define EC_HD_BACKUP_INVALID_BK_CONFIG_LEN			(EC_HD_BACKUP_BASENO + 15)	//备份配置文件和实际发送长度不符 //The backup configuration file is inconsistent with the really sent length
#define EC_HD_BACKUP_ARG_PARSE_FAILED				(EC_HD_BACKUP_BASENO + 16)	//命令行参数解析失败 //Parse the command line arguments failed
#define EC_HD_BACKUP_INVALID_ARG					(EC_HD_BACKUP_BASENO + 17)	//不合法的参数 //Invalid parameter
#define EC_HD_BACKUP_DUPLICATE_ARG					(EC_HD_BACKUP_BASENO + 18)	//重复的参数 //Duplicated parameter
#define EC_HD_BACKUP_ARG_NOT_FOUND					(EC_HD_BACKUP_BASENO + 19)	//未找到参数 //Parameter was not found
#define EC_HD_BACKUP_FILE_NAME_INVALID				(EC_HD_BACKUP_BASENO + 20)	//文件名称不合法 //Invalid file name
#define EC_HD_BACKUP_FILE_NOT_EXIST					(EC_HD_BACKUP_BASENO + 21)	//文件不存在 //The file does not exist
#define EC_HD_BACKUP_COMPRESS_FAILED				(EC_HD_BACKUP_BASENO + 22)	//压缩失败 //Compress failed
#define EC_HD_BACKUP_CANNOT_COMPRESS				(EC_HD_BACKUP_BASENO + 23)	//不能被压缩 //Can not be compressed
#define EC_HD_BACKUP_UNCOMPRESS_FAILED				(EC_HD_BACKUP_BASENO + 24)	//解压失败 //Decompress failed
#define EC_HD_BACKUP_CANNOT_UNCOMPRESS				(EC_HD_BACKUP_BASENO + 25)	//不能被解压 //Can not be decompressed
#define EC_HD_BACKUP_NOT_SET_SRC_HD					(EC_HD_BACKUP_BASENO + 26)		//未设置备份源实时数据库 //The source iHyperDB of backup is not set
#define EC_HD_BACKUP_MEM_MALLOC						(EC_HD_BACKUP_BASENO + 27)		//内存分配失败 //Malloc memory failed
#define EC_HD_BACKUP_SEREAL_PKG_FAILED				(EC_HD_BACKUP_BASENO + 28)		//序列化消息失败 //Serialize the message package failed
#define EC_HD_BACKUP_PARSE_PKG_FAILED				(EC_HD_BACKUP_BASENO + 29)		//解析消息失败 //Parse the message package failed
#define EC_HD_BACKUP_UNKNOWN_OPER_TYPE				(EC_HD_BACKUP_BASENO + 30)		//无法识别的备份操作类型 //Unknown backup operation type
#define EC_HD_BACKUP_CACULATE_FAILED				(EC_HD_BACKUP_BASENO + 31)		//计算错误 //Calculate failed
#define EC_HD_BACKUP_LOCK_EXEC_FAILED				(EC_HD_BACKUP_BASENO + 32)		//获取执行任务锁失败 //Acquire the task execution lock failed
#define EC_HD_BACKUP_BKDB_NO_EXIST					(EC_HD_BACKUP_BASENO + 33)		//备份库不存在 //The backup database does not exist
#define EC_HD_BACKUP_BACKUP_DIR_TOO_LONG			(EC_HD_BACKUP_BASENO + 34)		//备份路径超长 //The length of backup directory is too long
#define EC_HD_BACKUP_BACKUP_DIR_NO_ABS				(EC_HD_BACKUP_BASENO + 35)		//备份路径不是绝对路径 //The backup directory is not the absolute path
#define EC_HD_BACKUP_ALREADY_START					(EC_HD_BACKUP_BASENO + 36)		//备份库己启动 //The backup is already started
#define EC_HD_BACKUP_ALREADY_STOP					(EC_HD_BACKUP_BASENO + 37)		//备份库己停止 //The backup is already stopped
#define EC_HD_BACKUP_INVALID_LOGID					(EC_HD_BACKUP_BASENO + 38)		//非法备份日志ID //Invalid log ID of backup
#define EC_HD_BACKUP_UNKNOWN_STATUS					(EC_HD_BACKUP_BASENO + 39)		//因备份服务退出导致备份任务状态未知 //The status of backup task is unknown because the backup server quitted
#define EC_HD_BACKUP_CONFIG_DISCORD					(EC_HD_BACKUP_BASENO + 40)		//备份文件与实时数据库服务器点配置不一致 //The configuration of tags in the backup files is inconsistent with that of iHyperDB server
//error code 
#define EC_RD_BACKUP_RUNMODE_INVALID				(EC_HD_BACKUP_BASENO + 41)			//备份库模式错误 //Invalid running mode of backup
#define EC_RD_BACKUP_IP_INVALID				(EC_HD_BACKUP_BASENO + 42)			//IP错误 //Invalid IP
#define EC_RD_BACKUP_PORT_INVALID 				(EC_HD_BACKUP_BASENO + 43)			//端口号错误 //Invalid port
#define EC_RD_BACKUP_WEEK_INVALID 				(EC_HD_BACKUP_BASENO + 44)			//错误的周数 //Invalid number of weeks
#define EC_RD_BACKUP_HOUR_INVALID 				(EC_HD_BACKUP_BASENO + 45)			//错误的小时数 //Invalid number of hours
#define EC_RD_BACKUP_DAY_INVALID 				(EC_HD_BACKUP_BASENO + 46)			//错误的天数 //Invalid number of days
#define EC_RD_BACKUP_MONTH_INVALID 				(EC_HD_BACKUP_BASENO + 47)			//错误的月份数 //Invalid number of monthes
#define EC_RD_BACKUP_SCHMODE_INVALID 				(EC_HD_BACKUP_BASENO + 48)			//错误的模式 //Invalid mode
#define EC_RD_BACKUP_LOAD_CONFIG_FAILED 				(EC_HD_BACKUP_BASENO + 49)			//加载配置文件失败 //Load the configuration file failed
#define EC_RD_BACKUP_TIME_INVALID 				(EC_HD_BACKUP_BASENO + 50)			//时间不合法 //Invalid time
#define EC_RD_BACKUP_FIND_FAILED 				(EC_HD_BACKUP_BASENO + 51)			//查找失败 //Query failed
#define EC_RD_BACKUP_DBNAME_EXIST 				(EC_HD_BACKUP_BASENO + 52)			//备份库已存在 //The backup database already exists
#define EC_RD_BACKUP_DBPATH_EXIST 				(EC_HD_BACKUP_BASENO + 53)			//备份路径已存在 //The backup directory already exists
#define EC_RD_BACKUP_USER_INVALID				(EC_HD_BACKUP_BASENO + 54)			//用户名错误 //Invalid user name
#define EC_RD_BACKUP_PASSWORD_INVALID 				(EC_HD_BACKUP_BASENO + 55)			//密码错误 //Invalid password
/*****************************************************************************************/
/*         SQL:     (116900 ~ 116950)        */
/*****************************************************************************************/
#define EC_HD_SQL_BASENO							(EC_RD_BASENO + 6900)
#define EC_HD_SQL_INVALID_TIMESTEP_VAL			(EC_HD_SQL_BASENO + 1)			//无效的插值时间间隔 //Invalid interpolation time interval
#define EC_HD_SQL_FIELD_NO_SUPPORT_CMP_OPER			(EC_HD_SQL_BASENO + 2)			//表字段不支持的比较操作符 //The current compare operator is not supported by the table fields
#define EC_HD_SQL_NOT_EXIST_FIELD			(EC_HD_SQL_BASENO + 3)				// SQL中出现表中不存在的字段 //Fields no not exsit in the table
#define EC_HD_SQL_OVERFLOW_TIMESTEP_VAL			(EC_HD_SQL_BASENO + 4)			//插值时间间隔超出允许范围 //The interpolation time interval is bigger than the allowed range
#define EC_HD_SQL_INVALID_LIMIT_COUNT			(EC_HD_SQL_BASENO + 5)			//无效的查询最大条数 //Invalid query limitness of maximum number
#define EC_HD_SQL_PARSE_FAILED			(EC_HD_SQL_BASENO + 6)					//解析SQL失败 //Parse the SQL failed
#define EC_HD_SQL_DUP_FIELD			(EC_HD_SQL_BASENO + 7)					//SQL中SELECT重复字段 //Duplicated field
#define EC_HD_ODBC_SQL_TOO_LONG			(EC_HD_SQL_BASENO + 8)					//SQL语句超长 //The SQL statement is overlength
#define EC_HD_ODBC_INVALID_TIME_STR			(EC_HD_SQL_BASENO + 9)				//无效的时间字符串 //Invalid time string
#define EC_HD_ODBC_UNPARSE_SQL				(EC_HD_SQL_BASENO + 10)				//未解析SQL //The SQL was not parsed
#define EC_HD_ODBC_UNSET_SQL				(EC_HD_SQL_BASENO + 11)				//未设置SQL //The SQL was not set
#define EC_HD_ODBC_QUERY_COND_DIFF_PROP				(EC_HD_SQL_BASENO + 12)		//查询条件属性不相同 //The query condition differs from the property
#define EC_HD_ODBC_INVALID_TIME_REGION				(EC_HD_SQL_BASENO + 13)		//无效的时间区间 //Invalid time interval
#define EC_HD_ODBC_NO_ENOUGH_ATTR_BUF			(EC_HD_SQL_BASENO + 14)		// 生成DSN, 空间不足 //No enough buffer to generate DSN
#define EC_HD_ODBC_INVALID_DSN_ATTR			(EC_HD_SQL_BASENO + 15)		// DSN格式不正确 //Invalid DSN format
#define EC_HD_ODBC_STMT_ITER_END			(EC_HD_SQL_BASENO + 16)		// STMT迭代结束 //End of iteration in STMT
#define EC_HD_ODBC_STMT_INVALID_FIELD_NUM			(EC_HD_SQL_BASENO + 17)		// 无效的字段号 //Invalid field number in STMT
#define EC_HD_ODBC_STMT_INVALID_FIELD_VAL			(EC_HD_SQL_BASENO + 18)		// 无效的字段值 //Invalid field value in STMT
#define EC_HD_ODBC_STMT_BIND_COL_BUF_NO_ENOUGH			(EC_HD_SQL_BASENO + 19)		//绑定buf长度不足 //No enough buffer for the bound column in STMT
#define EC_HD_ODBC_STMT_TIME_STR_BUF_NO_ENOUGH			(EC_HD_SQL_BASENO + 20)		//时间字符串空间长度不足 //No enough space for the time string in STMT
#define EC_HD_ODBC_STMT_CANNOT_CONVERT_RECVAL			(EC_HD_SQL_BASENO + 21)		// 记录值无法转换为指定VAL类型 //Can not convert the record value to the specified variable type in STMT
#define EC_HD_ODBC_FAILED_GET_DSN_ATTR			(EC_HD_SQL_BASENO + 22)		// 无法获取指定DSN对应的属性 //Can not get the specified attributes of DSN
#define EC_HD_ODBC_UNKNOWN_CONN_ATTR			(EC_HD_SQL_BASENO + 23)		// 未知的连接属性 //Unknown connection attributes
#define EC_HD_ODBC_INVALID_CONN_ATTR_VALUE			(EC_HD_SQL_BASENO + 24)		// 无效的连接属性值 //Invalid connection attribute value
#define EC_HD_ODBC_DRV_REMOVE_FAILED			(EC_HD_SQL_BASENO + 25)		// ODBC驱动删除失败 //Remove the ODBC driver failed
#define EC_HD_ODBC_DRV_INSTALL_FAILED			(EC_HD_SQL_BASENO + 26)		// ODBC驱动安装失败 //Install the ODBC driver failed
#define EC_HD_ODBC_DRV_FAILED_GET_APP_NAME			(EC_HD_SQL_BASENO + 27)		// 获取应用名称失败 //The driver got the application name failed
#define EC_HD_ODBC_SET_CONN_ATTR_FAILED_FOR_ALREADY_CONN			(EC_HD_SQL_BASENO + 28)		// 因数据源己连接，设置连接属性失败 //Set the connection attributes failed because the data source is already connected
#define EC_HD_ODBC_MINUS_TIMESTEP_FAILED			(EC_HD_SQL_BASENO + 29)		// 基准时间减插值间隔失败，值为负数 //The reference time subtracted the interpolation interval failed, because the difference is negative
#define EC_HD_ODBC_ADD_TIMESTEP_FAILED			(EC_HD_SQL_BASENO + 30)		// 基准时间加插值间隔失败，值为负数 //The reference time adds the interpolation interval failed, because the sum is negative
#define EC_HD_SQL_NO_TAG_NAME			(EC_HD_SQL_BASENO + 31)					//点名为空串 //The tag name must be a string
#define EC_HD_ODBC_UNKNOWN_SQL_FETCH_TYPE (EC_HD_SQL_BASENO + 32)					//未知的SQLDataSources fetch类型 //Unknown fetch type of SQL data sources
#define EC_HD_ODBC_NO_DATA_SOURCE (EC_HD_SQL_BASENO + 33)					//未找到数据源或者数据源配置错误 //No data source
#define EC_HD_ODBC_FAILED_QUERY_DATA_SOURCE (EC_HD_SQL_BASENO + 34)					//查找数据源失败 //Query data source failed
#define EC_HD_ODBC_INTER_REGION_NO_REC (EC_HD_SQL_BASENO + 35)					//插值区间无数据 //No records in the interpolation interval
#define EC_HD_SQL_INVALID_BUILD_IN_FUNC_FIELD			(EC_HD_SQL_BASENO + 36)				// 仅fivalue，ffvalue字段可执行内置函数// Only fivalue, ffvalue field can exec build in function
#define EC_HD_ODBC_UNKNOWN_BUILD_IN_FUNC (EC_HD_SQL_BASENO + 37)					//无法识别的内联函数 //Unknown build in func
#define EC_HD_ODBC_NO_BIND_COL_BUF (EC_HD_SQL_BASENO + 38)					//未绑定列缓存 //Please bind col buffer
#define EC_HD_ODBC_FAILED_GET_VERSION				(EC_HD_SQL_BASENO + 39)					// 获取实时数据库版本信息失败 // Failed to get iHyperDB version
#define EC_HD_ODBC_OPT_NO_IMPL				(EC_HD_SQL_BASENO + 40)					// 操作不支持 // Option no supported
#define EC_HD_ODBC_IVALID_TAGTYPE				(EC_HD_SQL_BASENO + 41)					// 不合法的tag类型 // Ivalid tag type


/*****************************************************************************************/
/*         HdODBCSqlView:     (116970 ~ 116990)        */
/*****************************************************************************************/
#define EC_HD_ODBC_BASENO							(EC_RD_BASENO + 6970)
#define EC_HD_ODBC_INVALID_HANDLE			        (EC_HD_ODBC_BASENO + 1) //SQL查询传入无效句柄 //Invalid handle in SQL query
#define EC_HD_ODBC_INPUT_OVER_MAX_VALUE              (EC_HD_ODBC_BASENO + 2) //SQL查询最多支持十万条 //SQL query supports one hundred thousand records maximumly


/*****************************************************************************************/
/*         SysInfoSvc:     (117000 ~ 117050)        */
/*****************************************************************************************/
#define EC_HD_SYSINFO_BASENO							(EC_RD_BASENO + 7000)
#define EC_HD_SYSINFO_COLLECT_INTER_TOO_SMALL			(EC_HD_SYSINFO_BASENO + 1) //信息采集间隔太短 //The interval of collecting system information is too short
#define EC_HD_SYSINFO_INVALID_PREV_TIME					(EC_HD_SYSINFO_BASENO + 1) //上次统计时间非法 //The statistical time of the last time is invalid

/*****************************************************************************************/
/*         DispatchComm:     (117100 ~ 117200)        */
/*****************************************************************************************/
#define EC_HD_CD_COMM_BASENO                      (EC_RD_BASENO + 7100)
#define EC_HD_CD_COMM_REPO_USER_NOTSAME     	    (EC_HD_CD_COMM_BASENO + 1)  //用户账号不一致 //The user account is not consistent
#define EC_HD_CD_COMM_REPO_SQL_FAILED               (EC_HD_CD_COMM_BASENO + 2)   //sql执行失败 //Execute SQL failed
#define EC_HD_CD_COMM_REPO_PARA_NULL	            (EC_HD_CD_COMM_BASENO + 3) //存在为空的参数 //Null parameter
#define EC_HD_CD_COMM_REPO_OVERLEN                 (EC_HD_CD_COMM_BASENO + 4) //字符串超长 //The length of string is too long
#define EC_HD_CD_COMM_REPO_BAD_USER           (EC_HD_CD_COMM_BASENO + 5)  //操作者非法 //Invalid user

#define EC_HD_CD_COMM_REPO_NODE_NAME_EXISTED		(EC_HD_CD_COMM_BASENO + 11) //相同名称的节点已存在 //The node with the same name already exists
#define EC_HD_CD_COMM_REPO_NODE_IP_EXISTED			(EC_HD_CD_COMM_BASENO + 12) //相同IP的节点已存在 //The node with the same IP already exists
#define EC_HD_CD_COMM_REPO_NODE_NAME_ISNULL			(EC_HD_CD_COMM_BASENO + 13) //节点名为空 //The node name is null
#define EC_HD_CD_COMM_REPO_NODE_DEL_CHECKOUT		(EC_HD_CD_COMM_BASENO + 14) //节点被签出，不能被删除 //The node can not be deleted because it is checked out
#define EC_HD_CD_COMM_REPO_NODE_TYPE_UNKOWN		    (EC_HD_CD_COMM_BASENO + 15) //节点类型错误 //Unknown node type
#define EC_HD_CD_COMM_REPO_NODE_NOT_EXISTED			(EC_HD_CD_COMM_BASENO + 16) //节点不存在 //The node does not exist
#define EC_HD_CD_COMM_REPO_NODE_IP_ISNULL			(EC_HD_CD_COMM_BASENO + 17) //节点IP为空 //The node IP is null
#define EC_HD_CD_COMM_REPO_NODE_HAS_CHECKOUT     	(EC_HD_CD_COMM_BASENO + 18) //节点已被签出 //The node is already checked out
#define EC_HD_CD_COMM_REPO_NODE_NO_CHECKOUT     	(EC_HD_CD_COMM_BASENO + 19) //节点未被签出 //The node is not checked out
#define EC_HD_CD_COMM_REPO_NODE_WEB_EXISTED			(EC_HD_CD_COMM_BASENO + 20) // 唯一web服务器节点已添加 //The only web server node already exists
#define EC_HD_CD_COMM_REPO_NODE_IMAGE_EXISTED		(EC_HD_CD_COMM_BASENO + 21) //节点已绑定相同画面 //The node has bound the same picture
#define EC_HD_CD_COMM_REPO_HDB_NAME_EXISTED	        (EC_HD_CD_COMM_BASENO + 22) //相同名称的IHD服务器名已存在 //The iHyperDB server with the same name already exists
#define EC_HD_CD_COMM_REPO_HDB_NOT_EXISTED	        (EC_HD_CD_COMM_BASENO + 23) //对应的IHD服务器不存在 //The corresponding iHyperDB server does not exist


#define EC_HD_CD_COMM_REPO_ZTIMAGE_NAME_EXISTED		(EC_HD_CD_COMM_BASENO + 31) //相同名称的画面已存在 //The picture with the same name already exists
#define EC_HD_CD_COMM_REPO_ZTIMAGE_NOT_EXISTED	    (EC_HD_CD_COMM_BASENO + 32) //组态画面不存在 //The configuration picture does not exist
#define EC_HD_CD_COMM_REPO_ZTIMAGE_HAS_CHECKOUT     (EC_HD_CD_COMM_BASENO + 33) //画面已被签出 //The configuration picture has been checked out
#define EC_HD_CD_COMM_REPO_ZTIMAGE_NO_CHECKOUT      (EC_HD_CD_COMM_BASENO + 34) //画面未被签出 //The configuration picture is not checked out


#define EC_HD_CD_COMM_REPO_GALLERY_NAME_EXISTED		(EC_HD_CD_COMM_BASENO + 41) //相同名称的图库已存在 //The gallery with the same name already exists
#define EC_HD_CD_COMM_REPO_GALLERY_NOT_EXISTED	    (EC_HD_CD_COMM_BASENO + 42) //组态图库不存在 //The configuration gallery does not exist
#define EC_HD_CD_COMM_REPO_GALLERY_HAS_CHECKOUT     (EC_HD_CD_COMM_BASENO + 43) //图库已被签出 //The gallery has been checked out
#define EC_HD_CD_COMM_REPO_GALLERY_NO_CHECKOUT      (EC_HD_CD_COMM_BASENO + 44) //图库未被签出 //The gallery is not checked out

#define EC_HD_CD_COMM_REPO_ZTSCRIPT_NAME_EXISTED	(EC_HD_CD_COMM_BASENO + 51) //相同名称的脚本已存在 //The script with the same name already exists
#define EC_HD_CD_COMM_REPO_ZTSCRIPT_NOT_EXISTED	    (EC_HD_CD_COMM_BASENO + 52) //组态脚本不存在 //The configuration script does not exist
#define EC_HD_CD_COMM_REPO_ZTSCRIPT_HAS_CHECKOUT    (EC_HD_CD_COMM_BASENO + 53) //脚本已被签出 //The script has been checked out
#define EC_HD_CD_COMM_REPO_ZTSCRIPT_NO_CHECKOUT     (EC_HD_CD_COMM_BASENO + 54) //脚本未被签出 //The script is not checked out

#define EC_HD_CD_COMM_REPO_WEBPKG_NAME_EXISTED	    (EC_HD_CD_COMM_BASENO + 58) //相同名称的web发布包已存在 //The web release package with the same name already exists
#define EC_HD_CD_COMM_REPO_WEBPKG_NOT_EXISTED	    (EC_HD_CD_COMM_BASENO + 59) //web发布包不存在 //The release package does not exist

#define EC_HD_CD_COMM_OPEN_FILE_FAILED	    (EC_HD_CD_COMM_BASENO + 60) //打开文件失败 //Open file failed
#define EC_HD_CD_COMM_FILE_PATH_NO_EXIST	    (EC_HD_CD_COMM_BASENO + 61) //文件路径不存在 //The file path does not exist
#define EC_HD_CD_COMM_COPY_FILE                          (EC_HD_CD_COMM_BASENO + 62) //拷贝文件失败 //Copy file failed
#define EC_HD_CD_COMM_WRITE_FILE                         (EC_HD_CD_COMM_BASENO + 63) //文件写入失败 //Write file failed
#define EC_HD_CD_COMM_REMOVE_FILE                    (EC_HD_CD_COMM_BASENO + 64)  //文件移除失败 //Remove file failed
#define EC_HD_CD_COMM_LOAD_DLL                         (EC_HD_CD_COMM_BASENO + 65)  //加载动态库失败 //Load dynamic database failed
#define EC_HD_CD_COMM_FILESYSTEM                       (EC_HD_CD_COMM_BASENO + 66)  //文件系统操作错误 //The operation of file system is wrong
#define EC_HD_CD_COMM_CREATE_FOLDER               (EC_HD_CD_COMM_BASENO + 67)  //创建路径失败 //Create path failed
#define EC_HD_CD_COMM_FILE_PATH_EXIST               (EC_HD_CD_COMM_BASENO + 68)  //文件路径己存在 //The file path already exists
#define EC_HD_CD_COMM_ACE_ERROR                        (EC_HD_CD_COMM_BASENO + 69)  //ACE指定的错误 //ACE specified error
#define EC_HD_CD_COMM_FAILED_LIST_SUB_DIR               (EC_HD_CD_COMM_BASENO + 70)  //获取子目录失败 //Get subdirectory failed
#define EC_HD_CD_COMM_READ_FILE                          (EC_HD_CD_COMM_BASENO + 71)  //读取文件失败 //Read file failed
#define EC_HD_CD_COMM_DLL_FUNCTION                 (EC_HD_CD_COMM_BASENO + 72)  //获取动态库函数地址失败 //Load function address of dynamic database failed
#define EC_HD_CD_COMM_VERSION                             (EC_HD_CD_COMM_BASENO + 73)  //版本号不兼容 //Incompatible version number
#define EC_HD_CD_COMM_STRING_BUFFER_LEN       (EC_HD_CD_COMM_BASENO + 74)  //字符串操作，缓冲区太短 //The buffer is too short for string operation
#define EC_HD_CD_COMM_XML_ERROR                         (EC_HD_CD_COMM_BASENO + 75)  //请求XML消息格式错误 //Wrong XML format of request message
#define EC_HD_CD_COMM_DISK_SPACE                           (EC_HD_CD_COMM_BASENO + 76)  //磁盘可用空间不足 //No enough disk space available
#define EC_HD_CD_COMM_INVALID_ID                            (EC_HD_CD_COMM_BASENO + 77)  //非法ID //Invalid ID
#define EC_HD_CD_COMM_SQL_EMPTY                           (EC_HD_CD_COMM_BASENO + 78)  //传入空的数据库句柄指针 //Empty handle pointer of database
#define EC_HD_CD_COMM_CREATE_PATH                       (EC_HD_CD_COMM_BASENO + 79) // 创建文件夹失败，请检查文件夹名称长度 //Create folder failed, please check the length of folder name
#define EC_HD_CD_COMM_DISPATCH                            (EC_HD_CD_COMM_BASENO + 80)  // 分发失败 //Dispatch failed
#define EC_HD_CD_COMM_PUSH_SECTION                  (EC_HD_CD_COMM_BASENO + 81)  // 打包设置Section失败 //Set Section failed when packaging
#define EC_HD_CD_COMM_UPDATE_SECTION             (EC_HD_CD_COMM_BASENO + 82)  // 打包更新Section失败 //Update Section failed when packaging
#define EC_HD_CD_COMM_OUTPUT_TO_BUFFER      (EC_HD_CD_COMM_BASENO + 83)  // 打包结果缓存为字符串失败 //Package the result buffer to string failed
#define EC_HD_CD_COMM_ENCODE_PACKET              (EC_HD_CD_COMM_BASENO + 84)  // 打包失败 //Package failed
#define EC_HD_CD_COMM_UNCOMPRESS_FILE             (EC_HD_CD_COMM_BASENO + 85)  // 解压文件失败 //Decompress files failed
#define EC_HD_CD_COMM_GENERATE_MD5                (EC_HD_CD_COMM_BASENO + 86)  // 生成MD5码失败 //Generate MD5 failed
#define EC_HD_CD_COMM_RECV_RESPONSE                (EC_HD_CD_COMM_BASENO + 87)  // 接收网络消息失败 //Receive the network message failed
/*****************************************************************************************/
/*         DispatchClient:     (117200 ~ 117300)        */
/*****************************************************************************************/
#define EC_HD_CD_CLIENT_BASENO                      (EC_RD_BASENO + 7200)
#define EC_HD_CD_CLIENT_INITIALIZE  (EC_HD_CD_CLIENT_BASENO + 1)  //DRAPI初始化失败 //Initialize DRAPI failed
#define EC_HD_CD_CLIENT_GENID  (EC_HD_CD_CLIENT_BASENO + 2)  //数据包不匹配 //The packet does not match
#define EC_HD_CD_CLIENT_PORT  (EC_HD_CD_CLIENT_BASENO + 3)  //接口参数传入不合法的端口号 //Invalid port in interface parameters
#define EC_HD_CD_CLIENT_TIMEOUT  (EC_HD_CD_CLIENT_BASENO + 4)  //超时设置不合法 //Invalid timeout set
#define EC_HD_CD_CLIENT_USERNAME  (EC_HD_CD_CLIENT_BASENO + 5)  //接口参数传入不合法的操作者 //Invalid username in interface parameters
#define EC_HD_CD_CLIENT_USERINFO  (EC_HD_CD_CLIENT_BASENO + 6)  //接口参数传入不合法的操作者信息 //Invalid user information in interface parameters
#define EC_HD_CD_CLIENT_DSN  (EC_HD_CD_CLIENT_BASENO + 7)  //接口参数传入不合法的数据源名称 //Invalid data source name in interface parameters
#define EC_HD_CD_CLIENT_INCOMPLETE  (EC_HD_CD_CLIENT_BASENO + 8)  //接口参数传入不完备的信息 //Incomplete information in interface parameters
#define EC_HD_CD_CLIENT_DESC  (EC_HD_CD_CLIENT_BASENO + 9)  //接口参数传入不合法的描述 //Invalid description in interface parameters
#define EC_HD_CD_CLIENT_NODENAME  (EC_HD_CD_CLIENT_BASENO + 10)  //接口参数传入不合法的节点名称 //Invalid node name in interface parameters
#define EC_HD_CD_CLIENT_NODETYPE  (EC_HD_CD_CLIENT_BASENO + 11)  //接口参数传入不合法的节点类型 //Invalid node type in interface parameters
#define EC_HD_CD_CLIENT_PATH  (EC_HD_CD_CLIENT_BASENO + 12)  //接口参数传入不合法的路径 //Invalid path in interface parameters
#define EC_HD_CD_CLIENT_FOLDER  (EC_HD_CD_CLIENT_BASENO + 13)  //接口参数传入不合法的文件夹名称 //Invalid folder name in interface parameters
#define EC_HD_CD_CLIENT_FILE  (EC_HD_CD_CLIENT_BASENO + 14)  //接口参数传入不合法的文件名称 //Invalid file name in interface parameters
#define EC_HD_CD_CLIENT_REQTYPE  (EC_HD_CD_CLIENT_BASENO + 15)  //接口参数传入不合法的请求类型 //Invalid request type in interface parameters
#define EC_HD_CD_CLIENT_DISTRIBUTE  (EC_HD_CD_CLIENT_BASENO + 16)  //接口参数传入不一致的分发参数 //Inconsistent distribution parameters in interface parameters
#define EC_HD_CD_CLIENT_LOCAL_FILE_NO_EXIST (EC_HD_CD_CLIENT_BASENO + 17)  //本地文件不存在 //The local file does not exist
#define EC_HD_CD_CLIENT_INVALID_AUTHORITY   (EC_HD_CD_CLIENT_BASENO + 18)   //用户没有分发权限 //No authority of distribution
#define EC_HD_CD_CLIENT_DISTRIBUTE_CANCLE	(EC_HD_CD_CLIENT_BASENO + 19)   //因分发操作取消，分发未完成 //The distribution is not completed because it is cancelled
#define EC_HD_CD_CLIENT_OTHER_CONN_EXIST	(EC_HD_CD_CLIENT_BASENO + 20)   //己存在不同IP和端口号的连接 //Other connection with different IP and port already exists
#define EC_HD_CD_CLIENT_RUN_ZTDESIGN  (EC_HD_CD_CLIENT_BASENO + 21)  //启动组态编辑器失败 //Start up the configuration designer failed
#define EC_HD_CD_CLIENT_RUN_GALLERYDESIGN  (EC_HD_CD_CLIENT_BASENO + 22 ) //启动图库编辑器失败 //Start up the gallery designer failed


/*****************************************************************************************/
/*         DispatchSrv:     (117300 ~ 117400)        */
/*****************************************************************************************/
#define EC_HD_CD_SRV_BASENO                           (EC_RD_BASENO + 7300)
#define EC_HD_CD_SRV_INIT_DB_FAILED					  (EC_HD_CD_SRV_BASENO + 1)		//初始化RepoDB失败 //Initialize the repository database failed
#define EC_HD_CD_SRV_UNKNOWN_OBJ_TYPE					  (EC_HD_CD_SRV_BASENO + 2)		//未知的对象类型 //Unknown object type
#define EC_HD_CD_SRV_UNKNOWN_OPERATE_TYPE					  (EC_HD_CD_SRV_BASENO + 3)		//未知的操作类型 //Unknown operation type
#define EC_HD_CD_SRV_PACKET_NO_EXIST_FILE					  (EC_HD_CD_SRV_BASENO + 4)		//数据包中无文件 //There is no file in the packet
#define EC_HD_CD_SRV_EMPYT_PFN                                                (EC_HD_CD_SRV_BASENO + 5)    //回调函数为空 //The callback function is null
#define EC_HD_CD_SRV_FILE_EXISTED					(EC_HD_CD_SRV_BASENO + 6)    //服务端同名文件己存在 //The file with the same name already exists in the server
#define EC_HD_CD_SRV_DIR_HAS_FILE					(EC_HD_CD_SRV_BASENO + 7)    //目录下有文件存在 //There are files in the directory
#define EC_HD_CD_SRV_AGENT_RESPONSE_XML    (EC_HD_CD_SRV_BASENO + 8)  //Agent响应的XML消息格式错误 //Wrong format of the xml message responsed by the Agent
#define EC_HD_CD_SRV_AGENT_XML_ROOT            (EC_HD_CD_SRV_BASENO + 9)  //Agent响应的XML消息中无根元素 //There is no root in the XML message responsed by the Agent
#define EC_HD_CD_SRV_AGENT_XML_REQTYPE              (EC_HD_CD_SRV_BASENO + 10)  //Agent响应的XML消息中无reqtype属性 //There is no attribute of request type in XML message responsed by the Agent
#define EC_HD_CD_SRV_AGENT_XML_OBJECT         (EC_HD_CD_SRV_BASENO + 11)  //Agent响应的XML消息中无object属性 //There is no attribute of object in XML message responsed by the Agent
#define EC_HD_CD_SRV_AGENT_XML_RESULT         (EC_HD_CD_SRV_BASENO + 12)  //Agent响应的XML消息中无result属性 //There is no attribute of result in XML message responsed by the Agent

/*****************************************************************************************/
/*         DispatchParser:     (117400 ~ 117500)        */
/*****************************************************************************************/
#define EC_HD_CD_PARSER_BASENO                           (EC_RD_BASENO + 7400)
#define EC_HD_CD_PARSER_UNKNOWN_OBJ_NAME				(EC_HD_CD_PARSER_BASENO + 1)//未知的对象名称 //Unknown object name
#define EC_HD_CD_PARSER_FAILED_QUERY_ELEMENT_NAME				(EC_HD_CD_PARSER_BASENO + 2)//获取xml元素名称失败 //Get the XML element name failed
#define EC_HD_CD_PARSER_FAILED_PARSE_XMLSTR				(EC_HD_CD_PARSER_BASENO + 3)//解析xml string失败 //Parse XML string failed
#define EC_HD_CD_PARSER_FAILED_QUERY_ATTR				(EC_HD_CD_PARSER_BASENO + 4)//获取属性失败 //Get attributes failed
#define EC_HD_CD_PARSER_UNKNOWN_OPERATOR_NAME			(EC_HD_CD_PARSER_BASENO + 5)//未知的操作名称 //Unknown operation name
#define EC_HD_CD_PARSER_OBJ_NAME_DISAGREE				(EC_HD_CD_PARSER_BASENO + 6)//xml string 根节点名称与解析对象不匹配 //The root name of xml string dismatches the parsed object
#define EC_HD_CD_PARSER_UNKNOWN_DISPATCH_OBJ_NAME	(EC_HD_CD_PARSER_BASENO + 7)//未知的分发对象名称 //Unknown dispatched object name
#define EC_HD_CD_PARSER_FAILED_QUERY_ELEM				(EC_HD_CD_PARSER_BASENO + 8)//获取元素失败 //Get the element failed
#define EC_HD_CD_PARSER_INVLID_PARAM                       (EC_HD_CD_PARSER_BASENO + 9)  //参数非法 //Invalid parameter
#define EC_HD_CD_PARSER_FILEEMPTY                              (EC_HD_CD_PARSER_BASENO + 10)  //文件内容为空 //The file is empty
#define EC_HD_CD_PARSER_PACKTAIL                              (EC_HD_CD_PARSER_BASENO + 11)  //接收到的数据包尾部错误 //The tail of the received packet has error
#define EC_HD_CD_PARSER_PACKET_LEN                        (EC_HD_CD_PARSER_BASENO + 12)  //数据包长度非法 //Invalid length of packet
#define EC_HD_CD_PARSER_PACKET_NO_SECTION        (EC_HD_CD_PARSER_BASENO + 13)  //数据包中包含的数据节的个数为0 //The count of sections in the packet is zero
#define EC_HD_CD_PARSER_NO_FILE                                 (EC_HD_CD_PARSER_BASENO + 14)  //传入的文件名为空 //The file name is null


/*****************************************************************************************/
/*         DispatchNetQueue:     (117500 ~ 117600)        */
/*****************************************************************************************/
//netqueue
#define EC_HD_CD_NETQUEUE       (EC_RD_BASENO + 7500)
#define EC_HD_CD_NET_UNKNOWN            (EC_HD_CD_NETQUEUE + 1)           //NetQueue：未知类型错误 //NetQueue: unknown error
#define EC_HD_CD_NET_LISTENFAILED			(EC_HD_CD_NETQUEUE + 2)			//NetQueue：CVNDK监听端口失败 //NetQueue: listen to the port failed
#define EC_HD_CD_NET_SENDFAILED				(EC_HD_CD_NETQUEUE + 3)			//NetQueue：发送数据失败 //NetQueue: send data failed
#define EC_HD_CD_NET_RECVFAILED				(EC_HD_CD_NETQUEUE + 4)			//NetQueue：接收数据失败 //NetQueue: receive data failed
#define EC_HD_CD_NET_FINALIZEFAILED			 (EC_HD_CD_NETQUEUE + 5)			//NetQueue：终止CVNDK服务失败 //NetQueue: finalize the server failed
#define EC_HD_CD_NET_QUEUEERROR				(EC_HD_CD_NETQUEUE + 6)			//NetQueue：CVNDK中的Queue相关错误 //NetQueue: queue related errors
#define EC_HD_CD_NET_CONNECTFAILED			(EC_HD_CD_NETQUEUE + 7)			//NetQueue：连接失败 //NetQueue: connect failed
#define EC_HD_CD_NET_GET_PORT_FAILED		       (EC_HD_CD_NETQUEUE + 8)			//NetQueue：获取指定应用的端口失败 //NetQueue: get the specified application port failed
#define EC_HD_CD_NET_RECV_TIMEOUT			       (EC_HD_CD_NETQUEUE + 9)			//NetQueue：接收数据超时 //NetQueue: receive data timeout
#define EC_HD_CD_NET_NOT_INIT				             (EC_HD_CD_NETQUEUE + 10)			//NetQueue：CVNDK尚未初始化 //NetQueue: not initialized
#define EC_HD_CD_NET_INVALID_PARAMETER		         (EC_HD_CD_NETQUEUE + 11)			//NetQueue：无效的参数传递 //NetQueue: invalid parameter
#define EC_HD_CD_NET_MALLOC_FAILED			               (EC_HD_CD_NETQUEUE + 12)			//NetQueue：分配空间失败 //NetQueue: malloc space failed
#define EC_HD_CD_NET_PUTQ_FAILED			                 (EC_HD_CD_NETQUEUE + 13)			//NetQueue：数据发送到全局写Queue失败 //NetQueue: put data to the queue failed
#define EC_HD_CD_NET_LOCAL_QUEUE_NOT_FOUND	  (EC_HD_CD_NETQUEUE + 14)			//NetQueue：本地Queue未查找到 //NetQueue: can not find the local queue
#define EC_HD_CD_NET_CONNECT_NOT_EXIST		         (EC_HD_CD_NETQUEUE + 15)			//NetQueue：与远端Queue的连接不存在 //NetQueue: the connection to the remote queue does not exist
#define EC_HD_CD_NET_ACQUIRE_MUTEX_FAILED	          (EC_HD_CD_NETQUEUE + 16)			//NetQueue：获取全局锁失败 //NetQueue: acquire the global lock failed
#define EC_HD_CD_NET_INITFAILED			(EC_HD_CD_NETQUEUE + 17)			//NetQueue：CVNDK初始化失败 //NetQueue: initialize failed
#define EC_HD_CD_NET_REG_LOCAL_QUE                      (EC_HD_CD_NETQUEUE + 18)  //注册本地Queue失败 //NetQueue: register the local queue failed
#define EC_HD_CD_NET_REG_REMOTE_QUE                   (EC_HD_CD_NETQUEUE + 19)  //注册远程Queue失败 //NetQueue: register the remote queue failed
#define EC_HD_CD_NET_QUEUE_ID_DIFF                          (EC_HD_CD_NETQUEUE + 20)  //远程QueueID与本地ID不匹配 //NetQueue: the remote queue ID dismatches the local queue ID


/************************************************************************/
/*                      ZTPlay (117600 - 117700)                        */
/************************************************************************/
#define EC_HD_CD_ZTPLAY      (EC_RD_BASENO + 7600)
#define EC_HD_CD_ZTPLAY_STARTTIME_INVALID    (EC_HD_CD_ZTPLAY + 1)   //输入开始时间参数不合法 //Invalid start time
#define EC_HD_CD_ZTPLAY_ENDTIME_INVALID      (EC_HD_CD_ZTPLAY + 2)   //输入终止时间参数不合法 //Invalid end time
#define EC_HD_CD_ZTPLAY_PLAYSEG_INVALID      (EC_HD_CD_ZTPLAY + 3)   //输入播放间隔参数不合法 //Invalid playing time interval
#define EC_HD_CD_ZTPLAY_VALUEMODE_INVALID    (EC_HD_CD_ZTPLAY + 4)   //输入插值模式参数不合法，只支持0，1 //Invalid interpolation mode, only 0 or 1 is supported
#define EC_HD_CD_ZTPLAY_BACK_COLOR           (EC_HD_CD_ZTPLAY + 5)   //输入背景颜色参数不合法 //Invalid background color
#define EC_HD_CD_ZTPLAY_TEXT_COLOR           (EC_HD_CD_ZTPLAY + 6)   //输入文本颜色参数不合法 //Invalid font color
#define EC_HD_CD_ZTPLAY_PLAY_PERCENT         (EC_HD_CD_ZTPLAY + 7)   //输入播放点的百分比不合法 //Invalid percent of playing point
#define EC_HD_CD_ZTPLAY_SEPPD_UP_RATE        (EC_HD_CD_ZTPLAY + 8)   //输入的加速速率不合法 //Invalid rate of acceleration

/************************************************************************/
/*                      COM_Interface (117700 - 117800)                        */
/************************************************************************/
#define EC_HD_COM      (EC_RD_BASENO + 7700)
#define EC_HD_COM_SERVER_INVALID    (EC_HD_COM + 1)   //输入服务参数不合法 //Invalid server parameter
#define EC_HD_COM_POINTER_INVALID      (EC_HD_COM + 2)   //输入指针参数不合法 //Invalid pointer
#define EC_HD_COM_SHUZU_SIZE_INVALID      (EC_HD_COM + 3)   //输入数组大小不合法 //Invalid size of array
#define EC_HD_COM__INVALID2    (EC_HD_COM + 4)   //输入插值模式参数不合法，只支持0，1 //Invalid interpolation mode, only 0 or 1 is supported
#define EC_HD_COM__INVALID3          (EC_HD_COM + 5)   //输入背景颜色参数不合法 //Invalid background color
#define EC_HD_COM__INVALID4           (EC_HD_COM + 6)   //输入文本颜色参数不合法 //Invalid font color
#define EC_HD_COM__INVALID5         (EC_HD_COM + 7)   //输入播放点的百分比不合法 //Invalid percent of playing point
#define EC_HD_COM__INVALID6        (EC_HD_COM + 8)   //输入的加速速率不合法 //Invalid rate of acceleration

/************************************************************************/
/*                       HD3  (117800 ~ 119499)                         */         
/************************************************************************/
#define EC_HD3_BASE    (EC_RD_BASENO + 7800)
/* HD3 API */
#define EC_HD3_API_BASE    (EC_HD3_BASE)
#define EC_HD3_OBJECT_EXIST		(EC_HD3_BASE + 1) //新增的对象已存在 //The added object has been existed
// delete #define EC_HD3_API_QUERY_END    (EC_HD3_API_BASE + 2)  // 查询结束  // query end
#define EC_HD3_API_BATCH_REQUEST    (EC_HD3_API_BASE + 3)  // 批量请求失败，即不是所有的请求都成功  // batch requests failed, not every request success
#define EC_HD3_API_NOT_CONNECT    (EC_HD3_API_BASE + 4)  // API未连接  // api not connected
#define EC_HD3_API_EMPTY_SEND_PACK    (EC_HD3_API_BASE + 5)  // 发送包为空  // empty send package
#define EC_HD3_API_EMPTY_RECV_PACK    (EC_HD3_API_BASE + 6)  // 接收包为空  // empty receive package
#define EC_HD3_API_INVALID_RESULTSET_HANDLE    (EC_HD3_API_BASE + 7)  // 无效的结果集句柄  // invalid resultset handle
#define EC_HD3_API_INVALID_TAG_CLASS (EC_HD3_API_BASE + 8)  // 无效的Tag类别  // invalid tag class
#define EC_HD3_API_UNSET_QUERY_PARAM  (EC_HD3_API_BASE + 9)  // 未设置查询参数  // unset query parameter
#define EC_HD3_API_UNSUPPORT_REQUEST    (EC_HD3_API_BASE + 10)  // 不支持的客户端请求  // un-supported request
#define EC_HD3_API_INVALID_COLLECTOR_NAME    (EC_HD3_API_BASE + 11)  // 采集器名非法  // invalid collector name
#define EC_HD3_API_INVALID_COLLECTOR_DESC    (EC_HD3_API_BASE + 12)  // 采集器描述非法  // invalid collector description
#define EC_HD3_API_INVALID_COLLECTOR_EXT_PARAM    (EC_HD3_API_BASE + 13)  // 采集器扩展参数非法  // invalid collector ext param
#define EC_HD3_API_INVALID_DEVICE_NAME    (EC_HD3_API_BASE + 14)  // 设备名非法  // invalid device name
#define EC_HD3_API_INVALID_DEVICE_ADDR    (EC_HD3_API_BASE + 15)  // 设备地址非法  // invalid device addr
#define EC_HD3_API_INVALID_DEVICE_DESC    (EC_HD3_API_BASE + 16)  // 设备描述非法  // invalid device description
#define EC_HD3_API_INVALID_DEVICE_EXT_PARAM    (EC_HD3_API_BASE + 17)  // 设备扩展参数非法  // invalid device ext param
#define EC_HD3_API_INVALID_SCANGROUP_NAME    (EC_HD3_API_BASE + 18)  // 扫描组名非法  // invalid scan group name
#define EC_HD3_API_INVALID_SCANGROUP_DESC    (EC_HD3_API_BASE + 19)  // 扫描组描述非法  // invalid scan group description
#define EC_HD3_API_INVALID_SCANGROUP_EXT_PARAM    (EC_HD3_API_BASE + 20)  // 扫描组扩展参数非法  // invalid scan group ext param
#define EC_HD3_API_INVALID_DATANODE_NAME    (EC_HD3_API_BASE + 21)  // 数据节点名非法  // invalid datanode name
#define EC_HD3_API_INVALID_DATANODE_DESC    (EC_HD3_API_BASE + 22)  // 数据节点描述非法  // invalid datanode description
#define EC_HD3_API_INVALID_DATANODE_ADDR    (EC_HD3_API_BASE + 23)  // 数据节点地址非法  // invalid datanode address
#define EC_HD3_API_INVALID_DATANODE_MACHINE    (EC_HD3_API_BASE + 24)  // 数据节点机器名非法  // invalid datanode machine name
#define EC_HD3_API_BUCKET_TAGID    (EC_HD3_API_BASE + 25)  // 根据数据节点分桶TagID错误  // bucket tagid according to data server error
#define EC_HD3_API_DATANODE_NOT_EXIST    (EC_HD3_API_BASE + 26)  // 数据节点不存在 // datanode not exist
#define EC_HD3_API_SWITCH_CONFIGNODE    (EC_HD3_API_BASE + 27)  // 不允许切换配置节点  // forbidden switch config node
#define EC_HD3_API_INNER_LOGIC_ERROR    (EC_HD3_API_BASE + 28)  // 内部逻辑错误  // inner logic error
#define EC_HD3_API_INVALID_DIGITALSET_STATE_VALUE    (EC_HD3_API_BASE + 29)  // 数字量状态值非法  // invalid digitalset state value
#define EC_HD3_API_INVALID_VERSION_REGION    (EC_HD3_API_BASE + 30)  // 版本号区间错误  // invalid version region
#define EC_HD3_API_INVALID_STRING_RECORD_BUFFER  (EC_HD3_API_BASE + 31)  // 字符串类型的记录未分配缓存  // invalid string-record buffer
#define EC_HD3_API_USR_CHAR_LEN  (EC_HD3_API_BASE + 32)  // 用户分配的字符串长度太小  // user alloc char length is too small
#define EC_HD3_API_USR_ARRAY_SIZE  (EC_HD3_API_BASE + 33)  // 用户分配的数组长度太小 // user alloc array length is too small

#define EC_HD3_CC_BASE						(EC_RD_BASENO + 7900)
#define EC_HD3_CC_DATANODE_EXIST			(EC_HD3_CC_BASE + 1)//数据节点已经存在 //data node already exist	
#define EC_HD3_CC_DATANODE_NOT_EXIST		(EC_HD3_CC_BASE + 2)//数据节点不存在 //data node not exist
#define EC_HD3_CC_DATANODE_MAIN_BACK_IP	(EC_HD3_CC_BASE + 3)//数据节点主备IP相同 //data node host ip is the same as backup ip
#define EC_HD3_CC_DATANODE_LICENSE			(EC_HD3_CC_BASE + 4)//节点License点数不合法 //data node license tag capcity not correct
#define EC_HD3_CC_NAME_NOT_EXIST			(EC_HD3_CC_BASE + 5)//名字不存在 //name not exist
#define EC_HD3_CC_QUERY_ITEM_NOT_EXIST			(EC_HD3_CC_BASE + 6)//查询项不存在 //query item not exist
#define EC_HD3_CC_LOAD_XML				(EC_HD3_CC_BASE + 7)//加载XML失败 //load xml failed
#define EC_HD3_CC_XML_ELEMENT				(EC_HD3_CC_BASE + 8)//加载XML元素失败 //load xml element failed
#define EC_HD3_CC_XML_ATTRIBUTE				(EC_HD3_CC_BASE + 9)//加载XML属性失败 //load xml attribute failed
#define EC_HD3_CC_LOG_CATEGORY			(EC_HD3_CC_BASE + 10)//初始化日志失败 //logc init failed
#define EC_HD3_CC_DEL_TAG_FAILED			(EC_HD3_CC_BASE + 11)//删除点失败 //delete tags failed
#define EC_HD3_CC_QUERY_TAG_FAILED			(EC_HD3_CC_BASE + 12)//查询点失败 //query tags failed
#define EC_HD3_CC_ADD_TAG_FAILED			(EC_HD3_CC_BASE + 13)//添加点失败 //add tags failed
#define EC_HD3_CC_MODIFY_TAG_FAILED			(EC_HD3_CC_BASE + 14)//修改点失败 //modify tags failed
#define EC_HD3_CC_NAME_EXIST				(EC_HD3_CC_BASE + 15)//名字已经存在 //name has exist
#define EC_HD3_CC_ADD_MASK_ALARM_FAILED				(EC_HD3_CC_BASE + 16)//添加报警失败 //add alarm failed
#define EC_HD3_CC_QUERY_MASK_ALARM_FAILED				(EC_HD3_CC_BASE + 17)//查询报警失败 //query alarm failed
#define EC_HD3_CC_DELETE_NODE				(EC_HD3_CC_BASE + 18)//删除节点失败，节点上已经创建过点 //delete node failed, there are tags on this node
#define EC_HD3_CC_DATANODE_NUM_MAX			(EC_HD3_CC_BASE + 19)//数据节点个数达到上限128 //data node num reach 128	
#define EC_HD3_CC_AM_SOURCE_CLASS			(EC_HD3_CC_BASE + 20)//报警点源点不能为报警点 //alarm source tag cannot be alarm tag
#define EC_HD3_CC_DATANODE_TAG_CAPACITY			(EC_HD3_CC_BASE + 21)//节点的Tag点数不合法，最小为1，最大为5000000 //invalid datanode tag capacity must be in [1,5000000]
#define EC_HD3_CC_CALC_EXPR_HAS_STRING_OR_BLOB			(EC_HD3_CC_BASE + 22)//计算表达式包含string或者blob类型的点 // tag which type is string or blob exist in calc expr
#define EC_HD3_CC_NO_RY						(EC_HD3_CC_BASE + 23)//配置中心没有配置冗余//no ry config in configcenter
#define EC_HD3_CC_RY_BACKUP						(EC_HD3_CC_BASE + 24)//配置中心为备机// configcenter is backup machine
#define EC_HD3_CC_RY_UNAVILABLE						(EC_HD3_CC_BASE + 25)//配置中心为不可用// configcenter is unavilable
#define EC_HD3_CC_RY_NOT_BACKUP						(EC_HD3_CC_BASE + 26)//远程配置中心不为备机// remote configcenter is not backup
#define EC_HD3_CC_RY_CFG_MUST_HOST_AND_BACKUP			(EC_HD3_CC_BASE + 27)//冗余的主备服务器必须同时在线// host and backup configcenter must online
#define EC_HD3_CC_DATANODE_NOT_AVAILABLE		(EC_HD3_CC_BASE + 28)//数据节点不可用//data node not available 
/************************************************************************/
/*                       API  (119500 ~ 119999)                         */         
/************************************************************************/
#define EC_HD_API_BASENO						(EC_RD_BASENO + 9500)

/* invalid input parameter */
#define EC_HD_API_INVALID_PARAM_BASENO			(EC_HD_API_BASENO)
#define EC_HD_API_INVALID_POINTER				(EC_HD_API_INVALID_PARAM_BASENO + 1)//接口参数传入为NULL的指针 //Null pointer in interface parameters
#define EC_HD_API_INVALID_SERVERID				(EC_HD_API_INVALID_PARAM_BASENO + 2)//接口参数传入不合法的HDHANDLE //Invalid iHyperDB handle in interface parameters
#define EC_HD_API_INVALID_PORT					(EC_HD_API_INVALID_PARAM_BASENO + 3)//接口参数传入不合法的端口号 //Invalid port in interface parameters
#define EC_HD_API_INVALID_IP					(EC_HD_API_INVALID_PARAM_BASENO + 4)//接口参数传入不合法的IP //Invalid IP in interface parameters
#define EC_HD_API_INVALID_TAG_NAME				(EC_HD_API_INVALID_PARAM_BASENO + 5)//接口参数传入不合法的Tag名 //Invalid tag name in interface parameters
#define EC_HD_API_INVALID_TAG_DESC				(EC_HD_API_INVALID_PARAM_BASENO + 6)//接口参数传入不合法的Tag描述 //Invalid tag description in interface parameters
#define EC_HD_API_INVALID_TAG_TYPE				(EC_HD_API_INVALID_PARAM_BASENO + 7)//接口参数传入不合法的Tag类型 //Invalid tag type in interface parameters
#define EC_HD_API_INVALID_TAG_COMP_TYPE			(EC_HD_API_INVALID_PARAM_BASENO + 8)//接口参数传入不合法的Tag压缩类型 //Invalid tag compression type in interface parameters
#define EC_HD_API_INVALID_TAG_ARCHIVEING		(EC_HD_API_INVALID_PARAM_BASENO + 9)//接口参数传入不合法的Tag是否归档的属性 //Invalid tag property of archivement in interface parameters
#define EC_HD_API_INVALID_TAG_SCAN				(EC_HD_API_INVALID_PARAM_BASENO + 10)//接口参数传入不合法的Tag是否扫描的属性 //Invalid tag property of scanning in interface parameters
#define EC_HD_API_INVALID_TAG_COMP_DEV			(EC_HD_API_INVALID_PARAM_BASENO + 11)//接口参数传入不合法的Tag压缩误差 //Invalid tag compression deviation in interface parameters
#define EC_HD_API_INVALID_TAG_ID				(EC_HD_API_INVALID_PARAM_BASENO + 12)//接口参数传入不合法的TagID //Invalid tag ID in interface parameters
#define EC_HD_API_INVALID_TAG_IS_DELETE			(EC_HD_API_INVALID_PARAM_BASENO + 13)//接口参数传入不合法的Tag是否删除的属性 //Invalid tag property of deletion in interface parameters
#define EC_HD_API_INVALID_TAG_COMP_DEV_PERCENT	(EC_HD_API_INVALID_PARAM_BASENO + 14)//接口参数传入不合法的Tag压缩误差百分比 //Invalid tag compression deviation percent in interface parameters
#define EC_HD_API_INVALID_TAG_EXC_MAX			(EC_HD_API_INVALID_PARAM_BASENO + 15)//接口参数传入不合法的Tag例外测试最大时间 //Invalid maximum time of tag exception test in interface parameters
#define EC_HD_API_INVALID_TAG_EXC_DEV			(EC_HD_API_INVALID_PARAM_BASENO + 16)//接口参数传入不合法的Tag例外测试误差 //Invalid deviation of tag exception testTag in interface parameters
#define EC_HD_API_INVALID_TAG_EXC_MAX_MIN		(EC_HD_API_INVALID_PARAM_BASENO + 17)//接口参数传入不合法的Tag例外测试最大时间小于或等于最小时间 //The maximum time of tag exception test is less than or equals to the minimum time in interface parameters
#define EC_HD_API_INVALID_TAG_SPAN				(EC_HD_API_INVALID_PARAM_BASENO + 18)//接口参数传入不合法的Tag跨度 //Invalid tag span in interface parameters
#define EC_HD_API_INVALID_TAG_COMP_MAX			(EC_HD_API_INVALID_PARAM_BASENO + 19)//接口参数传入不合法的压缩超时 //Invalid compression timeout in interface parameters
#define EC_HD_API_INVALID_TAG_COMP_MIN			(EC_HD_API_INVALID_PARAM_BASENO + 20)//接口参数传入不合法的压缩精度 //Invalid compression precision in interface parameters
#define EC_HD_API_INVALID_TAG_COMP_MAX_MIN		(EC_HD_API_INVALID_PARAM_BASENO + 21)//接口参数传入不合法的Tag压缩超时或压缩精度，如压缩精度大于压缩超时 //Invalid tag compression timeout or compression precision in interface parameters; For example, the compression precision is bigger than the compression timeout
#define EC_HD_API_INVALID_TAG_SCAN_PERIOD		(EC_HD_API_INVALID_PARAM_BASENO + 22)//接口参数传入不合法的扫描周期 //Invalid tag scan period in interface parameters
#define EC_HD_API_INVALID_TAG_CHANGER			(EC_HD_API_INVALID_PARAM_BASENO + 23)//接口参数传入不合法的Tag修改者 //Invalid tag changer in interface parameters
#define EC_HD_API_INVALID_TAG_CREATOR			(EC_HD_API_INVALID_PARAM_BASENO + 24)//接口参数传入不合法的Tag创建者 //Invalid tag creator in interface parameters
#define EC_HD_API_INVALID_TAG_ENG_UINTS			(EC_HD_API_INVALID_PARAM_BASENO + 25)//接口参数传入不合法的Tag工程单位 //Invalid tag engineering unit in interface parameters
#define EC_HD_API_INVALID_TAG_INSTURMENT_POINT  (EC_HD_API_INVALID_PARAM_BASENO + 26)//接口参数传入不合法的Tag设备点名 //Invalid tag instrument point name in interface parameters
#define EC_HD_API_INVALID_TAG_INTERFACE_NAME	(EC_HD_API_INVALID_PARAM_BASENO + 27)//接口参数传入不合法的Tag采集接口名 //Invalid tag acquisition interface name in interface parameters
#define EC_HD_API_INVALID_TAG_REC_GROUP			(EC_HD_API_INVALID_PARAM_BASENO + 28)//接口参数传入不合法的Tag记录权限组 //Invalid tag record authority group in interface parameters
#define EC_HD_API_INVALID_TAG_REC_OWNER			(EC_HD_API_INVALID_PARAM_BASENO + 29)//接口参数传入不合法的Tag记录所有者 //Invalid tag record owner in interface parameters
#define EC_HD_API_INVALID_TAG_TAG_GROUP			(EC_HD_API_INVALID_PARAM_BASENO + 30)//接口参数传入不合法的Tag权限组 //Invalid tag authority group in interface parameters
#define EC_HD_API_INVALID_TAG_OWNER				(EC_HD_API_INVALID_PARAM_BASENO + 31)//接口参数传入不合法的Tag所有者 //Invalid tag owner in interface parameters
#define EC_HD_API_INVALID_RECORD				(EC_HD_API_INVALID_PARAM_BASENO + 40)//接口参数传入不合法的点的记录，如不合法的记录时间，不合法的记录长度，不合法的记录的数据质量，记录值为NULL //Invalid tag record in interface parameters; For example, invalid record time, invalid record length, invalid record quality or the record value is null
#define EC_HD_API_INVALID_RECORD_TIMESTAMP		(EC_HD_API_INVALID_PARAM_BASENO + 41)//接口参数传入不合法的记录时间戳 //Invalid record timestamp in interface parameters
#define EC_HD_API_INVALID_RDTIMESTAMP			(EC_HD_API_INVALID_PARAM_BASENO + 42)//接口参数传入不合法的时间戳 //Invalid timestamp in interface parameters
#define EC_HD_API_INVALID_TIMEOUT				(EC_HD_API_INVALID_PARAM_BASENO + 44)//接口参数传入不合法的超时 //Invalid timeout in interface parameters
#define EC_HD_API_INVALID_RECCOUNT				(EC_HD_API_INVALID_PARAM_BASENO + 45)//接口参数传入不合法的记录数量 //Invalid record count in interface parameters
#define EC_HD_API_INVALID_REC_VALUE_LEN			(EC_HD_API_INVALID_PARAM_BASENO + 47)//接口参数传入不合法的记录值的长度，查询时记录长度不能小于该类型的最大长度，保存记录时必须记录长度必须等于记录的实际长度 //Invalid length of record value in interface parameters; When querying records, the record length can not be less than the maximum length of current type; When saving records, the record length must equal to the record real length
#define EC_HD_API_INVALID_TAGCOUNT				(EC_HD_API_INVALID_PARAM_BASENO + 50)//接口参数传入不合法的点的个数 //Invalid tag count in interface parameters
#define EC_HD_API_INVALID_QUERYITME_ITEMID		(EC_HD_API_INVALID_PARAM_BASENO + 51)//条件查询接口参数传入不合法的查询项的ID //Invalid ID of the query item in conditional query interface parameters
#define EC_HD_API_INVALID_QUERYITME_RELATION	(EC_HD_API_INVALID_PARAM_BASENO + 52)//条件查询接口参数传入不合法的查询关系 //Invalid query relation in conditional query interface parameters
#define EC_HD_API_INVALID_QUERYITME_VALUE_LEN	(EC_HD_API_INVALID_PARAM_BASENO + 53)//条件查询接口参数传入不合法的查询项的值 //Invalid value of the query item in conditional query interface parameters
#define EC_HD_API_INVALID_QUERY_ITEM_COUNT		(EC_HD_API_INVALID_PARAM_BASENO + 54)//条件查询接口参数传入不合法的查询项的个数 //Invalid count of query items in conditional query interface parameters
#define EC_HD_API_INVALID_INTERFACE_NAME		(EC_HD_API_INVALID_PARAM_BASENO + 55)//接口参数传入不合法的采集接口名 //Invalid acquisition interface name in interface parameters
#define EC_HD_API_INVALID_MASK_TAG_NAME			(EC_HD_API_INVALID_PARAM_BASENO + 60)//接口参数传入不合法的掩码，如添加点时掩码不包含点的名字 //Invalid mask in interface parameters; For example, there is tag name in mask when adding tag
#define EC_HD_API_INVALID_MASK_TAG_TYPE			(EC_HD_API_INVALID_PARAM_BASENO + 61)//接口参数传入不合法的掩码，如添加点时掩码不包含点的类型 //Invalid mask in interface parameters; For example, there is tag type in mask when adding tag
#define	EC_HD_API_INVALID_MASK_CHANGE_DATE		(EC_HD_API_INVALID_PARAM_BASENO + 62)//接口参数传入不合法的掩码，如修改点时掩码包含点的修改日期 //Invalid mask in interface parameters; For example, there is modify date in mask when modifying tag
#define	EC_HD_API_INVALID_MASK_CREATION_DATE	(EC_HD_API_INVALID_PARAM_BASENO + 63)//接口参数传入不合法的掩码，如修改点时掩码包含点的创建日期 //Invalid mask in interface parameters; For example, there is create date in mask when modifying tag
#define	EC_HD_API_INVALID_MASK_TAGID			(EC_HD_API_INVALID_PARAM_BASENO + 64)//接口参数传入不合法的掩码，如修改点时掩码包含点的ID //Invalid mask in interface parameters For example, there is tag ID in mask when modifying tag
#define	EC_HD_API_INVALID_MASK_EXC				(EC_HD_API_INVALID_PARAM_BASENO + 65)//接口参数传入不合法的掩码，如添加或修改点时掩码没有同时包含点的报警上下限 //Invalid mask in interface parameters; For example, there are no upper or lower limits of the alarm in mask when adding or modifying tag
#define EC_HD_API_INVALID_MASK_COMP				(EC_HD_API_INVALID_PARAM_BASENO + 66)//接口参数传入不合法的掩码，如添加或修改点时掩码没有同时包含点的压缩超时和压缩精度 //Invalid mask in interface parameters; For example, there are no compression timeout or compression precision in mask when adding or modifying tag
#define EC_HD_API_INVALID_DIGITAL_SET_NAME		(EC_HD_API_INVALID_PARAM_BASENO + 67)//接口参数传入不合法的数字量状态集名称 //Invalid digital set name in interface parameters
#define EC_HD_API_INVALID_DIGITAL_SET_STATE_NAME	(EC_HD_API_INVALID_PARAM_BASENO + 68)//接口参数传入不合法的数字量状态集的状态名称 //Invalid digital set state name in interface parameters
#define EC_HD_API_INVALID_DIGITAL_SET_STATE_COUNT	(EC_HD_API_INVALID_PARAM_BASENO + 69)//接口参数传入不合法的数字量状态集的状态名个数 //Invalid count of digital set state names in interface parameters
#define EC_HD_API_INVALID_DIGITAL_SET_COUNT		(EC_HD_API_INVALID_PARAM_BASENO + 70)//接口参数传入不合法的数字量状态集名称的个数 //Invalid count of digital set names in interface parameters
#define EC_HD_API_INVALID_DIGITAL_SET_FIGURE	(EC_HD_API_INVALID_PARAM_BASENO + 71)//接口参数传入数值型的DigitalSet //Numerical digital set in interface parameters
#define EC_HD_API_INVALID_STARTTIME_ENDTIME		(EC_HD_API_INVALID_PARAM_BASENO + 72)//开始时间大于结束时间 //The start time is greater than the end time
#define EC_HD_API_INVALID_MASK_SOURCE_TAG		(EC_HD_API_INVALID_PARAM_BASENO + 73)//接口参数传入不合法的掩码，添加报警点时掩码必须包含监测点的名字，修改报警点时掩码不能包含监测点的名字 //Invalid mask in interface parameters; There must be detected source tag name in mask when adding alarm tag; There can not be detected source tag name in mask when modifying alarm tag
#define EC_HD_API_INVALID_TAG_PROP_AUTOACK		(EC_HD_API_INVALID_PARAM_BASENO + 74)//接口参数传入不合法的报警自动确认 //Invalid tag property of alarm auto acknowledgement in interface parameters
#define EC_HD_API_INVALID_ALARM_GROUP_NAME_LEN	(EC_HD_API_INVALID_PARAM_BASENO + 75)//接口参数传入不合法的报警组名长度,如名称为空字符串或者长度超过报警组名称的最大长度 //Invalid length of alarm group name in interface parameters; For example, the name is null or the length of name is bigger than the maximum length of alarm group name
#define EC_HD_API_INVALID_ALARM_GROUP_DESC_LEN	(EC_HD_API_INVALID_PARAM_BASENO + 76)//接口参数传入不合法的报警组描述长度 //Invalid length of alarm group description in interface parameters
#define EC_HD_API_INVALID_ALARM_GROUP_ID		(EC_HD_API_INVALID_PARAM_BASENO + 77)//接口参数传入不合法的报警组ID, 如ID为0 //Invalid alarm group ID in interface parameters; For example, the ID is zero
#define EC_HD_API_INVALID_GROUP_NUM				(EC_HD_API_INVALID_PARAM_BASENO + 78)//接口参数传入不合法的报警组个数 //Invalid count of alarm groups in interface parameters
#define EC_HD_API_INVALID_TAG_NUM				(EC_HD_API_INVALID_PARAM_BASENO + 79)//接口参数传入不合法的点数 //Invalid count of tags in interface parameters
#define EC_HD_API_INVALID_TAG_PROP_TEST_ACTION	(EC_HD_API_INVALID_PARAM_BASENO + 80)//添加或者修改报警点时，成对的TEST和ACTION属性必须同时添加或者同时修改，比如TEST1和ACTION1必须同时添加或者修改 //When adding or modifying the alarm tag, the properties of TEST and ACTION in pairs must be added or modified at the same time; For example, TEST1 and ACTION1 must be added or modified at the same time
#define EC_HD_API_INVALID_MONITOR_TYPE			(EC_HD_API_INVALID_PARAM_BASENO + 81)//不合法的监视点的类型 //Invalid type of monitoring tag
#define EC_HD_API_INVALID_TAG_ACCESS			(EC_HD_API_INVALID_PARAM_BASENO + 82)//不合法的点权限 //Invalid tag authority
#define EC_HD_API_INVALID_REC_ACCESS			(EC_HD_API_INVALID_PARAM_BASENO + 83)//不合法的记录权限 //Invalid record authority

#define EC_HD_API_INVALID_SEC_USER_NAME         (EC_HD_API_INVALID_PARAM_BASENO + 85)//接口参数传入不合法的 用户名 参数 //Invalid user name in interface parameters
#define EC_HD_API_INVALID_SEC_USER_DESC         (EC_HD_API_INVALID_PARAM_BASENO + 86)//接口参数传入不合法的 用户描述 参数 //Invalid user description in interface parameters
#define EC_HD_API_INVALID_SEC_PASSWORD          (EC_HD_API_INVALID_PARAM_BASENO + 87)//接口参数传入不合法的 用户密码 参数 //Invalid user password in interface parameters
#define EC_HD_API_INVALID_SEC_GROUP_NAME        (EC_HD_API_INVALID_PARAM_BASENO + 88)//接口参数传入不合法的 组名 参数 //Invalid group name in interface parameters
#define EC_HD_API_INVALID_SEC_GROUP_DESC        (EC_HD_API_INVALID_PARAM_BASENO + 89)//接口参数传入不合法的 组描述 参数 //Invalid group description in interface parameters
#define EC_HD_API_INVALID_SEC_TRUST_NAME        (EC_HD_API_INVALID_PARAM_BASENO + 90)//接口参数传入不合法的 信任名 参数 //Invalid trust name in interface parameters
#define EC_HD_API_INVALID_SEC_TRUST_IP          (EC_HD_API_INVALID_PARAM_BASENO + 91)//接口参数传入不合法的 信任IP 参数 //Invalid trust IP in interface parameters
#define EC_HD_API_INVALID_SEC_START_ID          (EC_HD_API_INVALID_PARAM_BASENO + 92)//接口参数传入不合法的 查询起始ID 参数 //Invalid query start ID in interface parameters
#define EC_HD_API_INVALID_SEC_QUERY_NUMBER      (EC_HD_API_INVALID_PARAM_BASENO + 93)//接口参数传入不合法的 查询数目 参数 //Invalid query number in interface parameters
#define EC_HD_API_INVALID_SEC_USER_POINTER      (EC_HD_API_INVALID_PARAM_BASENO + 94)//接口参数传入不合法的 用户指针 参数 //Invalid user pointer in interface parameters
#define EC_HD_API_INVALID_SEC_GROUP_POINTER     (EC_HD_API_INVALID_PARAM_BASENO + 95)//接口参数传入不合法的 组指针 参数 //Invalid group pointer in interface parameters
#define EC_HD_API_INVALID_SEC_TRUST_POINTER     (EC_HD_API_INVALID_PARAM_BASENO + 96)//接口参数传入不合法的 信任指针 参数 //Invalid trust pointer in interface parameters
#define EC_HD_API_INVALID_SEC_ITEM_TYPE         (EC_HD_API_INVALID_PARAM_BASENO + 97)//接口参数传入不合法的 安全项类型 参数 //Invalid safety item type in interface parameters
#define EC_HD_API_INVALID_SEC_ITEM_POINTER      (EC_HD_API_INVALID_PARAM_BASENO + 98)//接口参数传入不合法的 安全项指针 参数 //Invalid sfety item pointer in interface parameters
#define EC_HD_API_INVALID_SEC_ITEM_SEC          (EC_HD_API_INVALID_PARAM_BASENO + 99)//接口参数传入不合法的 Tag安全权限 参数 //Invalid tag security permissions in interface parameters

#define EC_HD_API_RECV_TAG_COUNT				    (EC_HD_API_INVALID_PARAM_BASENO + 101)//条件查询接收到的Tag数目比预先分配的多 //The count of received tags is more than that of alloted in advance in conditional query
#define EC_HD_API_RECV_END_TAGID				    (EC_HD_API_INVALID_PARAM_BASENO + 102)//条件查询EndTagID小于StartTagID //The end tag ID is smaller than the start tag ID in conditional query
#define EC_HD_API_CONVERT_TIME_TO_SECOND		    (EC_HD_API_INVALID_PARAM_BASENO + 106)//相对时间转换为绝对时间时失败 //Convert relative time to absolute time failed
#define EC_HD_API_MAP							    (EC_HD_API_INVALID_PARAM_BASENO + 107)//无法找到API内部缓存的MAP //The internal cache MAP in API can not be found
#define EC_HD_API_SAVE_SNAPSHOTS_FAILED			    (EC_HD_API_INVALID_PARAM_BASENO + 109)//保存快照失败，即不是所有的都成功 //Save snapshots failed; Not all snapshots were saved successfully
#define EC_HD_API_QUERY_SNAPSHOTS_FAILED		    (EC_HD_API_INVALID_PARAM_BASENO + 110)//查询快照失败，即不是所有的都成功 //Query snapshots failed;Not all snapshots were queried successfully
#define EC_HD_API_QUERY_INTERP_REC_FAILED		    (EC_HD_API_INVALID_PARAM_BASENO + 111)//记录的插值查询失败，即不是所有的都成功 //Interpolation query of records failed; Not all interpolation query successfully
#define EC_HD_API_LEN_RECV						    (EC_HD_API_INVALID_PARAM_BASENO + 113)//API从服务端接收到的数据包长度不正确 //The length of packet that API received from the server is incorrect
#define EC_HD_API_MUTEX_INIT					    (EC_HD_API_INVALID_PARAM_BASENO + 114)//初始化锁失败 //Initialize the lock failed
#define EC_HD_API_DIGITAL_SET_NOT_EXIST			    (EC_HD_API_INVALID_PARAM_BASENO + 115)//数字量状态集在客户端缓存中不存在 //The digital set does not exist in the client cache
#define EC_HD_API_DIGITAL_SET_STATE_COUNT_NOT_ENOUGH	(EC_HD_API_INVALID_PARAM_BASENO + 116)//查询数字量状态集时，必须一次查完，用户分配的空间不够 //All the states of the digital set must be queryed in one time; The space allocated by the user is not enough
#define EC_HD_API_INVALID_PROCCOMM_HANDLE		    (EC_HD_API_INVALID_PARAM_BASENO + 117)//API与Buffer进程间通信的句柄为空 //The handle of the interprocess communication between buffer and API is null
#define EC_HD_API_TIME_OUT						    (EC_HD_API_INVALID_PARAM_BASENO + 118)//在调用API接口的过程中发生了超时，如网络的接受和发送 //There is timeout in the call of the API interfaces, such as network receiving and sending
#define EC_HD_API_DIGITALSET_STATE_TOO_LARGER	    (EC_HD_API_INVALID_PARAM_BASENO + 119)//数值型的DigitalSet状态等于或大于状态个数 //The state of numerical digital set equals or is bigger than the count of states
#define EC_HD_API_CONVERT_SECOND_TO_TIME		    (EC_HD_API_INVALID_PARAM_BASENO + 120)//绝对时间转换为相对时间失败 //Convert the absolute time to relative time failed
#define EC_HD_API_NOT_ENOUGH_SPACE				    (EC_HD_API_INVALID_PARAM_BASENO + 121)//查询时分配的空间不够 //No enough space allocated in query
#define EC_HD_API_RECV_VALUE					    (EC_HD_API_INVALID_PARAM_BASENO + 122)//API接收到的服务端的数据包中的值不正确 //The value in the packet that API received from the server is incorrect
#define EC_HD_API_AM_QUERY_GROUP_NAMES_FAILED	    (EC_HD_API_INVALID_PARAM_BASENO + 123)//查询报警组名称失败，即不是所有的查询都成功 //Query alarm group names failed; Not all queries succeeded
#define EC_HD_API_AM_QUERY_SNAPSHOTS_FAILED		    (EC_HD_API_INVALID_PARAM_BASENO + 124)//查询实时报警记录失败，即不是所有的查询都成功 //Query real time alarm records failed;Not all queries succeeded
#define EC_HD_API_AM_QUERY_TAG_NAMES_FAILED		    (EC_HD_API_INVALID_PARAM_BASENO + 125)//查询多个报警点名称失败，即不是所有的查询都成功	 //Query multiple alarm tag names failed; Not all queries succeeded
#define EC_HD_API_QUERY_END						    (EC_HD_API_INVALID_PARAM_BASENO + 126)//迭代查询结束 //The iterator of query ended
#define EC_HD_API_QUERY_ALARM_GROUP_PROPS_FAILED	(EC_HD_API_INVALID_PARAM_BASENO + 127)//查询多个报警组属性失败，即不是所有的查询都成功 //Query properties of multiple alarm groups failed; Not all queries succeeded
#define EC_HD_API_INVALID_QUERY_TAG_NUM             (EC_HD_API_INVALID_PARAM_BASENO + 128)//翻页条件查询传入不合法的Tag查询个数 //Invalid count of queried tags in page-turn conditional query
#define EC_HD_API_INVALID_BUF_LEN                   (EC_HD_API_INVALID_PARAM_BASENO + 129)//不合法的缓冲区长度 //Invalid length of buffer
#define EC_HD_API_HOST_BACKUP_NOT_EXIST             (EC_HD_API_INVALID_PARAM_BASENO + 130)//缓存文件中主备机信息不存在 //There is no information of the host and backup servers in the cache file
#define EC_HD_API_HOST_BACKUP_ADDR                  (EC_HD_API_INVALID_PARAM_BASENO + 131)//主备地址中没有指定的IP地址 //There are no specified IP addresses in the configuration of the host and backup servers
#define EC_HD_API_CONNECT_FAILED					(EC_HD_API_INVALID_PARAM_BASENO + 132)//网络连接失败 //Connect to the network failed
#define EC_HD_API_INVALID_MASK_STATS_SOURCE_TAG_NAME		(EC_HD_API_INVALID_PARAM_BASENO + 133)//不合法的掩码，掩码没有包含监控点名称 //Invalid mask;There is no monitored source tag name in mask
#define EC_HD_API_INVALID_MASK_STATS_TYPE				(EC_HD_API_INVALID_PARAM_BASENO + 134)//不合法的掩码，掩码没有包含统计类型 //Invalid mask; There is no statistical type in mask
#define EC_HD_API_INVALID_MASK_STATS_SAMPLE_MODE		(EC_HD_API_INVALID_PARAM_BASENO + 135)//不合法的掩码，掩码没有包含统计模式 //Invalid mask; There is no statistical mode in mask
#define EC_HD_API_INVALID_MASK_STATS_COUNT_PARAM1		(EC_HD_API_INVALID_PARAM_BASENO + 136)//不合法的掩码，掩码没有包含CountParam1 //Invalid mask; There is no count parameter 1 in mask
#define EC_HD_API_INVALID_MASK_STATS_COUNT_PARAM2		(EC_HD_API_INVALID_PARAM_BASENO + 137)//不合法的掩码，掩码没有包含CountParam2 //Invalid mask; There is no count parameter 2 in mask
#define EC_HD_API_INVALID_STATS_TYPE					(EC_HD_API_INVALID_PARAM_BASENO + 138)//不合法的统计类型 //Invalid statistical type
#define EC_HD_API_INVALID_STATS_START_DATE				(EC_HD_API_INVALID_PARAM_BASENO + 139)//不合法的统计采样起始日期 //Invalid statistical sampling start date
#define EC_HD_API_INVALID_STATS_SAMPLE_MODE			(EC_HD_API_INVALID_PARAM_BASENO + 140)//不合法的统计采样模式 //Invalid statistical sampling mode
#define EC_HD_API_INVALID_STATS_SAMPLE_INTERVAL		(EC_HD_API_INVALID_PARAM_BASENO + 141)//不合法的统计采样周期(等间隔模式) //Invalid statistical sampling interval(Equal interval mode)
#define EC_HD_API_INVALID_STATS_BEGIN_END_OFFSET			(EC_HD_API_INVALID_PARAM_BASENO + 142)//不合法的统计采样起始时间和结束时间(同时段模式) //Invalid statistical sampling start date and end time (mode of the same time)
#define EC_HD_API_INVALID_STATS_CALC_PERIOD					(EC_HD_API_INVALID_PARAM_BASENO + 143)//不合法的统计计算周期 //Invalid statistical calc cycle
#define EC_HD_API_INVALID_STATS_PERIOD					(EC_HD_API_INVALID_PARAM_BASENO + 144)//不合法的统计周期 //Invalid statistical cycle
#define EC_HD_API_INVALID_STATS_PHASE					(EC_HD_API_INVALID_PARAM_BASENO + 145)//不合法的统计相位 //Invalid statistical phase
#define EC_HD_API_INVALID_STATS_PCT_GOOD				(EC_HD_API_INVALID_PARAM_BASENO + 146)//不合法的统计最小可信度 //Invalid statistical minimum confidence
#define EC_HD_API_INVALID_STATS_COUNT_CHG_VALUES		(EC_HD_API_INVALID_PARAM_BASENO + 147)//计数参数不正确 //Invalid counting parameter of changed values
#define EC_HD_API_GOOD_PERCENT_TOO_LOW				(EC_HD_API_INVALID_PARAM_BASENO + 148)//质量为Good的点少于指定的信任度 //The count of points whose qualities are good are less than the specified confidence
#define EC_HD_API_INVALID_WEIGHT_MODE				(EC_HD_API_INVALID_PARAM_BASENO + 149)//统计接口非法的权重模式 //Invalid weight mode in statistical interface
#define EC_HD_API_INVALID_QUALITY_MODE				(EC_HD_API_INVALID_PARAM_BASENO + 150)//统计接口非法的质量模式 //Invalid quality mode in statistical interface
#define EC_HD_API_INVALID_COUNT_CONDITION_VALUE		(EC_HD_API_INVALID_PARAM_BASENO + 151)//Count统计点，非法的条件值 //Invalid condition value for counting statistical tag
#define EC_HD_API_NO_DATA_IN_TIME_REGION		(EC_HD_API_INVALID_PARAM_BASENO + 152)//指定时间区间内无数据 //There is no data in the specified time interval
#define EC_HD_API_INVALID_STATS_BAD_MODE		(EC_HD_API_INVALID_PARAM_BASENO + 153)//不合法的弃坏点模式 //Invalid mode of discarding bad points
#define EC_HD_API_INVALID_STATS_SAMPLE_MONTH_BEGIN_DAY		(EC_HD_API_INVALID_PARAM_BASENO + 154)//不合法的月统计起始日，起始日范围为1-31 //Invalid start date for monthly statistics; The range of staring date is from 1 to 31
#define EC_HD_API_INVALID_STATS_SAMPLE_MONTH_END_DAY		(EC_HD_API_INVALID_PARAM_BASENO + 155)//不合法的月统计结束日，结束日范围为1-31 //Invalid end date for monthly statistics; The range of end date is from 1 to 31
#define EC_HD_API_INVALID_MASK_STATS_SAMPLE_BEGIN_END_OFFSET (EC_HD_API_INVALID_PARAM_BASENO + 156)//日统计和月统计掩码必须包含日开始时间和日结束时间 //There must be start date and end date in mask for dayly and monthly statistics
#define EC_HD_API_INVALID_MASK_STATS_SAMPLE_START_DATE  (EC_HD_API_INVALID_PARAM_BASENO + 157)//统计掩码必须包含采样起始时间 //There must be sampling start date in statistical mask
#define EC_HD_API_INVALID_MASK_STATS_SAMPLE_INTERVAL	 (EC_HD_API_INVALID_PARAM_BASENO + 158)//掩码必须包含采样间隔 //There must be sampling interval mask
#define EC_HD_API_INVALID_MASK_STATS_SAMPLE_MONTH_BEGIN_END_DAY   (EC_HD_API_INVALID_PARAM_BASENO + 159)	//月统计掩码必须包含月开始天和月结束天 //There must be start date and end date in monthly statistics mask
#define EC_HD_API_INVALID_MASK_CALC_MODE		(EC_HD_API_INVALID_PARAM_BASENO + 160)//不合法的掩码，掩码没有包含计算模式 //Invalid mask; There is no calculation mode in mask
#define EC_HD_API_INVALID_MASK_CALC_PERIOD		(EC_HD_API_INVALID_PARAM_BASENO + 161)//不合法的掩码，掩码没有包含计算周期 //Invalid mask;There is no calculation period in mask
#define EC_HD_API_INVALID_MASK_CALC_EXPR		(EC_HD_API_INVALID_PARAM_BASENO + 162)//不合法的掩码，掩码没有包含计算表达式 //Invalid mask; There is no calculation expression in mask

#define EC_HD_API_INVALID_CALC_MODE			(EC_HD_API_INVALID_PARAM_BASENO + 163)//不合法的计算模式 //Invalid calculation mode
#define EC_HD_API_INVALID_CALC_PERIOD			(EC_HD_API_INVALID_PARAM_BASENO + 164)//不合法的计算周期 //Invalid calculation period
#define EC_HD_API_INVALID_CALC_EXPR			(EC_HD_API_INVALID_PARAM_BASENO + 165)//不合法的计算表达式 //Invalid calculation expression
#define EC_HD_API_INVALID_TAG_IDS				(EC_HD_API_INVALID_PARAM_BASENO + 166)//TagID数组中ID重复 //There are duplicated IDs in the array of tag IDs
#define EC_HD_API_INVALID_COLLECTOR_TYPE		(EC_HD_API_INVALID_PARAM_BASENO + 167)//不合法的采集器类型 //Invalid collector type
#define EC_HD_API_INVALID_REC_INTERP_MODE		(EC_HD_API_INVALID_PARAM_BASENO + 168)//不合法的记录插值模式 //Invalid interpolation mode of records
#define EC_HD_API_INVALID_TAG_PROP_TIME_DEADBAND		(EC_HD_API_INVALID_PARAM_BASENO + 169)//接口参数传入不合法的报警时间死区 //Invalid tag property of alarm time deadband in interface parameters
#define EC_HD_API_INVALID_TAG_PROP_VALUE_DEADBAND	(EC_HD_API_INVALID_PARAM_BASENO + 170)//接口参数传入不合法的报警值死区 //Invalid tag property of alarm value deadband in interface parameters

#define EC_HD_API_INVALID_MASK_CALC_CALCHISTORY		(EC_HD_API_INVALID_PARAM_BASENO + 171)//不合法的掩码，掩码没有包含是否计算历史 //Invalid mask; Whether the historical data should be calculated is not included in mask
#define EC_HD_API_INVALID_MASK_CALC_STARTTIME		(EC_HD_API_INVALID_PARAM_BASENO + 172)//不合法的掩码，掩码没有包含计算开始时间 //Invalid mask; There is no calculation start time in mask
#define EC_HD_API_INVALID_MASK_CALC_HAVEENDTIME		(EC_HD_API_INVALID_PARAM_BASENO + 173)//不合法的掩码，掩码没有包含是否有结束时间 //Invalid mask; Whether there is the end time is not included in mask
#define EC_HD_API_INVALID_MASK_CALC_ENDTIME		(EC_HD_API_INVALID_PARAM_BASENO + 174)//不合法的掩码，掩码没有包含结束时间 //Invalid mask; There is no calculation end time in mask

#define EC_HD_API_INVALID_CALC_CALCHISTORY		(EC_HD_API_INVALID_PARAM_BASENO + 175)//不合法的是否计算历史 //Invalid parameter of whether the historical data should be calculated
#define EC_HD_API_INVALID_CALC_STARTTIME		(EC_HD_API_INVALID_PARAM_BASENO + 176)//不合法的计算开始时间 //Invalid calculation start time
#define EC_HD_API_INVALID_CALC_HAVEENDTIME		(EC_HD_API_INVALID_PARAM_BASENO + 177)//不合法的是否有结束时间 //Invalid parameter of whether there is the end time
#define EC_HD_API_INVALID_CALC_ENDTIME		(EC_HD_API_INVALID_PARAM_BASENO + 178)//不合法的结束时间 //Invalid calculation end time
#define EC_HD_API_INVALID_ADD_TAG_NUM		(EC_HD_API_INVALID_PARAM_BASENO + 179)//新增Tag点个数太多 //The count of newly added tags is too many
#define EC_HD_API_DUPLICATE_STATE_VALUE		(EC_HD_API_INVALID_PARAM_BASENO + 180)//重复的状态值 //Duplicated state value
#define EC_HD_API_DUPLICATE_TAG_NAME		(EC_HD_API_INVALID_PARAM_BASENO + 181)//重复的Tag名称 //Duplicated tag name
#define EC_HD_API_STATE_VALUE_NO_EXIST		(EC_HD_API_INVALID_PARAM_BASENO + 182)//数字量状态集不存在该状态值 //The state value does not exist in the digital set
#define EC_HD_API_CT_INVALID_CT_STATUS_VALUE	(EC_HD_API_INVALID_PARAM_BASENO + 183) //不合法的采集器状态值 //Invalid status value of the collector
#define EC_HD_API_CT_INVALID_DEVICE_STATUS_VALUE	(EC_HD_API_INVALID_PARAM_BASENO + 184) //不合法的设备状态值 //Invalid status value of the device
#define EC_HD_API_CT_QUERY_STATUS_INFO_FAILED		(EC_HD_API_INVALID_PARAM_BASENO + 185) //查询采集器或设备状态信息失败 //Query the status information of the collector or device failed
#define EC_HD_API_PT_ADD_TAGS_FAILED		(EC_HD_API_INVALID_PARAM_BASENO + 186) //不是所有的点都添加成功 //Not all tags were added successfully

#define EC_HD_API_INVALID_MASK_SPC_SOURCE_TAG_NAME	(EC_HD_API_INVALID_PARAM_BASENO + 187)//掩码没有包含源点 //There is no SPC source tag name in mask
#define EC_HD_API_INVALID_MASK_SPC_CTRL_CHART_TYPE	(EC_HD_API_INVALID_PARAM_BASENO + 188)//掩码没有包含控制图类型 //There is no control chart type in mask
#define EC_HD_API_INVALID_MASK_SPC_RULE	(EC_HD_API_INVALID_PARAM_BASENO + 189)//掩码没有包含判异条件 //There is no pattern tests in mask
#define EC_HD_API_INVALID_SPC_CTRL_CHART_TYPE		(EC_HD_API_INVALID_PARAM_BASENO + 190)//不合法的控制图类型 //Invalid control chart type
#define EC_HD_API_INVALID_SPC_TRIGGLE_MODE		(EC_HD_API_INVALID_PARAM_BASENO + 191)//不合法的触发模式 //Invalid trigger mode
#define EC_HD_API_INVALID_SPC_SAMPLE_SIZE		(EC_HD_API_INVALID_PARAM_BASENO + 192)//不合法的采样个数 //Invalid sampling size
#define EC_HD_API_INVALID_SPC_SAMPLE_INTERVAL		(EC_HD_API_INVALID_PARAM_BASENO + 193)//不合法的采样间隔 //Invalid sampling interval
#define EC_HD_API_INVALID_SPC_RULE1_M		(EC_HD_API_INVALID_PARAM_BASENO + 194)//不合法的判异规则1的M值 //Invalid M value of pattern test 1
#define EC_HD_API_INVALID_SPC_RULE2_M		(EC_HD_API_INVALID_PARAM_BASENO + 195)//不合法的判异规则2的M值 //Invalid M value of pattern test 2
#define EC_HD_API_INVALID_SPC_RULE3_M		(EC_HD_API_INVALID_PARAM_BASENO + 196)//不合法的判异规则3的M值 //Invalid M value of pattern test 3
#define EC_HD_API_INVALID_SPC_RULE4_M		(EC_HD_API_INVALID_PARAM_BASENO + 197)//不合法的判异规则4的M值 //Invalid M value of pattern test 4
#define EC_HD_API_INVALID_SPC_RULE5_M		(EC_HD_API_INVALID_PARAM_BASENO + 198)//不合法的判异规则5的M值 //Invalid M value of pattern test 5
#define EC_HD_API_INVALID_SPC_RULE5_N		(EC_HD_API_INVALID_PARAM_BASENO + 199)//不合法的判异规则5的N值 //Invalid N value of pattern test 5
#define EC_HD_API_INVALID_SPC_RULE6_M		(EC_HD_API_INVALID_PARAM_BASENO + 200)//不合法的判异规则6的M值 //Invalid M value of pattern test 6
#define EC_HD_API_INVALID_SPC_RULE6_N		(EC_HD_API_INVALID_PARAM_BASENO + 201)//不合法的判异规则6的N值 //Invalid N value of pattern test 6
#define EC_HD_API_INVALID_SPC_RULE7_M		(EC_HD_API_INVALID_PARAM_BASENO + 202)//不合法的判异规则7的M值 //Invalid M value of pattern test 7
#define EC_HD_API_INVALID_SPC_RULE8_M		(EC_HD_API_INVALID_PARAM_BASENO + 203)//不合法的判异规则8的M值 //Invalid M value of pattern test 8
#define EC_HD_API_INVALID_SPC_DAFAULT_VALUE		(EC_HD_API_INVALID_PARAM_BASENO + 204)//不合法的控制限默认值 //Invalid default values of control limits
#define EC_HD_API_SPC_QUERY_TAG_NAMES_FAILED		(EC_HD_API_INVALID_PARAM_BASENO + 205)//查询多个Tag点名称没有全部成功 //When querying a plurality of tag names, not all succeeded
#define EC_HD_API_SPC_QUERY_SNAPSHOTS_FAILED		(EC_HD_API_INVALID_PARAM_BASENO + 206)//查询实时SPC报警记录失败，即不是所有的查询都成功 //Query real time SPC alarm records failed; Not all queries succeeded
#define EC_HD_API_QUERY_TAG_IDS_FAILED				(EC_HD_API_INVALID_PARAM_BASENO + 207)//查询多个点的TagID失败，即不是所有的查询都成功 //Query a plurality of tag IDs failed; Not all queries succeeded
#define EC_HD_API_INVALID_QUERY_ITEM        (EC_HD_API_INVALID_PARAM_BASENO + 208)//查询条件为空 //The query conditions are empty
#define EC_HD_API_QUERY_TAGS_BAISC_INFO_FAILED				(EC_HD_API_INVALID_PARAM_BASENO + 209)//根据名称查询多个点的Tag基本信息失败，即不是所有的查询都成功 //Query multiple tag basic informations by tag names failed; Not all queries succeeded
#define EC_HD_API_QUERY_TAGS_PROP_FAILED				(EC_HD_API_INVALID_PARAM_BASENO + 210)//根据ID查询多个点的Tag基本属性失败，即不是所有的查询都成功 //Query multiple tag basic properties by tag IDs failed; Not all queries succeeded
#define EC_HD_API_OPC_RELEASE_TAGS_FAILED				(EC_HD_API_INVALID_PARAM_BASENO + 211)//设置OPC发布多个点失败，即不是所有的点设置都成功 //Set multiple tags to be released by OPC failed; Not all settings succeeded 
#define EC_HD_API_OPC_UNRELEASE_TAGS_FAILED				(EC_HD_API_INVALID_PARAM_BASENO + 212)//设置取消OPC发布多个点失败，既不是所有的点取消都成功 //Cancel the OPC release states of multiple tags failed; Not all cancel succeeded 
#define EC_HD_API_OPC_QUERY_TAGS_STATE_FAILED			(EC_HD_API_INVALID_PARAM_BASENO + 213)//根据ID查询多个点的OPC发布状态失败，即不是所有的查询都成功 //Query the OPC release states of multiple tags by IDs failed; Not all queried succeeded
#define EC_HD_API_OPC_SET_TAGS_STATE_FAILED				(EC_HD_API_INVALID_PARAM_BASENO + 214)//设置多个点的OPC发布状态失败，即不是所有的设置都成功 //Set the OPC release states of multiple tags failed; Not all settings succeeded 
#define EC_HD_API_STATS_CALC_INVALID_TIMEREGION_NUM				(EC_HD_API_INVALID_PARAM_BASENO + 215)//无效的统计计算时间区间个数 //Invalid stats calc time region num 
#define EC_HD_API_STATS_CALC_NULL_TIMEREGION_PTR				(EC_HD_API_INVALID_PARAM_BASENO + 216)// 时间区间指针为空指针 //Null time region ptr 
#define EC_HD_API_STATS_INVALID_PERCENT_GOOD_VAL				(EC_HD_API_INVALID_PARAM_BASENO + 217)// 无效的信任度 //Invalud percent good value 
#define EC_HD_API_STATS_INVALID_SAMPLE_TYPE						(EC_HD_API_INVALID_PARAM_BASENO + 218)// 无效的采样类型 //Invalud sample type
#define EC_HD_API_STATS_INVALID_INTER_PERIOD						(EC_HD_API_INVALID_PARAM_BASENO + 219)// 无效的插值间隔 //Invalid interpolate period
#define EC_HD_API_STATS_INVALID_INTER_OFFSET						(EC_HD_API_INVALID_PARAM_BASENO + 220)// 无效的插值偏移 //Invalud interpolate offset
#define EC_HD_API_STATS_CALC_SAMPLE_END							(EC_HD_API_INVALID_PARAM_BASENO + 221)// 统计计算采样结束 //Stats calce sample end
#define EC_HD_API_STATS_CALC_NO_SUPPORT_MULTI_TIMEREGION							(EC_HD_API_INVALID_PARAM_BASENO + 222)// 统计方法不支持多时间区间 //Stats type no support multi time region
#define EC_HD_API_STATS_CALC_PERIOD_OR_OFFSET_GT_TIMEREGION							(EC_HD_API_INVALID_PARAM_BASENO + 223)// 统计间隔或偏移大于时间区间跨度 //Stats period or offset great than timeregion range
#define EC_HD_API_STATS_CALC_INVALID_FIL_FAIL_MODE							(EC_HD_API_INVALID_PARAM_BASENO + 224)// 无效的统计过滤失败处理模式 //Invalid expr filter failed mode
#define EC_HD_API_STATS_CALC_NO_SUPPORT_INTERSECT_TIMEREGION							(EC_HD_API_INVALID_PARAM_BASENO + 225)// 不支持统计时间区间有交集 //No support intersect timeregion
#define EC_HD_API_STATS_STATS_TIME_TYPE                   (EC_HD_API_INVALID_PARAM_BASENO + 226)// 无效的统计时间类型 //Invalid stats time type
#define EC_HD_API_STATS_SAMPLE_INTERVAL_AND_SCAN_PERIOD  (EC_HD_API_INVALID_PARAM_BASENO + 227)// 统计时间的扫描周期必须小于间隔 //Scan Peirod for statistic tag Time must be less than Interval
#define EC_HD_API_STATS_INTERP_PERIOD_AND_INTERP_OFFSET  (EC_HD_API_INVALID_PARAM_BASENO + 228)// 统计点采样偏移量必须小于采样周期 //Sample Offset must be less than Sample Period for statistic tag
#define EC_HD_API_STATS_SAMPLE_MODE_SUPPORT_STATS_TYPE  (EC_HD_API_INVALID_PARAM_BASENO + 229)// 统计类型不在持续计算的支持范围 //Statistics type is not supported by time mode Forever
#define EC_HD_API_STATS_INTERP_PERIOD_AND_SCAN_PERIOD  (EC_HD_API_INVALID_PARAM_BASENO + 230)// 统计点插值周期必须小于扫描周期 // Interp Period must be less than Scan Peirod for statistic tag
#define EC_HD_API_STATS_CONVER_TYPE  (EC_HD_API_INVALID_PARAM_BASENO + 231)// 统计点不合法的转换类型 // Invalid conversion type for statistic tag
#define EC_HD_API_STATS_CONVERSION  (EC_HD_API_INVALID_PARAM_BASENO + 232)// 统计点不合法的转换系数,转换系数不能小于1 // Invalid conversion param for statistic tag
#define EC_HD_API_STATS_INTERP_PERIOD_AND_SAMPLE_INTERVAL  (EC_HD_API_INVALID_PARAM_BASENO + 233)// 统计点插值周期必须小于统计时间间隔 // Interp Period must be less than Scan Peirod for statistic tag
#define EC_HD_API_STATS_FOREVER_BEGIN_TIMESTAMP (EC_HD_API_INVALID_PARAM_BASENO + 234)// 统计点Forver模式不支持配置开始时间戳 // Forever mode not support begin timestamp
#define EC_HD_API_INVALID_SEC_AUTH_ITEM_NAME	    (EC_HD_API_INVALID_PARAM_BASENO + 235)//不合法的授权项名称 //Invalid authority item name
#define EC_HD_API_INVALID_SEC_AUTH_ITEM_DESC	    (EC_HD_API_INVALID_PARAM_BASENO + 236)//不合法的授权项描述 //Invalid authority item desc
#define EC_HD_API_INVALID_SEC_AUTH_TYPE	    (EC_HD_API_INVALID_PARAM_BASENO + 237)//不合法的授权项权限类型 //Invalid authority item auth type
#define EC_HD_API_INVALID_COLLECTOR_ID	    (EC_HD_API_INVALID_PARAM_BASENO + 238)//不合法采集器ID //Invalid collector id
#define EC_HD_API_INVALID_DEVICE_ID	    (EC_HD_API_INVALID_PARAM_BASENO + 239)//不合法的设备ID //Invalid device id
#define EC_HD_API_INVALID_SCAN_GROUP_ID	    (EC_HD_API_INVALID_PARAM_BASENO + 240)//不合法的扫描组ID //Invalid scan group id 
#define EC_HD_API_IP_NOT_EXIST	    (EC_HD_API_INVALID_PARAM_BASENO + 241)//IP不存在 //IP Not Exist 
#define EC_HD_API_RY_NOT_ENABLE				 (EC_HD_API_INVALID_PARAM_BASENO + 242)//没有启动冗余 //Ry Not Enable
#define EC_HD_API_STATS_CALC_PERIOD_BEGIN_TIMESTAMP (EC_HD_API_INVALID_PARAM_BASENO + 243)// 计算周期大于0时统计点等间隔、每天、每月模式不支持配置记录时间戳为起始偏移 // interval, everyday, everymonth mode not support begin timestamp when calcperiod > 0
#define EC_HD_API_INVALID_MASK_STATS_SAMPLE_TYPE		(EC_HD_API_INVALID_PARAM_BASENO + 244)//不合法的掩码，掩码没有包含统计采样类型 //Invalid mask; There is no statistical sample type in mask
#define EC_HD_API_INVALID_MASK_STATS_CALC_PERIOD		(EC_HD_API_INVALID_PARAM_BASENO + 245)//不合法的掩码，掩码没有包含统计计算周期 //Invalid mask; There is no statistical calc period in mask
#define EC_HD_API_CALC_NOTIFY_HIS		(EC_HD_API_INVALID_PARAM_BASENO + 246)//计算点的通知模式不支持历史计算 //Calc mode not support calc history
#define EC_HD_API_DATANODE_PORT		(EC_HD_API_INVALID_PARAM_BASENO + 247)//数据节点端口号不能与配置中心的端口号相同 //DataNode port cannot be equal to configcenter port
#define EC_HD_API_RY_YES		(EC_HD_API_INVALID_PARAM_BASENO + 248)//服务端是冗余配置，请传入正确的2个冗余地址 //ConfigCenter is ry, need two ry addr
#define EC_HD_API_RY_NO		(EC_HD_API_INVALID_PARAM_BASENO + 249)//服务端没有配置冗余，不能传入2个冗余地址 //ConfigCenter is not ry, do not need two ry addr

#define EC_HD_API_INVALID_MASK_SYNC (EC_HD_API_INVALID_PARAM_BASENO + 250)//接口参数传入不合法的掩码，如添加点时掩码不包含云同步点的同步方式 // Invalid mask; For example，there is lack of sync type mask when adding tags
#define EC_HD_API_INVALID_MASK_PERIOD (EC_HD_API_INVALID_PARAM_BASENO + 251)//接口参数传入不合法的掩码，如添加点时掩码不包含云同步点的同步周期// Invalid mask; For example，there is lack of sync period mask when adding tags
#define EC_HD_API_INVALID_MASK_COMP_DEV (EC_HD_API_INVALID_PARAM_BASENO + 251)//接口参数传入不合法的掩码，如添加点时掩码不包含云同步点的压缩率// Invalod mask; For example，there is lack of compression ration mask when adding tags
#define EC_HD_API_INVALID_TAG_CLOUD_SYNC (EC_HD_API_INVALID_PARAM_BASENO + 252)//接口参数传入不合法的同步方式// Invalid sync type in interface parameters
#define EC_HD_API_INVALID_TAG_CLOUD_PERIOD (EC_HD_API_INVALID_PARAM_BASENO + 253)//接口参数传入不合法的同步周期// Invalid sync period in interface parameters
#define EC_HD_API_INVALID_TAG_CLOUD_COMP_DEV (EC_HD_API_INVALID_PARAM_BASENO + 253)//接口参数传入不合法的压缩率// Invalid compression ratio in interface parameters

#define EC_HD_API_UT_GET_CAPACITY_FAILED (EC_HD_API_INVALID_PARAM_BASENO + 254)//查询数据节点资源使用情况失败，即不是所有的查询都成功 // Query data node resource usage failed:Not all queries succeeded
#define EC_HD_API_UT_INVALID_AVEUSAGE_TIME (EC_HD_API_INVALID_PARAM_BASENO + 255)//单个归档文件平均使用时间无效，目前无法计算//The average usage time of a single archive file is invalid and cannot be calculated at present 
#define EC_HD_API_UT_INVALID_CURR_ARCINDEX (EC_HD_API_INVALID_PARAM_BASENO + 256)//当前使用归档文件编号无效，目前无法获取//The currently used archive file index is invalid and cannot be obtained at present 
#endif //ERROR_CODE_H_
