#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

// Initializes the stack by setting the top index to -1
void initStack(Stack* stack) {
    stack->top = -1;
}

// Checks if the stack is empty (top index is -1)
int is_empty_s(const Stack* stack) {
    return stack->top == -1;
}

// Checks if the stack is full (top index is MAX_SIZE-1)
int is_full_s(const Stack* stack) {
    return stack->top == MAX_SIZE_S - 1;
}

// Pushes an item to the stack (increments top and adds item)
void push(Stack* stack, int item) {
    if (is_full_s(stack)) {
        printf("Stack Overflow! Unable to push %d\n", item);
        return;
    }
    stack->items[++stack->top] = item;
    printf("Pushed %d onto the stack\n", item);
}

// Pops an item from the stack (decrements top and returns item)
int pop(Stack* stack) {
    if (is_empty_s(stack)) {
        printf("Stack Underflow! Unable to pop\n");
        return -1;  // Return -1 to indicate an error
    }
    return stack->items[stack->top--];
}

// Returns the top item of the stack without removing it
int peek_s(const Stack* stack) {
    if (is_empty_s(stack)) {
        printf("Stack is empty! Cannot peek\n");
        return -1;  // Return -1 to indicate an error
    }
    return stack->items[stack->top];
}

// Clears the stack by resetting the top index to -1
void clear(Stack* stack) {
    stack->top = -1;
    printf("Stack cleared!\n");
}
