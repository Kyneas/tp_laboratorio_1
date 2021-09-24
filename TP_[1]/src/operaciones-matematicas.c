#include "operaciones-matematicas.h"

float SumarFloat(float valorA, float valorB) {
	float resultado;

	resultado = valorA + valorB;

	return resultado;
}

float RestarFloat(float valorA, float valorB) {
	float resultado;

	resultado = valorA - valorB;

	return resultado;
}

float MultiplicarFloat(float valorA, float valorB) {
	float resultado;

	resultado = valorA * valorB;

	return resultado;
}

int DividirFloat(float valorA, float valorB, float *resultado) {
	int divisionHecha;

	divisionHecha = 0;

	if (valorB != 0) {
		*resultado = valorA / valorB;
		divisionHecha = 1;
	}

	return divisionHecha;

}

int CalcularFactorial(float numIngresado, unsigned long int *resultado) {
	int factorial;
	int factorialHecho = 0;
	int i;
	int entero;
	entero = (int) numIngresado;

	if (numIngresado == 0) {
		factorialHecho = 1;
		*resultado = 1;
	} else if (entero <= 12 && !VerificarSiEsFlotante(numIngresado)) {
		factorial = 1;
		for (i = entero; i > 0; i--) {
			factorial *= i;
			factorialHecho = 1;
		}
		*resultado = factorial;
	}

	return factorialHecho;
}
