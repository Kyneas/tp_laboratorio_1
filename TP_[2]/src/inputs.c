#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/// @fn int EsNumeroEnteroInvalido(char[], int)
/// @brief Valida que la cadena de char contenga un numero int valido
///
/// @param buffer Cadena a verificar
/// @param longitud Largo de la cadena a verificar
/// @return 0 si es un numero valido, 1 si es un numero invalido
static int EsNumeroEnteroInvalido(char buffer[], int longitud);

/// @fn int EsNumeroFlotanteInvalido(char[], int)
/// @brief Valida que la cadena de char contenga un numero float valido
///
/// @param buffer Cadena a verificar
/// @param longitud longitud Largo de la cadena a verificar
/// @return 0 si es un numero valido, 1 si es un numero invalido
static int EsNumeroFlotanteInvalido(char buffer[], int longitud);

static int myGets(char * cadena, int longitud);

void PedirCadena(char vector[], int largoVector, char mensaje[],
		char mensajeError[]) {
	char buffer[1000];

	printf("%s", mensaje);

	while (!myGets(buffer, sizeof(buffer)) || strlen(buffer) > largoVector - 1) {
		printf("%s", mensajeError);
	}

	strncpy(vector, buffer, largoVector - 1);
}

int PedirSN(char mensaje[], char mensajeError[]) {
	char buffer[1000];
	int respuesta = 0;

	printf(mensaje);

	while (!myGets(buffer, sizeof(buffer)) || strlen(buffer) > 1 || (buffer[0] != 's' && buffer[0] != 'S'
			&& buffer[0] != 'n' && buffer[0] != 'N'))
	{
		printf(mensajeError);
	}

		if (buffer[0] == 'S' || buffer[0] == 's')
		{
			respuesta = 1;
		}

	return respuesta;
}

int PedirEntero(char mensaje[], char mensajeError[]) {
	char numeroIngresado[20];
	int entero;

	printf(mensaje);

	while (!myGets(numeroIngresado, sizeof(numeroIngresado)) || EsNumeroEnteroInvalido(numeroIngresado, sizeof(numeroIngresado))) {
		printf(mensajeError);
	}

	entero = atoi(numeroIngresado);

	return entero;
}

int PedirEnteroEnRango(char mensaje[], char mensajeError[], int min, int max) {
	char numeroIngresado[20];
	int entero;
	int flagErrorRango = 0;
	int overflow;

	printf("%s", mensaje);
	overflow = myGets(numeroIngresado, sizeof(numeroIngresado));

	do {
		if (flagErrorRango) {
			printf(mensajeError);
			overflow = myGets(numeroIngresado, sizeof(numeroIngresado));
		}

		flagErrorRango = 1;

		while (!overflow || EsNumeroEnteroInvalido(numeroIngresado, sizeof(numeroIngresado))) {
			printf(mensajeError);
			overflow = myGets(numeroIngresado, sizeof(numeroIngresado));
		}

		entero = atoi(numeroIngresado);

	} while (entero < min || entero > max);

	return entero;
}

int PedirEnteroPositivo(char mensaje[], char mensajeError[]) {
	char numeroIngresado[20];
	int entero;
	int flagErrorRango = 0;
	int overflow;

	printf("%s", mensaje);
	overflow = myGets(numeroIngresado, sizeof(numeroIngresado));

	do {
		if (flagErrorRango) {
			printf(mensajeError);
			overflow = myGets(numeroIngresado, sizeof(numeroIngresado));
		}

		flagErrorRango = 1;

		while (!overflow || EsNumeroEnteroInvalido(numeroIngresado, sizeof(numeroIngresado))) {
			printf(mensajeError);
			overflow = myGets(numeroIngresado, sizeof(numeroIngresado));
		}

		entero = atoi(numeroIngresado);

	} while (entero <= 0);

	return entero;
}

int PedirEnteroExcluyendo(char mensaje[], int valorAExcluir)
{
		char numeroIngresado[20];
		int entero;
		int flagErrorRango = 0;
		int overflow;

		printf("%s", mensaje);
		overflow = myGets(numeroIngresado, sizeof(numeroIngresado));

		do {
			if (flagErrorRango) {
				printf("Valor fuera de rango: ");
				overflow = myGets(numeroIngresado, sizeof(numeroIngresado));
			}

			flagErrorRango = 1;

			while (!overflow || EsNumeroEnteroInvalido(numeroIngresado, sizeof(numeroIngresado))) {
				printf("Caracter invalido: ");
				overflow = myGets(numeroIngresado, sizeof(numeroIngresado));
			}

			entero = atoi(numeroIngresado);

		} while (entero == valorAExcluir);

		return entero;
}

static int EsNumeroEnteroInvalido(char buffer[], int longitud) {
	int noEsNumero = 0;
	int largo = strnlen(buffer,longitud);

	for (int i = 0; i < longitud && buffer[i] != '\0'; i++) {
		if((buffer[0] == '+' || buffer[0] == '-') && largo > 1){
			continue;
		}
		if (isdigit(buffer[i]) == 0) {
			noEsNumero = 1;
			break;
		}
	}

	return noEsNumero;
}

float PedirFlotante(char mensaje[], char mensajeError[]) {
	char numeroIngresado[20];
	float flotante;

	printf("%s", mensaje);

	while (!myGets(numeroIngresado, sizeof(numeroIngresado)) ||EsNumeroFlotanteInvalido(numeroIngresado, sizeof(numeroIngresado))) {
		printf("%s", mensajeError);
	}

	flotante = atof(numeroIngresado);

	return flotante;
}

float PedirFlotanteEnRango(char mensaje[], float min, float max) {
	char numeroIngresado[20];
	float flotante;
	int flagErrorRango = 0;
	int overflow;

	printf("%s", mensaje);
	overflow = myGets(numeroIngresado, sizeof(numeroIngresado));

	do {

		if (flagErrorRango) {
			printf("Valor fuera de rango: ");
			overflow = myGets(numeroIngresado, sizeof(numeroIngresado));
		}

		flagErrorRango = 1;

		while (!overflow || EsNumeroFlotanteInvalido(numeroIngresado, sizeof(numeroIngresado))) {
			printf("\nError, ingreso caracteres invalidos: ");
			overflow = myGets(numeroIngresado, sizeof(numeroIngresado));
		}

		flotante = atof(numeroIngresado);

	} while (flotante < min || flotante > max);

	return flotante;
}

float PedirFlotantePositivo(char mensaje[], char mensajeError[]) {
	char numeroIngresado[20];
	float flotante;
	int flagErrorRango = 0;
	int overflow;

	printf(mensaje);
	overflow = myGets(numeroIngresado, sizeof(numeroIngresado));

	do {

		if (flagErrorRango) {
			printf(mensajeError);
			overflow = myGets(numeroIngresado, sizeof(numeroIngresado));
		}

		flagErrorRango = 1;

		while (!overflow || EsNumeroFlotanteInvalido(numeroIngresado, sizeof(numeroIngresado))) {
			printf(mensajeError);
			overflow = myGets(numeroIngresado, sizeof(numeroIngresado));
		}

		flotante = atof(numeroIngresado);

	} while (flotante <= 0);

	return flotante;
}

static int EsNumeroFlotanteInvalido(char buffer[], int longitud) {
	int noEsNumero = 0;
	int largo = strnlen(buffer,longitud);
	int contadorPuntos = 0;

	for (int i = 0; i < longitud && buffer[i] != '\0'; i++) {
		if(buffer[i] == '.')
		{
			contadorPuntos++;

			if(contadorPuntos > 1 || largo == 1)
			{
				noEsNumero = 1;
				break;
			}
			continue;
		}

		if(i == 0 && (buffer[i] == '+' || buffer[i] == '-') && largo > 1)
		{
			if(buffer[1] == '.' && largo == 2)
			{
				noEsNumero = 1;
				break;
			}
			continue;
		}

		if (!isdigit(buffer[i]))
		{
			noEsNumero = 1;
			break;
		}
	}

	return noEsNumero;
}

static int myGets(char * cadena, int longitud){
	int retorno = 0;
	char buffer[4096];
	int largo = sizeof(buffer);

	if(cadena != NULL && longitud > 0){
		fflush(stdin);

		if(fgets(buffer, largo, stdin) != NULL){

			if(buffer[strnlen(buffer, largo) - 1] == '\n'){
				buffer[strnlen(buffer, largo) - 1] = '\0';
			}

			if(strnlen(buffer, largo) <= longitud){
				strncpy(cadena, buffer, longitud);
				retorno = 1;
			}
		}
	}

	return retorno;
}
