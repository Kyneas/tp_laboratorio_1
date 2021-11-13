#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "utn_matias.h"


/// @fn void GuardarID(char[])
/// @brief Guarda el ultimo ID usado en un archivo txt
///
/// @param ultimoID ID a guardar
void GuardarID (char ultimoID[]);

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    int rtn = -1;
    FILE* pArchivo;

    if (path != NULL && pArrayListEmployee != NULL) {

    	pArchivo = fopen (path, "r");

    	if (pArchivo != NULL) {

    		rtn = parser_EmployeeFromText(pArchivo, pArrayListEmployee);

    		fclose(pArchivo);

    	}

    }

    return rtn;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	int rtn = -1;
	FILE* pArchivo;

    if (path != NULL && pArrayListEmployee != NULL) {

    	pArchivo = fopen (path, "rb");

    	if (pArchivo != NULL) {

    		rtn = parser_EmployeeFromBinary(pArchivo, pArrayListEmployee);

    		fclose(pArchivo);

    	}

    }


    return rtn;
}

void GuardarID (char ultimoID[]) {

	FILE* pUltimoID;

	pUltimoID = fopen ("ultimo_id.txt", "w");

	fprintf (pUltimoID, ultimoID);

	fclose(pUltimoID);

}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	int rtn = -3;
	char auxNombre[128];
	char auxHoras[12];
	char auxSueldo[12];
	char auxID[12];
	Employee* pEmpleado;

	if (pArrayListEmployee != NULL) {
		rtn = -2;
		if (SolicitarDatosEmpleadoYRetornarlos("\nIngrese el nombre del empleado: ", auxNombre, sizeof(auxNombre),
											   "\nIngrese la horas totales del mes realizadas: ", auxHoras,
											   "\nIngrese el sueldo correspondiente al mes previo: ", auxSueldo,
											   auxID, "\nError en la toma del dato. ") == 0) {
			rtn = -1;

			pEmpleado = employee_newParametros(auxID, auxNombre, auxHoras, auxSueldo);

			if (pEmpleado != NULL) {
				if (ll_add(pArrayListEmployee, pEmpleado) == 0) {
					GuardarID (auxID);
					rtn = 0;
				} else {
					employee_delete(pEmpleado);
				}

			}
		}
	}
    return rtn;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	int rtn = -4;
	int id;
	int index;
	Employee* pEmpleado = NULL;

	if (pArrayListEmployee != NULL) {

		rtn = -3;

		if (PedirEnteroV3("\nIngrese el ID del empleado a editar: ", "\nError.", &id, 3) == 0) {

			index = employee_returnIndexByID(pArrayListEmployee, id);

			rtn = -2;

			if (index != -1) {

				pEmpleado = (Employee*) ll_get(pArrayListEmployee, index);

				if (pEmpleado != NULL) {
					rtn = employee_Modify(pEmpleado);
				}
			}
		}
	}
    return rtn;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int rtn = -3;
	int id;
	int index;
	Employee* pEmpleado = NULL;
	int confirmar;

	if (pArrayListEmployee != NULL) {

		rtn = -2;

		if (PedirEnteroV3("\nIngrese el ID del empleado que quiere dar de baja. ", "\nError.", &id, 3) == 0) {

			index = employee_returnIndexByID(pArrayListEmployee, id);

			rtn = -1;

			if (index != -1) {

				pEmpleado = (Employee*) ll_get(pArrayListEmployee, index);

				if (pEmpleado != NULL &&
					employee_show(pEmpleado) == 0 &&
					PedirEnteroEnRangoV3("\nConfirma la baja?\n1. SI\n2. No", "\nError.", 1, 2, &confirmar, 3) == 0 &&
					confirmar == 1) {

					ll_remove(pArrayListEmployee, index);
					employee_delete(pEmpleado);

					rtn = 0;

				}

			}

		}

	}

    return rtn;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int rtn = -2;
	int len;
	Employee *auxiliar;

	if (pArrayListEmployee != NULL) {

		len = ll_len(pArrayListEmployee);
		rtn = -1;

		if (len > 0) {

			for (int i = 0 ; i < len ; i++) {

				auxiliar = (Employee*)ll_get(pArrayListEmployee, i);

				if (employee_show(auxiliar) == 0) {
					rtn = 0;
				}

			}

		}

	}

    return rtn;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int rtn = -3;
    int criterio;
    int orden;

    if (pArrayListEmployee != NULL) {

    	rtn = -2;

    	if (PedirEnteroEnRangoV3("\nBajo que criterio quiere ordenar la lista?"
    			                 "\n1. ID."
    			                 "\n2. Nombre."
    			                 "\n3. Horas."
    			                 "\n4. Sueldo", "\nError", 1, 4, &criterio, 4) == 0 &&
    		PedirEnteroEnRangoV3("\nOrden:"
    				             "\n1. Descendente."
    				             "\n2. Ascendente.", "\nError", 1, 2, &orden, 4) == 0) {

    		orden--;

    		switch (criterio) {

    		case 1:

    			printf ("\nOrdenando lista...\n");
        			rtn = ll_sort(pArrayListEmployee, employee_compareByID, orden);
    			break;

    		case 2:

    			printf ("\nOrdenando lista...\n");
        			rtn = ll_sort(pArrayListEmployee, employee_compareByName, orden);
    			break;

    		case 3:

    			printf ("\nOrdenando lista...\n");
        			rtn = ll_sort(pArrayListEmployee, employee_compareByHoras, orden);
    			break;

    		case 4:

    			printf ("\nOrdenando lista...\n");
        			rtn = ll_sort(pArrayListEmployee, employee_compareBySalario, orden);
    			break;

    		}

    	}

    }

    return rtn;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	int rtn = -2;
	int len;
	FILE* pArchivo;
	int auxID;
	char auxNombre[128];
	int auxHoras;
	int auxSueldo;
	Employee* auxEmpleado;

	if (path != NULL && pArrayListEmployee != NULL) {

		pArchivo = fopen (path, "w");

		if (pArchivo != NULL) {

			len = ll_len(pArrayListEmployee);

			fprintf (pArchivo, "id,nombre,horasTrabajadas,sueldo\n");

			for (int i = 0 ; i < len ; i++) {

				auxEmpleado = ll_get(pArrayListEmployee, i);

				employee_getId (auxEmpleado, &auxID);
				employee_getNombre(auxEmpleado, auxNombre);
				employee_getHorasTrabajadas(auxEmpleado, &auxHoras);
				employee_getSueldo(auxEmpleado, &auxSueldo);

				fprintf (pArchivo, "%d,%s,%d,%d\n", auxID, auxNombre, auxHoras, auxSueldo);

				rtn = 0;

			}

			fclose(pArchivo);

		}

	}

    return rtn;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	int rtn = -2;
	FILE* pArchivo;
	int len;
	Employee* auxEmpleado;

	if (path != NULL && pArrayListEmployee != NULL) {

		pArchivo = fopen (path, "wb");

		rtn = -1;

		if (pArchivo != NULL) {

			len = ll_len(pArrayListEmployee);

			for (int i = 0 ; i < len; i++) {

				auxEmpleado = (Employee*) ll_get(pArrayListEmployee, i);

				fwrite (auxEmpleado, sizeof(Employee), 1,  pArchivo);

			}

			fclose(pArchivo);

			rtn = 0;

		}

	}

    return rtn;
}
