#include "./stack.h"

#include <stdio.h>
#include <stdlib.h>

Stack *stack_init() {
    Stack *stack = (Stack*)malloc(sizeof(Stack));

    if (stack == NULL) {
        perror("Could not allocate memory for stack.");
        return NULL;
    }

    stack->head = NULL;
    stack->size = 0;

    return stack;
}

bool stack_is_empty(Stack *stack) {
    return stack->size == 0;
}

void stack_push(Stack *stack, int data) {
    Node *node = (Node*)malloc(sizeof(Node));

    if (node == NULL) {
        perror("Failed to allocate memory for stack item.");
        return;
    }

    node->data = data;
    node->next = stack->head;
    stack->head = node;
    stack->size++;
}

int stack_pop(Stack *stack) {
    if (stack_is_empty(stack))
        return -1;

    Node *node = stack->head;
    int data = node->data;
    stack->head = stack->head->next;
    stack->size--;
    free(node);

    return data;
}

void stack_free(Stack *stack) {
    while (!stack_is_empty(stack)) {
        stack_pop(stack);
    }

    free(stack);
}
