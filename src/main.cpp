#include "common/log.h"
#include "server/server.h"
#include <unistd.h>
#include <iostream>


int main()
{
    set_log_level(LogLevel::Warning);
    log(LogLevel::Debug,"will not print");
    log(LogLevel::Info,"will not print");
    log(LogLevel::Warning,"will print");
    log(LogLevel::Error,"will print");
    set_log_level(LogLevel::Info);
    if(create_listen_socket(9000)!=-1)
    {
        log(LogLevel::Info,"listening on port 9000");
        std::cout<<"press Ctrl+c to exit"<<'\n';
        pause();
    }
    else
    {
        return 1;
    }
    return 0;
}