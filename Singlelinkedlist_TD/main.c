#include <stdio.h>
#include "list.h"

//Exo 01. Begin
Node* initializeList()
{
    Node* head = createNode(1);
    Node* current = head;

    for (int i = 2; i <= 5; i++)
    {
        Node* newNode = createNode(i);
        setNext(current, newNode);
        current = newNode;
    }

    return head;
}

void printList(Node* head)
{
    Node* current = head;
    while (current != NULL)
    {
        printf("%d -> ", getValue(current));
        current = getNext(current);
    }
    printf("NULL\n");
}
// Exo 01. End

// Exo 02. Begin
void insert_end(Node* head, int x) {
    Node* newNode = createNode(x);
    Node* current = head;

    while (getNext(current) != NULL) {
        current = getNext(current);
    }

    setNext(current, newNode);
}
// Exo 02. End

// Exo 03. Begin
void delete_val(Node** head, int x) {
    Node* current = *head;
    Node* prev = NULL;

    while (current != NULL) {
        if (getValue(current) == x) {
            if (prev != NULL) {
                setNext(prev, getNext(current));
            } else {
                // Deleting the head node
                Node* nextNode = getNext(current);
                *head = nextNode;
            }
            deleteNode(current);
            return;
        }
        prev = current;
        current = getNext(current);
    }
}
// Exo 03. End

// Exo 04. Begin
int search(Node* head, int x) {
    int index = 0;
    Node* current = head;

    while (current != NULL) {
        if (getValue(current) == x) {
            return index+1;
        }
        current = getNext(current);
        index++;
    }

    return -1; // Not found
}
// Exo 04. End

// Exo 05. Begin
int count(Node* head, int x) {
    int count = 0;
    Node* current = head;

    while (current != NULL) {
        if (getValue(current) == x) {
            count++;
        }
        current = getNext(current);
    }

    return count;
}
// Exo 05. End

// Exo 06. Begin
void reverse(Node** head) {
    Node* prev = NULL;
    Node* current = *head;
    Node* next = NULL;

    while (current != NULL) {
        next = getNext(current);
        setNext(current, prev);
        prev = current;
        current = next;
    }

    *head = prev;
}
// Exo 06. End

// Exo 07. Begin
void sort(Node* head) {
    if (head == NULL || getNext(head) == NULL) return;

    Node* current = head;
    Node* nextNode;
    int swapped;

    do {
        swapped = 0;
        current = head;

        while (getNext(current) != NULL) {
            nextNode = getNext(current);
            if (getValue(current) > getValue(nextNode)) {
                // Swap values
                int temp = getValue(current);
                setValue(current, getValue(nextNode));
                setValue(nextNode, temp);
                swapped = 1;
            }
            current = nextNode;
        }
    } while (swapped);
}
// Exo 07. End

// Exo 08. Begin
Node* merge(Node* L1, Node* L2) {
    // Check if either list is empty
    if (L1 == NULL) return L2;
    if (L2 == NULL) return L1;

    Node* mergedList = NULL;  // Pointer to the head of the merged list
    Node* current = NULL;  // Pointer to the last node in the merged list

    // Decide which list should be the head of the merged list based on the first element
    if (getValue(L1) < getValue(L2)) {
        mergedList = L1;
        L1 = getNext(L1);
    } else {
        mergedList = L2;
        L2 = getNext(L2);
    }

    // Set current to the head of the merged list to start building
    current = mergedList;

    // Merge the remaining nodes
    while (L1 != NULL && L2 != NULL) {
        if (getValue(L1) < getValue(L2)) {
            setNext(current, L1);  // Link the current node to L1
            L1 = getNext(L1);      // Move L1 to the next node
        } else {
            setNext(current, L2);  // Link the current node to L2
            L2 = getNext(L2);      // Move L2 to the next node
        }
        current = getNext(current);  // Move current to point to the newly added node
    }

    // Attach the remaining nodes from L1 or L2, if any
    if (L1 != NULL) {
        setNext(current, L1);
    } else {
        setNext(current, L2);
    }

    return mergedList;  // Return the head of the merged list
}

// Exo 08. End

// Exo 09. Begin
void remove_duplicates(Node* head) {
    Node* current = head;

    while (current != NULL) {
        Node* runner = getNext(current);
        Node* prevRunner = current;

        while (runner != NULL) {
            if (getValue(current) == getValue(runner)) {
                setNext(prevRunner, getNext(runner));
                deleteNode(runner);
                runner = getNext(prevRunner);
            } else {
                prevRunner = runner;
                runner = getNext(runner);
            }
        }
        current = getNext(current);
    }
}
// Exo 09. End

// Exo 10. Begin
int kth_largest(Node* head, int k) {
    // Helper function to count the number of nodes in the list
    int count_nodes(Node* node) {
        int count = 0;
        while (node != NULL) {
            count++;
            node = getNext(node);
        }
        return count;
    }
    // Count the total number of nodes in the list
    int totalNodes = count_nodes(head);
    if (k > totalNodes || k <= 0) {
        return -1; // Invalid k value
    }

    // Helper function to find the k-th largest element in the list
    int find_kth_largest(Node* node, int k) {
        int size = count_nodes(node);
        if (size == 0) {
            return -1; // List is empty
        }

        Node* current = node;
        int kthLargest = -1;

        // Traverse the list to find the k-th largest element
        while (current != NULL) {
            // Count elements greater than the current node's value
            Node* compareNode = node;
            int greaterCount = 0;
            while (compareNode != NULL) {
                if (getValue(compareNode) > getValue(current)) {
                    greaterCount++;
                }
                compareNode = getNext(compareNode);
            }

            // If the number of elements greater than the current node is exactly k - 1,
            // then the current node is the k-th largest
            if (greaterCount == k - 1) {
                kthLargest = getValue(current);
                break;
            }
            current = getNext(current);
        }
        return kthLargest;
    }
    return find_kth_largest(head, k);
}


// Exo 10. End

int main()
{
    // Exo 01. Begin
    printf("\nExercise 1: Initializing the list with 5 elements.\n");

    Node* list = initializeList();
    printList(list);
    // Exo 01. End

    // Exo 02. Begin
    printf("\nExercise 2: Inserting given value at the end of the list.\n");

    insert_end(list, 6);
    printList(list);
    // Exo 02. End

    // Exo 03. Begin
    printf("\nExercise 3: Deleting the first occurrence of given value from the list.\n");

    delete_val(&list, 1);
    printList(list);
    delete_val(&list, 6);
    printList(list);
    // Exo 03. End

    // Exo 04. Begin
    printf("\nExercise 4: Searching for a given value in the list.\n");

    int index = search(list, 4);
    printf("Found %d at index %d.\n", 4, index);
    // Exo 04. End

    // Exo 05. Begin
    printf("\nExercise 5: Counting occurrences of a given value in the list.\n");

    insert_end(list,4);
    int c = count(list, 4);
    printf("\nThe value %d appears %d times in the list.\n", 4, c);
    // Exo 05. End

    // Exo 06. Begin
    printf("\nExercise 6: Reversing the list.\n");

    reverse(&list);
    printList(list);
    // Exo 06. End

    // Exo 07. Begin
    printf("\nExercise 7: Sorting the list.\n");

    sort(list);
    printList(list);
    // Exo 07. End

    // Exo 08. Begin
    printf("\nExercise 8: Merging two sorted lists.\n");
    Node* list1 = initializeList();
    Node* list2 = initializeList();

    Node* mergedList = merge(list1,list2);
    printList(mergedList);
    // Exo 08. End

    //Exo 09. Begin
    printf("\nExercise 9: Removing duplicate values from the list.\n");
    remove_duplicates(list);
    printList(list);
    //Exo 09. End

    //Exo 10. Begin
    printf("\10Exercise 10: Finding the k-th largest element in the list.\n");
    int kthLargest = kth_largest(list,2) ;
    printf("The %d-th largest element in the list is %d.\n", 2, kthLargest);
    //Exo 10. End
    return 0;
}
