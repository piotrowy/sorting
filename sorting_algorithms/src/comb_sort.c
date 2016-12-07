#include "../inc/comb_sort.h"
#include "../inc/commons.h"

void combSort(int *table, int size)
{
    int gap = size, guard = 1;
    while (gap > 1 || guard) {
        gap = gap * 10 / 13;
        if(gap==0)
            gap=1;
        guard = 0;
        for ( int i = 0; i + gap < size; ++i ) {
            if ( table[i + gap] < table[i] ) {
                swap(&table[i], &table[i + gap]);
                guard = 1;
            }
        }
    }
}
