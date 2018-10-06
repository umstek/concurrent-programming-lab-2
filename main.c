#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int init_mutex();

int destroy_mutex();

int main() {
    init_mutex();
    printf("%d", RAND_MAX);
    destroy_mutex();
    return 0;
}
