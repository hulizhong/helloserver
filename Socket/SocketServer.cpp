/*************************************************************************
	> File Name: SocketServer.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 08 Dec 2017 02:46:52 PM HKT
 ************************************************************************/

#include "SocketServer.h"
#include "../util/Log.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <errno.h> //errno
#include <string.h> //strerror(), memset()
#include <unistd.h> //close()
#include <netinet/in.h> //struct sockaddr_in
#include <arpa/inet.h> //inet_addr()


SocketServer::SocketServer(std::string host, unsigned int port)
            : mHost(host), mPort(port)
{
    mSock = -1;
}

bool SocketServer::start()
{
    LOG_INFO("host " << mHost << "  port " << mPort);
    //step 1. int socket(int domain, int type, int protocol);
    mSock = socket(AF_INET, SOCK_STREAM, 0);
    if (mSock == -1)
    {
        LOG_ERROR("socket " << strerror(errno));
        return false;
    }

    //step 2. int bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
    struct sockaddr_in sockAddr;
    memset(&sockAddr, 0, sizeof(sockAddr));
    sockAddr.sin_family = AF_INET;
    sockAddr.sin_port = htons(mPort);
    sockAddr.sin_addr.s_addr = inet_addr(mHost.c_str());
    int res = bind(mSock, (struct sockaddr *)&sockAddr, sizeof(sockAddr));
    if (res == -1)
    {
        LOG_ERROR("bind " << strerror(errno));
        return false;
    }
    
    //step 3. int listen(int sockfd, int backlog);
    res = listen(mSock, 30);
    if (res == -1)
    {
        LOG_ERROR("listen " << strerror(errno));
        return false;
    }

    //step 4. int accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
    struct sockaddr_in cliAddr;
    socklen_t cliAddrLen;
    int cliSock = 0;
    while (true)
    {
        memset(&cliAddr, 0, sizeof(cliAddr));
        cliSock = accept(mSock, (struct sockaddr *)&cliAddr, &cliAddrLen);
        if (cliSock == -1)
        {
            LOG_ERROR("accept " << strerror(errno));
            break;
        }
        processReq(cliSock, &cliAddr);
    }
    
    return true;
}

bool SocketServer::stop()
{
    if (mSock != -1)
        close(mSock);

    return true;
}

bool SocketServer::processReq(int cliSock, struct sockaddr_in *cliAddr)
{
    //need child class to implement it.
    return false;
}

