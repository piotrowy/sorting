#include "../inc/sorting.h"

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
        case QUICK_SORT_ITERATIVE:
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