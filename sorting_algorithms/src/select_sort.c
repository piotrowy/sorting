#include "../inc/commons.h"

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