#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include "ArrayEmployees.h"


/** \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in TRUE in all
* position of the array
* \param list Employee* Pointer to array of employees
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int initEmployees(Employee* list, int len)
{
    if(checkLenAndList(len, list) == 0)
    {
        return -1;
    }


    for(int i= 0; i < len; i++)
    {
        list[i].isEmpty = 1;
    }
    return 0;
}

/** \brief add in an existing list of employees the values received as parameters
* in the first empty position
* \param list employee*
* \param len int
* \param id int
* \param name[] char
* \param lastName[] char
* \param salary float
* \param sector int
* \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
**/
int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector)
{
    if(checkLenAndList(len, list) == 0)
    {
        return -1;
    }

    for(int i = 0; i < len; i++)
    {
        if(list[i].isEmpty == 1) // condición: que este vacío
        {
            list[i].id = id;
            strcpy(list[i].name, name);
            strcpy(list[i].lastName, lastName);
            list[i].salary = salary;
            list[i].sector = sector;
            list[i].isEmpty = 0;

            return 0;
        }
    }
    return -1; // devuelve -1 cuando no hay lugar para agregar empleado
}

/** \brief find an Employee by Id and returns the index position in array.
*
* \param list Employee*
* \param len int
* \param id int
* \return Return employee index position or (-1) if [Invalid length or NULL pointer received or employee not found]
*
*/
int findEmployeeById(Employee* list, int len,int id)
{
    if(checkLenAndList(len, list) == 0)
    {
        return -1;
    }

    for (int i = 0; i < len; i++)
    {
        if(list[i].isEmpty == 0) // condición: que no esté vacío
        {
            if(list[i].id == id)
            {
                return i;
            }
        }
    }
    return -1;
}

/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
*
* \param list Employee*
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't find a employee] - (0) if Ok
*
*/
int removeEmployee(Employee* list, int len, int id)
{
    if(checkLenAndList(len, list) == 0)
    {
        return -1;
    }

    int index = findEmployeeById(list, len, id);

    if(index == -1) // condición: no encontré el id que me pasaron
    {
        return -1;
    }

    list[index].isEmpty = 1; // como lo encontré, lo remuevo

    return 0;
}

/** \brief Sort the elements in the array of employees, the argument order indicates UP or DOWN order
*
* \param list Employee*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int sortEmployees(Employee* list, int len, int order)
{
    if(checkLenAndList(len, list) == 0)
    {
        return -1;
    }

    for (int i = 0; i < len; i++)
    {
        for(int j = i+1; j < len; j++)
        {
            if(list[i].isEmpty ==1) // los elementos vacios los ponemos al final
            {
                swapEmployee(list, i, j);
            }
            else
            {
                if(order == 1)
                {
                    if(list[i].lastName > list[j].lastName || (list[i].lastName == list[j].lastName && list[i].sector > list[j].sector)) // Ordena por apellido y sector de manera ascendente o descendente.
                    {
                        swapEmployee(list, i, j);
                    }
                }
                else
                {
                    if(list[i].lastName < list[j].lastName || (list[i].lastName == list[j].lastName && list[i].sector > list[j].sector)) // Ordena por apellido y sector de manera ascendente o descendente.
                    {
                        swapEmployee(list, i, j);
                    }
                }
            }
        }
    }
    return 0;
}

/** \brief print the content of employees array
*
* \param list Employee*
* \param length int
* \return int
*
*/
int printEmployees(Employee* list, int len)
{
    if(checkLenAndList(len, list) == 0)
    {
        return -1;
    }

    printf(" i     id     Nombre       Apellido    Salario       Sector          \n");
    for(int i = 0; i < len; i++)
    {


        if(list[i].isEmpty == 1)
        {
            printf("%d -\n", i);
        }
        else
        {
            printf("%d %d %s %s %.2f %d\n", i, list[i].id, list[i].name, list[i].lastName, list[i].salary, list[i].sector);
        }
    }

    return 0;
}

int checkLenAndList (int len, Employee* list)
{
    if(len < 0 || list == NULL)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

void swapEmployee(Employee* list, int i, int j)
{
    Employee aux;

    aux = list[i];
    list[i] = list[j];
    list[j] = aux;
}
