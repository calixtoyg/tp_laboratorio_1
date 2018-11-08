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
 * \return int
 *
 */
int controller_loadFromText(char *path, LinkedList *pArrayListEmployee) {
    FILE *pFile;
    pFile = fopen(path, "r");
    parser_EmployeeFromText(pFile, pArrayListEmployee);
    fclose(pFile);
    return 1;
}


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char *path, LinkedList *pArrayListEmployee) {

    FILE *pFile = fopen(path, "rb");
    parser_EmployeeFromBinary(pFile,pArrayListEmployee);
    fclose(pFile);
    return 1;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList *pArrayListEmployee) {
    Employee *temp = ll_get(pArrayListEmployee,pArrayListEmployee->size);
    char nombre[50];
    int salary,manHours;
    getStringLettersOnly(nombre, "Ingrese el nombre: \n", 50, 3);
    getEntero(&salary,"Ingrese el salario: \n","El numbero es invalido.\n",0,410065408,3);
    getEntero(&manHours,"Ingrese la cantidad de horas que trabaja: \n","El numbero es invalido.\n",0,24,3);
    Employee *employee = employee_newWithData(temp->id+1,nombre,salary,manHours);
    ll_add(pArrayListEmployee, employee);

}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList *pArrayListEmployee) {
    return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList *pArrayListEmployee) {
    return 1;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList *pArrayListEmployee) {
    return 1;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList *pArrayListEmployee) {
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char *path, LinkedList *pArrayListEmployee) {
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char *path, LinkedList *pArrayListEmployee) {
    return 1;
}

