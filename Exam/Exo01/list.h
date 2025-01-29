#ifndef LIST_H
#define LIST_H

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
} LinkedList;

// Function prototypes
void insert_at_position(LinkedList* list, int value, int k);
void print_list(LinkedList* list);
void free_list(LinkedList* list);

#endif 