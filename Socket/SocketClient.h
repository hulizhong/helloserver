/*************************************************************************
	> File Name: SocketClient.h
	> Author: 
	> Mail: 
	> Created Time: Fri 08 Dec 2017 05:05:41 PM HKT
 ************************************************************************/

#ifndef _SOCKETCLIENT_H
#define _SOCKETCLIENT_H

#include <string>

class SocketClient
{
public:
    SocketClient(std::string host, unsigned int port);

    //start the SocketClient.
    bool start();
    //stop the SocketClient.
    bool stop();

    //send request to SocketServer.
    virtual bool sendReq();

protected:
    std::string mHost;
    unsigned int mPort;
    int mSock;
};

#endif
