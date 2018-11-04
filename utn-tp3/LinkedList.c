//
// Created by yasir on 31-Oct-18.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "LinkedList.h"
#include "Employee.h"

int employee_equals(void *pElement,Node *currentNode);

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
    Node *temporary = list->pFirstNode;
    while(temporary != NULL){
        employee_print(temporary->data);
        temporary = temporary->pNextNode;
    }

}

int ll_push(LinkedList* this, void* pElement){
    Node * newNode;
    newNode = malloc(sizeof(Node));
    if (newNode == NULL){
        return NULL;
    }
    newNode->data = pElement;
    newNode->pNextNode = this->pFirstNode;
    this->pFirstNode = newNode;
    this->size += 1;


}

void* ll_pop(LinkedList* this){
    void* returnData = NULL;
    Node * nextNode = NULL;
    if (this->pFirstNode == NULL){
        return returnData;
    }
    nextNode = this->pFirstNode->pNextNode;
    returnData = this->pFirstNode->pNextNode->data;
    free(this->pFirstNode);
    this->pFirstNode = nextNode;
    this->size -= 1;
    return returnData;
}

LinkedList* ll_newLinkedList(void){
    LinkedList* linkedList = malloc(sizeof(LinkedList));
    if (linkedList == NULL){
        return linkedList;
    }
    linkedList->pFirstNode = NULL;
    linkedList->size = 0;
    return linkedList;
}

void* ll_get(LinkedList* this, int index){
    void* returnData = NULL;
    int i = 0;
    Node * currentNode = this->pFirstNode;
    Node * temporaryNode = NULL;
    if (index == 0) {
        return ll_pop(this);
    }
    for (i = 0; i < index-1; i++) {
        if (currentNode->pNextNode == NULL) {
            return -1;
        }
        currentNode = currentNode->pNextNode;
    }
    return currentNode->pNextNode->data;


}

int ll_indexOf(LinkedList* this, void* pElement){
    int index;
    Node * currentNode = this->pFirstNode;
    for (index = 0; currentNode != NULL; ++index) {
        if(employee_equals(pElement, currentNode)){
            return index;

        }
        currentNode = currentNode->pNextNode;

    }
    return -1;

}

int employee_equals(void *pElement,Node *currentNode) {
    return !strcmp(strupr(employee_getName(currentNode->data)), strupr(employee_getName(pElement)))
           && employee_getId(currentNode->data) == employee_getId(pElement)
           && employee_getManHours(currentNode->data) == employee_getManHours(pElement)
           && employee_getSalary(currentNode->data) == employee_getSalary(pElement);
}

void* ll_remove(LinkedList* this,int index){
    void* returnData = NULL;
    int i = 0;
    Node * currentNode = this->pFirstNode;
    Node * temporaryNode = NULL;
    if (index == 0) {
        return ll_pop(this);
    }
    for (i = 0; i < index-1; i++) {
        if (currentNode->pNextNode == NULL) {
            return (void *) -1;
        }
        currentNode = currentNode->pNextNode;
    }
    temporaryNode = currentNode->pNextNode;
    returnData = temporaryNode->data;
    currentNode->pNextNode = temporaryNode->pNextNode;
    free(temporaryNode);
    this->size -= 1;
    return returnData;
}

int ll_len(LinkedList* this){
    if(this == NULL){
        printf("Lista vacia");
        return -1;
    }else
        return this->size;
}