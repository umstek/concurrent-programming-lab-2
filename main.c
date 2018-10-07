#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

double time_serial(int mInserts, int mDeletes);

double time_mutex(int mInserts, int mDeletes, int thread_count);

int main() {
    srand((unsigned int) time(NULL));

    double serial_elapsed_1 = time_serial(50, 50);
    printf("%f\n", serial_elapsed_1);

    double serial_elapsed_2 = time_serial(500, 500);
    printf("%f\n", serial_elapsed_2);

    double serial_elapsed_3 = time_serial(2500, 2500);
    printf("%f\n", serial_elapsed_3);

    int thread_counts[] = {1, 2, 4, 8};
    for (int i = 0; i < 4; ++i) {
        double mutex_elapsed_1 = time_mutex(50, 50, thread_counts[i]);
        printf("%f:%d\n", mutex_elapsed_1, i);
    }
    return 0;
}
