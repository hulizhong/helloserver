/*************************************************************************
	> File Name: SocketServer.h
	> Author: 
	> Mail: 
	> Created Time: Fri 08 Dec 2017 02:44:29 PM HKT
 ************************************************************************/

#ifndef _SOCKETSERVER_H
#define _SOCKETSERVER_H

#include <string>

class SocketServer
{
public:
    SocketServer(std::string host, unsigned int port);
    bool start();
    bool stop();

protected:
    bool processEchoReq(int cliSock, struct sockaddr_in *cliAddr);

private:
    std::string mHost;
    unsigned int mPort;
    int mSock;
};

#endif
