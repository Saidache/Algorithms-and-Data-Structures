#include "stack.h"
#include <stdio.h>
#include <ctype.h>

//EXO 02. BEGIN

int is_matching_pair(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

int is_balanced(const char* expression) {
    Stack stack;
    initStack(&stack);

    for (int i = 0; expression[i] != '\0'; i++) {
        char ch = expression[i];

        if (ch == '(' || ch == '{' || ch == '[') {
            push(&stack, ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (is_empty(&stack)) {
                return 0; // Unbalanced
            }
            char top = pop(&stack);
            if (!is_matching_pair(top, ch)) {
                return 0; // Unbalanced
            }
        }
    }

    return is_empty(&stack);
}

//EXO 02. END

//EXO 03. BEGIN

int precedence(char op) {
    switch (op) {
        case '+': case '-': return 1;
        case '*': case '/': return 2;
        default: return 0;
    }
}

void infix_to_postfix(const char* infix, char* postfix) {
    Stack stack;
    initStack(&stack);
    int k = 0;

    for (int i = 0; infix[i] != '\0'; i++) {
        char ch = infix[i];

        if (isalnum(ch)) {
            postfix[k++] = ch;
        } else if (ch == '(') {
            push(&stack, ch);
        } else if (ch == ')') {
            while (!is_empty(&stack) && peek(&stack) != '(') {
                postfix[k++] = pop(&stack);
            }
            pop(&stack); // Remove '('
        } else {
            while (!is_empty(&stack) && precedence(peek(&stack)) >= precedence(ch)) {
                postfix[k++] = pop(&stack);
            }
            push(&stack, ch);
        }
    }

    while (!is_empty(&stack)) {
        postfix[k++] = pop(&stack);
    }

    postfix[k] = '\0';
}

//EXO 03. END

//EXO 04. BEGIN
int evaluate_postfix(const char* postfix) {
    Stack stack;
    initStack(&stack);

    for (int i = 0; postfix[i] != '\0'; i++) {
        char ch = postfix[i];

        if (isdigit(ch)) {
            push(&stack, ch - '0'); // Convert char to int
        } else {
            int b = pop(&stack);
            int a = pop(&stack);

            switch (ch) {
                case '+': push(&stack, a + b); break;
                case '-': push(&stack, a - b); break;
                case '*': push(&stack, a * b); break;
                case '/': push(&stack, a / b); break;
            }
        }
    }

    return pop(&stack);
}
//EXO 04. END

//EXO 05. BEGIN
void insert_at_bottom(Stack* stack, int item) {
    if (is_empty(stack)) {
        push(stack, item);
    } else {
        int top = pop(stack);
        insert_at_bottom(stack, item);
        push(stack, top);
    }
}

void reverse_stack(Stack* stack) {
    if (!is_empty(stack)) {
        int top = pop(stack);
        reverse_stack(stack);
        insert_at_bottom(stack, top);
    }
}
//EXO 05. END

int main() {
    //EXO 01. BEGIN
     printf("Exercise 1: Implementing a stack and performing basic operations such as push, pop, peek, is_empty, and is_full.\n");

    Stack stack;

    // Initialize the stack
    initStack(&stack);

    // Test the stack functions
    push(&stack, '1');
    push(&stack, '2');
    push(&stack, '3');

    printf("Top element: %c\n", peek(&stack));

    printf("Popped element: %c\n", pop(&stack));
    printf("Popped element: %c\n", pop(&stack));
    printf("Top element after pops: %c\n", peek(&stack));

    // Clear the stack
    clear(&stack);

    // Check if stack is empty after clearing
    if (is_empty(&stack)) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack is not empty.\n");
    }
    //EXO 01. END

    //EXO 02. BEGIN
    printf("\nExercise 2: Checking if the parentheses in the given expression are balanced.\n");
    const char* expr1 = "({[()]})";
    const char* expr2 = "{[([))]}";

    printf("Expression 1: %s\n", is_balanced(expr1) ? "Balanced" : "Unbalanced");
    printf("Expression 2: %s\n", is_balanced(expr2) ? "Balanced" : "Unbalanced");
    //EXO 02. END

    //EXO 03. BEGIN
    printf("\nExercise 3: Converting the given infix expression to postfix notation.\n");
    const char* infix = "A+B*(C-D)";
    char postfix[100];

    infix_to_postfix(infix, postfix);
    printf("Postfix: %s\n", postfix);
    //EXO 03. END

    //EXO 04. BEGIN
    //printf("\nExercise 4: Evaluating the given postfix expression.\n");
    //const char* postfix = "34+2*7/";
    //printf("Result: %d\n", evaluate_postfix(postfix));
    //EXO 04. END

    //EXO 05. BEGIN
    printf("\nExercise 5: Reversing the given stack using recursion.\n");

    //Stack stack;
    initStack(&stack);

    push(&stack, '1');
    push(&stack, '2');
    push(&stack, '3');
    push(&stack, '4');

    printf("Original Stack:\n");
    while (!is_empty(&stack)) {
        printf("%c ", pop(&stack));
    }
    printf("\n");

    // Refill stack for reversal
    push(&stack, '1');
    push(&stack, '2');
    push(&stack, '3');
    push(&stack, '4');

    reverse_stack(&stack);

    printf("Reversed Stack:\n");
    while (!is_empty(&stack)) {
        printf("%c ", pop(&stack));
    }
    printf("\n");
    //END 05.END

    return 0;
}
