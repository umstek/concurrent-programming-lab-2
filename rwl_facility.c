#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

struct Node;

int member(int value, struct Node *head_p);

int insert(int value, struct Node **head_pp);

int delete(int value, struct Node **head_pp);

