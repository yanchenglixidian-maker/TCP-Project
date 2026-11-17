#include "log.h"
#include <iostream>
#include <ctime>

void log_info(const std::string& msg)
{
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
    std::cout<<"["<<t<<"]"<<msg<<'\n';
}