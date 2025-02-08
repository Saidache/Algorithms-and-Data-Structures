#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

// Definition of the tree node structure
typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} Node;

// Definition of the binary search tree structure
typedef struct bst {
    Node *root;
} BST;

// Function to create an empty binary search tree
BST* create_bst() {
    BST* tree = (BST*)malloc(sizeof(BST));
    if (tree == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    tree->root = NULL;
    return tree;
}

// Function to insert a value into a binary search tree
Node* insert(Node* node, int data) {
    if (node == NULL) {
        Node* new_node = (Node*)malloc(sizeof(Node));
        if (new_node == NULL) {
            perror("Memory allocation failed");
            exit(EXIT_FAILURE);
        }
        new_node->data = data;
        new_node->left = NULL;
        new_node->right = NULL;
        return new_node;
    }

    if (data < node->data) {
        node->left = insert(node->left, data);
    } else if (data > node->data) {
        node->right = insert(node->right, data);
    }
    return node;
}

// Function to create a random binary search tree
BST* create_random_bst(int max_nodes) {
    BST* tree = create_bst();
    int num_nodes = (rand() % max_nodes) + 1;

    for (int i = 0; i < num_nodes; i++) {
        int value = rand() % 1001;
        tree->root = insert(tree->root, value);
    }
    return tree;
}

// Function to compare trees (for qsort)
int compare_bsts(const void* a, const void* b) {
    BST* bst1 = *(BST**)a;
    BST* bst2 = *(BST**)b;

    if (bst1->root == NULL && bst2->root == NULL) return 0;
    if (bst1->root == NULL) return -1;
    if (bst2->root == NULL) return 1;

    return (bst1->root->data - bst2->root->data);
}

// Function to search for a value in the tree
Node* search(Node* node, int value) {
    if (node == NULL || node->data == value) {
        return node;
    }
    if (value < node->data) {
        return search(node->left, value);
    } else {
        return search(node->right, value);
    }
}

// Global search across all trees
int global_search(BST* bst_array[], int n, int value) {
    for (int i = 0; i < n; i++) {
        if (bst_array[i]->root != NULL && search(bst_array[i]->root, value) != NULL) {
            return i;
        }
    }
    return -1;
}

// Function to count the number of nodes in the tree
int countNodes(Node* node) {
    if (node == NULL) {
        return 0;
    }
    return 1 + countNodes(node->left) + countNodes(node->right);
}

// Print trees in different orders
void print_preorder(Node* node) {
    if (node != NULL) {
        printf("%d ", node->data);
        print_preorder(node->left);
        print_preorder(node->right);
    }
}

void print_inorder(Node* node) {
    if (node != NULL) {
        print_inorder(node->left);
        printf("%d ", node->data);
        print_inorder(node->right);
    }
}

void print_postorder(Node* node) {
    if (node != NULL) {
        print_postorder(node->left);
        print_postorder(node->right);
        printf("%d ", node->data);
    }
}

// Create DOT file for graphical representation
void create_dot_file(Node* node, FILE* file) {
    if (node != NULL) {
        fprintf(file, "%d [label=\"%d\"];\n", node->data, node->data);

        if (node->left != NULL) {
            fprintf(file, "%d -> %d;\n", node->data, node->left->data);
            create_dot_file(node->left, file);
        }

        if (node->right != NULL) {
            fprintf(file, "%d -> %d;\n", node->data, node->right->data);
            create_dot_file(node->right, file);
        }
    }
}

// Generate PNG from DOT file (using Graphviz)
void generate_png(BST* tree, int index) {
    char filename[100];
    sprintf(filename, "tree_%d.dot", index);

    FILE* dot_file = fopen(filename, "w");
    if (dot_file == NULL) {
        perror("Error opening DOT file");
        return;
    }

    fprintf(dot_file, "digraph G {\n");
    create_dot_file(tree->root, dot_file);
    fprintf(dot_file, "}\n");
    fclose(dot_file);

    char command[100];
    sprintf(command, "dot -Tpng %s -o tree_%d.png", filename, index);
    if (access("/usr/bin/dot", X_OK) == 0) {
        int result = system(command);
        if (result != 0) {
            perror("Error executing dot command");
        }
    } else {
        printf("Graphviz is not installed or not in PATH\n");
    }
    remove(filename);
}

// Free memory allocated for the tree
void free_bst(Node* node) {
    if (node != NULL) {
        free_bst(node->left);
        free_bst(node->right);
        free(node);
    }
}

int main() {
    int n; 
printf(" '########::'####:'##::: ##::::'###::::'########::'##:::'##: \n"); 
printf(" ##.... ##:. ##:: ###:: ##:::'## ##::: ##.... ##:. ##:'##::  \n");
printf(" ##:::: ##:: ##:: ####: ##::'##:. ##:: ##:::: ##::. ####:::  \n");
printf(" ########::: ##:: ## ## ##:'##:::. ##: ########::::. ##::::  \n");
printf(" ##.... ##:: ##:: ##. ####: #########: ##.. ##:::::: ##::::  \n");
printf(" ##:::: ##:: ##:: ##:. ###: ##.... ##: ##::. ##::::: ##::::  \n");
printf(" ########::'####: ##::. ##: ##:::: ##: ##:::. ##:::: ##::::  \n");
printf("........:::....::..::::..::..:::::..::..:::::..:::::..:::::  \n");
printf("'########:'########::'########:'########:                    \n");
printf("... ##..:: ##.... ##: ##.....:: ##.....::                    \n");
printf("::: ##:::: ##:::: ##: ##::::::: ##:::::::                    \n");
printf("::: ##:::: ########:: ######::: ######:::                    \n");
printf("::: ##:::: ##.. ##::: ##...:::: ##...::::                    \n");
printf("::: ##:::: ##::. ##:: ##::::::: ##:::::::                    \n");
printf("::: ##:::: ##:::. ##: ########: ########:                    \n");
printf(":::..:::::..:::::..::........::........::                    \n");
printf("'##:::::'##:'####:'########::::'###::::'########::'########::\n");
printf(" ##:'##: ##:. ##::..... ##::::'## ##::: ##.... ##: ##.... ##:\n");
printf(" ##: ##: ##:: ##:::::: ##::::'##:. ##:: ##:::: ##: ##:::: ##:\n");
printf(" ##: ##: ##:: ##::::: ##::::'##:::. ##: ########:: ##:::: ##:\n");
printf(" ##: ##: ##:: ##:::: ##::::: #########: ##.. ##::: ##:::: ##:\n");
printf(" ##: ##: ##:: ##::: ##:::::: ##.... ##: ##::. ##:: ##:::: ##:\n");
printf(". ###. ###::'####: ########: ##:::: ##: ##:::. ##: ########::\n");
printf(":...::...:::....::........::..:::::..::..:::::..::........:::\n");
printf("      test tp ASD doing by CHEHARA Saida GROUP 02  \n");
    printf("Enter the number of trees (N): ");
    scanf("%d", &n);

    BST* bst_array[n];
    srand(time(NULL));

    // Initialize the array of binary search trees
    for (int i = 0; i < n; i++) {
        bst_array[i] = create_bst();
    }

    int max_nodes_per_tree;
    printf("Enter the maximum number of nodes per tree: ");
    scanf("%d", &max_nodes_per_tree);

    int choice;
    do {
        printf("\nMenu:\n");
        printf("1. Add a value to a tree\n");
        printf("2. Sort the array of trees\n");
        printf("3. Search in a specific tree\n");
        printf("4. Global search\n");
        printf("5. Display statistics\n");
        printf("6. Print a tree (preorder, inorder, postorder)\n");
        printf("7. Fill empty cells with random trees\n");
        printf("8. Generate PNG of tree (Graphviz)\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int index, value;
                printf("Enter the index to insert into (0-%d): ", n - 1);
                scanf("%d", &index);
                if (index < 0 || index >= n) {
                    printf("Invalid index.\n");
                    break;
                }
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                bst_array[index]->root = insert(bst_array[index]->root, value);
                break;
            }
            case 2:
                qsort(bst_array, n, sizeof(BST*), compare_bsts);
                printf("Array sorted.\n");
                break;
            case 3: {
                int index_search, value_search;
                printf("Enter the index to search in: ");
                scanf("%d", &index_search);
                if (index_search < 0 || index_search >= n) {
                    printf("Invalid index.\n");
                    break;
                }
                printf("Enter the value to search for: ");
                scanf("%d", &value_search);

                if (bst_array[index_search]->root != NULL) {
                    Node* result = search(bst_array[index_search]->root, value_search);
                    if (result != NULL) {
                        printf("Value found in tree at index %d.\n", index_search);
                    } else {
                        printf("Value not found in tree at index %d.\n", index_search);
                    }
                } else {
                    printf("Tree at index %d is empty.\n", index_search);
                }
                break;
            }
            case 4: {
                int value_global_search;
                printf("Enter the value to search for globally: ");
                scanf("%d", &value_global_search);

                int index_found = global_search(bst_array, n, value_global_search);
                if (index_found != -1) {
                    printf("Value found in tree at index %d.\n", index_found);
                } else {
                    printf("Value not found in any tree.\n");
                }
                break;
            }
            case 5: {
                int minNodesIndex = -1, maxNodesIndex = -1;
                int minValueIndex = -1, maxValueIndex = -1;
                int minNodes = INT_MAX, maxNodes = INT_MIN;
                int minValue = INT_MAX, maxValue = INT_MIN;
                for (int i = 0; i < n; i++) {
                    if (bst_array[i] != NULL && bst_array[i]->root != NULL) {
                        int nodes = countNodes(bst_array[i]->root);
                        if (nodes < minNodes) {
                            minNodes = nodes;
                            minNodesIndex = i;
                        }
                        if (nodes > maxNodes) {
                            maxNodes = nodes;
                            maxNodesIndex = i;
                        }

                        Node* minNodeInTree = bst_array[i]->root;
                        while(minNodeInTree->left != NULL) minNodeInTree = minNodeInTree->left;
                        if(minNodeInTree->data < minValue){
                            minValue = minNodeInTree->data;
                            minValueIndex = i;
                        }

                        Node* maxNodeInTree = bst_array[i]->root;
                        while(maxNodeInTree->right != NULL) maxNodeInTree = maxNodeInTree->right;
                        if(maxNodeInTree->data > maxValue){
                            maxValue = maxNodeInTree->data;
                            maxValueIndex = i;
                        }
                    }
                }
                if (minNodesIndex != -1) {
                    printf("minNodesIndex : %d\n", minNodesIndex);
                } else {
                    printf("There are no nodes to calculate minNodesIndex\n");
                }
                if (maxNodesIndex != -1) {
                    printf("maxNodesIndex : %d\n", maxNodesIndex);
                } else {
                    printf("There are no nodes to calculate maxNodesIndex\n");
                }
                if (minValueIndex != -1) {
                    printf("minValueIndex : %d\n", minValueIndex);
                } else {
                    printf("There are no nodes to calculate minValueIndex\n");
                }
                if (maxValueIndex != -1) {
                    printf("maxValueIndex : %d\n", maxValueIndex);
                } else {
                    printf("There are no nodes to calculate maxValueIndex\n");
                }
                break;
            }
            case 6: {
                int index_print;
                printf("Enter the index of the tree to print: ");
                scanf("%d", &index_print);
                if(index_print < 0 || index_print >= n){
                    printf("Invalid index.\n");
                    break;
                }
                if (bst_array[index_print]->root != NULL) {
                    printf("Preorder: ");
                    print_preorder(bst_array[index_print]->root);
                    printf("\nInorder: ");
                    print_inorder(bst_array[index_print]->root);
                    printf("\nPostorder: ");
                    print_postorder(bst_array[index_print]->root);
                    printf("\n");
                } else {
                    printf("Tree at index %d is empty.\n", index_print);
                }
                break;
            }
            case 7: {
                int value;
                printf("Enter the value to fill empty cells: ");
                scanf("%d", &value);

                for (int i = 0; i < n; i++) {
                    if (bst_array[i]->root == NULL) {
                        bst_array[i]->root = insert(bst_array[i]->root, value);
                    }
                }
                break;
            }
            case 8: {
                for (int i = 0; i < n; i++) {
                    if (bst_array[i]->root != NULL) {
                        generate_png(bst_array[i], i);
                    }
                }
                break;
            }
            case 0:
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    } while (choice != 0);

    // Free allocated memory
    for (int i = 0; i < n; i++) {
        free_bst(bst_array[i]->root);
        free(bst_array[i]);
    }

    return 0;
}
