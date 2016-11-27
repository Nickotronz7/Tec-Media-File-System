//
// Created by nickotronz7 on 27/11/16.
//

#include <stdlib.h>
#include <malloc.h>
#include "Striper.h"

Striper::Striper()
{

}

void Striper::setFichDest(string path)
{
    strcpy(nombreDest, path.c_str());
    strcpy(nombreDest1, nombreDest);

    if ((fichDest = fopen(nombreDest, "wb")) == NULL)
    {
        printf("No se ha podido crear el archivo en el set");
    }
}

void Striper::setFichOrg(string path)
{
    strcpy(nombreOrg, path.c_str());

    if ((fichOrg = fopen(nombreOrg, "rb")) == NULL)
    {
        printf("No existe el fichero de origen");
    }
}

void Striper::stripe(int cant)
{

    num_partes = cant;

    fseek(fichOrg, 0, SEEK_END);
    longitud = ftell(fichOrg);
    fseek(fichOrg, 0, SEEK_END);
    if ((fichDest = fopen(nombreDest, "a")) == NULL)
    {
        printf("No se ha podido crear el fichero en el striper1");
        return;
    }

    buffer = (char *) malloc(longitud);
    if (buffer == NULL)
    {
        printf("No se ha podido reservar tanto espacio");
        return;
    }

    for (int i = 0; i < num_partes; ++i)
    {
        sprintf(partes, "00%i_", i);
        strcat(partes, nombreDest1);
        if((fichDest = fopen(partes, "wb")) == NULL)
        {
            printf("No se ha podido crear el fichero destino");
            return;
        }

        fseek(fichOrg, i*longitud/num_partes, SEEK_SET);
        cantidad = fread(buffer, 1, longitud/num_partes, fichOrg);

        fwrite(buffer, 1, cantidad, fichDest);

        if (cantidad != longitud/num_partes)
            printf("Cuidado: no se han leido (ni copiado) todas las partes");
        strcpy(nombreDest1, nombreDest);
    }

    fclose(fichOrg);
    fclose(fichDest);
}