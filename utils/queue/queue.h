#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>

typedef struct queue_node {
    void *data;
    struct queue_node *next;
} QueueNode;

typedef struct queue {
    QueueNode *front;
    QueueNode *rear;
} Queue;

void queue_init(Queue *queue);
void queue_push(Queue *queue, void *data);
void *queue_pop(Queue *queue);
bool queue_is_empty(Queue *queue);
void queue_dispose(Queue *queue);

#endif
