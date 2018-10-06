#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

struct Node;

int member(int value, struct Node *head_p);

int insert(int value, struct Node **head_pp);

int delete(int value, struct Node **head_pp);

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
