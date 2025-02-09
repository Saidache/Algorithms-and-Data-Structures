#ifndef STACK_H
#define STACK_H

// Define the maximum size of the stack
#define MAX_SIZE_S 100

// Stack structure definition
typedef struct {
    int items[MAX_SIZE_S];
    int top;
} Stack;

// Function prototypes
void initStack(Stack* stack);
int is_empty_s(const Stack* stack);
int is_full_s(const Stack* stack);
void push(Stack* stack, int item);
int pop(Stack* stack);
int peek_s(const Stack* stack);
void clear(Stack* stack);

#endif // STACK_H
