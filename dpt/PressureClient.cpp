/*************************************************************************
	> File Name: PressureClient.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 09 Dec 2017 10:47:13 AM HKT
 ************************************************************************/

#include "PressureClient.h"

bool PressureClient::sendReq()
{
    //nothing.
    return true;
}

bool  PressureClient::sendCommand(CommandType type)
{
    switch (type)
    {
    case START_PRESS:
        startPress();
    case SUSPEND_PRESS:
        suspendPress();
    case STOP_PRESS:
        stopPress();
    }

    return true;
}

bool PressureClient::startPress()
{
    return false;
}

bool PressureClient::suspendPress()
{
    return false;
}

bool PressureClient::stopPress()
{
    return false;
}

