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
    int id;
    int assignedId = 1;
    char employeeName[51];
    char employeeLastName[51];
    float employeeSalary;
    int employeeSector;
    int removeResult;
    int index;
    // int isEmpty;
    int order=0; // revisarrrr

    // Contador de empleados activos en la lista, para impedir entrar a las opciones 2,3,4 si no hay nadie
    int activeEmployeeCount = 0;


    Employee employeesList[MAX_EMPLOYEES];
    initEmployees(employeesList, MAX_EMPLOYEES);

    showMenu();
    option = askForOption();

    while( option!=5)
    {
        switch(option)
        {
        case 1:
            loadEmployeeInformation (employeeName, employeeLastName, &employeeSalary, &employeeSector);

            int result = addEmployee(employeesList, MAX_EMPLOYEES, assignedId, employeeName, employeeLastName, employeeSalary, employeeSector);
            if(result == -1)
            {
                printf("No fue posible agregar un empleado\n");
            }
            else
            {
                printEmployees(employeesList, MAX_EMPLOYEES);
                assignedId++;
                activeEmployeeCount++;
            }
            break;
        case 2: // modificar
            if(activeEmployeeCount == 0)
            {
                printf("No se puede modificar porque no hay empleados cargados.\n");
            }
            else
            {
                printf("Ingrese el id del empleado a buscar: \n");
                scanf("%d", &id);

                index = findEmployeeById(employeesList, MAX_EMPLOYEES, id);

                if(index == -1)
                {
                    printf("No se encontró el id ingresado.\n");
                }
                else
                {
                    modifyEmployee(employeesList, MAX_EMPLOYEES, index);
                    printf("Empleado modificado.\n");
                }

            }
            break;
        case 3: // baja
            if(activeEmployeeCount == 0)
            {
                printf("No se puede dar de baja porque no hay empleados cargados.\n");
            }
            else
            {
                printf("Ingrese el id del empleado a borrar: \n");
                scanf("%d", &id);
                removeResult = removeEmployee(employeesList, MAX_EMPLOYEES, id);
                if(removeResult != -1){
                    printf("Empleado eliminado.\n");
                    activeEmployeeCount--;
                }
                else{
                    printf("No se pudo borrar el id ingresado.\n");
                }


            }
            break;
        case 4: // informar
            if(activeEmployeeCount == 0)
            {
                printf("No se puede informar porque no hay empleados cargados.\n");
            }
            else
            {
                sortEmployees(employeesList, MAX_EMPLOYEES, order);

                printEmployees(employeesList, MAX_EMPLOYEES);
            }
            break;
        default:
            printf("Error, opción inválida.\n");
            break;
        }
    showMenu();
    option = askForOption();
    }
    return 0;
}
