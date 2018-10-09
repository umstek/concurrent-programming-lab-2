#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "timer.h"

#define M 10000

enum OperationType;

struct Node;

int member(int value, struct Node *head_p);

int insert(int value, struct Node **head_pp);

int delete(int value, struct Node **head_pp);

void populate_initial(struct Node *head_pp);

void populate_values(int *values);

void populate_operations(int *operations, int mInserts, int mDeletes);

int operations[M];
int values[M];

double time_serial(int mInserts, int mDeletes) {
    double start, finish, elapsed;

    struct Node *head = NULL;
    populate_initial(head);

    populate_values(values);
    populate_operations(operations, mInserts, mDeletes);

    GET_TIME(start);
    for (int i = 0; i < M; ++i) {
	// printf("%d,%d ", i, operations[i]);
        switch (operations[i]) {
            case 1:
                insert(values[i], &head);
                break;
            case 2:
                delete(values[i], &head);
                break;
            default:
                member(values[i], head);
                break;
        }
    }
    GET_TIME(finish);
    elapsed = finish - start;

    return elapsed;
}
