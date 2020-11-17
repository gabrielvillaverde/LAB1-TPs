#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "Controller.h"
#include "parser.h"

/*
* \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
* \param FILE* puntero al archivo.
* \param pArrayListEmployee LinkedList* puntero al array de empleados.
* \return (-1) Error (0) todo OK
*/
int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
	int retorno = -1;

	Employee* pEmployee;

	char idAuxiliar[4000];
	char nombreAuxiliar[4000];
	char horasTrabajadasAuxiliar[4000];
	char sueldoAuxiliar[4000];

	if(pFile != NULL && pArrayListEmployee != NULL)
	{
		do
		{
			if(fscanf(pFile, "%[^,], %[^,], %[^,], %[^\n]\n", idAuxiliar, nombreAuxiliar, horasTrabajadasAuxiliar, sueldoAuxiliar) == 4)
			{
				pEmployee = employee_newParametros(idAuxiliar, nombreAuxiliar, horasTrabajadasAuxiliar, sueldoAuxiliar);
				if(pEmployee != NULL)
				{
					printf("%s - %s - %s - %s\n", idAuxiliar, nombreAuxiliar, horasTrabajadasAuxiliar, sueldoAuxiliar);
					ll_add(pArrayListEmployee, pEmployee);
					retorno = 0;
				}
			}
		}while(feof(pFile) == 0);
	}
    return retorno;
}

/*
* \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
* \param FILE* puntero al archivo.
* \param pArrayListEmployee LinkedList* puntero al array de empleados.
* \return (-1) Error (0) todo OK
*/
int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
	int retorno = -1;

	Employee* pAux;

	if(pFile != NULL && pArrayListEmployee != NULL)
	{
		do
		{
			pAux = employee_new();
			if(pAux != NULL && fread(pAux, sizeof(Employee), 1, pFile) == 1)
			{
				ll_add(pArrayListEmployee, pAux);
			}
			else
			{
				employee_delete(pAux);
			}
		}while(feof(pFile) == 0);
	}
    return retorno;
}
