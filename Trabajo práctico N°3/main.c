#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn.h"

// ERRORES:

// MODIFICAR: Me acepta valores de ID que no debería (fuera de -1 y más de 1000)
// ELIMINAR: Me acepta valores de ID que no debería (fuera de -1 y más de 1000)

int main()
{
	setbuf(stdout, NULL);

    int opcion;
    int id = 1001;

    LinkedList* listaEmpleados = ll_newLinkedList();
    do
    {
    	if(utn_getIntConMinMax("\nBienvenido al sistema, elija una opción: \n\n"
    			"1  -  Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n"
    			"2  -  Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n"
    			"3  -  Alta de empleado.\n"
    			"4  -  Modificar datos de empleado.\n"
    			"5  -  Baja de empleado.\n"
    			"6  -  Listar empleados.\n"
    			"7  -  Ordenar empleados.\n"
    			"8  -  Guardar los datos de los empleados en el archivo data.csv (modo texto).\n"
    			"9  -  Guardar los datos de los empleados en el archivo data.csv (modo binario).\n"
    			"10 -  Salir\n", "\nError, ingrese una opción entre 1 y 10.\n", &opcion, 1, 10, 3) == 0)
    	{
    		switch(opcion)
			{
				case 1:
					controller_loadFromText("data.csv", listaEmpleados);
					break;
				case 2:
					controller_loadFromBinary("data.csv", listaEmpleados);
					break;
				case 3:
					if(ll_isEmpty(listaEmpleados) == 0)
					{
						if(controller_addEmployee(listaEmpleados, &id) == 0)
						{
							printf("\nEmployee registered correctly.\n");
						}
						else
						{
							printf("\Employee could not be registered.\n");
						}
					}
					else
					{
						printf("\nPlease load the file first.\n");
					}
					break;
				case 4:
					if(ll_isEmpty(listaEmpleados) == 0)
					{
						if(controller_editEmployee(listaEmpleados) == 0)
						{
							printf("\nEmployee modified correctly.\n");
						}
						else
						{
							printf("\Employee could not be modified.\n");
						}
					}
					else
					{
						printf("\nPlease load the file first.\n");
					}
					break;
				case 5:
					if(ll_isEmpty(listaEmpleados) == 0)
					{
						if(controller_removeEmployee(listaEmpleados) == 0)
						{
							printf("Employee removed correctly.\n");
						}
						else
						{
							printf("\nEmployee could not be removed.\n");
						}
					}
					else
					{
						printf("\nPlease load the file first.\n");
					}
					break;
				case 6:
					if(ll_isEmpty(listaEmpleados) == 0)
					{
						controller_ListEmployee(listaEmpleados);
					}
					else
					{
						printf("\nPlease load the file first.\n");
					}
					break;
				case 7:
					if(ll_isEmpty(listaEmpleados) == 0)
					{
						controller_sortEmployee(listaEmpleados);
					}
					else
					{
						printf("\nPlease load the file first.\n");
					}
					break;
				case 8:
					if(ll_isEmpty(listaEmpleados) == 0)
					{
						if(controller_saveAsText("data.csv", listaEmpleados) == 0)
						{
							printf("\nFile saved as text successfully.\n");
						}
						else
						{
							printf("\nFile could not be saved as text.\n");
						}
					}
					else
					{
						printf("\nPlease load the file first.\n");
					}

					break;
				case 9:
					if(ll_isEmpty(listaEmpleados) == 0)
					{
						if(controller_saveAsBinary("data.csv", listaEmpleados) == 0)
						{
							printf("\nFile saved as binary successfully.\n");
						}
						else
						{
							printf("\nFile could not be saved as binary.\n");
						}
					}
					else
					{
						printf("\nPlease load the file first.\n");
					}
					break;
			}
    	}
    }while(opcion != 10);
    return 0;
}
