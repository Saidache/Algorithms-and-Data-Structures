#include "list.h"

int main() {
    LinkedList list = {NULL};  

    insert_at_position(&list, 10, 0);
    print_list(&list); 
 
    insert_at_position(&list, 20, 1);
    print_list(&list);  
 
    insert_at_position(&list, 15, 1);
    print_list(&list);  
 
    LinkedList empty_list = {NULL};
    insert_at_position(&empty_list, 5, 0);
    print_list(&empty_list);  
 
    insert_at_position(&list, 30, 5); 
 
    free_list(&list);
    free_list(&empty_list);

    return 0;
}