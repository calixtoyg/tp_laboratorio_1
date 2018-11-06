/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef __LINKEDLIST
#define __LINKEDLIST
struct Node {
    void *data;//data
    struct Node *pNextNode;
} typedef Node;

struct LinkedList {
    Node *pFirstNode;
    int size;
} typedef LinkedList;
#endif

//Publicas
/**
 * Returns pointer to new LinkedList.
 * If memory couldn't be allocated returns NULL else pointer to new LinkedList
 * @return linkedList pointer to new LinkedList
 */
LinkedList *ll_newLinkedList(void);

int ll_len(LinkedList *this);

/**
 * Gets Node from the specify index.
 * If LinkedList is empty or nextNode is Null(Index out of bound) returns -1 else 0 (success)
 * @param this LinkedList
 * @param index int
 * @return node pointer to Node
 */
Node *ll_getNode(LinkedList *this, int nodeIndex);

Node *test_getNode(LinkedList *this, int nodeIndex);

int test_addNode(LinkedList *this, int nodeIndex, void *pElement);

/**
 * Adds element to the specify index.
 * If LinkedList is empty or nextNode is Null(Index out of bound) returns -1 else 0 (success)
 * @param this LinkedList
 * @param index int
 * @param pElement pointer to any type of data
 * @return 0 or -1
 */
int ll_add(LinkedList *this, int index, void *pElement);

/**
 * Gets element from the specify index.
 * If LinkedList is empty or nextNode is Null(Index out of bound) returns -1 else 0 (success)
 * @param this LinkedList
 * @param index int
 * @return data pointer to any type of data
 */
void *ll_get(LinkedList *this, int index);

/**
 * Sets element to the specify index.
 * If LinkedList is empty or nextNode is Null(Index out of bound) returns -1 else 0 (success)
 * @param this LinkedList
 * @param index int
 * @param pElement pointer to any type of data
 * @return 0 or -1
 */
int ll_set(LinkedList *this, int index, void *pElement);

/**
 * Removes specific element from LinkedList with the provided index
 * If LinkedList is empty or nextNode is Null(Index out of bound) returns -1 else 0 (success)
 * @param this LinkedList
 * @param index int
 * @return 0 or -1
 */
void *ll_remove(LinkedList *this, int index);

int ll_clear(LinkedList *this);

int ll_deleteLinkedList(LinkedList *this);

/**
 * Returns index of element located in LinkedList.
 * If LinkedList is empty or node is Null(There is no element) returns -1 else 0 (success)
 * @param this
 * @param pElement
 * @return 0 or -1
 */
int ll_indexOf(LinkedList *this, void *pElement);

/**
 * Returns 1 if list is empty else 0
 * @param this LinedList
 * @return 0 or 1
 */
int ll_isEmpty(LinkedList *this);

/**
 * Adds in front of the LinkedList moves all nodes to the right.
 * if LinkedList is empty or node couldn't allocate memory it returns -1 else 0 (success)
 * @param this LinkedList
 * @return pElement pointer to any type of data
 */
int ll_push(LinkedList *this, void *pElement);

/**
 * Takes out the first element of the LinkedList and returns it's pointer
 * if LinkedList is empty it returns -1 else pointer to data
 * @param this
 * @return returnData pointer to any type of data
 */
void *ll_pop(LinkedList *this);

/**
 * Returns 1 if employee received as parameter is in the list else 0
 * @param this LinkedList
 * @param pElement pointer to employee(in this case it can't be any type of data)
 * @return 1 or 0
 */
int ll_contains(LinkedList *this, void *pElement);

int ll_containsAll(LinkedList *this, LinkedList *this2);

LinkedList *ll_subList(LinkedList *this, int from, int to);

LinkedList *ll_clone(LinkedList *this);

int ll_sort(LinkedList *this, int (*pFunc)(void *, void *), int order);

/**
 * Prints out LinkedList
 * if LinkedList is empty it returns -1 else 0 (success)
 * @param this LinkedList
 * @return number int
 */
int ll_print(LinkedList *list);

/**
 * Adds element to end of the LinkedList.
 * If LinkedList is empty returns -1 else 0 (success)
 * @param this LinkedList
 * @param pElement pointer to any type of data
 * @return -1 or 0
 */
int ll_append(LinkedList *list, void *pElement);
/**
 * Checks if the menu was valid
 * @param menu int menu number
 * @param min int minimum number included
 * @param max int maximum number included
 * @return int returns 1 if the menu is valid 0 otherwise
 */
int isValidMenu(int menu, int min, int max);
