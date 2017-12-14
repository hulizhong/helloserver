/*************************************************************************
	> File Name: Server.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 09 Dec 2017 09:46:26 AM HKT
 ************************************************************************/

#include "PressureServer.h"
using namespace std;

int main(int argc, char* argv[])
{
    PressureServer ps("127.0.0.1", 8899);
    ps.start();
    ps.stop();
    return 0;
}

