/*************************************************************************
	> File Name: HelloClient.h
	> Author: 
	> Mail: 
	> Created Time: Sat 09 Dec 2017 11:35:22 AM HKT
 ************************************************************************/

#ifndef _HELLOCLIENT_H
#define _HELLOCLIENT_H

#include "../Socket/SocketClient.h"

class HelloClient : public SocketClient
{
public:
    HelloClient(std::string host, unsigned int port) : SocketClient(host, port) {}

    virtual bool sendReq();
};

#endif
