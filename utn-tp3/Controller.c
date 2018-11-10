#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "functionsForProjects.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int 1 exito -1 error
 *
 */
int controller_loadFromText(char *path, LinkedList *pArrayListEmployee) {
    FILE *pFile;
    pFile = fopen(path, "r");
    if (pFile == NULL){
        printf("El archivo no se puede abrir o esta vacio.\n");
        return -1;
    }
    parser_EmployeeFromText(pFile, pArrayListEmployee);
    fclose(pFile);
    return 1;
}


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int 1 exito -1 error
 *
 */
int controller_loadFromBinary(char *path, LinkedList *pArrayListEmployee) {
    FILE *pFile = fopen(path, "rb");
    if (pFile == NULL){
        printf("El archivo no se puede abrir o esta vacio.\n");
        return -1;
    }
    parser_EmployeeFromBinary(pFile, pArrayListEmployee);
    fclose(pFile);
    return 1;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int 1 exito -1 error
 *
 */
int controller_addEmployee(LinkedList *pArrayListEmployee) {
    if (!ll_isEmpty(pArrayListEmployee))
        return -1;

    char nombre[50];
    int salary, manHours;

    getStringLettersOnly(nombre, "Ingrese el nombre: \n", 50, 3);
    getEntero(&salary, "Ingrese el salario: \n", "El numbero es invalido.\n", 0, 410065408, 3);
    getEntero(&manHours, "Ingrese la cantidad de horas que trabaja: \n", "El numbero es invalido.\n", 0, 24, 3);
    Employee *employee = employee_newWithData(pArrayListEmployee->size + 1, nombre, salary, manHours);
    ll_add(pArrayListEmployee, employee);
    return 1;

}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int 1 exito -1 error
 *
 */
int controller_editEmployee(LinkedList *pArrayListEmployee) {
    if (ll_isEmpty(pArrayListEmployee)){
        return -1;
    }
    LinkedList *temp;
    char nombre[50];
    int i = 0;
    int salary, manHours, id;
    int returNumber = getEntero(&id, "Ingrese el ID del empleado a editar: \n",
                                "El ID es invalido o no se encuentra en la lista.\n", 1, pArrayListEmployee->size, 0);
    if (returNumber == -1)
        return -1;
    temp = ll_get(pArrayListEmployee, id - 1);
    if (temp == NULL) {
        return -1;
    }
    getStringLettersOnly(nombre, "Ingrese el nombre: \n", 50, 3);
    getEntero(&salary, "Ingrese el salario: \n", "El numero es invalido.\n", 0, 410065408, 3);
    getEntero(&manHours, "Ingrese la cantidad de horas que trabaja: \n", "El numbero es invalido.\n", 0, 24, 3);
    Employee *employee = employee_newWithData(id, nombre, salary, manHours);
    printf("Employee editado con exito.\n");
    ll_set(pArrayListEmployee, id - 1, employee);
    return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int 1 exito -1 error
 *
 */
int controller_removeEmployee(LinkedList *pArrayListEmployee) {
    if (ll_isEmpty(pArrayListEmployee)){
        return -1;
    }
    int id;
    int returNumber = getEntero(&id, "Ingrese el ID del empleado a eliminar: \n",
                                "El ID es invalido o no se encuentra en la lista.\n", 1, pArrayListEmployee->size, 0);
    if (ll_remove(pArrayListEmployee, id - 1) == -1 && returNumber == -1) {
        return -1;
    } else {
        printf("Employee borrado con exito.\n");
        return 1;
    }
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int 1 exito -1 error
 *
 */
int controller_ListEmployee(LinkedList *pArrayListEmployee) {
    if (ll_isEmpty(pArrayListEmployee)){
        return -1;
    }
    if (ll_print(pArrayListEmployee) == -1)
        return -1;
    return 1;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int 1 exito -1 error
 *
 */
int controller_sortEmployee(LinkedList *pArrayListEmployee) {
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int 1 exito -1 error
 *
 */
int controller_saveAsText(char *path, LinkedList *pArrayListEmployee) {
    FILE* pFile;
    int i=0;
    Employee *employee;
    LinkedList *listCloned = ll_newLinkedList();
    listCloned = ll_clone(pArrayListEmployee);
    pFile = fopen(path, "a+");
    if (pFile == NULL){
        return -1;
    }
    if (ll_isEmpty(pArrayListEmployee)){
        fclose(pFile);
        return -1;
    }
    do{

        employee = ll_get(listCloned,i);
        fwrite(employee, sizeof(Employee), 1, pFile);

    }while(ll_remove(listCloned, 0) != 0) ;
    fclose(pFile);
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int 1 exito -1 error
 *
 */
int controller_saveAsBinary(char *path, LinkedList *pArrayListEmployee) {
    FILE* pFile;
    int i=0;
    Employee *employee;
    LinkedList *listCloned = ll_newLinkedList();
    listCloned = ll_clone(pArrayListEmployee);
    pFile = fopen(path, "wb+");
    if (pFile == NULL){
        return -1;
    }
    if (ll_isEmpty(pArrayListEmployee)){
        fclose(pFile);
        return -1;
    }
    do{

        employee = ll_get(listCloned,i);
        fwrite(employee, sizeof(Employee), 1, pFile);

    }while(ll_remove(listCloned, 0) != 0) ;
    fclose(pFile);
    return 1;

}

