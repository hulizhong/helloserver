/*************************************************************************
	> File Name: Log.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 12 Dec 2017 11:25:10 AM HKT
 ************************************************************************/


#include "Log.h"
#include <log4cxx/xml/domconfigurator.h>
#include <log4cxx/helpers/properties.h>
#include <log4cxx/propertyconfigurator.h>
#include <log4cxx/appender.h>
#include <log4cxx/rollingfileappender.h>
#include <log4cxx/asyncappender.h>
#include <log4cxx/patternlayout.h>
#if defined(TEST_ASYNC_LOG)
    #include <memory>
#endif


//log4cxx::LoggerPtr Log::logger = log4cxx::Logger::getRootLogger();
log4cxx::LoggerPtr Log::logger = log4cxx::Logger::getLogger("rabin");
/*
log4cxx::LoggerPtr logger = log4cxx::Logger::getLogger("rabin");
undefined reference to `Log::logger'
collect2: error: ld returned 1 exit status
make[2]: *** [helloserver] Error 1
make[1]: *** [CMakeFiles/helloserver.dir/all] Error 2
make: *** [all] Error 2
*/

Log::Log()
{
    /*
    //static void configure(helpers::Properties& properties);
    static log4cxx::helpers::Properties prop;
    //virtual void addAppender(const AppenderPtr& newAppender);
    //void removeAllAppenders();
    log4cxx::Appender::;
    virtual void setLayout(const LayoutPtr& layout) = 0;
    //log4cxx::Layout;
    */
}

Log::~Log()
{
    finalize();
}
    
    
bool Log::initialize()
{
    std::string logFilePath = "/var/log/hello.log";
    //[fix], cant "3M", then will only write one word in every log file.
    std::string logFileSize = "30MB";
    std::string logFileNum = "3";
    std::string logPattern = "%d [%t] %-5p %.32c - %m%n";

    //ConsoleAppender
#if 0
    log4cxx::helpers::Properties props;
    props.put("log4j.logger.rabin", "DEBUG, console");
    props.put("log4j.appender.console", "org.apache.log4j.ConsoleAppender");
    props.put("log4j.appender.console.layout", "org.apache.log4j.Patternlayout");
    props.put("log4j.appender.console.layout.ConversionPattern", logPattern);
    log4cxx::PropertyConfigurator::configure(props);
#endif

    //FileAppender
#if 0
    log4cxx::helpers::Properties props;
    /*
    props.put("log4j.rootLogger", "DEBUG, file");
    if not the rootLogger, should named 'log4j.logger.loggerName'
    the value was 'loggerLevel, appender1, appender2 ..'
    */
    props.put("log4j.logger.rabin", "DEBUG, file");
    props.put("log4j.appender.file", "org.apache.log4j.FileAppender");
    props.put("log4j.appender.file.File", logFilePath);
    props.put("log4j.appender.file.Append", "true");
    props.put("log4j.appender.file.layout", "org.apache.log4j.Patternlayout");
    props.put("log4j.appender.file.layout.ConversionPattern", logPattern);
    log4cxx::PropertyConfigurator::configure(props);
#endif

    //RollingFileAppender
#if defined(USE_SYNC_LOG)
    log4cxx::helpers::Properties props;
    props.put("log4j.logger.rabin", "DEBUG, rfile");
    props.put("log4j.appender.rfile", "org.apache.log4j.RollingFileAppender");
    props.put("log4j.appender.rfile.File", logFilePath);
    props.put("log4j.appender.rfile.MaxFileSize", logFileSize);
    props.put("log4j.appender.rfile.MaxBackupIndex", logFileNum);
    //[fix], set false then reopen the log file will truncate to zeor.
    props.put("log4j.appender.rfile.Append", "true");
    props.put("log4j.appender.rfile.layout", "org.apache.log4j.Patternlayout");
    props.put("log4j.appender.rfile.layout.ConversionPattern", logPattern);
    log4cxx::PropertyConfigurator::configure(props);
#endif

    //async file appender.
#if defined(USE_ASYNC_LOG) && 0
    //load with dom file.(xml.xml)
    //[bug], the TEST_ASYNC_LOG not worked.
    log4cxx::xml::DOMConfigurator::configure("./log4j.xml"); 

#elif defined(USE_ASYNC_LOG) && 1
    //configuard by cpp code.
    log4cxx::LayoutPtr rfaLayout = new log4cxx::PatternLayout(logPattern);
    log4cxx::RollingFileAppenderPtr rfa = new log4cxx::RollingFileAppender(rfaLayout, logFilePath);
    rfa->setMaxBackupIndex(3);
    rfa->setMaxFileSize("3MB");
    log4cxx::AsyncAppenderPtr asyncRfa = new log4cxx::AsyncAppender();
    asyncRfa->addAppender(rfa);
    asyncRfa->setBufferSize(0);
    asyncRfa->setBlocking(true);
    logger->addAppender(asyncRfa);
    logger->setLevel(log4cxx::Level::getInfo());

#elif defined(USE_ASYNC_LOG) && 0
    //configuard by Properties.put(), cant work.
    //props.put() only set the <param /> node, cant work for <appender-ref /> node.
    /*
        <appender-ref ref="myFile"/>        
        <param name="BufferSize" value="1000" />     
    */
    log4cxx::helpers::Properties props;
    props.put("log4j.logger.rabin", "DEBUG, rfile, asyncRfile");

    props.put("log4j.appender.rfile", "org.apache.log4j.RollingFileAppender");
    props.put("log4j.appender.rfile.File", logFilePath);
    props.put("log4j.appender.rfile.MaxFileSize", logFileSize);
    props.put("log4j.appender.rfile.MaxBackupIndex", logFileNum);
    props.put("log4j.appender.rfile.Append", "true");
    props.put("log4j.appender.rfile.layout", "org.apache.log4j.Patternlayout");
    props.put("log4j.appender.rfile.layout.ConversionPattern", logPattern);

    props.put("log4j.appender.asyncRfile", "org.apache.log4j.AsyncAppender");
    props.put("log4j.appender.asyncRfile.BufferSize", "10000");
    props.put("log4j.appender.asyncRfile.Blocking", "false");
    props.put("log4j.logger.rabin.appenderRefs.ref", "rfile");

    log4cxx::PropertyConfigurator::configure(props);
#else
    ;
#endif


#if defined(TEST_ASYNC_LOG)
    //async logger will not write the all content into file.
    LOG_INFO("1");
    std::shared_ptr<int> pi;
    LOG_INFO("2");
    *pi = 10;
    LOG_INFO("3");
#endif

    return true;
}

bool Log::finalize()
{
    logger->removeAllAppenders();
    return true;
}

log4cxx::LoggerPtr Log::getLog()
{
    return logger;
}


