#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
 
void initializeQueue(Queue* q) {
    q->front = q->rear = -1;
}
 
bool isEmptyQueue(Queue* q) {
    return q->front == -1;
}
 
bool isFullQueue(Queue* q) {
    return (q->rear + 1) % MAX_SIZE == q->front;
}
 
void enqueue(Queue* q, int value) {
    if (isFullQueue(q)) {
        fprintf(stderr, "Queue is full\n");
        exit(EXIT_FAILURE);
    }
    if (isEmptyQueue(q)) {
        q->front = q->rear = 0;
    } else {
        q->rear = (q->rear + 1) % MAX_SIZE;
    }
    q->data[q->rear] = value;
}
 
int dequeue(Queue* q) {
    if (isEmptyQueue(q)) {
        fprintf(stderr, "Queue is empty\n");
        exit(EXIT_FAILURE);
    }
    int value = q->data[q->front];
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX_SIZE;
    }
    return value;
}