#include "stats_util.h"
#include "sorting_algorithms/inc/sorting.h"

#define START 10
#define STOP 10000000

fptr_sorting getSortingAlgorithm(int type) {
    switch (type) {
        case SELECT_SORT:
            return selectSort;
        case INSERT_SORT:
            return insertSort;
        case COMB_SORT:
            return combSort;
        case BUBBLE_SORT:
            return bubbleSort;
        case QUICK_SORT:
            return quickSortParametrized;
        case QUICK_ITERATIVE_SORT:
            return quickSortIterativeParametrized;
        case HEAP_SORT:
            return heapSort;
        case MERGE_SORT:
            return mergeSort;
        case SHELL_SORT:
            return shellSort;
        default:
            return quickSortParametrized;

    }
}

int* getTableOfTypeAndSize(int type, int size) {
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

double getSortingStats(int sortingType, int tableType, int size) {
    int *table = getTableOfTypeAndSize(tableType, size);
    double time = countTime(getSortingAlgorithm(sortingType), table, size);
    free(table);
    return time;
}

void runWithTimeout() {

}

int main(void) {
    printf("%f\n", getSortingStats(SHELL_SORT, INCREASING, 100000));
    return 0;
}
