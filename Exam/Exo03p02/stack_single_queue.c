#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    Queue q;
} StackSingleQueue;
 
void pushSingleQueue(StackSingleQueue* stack, int value) {
    int size = 0;
    Queue temp;
    initializeQueue(&temp);
 
    while (!isEmptyQueue(&stack->q)) {
        enqueue(&temp, dequeue(&stack->q));
        size++;
    }
 
    enqueue(&stack->q, value);
 
    while (!isEmptyQueue(&temp)) {
        enqueue(&stack->q, dequeue(&temp));
    }
}
 
int popSingleQueue(StackSingleQueue* stack) {
    if (isEmptyQueue(&stack->q)) {
        fprintf(stderr, "Stack is empty\n");
        exit(EXIT_FAILURE);
    }
    return dequeue(&stack->q);
}
 
int peekSingleQueue(StackSingleQueue* stack) {
    if (isEmptyQueue(&stack->q)) {
        fprintf(stderr, "Stack is empty\n");
        exit(EXIT_FAILURE);
    }
    return stack->q.data[stack->q.front];
}
 
bool emptySingleQueue(StackSingleQueue* stack) {
    return isEmptyQueue(&stack->q);
}