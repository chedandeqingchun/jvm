#include <iostream>
#include <cstdio>
#include <mutex>
#include <string>
#include "log.h"

JLog::JLog() {
    this->initLog();
}

JLog::~JLog() {
    
}

void JLog::basePrint(const char *fmt, va_list args) {
    vfprintf(this->fd, fmt, args);
}



int JLog::initLog() {

    this->fileName = nullptr;
    this->type = LOG_TO_SCREEN; 
    this->level = LOG_ERR;
    this->fd = stdout;
    return 0;
}

void JLog::debug(std::string fileName, std::string funcName, std::string lineNum, const char *fmt, ...) {

    std::string str;
    str += "[DEBUG]";
    str = str + " " + fileName;
    str = str + ":" + funcName;
    str = str + " " + lineNum;
    str = str + " " + " " + fmt;
    str = str + " " + "\n";

    va_list args;
    va_start(args, fmt);
    this->basePrint(str.c_str(), args);
    va_end(args);
}

void JLog::info(std::string fileName, std::string funcName, std::string lineNum, const char *fmt, ...) {

    std::string str;
    str += "[INFO]";
    str = str + " " + fileName;
    str = str + ":" + funcName;
    str = str + " " + lineNum;
    str = str + " " + " " + fmt;
    str = str + " " + "\n";

    va_list args;
    va_start(args, fmt);
    this->basePrint(str.c_str(), args);
    va_end(args);
}

void JLog::warning(std::string fileName, std::string funcName, std::string lineNum, const char *fmt, ...) {

    std::string str;
    str += "[WARN]";
    str = str + " " + fileName;
    str = str + ":" + funcName;
    str = str + " " + lineNum;
    str = str + " " + " " + fmt;
    str = str + " " + "\n";

    va_list args;
    va_start(args, fmt);
    this->basePrint(str.c_str(), args);
    va_end(args);

}

void JLog::error(std::string fileName, std::string funcName, std::string lineNum, const char *fmt, ...) {

    std::string str;
    str += "[ERROR]";
    str = str + " " + fileName;
    str = str + ":" + funcName;
    str = str + " " + lineNum;
    str = str + " " + " " + fmt;
    str = str + " " + "\n";

    va_list args;
    va_start(args, fmt);
    this->basePrint(str.c_str(), args);
    va_end(args);

}

void JLog::fatal(std::string fileName, std::string funcName, std::string lineNum, const char *fmt, ...) {

    std::string str;
    str += "[FATAL]";
    str = str + " " + fileName;
    str = str + ":" + funcName;
    str = str + " " + lineNum;
    str = str + " " + fmt;
    str = str + "\n";

    va_list args;
    va_start(args, fmt);
    this->basePrint(str.c_str(), args);
    va_end(args);
}
