#include "sorting.h"

void merge(int *table, int left, int pivot, int right, int *helpTable) {
    int l1, l2, i;

    for (l1 = left, l2 = pivot + 1, i = left; l1 <= pivot && l2 <= right; i++) {
        if (table[l1] <= table[l2])
            helpTable[i] = table[l1++];
        else
            helpTable[i] = table[l2++];
    }

    while (l1 <= pivot)
        helpTable[i++] = table[l1++];

    while (l2 <= right)
        helpTable[i++] = table[l2++];

    for (i = left; i <= right; i++)
        table[i] = helpTable[i];
}

void part(int *table, int left, int right, int *helpTable) {
    if (left < right) {
        int pivot = left + (right - left) / 2;
        part(table, left, pivot, helpTable);
        part(table, pivot + 1, right, helpTable);
        merge(table, left, pivot, right, helpTable);
    }
}

void mergeSort(int *table, int size) {
    int *helpTable = (int *) malloc(size * sizeof(int));
    part(table, 0, size - 1, helpTable);
    free(helpTable);
}