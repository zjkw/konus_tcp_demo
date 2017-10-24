#pragma once

#include <stdint.h>
#include <string>

#include <sys/types.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

#ifdef WIN32
#include <winsock2.h>
#else
typedef int SOCKET;
#endif

#define INVALID_SOCKET			(-1)

#define DEFAULT_READ_BUFSIZE	(100 * 1024)
#define DEFAULT_WRITE_BUFSIZE	(100 * 1024)

//除非特别说明，内部不会主动close/shutdown
enum CHANNEL_ERROR_CODE
{
	CEC_NONE = 0,
	CEC_CLOSE_BY_PEER = -1,	//对端关闭
	CEC_RECVBUF_SHORT = -2,	//接收缓存区不够
	CEC_SENDBUF_FULL = -3,	//发送缓存区满了
	CEC_RECVBUF_FULL = -4,	//接收缓存区满了
	CEC_SPLIT_FAILED = -5,	//接收缓存区解析包失败
	CEC_WRITE_FAILED = -6,	//写异常
	CEC_READ_FAILED = -7,	//读异常
	CEC_INVALID_SOCKET = -8,//无效socket
};

enum CLOSE_MODE_STRATEGY
{
	CMS_MANUAL_CONTROL = 0,	//外部用户手工控制
	CMS_INNER_AUTO_CLOSE = 1,//内部自动关闭
};
