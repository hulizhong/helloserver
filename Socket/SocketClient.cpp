/*************************************************************************
	> File Name: SocketClient.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 08 Dec 2017 05:07:22 PM HKT
 ************************************************************************/

#include "SocketClient.h"

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

#include <iostream>


SocketClient::SocketClient(std::string host, unsigned int port) : mHost(host), mPort(port)
{
    mSock = -1;
}


bool SocketClient::start()
{
    //step 1. int socket(int domain, int type, int protocol);
    mSock = socket(AF_INET, SOCK_STREAM, 0);
    if (mSock == -1)
    {
        std::cout << "socket " << strerror(errno) << std::endl;
        return false;
    }

    //step 2. int connect(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
    struct sockaddr_in sockAddr;
    memset(&sockAddr, 0, sizeof(sockAddr));
    sockAddr.sin_family = AF_INET;
    sockAddr.sin_port = htons(mPort);
    sockAddr.sin_addr.s_addr = inet_addr(mHost.c_str());
    int res = connect(mSock, (struct sockaddr *)&sockAddr, sizeof(sockAddr));
    if (res == -1)
    {
        std::cout << "connect " << strerror(errno) << std::endl;
        return false;
    }

    return true;
}

bool SocketClient::stop()
{
    if (mSock != -1)
        close(mSock);

    return true;
}

bool SocketClient::sendReq()
{
    //need child class to implement it.
    return false;
}

