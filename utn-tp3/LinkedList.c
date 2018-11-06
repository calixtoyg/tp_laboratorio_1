//
// Created by yasir on 31-Oct-18.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "LinkedList.h"
#include "Employee.h"


static Node *_ll_createNode(Node *next, void *pElement);

int isValidMenu(int menu, int min, int max) {
    if (menu >= min && menu <= max) {
        return 1;
    } else
        return 0;
}

int ll_print(LinkedList *list) {
    if (ll_isEmpty(list)) {
        return -1;
    }
    Node *temporary = list->pFirstNode;
    while (temporary != NULL) {
        employee_print(temporary->data);
        temporary = temporary->pNextNode;
    }
    return 0;

}

int ll_push(LinkedList *this, void *pElement) {
    if (ll_isEmpty(this)) {
        return -1;
    }
    Node *newNode;
    newNode = malloc(sizeof(Node));
    if (newNode == NULL) {
        return -1;
    }
    newNode->data = pElement;
    newNode->pNextNode = this->pFirstNode;
    this->pFirstNode = newNode;
    this->size += 1;
    return 0;

}

void *ll_pop(LinkedList *this) {
    if (ll_isEmpty(this)) {
        return (void *) -1;
    }
    void *returnData = NULL;
    Node *nextNode = NULL;
    nextNode = this->pFirstNode->pNextNode;
    returnData = this->pFirstNode->pNextNode->data;
    free(this->pFirstNode);
    this->pFirstNode = nextNode;
    this->size -= 1;
    return returnData;
}

int ll_add(LinkedList *this, int index, void *pElement) {
    if (ll_isEmpty(this)) {
        return -1;
    }
    Node *currentNode = this->pFirstNode;
    int i = 0;
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
        return NULL;
    }
    linkedList->pFirstNode = NULL;
    linkedList->size = 0;
    return linkedList;
}

void *ll_get(LinkedList *this, int index) {
    if (ll_isEmpty(this)) {
        return (void *) -1;
    }
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

Node *ll_getNode(LinkedList *this, int nodeIndex) {
    if (ll_isEmpty(this)) {
        return (Node *) -1;
    }
    void *returnData = NULL;
    int i = 0;
    Node *currentNode = this->pFirstNode;
    Node *temporaryNode = NULL;
    if (nodeIndex == 0) {
        return ll_pop(this);
    }
    for (i = 0; i < nodeIndex - 1; i++) {
        if (currentNode->pNextNode == NULL) {
            printf("Index out of bound.\n");
            return (void *) -1;
        }
        currentNode = currentNode->pNextNode;
    }
    return currentNode->pNextNode;

}

int ll_indexOf(LinkedList *this, void *pElement) {
    if (ll_isEmpty(this)) {
        return -1;
    }
    Node *currentNode = this->pFirstNode;
    int index;
    for (index = 0; currentNode != NULL; ++index) {
        if (employee_equals(pElement, currentNode)) {
            return index;

        }
        currentNode = currentNode->pNextNode;

    }
    printf("There is no element.\n");
    return -1;

}

void *ll_remove(LinkedList *this, int index) {
    if (ll_isEmpty(this)) {
        return (void *) -1;
    }
    Node *currentNode = this->pFirstNode;
    void *returnData = NULL;
    int i = 0;
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
/**
 * Returns length of the LinkedList
 * If LinkedList is empty returns -1 else length(size) of list
 * @param this LinkedList
 * @return size size of LinkedList
 */
int ll_len(LinkedList *this) {
    if (ll_isEmpty(this)) {
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
    if (this == NULL) {
        printf("List is empty.");
        return 1;
    } else
        return 0;
}

//TODO
/**
 *
 * @param this
 * @return
 */
int ll_deleteLinkedList(LinkedList *this) {
    if (ll_isEmpty(this)) {
        return -1;
    }
    Node *currentNode = this->pFirstNode;

    Node *temporaryNode;
    int i;
    if (ll_isEmpty(this)) {
        return -1;
    }
    for (i = 0; currentNode != NULL; i++) {
        temporaryNode = currentNode;
        free(currentNode);
        currentNode = temporaryNode->pNextNode;

    }
    return 0;
}

int ll_contains(LinkedList *this, void *pElement) {
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

int ll_append(LinkedList *list, void *pElement) {
    if (ll_isEmpty(list)) {
        return -1;
    }
    int i = 0;
    Node *currentNode = list->pFirstNode;
    Node *temporaryNode = malloc(sizeof(Node));
    for (i = 0; currentNode->pNextNode != NULL; i++) {
        currentNode = currentNode->pNextNode;
    }
    currentNode->pNextNode = temporaryNode;
    temporaryNode->data = pElement;
    temporaryNode->pNextNode = NULL;
    list->size++;
}

static Node *_ll_createNode(Node *next, void *pElement) {
    Node *newNode = malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("ERROR creating node. \n");
        return (Node *) -1;
    }
    newNode->data = pElement;
    newNode->pNextNode = next;
}

