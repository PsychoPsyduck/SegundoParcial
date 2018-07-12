#include <stdio.h>
#include <stdlib.h>
#include "Empleado.h"
#include "ArrayList.h"
#include "Parser.h"

/**
    Realizar un programa que lee de un archivo los datos de empleados y los guarda en un arraylist de entidades
    empleado.
    Luego, debera calcular el campo "sueldo" de cada uno de los empleados leidos, segun la horas que trabajaron, con el
    siguiente criterio:
    Los valores de horas varian entre 80 y 240.
    - Las primeras 120 horas la hora vale $180
    - De 120 a 160 horas, la hora vale $240
    - De 160 a 240 horas, la hora vale $350

    Utilizar la funcion "map" desarrollada durante la cursada para realizar este calculo.

    Luego, debera filtrar los empleados leidos, segun el sueldo que poseen, y generar una lista nueva en donde solo se encuentren
    los que cobran mas de $25000.

    Para hacer esta operacion, se debera utilizar la funcion "filter" en la biblioteca ArrayList.

    Una vez generada la nueva lista filtrada, se debera generar un archivo de salida "datosCalculados.csv" igual que el original pero con una columna mas al final, en donde se indicara el sueldo calculado.
*/

int generarArchivoFiltrado(char* fileName,ArrayList* listaEmpleados);

int main()
{
    // Definir lista de empleados
    ArrayList* listaEmpleados;

    // Crear lista empledos
    listaEmpleados = al_newArrayList();


    ArrayList* nuevaListaEmpleados;

    // Leer empleados de archivo data.csv
    if(parser_parseEmpleados("data.csv",listaEmpleados)==1)
    {
        // Hacer MAP
        printf("Calculando sueldos de empleados\n");
        al_map(listaEmpleados,empleado_calcularSueldo);

        // Hacer FILTER
        printf("Filtrando empleados\n");
        nuevaListaEmpleados = al_filter(listaEmpleados,empleado_ganaMasDe);

        // Generar archivo de salida
        if(generarArchivoFiltrado("sueldos.csv",nuevaListaEmpleados)==1)
        {
            printf("Archivo generado correctamente\n");
        }
        else
            printf("Error generando archivo\n");
    }
    else
        printf("Error leyendo empleados\n");


    return 0;
}

int generarArchivoFiltrado(char* fileName,ArrayList* listaEmpleados)
{
    int i;
    int returnAux=-1;
    int id;
    char nombre[250];
    int horas;
    int sueldo;
    FILE* pFile=fopen(fileName,"w");
    void* pCliente=NULL;
    if(pFile!=NULL)
    {
		fprintf(pFile,"Id,Nombre,Horas\n");
        for(i=0;i<al_len(listaEmpleados);i++)
        {
            pCliente=al_get(listaEmpleados,i);
            empleado_getId(pCliente, &id);
            empleado_getNombre(pCliente, nombre);
            empleado_getHorasTrabajadas(pCliente, &horas);
            empleado_getSueldo(pCliente, &sueldo);
            fprintf(pFile, "%d,%s,%d,%d\n",id,nombre,horas,sueldo);
            returnAux=1;
        }
    }
    fclose(pFile);
    return returnAux;
}
