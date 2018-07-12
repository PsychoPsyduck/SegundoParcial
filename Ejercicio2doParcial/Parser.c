#include <stdio.h>
#include <stdlib.h>
#include "Empleado.h"
#include "ArrayList.h"
#include "Parser.h"


int parser_parseEmpleados(char* fileName, ArrayList* listaEmpleados)
{
    int retorno = -1;
    char auxid[128];
    int id;
    char nombre[128];
    char auxhoras[128];
    int horas;
    FILE* fp=fopen(fileName, "r");
    if(fp != NULL)
    {
        printf("Abri el archivo!\n");
        do
        {
            int parts = fscanf(fp,"%[^,],%[^,],%[^\n]",auxid,nombre,auxhoras);
            if(parts==3)
            {
                id=atoi(auxid);
                horas=atoi(auxhoras);
                printf("%d %s %d\n",id,nombre,horas);
                S_Empleado* auxEmpl = empleado_new();//hacer
                empleado_setId(auxEmpl, id);
                empleado_setNombre(auxEmpl, nombre);
                empleado_setHorasTrabajadas(auxEmpl, horas);
                al_add(listaEmpleados, auxEmpl);
                retorno = 1;
            }
        }while(feof(fp)==0);
    }

    return retorno; // OK
}
