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

int operations[M];
int values[M];
int n_threads_mutex;
struct Node *head = NULL;

void *single_mutex(void *rank) {
    int share = M / n_threads_mutex;
    int id = (int) rank;
    int bi = share * id;
    int ei = share * (id + 1);

    for (int i = bi; i < ei; ++i) {
        switch (operations[i]) {
            case 1:
                insert_mutex(values[i], &head);
                break;
            case 2:
                delete_mutex(values[i], &head);
                break;
            default:
                member_mutex(values[i], head);
                break;
        }
    }

    return NULL;
}

double time_mutex(int mInserts, int mDeletes, int thread_count) {
    n_threads_mutex = thread_count;
    pthread_t *thread_handles;
    thread_handles = (pthread_t *) malloc(thread_count * sizeof(pthread_t));

    double start, finish, elapsed;

    head = NULL;
    populate_initial(head);

    populate_values(values);
    populate_operations(operations, mInserts, mDeletes);

    GET_TIME(start);

    init_mutex();

    for (long thread = 0; thread < thread_count; thread++) {
        pthread_create(&thread_handles[thread], NULL, single_mutex, (void *) thread);
    }

    for (int thread = 0; thread < thread_count; thread++) {
        pthread_join(thread_handles[thread], NULL);
    }

    destroy_mutex();

    GET_TIME(finish);
    elapsed = finish - start;

    return elapsed;
}
