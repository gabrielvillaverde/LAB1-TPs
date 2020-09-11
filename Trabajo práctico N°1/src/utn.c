/*
 * utn.c
 *
 *  Trabajo práctico N°1
 *	Gabriel Villaverde - División H
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

int sumar(float operadorA, float operadorB, float *pResultado) {

	int retorno = -1;

	*pResultado = operadorA + operadorB;
	retorno = 0;

	return retorno;
}

int restar(float operadorA, float operadorB, float *pResultado) {

	int retorno = -1;
	*pResultado = operadorA - operadorB;
	retorno = 0;

	return retorno;
}

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

int multiplicar(float operadorA, float operadorB, float *pResultado) {

	int retorno = -1;

	*pResultado = operadorA * operadorB;
	retorno = 0;

	return retorno;
}

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
