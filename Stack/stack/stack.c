#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

// Initializes the stack with a maximum size and an empty list
void initStack(Stack* stack, int max_size) {
    stack->top = NULL;          // Start with an empty stack
    stack->max_size = max_size; // Set the max size of the stack
    stack->current_size = 0;    // Current size is zero
}

// Returns 1 if the stack is empty, otherwise returns 0
int is_empty(Stack* stack) {
    return stack->current_size == 0;
}

// Returns 1 if the stack is full, otherwise returns 0
int is_full(Stack* stack) {
    return stack->current_size == stack->max_size;
}

// Pushes an element onto the stack
void push(Stack* stack, int value) {
    if (is_full(stack)) {
        printf("Stack overflow! Cannot push %d, stack is full.\n", value);
        return; // Return without doing anything if the stack is full
    }

    // Create a new node for the element
    Node* newNode = createNode(value);
    // Link the new node to the current top of the stack
    setNext(newNode, stack->top);
    // Update the stack's top pointer to the new node
    stack->top = newNode;
    stack->current_size++;  // Increase the current size of the stack
    printf("Pushed %d onto the stack\n", value);
}

// Pops an element from the stack and returns its value
int pop(Stack* stack) {
    if (is_empty(stack)) {
        printf("Stack underflow! Cannot pop from an empty stack.\n");
        return -1;  // Return -1 to indicate an error (stack is empty)
    }

    // Remove the top node from the stack
    Node* topNode = stack->top;
    int value = getValue(topNode);  // Get the value of the top node
    stack->top = getNext(topNode);  // Update the top pointer to the next node
    deleteNode(topNode);           // Free the memory of the old top node
    stack->current_size--;         // Decrease the current size of the stack
    return value;                  // Return the value of the popped node
}

// Returns the value of the top element of the stack without removing it
int peek(Stack* stack) {
    if (is_empty(stack)) {
        printf("Stack is empty! Cannot peek.\n");
        return -1;  // Return -1 to indicate an error
    }

    return getValue(stack->top);  // Return the value of the top node
}

// Clears the stack by popping all elements
void clear(Stack* stack) {
    while (!is_empty(stack)) {
        pop(stack);  // Pop elements until the stack is empty
    }
    printf("Stack has been cleared.\n");
}
