#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main() {
    int option = 0;
    LinkedList *arrayListEmployee = ll_newLinkedList();
    ll_push(arrayListEmployee, employee_newWithData(5, "Alfredo", 10000, 4));
    ll_push(arrayListEmployee, employee_newWithData(4, "Juan", 10000, 4));
    ll_push(arrayListEmployee, employee_newWithData(3, "Pablo", 10000, 4));
    ll_push(arrayListEmployee, employee_newWithData(2, "Carlos", 10000, 4));
    ll_push(arrayListEmployee, employee_newWithData(1, "Capitan", 10000, 4));
//    Employee* data = ll_remove(arrayListEmployee,1);
    ll_print(arrayListEmployee);
//    printf("    %s    \n\n\n",employee_getName(data));
    printf("    %d    \n\n\n",ll_indexOf(arrayListEmployee, employee_newWithData(2, "pEdRo", 10000, 4)));
    ll_add(arrayListEmployee,5, employee_newWithData(3, "NUEVA DATA", 10000, 2));
    ll_add(arrayListEmployee,6, employee_newWithData(6, "NUEVA DATA", 10000, 2));
    ll_add(arrayListEmployee,7, employee_newWithData(6, "NUEVA DATA", 10000, 2));
    ll_set(arrayListEmployee,7,employee_newWithData(99, "NUEVA DATA PEGADA", 10000, 2));
    ll_print(arrayListEmployee);

    printf("EL TAMAÑO : %d",ll_len(arrayListEmployee));






//    do{
//        printf("------------------------ MENU JUEGOS ----------------------\n");
//        printf("| 1 - ALTA                                                 |\n");
//        printf("|                                                          |\n");
//        printf("| 2 - MODIFICAR                                            |\n");
//        printf("|                                                          |\n");
//        printf("| 3 - BAJA                                                 |\n");
//        printf("|                                                          |\n");
//        printf("| 4 - LISTA                                                |\n");
//        printf("|                                                          |\n");
//        printf("| 5 - RETORNAR A MENU PRINCIPAL                            |\n");
//        printf("------------------------------------------------------------\n");
//        fflush(stdin);
//        scanf("%d", &employeeMenu);
//        if (!isValidMenu(employeeMenu, 1, 5))
//        {
//            printf("El numero ingresado no es valido.\n");
//            menuJuegos = 0;
//        }
//        switch(option)
//        {
//            case 1:
////                controller_loadFromText("data.csv",listaEmpleados);
//                break;
//        }
//    }while(option != 10);
    return 0;
}
