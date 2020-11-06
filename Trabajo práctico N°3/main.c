#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn.h"

#define FALSE 0
#define TRUE 1

int main()
{
	setbuf(stdout, NULL);

    int opcion;
    int id = 1001;
    int archivoGuardado = FALSE;

    LinkedList* listaEmpleados = ll_newLinkedList();
    do
    {
    	if(utn_getIntConMinMax("\nBienvenido al sistema, elija una opción: \n\n"
    			"1  -  Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n"
    			"2  -  Cargar los datos de los empleados desde el archivo data.bin (modo binario).\n"
    			"3  -  Alta de empleado.\n"
    			"4  -  Modificar datos de empleado.\n"
    			"5  -  Baja de empleado.\n"
    			"6  -  Listar empleados.\n"
    			"7  -  Ordenar empleados.\n"
    			"8  -  Guardar los datos de los empleados en el archivo data.csv (modo texto).\n"
    			"9  -  Guardar los datos de los empleados en el archivo data.bin (modo binario).\n"
    			"10 -  Salir\n", "\nError, ingrese una opción entre 1 y 10.\n", &opcion, 1, 10, 3) == 0)
    	{
    		switch(opcion)
			{
				case 1:
					if(controller_loadFromText("data.csv", listaEmpleados) == 0)
					{
						printf("\nArchivo cargado como texto correctamente.\n");
					}
					else
					{
						printf("\nNo se pudo cargar el archivo como texto.\n");
					}
					break;
				case 2:
					if(controller_loadFromBinary("data.bin", listaEmpleados) == 0)
					{
						printf("\nArchivo cargado como binario correctamente.\n");
					}
					else
					{
						printf("\nNo se pudo cargar el archivo como binario.\n");
					}
					break;
				case 3:
					if(ll_isEmpty(listaEmpleados) == 0)
					{
						if(controller_addEmployee(listaEmpleados, &id) == 0)
						{
							printf("\nEmpleado dado de alta correctamente.\n");
						}
						else
						{
							printf("\nNo se pudo dar de alta el empleado.\n");
						}
					}
					else
					{
						printf("\nPrimero cargue el archivo.\n");
					}
					break;
				case 4:
					if(ll_isEmpty(listaEmpleados) == 0)
					{
						if(controller_editEmployee(listaEmpleados) == 0)
						{
							printf("\nEmpleado modificado correctamente.\n");
						}
						else
						{
							printf("\nNo se pudo modificar al empleado.\n");
						}
					}
					else
					{
						printf("\nPrimero cargue el archivo.\n");
					}
					break;
				case 5:
					if(ll_isEmpty(listaEmpleados) == 0)
					{
						if(controller_removeEmployee(listaEmpleados) == 0)
						{
							printf("Empleado eliminado correctamente.\n");
						}
						else
						{
							printf("\nNo se pudo eliminar al empleado.\n");
						}
					}
					else
					{
						printf("\nPrimero cargue el archivo.\n");
					}
					break;
				case 6:
					if(ll_isEmpty(listaEmpleados) == 0)
					{
						controller_ListEmployee(listaEmpleados);
					}
					else
					{
						printf("\nPrimero cargue el archivo.\n");
					}
					break;
				case 7:
					if(ll_isEmpty(listaEmpleados) == 0)
					{
						controller_sortEmployee(listaEmpleados);
					}
					else
					{
						printf("\nPrimero cargue el archivo.\n");
					}
					break;
				case 8:
					if(ll_isEmpty(listaEmpleados) == 0)
					{
						if(controller_saveAsText("data.csv", listaEmpleados) == 0)
						{
							printf("\nArchivo guardado como texto correctamente.\n");
							archivoGuardado = TRUE;
						}
						else
						{
							printf("\nEl archivo no se pudo guardar como texto.\n");
						}
					}
					else
					{
						printf("\nPrimero cargue el archivo.\n");
					}

					break;
				case 9:
					if(ll_isEmpty(listaEmpleados) == 0)
					{
						if(controller_saveAsBinary("data.bin", listaEmpleados) == 0)
						{
							printf("\nArchivo guardado como binario correctamente.\n");
							archivoGuardado = TRUE;
						}
						else
						{
							printf("\nEl archivo no se pudo guardar como binario.\n");
						}
					}
					else
					{
						printf("\nPrimero cargue el archivo.\n");
					}
					break;
				case 10:
					if(archivoGuardado == TRUE)
					{
						ll_clear(listaEmpleados);
						ll_deleteLinkedList(listaEmpleados);
					}
			}
    	}
    }while(opcion != 10);
    return 0;
}
