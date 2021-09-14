#ifndef INPUTS_H_
#define INPUTS_H_
#include <stdio.h>
#include "validaciones.h"

/// @fn int PedirEntero(char[], int, int)
/// @brief Pide y devuelve un numero entero validado entre un rango incluyendo el minimo y el maximo
///
/// @param mensaje Mensaje que se va a mostrar al solicitar el numero
/// @param min Valor minimo del rango para ingresar el numero entero
/// @param max Valor maximo del rango para ingresar el numero entero
/// @return Numero entero validado
int PedirEnteroEnRangoIncluyendo(char mensaje[], int min, int max);

/// @fn float PedirFlotante(char[])
/// @brief Pide al usuario ingresar un numero, puede ser flotante
///
/// @param mensaje Mensaje que se muestra al pedir el numero
/// @return Numero ingresado por el usuario
float PedirFlotante (char mensaje[]);


#endif
