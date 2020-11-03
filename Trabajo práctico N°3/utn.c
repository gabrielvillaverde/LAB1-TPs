/*
 * utn.c
 *
 *  Created on: 29 oct. 2020
 *      Author: Hzkr
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"

/**
 * \brief Función que guarda el ingreso de una cadena y remueve el salto de línea
 * \param pCadena: El puntero a char del cual sacar el salto de línea
 * \param len: El size limite de la cadena
 * \return (-1) Error (0) todo OK
 */
int myGets(char *pCadena, int len)
{
    int retorno = -1;
    char bufferString[4096];
    fflush(stdin);

    if(pCadena != NULL && len > 0 && fgets(bufferString, sizeof(bufferString), stdin) != NULL)
    {
        if (bufferString[0] == '\n')
        {
            printf("\nError, solo ingresó un ENTER.\n");
        }
        else
        {
            bufferString[strnlen(bufferString, sizeof(bufferString)) - 1] = '\0';
            if(strnlen(bufferString, sizeof(bufferString)) <= len)
            {
                strncpy(pCadena, bufferString, len);
                retorno = 0;
            }
        }
    }
    return retorno;
}

/**
 * \brief Función que chequea si una cadena es alfabética.
 * \param pCadena: El puntero a char que se recorre para corroborar si es alfabetico
 * \return (-1) Error (0) todo OK
 */
int utn_isAlphabetic(char *pCadena)
{
    int output = 1;
    if(pCadena != NULL){
        for(int x = 0 ; pCadena[x] != '\0' ; x++)
        {
            if((pCadena[x] < 'A' || pCadena[x] > 'z') && (pCadena[x] > 'Z' || pCadena[x] < 'a') && pCadena[x] != ' ' && pCadena[x] != '-')
            {
                output = 0;
                break;
            }
        }
    }
    return output;
}

/**
 * \brief Función que solicita por stdin el ingreso de una cadena
 * \param msg: El puntero a char que solicita el ingreso de una cadena
 * \param msgError: El puntero a char que informa de un error
 * \param pCadena: El puntero a char donde se guardar la cadena
 * \param limite: El limite de la cadena
 * \param reintentos: La cantidad de veces que el usuario puede reintentar en caso de error
 * \return (-1) Error (0) todo OK
 */
int utn_getString(char *msg, char *msgError, char *pCadena, int limite, int reintentos)
{
    int retorno = -1;
    if (msg != NULL && msgError != NULL && pCadena != NULL && limite > 0 && reintentos > 0)
    {
        do
        {
            printf("%s", msg);
            if (!(myGets(pCadena, limite)) && utn_isAlphabetic(pCadena))
            {
            	retorno = 0;
            } else
            {
                reintentos--;
                if (reintentos > 0)
                {
                    printf("\nLe quedan %d reintentos.\n", reintentos);
                }
            }
        } while (retorno != 0 && reintentos > 0);
    }
    return retorno;
}

/**
 * \brief Función que chequea si una cadena es alfanumerica
 * \param pCadena: El puntero a char que se recorre para corroborar si es alfabetico
 * \return (0) Error (1) todo OK
 */
int utn_isAlphanumeric(char *pCadena)
{
    int retorno = 1;
    if(pCadena !=NULL)
    {
        for(int x = 0 ; pCadena[x] != '\0' ; x++)
        {
            if(
               (pCadena[x] < '0' || pCadena[x] > 'z')
            && (pCadena[x] > '9' || pCadena[x] < 'A')
            && (pCadena[x] > 'Z' || pCadena[x] < 'a')
            && pCadena[x] != ' ')
            {
            	retorno = 0;
                break;
            }
        }
    }
    return retorno;
}

/**
 * \brief Función que chequea si una cadena es numérica
 * \param pCadena: El puntero a char que se recorre para corroborar si es alfabetico
 * \return (0) Error (1) todo OK
 */
int utn_isNumeric(char *pCadena)
{
    int retorno = 1;
    if(pCadena !=NULL)
    {
        for(int x = 0 ; pCadena[x] != '\0' ; x++)
        {
            if(pCadena[x] < '0' || pCadena[x] > '9')
            {
            	retorno = 0;
                break;
            }
        }
    }
    return retorno;
}
/**
 * \brief Función que solicita por stdin el ingreso de una cadena que permite letras y números
 * \param msg: El puntero a char que solicita el ingreso de una cadena
 * \param msgError: El puntero a char que informa de un error
 * \param pCadena: El puntero a char donde se guardar la cadena
 * \param limite: El limite de la cadena
 * \param reintentos: La cantidad de veces que el usuario puede reintentar en caso de error
 * \return (-1) Error (0) todo OK
 */
int utn_getStringWithNumbers(char *msg, char *msgError, char *pCadena, int limite, int reintentos)
{
    int retorno = -1;
    if (msg != NULL && msgError != NULL && pCadena != NULL && limite > 0 && reintentos > 0)
    {
        do
        {
            printf("%s", msg);
            if (!(myGets(pCadena, limite)) && utn_isAlphanumeric(pCadena))
            {
                for(int x = 0; x<limite; x++)
                {
                    pCadena[x] = toupper(pCadena[x]);
                }
                retorno = 0;
            }
            else
            {
                reintentos--;
                if (reintentos > 0)
                {
                    printf("\nLe quedan %d reintentos.\n", reintentos);
                }
            }
        } while (retorno != 0 && reintentos > 0);
    }
    return retorno;
}

/**
 * \brief Función que solicita por stdin el ingreso de una cadena que permite solo números
 * \param msg: El puntero a char que solicita el ingreso de una cadena
 * \param msgError: El puntero a char que informa de un error
 * \param pCadena: El puntero a char donde se guardar la cadena
 * \param limite: El limite de la cadena
 * \param reintentos: La cantidad de veces que el usuario puede reintentar en caso de error
 * \return (-1) Error (0) todo OK
 */
int utn_getStringWithOnlyNumbers(char *msg, char *msgError, char *pCadena, int limite, int reintentos)
{
    int retorno = -1;
    if(msg != NULL && msgError != NULL && pCadena != NULL && limite > 0 && reintentos > 0)
    {
        do
        {
            printf("%s", msg);
            if (!(myGets(pCadena, limite)) && utn_isNumeric(pCadena))
            {
                for(int x = 0; x<limite; x++)
                {
                    pCadena[x] = toupper(pCadena[x]);
                }
                retorno = 0;
            }
            else
            {
                reintentos--;
                if (reintentos > 0)
                {
                    printf("\nLe quedan %d reintentos.\n", reintentos);
                }
            }
        }while (retorno != 0 && reintentos > 0);
    }
    return retorno;
}

/**
 * \brief Función que solicita por stdin el ingreso de una cadena que permite letras, numeros y simbolos
 * \param msg: El puntero a char que solicita el ingreso de una cadena
 * \param msgError: El puntero a char que informa de un error
 * \param pCadena: El puntero a char donde se guardar la cadena
 * \param limite: El limite de la cadena
 * \param reintentos: La cantidad de veces que el usuario puede reintentar en caso de error
 * \return (-1) Error (0) todo OK
 */
int utn_getStringWithNumbersAndSymbols(char *msg, char *msgError, char *pCadena, int limite, int reintentos)
{
    int retorno = -1;
    if(msg != NULL && msgError != NULL && pCadena != NULL && limite > 0 && reintentos > 0)
    {
        do
        {
            printf("%s", msg);
            if (!(myGets(pCadena, limite)))
            {
                for(int x = 0 ; x<limite ; x++)
                {
                    pCadena[x] = tolower(pCadena[x]);
                }
                retorno = 0;
            }
            else
            {
                reintentos--;
                if(reintentos > 0)
                {
                    printf("\nLe quedan %d reintentos.\n", reintentos);
                }
            }
        }while (retorno != 0 && reintentos > 0);
    }
    return retorno;
}

/**
 * \brief Función que solicita por stdin el ingreso de un numero entero
 * \param msg: El puntero a char que solicita el ingreso de una cadena
 * \param msgError: El puntero a char que informa de un error
 * \param pResultado: El puntero a int donde se guardara el numero ingresado
 * \param reintentos La cantidad de veces que el usuario puede reintentar en caso de error
 * \return (-1) Error (0) todo OK
 */
int utn_getInt(char *msg, char *msgError, int *pResultado, int reintentos)
{
    int retorno = -1;
    char bufferString[50];

    if(msg != NULL && msgError != NULL && pResultado != NULL && reintentos > 0)
    {
        do
        {
            printf("%s", msg);
            if(!(myGets(bufferString, sizeof(bufferString))) && utn_isIntNumber(bufferString))
            {
            	retorno = 0;
                *pResultado = atoi(bufferString);
            }
            else
            {
                reintentos--;
                if (reintentos > 0)
                {
                    printf("\nLe quedan %d reintentos.\n", reintentos);
                }
            }
        }while (retorno != 0 && reintentos > 0);
    }
    return retorno;
}

/**
 * \brief Función que solicita por stdin el ingreso de un numero entero
 * \param msg: El puntero a char que solicita el ingreso de una cadena
 * \param msgError: El puntero a char que informa de un error
 * \param pResultado: El puntero a int donde se guardara el numero ingresado
 * \param min: El valor minimo permitido
 * \param max: El valor maximo permitido
 * \param reintentos La cantidad de veces que el usuario puede reintentar en caso de error
 * \return (-1) Error (0) todo OK
 */
int utn_getIntConMinMax(char *msg, char *msgError, int *pResultado, int min, int max, int reintentos)
{
    int retorno = -1;
    char bufferString[50];

    if(msg != NULL && msgError != NULL && pResultado != NULL && reintentos > 0)
    {
        do
        {
            printf("%s", msg);
            if(!(myGets(bufferString, sizeof(bufferString))) && (utn_isIntNumber(bufferString)) && (atoi(bufferString) >= min && atoi(bufferString) <= max))
            {
            	retorno = 0;
                *pResultado = atoi(bufferString);
            }
            else
            {
                reintentos--;
                if (reintentos > 0)
                {
                    printf("\nLe quedan %d reintentos.\n", reintentos);
                }
            }
        }while(retorno != 0 && reintentos > 0);
    }
    return retorno;
}

/**
 * \brief Función que valida si una cadena es un número entero
 * \param numberToValidate: El puntero a char que la funcion debe validar
 * \return (-1) Error (0) todo OK
 */
int utn_isIntNumber(char *numberToValidate)
{
    int retorno = 0;
    int contadorSignoNegativo = 0;

    if (numberToValidate != NULL)
    {
        for (int x = 0; numberToValidate[x] != '\0'; x++)
        {
            if ((numberToValidate[x] >= '0' && numberToValidate[x] <= '9')
                    || numberToValidate[x] == '-')
            {
                if (numberToValidate[x] == '-')
                {
                    contadorSignoNegativo++;
                }
                retorno = 1;
            }
            else
            {
            	retorno = 0;
                break;
            }
            if(contadorSignoNegativo > 1)
            {
            	retorno = 0;
                break;
            }
        }
    }
    return retorno;
}

/**
 * \brief Función que solicita por stdin el ingreso de un numero de punto flotante
 * \param msg: El puntero a char que solicita el ingreso de una cadena
 * \param msgError: El puntero a char que informa de un error
 * \param pResultado: El puntero a float donde se guardara el numero ingresado
 * \param reintentos La cantidad de veces que el usuario puede reintentar en caso de error
 * \return (-1) Error (0) todo OK
 */
int utn_getFloat(char *msg, char *msgError, float *pResultado, int reintentos) {
    int output = -1;
    char bufferFloat[20];
    if (msg != NULL && msgError != NULL && pResultado != NULL
            && reintentos > 0) {
        do {
            printf("%s", msg);
            if (!(myGets(bufferFloat, sizeof(bufferFloat)))
                    && utn_isFloatNumber(bufferFloat)) {
                output = 0;
                *pResultado = atof(bufferFloat);
            } else {
                reintentos--;
                if (reintentos > 0) {
                    printf("\nLe quedan %d reintentos.\n", reintentos);
                }
            }
        } while (output != 0 && reintentos > 0);
    }
    return output;
}

/**
 * \fn int utn_getFloatConMinMax(char*, char*, float*, float, float, int)
 * \brief Funcion que solicita por stdin el ingreso de un numero de punto flotante
 *
 * \param msg: El puntero a char que solicita el ingreso de una cadena
 * \param msgError: El puntero a char que informa de un error
 * \param pResultado: El puntero a float donde se guardara el numero ingresado
 * \param min: El valor minimo permitido
 * \param max: El valor maximo permitido
 * \param reintentos La cantidad de veces que el usuario puede reintentar en caso de error
 * \return (-1) Error (0) todo OK
 */
int utn_getFloatConMinMax(char *msg, char *msgError, float *pResultado, float min, float max, int reintentos) {
    int output = -1;
    char bufferFloat[20];
    if (msg != NULL && msgError != NULL && pResultado != NULL
            && reintentos > 0) {
        do {
            printf("%s", msg);
            if (!(myGets(bufferFloat, sizeof(bufferFloat)))
                    && utn_isFloatNumber(bufferFloat)
                    && (atof(bufferFloat) >= min && atof(bufferFloat) <= max)) {
                output = 0;
                *pResultado = atof(bufferFloat);
            } else {
                reintentos--;
                if (reintentos > 0) {
                    printf("\nLe quedan %d reintentos.\n", reintentos);
                }
            }
        } while (output != 0 && reintentos > 0);
    }
    return output;
}

/**
 * \fn int utn_isFloatNumber(char*)
 * \brief Funcion que valida si una cadena es un numero de punto flotante
 *
 * \param numberToValidate: El puntero a char que la funcion debe validar
 * \return (-1) Error (0) todo OK
 */
int utn_isFloatNumber(char *numberToValidate)
{
    int retorno = 0;

    unsigned int contadorSignoNegativo = 0;
    unsigned int contadorPunto = 0;

    if (numberToValidate != NULL)
    {
        for (int x = 0; numberToValidate[x] != '\0'; x++)
        {
            if ((numberToValidate[x] >= '0' && numberToValidate[x] <= '9')
                    || (numberToValidate[x] == '.' || numberToValidate[x] == '-'))
            {
                if (numberToValidate[x] == '-')
                {
                    contadorSignoNegativo++;
                }
                if (numberToValidate[x] == '.')
                {
                    contadorPunto++;
                }
                retorno = 1;
            }
            else
            {
            	retorno = 0;
                break;
            }
            if (contadorSignoNegativo > 1 || contadorPunto > 1 || (contadorSignoNegativo == 1 && numberToValidate[0] != '-'))
            {
            	retorno = 0;
                break;
            }
        }
    }
    return retorno;
}
