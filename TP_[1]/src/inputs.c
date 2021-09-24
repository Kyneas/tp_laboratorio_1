#include "inputs.h"


int PedirEnteroEnRangoIncluyendo(char mensaje[], int min, int max) {
	int entero;

	printf("%s", mensaje);
	scanf("%d", &entero);

	entero = ValidarEnteroIncluyendo(mensaje, entero, min, max);

	return entero;
}

float PedirFloat (char mensaje[]){
	float flotante;

	printf("%s", mensaje);
	scanf("%f", &flotante);

	return flotante;
}
