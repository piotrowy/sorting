#ifndef SORTING_H
#define SORTING_H

#include "commons.h"
#include "quick_sort.h"
#include "select_sort.h"
#include "comb_sort.h"
#include "bubble_sort.h"
#include "insert_sort.h"
#include "merge_sort.h"
#include "heap_sort.h"

enum SortingType {
    SELECT,
    INSERT,
    BUBBLE,
    COMB,
    QUICK,
    QUICK_ITERATIVE,
    MERGE,
    HEAP
};

#endif //SORTING_H
