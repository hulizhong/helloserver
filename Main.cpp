/*************************************************************************
	> File Name: Main.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 08 Dec 2017 02:18:04 PM HKT
 ************************************************************************/

//#include<iostream>
#include "HelloServer.h"
using namespace std;


int main(int argc, char* argv[])
{
    HelloServer hs("172.22.48.101", 8899);
    hs.start();
    return 0;
}

