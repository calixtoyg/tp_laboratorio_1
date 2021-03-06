
#include "Employee.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

static void initialize(Employee *this, int id, char *name, int salary, int manHours);

//int parseData(char *fileName, Employee *arrayPersonas[]) {
//
//    int readLine, i = 0, size = 2;
//    char id[50], lastName[50], name[50], age[50];
//    arrayPersonas = (Employee **) malloc(sizeof(Employee *) * size);
//
//    FILE *pFile;
//    pFile = fopen(fileName, "r");
//
//    if (pFile == NULL) {
//
//        return -1;
//    }
//    printf("---------Arreglo adentro de la funcion parseData-------------\n");
//    readLine = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, name, lastName, age);
//    do {
//        readLine = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, name, lastName, age);
//        if (readLine == 4) {
//
//
//
//            arrayPersonas[i] = employee_newWithData(atoi(id), name, lastName, atoi(age));
//            printf("-------------------------------------------------------------\n");
//            printf("%s\n",person_getName(arrayPersonas[i]));
//            printf("%s\n",person_getLastName(arrayPersonas[i]));
//            printf("%d\n",person_getAge(arrayPersonas[i]));
//            printf("%d\n",person_getId(arrayPersonas[i]));
//            printf("-------------------------------------------------------------\n");
//
//
//
//            i++;
//            if (i >= size) {
//                // incrementamos el tama�o del array
//                size += 10;
//                arrayPersonas = realloc(arrayPersonas, sizeof(Employee *) * size);
//            }
//
//
//        }
//    } while (!feof(pFile));
//    printf("-------------------------------------------------------------\n");
//    fclose(pFile);
//    return i;
//}

/** \brief  Reseva espacio en meomoria para una nueva Personaa y la inicializa
*
* \param int id Age de la Personaa
* \param int something Otros datos
* \return Persona* Retorna un puntero a la Personaa o NULL en caso de error
* TODO LOS DATOS DE LA ESTRUCTURA PersonaA
*/
Employee *employee_newWithData(int id, char *name, int salary, int manHours) {
    Employee *this = malloc(sizeof(Employee));
    if (this != NULL)
        initialize(this, id, name, salary, manHours);
    return this;
}

/** \brief  Inicializa a una Personaa recibida como parametro
 * \param Persona* this Puntero a la Personaa
 * \param int id Age de la Personaa
 * \param int something Otros datos
 * \return void
 *
 */
static void initialize(Employee *this, int id, char *name, int salary, int manHours) {

    this->id = id;
    strcpy(this->name, name);
    this->salary = salary;
    this->manHours = manHours;
}


/** \brief  Setea la age de una Personaa recibida como parametro
 * \param Persona* this Puntero a la Personaa
 * \param int id Age de la Personaa
 * \return void
 *
 */
int employee_setId(Employee *this, int id) {
    if (id > 0)
        this->id = id;
    else
        return -1;
}

/** \brief Obtiene la age de una Personaa recibida como parametro
 * \param Persona* this Puntero a la Personaa
 * \return int id Age de la Personaa
 *
 */
int employee_getId(Employee *this) {
    return this->id;
}

void employee_setName(Employee *this, char *name) {
    strcpy(this->name, name);
}

char *employee_getName(Employee *this) {
    return this->name;
}

int employee_getSalary(Employee *this) {
    return this->salary;
}

int employee_setSalary(Employee *this, int salary) {
    if (salary > 0)
        this->salary = salary;
    else
        return -1;
}

int employee_getManHours(Employee *this) {
    return this->manHours;
}

int employee_setManHours(Employee *this, int manHours) {
    if (manHours > 0)
        this->manHours = manHours;
    else
        return -1;
}


/** \brief Libera el espacio ocupado por una Personaa recibida como parametro
 * \param Persona* this Puntero a la Personaa
 * \return void
 *
 */
void employee_free(Employee *this) {
    // Do any other freeing required here.
    free(this);
}

void employee_print(Employee *employee) {
    printf("-----------------------------------------------------\n");
    printf("Nombre  : %s\n", employee->name);
    printf("Salario : %d\n", employee->salary);
    printf("Horas Trabajadas : %d\n", employee->manHours);
    printf("ID      : %d\n", employee->id);
    printf("-----------------------------------------------------\n");
}

Employee *employee_new() {
    Employee *employee = malloc(sizeof(Employee));
    if (employee == NULL) {
        return -1;
    } else
        return employee;
}

void* employee_sort(void *pEmployee1, void *pEmployee2) {

    Employee *employee1 = pEmployee1;
    Employee *employee2 = pEmployee2;

    if (strcmp(employee1->name, employee2->name) > 0)
        return employee1;
    else
        return employee2;


}
/*int employee_equals(void *pElement, Node *currentNode) {
    return !strcmp(strupr(employee_getName(currentNode->data)), strupr(employee_getName(pElement)))
           && employee_getId(currentNode->data) == employee_getId(pElement)
           && employee_getManHours(currentNode->data) == employee_getManHours(pElement)
           && employee_getSalary(currentNode->data) == employee_getSalary(pElement);
}*/





