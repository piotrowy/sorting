#ifndef SORTING_COMMONS_H
#define SORTING_COMMONS_H

#include <stdlib.h>

enum SortingType {
    SELECT,
    INSERT,
    BUBBLE,
    COMB,
    QUICK
};

enum TableType {
    DECREASING,
    INCREASING,
    RANDOM
};

void fillRandom(int *table, int size);

void fillIncreasing(int *table, int size);

void fillDecreasing(int *table, int size);

int check(int *table, int size);

#endif /* SORTING_COMMONS_H */
