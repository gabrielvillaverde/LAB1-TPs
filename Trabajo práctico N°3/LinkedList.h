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
    void* pElement; //Puntero al elemento (persona, empleado, etc.)
    struct Node* pNextNode; // Puntero al pr�ximo nodo
}typedef Node;

struct LinkedList
{
    Node* pFirstNode;
    int size; // Cada vez que agrego o elimino un elemento: size++/--
}typedef LinkedList;
#endif

// P�blicas
LinkedList* ll_newLinkedList(void);
int ll_len(LinkedList* this); // Devuelve el valor del campo int size
Node* test_getNode(LinkedList* this, int nodeIndex);
int test_addNode(LinkedList* this, int nodeIndex,void* pElement);
int ll_add(LinkedList* this, void* pElement); // Nos permite incorporar un elemento nuevo a la lista, recibe el puntero a la lista y el elemento que queremos guardar.
void* ll_get(LinkedList* this, int index); // Recibe qu� posici�n de la lista queremos obtener, nos devuelve un puntero a void.
int ll_set(LinkedList* this, int index,void* pElement); // Nos permite guardar en una posici�n de la lista un elemento.
int ll_remove(LinkedList* this,int index); // Le decimos una posici�n de la lista y elimina ese elemento.
int ll_clear(LinkedList* this); // Borra todos los elementos que tiene la lista, pero la lista sigue activa en memoria.
int ll_deleteLinkedList(LinkedList* this); // Borra de memoria la lista.
int ll_indexOf(LinkedList* this, void* pElement); // Le doy un puntero a un elemento, y me devuelve en qu� posici�n est� ese elemento.
int ll_isEmpty(LinkedList* this); // Me avisa si la lista est� vac�a.
int ll_push(LinkedList* this, int index, void* pElement); // Me permite elegir un lugar para agregar un elemento. Insertar en una posici�n un elemento y desplazar el que estaba ah� a la siguiente.
void* ll_pop(LinkedList* this,int index); // Elimina un elemento (los enlaces a ese elemento) y devuelve un puntero a ese elemento
int ll_contains(LinkedList* this, void* pElement); // Me devuelve verdadero si el elemento por el que estoy preguntando est� contenido dentro de la lista.
int ll_containsAll(LinkedList* this,LinkedList* this2); // Me devuelve verdadero si la lista contiene todos los elementos de la otra lista que le estoy pasando como par�metro. Es decir, si una lista est� contenida en otra.
LinkedList* ll_subList(LinkedList* this,int from,int to); // Me permite de una lista original, hacer una sublista de los elementos que quiero de esa lista original.
LinkedList* ll_clone(LinkedList* this); // Me permite duplicar la lista en memoria.
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order); // Me permite ordenar la lista. Se le pasa una funci�n criterio que va a terminar decidiendo el tipo de orden.
