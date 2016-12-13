#include <pthread.h>
#include <unistd.h>
#include "stats_util.h"
#include "sorting_algorithms/inc/sorting.h"
#define TIMEOUT 1
#define TABLE_SIZE 10000
#define NUMBER_OF_TABLE_TYPES 3

pthread_t THREADS[27];

double getSortingStats(int sortingType, int tableType, int size) {
    int *table = getTableOfTypeAndSize(tableType, size);
    double time = countTime(getSortingAlgorithm(sortingType), table, size);
    free(table);
    return time;
}

void* sortInThread(void* _params) {
    SortingParams* params = (SortingParams*) _params;
    printf("Sorting type: %s\nTable type: %s,\nTime: %f\n\n\n", SORTING_TYPES[params->sortingType],
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

void runWithTimeout(void* func, void* params, unsigned int time, int threadNumber) {
    if (pthread_create(&THREADS[threadNumber], NULL, func, params) == 1) {
        perror("pthread_create"); exit(EXIT_FAILURE);
    }
    sleep(time);

    pthread_cancel(THREADS[threadNumber]);
}

void every() {
    for(int i = BUBBLE_SORT; i <= SHELL_SORT; i++) {
        for(int j = DECREASING; j <= RANDOM; j++) {
            runWithTimeout(sortInThread, getSortingParamsStructure(i, j, TABLE_SIZE), TIMEOUT, i*NUMBER_OF_TABLE_TYPES + j);
        }
    }
}

int main(void) {
    every();
    return 0;
}
