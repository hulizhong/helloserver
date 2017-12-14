/*************************************************************************
	> File Name: HelloServer.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 08 Dec 2017 02:46:52 PM HKT
 ************************************************************************/

#include "util/Log.h"
#include "HelloServer.h"
#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <errno.h> //errno
#include <string.h> //strerror(), memset()
//#include <unistd.h> //close()
//#include <netinet/in.h> //struct sockaddr_in
//#include <arpa/inet.h> //inet_addr()


bool HelloServer::processReq(int cliSock, struct sockaddr_in *cliAddr)
{
    processEchoReq(cliSock, cliAddr);
}

bool HelloServer::processEchoReq(int cliSock, struct sockaddr_in *cliAddr)
{
    //step 1. ssize_t recv(int sockfd, void *buf, size_t len, int flags);
    char buff[128] = {0};
    ssize_t res = 0;
    while (true)
    {
        //while (1)
        //    LOG_INFO("peer was close. ---------------" << cliSock);

        res = recv(cliSock, buff, sizeof(buff), 0);
        if (res == 0)
        {
            LOG_INFO("peer was close." << cliSock);
            std::cout << "peer was close." << cliSock << std::endl;
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

