#include <stdio.h>
#include <stdlib.h>
#include <io.h>
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
    char buf[1024]; // hack, but fine for this
    printf("%s\n", getcwd(buf, 1024));
    int option = 0, num = 24;
    FILE *pFile;
    LinkedList *listaEmpleados = ll_newLinkedList();
    do {
        scanf("%d", &option);
        switch (option) {
            case 1:
                controller_loadFromText("data.csv", listaEmpleados);
                break;
            case 2:
                controller_loadFromBinary("data-binary", listaEmpleados);
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
                do {
                    employee_print(ll_get(listaEmpleados, num));
                    num--;
                } while (num >= 0);
                break;
            case 25:
                pFile = fopen("data.csv", "a");
                fprintf(pFile, "%s,%s,%s,%s\n", "funciona esto?", "creo", "que", "si");
                fclose(pFile);
                break;
            case 7:
                controller_loadFromBinary("data-binary", listaEmpleados);
                break;
            case 8:
                controller_saveAsText("path",listaEmpleados);
                break;
            case 9:
                controller_saveAsBinary("path",listaEmpleados);
                break;
        }
    } while (option != 10);
    return 0;
}
