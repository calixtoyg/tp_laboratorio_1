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
    LinkedList *arrayListEmployee = NULL;
    arrayListEmployee = malloc(sizeof(LinkedList));
    arrayListEmployee->pFirstNode = malloc(sizeof(Node));
    arrayListEmployee->pFirstNode->data = employee_newWithData(1, "Carlos", 10000, 4);
    arrayListEmployee->pFirstNode->pNextNode = NULL;
    arrayListEmployee->pFirstNode->pNextNode = malloc(sizeof(Node));
    arrayListEmployee->pFirstNode->pNextNode->data = employee_newWithData(2, "Pedro", 10000, 4);
    arrayListEmployee->pFirstNode->pNextNode->pNextNode = NULL;
//    ll_print(arrayListEmployee);

    ll_push(arrayListEmployee, employee_newWithData(2, "Pijazo", 10000, 4));
    ll_pop(arrayListEmployee);
    ll_print(arrayListEmployee);



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
