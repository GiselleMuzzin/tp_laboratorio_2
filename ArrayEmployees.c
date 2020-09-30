#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdio_ext.h>
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
    int result;

    if(checkLenAndList(len, list) == 0)
    {
        result = -1;
    }
    else
    {
        for(int i= 0; i < len; i++)
        {
            list[i].isEmpty = 1;
        }
        result = 0;
    }
    return result;
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
    int result;
    int flagRoomAvailable = 0; // Bandera para indicar si encontré lugar

    if(checkLenAndList(len, list) == 0)
    {
        result = -1;
    }
    else
    {
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
                flagRoomAvailable = 1;
                result = 0;
                break; // uso break porque solo necesito un lugar vacío
            }
        }
        if(flagRoomAvailable == 0)
        {
            result = -1; // devuelve -1 cuando no hay lugar para agregar empleado
        }
    }
    return result;
}

/** \brief find an Employee by Id and returns the index position in array.
*
* \param list Employee*
* \param len int
* \param id int
* \return Return employee index position or (-1) if [Invalid length or NULL pointer received or employee not found]
*
*/
int findEmployeeById(Employee* list, int len, int id)
{
    int result;

    result = -1;

    if(checkLenAndList(len, list) != 0)
    {
        for (int i = 0; i < len; i++)
        {
            if(list[i].isEmpty == 0) // condición: que no esté vacío
            {
                if(list[i].id == id)
                {
                    result = i;
                    break;
                }
            }
        }
    }
    return result;
}

void modifyEmployee (Employee* list, int len, int index)
{
    int option;

    showModificationMenu();

    option = askForOption();

    while(option != 5)
    {
        switch(option)
        {
            case 1:
                loadName(list[index].name);
                break;
            case 2:
                loadSurname(list[index].lastName);
                break;
            case 3:
                loadSalary (&(list[index].salary));
                break;
            case 4:
                loadSector(&(list[index].sector));
                break;
            default:
                printf("Error, opción inválida.\n");
                break;
        }
        showModificationMenu();
        option = askForOption();
    }
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
    int result;

    int index = findEmployeeById(list, len, id);

    if(index == -1) // condición: no encontré el id que me pasaron
    {
        result = -1;
    }
    else
    {
        list[index].isEmpty = 1; // como lo encontré, lo remuevo

        result = 0;
    }
    return result;
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
    int result;

    result = -1;

    if(checkLenAndList(len, list) != 0)
    {
        for (int i = 0; i < len; i++)
        {
            for(int j = i+1; j < len; j++)
            {
                if(list[i].isEmpty ==1) // los elementos vacios van al final
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
        result = 0;
    }
    return result;
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
    int result;

    result = -1;

    if(checkLenAndList(len, list) != 0)
    {
        printf("i   id     Nombre       Apellido    Salario       Sector          \n");
        for(int i = 0; i < len; i++)
        {
            if(list[i].isEmpty == 1)
            {
                printf("%d -\n", i);
            }
            else
            {
                printf("%d %4d %s %s %.2f %d\n", i, list[i].id, list[i].name, list[i].lastName, list[i].salary, list[i].sector);
            }
        }
        result = 0;
    }
    return result;
}

/** \brief verifies length and null
*
* \param list Employee*
* \param length int
* \return int
*
*/
int checkLenAndList (int len, Employee* list)
{
    int result;

    if(len < 0 || list == NULL)
    {
        result = 0;
    }
    else
    {
        result = 1;
    }
    return result;
}

void swapEmployee(Employee* list, int i, int j)
{
    Employee aux;

    aux = list[i];
    list[i] = list[j];
    list[j] = aux;
}
/** \brief solicita al usuario que ingrese la opción del menú que desea ejecutar
*
*   \param
*
*   \return el número de la opción elegida
**/
int askForOption()
{
    int option;
    printf("Ingrese opcion\n");
    __fpurge(stdin);
    scanf("%d", &option);
    while(option < 1 || option > 5)
    {
        printf("Opcion invalida, reingrese opcion\n");
        scanf("%d", &option);
    }
    return option;
}

/** \brief muestra el menú por pantalla
*
*   \param
*
*   \return void
**/
void showMenu()
{
    printf("***MENU DE OPCIONES***\n");
    printf("1_ Alta\n");
    printf("2_ Modificar\n");
    printf("3_ Baja\n");
    printf("4_ Informar\n");
    printf("5_ Salir\n");
    printf("\n");
}

void showModificationMenu()
{
    printf("***Seleccione el campo a modificar***\n");
    printf("1_ Nombre\n");
    printf("2_ Apellido\n");
    printf("3_ Salario\n");
    printf("4_ Sector\n");
    printf("5_ Finalizar modificacion\n");
    printf("\n");
}

void loadEmployeeInformation (char* employeeName, char* employeeLastName, float* employeeSalary, int* employeeSector)
{
    loadName(employeeName);
    loadSurname (employeeLastName);
    loadSalary (employeeSalary);
    loadSector(employeeSector);
}

void loadName(char* employeeName)
{
    printf("Ingrese nombre: ");
    __fpurge(stdin);
    scanf("%s", employeeName);
}

void loadSurname (char* employeeLastName)
{
    printf("Ingrese apellido: ");
    __fpurge(stdin);
    scanf("%s", employeeLastName);
}

void loadSalary (float* employeeSalary)
{
    printf("Ingrese salario: ");
    scanf("%f", employeeSalary);
    // TODO validar q sea mayor a 0
}

void loadSector(int* employeeSector)
{
    printf("Ingrese sector: ");
    scanf("%d", employeeSector);
    // TODO validar???

}
