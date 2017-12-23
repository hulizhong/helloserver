/*************************************************************************
	> File Name: Client.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 09 Dec 2017 09:46:26 AM HKT
 ************************************************************************/

#include "PressureClient.h"
#include "../util/Log.h"
using namespace std;


int main(int argc, char* argv[])
{
    Log::initialize("/var/log/dptCli.log");
    if (argc != 2)
    {
        LOG_ERROR("need server ip. ");
        return -1;
    }
    LOG_DEBUG("will connect the server " << argv[1]);

    PressureClient pc(argv[1], 8899);
    pc.start();
    pc.sendCommand(START_PRESS);
    //pc.sendCommand(SUSPEND_PRESS);
    //pc.sendCommand(STOP_PRESS);
    pc.stop();
    return 0;
}

