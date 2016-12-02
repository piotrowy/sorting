#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#include "sorting_commons.h"
#include "sortings.h"

#define START 10
#define STOP 10000000

void* sortTable(int type) {
    switch (type) {
        case SELECT:
            return selectSort;
        case INSERT:
            return insertSort;
        case COMB:
            return combSort;
        case BUBBLE:
            return bubbleSort;
        case QUICK:
            //quickSort(table, size);
        default:
            return quickSortParametrized;
    }
}

int *getTable(int type, int size) {
    int *table = (int *) malloc(size * sizeof(int));
    switch (type) {
        case DECREASING:
            fillDecreasing(table, size);
            break;
        case INCREASING:
            fillIncreasing(table, size);
            break;
        case RANDOM:
            fillRandom(table, size);
            break;
        default:
            fillRandom(table, size);
    }
    return table;
}

double countTime(void (*func)(int*, int), int *table, int size) {
    double time;
    clock_t clk = clock();
    func(table, size);
    time = (clock() - clk) * 1000 / (double) CLOCKS_PER_SEC;
    if (check(table, size)) {
        return time;
    }
    return -1.0;
}

int main(void) {
    printf("%f", countTime(sortTable(BUBBLE), getTable(DECREASING, 10000), 10000));
    return 0;
}
