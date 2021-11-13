#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "utn_matias.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int rtn = -1;
	char auxID[12];
	char auxNombre[128];
	char auxHoras[12];
	char auxSueldo[12];
	Employee* pEmpleado;

	if (pFile != NULL && pArrayListEmployee != NULL) {

		fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", auxID, auxNombre, auxHoras, auxSueldo);

		while (!feof(pFile)) {

			fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", auxID, auxNombre, auxHoras, auxSueldo);

			if (StringIsNumber(auxID) &&
				!EsNombreInvalido(auxNombre) &&
				StringIsNumber(auxHoras) &&
				StringIsNumber(auxSueldo)) {

				pEmpleado = employee_newParametros(auxID, auxNombre, auxHoras, auxSueldo);

				if (pEmpleado != NULL) {
					if (ll_add(pArrayListEmployee, pEmpleado) == 0) {
					rtn = 0;
					}else {
						employee_delete(pEmpleado);
					}
				}
			}
		}
	}
    return rtn;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int rtn = -1;
	Employee* pEmpleado;

	if (pFile != NULL && pArrayListEmployee != NULL) {

		while (!feof(pFile)) {

			pEmpleado = employee_new();

			if (pEmpleado != NULL && fread (pEmpleado, sizeof(Employee), 1, pFile)==1){
				if (ll_add(pArrayListEmployee, pEmpleado) == 0) {
					rtn = 0;
				} else {
					employee_delete (pEmpleado);
				}
			}
		}
	}
    return rtn;
}
