#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED

#include "employee.h"

int initEmployees(Employee* list, int len);

int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector);

int findEmployeeById(Employee* list, int len,int id);

int removeEmployee(Employee* list, int len, int id);

int sortEmployees(Employee* list, int len, int order);

int printEmployees(Employee* list, int len);

int checkLenAndList (int len, Employee* list);

void swapEmployee(Employee* list, int i, int j);

void showMenu();

void showModificationMenu();

int askForOption();

void loadEmployeeInformation (char* employeeName, char* employeeLastName, float* employeeSalary, int* employeeSector);

void loadName(char* employeeName);
void loadSurname (char* employeeLastName);
void loadSalary (float* employeeSalary);
void loadSector(int* employeeSector);
void modifyEmployee (Employee* list, int len, int index);

#endif // ARRAYEMPLOYEES_H_INCLUDED
