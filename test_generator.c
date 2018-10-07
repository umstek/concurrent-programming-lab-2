#include <stdlib.h>
#include <memory.h>
#include <stdio.h>

#define M 10000

void random_fill(int *operations, const int mInserts, const int mDeletes) {
    int a;
    do a = rand() % M; while (M / a == 0);
    int b = rand() % M;

    for (int i = 0; i < mInserts; ++i) {
        int ix = (a * i + b) % M;
        operations[ix] = 1;
    };
    for (int j = mInserts; j < mInserts + mDeletes; ++j) {
        int jx = (a * j + b) % M;
        operations[jx] = 2;
    };
}

void populate_values(int *values) {
    for (int i = 0; i < M; ++i) {
        values[i] = rand() % 65536;
    }
}

void populate_operations(int *operations, int mInserts, int mDeletes) {
    memset(operations, 0, sizeof(*operations));
    random_fill(operations, mInserts, mDeletes);
}
