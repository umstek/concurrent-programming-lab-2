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

double time_rwlock(int mInserts, int mDeletes, int threads) {
    int operations[M];
    int values[M];

    double start, finish, elapsed;

    struct Node *head = NULL;
    populate_initial(head);

    populate_values(values);
    populate_operations(operations, mInserts, mDeletes);

    GET_TIME(start);

    GET_TIME(finish);
    elapsed = finish - start;

    return elapsed;
}
