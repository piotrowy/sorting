#include "../inc/insert_sort.h"

void insertSort(int *table, int size) {
    int temp, j, i;
    for(i = 1; i < size; i++ ) {
        temp = table[ i ];
        for(j = i - 1; j >= 0 && table[j] > temp; j--)
            table[j + 1] = table[ j ];
        table[j + 1] = temp;
    }
}