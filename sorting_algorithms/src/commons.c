#include "commons.h"

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

Stack *MyStack(int size) {
    Stack *stack = (Stack *) malloc(sizeof(Stack));
    stack->table = (int *) malloc(size * sizeof(int));
    stack->position = -1;
    stack->maxSize = size;
    stack->push = push;
    stack->pop = pop;
    stack->isEmpty = isEmpty;
    stack->isFull = isFull;
    return stack;
}

Stack *MyDynamicStack(int size) {
    Stack *stack = (Stack *) malloc(sizeof(Stack));
    stack->table = (int *) malloc(size * sizeof(int));
    stack->position = -1;
    stack->maxSize = size;
    stack->push = forcePush;
    stack->pop = pop;
    stack->isEmpty = isEmpty;
    stack->isFull = isFull;
    return stack;
}

void changeSize(Stack *stack, int newSize) {
    int *oldPointer = stack->table;
    stack->maxSize = newSize * sizeof(int);
    stack->table = realloc(stack->table, stack->maxSize * sizeof(int));
    if (stack->table == NULL) {
        stack->table = oldPointer;
        printf("REALLOC FAILURE!");
    }
    free(oldPointer);
}

void push(Stack *stack, int elem) {
    if (!stack->isFull(stack)) {
        stack->position++;
        stack->table[stack->position] = elem;
    }
}

void forcePush(Stack *stack, int elem) {
    if (!stack->isFull(stack)) {
        changeSize(stack, stack->maxSize + 10);
    }
    stack->position++;
    stack->table[stack->position] = elem;
}

int pop(Stack *stack) {
    if (!stack->isEmpty(stack)) {
        stack->position--;
        return stack->table[stack->position + 1];
    }
    exit(139);
}

int isEmpty(Stack *stack) {
    return stack->position < 0;
}

int isFull(Stack *stack) {
    return stack->position == stack->maxSize - 1;
}