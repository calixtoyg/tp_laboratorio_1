#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
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
int employee_getId(Employee* employee,int* id);

int employee_setNombre(Employee* employee,char* nombre);
int employee_getNombre(Employee* employee,char* nombre);

int employee_setHorasTrabajadas(Employee* employee,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* employee,int* horasTrabajadas);

int employee_setSueldo(Employee* employee,int sueldo);
int employee_getSueldo(Employee* employee,int* sueldo);

void employee_print(Employee* employee);

#endif // employee_H_INCLUDED
