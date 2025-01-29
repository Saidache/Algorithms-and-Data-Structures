#include <stdio.h>
#include "stack_single_queue.c"
#include "stack_two_queues.c"

int main() {
  
    StackSingleQueue stack1;
    initializeQueue(&stack1.q);

    pushSingleQueue(&stack1, 10);
    pushSingleQueue(&stack1, 20);
    pushSingleQueue(&stack1, 30);

    printf("Single Queue Approach:\n");
    printf("Peek: %d\n", peekSingleQueue(&stack1)); 
    printf("Pop: %d\n", popSingleQueue(&stack1));    
    printf("Pop: %d\n", popSingleQueue(&stack1));    
 
    StackTwoQueues stack2;
    initializeQueue(&stack2.q1);
    initializeQueue(&stack2.q2);

    pushTwoQueues(&stack2, 10);
    pushTwoQueues(&stack2, 20);
    pushTwoQueues(&stack2, 30);

    printf("\nTwo Queues Approach:\n");
    printf("Peek: %d\n", peekTwoQueues(&stack2)); 
    printf("Pop: %d\n", popTwoQueues(&stack2));    
    printf("Pop: %d\n", popTwoQueues(&stack2));    

    return 0;
}