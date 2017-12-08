/*************************************************************************
	> File Name: SocketServer.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 08 Dec 2017 02:46:52 PM HKT
 ************************************************************************/

#include "SocketServer.h"
#include <iostream>
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
    std::cout << mHost << " " << mPort << std::endl;
    //step 1. int socket(int domain, int type, int protocol);
    mSock = socket(AF_INET, SOCK_STREAM, 0);
    if (mSock == -1)
    {
        std::cout << "socket " << strerror(errno) << std::endl;
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
        std::cout << "bind " << strerror(errno) << std::endl;
        return false;
    }
    
    //step 3. int listen(int sockfd, int backlog);
    res = listen(mSock, 30);
    if (res == -1)
    {
        std::cout << "listen " << strerror(errno) << std::endl;
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
            std::cout << "accept " << strerror(errno) << std::endl;
            break;
        }
        processEchoReq(cliSock, &cliAddr);
    }
    
    return true;
}

bool SocketServer::processEchoReq(int cliSock, struct sockaddr_in *cliAddr)
{
    //step 1. ssize_t recv(int sockfd, void *buf, size_t len, int flags);
    char buff[128] = {0};
    ssize_t res = 0;
    while (true)
    {
        res = recv(cliSock, buff, sizeof(buff), 0);
        if (res == 0)
        {
            std::cout << "peer was close." << std::endl;
            break;
            //return true;
        }
        else if (res == -1)
        {
            std::cout << "recv " << strerror(errno) << std::endl;
            break;
            //return false;
        }

        //step 2. ssize_t send(int sockfd, const void *buf, size_t len, int flags);
        res =  send(cliSock, buff, strlen(buff), 0);
        if (res == -1)
        {
            std::cout << "send " << strerror(errno) << std::endl;
            break;
            //return false;
        }
    }

    return true;
}

bool SocketServer::stop()
{
    if (mSock != -1)
        close(mSock);

    return true;
}

