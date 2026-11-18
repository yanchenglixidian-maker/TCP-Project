#include "log.h"
#include <iostream>
#include <ctime>

static LogLevel g_min_level = LogLevel::Info;

void set_log_level(LogLevel level)
{
    g_min_level = level;
}

static const char* level_to_str(LogLevel lv)
{
    switch(lv)
    {
        case LogLevel::Debug : return "DEBUG";
        case LogLevel::Info : return "INFO";
        case LogLevel::Warning : return "WARNING";
        case LogLevel::Error : return "ERROR";
        default : return "UNKNOWN";
    }
}


void log(LogLevel level,const std::string& msg)
{
    if(level<g_min_level)return;

    //输出时间和信息
    time_t current = std::time(nullptr);//timestamp
    struct tm tm_buf={};//timeadress
    struct tm* ret = localtime_r(&current,&tm_buf);//localtime_r(timestamp,timeadress)

    if(ret==nullptr)
    {
        std::cerr<<"[time error]"<<msg<<'\n';
        return;
    }
    char t[60]={0};
    if(std::strftime(t,sizeof(t),"%Y-%m-%d %H:%M:%S",ret)==0)
    {
        std::cerr<<"[time error]"<<msg<<'\n';
        return;
    }
    if(level<=LogLevel::Info)std::cout<<"["<<t<<"]["<<level_to_str(level)<<"]"<<msg<<'\n';
    else
    {
        std::cerr<<"["<<t<<"]["<<level_to_str(level)<<"]"<<msg<<'\n';
    }
}

