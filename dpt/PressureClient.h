/*************************************************************************
	> File Name: PressureClient.h
	> Author: 
	> Mail: 
	> Created Time: Sat 09 Dec 2017 10:46:06 AM HKT
 ************************************************************************/

#ifndef _PRESSURECLIENT_H
#define _PRESSURECLIENT_H

#include "../Socket/SocketClient.h"

enum CommandType {
    START_PRESS = 0,
    SUSPEND_PRESS,
    STOP_PRESS
};

class PressureClient : public SocketClient
{
public:
    PressureClient(std::string host, unsigned int port) : SocketClient(host, port) {}

    virtual bool sendReq();

public:
    bool sendCommand(CommandType type);

private:
    //send the PressureServer the command 'start pressure'.
    bool startPress();
    //send the PressureServer the command 'suspend pressure'.
    bool suspendPress();
    //send the PressureServer the command 'stop pressure'.
    bool stopPress();
};

#endif
