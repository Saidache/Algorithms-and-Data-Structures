#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    Queue q1, q2;
} StackTwoQueues;
 
void pushTwoQueues(StackTwoQueues* stack, int value) {
    enqueue(&stack->q2, value);
    while (!isEmptyQueue(&stack->q1)) {
        enqueue(&stack->q2, dequeue(&stack->q1));
    }
    Queue temp = stack->q1;
    stack->q1 = stack->q2;
    stack->q2 = temp;
}
 
int popTwoQueues(StackTwoQueues* stack) {
    if (isEmptyQueue(&stack->q1)) {
        fprintf(stderr, "Stack is empty\n");
        exit(EXIT_FAILURE);
    }
    return dequeue(&stack->q1);
}
int peekTwoQueues(StackTwoQueues* stack) {
    if (isEmptyQueue(&stack->q1)) {
        fprintf(stderr, "Stack is empty\n");
        exit(EXIT_FAILURE);
    }
    return stack->q1.data[stack->q1.front];
}
bool emptyTwoQueues(StackTwoQueues* stack) {
    return isEmptyQueue(&stack->q1);
}