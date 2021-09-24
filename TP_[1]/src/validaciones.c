#include "validaciones.h"

int ValidarEnteroIncluyendo(char mensaje[], int entero, int min, int max) {

	while (!(entero >= min && entero <= max)) {
		printf("Error, seleccione entre %d y %d. %s ", min, max, mensaje);
		scanf("%d", &entero);
	}

	return entero;
}

/// @fn int VerifiarSiEsFlotante(float)
/// @brief Informa si un valor ingresado es flotante o entero
///
/// @param numeroIngresado Numero a analizar
/// @return Retorna 1 si es flotante, 0 si es entero
int VerificarSiEsFlotante (float numeroIngresado){
	int resultado;
	float parteDecimales;
	int parteEntera;

	resultado = 1;

	parteEntera = numeroIngresado;

	parteDecimales = numeroIngresado - parteEntera;

	if(parteDecimales == 0){
		resultado = 0;
	}

	return resultado;
}
