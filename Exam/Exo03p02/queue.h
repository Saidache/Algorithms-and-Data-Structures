#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>

#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int front, rear;
} Queue;

// Function prototypes
void initializeQueue(Queue* q);
bool isEmptyQueue(Queue* q);
bool isFullQueue(Queue* q);
void enqueue(Queue* q, int value);
int dequeue(Queue* q);

#endif // QUEUE_H