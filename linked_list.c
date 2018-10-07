#include <stdio.h>
#include <stdlib.h>

#define N 1000

struct Node {
    int data;
    struct Node *next_p;
};

int member(int value, struct Node *head_p) {
    struct Node *current_p = head_p;
    while (current_p != NULL && current_p->data < value) current_p = current_p->next_p;
    if (current_p == NULL || current_p->data > value) return 0; else return 1;
}

int insert(int value, struct Node **head_pp) {
    struct Node *current_p = *head_pp;
    struct Node *pred_p = NULL;
    struct Node *temp_p;

    while (current_p != NULL && current_p->data < value) {
        pred_p = current_p;
        current_p = current_p->next_p;
    }

    if (current_p == NULL || current_p->data > value) {
        temp_p = malloc(sizeof(struct Node));
        temp_p->data = value;
        temp_p->next_p = current_p;

        if (pred_p == NULL) *head_pp = temp_p; else pred_p->next_p = temp_p;

        return 1;
    } else return 0;
}

int delete(int value, struct Node **head_pp) {
    struct Node *current_p = *head_pp;
    struct Node *pred_p = NULL;

    while (current_p != NULL && current_p->data < value) {
        pred_p = current_p;
        current_p = current_p->next_p;
    }

    if (current_p != NULL && current_p->data == value) {
        if (pred_p == NULL) {
            *head_pp = current_p->next_p;
            free(current_p);
        } else {
            pred_p->next_p = current_p->next_p;
            free(current_p);
        }
        return 1;
    } else return 0;
}

void populate_initial(struct Node *head_pp) {
    for (int i = 0; i < N; ++i) {
        int r = rand() % 65536;
        if (!insert(r, &head_pp)) i--;
    }
}
