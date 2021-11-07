/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef __LINKEDLIST
#define __LINKEDLIST
struct Node
{
    void* pElement;
    struct Node* pNextNode;
}typedef Node;

struct LinkedList
{
    Node* pFirstNode;
    int size;
}typedef LinkedList;
#endif



//Publicas
LinkedList* ll_newLinkedList(void);//Constructor, crea la lista en memoria
int ll_len(LinkedList* this);//Devuelve el largo de la lista
Node* test_getNode(LinkedList* this, int nodeIndex);
int test_addNode(LinkedList* this, int nodeIndex,void* pElement);
int ll_add(LinkedList* this, void* pElement);//Agrega un elemento a la linkedlist
void* ll_get(LinkedList* this, int index);//Retorna el elemento de una posicion especifica
int ll_set(LinkedList* this, int index,void* pElement);//Reemplaza un elemento por otro
int ll_remove(LinkedList* this,int index);//Remueve un elemento del indice especificado
int ll_clear(LinkedList* this);//Limpia toda la lista, la vacia, un remove de all
int ll_deleteLinkedList(LinkedList* this);//Borra la linkedlist
int ll_indexOf(LinkedList* this, void* pElement);//Retorna el indice de un elemento
int ll_isEmpty(LinkedList* this);//Verifica si el linkedlist esta vacio
int ll_push(LinkedList* this, int index, void* pElement);//Agrega un elemento en el indice especificado
void* ll_pop(LinkedList* this,int index);//Remueve un elemento y lo retorna
int ll_contains(LinkedList* this, void* pElement);//Verifica si un elemento existe en la lista
int ll_containsAll(LinkedList* this,LinkedList* this2);//Verifica si una lista esta en otra lista
LinkedList* ll_subList(LinkedList* this,int from,int to);//Crea una lista desde un indice hasta otro indice
LinkedList* ll_clone(LinkedList* this);//Clona la lista
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order);

