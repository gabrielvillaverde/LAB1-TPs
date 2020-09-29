/*
 ============================================================================
 Name        : TP2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "ArrayEmployees.h"

#define QTY_EMPLOYEES 1000

int main(void) {

	setbuf(stdout, NULL);

	Employee arrayEmployees[QTY_EMPLOYEES];

	int option;
	int reportOption;
	int orderOption;
	int freeIndex;
	int idToModify;
	int index;
	float totalSalary;
	float averageSalary;
	int greaterThanAverage;
	int counterEmployee = 0;

	employee_initEmployees(arrayEmployees, QTY_EMPLOYEES); // Inicializo la función de empleados.

	do
	{
		if(utn_getNumberInt("Welcome to the system, select an option: \n\n1 - Register employee\n2 - Modify registry\n3 - Remove employee\n4 - Report\n5 - Get out of the system\n","\nError. select a valid option (1-5)\n", &option, 2, 1, 5)==0)
		{
			switch (option)
			{
			case 1:
				printf("\nYou chose option 1 - Register employee\n");
				if(employee_findEmpty(arrayEmployees, QTY_EMPLOYEES,&freeIndex)==0) // Llamo a la función para encontrar un lugar vacío en el array.
				{
					employee_addEmployee(arrayEmployees, QTY_EMPLOYEES,freeIndex); // Si encontró un lugar vacío, llamo a la función para agregar un empleado.
					counterEmployee++; // Y aumento el contador de empleados.
				}
				break;
			case 2:
				if(counterEmployee > 0) // Si el contador de empleados es mayor a 0, significa que al menos ingresé 1 empleado al sistema, por lo tanto... --->
				{
				printf("\nYou entered option 2 - Modify data of an employee:\n"); // ... ---> pude ingresar a la opción 2.
				employee_printEmployees(arrayEmployees, QTY_EMPLOYEES); // Llamo a la función para imprimir los empleados cargados, así el usuario tiene una referencia de qué ID elegir para modificar.
					if (utn_getNumberInt("Enter the ID of the employee you want to modify:\n","Error, select a valid or empty ID.\n", &idToModify,2,1,1000) == 0)
					{
						if (employee_findEmployeeById(arrayEmployees, QTY_EMPLOYEES,&index,idToModify) == 0) // Llamo a la función para encontrar un empleado por su ID asignada.
						{
							employee_modifyEmployee(arrayEmployees, QTY_EMPLOYEES,index); // Si encuentro una ID ya cargada, llamo a la función para modificar los datos del empleado.
						}
					}
				}
				else // Sino, aviso al usuario que debe cargar un empleado para poder realizar modificaciones en el sistema.
				{
					printf("You must load an employee before making modifications.\n");
				}
				break;
			case 3:
				if(counterEmployee > 0) // Si el contador de empleados es mayor a 0, significa que así como puedo modificar, también puedo remover empleados.
				{
				printf("\nYou entered option 3 - Remove employee\nYou can delete the following employees:\n");
				employee_printEmployees(arrayEmployees, QTY_EMPLOYEES); // Llamo a la función para imprimir los empleados cargados, así el usuario tiene una referencia de qué ID elegir para eliminar.
					if (utn_getNumberInt("Enter the ID of the employee you want to remove:\n","Error, please type numbers choose the ID.\n",&idToModify,2,1,1000) == 0) // Pido al usuario que ingrese una ID.
					{
						if (employee_findEmployeeById(arrayEmployees,QTY_EMPLOYEES,&index,idToModify) == 0) // Llamo a la función de encontrar empleados por ID.
						{
							employee_removeEmployee(arrayEmployees, QTY_EMPLOYEES,index,idToModify); // Llamo a la función que se encarga de eliminar empleados.
							counterEmployee--; // Al eliminar un empleado, debo decrementar el contador de empleados.
						}
						else
						{
							printf("There's no employee to remove in this ID position.\n"); // Si ingresa un número de ID que no está cargado en sistema, muestro este mensaje de error.
						}
					}
				}
				else
				{
					printf("\nYou must load an employee before deleting.\n"); // El usuario debe cargar al menos 1 empleado para poder eliminar datos del sistema.
				}

				break;
			case 4:
				if(counterEmployee > 0) // Si el contador de empleados es mayor a 0...
				{
				printf("\nYou entered option 4 - Report\n"); // Significa que al menos hay 1 empleado cargado y puedo mostrar el reporte de datos.
					if(utn_getNumberInt("Select an option:\n1 - Report employees sorted alphabetically and by sector\n2 - Total and average salaries, and how many employees are above the average salary\n","\nError, select a correct option [1-2]\n", &reportOption, 2, 1, 2)==0)
					{
						switch (reportOption) // Le indico al usuario qué información quiere recibir en base a un menú de 2 opciones.
						{
						case 1:
							if (utn_getNumberInt("Select an option to order: \n\n1 - Sort employees in ascending order\n2 - Sort employees in descending order\n","\nError, select a correct option [1-2]\n",&orderOption,2,1,2) == 0)
							{
								switch (orderOption) // Le indico al usuario qué tipo de orden quiere observar (ascendente o descendente).
								{
								case 1:
									printf("\nYou chose option 1 - Sort employees in ascending order by surname and then by sector if the surnames are the same\n");
									employee_sortEmployees(arrayEmployees,QTY_EMPLOYEES,1); // Llamo a la función que ordena empleados de manera ascendente, primero por apellido y luego por sector.
									employee_printEmployees(arrayEmployees,QTY_EMPLOYEES); // Muestro los datos.
									break;

								case 2:
									printf("\nYou chose option 2 - Sort employees in descending order by surname and then by sector if the surnames are the same\n");
									employee_sortEmployees(arrayEmployees, QTY_EMPLOYEES,0); // Llamo a la función que ordena empleados de manera descendente, primero por apellido y luego por sector.
									employee_printEmployees(arrayEmployees, QTY_EMPLOYEES); // Muestro los datos.
									break;
								}
							}
							break;
						case 2:
							printf("You want to find out the total and average wages, and how many employees are above the average salary:\n");
							employee_calculateTotalAndAverageSalary(arrayEmployees, QTY_EMPLOYEES, &totalSalary, &averageSalary, &greaterThanAverage); // Llamo a la función que calcula lo solicitado en la opción 2 del reporte.
							break;
						}
					}
				}
				else
				{
					printf("\nYou must load an employee before requesting a report.\n");
				}
				break;
			}
		}
	} while (option != 5);
return EXIT_SUCCESS;
}
