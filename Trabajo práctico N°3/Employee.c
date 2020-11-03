#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "LinkedList.h"
#include "Employee.h"
#include "utn.h"

/*
* \brief
* \param
* \param
* \param
* \param
* \return
*/
Employee* employee_new()
{
	Employee* newEmployee = NULL;
	newEmployee = (Employee*) malloc (sizeof(Employee));
	return newEmployee;
}

/*
* \brief
* \param
* \param
* \param
* \param
* \return
*/
Employee* employee_newParametros(char* idStr, char* nombreStr, char* horasTrabajadasStr, char* sueldoStr)
{
	Employee* this = NULL;
	this = employee_new();

	if(this != NULL && idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL && sueldoStr != NULL)
	{
		if(employee_setIdTxt(this, idStr) == -1                              ||
		   employee_setNombre(this, nombreStr) == -1					     ||
		   employee_setHorasTrabajadasTxt(this, horasTrabajadasStr) == -1	 ||
		   employee_setSueldoTxt(this, sueldoStr) == -1)
		{
			employee_delete(this);
			this = NULL;
		}
	}
	return this;
}

/*
* \brief
* \param
* \param
* \param
* \param
* \return
*/
void employee_delete(Employee* this)
{
	if(this != NULL)
	{
		free(this);
	}
}

// SETTERS AND GETTERS

/*
* \brief
* \param
* \param
* \param
* \param
* \return
*/
int employee_setIdTxt(Employee* this, char* id)
{
	int retorno = -1;
	if(this != NULL && id != NULL)
	{
		if(utn_isNumeric(id))
		{
			retorno = 0;
			this->id = atoi(id);
		}
	}
	return retorno;
}

/*
* \brief
* \param
* \param
* \param
* \param
* \return
*/
int employee_getIdTxt(Employee* this, char* id)
{
	int retorno = -1;
	if(this != NULL && id != NULL)
	{
		retorno = 0;
		sprintf(id,"%d",this->id);
	}
	return retorno;
}

/*
* \brief
* \param
* \param
* \param
* \param
* \return
*/
int employee_setId(Employee* this, int id)
{
	int retorno = -1;
	if(this != NULL && id >= 0)
	{
		retorno = 0;
		this->id = id;
	}
	return retorno;
}

/*
* \brief
* \param
* \param
* \param
* \param
* \return
*/
int employee_getId(Employee* this, int* id)
{
	int retorno = -1;
	if(this != NULL && id != NULL)
	{
		retorno = 0;
		*id = this->id;
	}
	return retorno;
}

/*
* \brief
* \param
* \param
* \param
* \param
* \return
*/
int employee_setNombre(Employee* this, char* nombre)
{
	int retorno = -1;
	if(this != NULL && nombre != NULL)
	{
		if(utn_isAlphabetic(nombre))
		{
			retorno = 0;
			strncpy(this->nombre, nombre, 50);
		}
	}
	return retorno;
}

/*
* \brief
* \param
* \param
* \param
* \param
* \return
*/
int employee_getNombre(Employee* this, char* nombre)
{
	int retorno = -1;
	if(this != NULL && nombre != NULL)
	{
		retorno = 0;
		strncpy(nombre, this->nombre, 50);
	}
	return retorno;
}

/*
* \brief
* \param
* \param
* \param
* \param
* \return
*/
int employee_setHorasTrabajadas(Employee* this, int horasTrabajadas)
{
    int retorno = -1;

    if(this != NULL && horasTrabajadas >= 0)
    {
		this->horasTrabajadas = horasTrabajadas;
		retorno = 0;
    }
    return retorno;
}

/*
* \brief
* \param
* \param
* \param
* \param
* \return
*/
int employee_getHorasTrabajadas(Employee* this, int* horasTrabajadas)
{
    int retorno = -1;

    if(this != NULL && horasTrabajadas != NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        retorno = 0;
    }
    return retorno;
}

/*
* \brief
* \param
* \param
* \param
* \param
* \return
*/
int employee_setHorasTrabajadasTxt(Employee* this, char* horasTrabajadas)
{
	int retorno = -1;
	if(this != NULL && horasTrabajadas != NULL)
	{
		if(utn_isNumeric(horasTrabajadas))
		{
			retorno = 0;
			this->horasTrabajadas = atoi(horasTrabajadas);
		}
	}
	return retorno;
}

/*
* \brief
* \param
* \param
* \param
* \param
* \return
*/
int employee_getHorasTrabajadasTxt(Employee* this, char* horasTrabajadas)
{
	int retorno = -1;
	if(this != NULL && horasTrabajadas != NULL)
	{
		retorno = 0;
		sprintf(horasTrabajadas,"%d",this->horasTrabajadas);
	}
	return retorno;
}

/*
* \brief
* \param
* \param
* \param
* \param
* \return
*/
int employee_setSueldo(Employee* this, int sueldo)
{
	int retorno = -1;
	if(this != NULL && sueldo >= 0)
	{
		retorno = 0;
		this->sueldo = sueldo;
	}
	return retorno;
}

/*
* \brief
* \param
* \param
* \param
* \param
* \return
*/
int employee_getSueldo(Employee* this, int* sueldo)
{
	int retorno = -1;
	if(this != NULL && sueldo != NULL)
	{
		retorno = 0;
		*sueldo = this->sueldo;
	}
	return retorno;
}

/*
* \brief
* \param
* \param
* \param
* \param
* \return
*/
int employee_setSueldoTxt(Employee* this, char* sueldo)
{
	int retorno = -1;
	if(this != NULL && sueldo != NULL)
	{
		if(utn_isNumeric(sueldo))
		{
			retorno = 0;
			this->sueldo = atoi(sueldo);
		}
	}
	return retorno;
}

/*
* \brief
* \param
* \param
* \param
* \param
* \return
*/
int employee_getSueldoTxt(Employee* this, char* sueldo)
{
	int retorno = -1;
	if(this != NULL && sueldo != NULL)
	{
		retorno = 0;
		sprintf(sueldo,"%d",this->sueldo);
	}
	return retorno;
}

int employee_sortEmployees(LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	int option;

	if(pArrayListEmployee != NULL)
	{
		do
		{
		if(utn_getIntConMinMax("\n1 - Sort the list by name."
							   "\n2 - Sort the list by quantity of hours."
							   "\n3 - Sort the list by salary."
							   "\n4 - Exit.\n",
							   "\nError, please select a correct option between 1 and 4.\n", &option, 1, 4, 3) == 0)
				{
					switch(option)
					{
						case 1:
							printf("\nYou sorted the employees by name in ascending order, now you can go back to the previous menu (select 4 and wait...)\n");
							ll_sort(pArrayListEmployee, employee_sortByName, 1);
							break;
						case 2:
							printf("\nYou sorted the employees by hours in ascending order, now you can go back to the previous menu (select 4 and wait...)\n");
							ll_sort(pArrayListEmployee, employee_sortByHours, 1);
							break;
						case 3:
							printf("\nYou sorted the employees by salary in ascending order, now you can go back to the previous menu (select 4 and wait...)\n");
							ll_sort(pArrayListEmployee, employee_sortBySalary, 1);
							break;
					}
				}
		}while(option != 4);
	}

	return retorno;
}

int employee_sortByName(void* pFirstElem, void* pSecondElem)
{
	int retorno = 0;

	char firstName[100];
	char secondName[100];

	employee_getNombre(pFirstElem, firstName);
	employee_getNombre(pSecondElem, secondName);

	if(strncmp(firstName, secondName, 100) > 0)
	{
		retorno = 1;
	}
	else if(strncmp(firstName, secondName, 100) < 0)
	{
		retorno = -1;
	}
	return retorno;
}

int employee_sortByHours(void* pFirstElem, void* pSecondElem)
{
	int retorno = 0;

	int firstHours;
	int secondHours;

	employee_getHorasTrabajadas(pFirstElem, &firstHours);
	employee_getHorasTrabajadas(pSecondElem, &secondHours);

	if(firstHours > secondHours)
	{
		retorno = 1;
	}
	else if(secondHours > firstHours)
	{
		retorno = -1;
	}
	return retorno;
}

int employee_sortBySalary(void* pFirstElem, void* pSecondElem)
{
	int retorno = 0;

	int firstSalary;
	int secondSalary;

	employee_getSueldo(pFirstElem, &firstSalary);
	employee_getSueldo(pSecondElem, &secondSalary);

	if(firstSalary > secondSalary)
	{
		retorno = 1;
	}
	else if(secondSalary > firstSalary)
	{
		retorno = -1;
	}
	return retorno;
}

int employee_findIndexById(LinkedList* pArrayListEmployee, int id)
{
    int retorno = -1;
    int idAux;

    Employee* pEmployee;

    for(int i = 0; i < ll_len(pArrayListEmployee); i++)
    {
        pEmployee = ll_get(pArrayListEmployee, i);
        if(employee_getId(pEmployee, &idAux) == 0 && idAux == id)
        {
            retorno = i;
        }
    }
    return retorno;
}
