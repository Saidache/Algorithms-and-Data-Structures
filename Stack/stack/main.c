#include <stdio.h>
#include "stack.h"

int main() {
    // Create a stack with a max size of 5
    Stack stack;
    initStack(&stack, 5);

    // Test stack operations
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    push(&stack, 40);
    push(&stack, 50);
    push(&stack, 60);  // This should show "Stack overflow!" since the max size is 5

    printf("Top element: %d\n", peek(&stack));  // Peek at the top element

    printf("Popped element: %d\n", pop(&stack));  // Pop an element
    printf("Popped element: %d\n", pop(&stack));  // Pop another element
    printf("Top element after pops: %d\n", peek(&stack));  // Peek again

    clear(&stack);  // Clear the stack

    return 0;
}
