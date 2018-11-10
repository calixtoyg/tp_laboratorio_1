#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

int isFileEmpty(FILE *pFile);

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 * pasar casi todo aca
 */
int parser_EmployeeFromText(FILE *pFile, LinkedList *pArrayListEmployee) {
    int readLine, i = 1;
    char id[50], name[50], salary[50], manHours[50];
    if (isFileEmpty(pFile)) {
        return -1;
    }
    readLine = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, name, salary, manHours);
    do {
        readLine = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, name, salary, manHours);
        if (readLine == 4) {
            if (atoi(id) && atoi(salary) && atoi(manHours)) {

                Employee *employee = employee_newWithData(atoi(id), name, atoi(salary), atoi(manHours));
//                fwrite(employee, sizeof(Employee), 1, pFileBinary);
                ll_add(pArrayListEmployee, employee);
            } else {
                printf("Linea %d contiene uno o mas caracteres que no son numeros.\n", i);
            }
            i++;
        }
    } while (!feof(pFile));
    fclose(pFile);

    return 1;
}

//int parser_EmployeeFromText(FILE *pFile, LinkedList *pArrayListEmployee) {
//    FILE *pFileBinary;
//    pFileBinary = fopen("data-binary", "wb+");
//    int readLine, i = 1;
//    char id[50], name[50], salary[50], manHours[50];
//    if (isFileEmpty(pFile)) {
//        return -1;
//    }
//    readLine = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, name, salary, manHours);
//    do {
//        readLine = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, name, salary, manHours);
//        if (readLine == 4) {
//            if (atoi(id) && atoi(salary) && atoi(manHours)) {
//
//                Employee *employee = employee_newWithData(atoi(id), name, atoi(salary), atoi(manHours));
//                fwrite(employee, sizeof(Employee), 1, pFileBinary);
//                ll_add(pArrayListEmployee, employee);
//            } else {
//                printf("Linea %d contiene uno o mas caracteres que no son numeros.\n", i);
//            }
//            i++;
//        }
//    } while (!feof(pFile));
//    fclose(pFileBinary);
//
//    return 1;
//}


/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE *pFile, LinkedList *pArrayListEmployee) {
    if (isFileEmpty(pFile)) {
        return -1;
    }
    if (pArrayListEmployee == NULL){
        pArrayListEmployee = ll_newLinkedList();
    }
    do {
        Employee *employee = employee_new();
        if(fread(employee, sizeof(Employee), 1, pFile) == 1){
            ll_add(pArrayListEmployee, employee);
        }
    } while (!feof(pFile));
    return 1;
}

int isFileEmpty(FILE *pFile) {
    if (pFile == NULL) {
        printf("El archivo se encuentra vacio\n");
        return -1;
    } else
        return 0;
}
