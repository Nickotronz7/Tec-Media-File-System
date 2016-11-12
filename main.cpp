/**
 * Path : "/home/nickotronz7/ClionProjects/Tec-Media-File-System/"
 */

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>

using namespace std;

void write(FILE * file);

int main()
{
    FILE * pFile;
    pFile = fopen ("/home/nickotronz7/ClionProjects/Tec-Media-File-System/prueba.txt" , "a+");

    write(pFile);

    fclose(pFile);

    return 0;
}

void write(FILE * file)
{
    char mystring [100];
    printf("Para terminar de introducir texto introdusca unicamente '*' \n");
    while(1)
    {
        printf("Ingrese la linea de texto, (tab equivale a 3 espacios)\n");
        if (fgets(mystring, 100, stdin) != NULL)
        {
            if(mystring[0] == '*')
            {
                break;
            } else {
                fputs(mystring, file);
            }
        }
    }
    fputs("\n", file);
}