//
// Created by nickotronz7 on 27/11/16.
//

#ifndef TEC_MEDIA_FILE_SYSTEM_STRIPER_H
#define TEC_MEDIA_FILE_SYSTEM_STRIPER_H


#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <string>

using namespace std;

class Striper
{
public:
    Striper();
    void stripe(int cant);
    void setFichOrg(string path);
    void setFichDest(string path);

private:

    FILE * fichOrg, * fichDest;

    char * buffer;
    char nombreOrg[80], nombreDest[80], nombreDest1[80], partes[80];
    long longitud;
    long cantidad;
    int num_partes;
};


#endif //TEC_MEDIA_FILE_SYSTEM_STRIPER_H
