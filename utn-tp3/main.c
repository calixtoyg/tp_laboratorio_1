#include <stdio.h>
#include <stdlib.h>
#include <io.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "functionsForProjects.h"

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
    char pathToReadBinary[1024] = "\0";
    char pathToReadText[1024] = "\0";
    char pathForText[1024] = "\0";
    char pathForBinary[1024] = "\0";
    int option = 0, num = 0, id, getId;
    FILE *pFile;
    LinkedList *listaEmpleados = ll_newLinkedList();
    do {
        printf("Menu:\n");
        printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
        printf("2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n");
        printf("3. Alta de empleado.\n");
        printf("4. Modificar datos de empleado.\n");
        printf("5. Baja de empleado.\n");
        printf("6. Listar empleados.\n");
        printf("7. Ordenar empleado.\n");
        printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
        printf("9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n");
        printf("10. Salir.\n");
        scanf("%d", &option);
        if (!isValidMenu(option, 1, 10)) {
            printf("Opcion de menu invalido.\n");
            option = 0;
        }
        switch (option) {
            case 1:
                getString(pathToReadText, "Ingrese el path donde se encuentra el CSV.\n");
                if (pathToReadText != "\0")
                    controller_loadFromText(pathToReadText, listaEmpleados);
                break;
            case 2:
                getString(pathToReadBinary, "Ingrese el path donde se encuentra el archivo binario.\n");
                if (pathToReadBinary != "\0")
                    controller_loadFromBinary(pathToReadBinary, listaEmpleados);
                break;
            case 3:
                controller_addEmployee(listaEmpleados);
                break;
            case 4:

                controller_editEmployee(listaEmpleados);
                break;
            case 5:
                controller_removeEmployee(listaEmpleados);
                break;
            case 6:
                controller_ListEmployee(listaEmpleados);
                break;
            case 7:

                break;
            case 8:
                getString(pathForText, "Ingrese el path donde guardar el archivo de texto.\n");
                if (pathForText != "\0")
                    controller_saveAsText(pathForText, listaEmpleados);
                break;
            case 9:
                getString(pathForBinary, "Ingrese el path donde guardar el archivo binario.\n");
                if (pathForBinary != "\0")
                    controller_saveAsBinary(pathForBinary, listaEmpleados);
                break;
        }
    } while (option != 10);
    return 0;
}
