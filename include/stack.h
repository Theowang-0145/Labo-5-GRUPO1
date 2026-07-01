#ifndef stack_h
#define stack_h

typedef struct StackNode {
    int data;
    struct StackNode *next;
} StackNode;

typedef struct {
    StackNode *top;
} Stack;

Stack *createStack();

void push(Stack *stack, int data);

int pop(Stack *stack);

int peek(Stack *stack);

int isEmpty(Stack *stack);

void printStack(Stack *stack);

void freeStack(Stack *stack);

#endif
