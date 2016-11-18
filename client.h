//
// Created by nickotronz7 on 10/11/16.
//

#ifndef TEC_MEDIA_FILE_SYSTEM_CLIENT_H
#define TEC_MEDIA_FILE_SYSTEM_CLIENT_H

#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <array>
#include <iostream>
#include <malloc.h>
//#include <iostream>

using namespace std;

class Client
{
public:
    void client();

private:
    int host_port;
    char * host_name;

    struct sockaddr_in my_addr;

    int bytecount;
    int buffer_len=0;

    int hsock;
    int * p_int;
    int err;
};
#endif //TEC_MEDIA_FILE_SYSTEM_CLIENT_H
