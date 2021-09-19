#include "operaciones-matematicas.h"

int SumarInt(int valorA, int valorB) {
	float resultado;

	resultado = valorA + valorB;

	return resultado;
}

int RestarInt(int valorA, int valorB) {
	float resultado;

	resultado = valorA - valorB;

	return resultado;
}

int MultiplicarInt(int valorA, int valorB) {
	float resultado;

	resultado = valorA * valorB;

	return resultado;
}

int DividirInt(int valorA, int valorB, float *resultado) {
	int divisionHecha;

	divisionHecha = 0;

	if (valorB != 0) {
		*resultado = (float) valorA / valorB;
		divisionHecha = 1;
	}

	return divisionHecha;

}

int CalcularFactorial(int entero, unsigned long int *resultado) {
	unsigned long int factorial;
	int factorialHecho = 0;
	int i;
	if (entero <= 12) {
		factorial = 1;
		for (i = entero; i > 1; i--) {
			factorial *= i;
			factorialHecho = 1;
		}
		*resultado = factorial;
	}

	return factorialHecho;
}
