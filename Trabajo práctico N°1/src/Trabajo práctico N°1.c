/*
 ============================================================================
Trabajo pr�ctico N�1
Gabriel Villaverde - Divisi�n H
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

int main(void)
{

	setbuf(stdout,NULL);

	int opcion;
	int respuesta;
	float suma;
	float resta;
	float division;
	float multiplicacion;
	long factorial;
	long factorialDos;
	int respuestaSuma;
	int respuestaResta;
	int respuestaDivision;
	int respuestaMultiplicacion;
	int respuestaFactorial;
	int respuestaFactorialDos;

	int numeroUno;
	int numeroDos;

	int primerNumeroIngresado = 0;
	int segundoNumeroIngresado = 0;
	int resultadosCalculados = 0;

	do
	{
		respuesta = utn_getNumero(&opcion, "Seleccione una opci�n\n\n1 - Ingresar el primer n�mero\n2 - Ingresar el segundo n�mero\n3 - Calcular todas las operaciones\n4 - Informar resultados\n5 - Salir\n", "Esa no es una opci�n v�lida", 1, 5, 2);
		if(respuesta == 0) // Si la respuesta de la funci�n es 0, es porque me devolvi� un valor correcto y...
		{
			switch(opcion) // ...entro al switch.
			{
			case 1:
				printf("Entr� a la opci�n 1, ingrese el primer n�mero:\n");
				scanf("%d", &numeroUno);
				printf("El n�mero uno es: %d\n", numeroUno);
				primerNumeroIngresado = 1;
				break;
			case 2:
				printf("Entr� a la opci�n 2, ingrese el segundo n�mero:\n");
				scanf("%d", &numeroDos);
				printf("El n�mero dos es: %d\n", numeroDos);
				segundoNumeroIngresado = 1;
				break;
			case 3:
				if(primerNumeroIngresado && segundoNumeroIngresado){
					printf("Entr� a la opci�n 3, se han calculado todas las operaciones:\n");
					respuestaSuma = sumar(numeroUno, numeroDos, &suma);
					respuestaResta = restar(numeroUno, numeroDos, &resta);
					respuestaDivision = dividir(numeroUno, numeroDos, &division);
					respuestaMultiplicacion = multiplicar(numeroUno, numeroDos, &multiplicacion);
					respuestaFactorial = funcionFactorial(numeroUno, &factorial);
					respuestaFactorialDos = funcionFactorial(numeroDos, &factorialDos);
					resultadosCalculados = 1;
				}
				else {
					printf("No se ingresaron todos los numeros, intente de nuevo.\n");
				}

				break;
			case 4:
				if(resultadosCalculados) {
					printf("Entr� a la opci�n 4, se mostrar�n todas las operaciones:\n");
					if (respuestaSuma == 0) // Si el retorno de la funci�n sumar es 0, entra al printf y muestra el resultado.
					{
						printf("\nEl resultado de la suma es: %.2f", suma);
					}
					else
					{
						printf("\nAlgo sali� mal.");
					}

					if (respuestaResta == 0)
					{
						printf("\nEl resultado de la resta es: %.2f", resta);
					}
					else
					{
						printf("\nAlgo sali� mal.");
					}

					if (respuestaDivision == 0)
					{
						printf("\nEl resultado de la divisi�n es: %.2f", division);
					}
					else
					{
						printf("\nNo es posible dividir por 0.");
					}

					if (respuestaMultiplicacion == 0)
					{
						printf("\nEl resultado de la multiplicacion es: %.2f", multiplicacion);
					}
					else
					{
						printf("\nAlgo sali� mal.");
					}
					if (respuestaFactorial == 0 && numeroUno > 0)
					{
						printf("\nEl factorial del primer n�mero es: %ld", factorial);
					}
					else
					{
						printf("\nNo es posible realizar el factorial de un n�mero negativo.");
					}
					if (respuestaFactorialDos == 0 && numeroDos > 0)
					{
						printf("\nEl factorial del segundo n�mero es: %ld\n", factorialDos);
					}
					else
					{
						printf("\nNo es posible realizar el factorial de un n�mero negativo.");
					}
					break;
				}
				else {
					printf("No se calcularon los resultados, ingrese la opcion 3");
				}
			}
		}
	}while(opcion != 5);
	return EXIT_SUCCESS;
}
