/*************************************************************************
	> File Name: Client.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 09 Dec 2017 09:46:26 AM HKT
 ************************************************************************/

#include "PressureClient.h"
using namespace std;


int main(int argc, char* argv[])
{
    PressureClient pc("127.0.0.1", 8899);
    pc.start();
    pc.sendCommand(START_PRESS);
    //pc.sendCommand(SUSPEND_PRESS);
    //pc.sendCommand(STOP_PRESS);
    pc.stop();
    return 0;
}

