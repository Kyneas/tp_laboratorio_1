#include "inputs.h"


int PedirEnteroEnRangoIncluyendo(char mensaje[], int min, int max) {
	int entero;

	printf("%s", mensaje);
	scanf("%d", &entero);

	entero = ValidarEnteroIncluyendo(mensaje, entero, min, max);

	return entero;
}

int PedirInt (char mensaje[]){
	int entero;

	printf("%s", mensaje);
	scanf("%d", &entero);

	return entero;
}
