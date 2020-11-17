#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h" // Tuve que correr la carpeta desde "inc" a "src" para que la reconozca.


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
// Explicaci�n: 8:44 hs (clase 21)
static Node* getNode(LinkedList* this, int nodeIndex)
{

	Node* pNode = NULL; // Creamos un nodo para devolver.

	if(this != NULL && nodeIndex >= 0 && nodeIndex < ll_len(this))
	{
		pNode = this->pFirstNode; // Le cargamos al nodo para devolver el valor del primer nodo.
		// La cantidad de veces que tenemos que iterar depende del �ndice que quiero devolver. Si el nodeIndex vale 2, tengo que iterar 2 veces.
		for(int i = 0 ; i < nodeIndex ; i++) // Si nodeIndex vale 0, NO VA A ENTRAR AL FOR. A medida que voy recorriendo la lista...
		{
			pNode = pNode->pNextNode; // Me guardo en la variable pNode el valor del campo del pr�ximo nodo.
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
	Node *pActualNode;

	if(this != NULL)
	{
		if(nodeIndex >= 0 && nodeIndex <= ll_len(this)) // NodeIndex representa la posici�n del nodo que estoy agregando, si es igual al ll_len lo dejo pasar, ya que puede ser que est� ingresando uno nuevo al final.
		{
			pNewNode = (Node*) malloc(sizeof(Node)); // Le pido al sistema que reserve memoria para un nuevo nodo
			pNewNode->pElement = pElement; // Escribo el elemento en el campo elemento del nodo.
			pNewNode->pNextNode = NULL;

			if(nodeIndex == 0) // Si estoy en la primera posici�n de la Linked List
			{
				// Explicaci�n: HORA 10:00
				pNewNode->pNextNode = this->pFirstNode;
				this->pFirstNode = pNewNode;
			}
			else
			{	// Explicaci�n: 10:30 HS. Recomendaci�n: dibujarlo en una hoja.
				pActualNode = getNode(this, nodeIndex - 1); // A getNode le paso la lista (this) y nodeIndex -1.
				pNewNode->pNextNode = pActualNode->pNextNode; // Indico que el nodo nuevo tiene que apuntar al pr�ximo nodo. // Hora 7:52 (clase 23)
				pActualNode->pNextNode = pNewNode;
			}
			this->size++; // En size se guarda la cantidad de nodos que existen.
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
    		if(index == 0)
    		{
    			this->pFirstNode = NULL;
    		}
    		else
    		{
    			pPreviousNode = getNode(this, index-1);
    			if(pPreviousNode != NULL)
    			{
    				pPreviousNode->pNextNode = pNodeToRemove->pNextNode;
    			}
    		}
    		free(pNodeToRemove);
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
	// https://vvcap.com/ha4AtUWko pero el to tiene que ser <= al ll_len
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
	// * Hay que preguntar si this != NULL y pFunc != NULL
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

// Explicaci�n, hora 20:00 de la clase (no grabaron)
// https://vvcap.com/7rPTsukGs

/* toma cada uno de los elementos q estan en la lista y se los pasa 1 por 1 a una
funcion, a la funcion que le esty pasand como argumento a la propia funcion map
*/
/* Ac� cada llamada a funci�n se ejecuta de forma independiente,
 * entra y sale y no deja ning�n valor que persista en ning�n lado, a diferencia
 * de reduce.
 */

int ll_map(LinkedList* this, int (*pFunc)(void*))
{
    int retorno =-1;

    /* Itera la lista, y por cada elemento, invoco a la funci�n. */


    return retorno;

}

// Hora: 9:39
/* Recorre el arrayList y debe llamar a una funci�n criterio que le va a decir
 * si a ese elemento hay o no que quitarlo del arrayList.
 * La funci�n criterio devolver� verdadero o falso.
 * Recibe una funci�n y me devuelve una lista nueva por valor de retorno.
 * Se puede reducir la original o agregar una nueva. */

LinkedList* ll_filter(LinkedList* this, int (*pFunc)(void*))
{	// Explicaci�n: Hora 8:58 (clase 23), pero lo hace con el remove
	// Hacer un ll_remove no significa borrar el elemento, significa borrar el nodo que contiene la direcci�n de memoria que apunta a ese elemento.
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
				if(pFunc(pElement)) // Si la funci�n devuelve TRUE...
				{
					ll_add(pFilteredList, pElement); // Cargo en la lista filtrada el elemento.
				}
			}
		}
	}
    return pFilteredList;
}

// Hora: 10:23
/* Reduce una lista a un n�mero. */
/* Sirven para obtener promedio de edades de la lista de empleados,
 * suma de todos los salarios de la lista de empleados, etc�tera.
 * Llaman a una funci�n, la funci�n devuelve un valor, y estas funciones
 * acumulan ese valor. Por ejemplo, de mis empleados, cu�ntos son
 * mayores de 18 a�os, la funci�n criterio que yo paso se fija si es
 * mayor de 18 a�os, si es mayor de 18 devuelve un 1.
 * Como se que reduceFloat acumula esos 1, la respuesta es cu�ntos
 * son mayores de 18 a�os.
 * Despu�s cu�ntos trabajan en determinado sector. Entonces
 * la funci�n criterio devuelve un 1 cuando trabaja en sistemas, y
 * la funci�n reduce me acumula cu�ntos empleados trabajan en sistemas.
 */
//float ll_reduceFloat(LinkedList* this, float (*pFunc)(void*))
//int ll_reduceInt(LinkedList* this, int (*pFunc)(void*))

// Pregunta examen prog: 9:10 (clase 23)
//int ll_reduce(LinkedList* this, int(*pFunc)(void*))
int ll_reduce(LinkedList* this, int (*pFunc)(void*, int, int))
{
	int index;
	void* auxElemento = NULL;
	int valor = 0;

	if(this != NULL && pFunc != NULL)
	{
		for(index=0;index < ll_len(this);index++)
		{
			auxElemento = ll_get(this, index);
			valor = pFunc(auxElemento,valor,index);
		}
	}

	return valor;
}

/** \brief Cuenta los elementos de la lista de acuerdo a la funci�n criterio recibida como par�metro.
 *
 * \param this LinkedList* Puntero a la lista
 * \param int* pFuncArgumento Funci�n criterio que determina qu� particularidad tienen loe elementos que voy a contar.
 * \return int Retorna  -1 si el puntero a la lista es NULL
 *                       o la cantidad total acumulada si sali� todo ok.
 */
int ll_count(LinkedList* this, int(*pFuncArgumento)(void*))
{
	int i;
	void* pElement;
	int acum = 0;
	int retorno = -1;

	if(this != NULL && pFuncArgumento != NULL)
	{
		for(i=0;i<ll_len(this);i++)
		{
			pElement = ll_get(this,i);
			if(pFuncArgumento(pElement)==1)
			{
				acum = acum + pFuncArgumento(pElement);
				retorno = acum;
			}
		}
	}
	return retorno;
}

/* Para despu�s del jueves. */
// int ll_findInt(LinkedList* this, int (*pFunc)(void*, int))
