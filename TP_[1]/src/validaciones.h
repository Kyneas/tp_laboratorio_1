#include <stdio.h>
#include <ctype.h>
#include "inputs.h"

#ifndef VALIDACIONES_H_
#define VALIDACIONES_H_

/// @fn int ValidarEntero(char[], int, int, int)
/// @brief Valida un numero entero en un rango
///
/// @param mensaje Mensaje que se va a mostar al solicitar el numero junto a un error en caso de que el numero este fuera del rango
/// @param entero  Numero entero a validar
/// @param min Valor minimo del rango para ingresar el numero entero
/// @param max Valor maximo del rango para ingresar el numero entero
/// @return Numero entero validado
int ValidarEnteroIncluyendo(char mensaje[], int entero, int min, int max);

#endif
