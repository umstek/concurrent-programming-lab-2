#include <stdlib.h>
#include <memory.h>

#define N 1000
#define M 10000

enum OperationType {
    MEMBER = 0, INSERT, DELETE
};

int initial[N];
int operations[M];
int values[M];

void affine_pseudo_random_fill(const int mInserts, const int mDeletes) {
    int a;
    do a = rand() % M; while (M / a == 0);
    int b = rand() % M;

    for (int i = 0; i < mInserts; ++i) operations[(a * i + b) % M] = INSERT;
    for (int j = mInserts; j < mInserts + mDeletes; ++j) operations[(a * j + b) % M] = DELETE;
}

void populate_initial() {
    for (int i = 0; i < N; ++i) {
        initial[i] = rand() % 65536;
    }
}

void populate_values() {
    for (int i = 0; i < M; ++i) {
        values[i] = rand() % 65536;
    }
}

void populate_operations(int mInserts, int mDeletes) {
    memset(operations, 0, sizeof(values));
    affine_pseudo_random_fill(mInserts, mDeletes);
}
