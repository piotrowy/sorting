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
    BUBBLE,
    COMB,
    HEAP,
    INSERT,
    MERGE,
    QUICK,
    QUICK_ITERATIVE,
    SELECT,
    SHELL
};

#endif //PIOTROWY_SORTING_H
