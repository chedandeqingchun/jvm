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
    void debug(std::string fileName, std::string funcName, std::string lineNum, const char *fmt, ...);
    void info(std::string fileName, std::string funcName, std::string lineNum, const char *fmt, ...);
    void warning(std::string fileName, std::string funcName, std::string lineNum, const char *fmt, ...);
    void error(std::string fileName, std::string funcName, std::string lineNum, const char *fmt, ...);
    void fatal(std::string fileName, std::string funcName, std::string lineNum, const char *fmt, ...);

    int setLogLevel(LogLevel level);
};

extern JLog log;

#define JDebug(fmt, ...)  log.debug(__FILE__, __func__, std::to_string(__LINE__), ##__VA_ARGS__);
#define JInfo(fmt, ...)  log.info(__FILE__, __func__, std::to_string(__LINE__), ##__VA_ARGS__);
#define JFatal(fmt, ...)  log.fatal(__FILE__, __func__, std::to_string(__LINE__), ##__VA_ARGS__);
#define JWarn(fmt, ...)  log.warning(__FILE__, __func__, std::to_string(__LINE__), ##__VA_ARGS__);
#define JError(fmt, ...)  log.error(__FILE__, __func__, std::to_string(__LINE__), ##__VA_ARGS__);

#endif
