#ifndef _CROSS_PLANTFORM_NET_H_
#define _CROSS_PLANTFORM_NET_H_
#undef OS_PLANTFORM
#ifdef WINDOWS_OS
#include <WinSock2.h>
#include <winsock.h>
#include <ws2tcpip.h>
#pragma comment(lib, "WS2_32.lib")
#define OS_PLANTFORM 1
#endif

#ifdef LINUX_OS
#include <netdb.h>
#include <sys/socket.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <WinSock2.h>
#define OS_PLANTFORM 2
#endif

#ifndef OS_PLANTFORM
#error should define WINDOWS_OS or LINUX_OS
#endif // !OS_PLANTFORM

#endif //_CROSS_PLANTFORM_NET_H_