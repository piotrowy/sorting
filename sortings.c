#include "sortings.h"

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void combSort(int *table, int size)
{
    int gap = size, temp, guard;
    while (gap > 1 || guard) {
        gap = gap * 10 / 13;
        if(gap==0)
            gap=1;
        guard = 1;
        for ( int i = 0; i + gap < size; ++i ) {
            if ( table[i + gap] < table[i] ) {
                swap(&table[i], &table[i + gap]);
                guard = 0;
            }
        }
    }
}

void insertSort(int *table, int size) {
    int temp, j, i;
    for(i = 1; i < size; i++ ) {
        temp = table[ i ];
        for(j = i - 1; j >= 0 && table[j] > temp; j--)
            table[j + 1] = table[ j ];
        table[j + 1] = temp;
    }
}

void selectSort(int *table, int size) {
    int j, i, min;
    for (j = 0; j < size-1; j++){
        min=j;
        for ( i = j+1; i < size; i++) {
            if(table[i]<table[min]){
                min = i;
            }
        }
        if(min!=j){
            swap(&table[j], &table[min]);
        }
    }
}

void bubbleSort(int *table, int size) {
    int temp = 0;
    for (int i = 0; i < size; i++) {
        int guard = 1;
        for (int j = 0; j < size-1; j++) {
            if(table[j] > table[j+1]) {
                swap(&table[j], &table[j+1]);
                guard = 0;
            }
        }
        if (guard == 0) break;
    }
}

void quickSort(int p, int r, int *table) {

}

void quickSortParametrized(int *table, int size){
    quickSort(0, size-1, table);
}
