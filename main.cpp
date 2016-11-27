/**
 * Path : "/home/nickotronz7/Desktop/prueba.xml"
 */

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <vector>
#include "tinyxml2.h"
#include "client.h"
#include <fstream>
#include <sys/stat.h>
#include "client.h"
#include "server.h"
#include "Striper.h"

using namespace std;
/*
using namespace tinyxml2;

#ifndef XMLCheckResult
#define XMLCheckResult(a_eResult) if (a_eResult != XML_SUCCESS) { printf("Error: %i\n", a_eResult); return a_eResult; }
#endif

void write(FILE * file);
int get_file_size(std::string filename);

int main()
{
    Client * cliente = new Client();
    Server * servidor = new Server();

    string path = "/home/nickotronz7/Desktop/prueba.xml";

    //servidor->server();
    cliente->client();

    XMLDocument xmlDoc;
    XMLNode * pRoot = xmlDoc.NewElement("Root");
    xmlDoc.InsertFirstChild(pRoot);

    XMLElement * pElement = xmlDoc.NewElement("ip");
    pElement->SetText("127.0.0.1");
    pRoot->InsertEndChild(pElement);

    pElement = xmlDoc.NewElement("port");
    pElement->SetText(1101);
    pRoot->InsertEndChild(pElement);

    pElement = xmlDoc.NewElement("path");
    pElement->SetText("/home/nickotronz7/Desktop/Path/");
    pRoot->InsertEndChild(pElement);

    pElement = xmlDoc.NewElement("fPersona");
    pElement->SetAttribute("fName", "Nickolas");
    pElement->SetAttribute("sName", "Javier");
    pElement->SetAttribute("fLastName", "Rodríguez");
    pElement->SetAttribute("sLastName", "Cordero");
    pElement->SetAttribute("edad", 19);
    pRoot->InsertEndChild(pElement);

    pElement = xmlDoc.NewElement("List");
    int veclen = 32;
    vector<int> vecList[veclen];
    for (int i = 0; i < veclen; ++i) {
        vecList[i] = {i};
    }
    //vecList = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    for (int item = 0; item < veclen; item++)
    {
        XMLElement * pListElement = xmlDoc.NewElement("Item");
        pListElement->SetText(item);

        pElement->InsertEndChild(pListElement);
    }
    //int size = vecList.size();
    pElement->SetAttribute("itemCount", veclen);
    pRoot->InsertEndChild(pElement);

    XMLError eResult = xmlDoc.SaveFile("/home/nickotronz7/Desktop/prueba.xml");
    XMLCheckResult(eResult);

    return 0;
}
*/

/* Copiador de ficheros a trozos en C*/

int main()
{
    Striper * s = new Striper();

    s->setFichOrg("foto.JPG");
    s->setFichDest("ca.JPG");
    s->stripe(3);
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

int get_file_size(std::string filename) // path to file
{
    FILE *p_file = NULL;
    p_file = fopen(filename.c_str(),"rb");
    fseek(p_file,0,SEEK_END);
    int size = ftell(p_file);
    fclose(p_file);
    return size;
}