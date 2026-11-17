#include "common/log.h"
#include "server/server.h"
#include <unistd.h>
#include <iostream>

int main()
{
    if(create_listen_socket(9000)!=-1)
    {
        log_info("listening on port 9000");
        std::cout<<"press Ctrl+c to exit"<<'\n';
        pause();
    }
    else
    {
        return 1;
    }
    return 0;
}