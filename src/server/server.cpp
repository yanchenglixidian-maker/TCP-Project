
#include "server.h"
#include "common/log.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <cstring>
#include <unistd.h>
#include <iostream>
#include <cerrno>


int create_listen_socket(int port)
{
    //socekt
    int fd = socket(AF_INET,SOCK_STREAM,0);
    if(fd==-1)
    {
        log(LogLevel::Error,std::string("socket failed: ")+std::strerror(errno));
        return -1;
    }
    
    int opt = 1;
    if(setsockopt(fd,SOL_SOCKET,SO_REUSEADDR,&opt,sizeof(opt))==-1)//避免服务器重启上次连接占用地址导致bind失败
    {
        log(LogLevel::Error,std::string("setsockopt failed: ")+std::strerror(errno));
        close(fd);
        return -1;
    }
    //bind
    struct sockaddr_in address = {};
    address.sin_family = AF_INET;
    address.sin_port = htons(port);
    address.sin_addr.s_addr = INADDR_ANY;

    if(bind(fd,(struct sockaddr*)&address,sizeof(address))==-1)//fail
    {
        log(LogLevel::Error,std::string("bind failed: ")+std::strerror(errno));
        close(fd);
        return -1;
    }

    //listen
    if(listen(fd,SOMAXCONN)==-1)
    {
        log(LogLevel::Error,std::string("listen failed: ")+std::strerror(errno));
        close(fd);
        return -1;
    }
    return fd;
}