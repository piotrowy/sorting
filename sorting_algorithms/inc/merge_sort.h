#ifndef PIOTROWY_SORTING_MERGE_SORT_H
#define PIOTROWY_SORTING_MERGE_SORT_H

void merge(int *table, int left, int pivot, int right, int *helpTable);

void part(int *table, int left, int right, int *helpTable);

void mergeSort(int *table, int size);

#endif //PIOTROWY_SORTING_MERGE_SORT_H
