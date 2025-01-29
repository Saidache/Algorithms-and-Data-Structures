#ifndef LIST_H
#define LIST_H

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

typedef struct {
    Node* head;
} DoublyLinkedList;

// Function prototypes
void reverse_list(DoublyLinkedList* list);
void print_list(DoublyLinkedList* list);
void insert_at_head(DoublyLinkedList* list, int value);
void free_list(DoublyLinkedList* list);

#endif // LIST_H