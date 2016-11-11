#include <iostream>
#include <libxml/xmlmemory.h>
#include <libxml/parser.h>
#include "server.h"
#include "client.h"

int main()
{
    Server * servidor = new Server();
    Client * cliente = new Client();
    //servidor->server();
    //cliente->client();

    return 0;
}