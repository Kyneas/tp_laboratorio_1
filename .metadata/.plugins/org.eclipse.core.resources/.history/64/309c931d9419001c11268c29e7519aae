#include "operaciones-matematicas.h"

float SumarFlotantes(float valorA, float valorB) {
	float resultado;

	resultado = valorA + valorB;

	return resultado;
}

float RestarFlotantes(float valorA, float valorB) {
	float resultado;

	resultado = valorA - valorB;

	return resultado;
}

float MultiplicarFlotantes(float valorA, float valorB) {
	float resultado;

	resultado = valorA * valorB;

	return resultado;
}

int DividirFlotantes(float valorA, float valorB, float *resultado) {
	int divisionHecha;

	divisionHecha = 0;

	if (valorB != 0) {
		*resultado = valorA / valorB;
		divisionHecha = 1;
	}

	return divisionHecha;

}

float CalcularFactorial (float flotante){
	float factorial;
	float i;

	factorial = 1;

	for( i = flotante ; i > 1 ; i--){
		factorial *= i;
	}

	return factorial;
}
