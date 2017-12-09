/*************************************************************************
	> File Name: PressureServer.h
	> Author: 
	> Mail: 
	> Created Time: Sat 09 Dec 2017 10:02:21 AM HKT
 ************************************************************************/

#ifndef _PRESSURESERVER_H
#define _PRESSURESERVER_H

#include "../Socket/SocketServer.h"

class PressureServer : SocketServer
{
public:
    bool doCommand();

};

#endif
