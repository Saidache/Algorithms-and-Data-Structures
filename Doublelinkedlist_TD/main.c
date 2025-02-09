#include <stdio.h>
#include <stdlib.h>
#include "list.h"

// Exo 01. Begin

Node* initializeList()
{
    Node* head = createNode(1);  // Create first node
    Node* current = head;
    for (int i = 2; i <= 5; i++)
    {
        Node* newNode = createNode(i);
        setNext(current, newNode);  // Link current node to the new node
        setPrev(newNode, current);  // Set the previous pointer of the new node
        current = newNode;  // Move current pointer
    }
    return head;  // Return the head of the list
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

void insert_begin(Node** head, int x)
{
    Node* newNode = createNode(x);  // Create new node
    if (*head == NULL)
    {
        *head = newNode;  // If the list is empty, set the new node as head
    }
    else
    {
        setNext(newNode, *head);  // Link the new node to the current head
        setPrev(*head, newNode);  // Set the previous pointer of the old head
        *head = newNode;  // Update head to the new node
    }
}

// Exo 02. End

// Exo 03. Begin
void delete_val(Node** head, int position)
{
    if (*head == NULL) return;
    Node* current = *head;
    int count = 0;

    if (position == 0)
    {
        *head = getNext(current);  // Update head if deleting the first node
        if (*head != NULL)
        {
            setPrev(*head, NULL);
        }
        deleteNode(current);  // Delete the node
        return;
    }

    while (current != NULL && count < position)
    {
        current = getNext(current);
        count++;
    }

    if (current == NULL) return;
    setNext(getPrev(current), getNext(current));  // Link previous node to the next node

    deleteNode(current);  // Free the node's memory
}

// Exo 03. End

// Exo 04. Begin
void traverse_forward(Node* head)
{
    Node* current = head;
    while (current != NULL)
    {
        printf("%d -> ", getValue(current));  // Print node value
        current = getNext(current);  // Move to next node
    }
    printf("NULL\n");  // Indicate end of list
}

// Exo 04. End

// Exo 05. Begin
void traverse_backward(Node* head)
{
    Node* current = head;
    while (current != NULL && getNext(current) != NULL)
    {
        current = getNext(current);  // Move to the last node
    }

    while (current != NULL)
    {
        printf("%d -> ", getValue(current));  // Print node value
        current = getPrev(current);  // Move to the previous node
    }
    printf("NULL\n");  // Indicate end of list
}

// Exo 05. End

// Exo 06. Begin

Node* find_middle(Node* head)
{
    if (head == NULL) return NULL;

    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && getNext(fast) != NULL)
    {
        slow = getNext(slow);  // Move slow pointer one step
        fast = getNext(getNext(fast));  // Move fast pointer two steps
    }

    return slow;  // Return the middle node
}

// Exo 06. End

// Exo 07. Begin
int has_cycle(Node* head)
{
    if (head == NULL) return 0;

    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && getNext(fast) != NULL)
    {
        slow = getNext(slow);  // Move slow pointer one step
        fast = getNext(getNext(fast));  // Move fast pointer two steps

        if (slow == fast)    // If slow and fast pointers meet, there is a cycle
        {
            return 1;
        }
    }

    return 0;  // No cycle detected
}
// Exo 07. End

// Exo 08. Begin
Node* copy(Node* head)
{
    if (head == NULL) return NULL;

    Node* newHead = createNode(getValue(head));  // Create first node of the copy
    Node* current = getNext(head);
    Node* newCurrent = newHead;

    while (current != NULL)
    {
        Node* newNode = createNode(getValue(current));  // Create a new node
        setNext(newCurrent, newNode);  // Link the new node to the copy
        setPrev(newNode, newCurrent);
        newCurrent = newNode;
        current = getNext(current);
    }

    return newHead;  // Return the copied list
}
// Exo 08. End

// Exo 09. Begin

Node* kth_from_end(Node* head, int k)
{
    if (head == NULL) return NULL;

    Node* first = head;
    Node* second = head;

    for (int i = 0; i < k; i++)
    {
        if (first == NULL) return NULL;
        first = getNext(first);  // Move the first pointer k steps ahead
    }

    while (first != NULL)
    {
        first = getNext(first);  // Move both pointers until first reaches the end
        second = getNext(second);
    }

    return second;  // Return the K-th node from the end
}
// Exo 09. End


int main()
{
    // Exo 01. Begin
    printf("\n1. Initialization: Defining a doubly linked list and adding 3 nodes with arbitrary values...\n");
    Node* list = initializeList();
    printList(list);
    // Exo 01. End
    // Exo 02. Begin
    printf("\n2. Insert at Beginning: Inserting a given element at the beginning of the doubly linked list...\n");
    insert_begin(&list, 6);
    printList(list);

    // Exo 02. End

    // Exo 03. Begin
    printf("\n3. Delete Node by Position: Deleting the node at position x from the doubly linked list...\n");
    delete_val(&list, 0);
    printList(list);
    // Exo 03. End

    // Exo 04. Begin
    printf("\n4. Traverse Forward: Traversing the doubly linked list from head to tail...\n");
    traverse_forward(list);
    // Exo 04. End

    // Exo 05. Begin
    printf("\n5. Traverse Backward: Traversing the doubly linked list from tail to head...\n");
    traverse_backward(list);
    // Exo 05. End

    // Exo 06. Begin
    printf("\n6. Find Middle Node: Finding the middle node of the doubly linked list...\n");
    Node* middle = find_middle(list);
    if (middle != NULL)
        printf("The middle node value %d\n", getValue(middle));

    // Exo 06. End

    // Exo 07. Begin
    printf("\n7. Detect Cycle: Checking if the linked list contains a cycle...\n");
    if (has_cycle(list)== 0)
        printf("No cycle detected\n");
    else
        printf("The list has cycle\n");
    // Exo 07. End

    // Exo 08. Begin
    printf("\n8. Copy List: Creating a new doubly linked list as a copy of the original list...\n");
    Node* list_cp  = copy(list);
    printList(list_cp);
    // Exo 08. End

    // Exo 09. Begin
    printf("\n9. Kth Node from End: Finding the k-th node from the end of the doubly linked list...\n");
    Node* kth = kth_from_end(list, 4);
    if (kth != NULL)
        printf("Kth node from end value is %d\n",getValue(kth));
    else
        printf("Kth node from end value is Empty\n");

    // Exo 09. End

    return 0;
}
