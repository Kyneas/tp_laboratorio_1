#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED

#include "LinkedList.h"

typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

int SolicitarDatosEmpleadoYRetornarlos (char mensajeNombre[], char nombre[], int sizeNombre, char mensajeHoras[], char horas[],
										char mensajeSueldo[], char sueldo[], char id[], char mensajeError[]);

int employee_compareByID (void* empA, void* empB);
int employee_compareByName (void* empA, void* empB);
int employee_compareByHoras (void* empA, void* empB);
int employee_compareBySalario (void* empA, void* empB);

int employee_Modify (Employee* this);

int employee_returnIndexByID (LinkedList* pArrayListEmployee, int idBuscado);

int employee_show (Employee* this);

Employee* employee_new();//Constructor por defecto
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr);
void employee_delete();

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);

#endif // employee_H_INCLUDED
