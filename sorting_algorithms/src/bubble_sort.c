#include "../inc/bubble_sort.h"
#include "../inc/commons.h"

void bubbleSort(int *table, int size) {
    for (int i = 0; i < size; i++) {
        int wasChange = 1;
        for (int j = 0; j < size-1; j++) {
            if(table[j] > table[j+1]) {
                swap(&table[j], &table[j+1]);
                wasChange = 0;
            }
        }
        if (wasChange == 1) break;
    }
}