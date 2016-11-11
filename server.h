//
// Created by nickotronz7 on 10/11/16.
//

#ifndef TEC_MEDIA_FILE_SYSTEM_SERVER_H
#define TEC_MEDIA_FILE_SYSTEM_SERVER_H

#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <iostream>
#include <malloc.h>

class Server
{
public:
    void server();
    int getHost_port() const;
    void setHost_port(int host_port);

private:
    int host_port;

    struct sockaddr_in my_addr;

    int hsock;
    int * p_int ;
    int err;

    socklen_t addr_size = 0;
    int* csock;
};

#endif //TEC_MEDIA_FILE_SYSTEM_SERVER_H
