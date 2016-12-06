#include <pthread.h>
#include <unistd.h>
#include "stats_util.h"
#include "sorting_algorithms/inc/sorting.h"
#define TIMEOUT 15
#define TABLE_SIZE 1000000

double getSortingStats(int sortingType, int tableType, int size) {
    int *table = getTableOfTypeAndSize(tableType, size);
    double time = countTime(getSortingAlgorithm(sortingType), table, size);
    free(table);
    return time;
}

void* sortInThread(void* _params) {
    SortingParams* params = (SortingParams*) _params;
    printf("Table type: %s,\nSorting type: %s\nTime: %f\n", SORTING_TYPES[params->sortingType],
           TABLE_TYPES[params->tableType], getSortingStats(params->sortingType, params->tableType, params->size));
    return NULL;
}

SortingParams* getSortingParamsStructure(int sortingType, int tableType, int size) {
    SortingParams* params = (SortingParams*) malloc(sizeof(SortingParams));
    params->sortingType = sortingType;
    params->tableType = tableType;
    params->size = size;
    return params;
}

void runWithTimeout(void* func, void* params, unsigned int time) {
    pthread_t id;

    if (pthread_create(&id, NULL, func, params) == 1) {
        perror("pthread_create"); exit(EXIT_FAILURE);
    }
    sleep(time);

    pthread_exit(id);
}

int main(void) {
    runWithTimeout(sortInThread, getSortingParamsStructure(QUICK_SORT, INCREASING, TABLE_SIZE), TIMEOUT);
    return 0;
}
