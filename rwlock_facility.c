#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "timer.h"

#define M 10000

struct Node;

int member(int value, struct Node *head_p);

int insert(int value, struct Node **head_pp);

int delete(int value, struct Node **head_pp);

void populate_initial(struct Node *head_pp);

void populate_values(int *values);

void populate_operations(int *operations, int mInserts, int mDeletes);

pthread_rwlock_t rwlock;

int init_rwlock() {
    if (pthread_rwlock_init(&rwlock, NULL) != 0) return 1;
    return 0;
}

void member_rwlock(int value, struct Node *head_p) {
    pthread_rwlock_rdlock(&rwlock);
    member(value, head_p);
    pthread_rwlock_unlock(&rwlock);
}

void insert_rwlock(int value, struct Node **head_pp) {
    pthread_rwlock_wrlock(&rwlock);
    insert(value, head_pp);
    pthread_rwlock_unlock(&rwlock);
}

void delete_rwlock(int value, struct Node **head_pp) {
    pthread_rwlock_wrlock(&rwlock);
    delete(value, head_pp);
    pthread_rwlock_unlock(&rwlock);
}

int destroy_rwlock() {
    pthread_rwlock_destroy(&rwlock);
    return 0;
}

int operations_rwlock[M];
int values_rwlock[M];
int n_threads_rwlock;
struct Node *head_rwlock = NULL;

void *single_rwlock(void *rank) {
    int share = M / n_threads_rwlock;
    int id = (int) rank;
    int bi = share * id;
    int ei = share * (id + 1);

    for (int i = bi; i < ei; ++i) {
        switch (operations_rwlock[i]) {
            case 1:
                insert_rwlock(values_rwlock[i], &head_rwlock);
                break;
            case 2:
                delete_rwlock(values_rwlock[i], &head_rwlock);
                break;
            default:
                member_rwlock(values_rwlock[i], head_rwlock);
                break;
        }
    }

    return NULL;
}

double time_rwlock(int mInserts, int mDeletes, int thread_count) {
    n_threads_rwlock = thread_count;
    pthread_t *thread_handles;
    thread_handles = (pthread_t *) malloc(thread_count * sizeof(pthread_t));

    double start, finish, elapsed;

    head_rwlock = NULL;
    populate_initial(head_rwlock);

    populate_values(values_rwlock);
    populate_operations(operations_rwlock, mInserts, mDeletes);

    GET_TIME(start);

    init_rwlock();

    for (long thread = 0; thread < thread_count; thread++) {
        pthread_create(&thread_handles[thread], NULL, single_rwlock, (void *) thread);
    }

    for (int thread = 0; thread < thread_count; thread++) {
        pthread_join(thread_handles[thread], NULL);
    }

    destroy_rwlock();

    GET_TIME(finish);
    elapsed = finish - start;

    return elapsed;
}
