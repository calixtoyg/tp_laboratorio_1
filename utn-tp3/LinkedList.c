#include "LinkedList.h"
#include "Employee.h"
#include <stdio.h>
#include <string.h>


int ll_print(LinkedList *list) {
    if (ll_isEmpty(list)) {
        return -1;
    }
    Node *temporary = list->pFirstNode;
    while (temporary != NULL) {
        employee_print(temporary->pElement);
        temporary = temporary->pNextNode;
    }
    return 0;

}

int ll_sorting(LinkedList *this, int order) {
//    Node *temporaryNode;
//    LinkedList *temp = this;
//    Employee *employee1;
//    Employee *employee2;
//    for (int i = 0; ll_get(this,i) != NULL ; ++i) {
//        employee1 = ll_get(this, i);
//        for (int j = i+1; ll_get(this,j) != NULL; ++j) {
//            employee2 = ll_get(this, j);
//            if (employee2 != NULL && strcmp(employee_getName(employee1), employee_getName(employee2)) > 0) {
//                ll_remove(this,i);
//                ll_set(this, i, employee2);
//                ll_remove(this,j);
//                ll_set(this, j, employee1);
//            }
//        }
//    }


    return 0;
}