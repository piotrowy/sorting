#ifndef SORTING_COMMONS_H
#define SORTING_COMMONS_H

#include <stdlib.h>

typedef struct Stack{
    int *table;
    int position;
    int maxSize;
    void (*push)(struct Stack *self, int elem);
    int (*pop)(struct Stack *self);
    int (*isEmpty)(struct Stack *self);
} Stack;

Stack* MyStack(int maxSize);

void swap(int *a, int *b);

void push(Stack *stack, int elem);

int pop(Stack *stack);

int isEmpty(Stack *stack);

#endif //SORTING_COMMONS_H
