#ifndef UTN_H_
#define UTN_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define LEN_DNI 9
#define LEN_CUIT 12
#define LEN_TELEFONO 10
#define LEN_CELULAR 13
#define LEN_EMAIL 64
#define LEN_TARJETA_CREDITO 20
#define LEN_DIRECCION 64
#define LEN_DIRECCION_ALTURA 10




////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////  NUMEROS  //////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////


/**
 * \brief Transforma una cadena de caractéres a números si es posible
 * \param int* pResultado Puntero donde se almacenará el número ingresado
 * \return Retorna 0 (EXITO) si se obtiene un número entero o -1 (ERROR) si no
*/
int utn_getInt(int *pResultado);

/**
 * \brief Transforma una cadena de caractéres a números decimales si es posible
 * \param float* pResultado Puntero donde se almacenará el número ingresado
 * \return Retorna 0 (EXITO) si se obtiene un número decimal o -1 (ERROR) si no
*/
int getFloat(float *pResultado);

/**
 * \brief Verifica que la cadena recibida contenga solamente números positivos o negativos
 * \param char* cadena Cadena de caracteres a ser analizada
 *  \param int len Define el tamaño de la cadena
 * \return Retorna 1 (verdadero) si la cadena es numérica, 0 (falso) si no o -1 si hubo algún error con los argumentos
*/
int utn_esNumerica(char* cadena, int len);

/**
 * \brief Verifica que la cadena recibida contenga solamente números decimales positivos o negativos
 * \param char* cadena Cadena de caracteres a ser analizada
 * \param int len Define el tamaño de la cadena
 * \return Retorna 1 (verdadero) si la cadena es decimal, 0 (falso) si no o -1 si hubo algún error con los argumentos
*/
int utn_esFloat(char* cadena, int len);

/**
 * \brief Solicita un número de tipo int al usuario, lo valida, verifica y devuelve el resultado
 * \param int* pResultado Puntero al resultado. Aquí se guarda el número ingresado por el usuario
 * \param char* pMensaje Puntero al mensaje a ser mostrado
 * \param char* pMensajeError Puntero al mensaje a ser mostrado en caso de error
 * \param int minimo Valor mínimo para el ingreso de números
 * \param int maximo Valor máximo para el ingreso de números
 * \param int reintentos Cantidad de reintentos en caso de error
 * \return Retorna 0 (EXITO) si se obtiene un número entre el rango o -1 (ERROR) si no
 */
int utn_getNumero(int* pResultado, char* pMensaje, char* pMensajeError, int minimo, int maximo, int reintentos);

/**
 * \brief Solicita un número de tipo float al usuario, lo valida, verifica y devuelve el resultado
 * \param int* pResultado Puntero al resultado. Aquí se guarda el número ingresado por el usuario
 * \param char* pMensaje Puntero al mensaje a ser mostrado
 * \param char* pMensajeError Puntero al mensaje a ser mostrado en caso de error
 * \param float minimo Valor mínimo para el ingreso de números
 * \param float maximo Valor máximo para el ingreso de números
 * \param int reintentos Cantidad de reintentos en caso de error
 * \return Retorna 0 (EXITO) si se obtiene un número entre el rango o -1 (ERROR) si no
 */
int utn_getFloat(float* pResultado, char* pMensaje, char* pMensajeError, float minimo, float maximo, int reintentos);


////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////  CALCULOS  ////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////


/**
 * \brief A partir de 2 números, realiza una suma
 * \param float operandoA Primer número que ingresó el usuario previamente
 * \param float operandoB Segundo número que ingresó el usuario previamente
 * \param float* pResultado Puntero donde se guardará la suma
 * \return 0 si la función fue exitosa, -1 si da error
 */
int utn_getSuma(float operandoA, float operandoB, float* pResultado);

/**
 * \brief A partir de 2 números, realiza una resta
 * \param float operandoA Primer número que ingresó el usuario previamente
 * \param float operandoB Segundo número que ingresó el usuario previamente
 * \param float* pResultado Puntero donde se guardará la resta
 * \return 0 si la función fue exitosa, -1 si da error
 */
int utn_getResta(float operandoA, float operandoB, float* pResultado);

/**
 * \brief A partir de 2 números, realiza una multiplicación
 * \param float operandoA Primer número que ingresó el usuario previamente
 * \param float operandoB Segundo número que ingresó el usuario previamente
 * \param float pResultado Puntero donde se guardará la multiplicación
 * \return 0 si la función fue exitosa, -1 si da error
 */
int utn_getMultiplicacion(float operandoA, float operandoB, float* pResultado);

/**
 * \brief A partir de 2 números, realiza una división. Valida si el divisor es 0
 * \param float operandoA Primer número que ingresó el usuario previamente
 * \param float operandoB Segundo número que ingresó el usuario previamente
 * \param float* pResultado Puntero donde se guardará la división
 * \param char* pMensajeError  Puntero al mensaje a ser mostrado en caso de error
 * \return 0 si la función fue exitosa, -1 si da error
 */
int utn_getDivision(float operandoA, float operandoB, float* pResultado, char* pMensajeError);

/**
 * \brief A partir de 1 número, realiza el factorial.
 * \param double operandoA Primer número que ingresó el usuario previamente
 * \param double* pResultadoA Puntero donde se guardará el factorial
 * \return Devuelve 0 si la función fue exitosa, -1 si da error
 */
int utn_getFactorial(double operandoA, double* pResultadoA);


////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////  STRING  ////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////


/**
 * \brief Solicita al usuario una cadena de caracteres, la valida y verifica que no quede un enter
 * \param char* pResultado Puntero donde se almacena la cadena de caracteres
 * \param char* pMensaje Puntero al mensaje a ser mostrado
 * \param char* pMensajeError Puntero al mensaje a ser mostrado en caso de error
 * \param int len Valor maximo de caracteres que se pueden ingresar
 * \param int reintentos Cantidad de reintentos en caso de error
 * \return Retorna 0 (EXITO) si se obtiene un número entre el rango o -1 (ERROR) si no
*/
int utn_getString(char* pResultado, char* pMensaje, char* pMensajeError, int len, int reintentos);

/**
 * \brief Solicita al usuario que ingrese un nombre
 * \param char* pNombre Puntero donde se almacenará el nombre ingresado
 * \param char* pMensaje Puntero al mensaje a ser mostrado
 * \param char* pMensajeError Puntero al mensaje a ser mostrado en caso de error
 * \param int limite Valor maximo de caracteres que se pueden ingresar
 * \param int reintentos Cantidad de reintentos en caso de error
 * \return Retorna 0 (EXITO) si se obtiene el nombre o -1 (ERROR) si no
 */
int utn_getNombre(char* pNombre, char* pMensaje, char* pMensajeError, int limite, int reintentos);

/**
 * \brief Solicita al usuario un caracter y lo valida
 * \param char* pResultado Puntero donde se almacena la cadena de caracteres
 * \param char* pMensaje Puntero al mensaje a ser mostrado
 * \param char* pMensajeError Puntero al mensaje a ser mostrado en caso de error
 * \param int reintentos Cantidad de reintentos en caso de error
 * \return Retorna 0 (EXITO) si se obtiene un número entre el rango o -1 (ERROR) si no
*/
int utn_getChar(char* pResultado, char* pMensaje, char* pMensajeError, int reintentos);


/**
 * \brief Recibe un caracter y valida que este entre a y z
 * \param char* letra: Puntero donde se almacena el caracter
 * \return Retorna 0 (EXITO) si se obtiene un número entre el rango o -1 (ERROR) si no
*/
int esLetra(char* letra);

/**
 * \brief Solicita al usuario el ingreso de un texto y lo convierte en mayusculas
 * \param char* pString Puntero donde se almacenará el texto ingresado en mayusculas
 * \param int limite Define el tamaño de la cadena
 * \param char* pMensaje Puntero al mensaje a ser mostrado
 * \param char* pMensajeError Puntero al mensaje a ser mostrado en caso de error
 * \return Retorna 0 (EXITO) si se obtiene el texto en mayúsculas o -1 (ERROR) si no
 */
int utn_getCadenaEnMayusculas(char* pString, int limite, char* pMensaje, char* pMensajeError);

/**
 * \brief Solicita al usuario el ingreso de un texto y lo convierte en minúsculas
 * \param char* pString Puntero donde se almacenará el texto ingresado en minusculas
 * \param int limite Define el tamaño de la cadena
 * \param char* pMensaje Puntero al mensaje a ser mostrado
 * \param char* pMensajeError Puntero al mensaje a ser mostrado en caso de error
 * \return Retorna 0 (EXITO) si se obtiene el texto en minúsculas o -1 (ERROR) si no
 */
int utn_getCadenaEnMinusculas(char* pString, int limite, char* pMensaje, char* pMensajeError);



////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////  OTRAS VALIDACIONES  ///////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////


/**
 * \brief Solicita al usuario el ingreso de un DNI
 * \param char* pDni: Puntero donde se almacenará el DNI ingresado
 * \param char* pMensaje Puntero al mensaje a ser mostrado
 * \param char* pMensajeError Puntero al mensaje a ser mostrado en caso de error
 * \return Retorna 0 (EXITO) si se obtiene el DNI o -1 (ERROR) si no
 */
int utn_getDni(char* pDni, char* pMensaje, char* pMensajeError);

/**
 * \brief Solicita al usuario que ingrese un CUIT
 * \param char* pCuit Puntero donde se almacenará el CUIT ingresado
 * \param char* pMensaje Puntero al mensaje a ser mostrado
 * \param char* pMensajeError Puntero al mensaje a ser mostrado en caso de error
 * \param int limite Define el tamaño de la cadena
 * \param int reintentos Cantidad de reintentos en caso de error
 * \return Retorna 0 (EXITO) si se obtiene el CUIT o -1 (ERROR) si no
 */
int utn_getCuit(char* pCuit, char* pMensaje, char* pMensajeError, int limite, int reintentos);

/**
 * \brief Solicita al usuario que ingrese una edad
 * \param int* pEdad Puntero donde se almacenará la edad ingresada
 * \param char* pMensaje Puntero al mensaje a ser mostrado
 * \param char* pMensajeError Puntero al mensaje a ser mostrado en caso de error
 * \return Retorna 0 (EXITO) si se obtiene la edad o -1 (ERROR) si no
 */
int utn_getEdad(int* pEdad, char* pMensaje, char* pMensajeError);

/**
 * \brief Solicita al usuario que ingrese un precio
 * \param float* pPrecio Puntero donde se almacenará el precio ingresado
 * \param char* pMensaje Puntero al mensaje a ser mostrado
 * \param char* pMensajeError Puntero al mensaje a ser mostrado en caso de error
 * \return Retorna 0 (EXITO) si se obtiene el precio o -1 (ERROR) si no
 */
int utn_getPrecio(float* pPrecio, char* pMensaje, char* pMensajeError);

/**
 * \brief Solicita al usuario que ingrese un teléfono
 * \param char* pTelefono Puntero donde se almacenará el telefono ingresado
 * \param char* pMensaje Puntero al mensaje a ser mostrado
 * \param char* pMensajeError Puntero al mensaje a ser mostrado en caso de error
 * \return Retorna 0 (EXITO) si se obtiene el teléfono o -1 (ERROR) si no
 */
int utn_getTelefono(char* pTelefono, char* pMensaje, char* pMensajeError);

/**
 * \brief Solicita al usuario que ingrese un celular
 * \param char* pCelular Puntero donde se almacenará el celular ingresado
 * \param char* pMensaje Puntero al mensaje a ser mostrado
 * \param char* pMensajeError Puntero al mensaje a ser mostrado en caso de error
 * \return Retorna 0 (EXITO) si se obtiene el celular o -1 (ERROR) si no
 */
int utn_getCelular(char* pCelular, char* pMensaje, char* pMensajeError);

/**
 * \brief Solicita al usuario que ingrese un email
 * \param char* pEmail Puntero donde se almacenará el email ingresado
 * \param char* pMensaje Puntero al mensaje a ser mostrado
 * \param char* pMensajeError Puntero al mensaje a ser mostrado en caso de error
 * \return Retorna 0 (EXITO) si se obtiene el email o -1 (ERROR) si no
 */
int utn_getEmail(char* pEmail, char* pMensaje, char* pMensajeError);

/**
 * \brief Le pide al usuario que ingrese una tarjeta de crédito
 * \param char* pTarjeta Puntero donde se almacenará la tarjeta de crédito ingresada
 * \param char* pMensaje Puntero al mensaje a ser mostrado
 * \param char* pMensajeError Puntero al mensaje a ser mostrado en caso de error
 * \return Retorna 0 (EXITO) si se obtiene la tarjeta de crédito o -1 (ERROR) si no
  */
int utn_getTarjetaCredito(char* pTarjeta, char* pMensaje, char* pMensajeError);

/**
 * \brief Solicita al usuario el ingreso de una dirección
 * \param char* pDireccion Puntero donde se almacenará la direccion ingresada
 * \param char* pMensaje Puntero al mensaje a ser mostrado
 * \param char* pMensajeAltura Puntero al texto que informa que se debe ingresar una altura
 * \param char* pMensajeError Puntero al mensaje a ser mostrado en caso de error
 * \param char* pMensajeErrorAltura Puntero al mensaje a ser mostrado en caso de que no se ingrese la altura de la dirección
 * \return Retorna 0 (EXITO) si se obtiene la dirección o -1 (ERROR) si no
 */
int utn_getDireccion(char* pDireccion, char* pMensaje, char* pMensajeAltura, char* pMensajeError, char* pMensajeErrorAltura);

/**
 * \brief Solicita un texto al usuario y lo convierte en mayúsculas
 * \param char* cadena Puntero donde se almacenará el texto en mayúsculas
 * \param int limite Limite Valor maximo de caracteres que se pueden ingresar
 * \return Retorna 0 (EXITO) si se convierte en mayúsculas o -1 (ERROR) si no
 */
int getMayusculas(char* cadena, int limite);

/**
 * \brief Solicita un texto al usuario y lo convierte en minúsculas
 * \param char* cadena Puntero donde se almacenará el texto en minúsculas
 * \param int limite Valor maximo de caracteres que se pueden ingresar
 * \return Retorna 0 (EXITO) si se convierte en minúsculas o -1 (ERROR) si no
 */
int getMinusculas(char* cadena, int limite);

/**
 * \brief Valida que la cadena recibida contenga solamente números decimales positivos o negativos
 * \param char* cadena Puntero a la cadena de caracteres a ser analizada
 * \param int limite Valor maximo de caracteres que se pueden ingresar
 * \return Retorna 1 (verdadero) si la cadena es decimal, 0 (falso) si no o -1 si hubo algún error con los argumentos
 */
int validarDecimal(char* cadena, int limite);

/**
 * \brief Valida que la cadena recibida contenga un nombre o apellido válido
 * \param char* cadena Puntero a la cadena de caracteres a ser analizada
 * \param int limite Valor maximo de caracteres que se pueden ingresar
 * \return Retorna 1 (verdadero) si la cadena es un nombre o apellido, 0 (falso) si no o -1 si hubo algún error con los argumentos
 */
int validarNombre(char* cadena, int limite);

/**
 * \brief Valida que la cadena recibida sea un DNI válido
 * \param char* cadena Puntero a la cadena de caracteres a ser analizada
 * \param int limite Valor maximo de caracteres que se pueden ingresar
 * \return Retorna 1 (verdadero) si la cadena es un DNI, 0 (falso) si no o -1 si hubo algún error en los argumentos
 */
int validarDni(char* cadena, int limite);

/**
 * \brief Valida que la cadena recibida sea un CUIT válido
 * \param char* cadena Puntero a la cadena de caracteres a ser analizada
 * \param int limite Valor maximo de caracteres que se pueden ingresar
 * \return Retorna 1 (verdadero) si la cadena es un CUIT, 0 (falso) si no o -1 si hubo algún error con los argumentos
 */
int validarCuit(char* cadena, int limite);

/**
 * \brief Valida que el número ingresado sea una edad válida
 * \param int* pNumero Puntero donde se almacenará la edad correcta
 * \return Retorna 1 (verdadero) si es una edad válida, 0 (falso) si no o -1 si hubo algún error con los argumentos
 */
int validarEdad(int* pNumero);

/**
 * \brief Valida que el número ingresado sea un precio válido
 * \param float* pResultado Puntero donde se almacenará el precio
 * \return Retorna 1 (verdadero) si es un precio válido, 0 (falso) si no o -1 si hubo algún error con los argumentos
 */
int validarPrecio(float* pResultado);

/**
 * \brief Valida que la cadena recibida sea un teléfono válido
 * \param char* cadena Puntero a la cadena de caracteres a ser analizada
 * \param int limite Valor maximo de caracteres que se pueden ingresar
 * \return Retorna 1 (verdadero) si la cadena es un teléfono, 0 (falso) si no o -1 si hubo algún error con los argumentos
  */
int validarTelefono(char* cadena, int limite);

/**
 * \brief Valida que la cadena recibida sea un celular válido
 * \param char* cadena Puntero a la cadena de caracteres a ser analizada
 * \param int limite Valor maximo de caracteres que se pueden ingresar
 * \return Retorna 1 (verdadero) si la cadena es un celular, 0 (falso) si no o -1 si hubo algún error con los argumentos
 */
int validarCelular(char* cadena, int limite);

/**
 * \brief Valida que la cadena recibida contenga un email válido
 * \param char* cadena Puntero a la cadena de caracteres a ser analizada
 * \param int limite Valor maximo de caracteres que se pueden ingresar
 * \return Retorna 1 (verdadero) si la cadena es un email, 0 (falso) si no o -1 si hubo algún error con los argumentos
 */
int validarEmail(char* cadena, int limite);


/**
 * \brief Valida que la cadena recibida sea una tarjeta de crédito válida
 * \param char* cadena Puntero a la cadena de caracteres a ser analizada
 * \param int limite Valor maximo de caracteres que se pueden ingresar
 * \return Retorna 1 (verdadero) si la cadena es una tarjeta de crédito, 0 (falso) si no o -1 si hubo algún error con los argumentos
 */
int validarTarjetaCredito(char* cadena, int limite);

/**
 * \brief Valida que la cadena recibida contenga una dirección válida
 * \param char* cadena Puntero a la cadena de caracteres a ser analizada
 * \param int limite Valor maximo de caracteres que se pueden ingresar
 * \return Retorna 1 (verdadero) si la cadena es una dirección, 0 (falso) si no o -1 si hubo algún error con los argumentos
 */
int validarDireccion(char* cadena, int limite);

/**
 * \brief Valida que la cadena recibida contenga una altura válida de una dirección
 * \param char* cadena Puntero a la cadena de caracteres a ser analizada
 * \param int limite Valor maximo de caracteres que se pueden ingresar
 * \return Retorna 1 (verdadero) si la cadena es una altura de dirección, 0 (falso) si no o -1 si hubo algún error con los argumentos
 */
int validarDireccionAltura(char* cadena, int limite);

/**
 * \brief Pregunta al usuario si desea continuar y valida que ingres Y/y o N/n
 * \param char* pResultado Puntero donde se almacena el caracter
 * \param char* pMensaje Puntero al mensaje a ser mostrado
 * \param char* pMensajeError Puntero al mensaje a ser mostrado en caso de error
 * \param int reintentos Cantidad de reintentos en caso de error
 * \return Retorna 0 (EXITO) si se obtiene un número entre el rango o -1 (ERROR) si no
*/
int utn_getContinuar(char* pRespuesta, char* pMensaje, char* pMensajeError, int reintentos);

/**
 * \brief Verifica que una cadena de caracteres sea un numero entero sin signo
 * \param char* cadena Puntero donde se almacenará el número ingresado
 * \return Retorna 1 (EXITO) si es un entero; 0(NO) si el string no es un numero; -1 (ERROR) si es nulo
*/
int utn_isIntSinSigno(char* cadena);

/**
 * \brief Funcion que chequea si una cadena es alfanumerica
 * \param char* cadena Puntero a char que se recorre para corroborar si es alfanumerico
 * \return (0) Error (1)  OK
 */
int utn_isAlfanumerico(char *cadena);

/**
 * \brief Funcion que chequea si una cadena es numerica
 * \param char* cadena Puntero a char que se recorre para corroborar si es numerico
 * \return (0) Error (1) OK
 */
int utn_isNumerico(char *cadena);

/**
 * \brief Solicita por medio del archivo stdin el ingreso de una cadena que permite letras y numeros
 * \param char* pMensaje Puntero al mensaje a ser mostrado
 * \param char* pMensajeError Puntero al mensaje a ser mostrado en caso de error
 * \param char* pCadena Puntero a char donde se guarda la cadena
 * \param int limite Valor maximo de caracteres que se pueden ingresar
 * \param int reintentos Cantidad de reintentos en caso de error
 * \return (-1) Error (0)  OK
 */
int utn_getAlfanumerico(char *pMensaje, char *pMensajeError, char *pCadena, int limite, int reintentos);

/**
 * \brief Solicita por medio del archivo stdin el ingreso de una cadena que permite solo numeros
 * \param char* pMensaje Puntero al mensaje a ser mostrado
 * \param char* pMensajeError Puntero al mensaje a ser mostrado en caso de error
 * \param char* pCadena Puntero a char donde se guardar la cadena
 * \param int limite Valor maximo de caracteres que se pueden ingresar
 * \param int reintentos Cantidad de reintentos en caso de error
 * \return (-1) Error (0)  OK
 */
int utn_getStringSoloNumeros(char *pMensaje, char *pMensajeError, char *pCadena, int limite, int reintentos);

/**
 * \brief Valida que la cadena recibida sea una cadena de caracteres sin comas
 * \param char* cadena Puntero a la cadena a validar
 * \return (-1) Error (1)  OK  (0) Caracteres Invalidos
 */
int utn_isString(char* cadena);

#endif
