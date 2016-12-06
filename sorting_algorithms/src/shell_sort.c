#include "../inc/shell_sort.h"

void shellSortPhase(int *table, int size, int gap) {
    for(int i = gap - 1; i >= 0; --i) {
        int value = table[i], j;
        for(j = i - gap; j >= 0 && table[j] > value; j -= gap) {
            table[j + gap] = table[j];
        }
        table[j + gap] = value;
    }
}

void shellSort(int *table, int size) {
    static const int gaps[ ] = { 1, 4, 10, 23, 57, 132, 301, 701 };

    for (int gap = (int) sizeof(gaps)/sizeof(int) - 1; gap >= 0; --gap) {
        shellSortPhase(table , size, gaps[gap]);
    }
}