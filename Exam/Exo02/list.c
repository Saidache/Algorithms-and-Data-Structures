#include "list.h"
#include <stdio.h>
#include <stdlib.h>
 
void insert_at_head(DoublyLinkedList* list, int value) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    new_node->data = value;
    new_node->next = list->head;
    new_node->prev = NULL;

    if (list->head != NULL) {
        list->head->prev = new_node;
    }
    list->head = new_node;
}
 
void reverse_list(DoublyLinkedList* list) {
    Node* current = list->head;
    Node* temp = NULL;

    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
 
        current = current->prev;
    }
 
    if (temp != NULL) {
        list->head = temp->prev;
    }
}
 
void print_list(DoublyLinkedList* list) {
    Node* current = list->head;
    while (current != NULL) {
        printf("%d <-> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}
 
void free_list(DoublyLinkedList* list) {
    Node* current = list->head;
    Node* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    list->head = NULL;
}