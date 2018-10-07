#include <stdlib.h>
#include <memory.h>

#define M 10000

void affine_pseudo_random_fill(int *operations, const int mInserts, const int mDeletes) {
    int a;
    do a = rand() % M; while (M / a == 0);
    int b = rand() % M;

    for (int i = 0; i < mInserts; ++i) operations[(a * i + b) % M] = 1;
    for (int j = mInserts; j < mInserts + mDeletes; ++j) operations[(a * j + b) % M] = 2;
}

void populate_values(int *values) {
    for (int i = 0; i < M; ++i) {
        values[i] = rand() % 65536;
    }
}

void populate_operations(int *operations, int mInserts, int mDeletes) {
    memset(operations, 0, sizeof(*operations));
    affine_pseudo_random_fill(operations, mInserts, mDeletes);
}
