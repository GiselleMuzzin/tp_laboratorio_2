#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED

#include "employee.h"

/** \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in TRUE in all positions of the array
*
* \param list Employee* Pointer to array of employees
* \param len int Array length
*
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
**/
int initEmployees(Employee* list, int len);


/** \brief add in an existing list of employees the values received as parameters in the first empty position
*
* \param list employee* Pointer to array of employees
* \param len int Array length
* \param id int Id of the employee
* \param name[] char Name of the employee
* \param lastName[] char Last name of the employee
* \param salary float Salary of the employee
* \param sector int Sector of the employee
*
* \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
**/
int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector);


/** \brief find an Employee by Id and returns the index position in array.
*
* \param list Employee* Pointer to array of employees
* \param len int Array length
* \param id int Id of the employee
*
* \return Return employee index position or (-1) if [Invalid length or NULL pointer received or employee not found]
**/
int findEmployeeById(Employee* list, int len,int id);


/** \brief modifies the information loaded about an employee.
*
* \param list Employee* Pointer to array of employees
* \param len int Array length
* \param index int index of the employee to modify. Must be a valid index
*
* \return int 0 if the employee could be modified, -1 if [Invalid length or NULL pointer received or invalid index]
**/
int modifyEmployee (Employee* list, int len, int index);


/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
*
* \param list Employee* Pointer to array of employees
* \param len int Array length
* \param id int Id of the employee
*
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't find a employee] - (0) if Ok
**/
int removeEmployee(Employee* list, int len, int id);


/** \brief Sort the elements in the array of employees, the argument order indicates UP or DOWN order
*
* \param list Employee* Pointer to array of employees
* \param len int Array length
* \param order int [1] indicate UP - [0] indicate DOWN
*
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
**/
int sortEmployees(Employee* list, int len, int order);


/** \brief print the content of employees array
*
* \param list Employee* Pointer to array of employees
* \param len int Array length
*
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
**/
int printEmployees(Employee* list, int len);


/** \brief shows the sum of all salaries and the average salary or an error message if params were invalid
*
* \param list Employee* Pointer to array of employees
* \param len int Array length
* \param activeEmployeeCount int the number of active employees
*
* \return void
**/
void showEmployeesSalaries(Employee* list, int len, int activeEmployeeCount);


/** \brief operates the sum of all salaries
*
* \param list Employee* Pointer to array of employees
* \param len int Array length
*
* \return float the sum of all salaries
**/
float salarySum(Employee* list, int len);


/** \brief returns the number of employees that have a salary that is over a comparison salary
*
* \param list Employee* Pointer to array of employees
* \param len int Array length
* \param salaryToCompare float
*
* \return int the amount of employees that have a salary that is over a comparison salary
**/
int employeesOverSalaryCalculation(Employee* list, int len, float salaryToCompare);


/** \brief verifies length and null
*
* \param len int Array length
* \param list Employee* Pointer to array of employees
*
* \return int Return 0 if Invalid length or NULL pointer - 1 if Ok
**/
int checkLenAndList (int len, Employee* list);


/** \brief exchanges the element in the ith position with the one in the jth position
*
* \param list Employee* Pointer to array of employees
* \param i int index in the list of the first element to swap
* \param j int index in the list of the second element to swap
*
* \return void
**/
void swapEmployee(Employee* list, int i, int j);

/** \brief shows menu on the screen
*
*   \param
*
*   \return void
**/
void showMenu();


/** \brief shows the modification menu on the screen
*
*   \param
*
*   \return void
**/
void showModificationMenu();


/** \brief asks the user to select an option from the menu. The option must be a number from 1 to 5.
*
*   \param
*
*   \return int the selected option
**/
int askForOption();


/** \brief allows the user to enter information about the employee
*
*   \param employeeName char* Name of the employee
*   \param employeeLastName char* Last name of the employee
*   \param employeeSalary float* Salary of the employee
*   \param employeeSector int* Sector of the employee
*
*   \return void
**/
void loadEmployeeInformation (char* employeeName, char* employeeLastName, float* employeeSalary, int* employeeSector);


/** \brief asks the user to enter the name of the employee
*
*   \param employeeName char* Name of the employee
*
*   \return void
**/
void loadName(char* employeeName);


/** \brief asks the user to enter the last name of the employee
*
*   \param employeeLastName char* Last name of the employee
*
*   \return void
**/
void loadSurname (char* employeeLastName);


/** \brief asks the user to enter the salary of the employee
*
*   \param employeeSalary float* Salary of the employee
*
*   \return void
**/
void loadSalary (float* employeeSalary);


/** \brief asks the user to enter the sector of the employee
*
*   \param employeeSector int* Sector of the employee
*
*   \return void
**/
void loadSector(int* employeeSector);

#endif // ARRAYEMPLOYEES_H_INCLUDED
