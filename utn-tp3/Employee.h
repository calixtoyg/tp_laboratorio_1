#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED

#include "LinkedList.h"

typedef struct
{
    int id;
    char name[128];
    int manHours;
    int salary;
}Employee;

Employee* employee_new();
Employee *employee_newWithData(int id, char *name, int salary, int manHours);

void employee_delete();

int employee_setId(Employee* employee,int id);
int employee_getId(Employee* employee);

void employee_setName(Employee* employee,char* name);
char* employee_getName(Employee* employee);

int employee_setManHours(Employee* employee,int manHours);
int employee_getManHours(Employee *employee);

int employee_setSalary(Employee* employee,int salary);
int employee_getSalary(Employee* employee);

void employee_print(Employee* employee);
int employee_equals(void *pElement, Node *currentNode);

void* employee_sort(void* pEmployee1,void* pEmployee2);

#endif // employee_H_INCLUDED
