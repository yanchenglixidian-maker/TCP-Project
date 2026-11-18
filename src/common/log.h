#ifndef NET_SERVER_LOG_H
#define NET_SERVER_LOG_H

#include <string>

enum class LogLevel
{
    Debug,
    Info,
    Warning,
    Error
};

void log(LogLevel level,const std::string& msg);
void set_log_level(LogLevel level);

#endif