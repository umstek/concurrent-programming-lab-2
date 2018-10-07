#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

double time_serial(int mInserts, int mDeletes);

int main() {
    double serial_elapsed = time_serial(500, 500);
    printf("%f", serial_elapsed);
    return 0;
}
