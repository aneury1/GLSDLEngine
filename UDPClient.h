#pragma once

#ifdef __WIN32__
#include <winsock2.h>
#include <windows.h>

struct socket_init{
   socket_init(){
       WSAData wdas;
       WSAStartup(MAKEWORD(2,2), &wdas);
   }
}object_t;


#else
typedef int SOCKET;
#include <sys/socket.h>
#endif


struct UDPClient
{
   


};