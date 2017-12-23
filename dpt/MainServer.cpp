/*************************************************************************
	> File Name: Server.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 09 Dec 2017 09:46:26 AM HKT
 ************************************************************************/

#include "PressureServer.h"
#include "../util/Log.h"
//#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int main(int argc, char* argv[])
{
    Log::initialize("/var/log/dptSer.log");

    FILE *fp = popen("ifconfig | grep 'inet addr:172.22' | awk '{print $2}' | awk -F ':' '{print $2}'", "r");
#define IP_STR_LEN 128
    char ip[IP_STR_LEN] = {0};
    while (true)
    {
        memset(ip, 0, sizeof(ip));
        if (fgets(ip, IP_STR_LEN-1, fp) == NULL)
            break;
        LOG_DEBUG("Will bind the " << ip);
    }
    PressureServer ps(ip, 8899);
    ps.start();
    ps.stop();
    return 0;
}

