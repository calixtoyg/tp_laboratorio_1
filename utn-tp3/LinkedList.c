#include "LinkedList.h"
#include "Employee.h"
#include <stdio.h>


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