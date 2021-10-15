/*
 ============================================================================
 Name        : TP_[2].c
 Author      : Matias Ferreira
 Version     : 1.0
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "inputs.h"
#include "ArrayEmployees.h"

#define TAM 7

int main(void) {
	setbuf(stdout, NULL);

	Employee listaEmpleados[TAM];

	int opcion;
	int id;
	int position;
	float promedioSalario;
	int totalSueldos;
	int empleadosMayorSueldoPromedio;

	initEmployees(listaEmpleados, TAM);

	do
	{
		opcion = MostrarMenuYElegirOpcion("\n\n1.ALTAS\n2.MODIFICAR\n3.BAJA\n4.INFORMAR\n5.SALIR", 1, 5);

		switch(opcion)
		{
			case 1:

				if(TheListIsFull(listaEmpleados, TAM))
				{
					printf("\nNo se puede dar de alta un nuevo empleado, la lista esta llena");
				}
				else
				{
					do
					{
						MensajeAlerta(chargeEmployee(listaEmpleados, TAM), "\nCarga exitosa", "\nError");

					}while(PedirSN("\nQuiere agregar mas usuarios? S/N ", "\nError, escriba S/N"));
				}

				break;
			case 2:
				if(thereIsEmployee(listaEmpleados, TAM))
				{
					do
					{
						printEmployees(listaEmpleados, TAM);
						id = PedirEntero("\nIngrese el ID del empleado a modificar", "\nError, ingrese un numero de ID valido");

						position = findEmployeeById(listaEmpleados, TAM, id);

						if(position == -1)
						{
							printf("\nNo hay empleadados cargados/activos con el ID %d", id);
						}
						else
						{

							MensajeAlerta(modifyEmployee(listaEmpleados, position), "\nModificacion realizada con exito.", "\nError al realizar la modificación");
						}

					}while(PedirSN("\nQuiere modificar otro usuario? S/N", "Error, escriba S/N"));
				}
				else
				{
					printf("\nNo hay empleados cargados / Dados de alta.");
				}
				break;
			case 3:
				if(thereIsEmployee(listaEmpleados, TAM))
				{
					printEmployees(listaEmpleados, TAM);

					id = PedirEntero("\nQue ID desea dar de baja?", "Error, ingrese un numero de ID valido");

					if(findEmployeeById(listaEmpleados, TAM, id) != -1)
					{
						printf("\nConfirma la baja del usuario con el ID %d?", id);
						opcion = PedirSN("S/N", "Error, escriba S/N");
						if(opcion)
						{
							MensajeAlerta(removeEmployee(listaEmpleados, TAM, id), "\nEl usuario fue dado de baja exitosamente.", "\nError al realizar la baja.");

						}
						else
						{
							printf("\nSolicitud de baja cancelada");
						}
					}
					else
					{
						printf("\nNo hay empleadados cargados/activos con el ID %d", id);
					}

				}
				else
				{
					printf("\nNo hay empleados cargados / Dados de alta.");
				}
				break;
			case 4:
				if(thereIsEmployee(listaEmpleados, TAM))
				{
					opcion = MostrarMenuYElegirOpcion("\n\n1. Listado de los empleados ordenados alfabéticamente por Apellido y Sector.\n2. Total y promedio de los salarios, y cuántos empleados superan el salario promedio.", 1, 2);

					if(opcion == 1)
					{

						opcion = MostrarMenuYElegirOpcion("\n\n1. Ordenar de forma ascendente.\n2. Ordenar de formas descendente.", 1, 2);

						sortEmployees(listaEmpleados, TAM, opcion);
						printEmployees(listaEmpleados, TAM);
					}
					else
					{
						promedioSalario = promedioSueldo(listaEmpleados, TAM, &totalSueldos);

						if(promedioSalario != -1)
						{
							empleadosMayorSueldoPromedio = mostrarEmpleadosMayorASueldo(listaEmpleados, TAM, promedioSalario);

							if(empleadosMayorSueldoPromedio == -1)
							{
								printf("\nError al mostrar el promedio");
							}
							else
							{
								printf("\nLa cantidad de sueldos totales es de $%d, con un promedio de $%.2f. Siendo superado por un total de %d empleados", totalSueldos, promedioSalario, empleadosMayorSueldoPromedio);
							}
						}
					}

				}else
				{
					printf("\nNo hay empleados cargados / Dados de alta.");
				}
				break;
		}

	}while(opcion != 5);

	printf("\nPrograma finalizado");


	return EXIT_SUCCESS;
}
