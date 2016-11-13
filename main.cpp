/**
 * Path : "/home/nickotronz7/Desktop/prueba.txt"
 */

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <vector>
#include "tinyxml2.h"

using namespace tinyxml2;
using namespace std;

#ifndef XMLCheckResult
#define XMLCheckResult(a_eResult) if (a_eResult != XML_SUCCESS) { printf("Error: %i\n", a_eResult); return a_eResult; }
#endif

void write(FILE * file);

int main()
{
    FILE * file;
    file = fopen ("/home/nickotronz7/Desktop/kokkachi.xml", "a+");
    //write(pFile);

    int myints[] = {20, 40, 7, 12};
    vector<int> vec (myints, myints + sizeof(myints)/sizeof(int));

    XMLDocument xmlDoc;
    xmlDoc.LoadFile(file);
    XMLNode * pRoot = xmlDoc.NewElement("Root");
    xmlDoc.InsertFirstChild(pRoot);
    XMLElement * pElement = xmlDoc.NewElement("IntValue");

    pElement->SetText(10);
    pRoot->InsertEndChild(pElement);

    pElement = xmlDoc.NewElement("FloatValue");
    pElement->SetText(0.5f);
    pRoot->InsertEndChild(pElement);

    pElement = xmlDoc.NewElement("Date");
    pElement->SetAttribute("day", 5);
    pElement->SetAttribute("month", "Febrero");
    pElement->SetAttribute("year", 1997);
    pElement->SetAttribute("dateFormat", "5/02/1997");
    pRoot->InsertEndChild(pElement);

    pElement = xmlDoc.NewElement("List");
    for (const auto & item : vec)
    {
        XMLElement * pListElement = xmlDoc.NewElement("Item");
        pListElement->SetText(item);

        pElement->InsertEndChild(pListElement);
    }
    pElement->SetAttribute("itemCount", 4);
    pRoot->InsertEndChild(pElement);

    XMLError eResult = xmlDoc.SaveFile(file, true);
    XMLCheckResult(eResult);

    fclose(file);
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