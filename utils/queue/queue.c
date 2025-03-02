#include "queue.h"

#include <stdio.h>
#include <stdlib.h>

void queue_init(Queue *queue) {
    queue->front = NULL;
    queue->rear = NULL;
}

bool queue_is_empty(Queue *queue) { return queue->front == NULL && queue->rear == NULL; }

void queue_push(Queue *queue, void *data) {
    QueueNode *node = (QueueNode *)malloc(sizeof(QueueNode));

    if (node == NULL) {
        fprintf(stderr, "Failed to allocate memory!");
        return;
    }

    node->data = data;
    node->next = NULL;

    if (queue_is_empty(queue)) {
        queue->front = node;
        queue->rear = node;
        return;
    }

    queue->rear->next = node;
    queue->rear = node;
}

void *queue_pop(Queue *queue) {
    if (queue_is_empty(queue)) {
        return NULL;
    }

    QueueNode *temp = queue->front;
    void *data = temp->data;

    queue->front = queue->front->next;

    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    temp->data = NULL;
    free(temp);

    return data;
}

void queue_dispose(Queue *queue) {
    QueueNode *current = queue->front;

    while (current != NULL) {
        QueueNode *temp = current;
        current = current->next;
        free(temp);
    }

    queue->front = NULL;
    queue->rear = NULL;
}