/*
 * ArrayEmployees.h
 *
 *  Created on: 25 sep. 2020
 *      Author: Hzkr
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

#define LONG_NAME 51
#define LONG_LASTNAME 51

typedef struct
{
	int id;
	char name[LONG_NAME];
	char lastName[LONG_LASTNAME];
	float salary;
	int sector;
	int isEmpty;
}Employee;

int employee_initEmployees(Employee* list, int len);
int employee_addEmployee(Employee* pArrayList, int len, int index);
int employee_removeEmployee(Employee* pArrayList, int len, int index, int id);
int employee_findEmpty(Employee* pArrayList, int len, int* pIndex);
int employee_modifyEmployee(Employee* pArrayList, int len, int index);
int employee_findEmployeeById(Employee* pArrayList, int len, int* pIndex, int id);
int employee_printEmployees(Employee* pArrayList, int len);
int employee_sortEmployees(Employee* pArrayList, int len, int order);
int employee_calculateTotalAndAverageSalary(Employee* pArrayList, int len, float* pTotalSalary, float* pAverageSalary, int *pGreaterThanAverage);
int returnId();

#endif /* ARRAYEMPLOYEES_H_ */
