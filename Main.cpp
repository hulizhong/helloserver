/*************************************************************************
	> File Name: Main.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 08 Dec 2017 02:18:04 PM HKT
 ************************************************************************/

//#include<iostream>
#include "SocketServer.h"
using namespace std;


int main(int argc, char* argv[])
{
    SocketServer ss("172.22.48.101", 8899);
    ss.start();
    return 0;
}

