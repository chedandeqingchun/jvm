#ifndef _LOG_H
#define _LOG_H
#include <string>
#include <cstdarg>
#include <mutex>

enum LogLevel {
    LOG_DEBUG,
    LOG_INFO,
    LOG_WARN,
    LOG_ERR,
    LOG_FATAL
};

enum LogType {
    LOG_TO_STORAGE,
    LOG_TO_SCREEN,
    LOG_TO_NET
};


class JLog {
private:
    LogType  type; 
    LogLevel level;
    const char *fileName;
    std::mutex lock;

public:
    JLog();
    ~JLog();

    int initLog();
    void basePrint(const char *fmt, ...); 


public:
    void debug(const char *fmt, ...);
    void info(const char *fmt, ...);
    void warning(const char *fmt, ...);
    void error(const char *fmt, ...);
    void fatal(const char *fmt, ...);
    int setLogLevel(LogLevel level);
};

#endif
