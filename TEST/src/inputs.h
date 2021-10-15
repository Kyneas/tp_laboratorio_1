#ifndef INPUTS_H_
#define INPUTS_H_

/// @fn void PedirCadena(char[], int, char[], char[])
/// @brief Realiza la carga de un vector char
///
/// @param vector Vector donde se hara la carga
/// @param largoVector Largo del vector donde se hara la carga
/// @param mensaje Mensaje que se solicita al hacer la carga
/// @param mensajeError Mensaje de error en caso de que la carga se exceda de la capacidad del vector
void PedirCadena(char vector[], int largoVector, char mensaje[],
		char mensajeError[]);

/// @fn int PedirEntero(char[])
/// @brief Pide y valida que el valor ingresado sea un valor valido para int
///
/// @param mensaje Mensaje que se muestra al solicitar el numero
/// @param mensajeError Mensaje que se muestra en caso de ingresar caracteres invalidos
/// @return Numero int validado
int PedirEntero(char mensaje[], char mensajeError[]);

/// @fn int PedirEnteroEnRango(char[], int, int)
/// @brief Pide y valida que el valor ingresado sea un valor valido para int y ademas que este dentro de un rango especifico
///
/// @param mensaje Mensaje que se muestra al solicitar el numero
/// @param mensajeError Mensaje que se muestra al ingresar un numero fuera del rango valido o un caracter invalido
/// @param min Valor minimo del rango permitido
/// @param max Valor maximo del rango permitido
/// @return Numero int validado
int PedirEnteroEnRango(char mensaje[], char mensajeError[], int min, int max);

/// @fn int PedirEnteroExcluyendo(char[], int)
/// @brief Pide y valida que el valor ingresado sea un valor valido para int y ademas excluye un valor
///
/// @param mensaje Mensaje que se muestra al solicitar el numero
/// @param valorAExcluir Numero que no se permite en el ingreso
/// @return Numero int validado
int PedirEnteroExcluyendo(char mensaje[], int valorAExcluir);

/// @fn float PedirFlotante(char[])
/// @brief Pide y valida que el valor ingresado sea un valor valido para float
///
/// @param mensaje Mensaje que se muestra al solicitar el numero
/// @param mensajeError Mensaje que se muestra al ingresar caracteres invalidos
/// @return Numero float validado
float PedirFlotante(char mensaje[], char mensajeError[]);

/// @fn float PedirFlotanteEnRango(char[], float, float)
/// @brief Pide y valida que el valor ingresado sea un valor valido para float y ademas que este dentro de un rango especifico
///
/// @param mensaje Mensaje que se muestra al solicitar el numero
/// @param mensajeError Mensaje que se muestra en caso de error de rango o caracter invalido
/// @param min Valor minimo del rango permitido
/// @param max Valor maximo del rango permitido
/// @return Numero float validado
float PedirFlotanteEnRango(char mensaje[], float min, float max);

/// @fn int myGets(char*, int)
/// @brief
///
/// @param cadena
/// @param longitud
/// @return
int myGets(char * cadena, int longitud);

/// @fn int PedirSN(char[])
/// @brief Pide ingresar S para continuar o N para no hacerlo, indistinto si se usan mayus o minus y se valida.
///
/// @param mensaje El mensaje a mostrar al pedir el caracter
/// @param mensajeError El mensaje a mostrar luego de ingresar un caracter no valido
/// @return 1 en caso de S y 0 en caso de N
int PedirSN(char mensaje[], char mensajeError[]);


#endif
