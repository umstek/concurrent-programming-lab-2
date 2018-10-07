#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

double time_serial(int mInserts, int mDeletes);

double time_mutex(int mInserts, int mDeletes, int thread_count);

double time_rwlock(int mInserts, int mDeletes, int thread_count);

int main() {
    int thread_counts[] = {1, 2, 4, 8};

    printf("Impl,case,threads,time\n");

    srand((unsigned int) time(NULL));

    double serial_elapsed_1 = time_serial(50, 50);
    printf("serial,1,1,%f\n", serial_elapsed_1);

    for (int i = 0; i < 4; ++i) {
        double elapsed = time_mutex(50, 50, thread_counts[i]);
        printf("mutex,1,%d,%f\n", thread_counts[i], elapsed);
    }

    for (int i = 0; i < 4; ++i) {
        double elapsed = time_rwlock(50, 50, thread_counts[i]);
        printf("rwlock,1,%d,%f\n", thread_counts[i], elapsed);
    }

    double serial_elapsed_2 = time_serial(500, 500);
    printf("serial,2,1,%f\n", serial_elapsed_2);

    for (int i = 0; i < 4; ++i) {
        double elapsed = time_mutex(500, 500, thread_counts[i]);
        printf("mutex,2,%d,%f\n", thread_counts[i], elapsed);
    }

    for (int i = 0; i < 4; ++i) {
        double elapsed = time_rwlock(500, 500, thread_counts[i]);
        printf("rwlock,2,%d,%f\n", thread_counts[i], elapsed);
    }

    double serial_elapsed_3 = time_serial(2500, 2500);
    printf("serial,3,1,%f\n", serial_elapsed_3);

    for (int i = 0; i < 4; ++i) {
        double elapsed = time_mutex(2500, 2500, thread_counts[i]);
        printf("mutex,3,%d,%f\n", thread_counts[i], elapsed);
    }

    for (int i = 0; i < 4; ++i) {
        double elapsed = time_rwlock(2500, 2500, thread_counts[i]);
        printf("rwlock,3,%d,%f\n", thread_counts[i], elapsed);
    }

    return 0;
}
