#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Empleado.h"

int empleado_ganaMasDe(void* item)
{
    int returnAux = -1;
    int sueldo;

    if(item != NULL);
    {
       empleado_getSueldo(item, &sueldo);
       if(sueldo > 25000)
       {
           returnAux = 1;
       }
       else
       {
           returnAux = 0;
       }
    }
    return returnAux;
}

void empleado_calcularSueldo(void* p)
{
    int horasTrabajadas;
    int sueldo;
    int horas=180;
    int horasMas=240;
    int horasMasMas=350;
    if(p != NULL);
    {
       empleado_getHorasTrabajadas(p, &horasTrabajadas);
       if(horasTrabajadas > 0 && horasTrabajadas <= 120)
       {
           sueldo = horasTrabajadas*horas;
       }
       else if(horasTrabajadas > 120 && horasTrabajadas <= 160)
       {
           sueldo=120*horas;
           horasTrabajadas= horasTrabajadas - 120;
           sueldo = sueldo + (horasTrabajadas*horasMas);
       }
       else if(horasTrabajadas > 160)
       {
           sueldo=(120*horas)+(40*horasMas);
           horasTrabajadas= horasTrabajadas - 160;
           sueldo= sueldo + (horasTrabajadas*horasMasMas);
       }
    }
    empleado_setSueldo(p,sueldo);
}

S_Empleado* empleado_new(void)
{
    S_Empleado* returnAux = (S_Empleado*) malloc(sizeof(S_Empleado));
    return returnAux;
}

int empleado_setId(S_Empleado* this,int id)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->id=id;
        retorno=0;
    }
    return retorno;
}

int empleado_getId(S_Empleado* this,int* id)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *id=this->id;
        retorno=0;
    }
    return retorno;
}

int empleado_setNombre(S_Empleado* this,char* nombre)
{
    int retorno=-1;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(this->nombre,nombre);
        retorno=0;
    }
    return retorno;
}

int empleado_getNombre(S_Empleado* this,char* nombre)
{
    int retorno=-1;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(nombre,this->nombre);
        retorno=0;
    }
    return retorno;
}

int empleado_setHorasTrabajadas(S_Empleado* this,int horasTrabajadas)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->horasTrabajadas=horasTrabajadas;
        retorno=0;
    }
    return retorno;
}

int empleado_getHorasTrabajadas(S_Empleado* this,int* horasTrabajadas)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *horasTrabajadas=this->horasTrabajadas;
        retorno=0;
    }
    return retorno;
}

int empleado_setSueldo(S_Empleado* this,int sueldo)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->sueldo=sueldo;
        retorno=0;
    }
    return retorno;
}

int empleado_getSueldo(S_Empleado* this,int* sueldo)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *sueldo=this->sueldo;
        retorno=0;
    }
    return retorno;
}
