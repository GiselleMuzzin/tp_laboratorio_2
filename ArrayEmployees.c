#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdio_ext.h>
#include "ArrayEmployees.h"

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

int modifyEmployee (Employee* list, int len, int index)
{
    int option;
    int result = 0;

    if(checkLenAndList(len, list) == 0 || index < 0 || index >= len)
    {
        result = -1;
    }
    else
    {
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
    return result;

}


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

void showEmployeesSalaries(Employee* list, int len, int activeEmployeeCount)
{
    int employeesOverAverageSalary;
    float averageSalary;
    float totalSalarySum;

    if(checkLenAndList(len, list) != 0)
    {
        totalSalarySum = salarySum(list, len);
        averageSalary =  totalSalarySum / activeEmployeeCount;

        employeesOverAverageSalary = employeesOverSalaryCalculation(list, len, averageSalary);

        printf("El total de los salarios es %.2f y el promedio es %.2f. Los empleados cuyos salarios superan el sueldo promedio son %d.\n", totalSalarySum, averageSalary, employeesOverAverageSalary);
    }
    else
    {
        printf("La lista de empleados o su tamaño son invalidos");
    }
}

float salarySum(Employee* list, int len)
{
    // Total y promedio de los salarios
    float salariesEmployeesSum;

    salariesEmployeesSum = 0;

    for (int i = 0; i < len; i++)
    {
        if(list[i].isEmpty == 0)
        {
            salariesEmployeesSum = salariesEmployeesSum + list[i].salary;
        }
    }

    return salariesEmployeesSum;
}

int employeesOverSalaryCalculation(Employee* list, int len, float salaryToCompare)
{
    // cuántos empleados superan el salario promedio.
    int employeesOverSalaryToCompare;

    employeesOverSalaryToCompare = 0;

    if(checkLenAndList(len, list) != 0)
    {
        for (int i = 0; i < len; i++)
            {
                if(list[i].isEmpty == 0)
                {
                    if(list[i].salary > salaryToCompare)
                        {
                            employeesOverSalaryToCompare++;
                        }
                }
            }
    }
    return employeesOverSalaryToCompare;
}

int printEmployees(Employee* list, int len)
{
    int result;

    result = -1;

    if(checkLenAndList(len, list) != 0)
    {
        printf("i\tid\tNombre\tApellido\tSalario\tSector\n");
        for(int i = 0; i < len; i++)
        {
            if(list[i].isEmpty == 1)
            {
                printf("%d \n", i);
            }
            else
            {
                printf("%4d\t%4d\t%s\t%s\t%.2f\t%d\n", i, list[i].id, list[i].name, list[i].lastName, list[i].salary, list[i].sector);
            }
        }
        result = 0;
    }
    printf("\n");
    return result;
}

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

int askForOption()
{
    int option;
    printf("Ingrese opcion\n");
    scanf("%d", &option);
    while(option < 1 || option > 5)
    {
        printf("Opcion invalida, reingrese opcion\n");
        scanf("%d", &option);
    }
    return option;
}

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
    while(employeeSalary <= 0)
    {
        printf("Error, reingrese salario: ");
        scanf("%f", employeeSalary);
    }
}

void loadSector(int* employeeSector)
{
    printf("Ingrese sector: ");
    scanf("%d", employeeSector);
}
