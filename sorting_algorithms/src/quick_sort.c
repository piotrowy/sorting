#include <math.h>
#include "../inc/quick_sort.h"
#include "../inc/commons.h"

#define true 1

int getDividingPoint(int left, int right) {
    return (int) floor(left + (right - left) / 2);
}

int partition(int *table, int left, int right) {
    int dividingValue = table[getDividingPoint(left, right)];
    while (true) {
        while (table[right] > dividingValue)
            right--;
        while (table[left] < dividingValue)
            left++;
        if (left < right) {
            swap(&table[left], &table[right]);
            left++;
            right--;
        } else {
            return right;
        }
    }
}

void quickSort(int *table, int left, int right) {
    if (left < right) {
        int newIndex = partition(table, left, right);
        quickSort(table, left, newIndex);
        quickSort(table, newIndex + 1, right);
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