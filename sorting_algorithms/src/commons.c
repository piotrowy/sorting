#include "commons.h"

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

Stack* MyStack(int maxSize) {
    Stack *stack = (Stack*) malloc(sizeof(Stack));
    stack->table = (int *) malloc(maxSize * sizeof(int));
    stack->position = -1;
    stack->maxSize = maxSize;
    stack->push = push;
    stack->pop = pop;
    stack->isEmpty = isEmpty;
    return stack;
}

void push(Stack *stack, int elem) {
    if ((stack->position + 1) < stack->maxSize) {
        stack->position = stack->position + 1;
        stack->table[stack->position] = elem;
    }
}

int pop(Stack *stack) {
    if (stack->position >= 0) {
        stack->position = stack->position - 1;
        return stack->table[stack->position + 1];
    }
}

int isEmpty(Stack *stack) {
    if (stack->position == -1) {
        return 1;
    }
    return 0;
}