#ifndef PIOTROWY_STATS_UTIL_H
#define PIOTROWY_STATS_UTIL_H

#include <stdlib.h>
#include <time.h>

typedef struct _SortingParams {
    int sortingType;
    int tableType;
    int size;
} SortingParams;

typedef void (*fptr_sorting)(int *table, int size);

enum TableType {
    DECREASING,
    INCREASING,
    RANDOM
};

const char* TABLE_TYPES[3];

void fillRandom(int *table, int size);

void fillIncreasing(int *table, int size);

void fillDecreasing(int *table, int size);

int check(int *table, int size);

int* getTableOfTypeAndSize(int type, int size);

double countTime(fptr_sorting func, int *table, int size);

#endif //PIOTROWY_STATS_UTIL_H
