#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"
#include "utn_matias.h"

//ID
//Nombre
//Horas
//Sueldo

static int NuevoID (char IDparaEmpleado[]);

static int NuevoID (char IDparaEmpleado[]) {

	int rtn = -1;

	char idRTN[12];
	int idAux;
	FILE* pUltimoID;

	pUltimoID = fopen ("ultimo_id.txt", "r");

	if (IDparaEmpleado != NULL && pUltimoID != NULL) {

		fgets (idRTN, 12, pUltimoID);

		fclose(pUltimoID);

		idAux = atoi (idRTN);

		idAux++;

		if (itoa (idAux, idRTN, 10) != NULL) {
			strcpy (IDparaEmpleado, idRTN);
			rtn = 0;
		}
	}

	return rtn;

}

int SolicitarDatosEmpleadoYRetornarlos (char mensajeNombre[], char nombre[], int sizeNombre, char mensajeHoras[], char horas[],
										char mensajeSueldo[], char sueldo[], char id[], char mensajeError[]) {
	int rtn = -1;
	int auxHoras;
	int auxSueldo;

	if (mensajeNombre != NULL && nombre != NULL && mensajeHoras != NULL && horas != NULL &&
		mensajeSueldo != NULL && sueldo != NULL && id != NULL && mensajeError != NULL &&
		utn_getNombre(nombre, mensajeNombre, mensajeError, sizeNombre, 3) == 0 &&
		PedirEnteroEnRangoV3(mensajeHoras, mensajeError, 0, 325, &auxHoras, 3) == 0 &&
		PedirEnteroEnRangoV3(mensajeSueldo, mensajeError, 1, 400000, &auxSueldo, 3) == 0 &&
		itoa(auxHoras, horas, 10) != NULL && itoa(auxSueldo, sueldo, 10) != NULL && NuevoID(id) == 0) {

		rtn = 0;

	}

	return rtn;
}

int employee_compareByID (void* empA, void* empB) {

	int rtn = 0;
	Employee* empleadoA;
	Employee* empleadoB;
	int idAAux;
	int idBAux;

	empleadoA = (Employee*) empA;
	empleadoB = (Employee*) empB;

	if (empleadoA != NULL && empleadoB != NULL) {

		employee_getId(empleadoA,&idAAux);
		employee_getId(empleadoB,&idBAux);

		if (idAAux > idBAux) {

			rtn = 1;

		} else if (idAAux < idBAux){

			rtn = -1;

		}


	}

	return rtn;
}


int employee_compareByName (void* empA, void* empB) {
	int rtn = 0;
	Employee* empleadoA;
	Employee* empleadoB;
	char auxNombreA[128];
	char auxNombreB[128];

	if (empA != NULL && empB != NULL) {
		empleadoA = (Employee*) empA;
		empleadoB = (Employee*) empB;

		employee_getNombre(empleadoA, auxNombreA);
		employee_getNombre(empleadoB, auxNombreB);

		rtn = strcmp(auxNombreA, auxNombreB);
	}

	return rtn;
}

int employee_compareByHoras (void* empA, void* empB) {

	int rtn = 0;
	Employee* empleadoA;
	Employee* empleadoB;
	int horasAuxA;
	int horasAuxB;

	empleadoA = (Employee*) empA;
	empleadoB = (Employee*) empB;

	if (empleadoA != NULL && empleadoB != NULL) {

		employee_getHorasTrabajadas(empleadoA,&horasAuxA);
		employee_getHorasTrabajadas(empleadoB,&horasAuxB);

		if (horasAuxA > horasAuxB) {

			rtn = 1;

		} else if (horasAuxA < horasAuxB){

			rtn = -1;

		}

	}

	return rtn;
}

int employee_compareBySalario (void* empA, void* empB) {

	int rtn = 0;
	Employee* empleadoA;
	Employee* empleadoB;
	int salarioAuxA;
	int salarioAuxB;

	empleadoA = (Employee*) empA;
	empleadoB = (Employee*) empB;

	if (empleadoA != NULL && empleadoB != NULL) {

		employee_getSueldo(empleadoA,&salarioAuxA);
		employee_getSueldo(empleadoB,&salarioAuxB);

		if (salarioAuxA > salarioAuxB) {

			rtn = 1;

		} else if (salarioAuxA < salarioAuxB){

			rtn = -1;

		}

	}

	return rtn;
}

int employee_returnIndexByID (LinkedList* pArrayListEmployee, int idBuscado) {
	int index = -1;
	int len;
	int id;
	Employee* pEmpleado;

	if (pArrayListEmployee !=NULL && idBuscado >= 0) {

		len = ll_len(pArrayListEmployee);

		if (len > 0) {

			for (int i = 0 ; i < len ; i++) {

				pEmpleado = ll_get(pArrayListEmployee, i);

				if (pEmpleado != NULL && employee_getId(pEmpleado, &id) == 0 && id == idBuscado) {

					index = i;
					break;
				}

			}

		}

	}

	return index;
}

int employee_Modify (Employee* this) {

	int rtn = -1;
	int option;
	char auxNombre[128];
	char auxHoras[14];
	char auxSueldo[14];


	if (this != NULL) {

		if (employee_show(this) == 0 &&
			PedirEnteroEnRangoV3("\nQue opcion quiere modificar?\n1. Nombre.\n2. Horas.\n3. Sueldo.\n", "\nError.", 1, 3, &option, 3) == 0) {

			switch (option) {

			case 1:

				if (utn_getNombre(auxNombre, "\nIngrese el nuevo nombre: ", "\nError.", sizeof(auxNombre), 3) == 0) {

					employee_setNombre(this, auxNombre);
					rtn = 0;

				}

				break;
			case 2:

				if (PedirEnteroChar("\nIngrese las nuevas horas: ", "\nError. ", auxHoras, 3) == 0) {

					employee_setHorasTrabajadas(this, atoi(auxHoras));
					rtn = 0;
				}

				break;
			case 3:

				if (PedirEnteroChar("\nIngrese sueldo: ", "\nError, ingrese un sueldo valido", auxSueldo, 3) == 0) {

					employee_setSueldo(this, atoi(auxSueldo));
					rtn = 0;

				}
				break;
			}

		}

	}


	return rtn;
}

int employee_show (Employee* this) {
	int rtn = -1;
	int auxID;
	char auxNombre[128];
	int auxHoras;
	int auxSueldo;

	if (this != NULL &&
		employee_getId (this, &auxID) == 0 &&
		employee_getNombre(this, auxNombre) == 0 &&
		employee_getHorasTrabajadas(this, &auxHoras) == 0 &&
		employee_getSueldo(this, &auxSueldo) == 0) {

		printf ("%-8d %-20s %-8d %-8d\n", auxID, auxNombre, auxHoras, auxSueldo);

		rtn = 0;

	}

	return rtn;
}

int employee_getOne (Employee* empleado)
{
	int rtn = -1;


	return rtn;
}

Employee* employee_new(){
	Employee* pEmpleado;

	pEmpleado = (Employee*) malloc (sizeof(Employee));

	if (pEmpleado != NULL){
//		pEmpleado->id = 0;
//		strcpy(pEmpleado->nombre,"\0");
//		pEmpleado->horasTrabajadas = 0;
//		pEmpleado->sueldo = 0;
		employee_setId(pEmpleado, 0);
		employee_setNombre(pEmpleado, "0");
		employee_setHorasTrabajadas(pEmpleado, 0);
		employee_setSueldo(pEmpleado, 0);
	}

	return pEmpleado;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr){
	Employee* pEmpleado;

	pEmpleado = employee_new();

	int auxID;
	int auxHoras;
	int auxSueldo;

	if(pEmpleado != NULL && idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL && sueldoStr != NULL){

		auxID = atoi(idStr);
		auxHoras = atoi(horasTrabajadasStr);
		auxSueldo = atoi(sueldoStr);

		employee_setId(pEmpleado, auxID);
		employee_setNombre(pEmpleado, nombreStr);
		employee_setHorasTrabajadas(pEmpleado, auxHoras);
		employee_setSueldo(pEmpleado, auxSueldo);
	}

	return pEmpleado;
}

//////////// SETTERS

int employee_setId(Employee* this,int id){
	int rtn = -1;

	if (this != NULL) {
		this->id = id;
		rtn = 0;
	}
	return rtn;
}

int employee_setNombre(Employee* this,char* nombre){
	int rtn = -1;

	if (this != NULL) {
		strcpy(this->nombre, nombre);
		rtn = 0;
	}

	return rtn;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas){
	int rtn = -1;

	if (this != NULL) {
		this->horasTrabajadas = horasTrabajadas;
		rtn = 0;
	}

	return rtn;
}

int employee_setSueldo(Employee* this,int sueldo) {
	int rtn = -1;

	if (this != NULL) {
		this-> sueldo = sueldo;
		rtn = 0;
	}

	return rtn;
}

//////////// GETTERS

int employee_getId(Employee* this,int* id) {
	int rtn = -1;

	if (this != NULL && id != NULL) {
		*id = this -> id;
		rtn = 0;
	}

	return rtn;
}

int employee_getNombre(Employee* this,char* nombre) {
	int rtn = -1;

	if (this != NULL && nombre != NULL) {
		strcpy (nombre, this->nombre);
		rtn = 0;
	}

	return rtn;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas){
	int rtn = -1;

	if (this != NULL && horasTrabajadas != NULL) {
		*horasTrabajadas = this -> horasTrabajadas;
		rtn = 0;
	}

	return rtn;
}

int employee_getSueldo(Employee* this,int* sueldo) {
	int rtn = -1;

	if (this != NULL && sueldo != NULL) {
		*sueldo = this->sueldo;
		rtn = 0;
	}
	return rtn;
}
