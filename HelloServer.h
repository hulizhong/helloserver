/*************************************************************************
	> File Name: HelloServer.h
	> Author: 
	> Mail: 
	> Created Time: Fri 08 Dec 2017 02:44:29 PM HKT
 ************************************************************************/

#ifndef _HELLOSERVER_H
#define _HELLOSERVER_H

#include "Socket/SocketServer.h"

class HelloServer : public SocketServer
{
public:
    HelloServer(std::string host, unsigned int port) : SocketServer(host, port) {}
    
protected:
    bool processReq(int cliSock, struct sockaddr_in *cliAddr);

private:
    bool processEchoReq(int cliSock, struct sockaddr_in *cliAddr);
};

#endif
