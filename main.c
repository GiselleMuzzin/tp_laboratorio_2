#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>

#include "employee.h"
#include "ArrayEmployees.h"

#define MAX_EMPLOYEES 1000

int main()
{
    char employeeName[51];
    char employeeLastName[51];
    float employeeSalary;
    int employeeSector;
    int assignedId = 1;
    int id;
    int option;
    int result;
    int removeResult;
    int modifyResult;
    int index;
    int order = 1;
    int activeEmployeeCount = 0; // Contador de empleados activos en la lista, impide entrar a las opciones 2,3,4 si no hay nadie

    Employee employeesList[MAX_EMPLOYEES];
    initEmployees(employeesList, MAX_EMPLOYEES);

    showMenu();
    option = askForOption();

    while( option!= 5)
    {
        switch(option)
        {
        case 1:
            loadEmployeeInformation (employeeName, employeeLastName, &employeeSalary, &employeeSector);
            result = addEmployee(employeesList, MAX_EMPLOYEES, assignedId, employeeName, employeeLastName, employeeSalary, employeeSector);
            if(result == -1)
            {
                printf("No fue posible agregar un empleado\n\n");
            }
            else
            {
                printEmployees(employeesList, MAX_EMPLOYEES);
                assignedId++;
                activeEmployeeCount++;
                printf("El empleado fue cargado\n\n");
            }
            break;
        case 2: // modificar
            if(activeEmployeeCount == 0)
            {
                printf("No se puede modificar porque no hay empleados cargados\n\n");
            }
            else
            {
                printf("Ingrese el id del empleado a buscar: \n");
                scanf("%d", &id);
                index = findEmployeeById(employeesList, MAX_EMPLOYEES, id);
                if(index == -1)
                {
                    printf("No se encontró el id ingresado\n\n");
                }
                else
                {
                    modifyResult = modifyEmployee(employeesList, MAX_EMPLOYEES, index);
                    if(modifyResult != -1)
                    {
                        printf("El empleado fue modificado\n\n");
                    }
                    else
                    {
                        printf("No fue posible modificar el empleado\n\n");
                    }
                }
            }
            break;
        case 3: // baja
            if(activeEmployeeCount == 0)
            {
                printf("No se puede dar de baja porque no hay empleados cargados\n\n");
            }
            else
            {
                printf("Ingrese el id del empleado a borrar: \n");
                scanf("%d", &id);
                removeResult = removeEmployee(employeesList, MAX_EMPLOYEES, id);
                if(removeResult != -1)
                {
                    printf("El empleado fue eliminado\n\n");
                    activeEmployeeCount--;
                }
                else
                {
                    printf("No se pudo borrar el id ingresado\n\n");
                }
            }
            break;
        case 4: // informar
            if(activeEmployeeCount == 0)
            {
                printf("No se puede informar porque no hay empleados cargados\n\n");
            }
            else
            {
                sortEmployees(employeesList, MAX_EMPLOYEES, order);
                printEmployees(employeesList, MAX_EMPLOYEES);
                showEmployeesSalaries(employeesList, MAX_EMPLOYEES, activeEmployeeCount);
            }
            break;
        default:
            printf("Error, opción inválida\n\n");
            break;
        }
        showMenu();
        option = askForOption();
    }
    return 0;
}
