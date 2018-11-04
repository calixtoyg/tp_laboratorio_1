//
// Created by yasir on 31-Oct-18.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "LinkedList.h"
#include "Employee.h"

int employee_equals(void *pElement, Node *currentNode);

Node *_ll_createNode(Node *next, void *pElement);

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

void ll_print(LinkedList *list) {
    Node *temporary = list->pFirstNode;
    while (temporary != NULL) {
        employee_print(temporary->data);
        temporary = temporary->pNextNode;
    }

}

int ll_push(LinkedList *this, void *pElement) {
    Node *newNode;
    newNode = malloc(sizeof(Node));
    if (newNode == NULL) {
        return NULL;
    }
    newNode->data = pElement;
    newNode->pNextNode = this->pFirstNode;
    this->pFirstNode = newNode;
    this->size += 1;
    return 0;

}

void *ll_pop(LinkedList *this) {
    void *returnData = NULL;
    Node *nextNode = NULL;
    if (this->pFirstNode == NULL) {
        return returnData;
    }
    nextNode = this->pFirstNode->pNextNode;
    returnData = this->pFirstNode->pNextNode->data;
    free(this->pFirstNode);
    this->pFirstNode = nextNode;
    this->size -= 1;
    return returnData;
}

int ll_add(LinkedList *this, int index, void *pElement) {
    int i = 0;
    Node *currentNode = this->pFirstNode;
    if (index == 0) {
        return ll_push(this, pElement);
    }
    for (i = 0; i < index - 1; i++) {
        if (currentNode->pNextNode == NULL) {
            printf("Index out of bound.\n");
            return -1;
        }
        currentNode = currentNode->pNextNode;
    }
    Node *newNode = _ll_createNode(currentNode->pNextNode, pElement);
    currentNode->pNextNode = newNode;
    this->size += 1;

    return 0;

}

LinkedList *ll_newLinkedList(void) {
    LinkedList *linkedList = malloc(sizeof(LinkedList));
    if (linkedList == NULL) {
        return linkedList;
    }
    linkedList->pFirstNode = NULL;
    linkedList->size = 0;
    return linkedList;
}

void *ll_get(LinkedList *this, int index) {
    void *returnData = NULL;
    int i = 0;
    Node *currentNode = this->pFirstNode;
    Node *temporaryNode = NULL;
    if (index == 0) {
        return ll_pop(this);
    }
    for (i = 0; i < index - 1; i++) {
        if (currentNode->pNextNode == NULL) {
            printf("Index out of bound.\n");
            return (void *) -1;
        }
        currentNode = currentNode->pNextNode;
    }
    return currentNode->pNextNode->data;


}

int ll_indexOf(LinkedList *this, void *pElement) {
    int index;
    Node *currentNode = this->pFirstNode;
    for (index = 0; currentNode != NULL; ++index) {
        if (employee_equals(pElement, currentNode)) {
            return index;

        }
        currentNode = currentNode->pNextNode;

    }
    return -1;

}

int employee_equals(void *pElement, Node *currentNode) {
    return !strcmp(strupr(employee_getName(currentNode->data)), strupr(employee_getName(pElement)))
           && employee_getId(currentNode->data) == employee_getId(pElement)
           && employee_getManHours(currentNode->data) == employee_getManHours(pElement)
           && employee_getSalary(currentNode->data) == employee_getSalary(pElement);
}

void *ll_remove(LinkedList *this, int index) {
    void *returnData = NULL;
    int i = 0;
    Node *currentNode = this->pFirstNode;
    Node *temporaryNode = NULL;
    if (index == 0) {
        return ll_pop(this);
    }
    for (i = 0; i < index - 1; i++) {
        if (currentNode->pNextNode == NULL) {
            printf("Index out of bound.\n");
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

int ll_len(LinkedList *this) {
    if (this == NULL) {
        printf("Lista vacia");
        return -1;
    } else
        return this->size;
}

int ll_set(LinkedList *this, int index, void *pElement) {
    if (ll_isEmpty(this)) {
        return -1;
    }
    Node *currentNode = this->pFirstNode;
    int i;
    if (index == 0) {
        currentNode->data = pElement;
        return 0;

    }
    for (i = 0; i < index - 1; i++) {
        if (currentNode->pNextNode == NULL) {
            printf("Index out of bound.\n");
            return -1;
        }
        currentNode = currentNode->pNextNode;
    }
    if (currentNode->pNextNode != NULL) {
        currentNode->pNextNode->data = pElement;
    }
    return 0;

}

int ll_isEmpty(LinkedList *this) {
    if (this->pFirstNode == NULL) {
        printf("List is empty.");
        return 1;
    } else
        return 0;
}

int ll_deleteLinkedList(LinkedList *this) {
    Node *currentNode = this->pFirstNode;
    Node *temporaryNode;
    int i;
    if (ll_isEmpty(this->pFirstNode)) {
        return -1;
    }
    for (i = 0; currentNode != NULL; i++) {
        temporaryNode = currentNode;
        free(currentNode);
        currentNode = temporaryNode->pNextNode;

    }
    return 0;
}

int ll_contains(LinkedList* this, void* pElement){
    int index;
    Node *currentNode = this->pFirstNode;
    for (index = 0; currentNode != NULL; ++index) {
        if (employee_equals(pElement, currentNode)) {
            return 1;

        }
        currentNode = currentNode->pNextNode;

    }
    return 0;

}

Node *_ll_createNode(Node *next, void *pElement) {
    Node *newNode = malloc(sizeof(Node));
    if (newNode == NULL)
        printf("ERROR creating node. \n");
    newNode->data = pElement;
    newNode->pNextNode = next;
}

