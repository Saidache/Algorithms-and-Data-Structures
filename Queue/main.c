#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "stack.h"

//EXO 03. BEGIN
// Function to reverse the queue using two stacks
void reverseQueue(Queue *q) {
    Stack stack1;
    initStack(&stack1);  // Initialize stack1

    // Step 1: Dequeue elements from the queue and push them to stack1
    while (!is_empty(q)) {
        int value = dequeue(q);
        push(&stack1, value);
    }

    // Step 2: Pop elements from stack1 and enqueue them back to the queue
    while (!is_empty_s(&stack1)) {
        int value = pop(&stack1);
        enqueue(q, value);
    }
}

//EXO 04. BEGIN
// Function to enqueue an element into the simulated queue
void enqueueUsingTwoStacks(Queue *q, Stack *stack1, Stack *stack2, int value) {
    push(stack1, value);
}

// Function to dequeue an element from the simulated queue
int dequeueUsingTwoStacks(Queue *q, Stack *stack1, Stack *stack2) {
    if (is_empty_s(stack2)) {
        // Transfer all elements from stack1 to stack2
        while (!is_empty_s(stack1)) {
            int value = pop(stack1);
            push(stack2, value);
        }
    }

    // If stack2 is still empty, the queue is empty
    if (is_empty_s(stack2)) {
        printf("Queue is empty.\n");
        return -1;
    }

    // Pop from stack2 to simulate dequeue
    return pop(stack2);
}
//EXO 04. END

//EXO 05. BEGIN


int main()
{
    //EXO 03. BEGIN
    printf("\n Exercice 03. Reversing the queue using two stacks.\n");

    Queue q;
    initializeQueue(&q);

    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    enqueue(&q, 4);

    printf("Queue before reversal:\n");
    for (int i = 0; i < 4; i++) {
        printf("%d ", q.queue[i]);
    }
    printf("\n");

    reverseQueue(&q);

    printf("Queue after reversal:\n");
    for (int i = 0; i < 4; i++) {
        printf("%d ", q.queue[i]);
    }
    printf("\n");
    //EXO 03. END

    //EXO 04. BEGIN
    printf("\n Exercice 04. Simulating a queue using two stacks (one for enqueue, one for dequeue).\n");

    Stack stack1, stack2;
    initStack(&stack1);
    initStack(&stack2);

    // Enqueue operations
    enqueueUsingTwoStacks(NULL, &stack1, &stack2, 10);
    enqueueUsingTwoStacks(NULL, &stack1, &stack2, 20);
    enqueueUsingTwoStacks(NULL, &stack1, &stack2, 30);

    // Dequeue operations
    printf("Dequeued: %d\n", dequeueUsingTwoStacks(NULL, &stack1, &stack2));
    printf("Dequeued: %d\n", dequeueUsingTwoStacks(NULL, &stack1, &stack2));


    //EXO 04. END

    //EXO 05. BEGIN
    //EXO 05. END


    return 0;
}
