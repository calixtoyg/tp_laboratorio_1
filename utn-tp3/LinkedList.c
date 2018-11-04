//
// Created by yasir on 31-Oct-18.
//
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/**
 * Checks if the menu was valid
 * @param menu int menu number
 * @param min int minimum number included
 * @param max int maximum number included
 * @return int returns 1 if the menu is valid 0 otherwise
 */
int isValidMenu(int menu, int min, int max) {
    if (menu >= min && menu <= max) {
        return 1;
    } else
        return 0;
}

void ll_print(LinkedList* list){
    while(list->pFirstNode != NULL){
        employee_print(list->pFirstNode->data);
        list->pFirstNode = list->pFirstNode->pNextNode;
    }

}

int ll_push(LinkedList* this, void* pElement){
    Node * newNode;
    newNode = malloc(sizeof(Node));
    if (newNode == NULL){
        return -1;
    }
    newNode->data = pElement;
    newNode->pNextNode = this->pFirstNode;
    this->pFirstNode = newNode;

}

void* ll_pop(LinkedList* this){
    int returnData = -1;
    Node * nextNode = NULL;
    if (this->pFirstNode == NULL){
        return (void *) returnData;
    }
    nextNode = this->pFirstNode->pNextNode;
    returnData = this->pFirstNode->pNextNode->data;
    free(this->pFirstNode);
    this->pFirstNode = nextNode;
    return (void *) returnData;
}