#ifndef PIOTROWY_SORTING_H
#define PIOTROWY_SORTING_H

#include "bubble_sort.h"
#include "comb_sort.h"
#include "commons.h"
#include "heap_sort.h"
#include "insert_sort.h"
#include "merge_sort.h"
#include "quick_sort.h"
#include "select_sort.h"
#include "shell_sort.h"

enum SortingType {
    BUBBLE_SORT,
    COMB_SORT,
    HEAP_SORT,
    INSERT_SORT,
    MERGE_SORT,
    QUICK_SORT,
    QUICK_SORT_ITERATIVE,
    SELECT_SORT,
    SHELL_SORT
};

const char* SORTING_TYPES[] = {"BUBBLE_SORT",
                              "COMB_SORT",
                              "HEAP_SORT",
                              "INSERT_SORT",
                              "MERGE_SORT",
                              "QUICK_SORT",
                              "QUICK_SORT_ITERATIVE",
                              "SELECT_SORT",
                              "SHELL_SORT"};

typedef void (*fptr_sorting)(int *table, int size);

fptr_sorting getSortingAlgorithm(int type);

#endif //PIOTROWY_SORTING_H
