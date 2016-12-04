#ifndef SORTING_COMMONS_H
#define SORTING_COMMONS_H

#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b);

typedef struct Stack{
    int *table;
    int position;
    int maxSize;
    void (*push)(struct Stack *self, int elem);
    int (*pop)(struct Stack *self);
    int (*isEmpty)(struct Stack *self);
    int (*changeSize)(struct Stack *self, int newSize);
} Stack;

Stack* MyStack(int size);

Stack* MyDynamicStack(int size);

void changeSize(Stack *stack, int newSize);

void push(Stack *stack, int elem);

void forcePush(Stack *stack, int elem);

int pop(Stack *stack);

int isEmpty(Stack *stack);

#endif //SORTING_COMMONS_H
