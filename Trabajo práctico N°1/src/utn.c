/*
 * utn.c
 *
 *  Trabajo práctico N°1
 *	Gabriel Villaverde - División H
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"


/**
 * \brief Función que suma
 *\param operadorA es el primer argumento, representado por númeroUno en la función main.
 *\param operadorB es el segundo argumento, representado por númeroDos en la función main.
 *\param puntero del resultado que obtengo en la función, escribe en la dirección de memoria de suma.
 *\return retorna un valor negativo para error y un 0 si salió bien.
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
 * \brief Función que resta
 *\param operadorA es el primer argumento, representado por númeroUno en la función main.
 *\param operadorB es el segundo argumento, representado por númeroDos en la función main.
 *\param puntero del resultado que obtengo en la función, escribe en la dirección de memoria de resta.
 *\return retorna un valor negativo para error y un 0 si salió bien.
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
 * \brief Función que divide
 *\param operadorA es el primer argumento, representado por númeroUno en la función main.
 *\param operadorB es el segundo argumento, representado por númeroDos en la función main.
 *\param puntero del resultado que obtengo en la función, escribe en la dirección de memoria de division.
 *\return retorna un valor negativo para error y un 0 si salió bien.
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
 * \brief Función que multiplica
 *\param operadorA es el primer argumento, representado por númeroUno en la función main.
 *\param operadorB es el segundo argumento, representado por númeroDos en la función main.
 *\param puntero del resultado que obtengo en la función, escribe en la dirección de memoria de multiplicacion.
 *\return retorna un valor negativo para error y un 0 si salió bien.
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
 * \brief Función que obtiene el factorial de un número
 *\param es el argumento del número que recibe la función, tanto para los casos del primer operando como del segundo.
 *\param pResultado es el puntero que escribe en la dirección de memoria de factorial y factorialDos.
 *\return retorna un valor negativo para error y un 0 si salió bien.
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
 * \brief Función que obtiene un número
 *\param pResultado es el puntero que guarda lo escrito en bufferInt y lo escribe en la dirección de memoria de la variable opcion.
 *\param mensaje es el puntero del mensaje que se le pide al usuario.
 *\param mensajeError es el puntero del mensaje de error que se le pide al usuario.
 *\param minimo es el valor mínimo entre todas las opciones que el usuario tiene para ingresar, en este caso 1.
 *\param maximo es el valor maximo entre todas las opciones que el usuario tiene para ingresar, en este caso 5.
 *\param reintentos es la cantidad de reintentos que el usuario tiene para hacer.
 *\return retorna como valor por defecto un -1 para indicar error, pero existe un if que si el número ingresado está entre el rango del mínimo y el máximo, devuelve un return en 0.
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
				break; // Si logre conseguir el número que estaba buscando, tengo que cortar. Si no hago esto, ingresaría el 1000 y seguiría pidiendo números.
			}
			else{
				printf("%s\n", mensajeError);
				reintentos--;
			}
		}while(reintentos >= 0);
	}
	return retorno;
}
