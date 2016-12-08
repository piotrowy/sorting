#include <math.h>
#include "../inc/quick_sort.h"
#include "../inc/commons.h"

#define true 1

int getDividingPoint(int left, int right) {
    return (int) ceil(left + (right - left) / 2);
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

int Partition(int *table, int left, int right) {
    int x = table[right];
    int i = (left - 1);

    for (int j = left; j <= right - 1; ++j) {
        if (table[j] <= x) {
            ++i;
            swap(&table[i], &table[j]);
        }
    }

    swap(&table[i + 1], &table[right]);

    return (i + 1);
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
    Stack *stack = MyStack(10 * right);
    stack->push(stack, left);
    stack->push(stack, right);
    while (!stack->isEmpty(stack)) {
        int r = stack->pop(stack);
        int l = stack->pop(stack);
        int pivot = partition(table, l, r);
        if (r - l < 2) continue;
        stack->push(stack, l);
        stack->push(stack, pivot);
        stack->push(stack, pivot + 1);
        stack->push(stack, r);
    }
}

void quickSortIterativeParametrized(int *table, int size) {
    quickSortIterative(table, 0, size - 1);
}