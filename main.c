#include<stdio.h>
#include<time.h>

#include "sorting_commons.h"
#include "sortings.h"

#define START 10
#define STOP 10000000

void* getAlgorithm(int type) {
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
            quickSortParametrized;
        default:
            return quickSortParametrized;
    }
}

int *getTableOfTypeAndSize(int type, int size) {
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
    int size = 100000, *table = getTableOfTypeAndSize(DECREASING, size);
    printf("%f", countTime(getAlgorithm(BUBBLE), table, size));
    free(table);
    return 0;
}
