#include "verificar-retornos.h"

void retornos_loadFromAny(int estado, int *retorno) {

	*retorno = estado;
	if (estado == 0) {
		printf ("\nLa lista se cargo correctamente.");
	} else {
		printf ("\nError en la carga.");
	}
}

void retornos_addEmployee (int estado, int *retorno) {

	*retorno = estado;
	if (estado == 0) {
		printf ("\nEl empleado se agrego correctamente.");
	} else if (estado == -1) {
		printf ("\nError, al agregar al empleado.");
	}else if (estado == -2) {
		printf ("\nError, ingrese muchas veces opciones invalidas, reintente luego.");
	} else {
		printf ("\nError en la lista.");
	}
}

void retornos_editEmployee (int estado, int *retorno) {
	*retorno = estado;

	if (estado == 0) {
		printf ("\nCliente modificado con exito.");
	}else if (estado == 1) {
		printf ("\nModificación cancelada.");
	}else if (estado == -1) {
		printf ("\nError en modificacion del empleado.");
	} else if (estado == -4) {
		printf ("\nError en la lista.");
	} else {
		printf ("\nError, ingreso muchas veces una opcion incorrecta. Reintente luego.");
	}

}

void retornos_removeEmployee (int estado, int *retorno) {
	*retorno = estado;

	if (estado == 0) {
		printf ("\nCliente eliminado con exito.");
	} else if (estado == -1) {
		printf ("\nBaja cancelada.");
	} else if (estado == -2){
		printf ("\nError, ingreso muchas veces una opcion incorrecta. Reintente luego.");
	} else {
		printf ("\nError en la lista.");
	}
}

void retornos_ListEmployee (int estado) {
	if (estado == -1) {
		printf ("\nLa lista esta vacia.");
	} else if (estado == -2) {
		printf ("\nError en la lista.");
	}
}

void retornos_sortEmployee (int estado, int *retorno) {
	*retorno = estado;

	if (estado == 0) {
		printf ("\nLa lista se a ordenado exitosamente.");
	} else if (estado == -1) {
		printf ("\nError al realizar el ordenamiento.");
	} else if (estado == -2) {
		printf ("\nError, ingreso muchas veces una opcion incorrecta. Reintente luego.");
	} else {
		printf ("\nError en la lista.");
	}
}

void retornos_saveAsAny (int estado) {
	if (estado == 0) {
		printf ("\nLista guardada exitosamente.");
	} else if (estado == -1) {
		printf ("\nError al abrir el archivo para guardar.");
	} else {
		printf ("\nError en el directorio/lista");
	}
}
