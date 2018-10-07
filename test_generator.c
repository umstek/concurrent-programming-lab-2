#include <stdlib.h>
#include <memory.h>
#include <stdio.h>

#define M 10000

void random_fill(int *operations, const int mInserts, const int mDeletes) {
    for (int k = 0; k < mInserts; ++k) {
        int r = rand() % M;
        if (operations[r] == 0) operations[r] = 1; else k--;
    }

    for (int l = 0; l < mDeletes; ++l) {
        int s = rand() % M;
        if (operations[s] == 0) operations[s] = 2; else l--;
    }
}

void populate_values(int *values) {
    for (int i = 0; i < M; ++i) {
        values[i] = rand() % 65536;
    }
}

void populate_operations(int *operations, int mInserts, int mDeletes) {
    memset(operations, 0, M * sizeof(operations[0]));
    random_fill(operations, mInserts, mDeletes);
}
