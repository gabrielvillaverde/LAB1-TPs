#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex, void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera din�mica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this = NULL;
    this = (LinkedList*) malloc (sizeof(LinkedList));

    if(this != NULL)
    {
    	this->size = 0;
    	this->pFirstNode = NULL;
    }
    return this;
}

/** \brief Retorna la cantidad de elementos y de nodos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int retorno = -1;

    if(this != NULL)
    {
    	retorno = this->size;
    }
    return retorno;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
 *                        (pNode) Si funciono correctamente
 *
 */

static Node* getNode(LinkedList* this, int nodeIndex)
{

	Node* pNode = NULL;

	if(this != NULL && nodeIndex >= 0 && nodeIndex < ll_len(this))
	{
		pNode = this->pFirstNode;
		for(int i = 0 ; i < nodeIndex ; i++)
		{
			pNode = pNode->pNextNode;
		}
	}
    return pNode;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
 *                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex, void* pElement)
{
	int retorno = -1;

	Node *pNewNode;
	Node *pPrevNode;

	if(this != NULL)
	{
		if(nodeIndex >= 0 && nodeIndex <= ll_len(this)) // nodeIndex <= al tama�o de la LinkedList porque puede ser que agregue uno al final.
		{
			pNewNode = (Node*) malloc(sizeof(Node)); // Reservo memoria para un nuevo nodo.

			pNewNode->pElement = pElement; // Guardo el puntero al elemento dentro del nodo. El elemento que recibo como par�metro ser� el pElement del nuevo nodo.
			pNewNode->pNextNode = NULL; // Indico que el campo que apunta al pr�ximo nodo de la lista sea NULL.

			if(nodeIndex == 0) // Si estoy en la primera posici�n...
			{
				pNewNode->pNextNode = this->pFirstNode; // Hago que el nuevo nodo apunte a la posici�n 0 (al nodo que estaba antes de que yo agregue el nuevo).
				this->pFirstNode = pNewNode; // Hago que en la LL, el puntero al primer nodo apunte al nuevo nodo que agrego.
			}
			else // Si estoy en cualquier otra posici�n que no sea la primera (el medio o el final).
			{
				pPrevNode = getNode(this, nodeIndex - 1); // Me guardo en pPrevNode el nodo previo al �ndice que le paso por argumento, que es la posici�n donde quiero agregar uno.
				pNewNode->pNextNode = pPrevNode->pNextNode; // Estoy haciendo que el nodo nuevo apunte hacia donde estaba apuntando el nodo previo, de lo contrario la lista se romper�a. Por ejemplo, si agrego un nodo entre el 1 y el 2, ese nuevo nodo que agregu� debe apuntar hacia donde apuntaba el 1 (que apuntaba al 2).
				pPrevNode->pNextNode = pNewNode; // El siguiente del nodo previo, ser� el nodo nuevo (el que cree arriba).
			}
			this->size++; // Al agregar uno nuevo, aumento el size de la LinkedList, en se size se guardan la cantidad de nodos que existen.
			retorno = 0;
		}
	}
	return retorno;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                         ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex, void* pElement)
{
	return addNode(this, nodeIndex, pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int retorno = -1;

    if(this != NULL)
    {
    	addNode(this, ll_len(this), pElement);
    	retorno = 0;
    }

    return retorno;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* retorno    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* retorno = NULL;

    Node* pNode = NULL;
    int len = ll_len(this);

    if(this != NULL && index >= 0 && index < len)
    {
    	pNode = getNode(this, index);
		if(pNode != NULL)
		{
			retorno = pNode->pElement;
		}
    }
    return retorno;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index, void* pElement)
{
    int retorno = -1;

    Node* pNode;
    int len = ll_len(this);

    if(this != NULL && index >= 0 && index < len)
    {
    	pNode = getNode(this, index);
    	if(pNode != NULL)
    	{
    		pNode->pElement = pElement;
    		retorno = 0;
    	}
    }
    return retorno;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this, int index)
{
	// Elimina NODOS de la lista.
    int retorno = -1;

    Node* pNodeToRemove = NULL;
    Node* pPreviousNode = NULL;

    int len = ll_len(this);

    if(this != NULL && index >= 0 && index < len)
    {
    	pNodeToRemove = getNode(this, index);
    	if(pNodeToRemove != NULL)
    	{
    		if(index == 0) // Si estoy en la primera posici�n...
    		{
    			this->pFirstNode = pNodeToRemove->pNextNode; // Le paso al primer nodo de la lista, hacia donde apunta el nodo que voy a remover.B
    			// this->pFirstNode = NULL; Esto provocar�a que al borrar el primer nodo de la lista, se rompa la LinkedList.
    		}
    		else
    		{
    			pPreviousNode = getNode(this, index-1); // Me guardo en pPreviousNode el nodo previo al �ndice que le paso como argumento.
    			if(pPreviousNode != NULL) // Si ese nodo previo es distinto de NULL..
    			{
    				pPreviousNode->pNextNode = pNodeToRemove->pNextNode; // Hago que el nodo previo al que voy a remover apunte al que le sigue del que voy a remover.
    				// Es como si en un caso de 4 nodos, voy a borrar el 2, es necesario que el 1 apunte al 3 antes de borrar el 2, porque sino se rompe la lista y no hay manera de enlazar el 1 y el 3.
    			}
    		}
    		free(pNodeToRemove); // Y finalmente ya s� puedo borrar el nodo objetivo.
    		pNodeToRemove = NULL;
    		this->size--;
    		retorno = 0;
    	}
    }
    return retorno;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int retorno = -1;

    int len = ll_len(this);

    if(this != NULL)
    {
    	for(int i = 0; i < len ; i++)
    	{
    		if(ll_remove(this, i) == 0)
    		{
    			retorno = 0;
    		}
    	}
    }
    return retorno;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int retorno = -1;

    if(this != NULL)
    {
    	if(ll_clear(this) == 0)
    	{
    		free(this);
    		retorno = 0;
    	}
    }
    return retorno;
}

/** \brief Busca el �ndice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int retorno = -1;

    int len = ll_len(this);

    if(this != NULL)
    {
    	for(int i = 0; i < len ; i++)
    	{
    		if(ll_get(this, i) == pElement)
    		{
    			retorno = i;
    			break;
    		}
    	}
    }
    return retorno;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int retorno = -1; // Si el puntero a la lista apunta a NULL.

    if(this != NULL) // Si la lista no est� vac�a...
    {
    	retorno = 0;
    	if(ll_len(this) <= 0) // Si la lista est� vac�a...
    	{
    		retorno = 1;
    	}
    }
    return retorno;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int retorno = -1;

    int len = ll_len(this);

    if(this != NULL && index >= 0 && index <= len)
    {
    	if(addNode(this, index, pElement) == 0)
    	{
    		retorno = 0;
    	}
    }
    return retorno;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this, int index) // Junta el get y el remove
{
    void* retorno = NULL;

    int len = ll_len(this);

    if(this != NULL && index >= 0 && index < len)
    {
    	retorno = ll_get(this, index); // ll_get devuelve un puntero a un elemento o NULL.
    	if(ll_remove(this, index) == -1)
    	{
    		retorno = NULL;
    	}
    }
    return retorno;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) Si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int retorno = -1;

    if(this != NULL) // Si el puntero a la lista es distinto de NULL...
    {
    	retorno = 0;
		if(ll_indexOf(this, pElement) >= 0) // Y adem�s el �ndice que devuelve indexOf es mayor o igual a 0.
		{
			retorno = 1;
		}
    }
    return retorno;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) Si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this, LinkedList* this2)
{
    int retorno = -1;

    void* pElement;

    int contadorThis2 = 0;

    if(this != NULL && this2 != NULL)
    {
        retorno = 0;

        if(ll_len(this) >= ll_len(this2))
        {
            for(int i = 0 ; i < ll_len(this2) ; i++)
            {
            	pElement = ll_get(this2, i);
                if(ll_contains(this, pElement) == 1)
                {
                    contadorThis2++;
                }
            }
            if(contadorThis2 == ll_len(this))
			{
            	retorno = 1;
			}
        }
    }
    return retorno;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this, int from, int to)
{
    LinkedList* cloneArray = NULL;

    void* pElement;

    int len = ll_len(this);

    if(this != NULL && from >= 0 && from <= len && to > from && to <= len)
    {
    	cloneArray = ll_newLinkedList();
    	if(cloneArray != NULL)
    	{
    		for(int i = from ; i <= to ; i++)
    		{
        		pElement = ll_get(this, i);
        		ll_add(cloneArray, pElement);
    		}
    	}
    }
    return cloneArray;
}

/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la lista es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;

    if(this != NULL)
    {
    	cloneArray = ll_subList(this, 0, ll_len(this));
    }
    return cloneArray;
}

/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void*, void*), int order)
{
	int retorno = -1;

	void* pFirstElement;
	void* pSecondElement;

	if(this != NULL && pFunc != NULL && (order == 1 || order == 0))
	{
		for(int i = 0 ; i < ll_len(this) - 1 ; i++)
		{
			for(int j = i + 1 ; j < ll_len(this) ; j++)
			{
				pFirstElement = ll_get(this, i);
				pSecondElement = ll_get(this, j);
				if ((pFunc(pFirstElement, pSecondElement) > 0 && order) || (pFunc(pFirstElement, pSecondElement) < 0 && !order))
				{
					ll_set(this, i, pSecondElement);
					ll_set(this, j, pFirstElement);
				}
			}
		}
		retorno = 0;
	}
	return retorno;
}

/**
 * \brief Recorre la lista, analizando cada elemento para que se realice una tarea.
 *
 * \this Puntero al espacio de memoria donde se empieza la lista.
 * \pFuncGenerica Puntero al espacio de memoria donde comienza el c�digo de dicha funci�n.
 * \return Retorna -1 los parametros recibidos son NULL o si al menos un elemento no cumple con el criterio establecido.
 * 				   Retorna 0 si ok.
 *
 */
int ll_map(LinkedList* this, int (*pFunc)(void*))
{
	int retorno = -1;

	void* pElement = NULL;

	if(this != NULL && pFunc != NULL)
	{
		retorno = 0;
		for(int i = 0 ; i < ll_len(this) ; i++) /* Itera la lista y por cada elemento, invoca a la funci�n que recibe como par�metro. */
		{
			pElement = ll_get(this,i);
			if(pFunc(pElement) < 0)
			{
				retorno = -1;
			}
		}
	}
	return retorno;
}

LinkedList* ll_filter(LinkedList* this, int (*pFunc)(void*))
{
	LinkedList* pFilteredList = NULL;
	void* pElement;
    int len = ll_len(this);

	if(this != NULL && pFunc != NULL)
	{
		pFilteredList = ll_newLinkedList(); // Devuelvo una lista nueva
		if(pFilteredList != NULL)
		{
			for(int i = 0 ; i < len ; i++)
			{
				pElement = ll_get(this, i); // Realizo un recorrido de la lista original.
				if(pFunc(pElement)) // Si la funci�n gen�rica devuelve TRUE...
				{
					ll_add(pFilteredList, pElement); // Cargo en la lista filtrada el elemento.
				}
			}
		}
	}
    return pFilteredList;
}

LinkedList* ll_filter2(LinkedList* this, int (*pFunc)(void*,void*), void* argumento)
{
	LinkedList* pFilteredList = NULL;
	void* pElement;
    int len = ll_len(this);

	if(this != NULL && pFunc != NULL)
	{
		pFilteredList = ll_newLinkedList(); // Devuelvo una lista nueva
		if(pFilteredList != NULL)
		{
			for(int i = 0 ; i < len ; i++) // Realizo un recorrido de la lista original.
			{
				pElement = ll_get(this, i);
				if(pFunc(pElement, argumento)) // Si la funci�n gen�rica devuelve TRUE...
				{
					ll_add(pFilteredList, pElement); // Cargo en la lista filtrada el elemento.
				}
			}
		}
	}
    return pFilteredList;
}

LinkedList* ll_filter3(LinkedList* this, int (*pFunc)(void*, void*, void*), void* argumentoUno, void* argumentoDos)
{
	LinkedList* pFilteredList = NULL;
	void* pElement;
    int len = ll_len(this);

	if(this != NULL && pFunc != NULL)
	{
		pFilteredList = ll_newLinkedList(); // Devuelvo una lista nueva
		if(pFilteredList != NULL)
		{
			for(int i = 0 ; i < len ; i++) // Realizo un recorrido de la lista original.
			{
				pElement = ll_get(this, i);
				if(pFunc(pElement, argumentoUno, argumentoDos)) // Si la funci�n gen�rica devuelve TRUE...
				{
					ll_add(pFilteredList, pElement); // Cargo en la lista filtrada el elemento.
				}
			}
		}
	}
    return pFilteredList;
}

int ll_reduce(LinkedList* this, int (*pFunc)(void*, int, int))
{
	void* pElement = NULL;
	int valor = 0;

	if(this != NULL && pFunc != NULL)
	{
		for(int i = 0 ; i < ll_len(this) ; i++)
		{
			pElement = ll_get(this, i);
			valor = pFunc(pElement, valor, i);
		}
	}
	return valor;
}

/** \brief Recorre la lista y va acumulando valores del tipo int.
 * \param this LinkedList* Puntero a la lista
 * \param int (*pFunc) Puntero a la funci�n criterio
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                        ( 0) Si ok
 */
int ll_reduceInt(LinkedList* this, int (*pFunc)(void*,void*), void* argumento)
{
	int retorno = 0;

	void* pElement;

	if(this != NULL && pFunc != NULL)
	{
		for (int i = 0 ; i < ll_len(this) ; i++)
		{
			pElement = ll_get(this, i);
			retorno += pFunc(pElement, argumento);
		}
	}
	return retorno;
}

/** \brief Recorre la lista y va acumulando valores del tipo float.
 * \param this LinkedList* Puntero a la lista
 * \param int (*pFunc) Puntero a la funci�n criterio
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                        ( 0) Si ok
 */
float ll_reduceFloat(LinkedList* this, float (*pFunc)(void*))
{
	int retorno = -1;

	void* pElement;

	if(this != NULL && pFunc != NULL)
	{
		for (int i = 0 ; i < ll_len(this) ; i++)
		{
			pElement = ll_get(this, i);
			retorno += pFunc(pElement);
		}
	}
	return retorno;
}

/** \brief Cuenta los elementos de la lista de acuerdo a la funci�n criterio recibida como par�metro.
 *
 * \param this LinkedList* Puntero a la lista
 * \param int* pFuncArgumento Funci�n criterio que determina qu� particularidad tienen loe elementos que voy a contar.
 * \return int Retorna  -1 si el puntero a la lista es NULL
 *                       o la cantidad total acumulada si sali� todo ok.
 */
int ll_count(LinkedList* this, int(*pFunc)(void*))
{
	void* pElement;
	int acum = 0;
	int retorno = -1;

	if(this != NULL && pFunc != NULL)
	{
		for(int i = 0 ; i < ll_len(this) ; i++)
		{
			pElement = ll_get(this, i);
			if(pFunc(pElement) == 1)
			{
				acum = acum + pFunc(pElement);
				retorno = acum;
			}
		}
	}
	return retorno;
}
