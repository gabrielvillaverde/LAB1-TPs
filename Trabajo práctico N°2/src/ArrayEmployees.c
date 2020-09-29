/*
 * ArrayEmployees.c
 *
 *  Created on: 25 sep. 2020
 *      Author: Hzkr
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "ArrayEmployees.h"

#define TRUE 1
#define FALSE 0

#define LONG_NAME 51
#define LONG_LASTNAME 51
#define QTY_EMPLOYEES 1000

// Prototipos:
static int generateNewId(void);
static int releaseId(int idToRelease);
static int compareElements(Employee currentEmployee, Employee nextEmployee, int order, int sort);
static int freeIds[QTY_EMPLOYEES];
static int len = 0;
static int IdsEmpty = TRUE;

/** \brief To indicate that all position in the array are empty, this function put the flag (isEmpty) in TRUE in all the positions of the array
* \param pArrayList Employee* Pointer to array of employees
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int employee_initEmployees(Employee* pArrayList, int len)
{
	int retorno = -1;
	if(pArrayList != NULL && len > 0)
	{
		for(int i= 0;i<len;i++)
		{
			pArrayList[i].isEmpty = TRUE;
		}
		retorno = 0;
	}
	return retorno;
}

/** \brief Add in a existing list of employees the values received as parameters in the first empty position
* \param pArrayList Employee* Pointer to array of employees
* \param len int Array lenght
* \param index int Receives content of bufferEmployee
* \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
*/
int employee_addEmployee(Employee* pArrayList, int len, int index)
{
	int retorno = -1;
	Employee bufferEmployee;
	if(pArrayList != NULL && len > 0 && index >= 0 && index <= len && pArrayList[index].isEmpty == TRUE)
	{
		if
		(
		utn_getName("\nName of employee:\n","Error, please type a correct name.\n",bufferEmployee.name,2,LONG_NAME)==0 // Me tiraba error porque estaba usando &bufferEmployee, ¿por qué acá no y en las otras sí el &?
			&&
		utn_getName("\nLast name of employee:\n","Error, please type a correct last name.\n",bufferEmployee.lastName,2,LONG_LASTNAME)==0 // Me tiraba error porque estaba usando &bufferEmployee, ¿por qué acá no y en las otras sí el &?
			&&
		utn_getNumberFloat("\nSalary:\n","Error, please type a correct salary between $0 and $999999.\n", &bufferEmployee.salary,2, 0, 999999)==0
			&&
		utn_getNumberInt("\nSector:\n", "Error, please type a correct sector\n", &bufferEmployee.sector, 2, 0, 999999)==0
		)
		{
			bufferEmployee.id = generateNewId();
			pArrayList[index] = bufferEmployee;
			pArrayList[index].isEmpty = FALSE;
			retorno = 0;
		}
	}
	return retorno;
}

/** \brief Remove a Employee by ID (put isEmpty Flag in TRUE)
* \param pArrayList Employee* Pointer to array of employees
* \param len int Array lenght
* \param index int Position in the array that changes between TRUE and FALSE value determined by isEmpty flag.
* \param id int Receives the ID that will be removed from the system.
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't find a employee] - (0) if Ok
*
*/
int employee_removeEmployee(Employee* pArrayList, int len, int index, int id)
{
	int retorno = -1;
	if(pArrayList != NULL && len > 0 && index < len && pArrayList[index].isEmpty == FALSE)
	{
		pArrayList[index].isEmpty = TRUE;
		releaseId(id);
		retorno = 0;
	}
	printf("\nYou just removed the following ID: %d\n",id);
	return retorno;
}

/** \brief Finds an empty slot in the array to load an employee
* \param pArrayList Employee* Pointer to array of employees
* \param len int Array lenght
* \param pIndex int* Pointer to an empty position in the index.
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't find a employee] - (0) if Ok
*
*/
int employee_findEmpty(Employee* pArrayList, int len, int* pIndex)
{
	int retorno = -1;
	if(pArrayList != NULL && pIndex != NULL && len > 0)
	{
		for(int i=0;i<len;i++)
		{
			if(pArrayList[i].isEmpty == TRUE)
			{
				*pIndex = i;
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

/** \brief Finds an employee by ID
* \param pArrayList Employee* Pointer to array of employees
* \param len int Array lenght
* \param id int Receives the ID of the employee
* \param pIndex int* Pointer to a loaded position in the index
* \return int Return (-1) if Error [Invalid length or NULL pointer received or employee not found] - (0) if Ok
*/
int employee_findEmployeeById(Employee* pArrayList, int len, int* pIndex, int id)
{
	int retorno = -1;
	if(pArrayList != NULL && len > 0)
	{
		for(int i=0;i<len;i++)
		{
			if(pArrayList[i].isEmpty == FALSE)
			{
				if(pArrayList[i].id == id) // Estaba poniendo pArrayList[id].id == id, tenía que poner en vez de [id] era [i]
				{
					*pIndex = i;
					retorno = 0;
					break;
				}
			}
		}
	}
	return retorno;
}

/** \brief Modifies the data of an employee only if the index is loaded
* \param pArrayList Employee* Pointer to array of employees
* \param len int Array lenght
* \param index int Receives the index to which it will be assigned after modifications
 * \return (-1) Error / (0) Ok
 *
 */
int employee_modifyEmployee(Employee* pArrayList, int len, int index)
{
	int retorno = -1;
	Employee bufferEmployee;
	if
	(
	utn_getName("\nName of employee:\n","Error, please type a correct name.\n",bufferEmployee.name,2,LONG_NAME)==0 // Me tiraba error porque estaba usando &bufferEmployee, ¿por qué acá no y en las otras sí el &?
		&&
	utn_getName("\nLast name of employee:\n","Error, please type a correct last name.\n",bufferEmployee.lastName,2,LONG_LASTNAME)==0 // Me tiraba error porque estaba usando &bufferEmployee, ¿por qué acá no y en las otras sí el &?
		&&
	utn_getNumberFloat("\nSalary:\n","Error, please type a correct salary between $0 and $999999.\n", &bufferEmployee.salary,2, 0, 999999)==0
		&&
	utn_getNumberInt("\nSector:\n", "Error, please type a correct sector\n", &bufferEmployee.sector, 2, 0, 999999)==0
	)
	{
		bufferEmployee.id = pArrayList[index].id;
		pArrayList[index] = bufferEmployee;
		pArrayList[index].isEmpty = FALSE;
		retorno = 0;
	}
	return retorno;
}

/** \brief Prints the content of employees array
* \param pArrayList Employee* Pointer to array of employees
* \param len int Array lenght
* \return int Return (-1) if Error [Invalid length or NULL pointer received or employee not found] - (0) if Ok
*
*/
int employee_printEmployees(Employee* pArrayList, int len)
{
	int retorno = -1;
	if(pArrayList != NULL && len > 0)
	{
		for(int i=0;i<len;i++)
		{
			if(pArrayList[i].isEmpty == FALSE)
			{
				printf("Name: %s - Last name: %s - Salary: %f - Sector: %d - ID: %d\n\n", pArrayList[i].name, pArrayList[i].lastName, pArrayList[i].salary, pArrayList[i].sector, pArrayList[i].id);
			}
		}
		retorno = 0;
	}
	return retorno;
}

/** \brief Sort the elements in the array of employees, the argument order indicate UP or DOWN order*
* \param pArrayList Employee* Pointer to array of employees
* \param len int Array lenght
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
**/
int employee_sortEmployees(Employee* pArrayList, int len, int order)
{
	int sort;
	if(order == 1)
	{
		sort = 1;
	}
	else if(order == 0)
	{
		sort = -1;
	}

	int retorno = -1;
	int i;
	int newLen;
	int flagSwap;
	Employee bufferEmployee;
	if(pArrayList != NULL && len > 0)
	{
		newLen = len -1;
		do
		{
			flagSwap = 0;
			for(i=0;i<newLen;i++)
			{
				if(pArrayList[i+1].isEmpty == 0)
				{

					if(compareElements(pArrayList[i], pArrayList[i+1], order, sort))
					{
						flagSwap = 1;
						bufferEmployee=pArrayList[i];
						pArrayList[i]=pArrayList[i+1];
						pArrayList[i+1]=bufferEmployee;
					}

				}
			}
			newLen--;
			retorno=0;
		}while(flagSwap);
	}
	return retorno;
}

/** \brief Compare the elements of one employee with the next
* \param currentEmployee Employee indicates the first employee to compare
* \param nextEmployee Employee indicates the next employee to compare
* \param order int [1] indicate UP - [0] indicate DOWN
* \param sort int indicate the order of lastName
* \return int Return (1) if Ok, (0) if Error
**/
static int compareElements(Employee currentEmployee, Employee nextEmployee, int order, int sort)
{
	if(strcmp(currentEmployee.lastName, nextEmployee.lastName) == sort)
	{
		return 1;
	}
	else if(strcmp(currentEmployee.lastName, nextEmployee.lastName) == 0)
	{
		if(order)
		{
			if(currentEmployee.sector > nextEmployee.sector)
			{
				return 1;
			}
			else
			{
			return 0;
			}
		}
		else
		{
			if(currentEmployee.sector < nextEmployee.sector)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
	}
	else
	{
	return 0;
	}
}

/** \brief Calculate the total and average salary, and how many employees have a salary greater than average
* \param pArrayList Employee* Pointer to array of employees
* \param len int Array lenght
* \param pTotalSalary float* Pointer to the total salary
* \param pAveragesalary float* Pointer to the average salary
* \param pGreaterThanAverage int* Pointer to the employees that have a greater salary than average
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
**/
int employee_calculateTotalAndAverageSalary(Employee* pArrayList, int len, float* pTotalSalary, float* pAverageSalary, int *pGreaterThanAverage)
{
	int i;
	int retorno = -1;
	int counter = 0;
	int aboveAverageCounter = 0;
	int salaryAcumulator = 0;

	if(pArrayList != NULL && pTotalSalary != NULL && pAverageSalary != NULL && len > 0)
	{

		for(i=0;i<len;i++)
		{
			if(!pArrayList[i].isEmpty)
			{
				salaryAcumulator += pArrayList[i].salary;
				counter++;
			}
		}
		*pTotalSalary = salaryAcumulator;
		*pAverageSalary = (float)salaryAcumulator / counter;

		for(i=0;i<len;i++)
		{
			if(!pArrayList[i].isEmpty)
			{
				if(pArrayList[i].salary > *pAverageSalary)
				{
					aboveAverageCounter++;
				}
			}
		}
		*pGreaterThanAverage = aboveAverageCounter;
		printf("Average wages: %f - Total wages: %f - Quantity of employees that are above the average wage: %d\n",*pAverageSalary,*pTotalSalary,*pGreaterThanAverage);
		retorno = 0;
	}
return retorno;
}

static int generateNewId(void)
{
	static int id=0;
	if(!IdsEmpty)
	{
		int aux = returnId();
		return aux;
	}
	else
	{
		id=id+1;
		return id;
	}
}

static int releaseId(int idToRelease)
{
	IdsEmpty = FALSE;
	freeIds[len] = idToRelease;
	len++;
	return 1;
}

int returnId()
{
	int aux;
	if(1 <= freeIds[0] && freeIds[0] <= QTY_EMPLOYEES)
	{
		aux = freeIds[0];
		if(1 <= freeIds[0] && freeIds[0] <= QTY_EMPLOYEES)
		{
			freeIds[0] = freeIds[1];
		}
		else
		{
			IdsEmpty = TRUE;
		}
	}
	return aux;

}
