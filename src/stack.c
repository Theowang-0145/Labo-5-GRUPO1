#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
//funcion de creacion de stack
Stack *createStack() {

    Stack *stack = (Stack *)malloc(sizeof(Stack));

    if (stack == NULL) {
        return NULL;
    }

    stack->top = NULL;

    return stack;
}

//Funcion de nodo para coneccion entre datos 
static StackNode *createNode(int data) {

    StackNode *newNode =
        (StackNode *)malloc(sizeof(StackNode));

    if (newNode == NULL) {
        return NULL;
    }

    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

//Funcion parala asignacion del stack al nodo
//EsTA FUNCION DEBE TOMAR EL STACK EXISTENTE Y CAMBIARLO PARA QUE SEA EL NUEVO NODO
void push(Stack *stack, int data) {

    StackNode *newNode = createNode(data);

    if (newNode == NULL) {
        return;
    }

    newNode->next = stack->top;

    stack->top = newNode;
}
//En caso de estar vaco el stack, se asigna aca un valor Null para evitar fallos
int isEmpty(Stack *stack) {

    return (stack->top == NULL);
}
//Esto permite devolver en caso de error un mensaje de que el stack esta vacio y si no lo esta, le otorga una posicion en la data
int peek(Stack *stack) {

    if (isEmpty(stack)) {
        printf("Error: Stack vacio\n");
        return -1;
    }

    return stack->top->data;
}
//el pop es para trabajar el stack que este en temporal como datos modificables con valor, pero tambien se libera el espacio enel temporal para evitar mal uso de memoria 
int pop(Stack *stack) {

    if (isEmpty(stack)) {
        printf("Error: Stack vacio\n");
        return -1;
    }

    StackNode *temp = stack->top;

    int value = temp->data;

    stack->top = temp->next;

    free(temp);

    return value;
}

//ESTO SIMPLEMENTE ES PARA MOSTRAR EL STACK EN FUNCION 
void printStack(Stack *stack) {

    StackNode *current = stack->top;

    printf("TOP -> ");

    while (current != NULL) {

        printf("%d", current->data);

        if (current->next != NULL) {
            printf(" -> ");
        }

        current = current->next;
    }

    printf("\n");
}
//FUNCION para liberar el espacio de memoria utilizado por la funcion en general 
void freeStack(Stack *stack) {

    while (!isEmpty(stack)) {
        pop(stack);
    }

    free(stack);
}
