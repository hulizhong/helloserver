/*************************************************************************
	> File Name: Log.h
	> Author: 
	> Mail: 
	> Created Time: Tue 12 Dec 2017 10:45:04 AM HKT
 ************************************************************************/

#ifndef _LOG_H
#define _LOG_H

//#include <log4cxx/log4cxx.h>
#include <log4cxx/logger.h>

//class __attribute__((visibility("default"))) Log{
class Log
{
private:
    static log4cxx::LoggerPtr logger;
    static bool finalize();
    Log();
    
public:
    ~Log();
    static bool initialize();
    static log4cxx::LoggerPtr getLog();
};


#define LOG_DEBUG(message)  LOG4CXX_DEBUG(Log::getLog(), message)
#define LOG_INFO(message)   LOG4CXX_INFO(Log::getLog(), message)
#define LOG_WARN(message)   LOG4CXX_WARN(Log::getLog(), message)
#define LOG_ERROR(message)  LOG4CXX_ERROR(Log::getLog(), message)
#define LOG_FATAL(message)  LOG4CXX_FATAL(Log::getLog(), message)

#endif
