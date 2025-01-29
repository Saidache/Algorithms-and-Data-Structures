#include "list.h"
#include <stdio.h>
#include <stdlib.h>
void insert_at_position(LinkedList* list, int value, int k) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    new_node->data = value;
    new_node->next = NULL;
 
    if (k == 0) {
        new_node->next = list->head;
        list->head = new_node;
        return;
    }
 
    Node* current = list->head;
    for (int i = 0; i < k - 1; i++) {
        if (current == NULL) {
            fprintf(stderr, "Error: Position %d is out of bounds\n", k);
            free(new_node);
            return;
        }
        current = current->next;
    }

     
    new_node->next = current->next;
    current->next = new_node;
}
 
void print_list(LinkedList* list) {
    Node* current = list->head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void free_list(LinkedList* list) {
    Node* current = list->head;
    Node* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    list->head = NULL;
}