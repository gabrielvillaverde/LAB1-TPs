/*
 * utn.c
 *
 *  Trabajo pr�ctico N�1
 *	Gabriel Villaverde - Divisi�n H
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"


/**
 * \brief Funci�n que suma
 *\param operadorA es el primer argumento, representado por n�meroUno en la funci�n main.
 *\param operadorB es el segundo argumento, representado por n�meroDos en la funci�n main.
 *\param puntero del resultado que obtengo en la funci�n, escribe en la direcci�n de memoria de suma.
 *\return retorna un valor negativo para error y un 0 si sali� bien.
 */
int sumar(float operadorA, float operadorB, float *pResultado) {

	int retorno = -1;

	if(pResultado != NULL)
	{

		*pResultado = operadorA + operadorB;
		retorno = 0;
	}

	return retorno;
}

/**
 * \brief Funci�n que resta
 *\param operadorA es el primer argumento, representado por n�meroUno en la funci�n main.
 *\param operadorB es el segundo argumento, representado por n�meroDos en la funci�n main.
 *\param puntero del resultado que obtengo en la funci�n, escribe en la direcci�n de memoria de resta.
 *\return retorna un valor negativo para error y un 0 si sali� bien.
 */
int restar(float operadorA, float operadorB, float *pResultado) {

	int retorno = -1;
	if(pResultado != NULL)
	{
		*pResultado = operadorA - operadorB;
		retorno = 0;
	}
	return retorno;
}


/**
 * \brief Funci�n que divide
 *\param operadorA es el primer argumento, representado por n�meroUno en la funci�n main.
 *\param operadorB es el segundo argumento, representado por n�meroDos en la funci�n main.
 *\param puntero del resultado que obtengo en la funci�n, escribe en la direcci�n de memoria de division.
 *\return retorna un valor negativo para error y un 0 si sali� bien.
 */
int dividir (int operador1, int operador2, float* pResultado) {

	int retorno = -1;
	float resultado;
	if(pResultado != NULL && operador2 != 0){
		resultado = (float) operador1 / operador2;
		*pResultado = resultado;
		retorno = 0;
	}
	return retorno;
}

/**
 * \brief Funci�n que multiplica
 *\param operadorA es el primer argumento, representado por n�meroUno en la funci�n main.
 *\param operadorB es el segundo argumento, representado por n�meroDos en la funci�n main.
 *\param puntero del resultado que obtengo en la funci�n, escribe en la direcci�n de memoria de multiplicacion.
 *\return retorna un valor negativo para error y un 0 si sali� bien.
 */
int multiplicar(float operadorA, float operadorB, float *pResultado) {

	int retorno = -1;
	if(pResultado != NULL)
	{
		*pResultado = operadorA * operadorB;
		retorno = 0;
	}
	return retorno;
}

/**
 * \brief Funci�n que obtiene el factorial de un n�mero
 *\param es el argumento del n�mero que recibe la funci�n, tanto para los casos del primer operando como del segundo.
 *\param pResultado es el puntero que escribe en la direcci�n de memoria de factorial y factorialDos.
 *\return retorna un valor negativo para error y un 0 si sali� bien.
 */
int funcionFactorial(int numero, long *pResultado) {

	int retorno = -1;

	long factorial = 1;

	for(int i = numero; i>= 1; i--)
	{
		factorial = factorial * i;
	}

	*pResultado = factorial;
	retorno = 0;

	return retorno;
}

/**
 * \brief Funci�n que obtiene un n�mero
 *\param pResultado es el puntero que guarda lo escrito en bufferInt y lo escribe en la direcci�n de memoria de la variable opcion.
 *\param mensaje es el puntero del mensaje que se le pide al usuario.
 *\param mensajeError es el puntero del mensaje de error que se le pide al usuario.
 *\param minimo es el valor m�nimo entre todas las opciones que el usuario tiene para ingresar, en este caso 1.
 *\param maximo es el valor maximo entre todas las opciones que el usuario tiene para ingresar, en este caso 5.
 *\param reintentos es la cantidad de reintentos que el usuario tiene para hacer.
 *\return retorna como valor por defecto un -1 para indicar error, pero existe un if que si el n�mero ingresado est� entre el rango del m�nimo y el m�ximo, devuelve un return en 0.
 */
int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{

	int retorno = -1;
	int bufferInt;

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{
		do
		{
			printf("%s\n", mensaje);
			fflush(stdin);
			scanf("%d", &bufferInt);
			if(bufferInt >= minimo && bufferInt <= maximo)
			{
				retorno = 0;
				*pResultado = bufferInt;
				break; // Si logre conseguir el n�mero que estaba buscando, tengo que cortar. Si no hago esto, ingresar�a el 1000 y seguir�a pidiendo n�meros.
			}
			else{
				printf("%s\n", mensajeError);
				reintentos--;
			}
		}while(reintentos >= 0);
	}
	return retorno;
}
