#include <ios>
#include "client.h"
#include <fstream>


using namespace std;

void Client::client()
{

    ifstream infile ("/home/nickotronz7/Desktop/prueba.xml" ,ifstream::binary);

    // get size of file
    infile.seekg (0,infile.end);
    long size = infile.tellg();
    infile.seekg (0);

    // allocate memory for file content
    char * buffer = new char[buffer_len];
    memset(buffer, ' ', buffer_len);

    // read content of infile
    infile.read (buffer,size);

    host_port = 1101;
    host_name = "127.0.0.1";

    hsock = socket(AF_INET, SOCK_STREAM, 0);
    if(hsock == -1){
        printf("Error initializing socket %d\n",errno);
         
    }

    p_int = (int*)malloc(sizeof(int));
    *p_int = 1;

    if( (setsockopt(hsock, SOL_SOCKET, SO_REUSEADDR, (char*)p_int, sizeof(int)) == -1 )||
        (setsockopt(hsock, SOL_SOCKET, SO_KEEPALIVE, (char*)p_int, sizeof(int)) == -1 ) )
    {
        printf("Error setting options %d\n",errno);
        free(p_int);
    }
    free(p_int);

    my_addr.sin_family = AF_INET ;
    my_addr.sin_port = htons(host_port);

    memset(&(my_addr.sin_zero), 0, 8);
    my_addr.sin_addr.s_addr = inet_addr(host_name);

    if( connect( hsock, (struct sockaddr*)&my_addr, sizeof(my_addr)) == -1 ){
        if((err = errno) != EINPROGRESS){
            fprintf(stderr, "Error connecting socket", errno);
             
        }
    }

    //Now lets do the client related stuff
    // printf(sizeof(&buffer));

    if( (bytecount=send(hsock, buffer, strlen(buffer),0))== -1){
        fprintf(stderr, "Error sending data %d\n", errno);
         
    }
    printf("Sent bytes %d\n", bytecount);

    if((bytecount = recv(hsock, buffer, size, 0))== -1){
        fprintf(stderr, "Error receiving data %d\n", errno);
         
    }

    printf("Recieved bytes %d\nReceived string \"%s\"\n", bytecount, buffer);

    close(hsock);
}