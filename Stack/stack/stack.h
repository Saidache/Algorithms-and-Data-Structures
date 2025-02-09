#ifndef STACK_H
#define STACK_H

#include "list.h"

// Define the Stack structure with a maximum size
typedef struct Stack {
    Node* top;        // Pointer to the top of the stack (head of the linked list)
    int max_size;     // Maximum size of the stack
    int current_size; // Current number of elements in the stack
} Stack;

// Function prototypes for stack operations
void initStack(Stack* stack, int max_size);  // Initializes the stack with a max size
int is_empty(Stack* stack);                   // Returns 1 if the stack is empty, 0 otherwise
int is_full(Stack* stack);                    // Returns 1 if the stack is full, 0 otherwise
void push(Stack* stack, int value);           // Pushes an element onto the stack
int pop(Stack* stack);                        // Pops an element from the stack and returns its value
int peek(Stack* stack);                       // Returns the top element of the stack without removing it
void clear(Stack* stack);                     // Clears the stack (removes all elements)

#endif // STACK_H
