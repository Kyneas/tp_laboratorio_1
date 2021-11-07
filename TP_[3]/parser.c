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
	char auxID[14];
	char auxNombre[128];
	char auxHoras[14];
	char auxSueldo[14];
	Employee* pEmpleado;

	if (pFile != NULL && pArrayListEmployee != NULL) {

		fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", auxID, auxNombre, auxHoras, auxSueldo);

		while (!feof(pFile)) {

			fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", auxID, auxNombre, auxHoras, auxSueldo);

			if (StringIsNumber(auxID, sizeof(auxID)) &&
//				!EsNombreInvalido(auxNombre) &&
				StringIsNumber(auxHoras, sizeof(auxHoras)) &&
				StringIsNumber(auxSueldo, sizeof(auxSueldo))) {

				pEmpleado = employee_newParametros(auxID, auxNombre, auxHoras, auxSueldo);

				if (pEmpleado != NULL) {
					ll_add(pArrayListEmployee, pEmpleado);
					rtn = 0;
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

			if (fread (pEmpleado, sizeof(Employee), 1, pFile)==1){
				ll_add(pArrayListEmployee, pEmpleado);
			}

			rtn = 0;

		}
	}

    return rtn;
}
