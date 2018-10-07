#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int init_mutex();

int destroy_mutex();

int init_rwlock();

int destroy_rwlock();

int main() {
    init_rwlock();
    printf("%d", RAND_MAX);
    destroy_rwlock();
    return 0;
}
