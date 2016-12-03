#include "stats_util.h"

void fillTable(int *table, int size, int (*func)(int)) {
    table[0] = rand() % 100;
    for (int i = 1; i < size; i++) {
        table[i] = func(table[i-1]);
    }
}

int nextRandom(int arg) {
    return rand() % 10000 + 1;
}

int nextIncreased(int number) {
    return number + 1;
}

int nextDecreased(int number) {
    return number - 1;
}

void fillRandom(int *table, int size) {
    fillTable(table, size, nextRandom);
}

void fillIncreasing(int *table, int size) {
    fillTable(table, size, nextIncreased);
}

void fillDecreasing(int *table, int size) {
    fillTable(table, size, nextDecreased);
}

int check(int *table, int size) {
    for (int i = 1; i < size; i++) {
        if (table[i] < table[i - 1]) {
            return 0;
        }
    }
    return 1;
}

double countTime(fptr_sorting func, int *table, int size) {
    double time;
    clock_t clk = clock();
    func(table, size);
    time = (clock() - clk) * 1000 / (double) CLOCKS_PER_SEC;
    if (check(table, size)) {
        return time;
    }
    return -1.0;
}
