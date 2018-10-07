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

pthread_mutex_t mutex;

int init_mutex() {
    if (pthread_mutex_init(&mutex, NULL) != 0) return 1;
    return 0;
}

void member_mutex(int value, struct Node *head_p) {
    pthread_mutex_lock(&mutex);
    member(value, head_p);
    pthread_mutex_unlock(&mutex);
}

void insert_mutex(int value, struct Node **head_pp) {
    pthread_mutex_lock(&mutex);
    insert(value, head_pp);
    pthread_mutex_unlock(&mutex);
}

void delete_mutex(int value, struct Node **head_pp) {
    pthread_mutex_lock(&mutex);
    delete(value, head_pp);
    pthread_mutex_unlock(&mutex);
}

int destroy_mutex() {
    pthread_mutex_destroy(&mutex);
    return 0;
}

double time_mutex(int mInserts, int mDeletes, int threads) {
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