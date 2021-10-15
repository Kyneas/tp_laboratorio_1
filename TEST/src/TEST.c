/*
 ============================================================================
 Name        : TEST.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "inputs.h"

int main(void) {
	setbuf(stdout,NULL);

	float flotante;

	do{

		flotante = PedirFlotante("\nIngrese numero", "\nError");

		printf("\nEl numero es %.2f", flotante);

	}while(flotante!=2);

	printf("\nFin del test");


	return EXIT_SUCCESS;
}
