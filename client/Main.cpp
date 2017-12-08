/*************************************************************************
	> File Name: Main.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 08 Dec 2017 03:44:39 PM HKT
 ************************************************************************/

#include "SocketClient.h"
#include <iostream>
#include <pthread.h>
using namespace std;

/**
 * the helloserver test client.
 **/

void* threadFun(void*)
{
    SocketClient sc("172.22.48.101", 8899);
    sc.start();

    for (int i=0; i<100; i++)
        sc.sendEcho();

    sc.stop();
}

int main(int argc, char* argv[])
{
    //int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine) (void *), void *arg);

#define THREAD_NUM 100
    pthread_t thrIdArrary[THREAD_NUM];

    pthread_attr_t thrAttr;
    for (int i=0; i<THREAD_NUM; i++)
    {
        pthread_create(&thrIdArrary[i], NULL, threadFun, NULL);
    }

    for (int i=0; i<THREAD_NUM; i++)
        pthread_join(thrIdArrary[i], NULL);

    return 0;
}

