#include "../inc/quick_sort.h"
#include "../inc/commons.h"

int getDividingPoint(int left, int right) {
    return left + (right - left)/2;
}

int partition(int *table, int left, int right) {
    int dividingPoint = getDividingPoint(left, right);
    int dividingValue = table[dividingPoint];

    swap(&table[dividingPoint], &table[right]);
    int positionIndex = left;
    for (int i = left; i < right - 1; i ++) {
        if (table[i] < dividingValue) {
            swap(&table[i], &table[positionIndex]);
            positionIndex = positionIndex + 1;
        }
    }
    swap(&table[positionIndex], &table[right]);

    return positionIndex;
}

void quickSort(int *table, int left, int right) {
    if (left < right) {
        int newIndex = partition(table, left, right);
        partition(table, left, newIndex);
        partition(table, newIndex + 1, right);
    }
}

void quickSortParametrized(int *table, int size) {
    quickSort(table, 0, size - 1);
}

void quickSortIterative(int *table, int left, int right) {
    Stack *stack = MyStack(right + 1);
    stack->push(stack, left);
    stack->push(stack, right);
    while(!stack->isEmpty(stack)) {
        int r = stack->pop(stack);
        int l = stack->pop(stack);
        if ((r - l) < 2) continue;
        int part = partition(table, l, r);

        stack->push(stack, part + 1);
        stack->push(stack, r);

        stack->push(stack, l);
        stack->push(stack, part);
    }
}

void quickSortIterativeParametrized(int *table, int size) {
    quickSortIterative(table, 0, size - 1);
}