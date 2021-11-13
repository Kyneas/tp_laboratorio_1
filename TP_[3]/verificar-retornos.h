#include <stdio.h>

#ifndef VERIFICAR_RETORNOS_H_
#define VERIFICAR_RETORNOS_H_

void retornos_loadFromAny(int estado, int *retorno);
void retornos_addEmployee (int estado, int *retorno);
void retornos_editEmployee (int estado, int *retorno);
void retornos_removeEmployee (int estado, int *retorno);
void retornos_ListEmployee (int estado);
void retornos_sortEmployee (int estado, int *retorno);
void retornos_saveAsAny (int estado);

#endif /* VERIFICAR_RETORNOS_H_ */
