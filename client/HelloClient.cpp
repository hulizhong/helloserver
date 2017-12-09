/*************************************************************************
	> File Name: HelloClient.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 09 Dec 2017 11:36:15 AM HKT
 ************************************************************************/

#include "HelloClient.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <errno.h>
#include <string.h>
#include <iostream>

bool HelloClient::sendReq()
{
    char buff[128] = "hello-Word-!";
    ssize_t res = 0;

    //step 1. ssize_t send(int sockfd, const void *buf, size_t len, int flags);
    res =  send(mSock, buff, strlen(buff), 0);
    if (res == -1)
    {
        std::cout << "send " << strerror(errno) << std::endl;
        return false;
    }
    else
        std::cout << "send " << res << " " << buff << std::endl;

    //step 2. ssize_t send(int sockfd, const void *buf, size_t len, int flags);
    res = recv(mSock, buff, sizeof(buff), 0);
    if (res == 0)
    {
        std::cout << "peer was close." << std::endl;
        return true;
    }
    else if (res == -1)
    {
        std::cout << "recv " << strerror(errno) << std::endl;
        return false;
    }
    else
        std::cout << "recv " << res << " " << buff << std::endl;

    return true;
}

