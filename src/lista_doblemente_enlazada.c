#include <stdio.h>
#include <stdlib.h>
#include "lista_doblemente_enlazada.h"

//funcion para crear una lista
DoublyLinkedList *createList() {
    DoublyLinkedList *list =
        (DoublyLinkedList *)malloc(sizeof(DoublyLinkedList));

    if (list == NULL) {
        return NULL;
    }

    list->head = NULL;
    list->tail = NULL;

    return list;
}

//Funcion de creacion de nodo, para rediraccion entre listas
static Node *createNode(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));

    if (newNode == NULL) {
        return NULL;
    }

    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    return newNode;
}

//Funcion para toplocar al principio
void insertAtBeginning(DoublyLinkedList *list, int data) {
    Node *newNode = createNode(data);

    if (newNode == NULL) {
        return;
    }

    if (list->head == NULL) {
        list->head = newNode;
        list->tail = newNode;
        return;
    }

    newNode->next = list->head;
    list->head->prev = newNode;

    list->head = newNode;
}

//Funcion para colocar en segundo plano
void insertAtEnd(DoublyLinkedList *list, int data) {
    Node *newNode = createNode(data);

    if (newNode == NULL) {
        return;
    }

    if (list->tail == NULL) {
        list->head = newNode;
        list->tail = newNode;
        return;
    }

    newNode->prev = list->tail;
    list->tail->next = newNode;

    list->tail = newNode;
}

//Funcion para definir en que lugar debe estar la lista
void insertAtPosition(DoublyLinkedList *list, int data, int position) {

    if (position <= 0 || list->head == NULL) {
        insertAtBeginning(list, data);
        return;
    }

    Node *current = list->head;
    int index = 0;

    while (current != NULL && index < position - 1) {
        current = current->next;
        index++;
    }

    if (current == NULL || current->next == NULL) {
        insertAtEnd(list, data);
        return;
    }

    Node *newNode = createNode(data);

    if (newNode == NULL) {
        return;
    }

    newNode->next = current->next;
    newNode->prev = current;

    current->next->prev = newNode;
    current->next = newNode;
}

//Funcion para eliminar un elemento y prevenir mal uso de memoria 
void deleteElement(DoublyLinkedList *list, int data) {

    Node *current = list->head;

    while (current != NULL) {

        if (current->data == data) {

            if (current->prev != NULL) {
                current->prev->next = current->next;
            } else {
                list->head = current->next;
            }

            if (current->next != NULL) {
                current->next->prev = current->prev;
            } else {
                list->tail = current->prev;
            }

            free(current);
            return;
        }

        current = current->next;
    }
}

//FUNCION para que el nodo encuentre una lista en los datos 
Node *searchElement(DoublyLinkedList *list, int data) {

    Node *current = list->head;

    while (current != NULL) {

        if (current->data == data) {
            return current;
        }

        current = current->next;
    }

    return NULL;
}
//FUNCION para ver que esta por delante 
void printForward(DoublyLinkedList *list) {

    Node *current = list->head;

    printf("NULL <- ");

    while (current != NULL) {
        printf("%d", current->data);

        if (current->next != NULL) {
            printf(" <-> ");
        }

        current = current->next;
    }

    printf(" -> NULL\n");
}
//Funcion para ver que esta por detras 
void printBackward(DoublyLinkedList *list) {

    Node *current = list->tail;

    printf("NULL <- ");

    while (current != NULL) {

        printf("%d", current->data);

        if (current->prev != NULL) {
            printf(" <-> ");
        }

        current = current->prev;
    }

    printf(" -> NULL\n");
}
//Funcion para liberar el espacio creado en memoria para las listas dobles
void freeList(DoublyLinkedList *list) {

    Node *current = list->head;

    while (current != NULL) {

        Node *temp = current;

        current = current->next;

        free(temp);
    }

    free(list);
}
