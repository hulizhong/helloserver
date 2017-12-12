/*************************************************************************
	> File Name: PressureServer.h
	> Author: 
	> Mail: 
	> Created Time: Sat 09 Dec 2017 10:02:21 AM HKT
 ************************************************************************/

#ifndef _PRESSURESERVER_H
#define _PRESSURESERVER_H

#include "../Socket/SocketServer.h"

class PressureServer : public SocketServer
{
public:
    PressureServer(std::string host, unsigned int port) : SocketServer(host, port) {}

    bool doCommand();

protected:
    virtual bool processReq(int cliSock, struct sockaddr_in *cliAddr);
};

#endif
