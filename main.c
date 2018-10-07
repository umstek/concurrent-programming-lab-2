#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

double time_serial(int mInserts, int mDeletes);

int main() {
    srand((unsigned int) time(NULL));

    double serial_elapsed_1 = time_serial(50, 50);
    printf("%f\n", serial_elapsed_1);

    double serial_elapsed_2 = time_serial(500, 500);
    printf("%f\n", serial_elapsed_2);

    double serial_elapsed_3 = time_serial(2500, 2500);
    printf("%f\n", serial_elapsed_3);

    return 0;
}
