/*
 ============================================================================
 Name        : TP1.c
 Author      : Matias Ferreira
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 Hacer una calculadora. Para ello el programa iniciar? y contar? con un men? de opciones:
 1. Ingresar 1er operando (A=x)
 2. Ingresar 2do operando (B=y)
 3. Calcular todas las operaciones
 a) Calcular la suma (A+B)
 b) Calcular la resta (A-B)
 c) Calcular la division (A/B)
 d) Calcular la multiplicacion (A*B)
 e) Calcular el factorial (A!)
 4. Informar resultados
 a) ?El resultado de A+B es: r?
 b) ?El resultado de A-B es: r?
 c) ?El resultado de A/B es: r? o ?No es posible dividir por cero?
 d) ?El resultado de A*B es: r?
 e) ?El factorial de A es: r1 y El factorial de B es: r2?
 5. Salir
 ? Todas las funciones matem?ticas del men? se deber?n realizar en una biblioteca aparte,
 que contenga las funciones para realizar las cinco operaciones.
 ? En el men? deber?n aparecer los valores actuales cargados en los operandos A y B
 (donde dice ?x? e ?y? en el ejemplo, se debe mostrar el n?mero cargado)
 ? Deber?n contemplarse los casos de error (divisi?n por cero, etc)
 ? Documentar todas las funciones
 */

#include <stdio.h>
#include <stdlib.h>
#include "inputs.h"
#include "operaciones-matematicas.h"

int main(void) {
	setbuf(stdout, NULL);
	int opcion;
	float operandoA;
	float operandoB;
	int flagOperandoACargado;
	int flagOperandoBCargado;
	int flagCalcularOperaciones;
	float resultadoSuma;
	float resultadoResta;
	float resultadoMultiplicacion;
	float resultadoDivision;
	int divisionHecha;
	int factorialAHecho;
	int factorialBHecho;
	unsigned long int resultadoFactorialA;
	unsigned long int resultadoFactorialB;

	flagOperandoACargado = 0;
	flagOperandoBCargado = 0;
	flagCalcularOperaciones = 0;

	printf("Bienvenido/a a mi calculadora\n");

	do {
		printf("__________________________________\n");
		if (flagOperandoACargado && flagOperandoBCargado) {
			printf("1. Ingresar 1er operando (A=%.2f)\n", operandoA);
			printf("2. Ingresar 2do operando (B=%.2f)\n", operandoB);
			printf("3. Calcular todas las operaciones\n");
			printf(" a) Calcular la suma (%.2f+%.2f)\n", operandoA, operandoB);
			printf(" b) Calcular la resta (%.2f-%.2f)\n", operandoA, operandoB);
			printf(" c) Calcular la division (%.2f/%.2f)\n", operandoA,
					operandoB);
			printf(" d) Calcular la multiplicacion (%.2f*%.2f)\n", operandoA,
					operandoB);
			printf(" e) Calcular el factorial (%.2f! y %.2f!)\n", operandoA,
					operandoB);
		} else if (flagOperandoACargado) {
			printf("1. Ingresar 1er operando (A=%.2f)\n", operandoA);
			printf("2. Ingresar 2do operando (B=x)\n");
			printf("3. Calcular todas las operaciones\n");
			printf(" a) Calcular la suma (%.2f+B)\n", operandoA);
			printf(" b) Calcular la resta (%.2f-B)\n", operandoA);
			printf(" c) Calcular la division (%.2f/B)\n", operandoA);
			printf(" d) Calcular la multiplicacion (%.2f*B)\n", operandoA);
			printf(" e) Calcular el factorial (%.2f! y B!)\n", operandoA);

		} else if (flagOperandoBCargado) {
			printf("1. Ingresar 1er operando (A=y)\n");
			printf("2. Ingresar 2do operando (B=%.2f)\n", operandoB);
			printf("3. Calcular todas las operaciones\n");
			printf(" a) Calcular la suma (A+%.2f)\n", operandoB);
			printf(" b) Calcular la resta (A-%.2f)\n", operandoB);
			printf(" c) Calcular la division (A/%.2f)\n", operandoB);
			printf(" d) Calcular la multiplicacion (A*%.2f)\n", operandoB);
			printf(" e) Calcular el factorial (A! y %.2f!)\n", operandoB);

		} else {

			printf("1. Ingresar 1er operando (A=y)\n");
			printf("2. Ingresar 2do operando (B=x)\n");
			printf("3. Calcular todas las operaciones\n");
			printf(" a) Calcular la suma (A+B)\n");
			printf(" b) Calcular la resta (A-B)\n");
			printf(" c) Calcular la division (A/B)\n");
			printf(" d) Calcular la multiplicacion (A*B)\n");
			printf(" e) Calcular el factorial (A! y B!)\n");

		}
		printf("4. Informar resultados\n");
		printf("5. Salir\n");

		opcion = PedirEnteroEnRangoIncluyendo("Ingrese un opcion: ", 1, 5);

		switch (opcion) {
		case 1:
			operandoA = PedirFloat("Ingrese el operando A: ");
			flagOperandoACargado = 1;
			flagCalcularOperaciones = 0;
			break;
		case 2:
			operandoB = PedirFloat("Ingrese el operando B: ");
			flagOperandoBCargado = 1;
			flagCalcularOperaciones = 0;
			break;
		case 3:
			if (flagOperandoACargado && flagOperandoBCargado) {
				printf("\nOperaciones realizadas\n");
				resultadoSuma = SumarFloat(operandoA, operandoB);
				resultadoResta = RestarFloat(operandoA, operandoB);
				divisionHecha = DividirFloat(operandoA, operandoB,
						&resultadoDivision);
				resultadoMultiplicacion = MultiplicarFloat(operandoA,
						operandoB);

				factorialAHecho = CalcularFactorial(operandoA,
						&resultadoFactorialA);
				factorialBHecho = CalcularFactorial(operandoB,
						&resultadoFactorialB);

				flagCalcularOperaciones = 1;
			} else {
				printf("\n--Debe ingresar primero el operando A y B\n");
			}
			break;
		case 4:
			if (flagCalcularOperaciones) {
				printf(" a) ?El resultado de %.2f + %.2f es: %.2f?\n", operandoA,
						operandoB, resultadoSuma);
				printf(" b) ?El resultado de %.2f - %.2f es: %.2f?\n", operandoA,
						operandoB, resultadoResta);
				if (divisionHecha) {
					printf(" c) ?El resultado de %.2f / %.4f es: %.2f?\n",
							operandoA, operandoB, resultadoDivision);
				} else {
					printf(" c) ?No es posible dividir por cero?\n");
				}
				printf(" d) ?El resultado de %.2f * %.2f es: %.2f?\n", operandoA,
						operandoB, resultadoMultiplicacion);
				if (factorialAHecho && factorialBHecho) {
					printf(
							" e) ?El factorial de %.2f es: %lu y El factorial de %.2f es: %lu?\n",
							operandoA, resultadoFactorialA, operandoB,
							resultadoFactorialB);
				} else if (factorialAHecho) {
					printf(
							" e) ?El factorial de %.2f es: %lu\n     El factorial de %.2f no pudo calcularse, esto de debe a que es negativo, \n     decimal o excede las capacidades de la calculadora?\n",
							operandoA, resultadoFactorialA, operandoB);
				} else if (factorialBHecho) {
					printf(
							" e) ?El factorial de %.2f es: %lu\n     El factorial de %.2f no pudo calcularse, esto de debe a que es negativo, \n     decimal o excede las capacidades de la calculadora?\n",
							operandoB, resultadoFactorialB, operandoA);
				} else {
					printf(
							" e) ?Error, no pudo calcularse. Los valores no deben ser negativos o decimales o excedieron las capacidades de la calculadora\n");
				}

			} else {
				printf("\n--Debe calcular primero las operaciones\n");
			}
			break;
		}

	} while (opcion != 5);

	printf("Calculadora finalizada.");

	return EXIT_SUCCESS;
}
