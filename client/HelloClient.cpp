/*************************************************************************
	> File Name: HelloClient.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 09 Dec 2017 11:36:15 AM HKT
 ************************************************************************/

#include "HelloClient.h"
#include "../util/Log.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <errno.h>
#include <string.h>

bool HelloClient::sendReq()
{
    char buff[128] = "hello-Word-!";
    ssize_t res = 0;

    //step 1. ssize_t send(int sockfd, const void *buf, size_t len, int flags);
    res =  send(mSock, buff, strlen(buff), 0);
    if (res == -1)
    {
        LOG_ERROR("send " << strerror(errno));
        return false;
    }
    else
        LOG_INFO("send " << res << " " << buff);

    //step 2. ssize_t send(int sockfd, const void *buf, size_t len, int flags);
    res = recv(mSock, buff, sizeof(buff), 0);
    if (res == 0)
    {
        LOG_INFO("peer was close.");
        return true;
    }
    else if (res == -1)
    {
        LOG_ERROR("recv " << strerror(errno));
        return false;
    }
    else
        LOG_INFO("recv " << res << " " << buff);

    return true;
}

