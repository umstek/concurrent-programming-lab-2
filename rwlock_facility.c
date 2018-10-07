#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

struct Node;

int member(int value, struct Node *head_p);

int insert(int value, struct Node **head_pp);

int delete(int value, struct Node **head_pp);

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
