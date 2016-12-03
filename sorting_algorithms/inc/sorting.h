#ifndef SORTING_H
#define SORTING_H

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
    QUICK
};

#endif //SORTING_H
