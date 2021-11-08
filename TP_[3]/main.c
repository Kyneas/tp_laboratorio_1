#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "parser.h"
#include "utn_matias.h"
#include "verificar-retornos.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main()
{
	setbuf(stdout,NULL);

	int option;
	int rtnOption;
	int cargaOK = -1;
	int cargaLista = 1;
	int salirSinGuardar = 1;
	int confirmaSalirSinGuardar;


    LinkedList* pArrayListEmployee = ll_newLinkedList();

    do {
        do{

        	rtnOption = PedirEnteroEnRangoV3("\n-------------------MENU----------------------------\n"
        								     "1. Cargar los datos de los empleados desde el archivo data.csv (modo texto)\n"
    										 "2. Cargar los datos de los empleados desde el archivo data.csv (modo binario)\n"
    										 "3. Alta de empleado\n"
    										 "4. Modificar datos de empleado\n"
    										 "5. Baja de empleado\n"
    										 "6. Listar empleados\n"
    										 "7. Ordenar empleados\n"
    										 "8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n"
    										 "9. Guardar los datos de los empleados en el archivo data.bin (modo binario).\n"
    										 "10. Salir\n",
    										 "Error, opcion incorrecta", 1, 10, &option, 5);

            switch(option)
            {
                case 1:

                	if (cargaLista) {

//                		cargaOK = controller_loadFromText("data2.csv",pArrayListEmployee);
                		retornos_loadFromAny(controller_loadFromText("data2.csv",pArrayListEmployee), &cargaOK);
                		cargaLista = 0;
                	}
                	else
                	{
                		printf ("La carga ya fue realizada con exito anteriormente.\n");
                	}

                    break;
                case 2:

                	if (cargaLista) {

//                		cargaOK = controller_loadFromBinary("data4.dat", pArrayListEmployee);
                		retornos_loadFromAny(controller_loadFromBinary("data4.dat", pArrayListEmployee), &cargaOK);
                		cargaLista = 0;

                	}
                	else
                	{
                		printf ("La carga ya fue realizada con exito anteriormente.\n");
                	}

                	break;
                case 3:

//                	cargaOK = controller_addEmployee(pArrayListEmployee);
                	retornos_addEmployee(controller_addEmployee(pArrayListEmployee), &cargaOK);

                	break;
                case 4:
                	if (cargaOK == 0) {
//                		controller_editEmployee(pArrayListEmployee);
                		retornos_editEmployee(controller_editEmployee(pArrayListEmployee));
                	}
                	else
                	{
                		printf ("Debe hacer primero la carga de los empleados.\n");
                	}
                	break;
                case 5:

                	if (cargaOK == 0) {
//                		controller_removeEmployee(pArrayListEmployee);
                		retornos_removeEmployee(controller_removeEmployee(pArrayListEmployee));
                	}
                	else
                	{
                		printf ("Debe hacer primero la carga de los empleados.\n");
                	}

                	break;
                case 6:
                	if (cargaOK == 0) {
//                		controller_ListEmployee(pArrayListEmployee);
                		retornos_ListEmployee(controller_ListEmployee(pArrayListEmployee));
                	}
                	else
                	{
                		printf ("Debe hacer primero la carga de los empleados.\n");
                	}

                	break;
                case 7:
                	if (cargaOK == 0) {
//                		controller_sortEmployee(pArrayListEmployee);
                		retornos_sortEmployee(controller_sortEmployee(pArrayListEmployee));
                	}
                	else
                	{
                		printf ("Debe hacer primero la carga de los empleados.\n");
                	}
                	break;
                case 8:
                	if (cargaOK == 0 && cargaLista == 0) {
//                		controller_saveAsText("data2.csv", pArrayListEmployee);
                		retornos_saveAsAny(controller_saveAsText("data2.csv", pArrayListEmployee));
                		controller_saveAsBinary("data4.dat", pArrayListEmployee);
                		salirSinGuardar=0;
                	}
                	else
                	{
                		printf ("Debe hacer primero la carga de los empleados.\n");
                	}
                	break;

                case 9:
                	if (cargaOK == 0 && cargaLista == 0) {
//                		controller_saveAsBinary("data4.dat", pArrayListEmployee);
                		retornos_saveAsAny(controller_saveAsBinary("data4.dat", pArrayListEmployee));
                		controller_saveAsText("data2.csv", pArrayListEmployee);
                		salirSinGuardar=0;
                	}
                	else
                	{
                		printf ("Debe hacer primero la carga de los empleados.\n");
                	}

            }
        }while(option != 10 && rtnOption == 0);

        if (rtnOption != 0 || (salirSinGuardar && PedirEnteroEnRangoV3("\nEsta saliendo sin guardar los cambios. Confirma que desear salir?"
	             "\n1. No"
	             "\n2. Si", "\nError", 1, 2, &confirmaSalirSinGuardar, 3)==0)) {
        	confirmaSalirSinGuardar--;
        } else if (salirSinGuardar == 0) {
        	break;
        }

    }while(rtnOption == 0 && confirmaSalirSinGuardar == 0);

    printf ("FIN");

    return 0;
}

