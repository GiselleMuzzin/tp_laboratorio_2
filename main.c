#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>

#include "employee.h"
#include "ArrayEmployees.h"
/*
El sistema deberá tener el siguiente menú de opciones:
1. ALTAS: Se debe permitir ingresar un empleado calculando automáticamente el número
de Id. El resto de los campos se le pedirá al usuario.
2. MODIFICAR: Se ingresará el Número de Id, permitiendo modificar: o Nombre o Apellido
o Salario o Sector
3. BAJA: Se ingresará el Número de Id y se eliminará el empleado del sistema.
4. INFORMAR:
1. Listado de los empleados ordenados alfabéticamente por Apellido y Sector.
2. Total y promedio de los salarios, y cuántos empleados superan el salario promedio.
NOTA: Se deberá realizar el menú de opciones y las validaciones a través de funciones.
Tener en cuenta que no se podrá ingresar a los casos 2, 3 y 4; sin antes haber realizado la
carga de algún empleado.
*/

#define MAX_EMPLOYEES 1

int main()
{
    int option;
    // int id;
    int assignedId = 1;
    char employeeName[51];
    char employeeLastName[51];
    float employeeSalary;
    int employeeSector;
    // int isEmpty;
    Employee employeesList[MAX_EMPLOYEES];
    initEmployees(employeesList, MAX_EMPLOYEES);

    printf("***MENU DE OPCIONES***\n");
    printf("1_ Alta\n");
    printf("2_ Modificar\n");
    printf("3_ Baja\n");
    printf("4_ Informar\n");
    printf("5_ Salir\n");
    printf("Ingrese opción: \n");

    scanf("%d", &option);

    while( option!=5)
    {
        switch(option)
        {

        case 1:
            printf("Ingrese nombre: \n");
            __fpurge(stdin);
            scanf("%s", employeeName);

            printf("Ingrese apellido: \n");
            __fpurge(stdin);
            scanf("%s", employeeLastName);

            printf("Ingrese salario: \n");
            scanf("%f", &employeeSalary);

            printf("Ingrese sector: \n");
            scanf("%d", &employeeSector);


            int result = addEmployee(employeesList, MAX_EMPLOYEES, assignedId, employeeName, employeeLastName, employeeSalary, employeeSector);
            if(result == -1)
            {
                    printf("No fue posible agregar un empleado\n");
            }
            else
            {
                printEmployees(employeesList, MAX_EMPLOYEES);
                assignedId++;
            }
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        default:
            printf("Error, opción inválida");
            break;
        }
    }
    return 0;
}
