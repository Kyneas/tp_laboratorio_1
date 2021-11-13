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

/// @fn void BorrarEmpleadosYBorrarLinkedList(LinkedList*)
/// @brief Borra la linkedlist y libera el espacion en memoria de todos los empleados
///
/// @param pArrayListEmployee Linkedist a borrar
void BorrarEmpleadosYBorrarLinkedList (LinkedList* pArrayListEmployee);

/// @fn int SolicitarDatosEmpleadoYRetornarlos(char[], char[], int, char[], char[], char[], char[], char[], char[])
/// @brief Solicita al usuario los datos a cargar para un empleado
///
/// @param mensajeNombre Mensaje a mostrar cuando se solicita el nombre
/// @param nombre Direccion de memoria donde se almacena el nombre
/// @param sizeNombre sizeof de la variable del nombre
/// @param mensajeHoras Mensaje a mostrar cuando se solicita las horas
/// @param horas Direccion de memoria donde se almacenan las horas
/// @param mensajeSueldo Mensaje a mostrar cuando se solicita el sueldo
/// @param sueldo Direccion de memoria donde se almacena el sueldo
/// @param id Direccion de memoria donde se almacena el ID
/// @param mensajeError Mensaje de error cuando se ingresa un dato incorrecto
/// @return -1 en caso de error, 0 si se pudieron obtener los datos
int SolicitarDatosEmpleadoYRetornarlos (char mensajeNombre[], char nombre[], int sizeNombre, char mensajeHoras[], char horas[],
										char mensajeSueldo[], char sueldo[], char id[], char mensajeError[]);
/// @fn int employee_compareByID(void*, void*)
/// @brief Compara el ID de 2 empleados
///
/// @param empA Primer empleado para hacer la comparacion
/// @param empB Segundo empleado para hacer la comparacion
/// @return 0 si los ID son iguales o en caso de no poder hacer la comparacion, -1 si el ID del segundo empleado
/// 		es mayor, 1 si el ID del primer empleado es mayor
int employee_compareByID (void* empA, void* empB);

/// @fn int employee_compareByName(void*, void*)
/// @brief Compara el nombre de 2 empleados
///
/// @param empA Primer empleado para hacer la comparacion
/// @param empB Segundo empleado para hacer la comparacion
/// @return 0 si los nombre son iguales o en caso de no poder hacer la comparacion, -1 si el nombre del segundo
/// 		empleado es mayor, 1 si el nombre del primer empleado es mayor
int employee_compareByName (void* empA, void* empB);

/// @fn int employee_compareByHoras(void*, void*)
/// @brief Compara las horas de 2 empleados
///
/// @param empA Primer empleado para hacer la comparacion
/// @param empB Segundo empleado para hacer la comparacion
/// @return 0 si las horas son iguales o en caso de no poder hacer la comparacion, -1 si las horas  del segundo
/// 		empleado son mayores, 1 si las horas del primer empleado son mayores
int employee_compareByHoras (void* empA, void* empB);

/// @fn int employee_compareBySalario(void*, void*)
/// @brief Compara el sueldo de 2 empleados
///
/// @param empA Primer empleado para hacer la comparacion
/// @param empB Segundo empleado para hacer la comparacion
/// @return 0 si los sueldos son iguales o en caso de no poder hacer la comparacion, -1 si el sueldo del segundo
/// 		empleado es mayor, 1 si el sueldo del primer empleado es mayor
int employee_compareBySalario (void* empA, void* empB);

/// @fn int employee_Modify(Employee*)
/// @brief Permite al usuario moficar el nombre, sueldo o las horas de un empleado, o cancelar la modificacion
///
/// @param this Empleado a modificar
/// @return -1 por error, 0 si se hizo una moficacion, 1 si el usuario cancelo la modificaon
int employee_Modify (Employee* this);

/// @fn int employee_returnIndexByID(LinkedList*, int)
/// @brief Devuelve el indice de un empleado buscado por ID
///
/// @param pArrayListEmployee Lista de empleado
/// @param idBuscado ID buscado
/// @return -1 por error o no encontrarse, sino la posicion del empleado en la lista
int employee_returnIndexByID (LinkedList* pArrayListEmployee, int idBuscado);

/// @fn int employee_show(Employee*)
/// @brief Muestra el ID, nombre, horas y sueldo de un empleado
///
/// @param this Empleado a mostrar
/// @return -1 por error, 0 si se pudo mostrar
int employee_show (Employee* this);

Employee* employee_new();//Constructor por defecto
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr);
void employee_delete(Employee* this);

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);

#endif // employee_H_INCLUDED
