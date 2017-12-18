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

void JLog::basePrint(const char *fmt, ...) {

    va_list args;
    va_start(args, fmt);
    fprintf(stdout, fmt, args);
    va_end(args);

}

int JLog::initLog() {

    this->fileName = nullptr;
    this->type = LOG_TO_SCREEN; 
    this->level = LOG_ERR;
    return 0;
}

void JLog::debug(const char *fmt, ...) {

    std::string str;
    str += "[DEBUG]";
    str = str + " " + __FILE__;
    str = str + " " + __func__;
    str = str + " " + std::to_string(__LINE__);
    str = str + fmt;
    str = str + "\n";

    va_list args;
    va_start(args, fmt);
    this->basePrint(str.c_str(), args);
    va_end(args);

}

void JLog::info(const char *fmt, ...) {

    std::string str;
    str += "[INFO]";
    str = str + " " + __FILE__;
    str = str + " " + __func__;
    str = str + " " + std::to_string(__LINE__);
    str = str + fmt;
    str = str + "\n";

    va_list args;
    va_start(args, fmt);
    this->basePrint(str.c_str(), args);
    va_end(args);

}

void JLog::warning(const char *fmt, ...) {

    std::string str;
    str += "[WARN]";
    str = str + " " + __FILE__;
    str = str + " " + __func__;
    str = str + " " + std::to_string(__LINE__);
    str = str + " " + fmt;
    str = str + "\n";

    va_list args;
    va_start(args, fmt);
    this->basePrint(str.c_str(), args);
    va_end(args);

}

void JLog::error(const char *fmt, ...) {

    std::string str;
    str += "[ERROR]";
    str = str + " " + __FILE__;
    str = str + " " + __func__;
    str = str + " " + std::to_string(__LINE__);
    str = str + " " + fmt;
    str = str + "\n";
    
    va_list args;
    va_start(args, fmt);
    this->basePrint(str.c_str(), args);
    va_end(args);

}

void JLog::fatal(const char *fmt, ...) {

    std::string str;
    str += "[FATAL]";
    str = str + " " + __FILE__;
    str = str + " " + __func__;
    str = str + " " + std::to_string(__LINE__);
    str = str + " " + fmt;
    str = str + "\n";

    va_list args;
    va_start(args, fmt);
    this->basePrint(str.c_str(), args);
    va_end(args);

}
