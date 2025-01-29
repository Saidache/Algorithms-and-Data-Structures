#include "list.h"
#include <stddef.h>

int main() {
    DoublyLinkedList list = {NULL}; 
    insert_at_head(&list, 10);
    insert_at_head(&list, 20);
    insert_at_head(&list, 30);
    insert_at_head(&list, 40);
    printf("Original list: ");
    print_list(&list); 
    reverse_list(&list);
    printf("Reversed list: ");
    print_list(&list); 
    free_list(&list);

    return 0;
}