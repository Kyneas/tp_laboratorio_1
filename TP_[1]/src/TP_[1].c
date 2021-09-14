/*
 ============================================================================
 Name        : TP1.c
 Author      : Matias Ferreira
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 Hacer una calculadora. Para ello el programa iniciar� y contar� con un men� de opciones:
 1. Ingresar 1er operando (A=x)
 2. Ingresar 2do operando (B=y)
 3. Calcular todas las operaciones
 a) Calcular la suma (A+B)
 b) Calcular la resta (A-B)
 c) Calcular la division (A/B)
 d) Calcular la multiplicacion (A*B)
 e) Calcular el factorial (A!)
 4. Informar resultados
 a) �El resultado de A+B es: r�
 b) �El resultado de A-B es: r�
 c) �El resultado de A/B es: r� o �No es posible dividir por cero�
 d) �El resultado de A*B es: r�
 e) �El factorial de A es: r1 y El factorial de B es: r2�
 5. Salir
 � Todas las funciones matem�ticas del men� se deber�n realizar en una biblioteca aparte,
 que contenga las funciones para realizar las cinco operaciones.
 � En el men� deber�n aparecer los valores actuales cargados en los operandos A y B
 (donde dice �x� e �y� en el ejemplo, se debe mostrar el n�mero cargado)
 � Deber�n contemplarse los casos de error (divisi�n por cero, etc)
 � Documentar todas las funciones
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
	float divisionHecha;
	float resultadoFactorialA;
	float resultadoFactorialB;

	flagOperandoACargado = 0;
	flagOperandoBCargado = 0;
	flagCalcularOperaciones = 0;


	printf("Bienvenido/a a mi calculadora\n");

	do {

		if (flagOperandoACargado && flagOperandoBCargado) {
			printf("__________________________________\n");
			printf("1. Ingresar 1er operando (A=%g)\n", operandoA);
			printf("2. Ingresar 2do operando (B=%g)\n", operandoB);
			printf("3. Calcular todas las operaciones\n");
			printf("4. Informar resultados\n");
			printf("5. Salir\n");
		} else if (flagOperandoACargado) {
			printf("__________________________________\n");
			printf("1. Ingresar 1er operando (A=%g)\n", operandoA);
			printf("2. Ingresar 2do operando (B=x)\n");
			printf("3. Calcular todas las operaciones\n");
			printf("4. Informar resultados\n");
			printf("5. Salir\n");
		} else if (flagOperandoBCargado) {
			printf("__________________________________\n");
			printf("1. Ingresar 1er operando (A=y)\n");
			printf("2. Ingresar 2do operando (B=%g)\n", operandoB);
			printf("3. Calcular todas las operaciones\n");
			printf("4. Informar resultados\n");
			printf("5. Salir\n");
		} else {
			printf("__________________________________\n");
			printf("1. Ingresar 1er operando (A=y)\n");
			printf("2. Ingresar 2do operando (B=x)\n");
			printf("3. Calcular todas las operaciones\n");
			printf("4. Informar resultados\n");
			printf("5. Salir\n");
		}

		opcion = PedirEnteroEnRangoIncluyendo("Ingrese un opcion: ", 1, 5);

		switch (opcion) {
		case 1:
			operandoA = PedirFlotante("Ingrese el operando A: ");
			flagOperandoACargado = 1;
			flagCalcularOperaciones = 0;
			break;
		case 2:
			operandoB = PedirFlotante("Ingrese el operando B: ");
			flagOperandoBCargado = 1;
			flagCalcularOperaciones = 0;
			break;
		case 3:
			if (flagOperandoACargado && flagOperandoBCargado) {
				printf(" a) Calcular la suma (%g+%g)\n", operandoA,
						operandoB);
				printf(" b) Calcular la resta (%g-%g)\n", operandoA,
						operandoB);
				printf(" c) Calcular la division (%g/%g)\n", operandoA,
						operandoB);
				printf(" d) Calcular la multiplicacion (%g*%g)\n",
						operandoA, operandoB);
				printf(" e) Calcular el factorial (%g! y %g!)\n", operandoA,
						operandoB);
				resultadoSuma = SumarFlotantes(operandoA, operandoB);
				resultadoResta = RestarFlotantes(operandoA, operandoB);
				divisionHecha = DividirFlotantes(operandoA, operandoB,
						&resultadoDivision);
				resultadoMultiplicacion = MultiplicarFlotantes(operandoA,
						operandoB);
				resultadoFactorialA = CalcularFactorial(operandoA);
				resultadoFactorialB = CalcularFactorial(operandoB);
				flagCalcularOperaciones = 1;
			} else {
				printf("\n--Debe ingresar primero el operando A y B\n");
			}
			break;
		case 4:
			if (flagCalcularOperaciones) {
				printf(" a) �El resultado de %g+%g es: %g�\n", operandoA,
						operandoB, resultadoSuma);
				printf(" b) �El resultado de %g-%g es: %g�\n", operandoA,
						operandoB, resultadoResta);
				if (divisionHecha) {
					printf(" c) �El resultado de %g/%g es: %g�\n", operandoA,
							operandoB, resultadoDivision);
				} else {
					printf(" c) �No es posible dividir por cero�\n");
				}
				printf(" d) �El resultado de %g*%g es: %g�\n", operandoA,
						operandoB, resultadoMultiplicacion);
				printf(
						" e) �El factorial de %g es: %g y El factorial de %g es: %g�\n",
						operandoA, resultadoFactorialA, operandoB, resultadoFactorialB);
			} else {
				printf("\n--Debe calcular primero las operaciones\n");
			}
			break;
		}

	} while (opcion != 5);

	printf("Calculadora finalizada.");

	return EXIT_SUCCESS;
}
