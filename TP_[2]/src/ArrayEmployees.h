/*
 * ArrayEmployees.h
 *
 *  Created on: 8 oct. 2021
 *      Author: Matias
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

typedef struct{
	int id;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int isEmpty;

}Employee;

int initEmployees(Employee* list, int len);
int addEmployee(Employee* list, int len, int id, char name[],char
lastName[],float salary,int sector);
int chargeEmployee(Employee* list, int len);
int findEmployeeById(Employee* list, int len,int id);
int removeEmployee(Employee* list, int len, int id);
int sortEmployees(Employee* list, int len, int order);
int printEmployees(Employee* list, int length);
void printEmployee(Employee empleado);
int thereIsEmployee (Employee* list, int length);
int modifyEmployee(Employee* list, int pos);
float promedioSueldo(Employee* list, int length, int * totalSueldo);
int mostrarEmpleadosMayorASueldo(Employee* list, int length, float promedio);
int TheListIsFull(Employee* list, int length);
void MensajeAlerta(int estado, char mensajeOk[], char mensajeError[]);
int MostrarMenuYElegirOpcion(char menu[], int minOpcion, int maxOpcion);

#endif
