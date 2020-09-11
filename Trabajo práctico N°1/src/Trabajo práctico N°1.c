/*
 ============================================================================
Trabajo práctico N°1
Gabriel Villaverde - División H
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
		respuesta = utn_getNumero(&opcion, "Seleccione una opción\n\n1 - Ingresar el primer número\n2 - Ingresar el segundo número\n3 - Calcular todas las operaciones\n4 - Informar resultados\n5 - Salir\n", "Esa no es una opción válida", 1, 5, 2);
		if(respuesta == 0) // Si la respuesta de la función es 0, es porque me devolvió un valor correcto y...
		{
			switch(opcion) // ...entro al switch.
			{
			case 1:
				printf("Entró a la opción 1, ingrese el primer número:\n");
				scanf("%d", &numeroUno);
				printf("El número uno es: %d\n", numeroUno);
				primerNumeroIngresado = 1;
				break;
			case 2:
				printf("Entró a la opción 2, ingrese el segundo número:\n");
				scanf("%d", &numeroDos);
				printf("El número dos es: %d\n", numeroDos);
				segundoNumeroIngresado = 1;
				break;
			case 3:
				if(primerNumeroIngresado && segundoNumeroIngresado){
					printf("Entró a la opción 3, se han calculado todas las operaciones:\n");
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
					printf("Entró a la opción 4, se mostrarán todas las operaciones:\n");
					if (respuestaSuma == 0) // Si el retorno de la función sumar es 0, entra al printf y muestra el resultado.
					{
						printf("\nEl resultado de la suma es: %.2f", suma);
					}
					else
					{
						printf("\nAlgo salió mal.");
					}

					if (respuestaResta == 0)
					{
						printf("\nEl resultado de la resta es: %.2f", resta);
					}
					else
					{
						printf("\nAlgo salió mal.");
					}

					if (respuestaDivision == 0)
					{
						printf("\nEl resultado de la división es: %.2f", division);
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
						printf("\nAlgo salió mal.");
					}
					if (respuestaFactorial == 0 && numeroUno > 0)
					{
						printf("\nEl factorial del primer número es: %ld", factorial);
					}
					else
					{
						printf("\nNo es posible realizar el factorial de un número negativo.");
					}
					if (respuestaFactorialDos == 0 && numeroDos > 0)
					{
						printf("\nEl factorial del segundo número es: %ld\n", factorialDos);
					}
					else
					{
						printf("\nNo es posible realizar el factorial de un número negativo.");
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
