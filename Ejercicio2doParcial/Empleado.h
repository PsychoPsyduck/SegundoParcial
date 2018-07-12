#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED

typedef struct
{
  int id;
  char nombre[128];
  int horasTrabajadas;
  int sueldo;
}S_Empleado;

int empleado_ganaMasDe(void* item);
void empleado_calcularSueldo(void* p);

#endif // EMPLEADO_H_INCLUDED

S_Empleado* empleado_new(void);

int empleado_setId(S_Empleado* this,int id);
int empleado_getId(S_Empleado* this,int* id);

int empleado_setNombre(S_Empleado* this,char* nombre);
int empleado_getNombre(S_Empleado* this,char* nombre);

int empleado_setHorasTrabajadas(S_Empleado* this,int horasTrabajadas);
int empleado_getHorasTrabajadas(S_Empleado* this,int* horasTrabajadas);

int empleado_setSueldo(S_Empleado* this,int sueldo);
int empleado_getSueldo(S_Empleado* this,int* sueldo);
