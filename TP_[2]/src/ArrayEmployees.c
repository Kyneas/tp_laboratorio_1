#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "inputs.h"

static int NewID();

/** \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int initEmployees(Employee* list, int len)
{
	int retorno = -1;
	if(list != NULL && len > 1)
	{
		for (int i = 0 ; i < len ; i++)
		{
			list[i].isEmpty = 1;
		}

		retorno = 0;
	}
 return retorno;
}

/** \brief add in a existing list of employees the values received as parameters
 * in the first empty position
 * \param list employee*
 * \param len int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
 *
 **/
int addEmployee(Employee* list, int len, int id, char name[],char
lastName[],float salary,int sector)
{
	int retorno = -1;

	if(list != NULL && len > 1)
	{
		for(int i = 0 ; i < len ; i++)
		{
			if(list[i].isEmpty)
			{
				list[i].id = id;
				strcpy(list[i].name, name);
				strcpy(list[i].lastName, lastName);
				list[i].salary = salary;
				list[i].sector = sector;
				list[i].isEmpty = 0;

				retorno = 0;

				break;
			}
		}
	}

    return retorno;
}

/** \brief Permite hacer la carga de un empleado solicitando los datos al usuario
 * \param list employee* Lista de empleados donde se hara la carga
 * \param len int Largo de la lista de empleados donde se hara la carga
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
 *
 **/
int chargeEmployee(Employee* list, int len)
{
	int retorno = -1;
	char name[51];
	char lastName[51];
	int id;
	float salary;
	int sector;

	if(list != NULL && len > 1)
	{
		PedirCadena(name, sizeof(name), "Ingrese el nombre: ", "Error, vuelva a ingresar el nombre: ");
		PedirCadena(lastName, sizeof(lastName), "Ingrese el apellido: ", "Error, vuelva a ingresar el apellido: ");
		id = NewID();
		salary = PedirFlotantePositivo("Ingrese el sueldo: ", "Error, vuelva a ingresar el sueldo: ");
		sector = PedirEnteroPositivo("Ingrese el numero de sector: ", "Error, vuelva a ingresar el sector: ");

		retorno = addEmployee(list, len, id, name, lastName, salary, sector);
	}

	return retorno;
}

/** \brief find an Employee by Id en returns the index position in array.
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
 *
 */
int findEmployeeById(Employee* list, int len,int id)
{
	int retorno = -1;

	if(list != NULL && len > 1)
	{
		for(int i = 0 ; i < len ; i++)
		{
			if(!list[i].isEmpty && list[i].id == id)
			{
				retorno = i;
			}
		}
	}

	return retorno;
}

/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
 *
 */
int removeEmployee(Employee* list, int len, int id)
{
	int retorno = -1;

	if(list != NULL && len > 1)
	{
		for(int i = 0 ; i < len ; i++)
		{
			if(!list[i].isEmpty && list[i].id == id)
			{
				list[i].isEmpty = 1;
				retorno = 0;
			}
		}
	}

	return retorno;
}

/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
 *
 * \param list Employee*
 * \param len int
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int sortEmployees(Employee* list, int len, int order)
{
	int retorno = -1;
	Employee auxiliar;
	int comparacion;

	if(list != NULL && len > 1)
	{

		switch(order)
		{case 1:
			for(int i = 0 ; i < len - 1 ; i++)
			{
				for(int j = i + 1 ; j < len ; j++)
				{
					if(!list[i].isEmpty && !list[j].isEmpty)
					{
						comparacion = stricmp(list[i].lastName, list[j].lastName);
						if(comparacion > 0)
						{
							auxiliar = list[i];
							list[i] = list[j];
							list[j] = auxiliar;
							retorno = 0;
						}else if(comparacion == 0 && list[i].sector > list[j].sector)
						{
							auxiliar = list[i];
							list[i] = list[j];
							list[j] = auxiliar;
							retorno = 0;
						}
					}

				}
			}
			break;
		case 2:
			for(int i = 0 ; i < len - 1 ; i++)
			{
				for(int j = i + 1 ; j < len ; j++)
				{
					if(!list[i].isEmpty && !list[j].isEmpty)
					{
						comparacion = stricmp(list[i].lastName, list[j].lastName);
						if(comparacion < 0)
						{
							auxiliar = list[i];
							list[i] = list[j];
							list[j] = auxiliar;
							retorno = 0;
						}else if(comparacion == 0 && list[i].sector < list[j].sector)
						{
							auxiliar = list[i];
							list[i] = list[j];
							list[j] = auxiliar;
							retorno = 0;
						}
					}

				}
			}

		}

	}

	return retorno;
}

/** \brief print the content of employees array
 *
 * \param list Employee*
 * \param length int
 * \return int -1 en caso de error por lista nula, 0 si pudo imprimirse
 */
int printEmployees(Employee* list, int length)
{
	int retorno = -1;
	int flagFirstEmployee = 1;

	if(list != NULL && length > 1)
	{

		for(int i = 0 ; i < length ; i++)
		{
			if(!list[i].isEmpty)
			{
				if(flagFirstEmployee)
				{
					printf("\nID   Apellido       Nombre         Salario     Sector");
				}
				printEmployee(list[i]);
				flagFirstEmployee = 0;
				retorno = 0;
			}

		}
	}

	return retorno;
}

/** \brief Imprime en pantalla los datos de un empleado
 *
 * \param empleado Empleado que se va a imprimir en pantalla
 *
 */
void printEmployee(Employee empleado)
{
	printf("\n%-4d %-14s %-14s $%-10.2f %-4d",empleado.id,empleado.lastName,empleado.name, empleado.salary, empleado.sector);
}

/** \brief Informa si hay algun empleado cargado en la lista
 *
 * \param list Employee* Lista de empleados a evaluar
 * \param length int Largo de la lista de empleados a evaluar
 * \return int 0 Si no existe ningun empleado cargado, 1 si hay por lo menos 1 empleado cargado en la lista.
 */
int thereIsEmployee (Employee* list, int length)
{
	int retorno = 0;

	if(list != NULL && length > 1)
	{
		for (int i = 0 ; i < length ; i++)
		{
			if(!list[i].isEmpty)
			{
				retorno = 1;
				break;
			}
		}
	}

	return retorno;
}

/** \brief Informa si una lista de empleados esta llena
 *
 * \param list Lista de empleados a evaluar
 * \param length Largo de la lista de empleados a evaluar
 * \return 1 si la lista esta llena, 0 si queda al menos 1 lugar
 *
 */
int TheListIsFull(Employee* list, int length)
{
	int retorno = 1;

	if(list != NULL && length > 1)
	{
		for(int i = 0 ; i < length ; i++)
		{
			if(list[i].isEmpty)
			{
				retorno = 0;
				break;
			}
		}
	}

	return retorno;
}

/** \brief Permite modificar nombre, apellido, sector o salario de un empleado
 *
 * \param list Lista de empleados a evaluar
 * \param pos Posicion en la lista del empleado a modificar
 * \return -1 en caso de error, 0 si se pudo modificar con exito
 *
 */
int modifyEmployee(Employee* list, int pos)
{
	int retorno = -1;
	int opcion;
	printf("\nID   Apellido       Nombre         Salario     Sector");
	printEmployee(list[pos]);

	opcion = MostrarMenuYElegirOpcion("\n\n1.Nombre.\n2.Apellido.\n3.Sector.\n4.Salario.", 1, 4);

	if(list != NULL)
	{
		switch(opcion)
		{
		case 1:
			PedirCadena(list[pos].name, sizeof(list[pos].name), "Ingrese el nombre", "Error");
			retorno = 0;
			break;
		case 2:
			PedirCadena(list[pos].lastName, sizeof(list[pos].lastName), "Ingrese el apellido", "Error");
			retorno = 0;
			break;
		case 3:
			list[pos].sector = PedirEntero("Ingrese el numero del nuevo sector", "Error, ingrese un sector valido");
			retorno = 0;
			break;
		case 4:
			list[pos].salary = PedirFlotante("Ingrese el nuevo sueldo", "Error, ingrese un sueldo valido");
			retorno = 0;
			break;
		}
	}

	return retorno;
}

/** \brief Calcula cuando es el sueldo promedio de una lista de empleados e informa cuando es la suma total de todos
 *
 * \param list Lista de empleados a evaluar
 * \param length Largo de la lista de empleados a evaluar
 * \param totalSueldo Direccion de memoria de la variable donde se almacenara el total de la suma de sueldos
 * \return Valor del promedio del sueldo, -1 en caso de error por lista nula
 *
 */
float promedioSueldo(Employee* list, int length, int * totalSueldo)
{
	float promedio = -1;
	float acumulador = 0;
	int contador = 0;

	if(list != NULL && length > 1)
	{
		for(int i = 0; i < length ; i++)
		{
			if(!list[i].isEmpty)
			{
				acumulador += list[i].salary;
				contador++;
			}
		}
		promedio = acumulador / contador;
		*totalSueldo = acumulador;
	}
	return promedio;
}

/** \brief Muestra una lista de los empleados que tienen un sueldo mayor al pasado como parametro y los cuenta
 *
 * \param list Lista de empleados a evaluar
 * \param length Largo de la lista de empleados a evaluar
 * \param promedio para verificar
 * \return -1 En caso de ERROR por lista nula o largo invalido, 0 si salio Ok
 *
 */
int mostrarEmpleadosMayorASueldo(Employee* list, int length, float promedio)
{
	int retorno = -1;
	int contador = 0;
	int flagFirstEmployee = 1;

	if(list != NULL && length > 1)
	{
		for(int i = 0 ; i < length ; i++)
		{
			if(!list[i].isEmpty && list[i].salary > promedio)
			{
				if(flagFirstEmployee)
				{
					printf("\nID   Apellido       Nombre         Salario     Sector");
				}
				printEmployee(list[i]);
				contador++;
				flagFirstEmployee = 0;
			}
		}
		retorno = contador;
	}
	return retorno;
}

/** \brief Muestra 1 mensaje a base a si la funcion pasada como parametro tuvo exito o no
 *
 * \param estado Retorno de la funcion a evaluar
 * \param mensajeOk Mensaje si el retorno de la funcion es 0 (Salio bien)
 * \param mensajeError Mensaje si el retorno de la funcion es -1 (Salio mal)
 *
 */
void MensajeAlerta(int estado, char mensajeOk[], char mensajeError[])
{
	if(estado == -1)
	{
		printf(mensajeError);
	}
	else
	{
		printf(mensajeOk);
	}
}

/** \brief Muestra una menu de opcion y retorna una opcion en un rango determinado
 *
 * \param menu Menu a mostras
 * \param minOpcion Valor minimo de opcion para elegir en el menu
 * \param maxOpcion Valor maximo de opcion para elegir en el menu
 * \return Opcion validada en el rango determinado
 *
 */
int MostrarMenuYElegirOpcion(char menu[], int minOpcion, int maxOpcion)
{
	int opcion;

	printf(menu);

	opcion = PedirEnteroEnRango("\nIngrese la opcion deseada: ","\nError, fuera de rango: ",  minOpcion, maxOpcion);

	return opcion;
}

/** \brief Genera un ID incremental, diferente cada vez que se llama a la funcion
 *
*
 * \return Numero de ID unico
 *
 */
static int NewID()
{
 static int id = 0;
 id++;
 return id;
}
