#ifndef OPERACIONES_MATEMATICAS_H_
#define OPERACIONES_MATEMATICAS_H_

#include "validaciones.h"

/// @fn float SumarFlotantes(float, float)
/// @brief Suma 2 flotantes y devuelve el resultado flotante
///
/// @param valorA Primer valor flotante
/// @param valorB Segundo valor flotante
/// @return Resultado de la operacion suma
float SumarFloat(float valorA, float valorB);

/// @fn float RestarFlotantes(float, float)
/// @brief  Resta 2 flotantes y devuelve el resultado flotante
///
/// @param valorA Primer valor flotante
/// @param valorB Segundo valor flotante
/// @return Resultado de la operacion resta
float RestarFloat(float valorA, float valorB);

/// @fn int DividirFlotantes(float, float, float*)
/// @brief Divide 2 flotantes de ser posible e informa si pudo o no hacerse la operacion
///
/// @param valorA Primer valor flotante
/// @param valorB Segundo valor flotante
/// @param resultado Resultado de la operacion division
/// @return Retorna 1 en caso de que se haya realizado la operacion y 0 si no pudo realizarce
int DividirFloat(float valorA, float valorB, float *resultado);

/// @fn float MultiplicarFlotantes(float, float)
/// @brief Multiplica 2 flotantes y devuelve el resultado flotante
///
/// @param valorA Primer valor flotante
/// @param valorB Segundo valor flotante
/// @return Resultado de la operacion multiplicacion
float MultiplicarFloat(float valorA, float valorB);

/// @fn int CalcularFactorial(int, unsigned long int*)
/// @brief Calcula el factorial de un numero, retorna un valor segun segun el exito de la funcion y asigna el resultado en una direccion de memoria
///
/// @param entero Valor del cual se calculara el factorial
/// @param resultado Direccion de memoria en la cual se guardara el resultado (De ser posible)
/// @return Devuelve 1 si pudo calcular el factorial y 0 caso contrario
int CalcularFactorial(float flotante, unsigned long int *resultado);

#endif /* OPERACIONES_MATEMATICAS_H_ */
