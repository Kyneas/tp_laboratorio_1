#include "validaciones.h"

int ValidarEnteroIncluyendo(char mensaje[], int entero, int min, int max) {

	while (!(entero >= min && entero <= max)) {
		printf("Error, seleccione entre %d y %d. %s ", min, max, mensaje);
		scanf("%d", &entero);
	}

	return entero;
}
