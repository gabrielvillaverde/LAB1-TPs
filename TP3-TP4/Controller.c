#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "Controller.h"
#include "parser.h"
#include "utn.h"

/*
* \brief Función que carga los datos de los empleados desde el archivo data.csv (modo texto).
* \param path char* es la ruta del archivo.
* \param pArrayListEmployee LinkedList* es el puntero al array de empleados.
* \return (-1) Error (0) todo OK
*/
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
	int retorno = -1;

	FILE* punteroArchivo;

	if(path != NULL && pArrayListEmployee != NULL)
	{
		punteroArchivo = fopen(path, "r");
		if(punteroArchivo != NULL)
		{
			parser_EmployeeFromText(punteroArchivo, pArrayListEmployee);
			retorno = 0;
		}
		fclose(punteroArchivo);
	}
    return retorno;
}

/*
* \brief Función que carga los datos de los empleados desde el archivo data.bin (modo binario).
* \param path char* es la ruta del archivo.
* \param pArrayListEmployee LinkedList* es el puntero al array de empleados.
* \return (-1) Error (0) todo OK
*/
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = -1;

	FILE * punteroArchivo;

	if(path != NULL && pArrayListEmployee != NULL)
	{
		punteroArchivo = fopen(path, "rb");
		if(punteroArchivo != NULL)
		{
			parser_EmployeeFromBinary(punteroArchivo, pArrayListEmployee);
			retorno = 0;
		}
		fclose(punteroArchivo);
	}
    return retorno;
}

/*
* \brief Función que guarda los datos de los empleados en el archivo data.csv (modo texto).
* \param path char* es la ruta del archivo.
* \param pArrayListEmployee LinkedList* es el puntero al array de empleados.
* \return (-1) Error (0) todo OK
*/
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
	int retorno = -1;

	FILE* pArchivo;
	Employee* pEmployee;

	char id[10000];
	char nombre[10000];
	char horasTrabajadas[10000];
	char sueldo[10000];

	if(path != NULL && pArrayListEmployee != NULL)
	{
		pArchivo = fopen(path, "w");
		if(pArchivo != NULL)
		{
			retorno = 0;
			for(int i ; i < ll_len(pArrayListEmployee) ; i++)
			{
				pEmployee = ll_get(pArrayListEmployee, i);
				if(pEmployee != NULL)
				{
					if( !employee_getIdTxt(pEmployee, id) &&
					    !employee_getNombre(pEmployee, nombre) &&
					    !employee_getHorasTrabajadasTxt(pEmployee, horasTrabajadas) &&
					    !employee_getSueldoTxt(pEmployee, sueldo) )
					{
						fprintf(pArchivo, "%s, %s, %s, %s\n", id, nombre, horasTrabajadas, sueldo);
					}
				}
			}
			fclose(pArchivo);
		}
	}
    return retorno;
}

/*
* \brief Función que guarda los datos de los empleados en el archivo data.bin (modo binario).
* \param path char* es la ruta del archivo
* \param pArrayListEmployee LinkedList* es el puntero al array de empleados.
* \return (-1) Error (0) todo OK
*/
int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
	int retorno = -1;

	FILE* pArchivo;
	Employee* pEmployee;

	if(path != NULL && pArrayListEmployee != NULL)
	{
		pArchivo = fopen(path, "wb");
		if(pArchivo != NULL)
		{
			retorno = 0;
			for(int i ; i < ll_len(pArrayListEmployee) ; i++)
			{
				pEmployee = (Employee*)ll_get(pArrayListEmployee, i);
				if(pEmployee != NULL)
				{
					fwrite(pEmployee, sizeof(Employee), 1, pArchivo);
				}
			}
			fclose(pArchivo);
		}
	}
    return retorno;
}

/*
* \brief Función que se encarga de dar de alta un empleado
* \param pArrayListEmployee LinkedList* es el puntero al array de empleados.
* \param int* es el puntero al ID.
* \return (-1) Error (0) todo OK
*/
int controller_addEmployee(LinkedList* pArrayListEmployee, int* id)
{
	int retorno = -1;

	Employee* pEmployee;
	pEmployee = employee_new();

	char nombre[10000];
	char sueldoTxt[10000];
	char horasTrabajadasTxt[10000];

	if(pArrayListEmployee != NULL)
	{
		if( utn_getString("\nIngrese el nombre:\n", "\nError, ingrese un nombre correcto.\n", nombre, 10000, 3) == 0
				&&
			utn_getStringWithOnlyNumbers("\nIngrese las horas trabajadas.\n", "\nError, ingrese las horas trabajadas.\n", horasTrabajadasTxt, 10000, 3) == 0
				&&
			utn_getStringWithOnlyNumbers("\nIngrese el sueldo:\n", "Error, ingrese el sueldo.\n", sueldoTxt, 10000, 3) == 0)
		{
			if(pEmployee != NULL)
			{
				employee_setId(pEmployee, *id);
				employee_setNombre(pEmployee, nombre);
				employee_setHorasTrabajadasTxt(pEmployee, horasTrabajadasTxt);
				employee_setSueldoTxt(pEmployee, sueldoTxt);
				ll_add(pArrayListEmployee, pEmployee);
				*id = *id+1;
				retorno = 0;
			}
		}
	}
    return retorno;
}

/*
* \brief Función que modifica datos del empleado
* \param pArrayListEmployee LinkedList* es el puntero al array de empleados.
* \return (-1) Error (0) todo OK
*/
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = -1;

	Employee* pEmployee = NULL;

	int idEditar;
	int indiceEditar;
	char nombre[1000];
	char horasTrabajadas[1000];
	char sueldo[1000];

	if(pArrayListEmployee != NULL)
	{
		if(utn_getInt("\nIngrese el ID del empleado:\n", "\nError, ingrese el ID correcto.\n", &idEditar, 3) == 0)
		{
			printf("ID encontrado correctamente: %d\n", idEditar);
			indiceEditar = employee_findIndexById(pArrayListEmployee, idEditar);
			pEmployee = ll_get(pArrayListEmployee, indiceEditar);

			if(pEmployee != NULL)
			{
				printf("El empleado a modificar es: %s, con el siguiente ID: %d\n", pEmployee->nombre, pEmployee->id);
				if( utn_getString("\nIngrese el nuevo nombre:\n", "\nError, ingrese un nombre correcto.\n", nombre, 1000, 3) == 0
						&&
					utn_getStringWithOnlyNumbers("\nIngrese las nuevas horas trabajadas.\n", "\nError, ingrese las horas trabajadas.\n", horasTrabajadas, 1000, 3) == 0
						&&
					utn_getStringWithOnlyNumbers("\nIngrese el nuevo sueldo:\n", "Error, ingrese el sueldo.\n", sueldo, 1000, 3) == 0)
				{
					employee_setNombre(pEmployee, nombre);
					employee_setHorasTrabajadasTxt(pEmployee, horasTrabajadas);
					employee_setSueldoTxt(pEmployee, sueldo);
					retorno = 0;
				}
			}
		}
	}
	return retorno;
}

/*
* \brief Función que da de baja al empleado
* \param pArrayListEmployee LinkedList* es el puntero al array de empleados.
* \return (-1) Error (0) todo OK
*/
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = -1;

	Employee* pEmployee;

	int idEliminar;
	int indiceEliminar;

	if(pArrayListEmployee != NULL)
	{
		if(utn_getInt("\nIngrese el ID del empleado a eliminar:\n", "\nError, ingrese el ID correcto.\n", &idEliminar, 3) == 0)
		{
			indiceEliminar = employee_findIndexById(pArrayListEmployee, idEliminar);
			pEmployee = ll_get(pArrayListEmployee, indiceEliminar);

			if(pEmployee != NULL)
			{
				printf("Usted borró el siguiente empleado: %s, con el ID: %d\n", pEmployee->nombre, pEmployee->id);
				pEmployee = ll_get(pArrayListEmployee, indiceEliminar);
				employee_delete(pEmployee);
				ll_remove(pArrayListEmployee, indiceEliminar);
				retorno = 0;
			}
		}
	}
    return retorno;
}


/*
* \brief Función que imprime los empleados
* \param pArrayListEmployee LinkedList* es el puntero al array de empleados.
* \return (-1) Error (0) todo OK
*/
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = -1;

	char id[10000];
	char nombre[10000];
	char horasTrabajadas[10000];
	char sueldo[10000];

	Employee* pEmployee;

	if(pArrayListEmployee != NULL)
	{
		retorno = 0;
		printf("\n| LISTA DE EMPLEADOS |\n");

		for(int i ; i < ll_len(pArrayListEmployee) ; i++)
		{
			pEmployee = ll_get(pArrayListEmployee, i);
			employee_getIdTxt(pEmployee, id);
			employee_getNombre(pEmployee, nombre);
			employee_getHorasTrabajadasTxt(pEmployee, horasTrabajadas);
			employee_getSueldoTxt(pEmployee, sueldo);
			printf("%s - %s - %s - %s\n", id, nombre, horasTrabajadas, sueldo);
		}
	}
    return retorno;
}

/*
* \brief Función que ordena los empleados
* \param pArrayListEmployee LinkedList* es el puntero al array de empleados.
* \return (-1) Error (0) todo OK
*/
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = -1;

	if(pArrayListEmployee != NULL)
	{
		employee_sortEmployees(pArrayListEmployee);
		retorno = 0;
	}
    return retorno;
}
