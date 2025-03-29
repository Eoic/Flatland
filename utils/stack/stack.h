#ifndef STACK_H
#define STACK_H

#include <stdbool.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

typedef struct stack {
    Node *head;
    size_t size;
} Stack;

Stack* stack_init();

void stack_push(Stack *stack, int data);

int stack_pop(Stack *stack);

void stack_free(Stack *stack);

bool stack_is_empty(Stack *stack);

#endif
