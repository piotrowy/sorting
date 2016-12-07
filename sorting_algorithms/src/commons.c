#include "commons.h"

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

Stack* MyStack(int size) {
    Stack *stack = (Stack*) malloc(sizeof(Stack));
    stack->table = (int *) malloc(size * sizeof(int));
    stack->position = -1;
    stack->maxSize = size;
    stack->push = push;
    stack->pop = pop;
    stack->isEmpty = isEmpty;
    return stack;
}

Stack* MyDynamicStack(int size) {
    Stack *stack = (Stack*) malloc(sizeof(Stack));
    stack->table = (int *) malloc(size * sizeof(int));
    stack->position = -1;
    stack->maxSize = size;
    stack->push = forcePush;
    stack->pop = pop;
    stack->isEmpty = isEmpty;
    return stack;
}

void changeSize(Stack *stack, int newSize) {
    int *oldPointer = stack->table;
    stack->table = realloc(stack->table, newSize * sizeof(int));
    if (stack->table == NULL) {
        stack->table = oldPointer;
        printf("REALLOC FAILURE!");
    }
    free(oldPointer);
}

void push(Stack *stack, int elem) {
    if ((stack->position + 1) < stack->maxSize) {
        stack->position++;
        stack->table[stack->position] = elem;
    }
}

void forcePush(Stack *stack, int elem) {
    if ((stack->position + 1) > stack->maxSize) {
        changeSize(stack, stack->maxSize + 10);
    }
    stack->position++;
    stack->table[stack->position] = elem;
}

int pop(Stack *stack) {
    if (stack->position >= 0) {
        stack->position--;
        return stack->table[stack->position + 1];
    }
    return NULL;
}

int isEmpty(Stack *stack) {
    if (stack->position == -1) {
        return 1;
    }
    return 0;
}
