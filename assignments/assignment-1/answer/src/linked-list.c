#include <malloc.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef int Key;

typedef struct linked_list {
    struct node *front;
    size_t length;
} Linked_List;

typedef struct node {
    Key key;
    struct node *next;
} Node;

// Function prototypes

/* Create a Linked List and return a pointer to it. */
Linked_List *create_linked_list();

/* Write the key of all nodes in `linked_list` to stdout. */
void print_linked_list(Linked_List *linked_list);

/* Insert `node` at the beginning of `linked_list`. */
bool push_front(Linked_List *linked_list, Node *node);

/* Insert `node` at the end of `linked_list`. */
bool push_back(Linked_List *linked_list, Node *node);

/* Remove the node at the beginning of `linked_list`. */
bool remove_front(Linked_List *linked_list);

/* Remove the node at the end of `linked_list`. */
bool remove_back(Linked_List *linked_list);

/* Remove and deallocate all nodes of a given Linked List. */
void remove_all_nodes(Linked_List *linked_list);

/* Search for a node by its key.
   Return a pointer to the found node or NULL if it was not found in `linked_list`.
*/
Node *search_by_key(Linked_List *linked_list, Key key);

/* Verify whether `linked_list` is NULL. */
bool is_linked_list_null(Linked_List *linked_list);

/* Verify whether `linked_list is empty`. */
bool is_linked_list_empty(Linked_List *linked_list);

int main() {

    Linked_List *empty_linked_list = create_linked_list();
    Linked_List *main_linked_list = create_linked_list();
    Linked_List *unitary_linked_list = create_linked_list();


    Node *node_1 = (Node *)malloc(sizeof(Node));
    node_1->key = 1;

    Node *node_2 = (Node *)malloc(sizeof(Node));
    node_2->key = 2;

    Node *node_3 = (Node *)malloc(sizeof(Node));
    node_3->key = 3;

    Node *node_4 = (Node *)malloc(sizeof(Node));
    node_4->key = 4;

    Node *main_linked_list_first_node = (Node *)malloc(sizeof(Node));
    main_linked_list_first_node->key = 10;

    // Alocate the unique node of `unitary_linked_list`

    Node *unitary_linked_list_node = (Node *)malloc(sizeof(Node));
    unitary_linked_list_node->key = 25;


    puts("Testing `push_back()` and `print_linked_list()` functions:\n");

    print_linked_list(empty_linked_list);

    push_back(main_linked_list, node_1);
    print_linked_list(main_linked_list);

    push_back(main_linked_list, node_2);
    print_linked_list(main_linked_list);

    push_back(main_linked_list, node_3);
    print_linked_list(main_linked_list);

    push_back(main_linked_list, node_4);
    print_linked_list(main_linked_list);

    push_back(unitary_linked_list, unitary_linked_list_node);
    print_linked_list(unitary_linked_list);

    puts("\n\nTesting `push_front()` function:\n");

    push_front(main_linked_list, main_linked_list_first_node);
    print_linked_list(main_linked_list);

    puts("\n\nTesting `search_by_key()` function:\n");

    puts((search_by_key(empty_linked_list, 1))
             ? "There is a node with the key '1' in the empty Linked List."
             : "There is no node with the key '1' in the empty Linked List.");

    puts((search_by_key(main_linked_list, 1))
             ? "There is a node with the key '1' in the main Linked List."
             : "There is no node with the key '1' in the main Linked List.");

    puts((search_by_key(main_linked_list, 2))
             ? "There is a node with the key '2' in the main Linked List."
             : "There is no node with the key '2' in the main Linked List.");
    
    puts((search_by_key(main_linked_list, 3))
             ? "There is a node with the key '3' in the main Linked List."
             : "There is no node with the key '3' in the main Linked List.");
    
    puts((search_by_key(main_linked_list, 4))
             ? "There is a node with the key '4' in the main Linked List."
             : "There is no node with the key '4' in the main Linked List.");

    puts((search_by_key(main_linked_list, 5))
             ? "There is a node with the key '5' in the main Linked List."
             : "There is no node with the key '5' in the main Linked List.");
    
    puts((search_by_key(main_linked_list, 6))
             ? "There is a node with the key '6' in the main Linked List."
             : "There is no node with the key '6' in the main Linked List.");

    
    puts("\n\nTesting `remove_front()` function:\n");

    puts("`main_linked_list` before removing the front node:");
    print_linked_list(main_linked_list);
    puts("");

    remove_front(main_linked_list);
    
    puts("`main_linked_list` after removing the front node:");
    print_linked_list(main_linked_list);

    puts("\n`unitary_linked_list` before removing the front node:");
    print_linked_list(unitary_linked_list);

    remove_front(unitary_linked_list);
    puts("\n`unitary_linked_list` after removing the front node:");
    print_linked_list(unitary_linked_list);


    puts("\n\nTesting `remove_back()` function:\n");

    puts("`main_linked_list` before removing the back node:");
    print_linked_list(main_linked_list);

    remove_back(main_linked_list);

    puts("\n`main_linked_list` after removing the back node:");
    print_linked_list(main_linked_list);

    puts("\nTesting `remove_all_nodes()` function:\n");
    
    puts("`main_linked_list` before removing all of its nodes:");
    print_linked_list(main_linked_list); 

    remove_all_nodes(main_linked_list);

    puts("`\nmain_linked_list` after removing all of its nodes:");
    print_linked_list(main_linked_list); 
    

    return 0;
}

// Function implementations

Linked_List *create_linked_list() {
    Linked_List *new_linked_list = (Linked_List *)malloc(sizeof(Linked_List));

    new_linked_list->front == NULL;

    new_linked_list->length = 0;

    return new_linked_list;
}

void print_linked_list(Linked_List *linked_list) {
    if (is_linked_list_null(linked_list)) {
        puts("ERROR! `linked_list` parameter is NULL.");
        return;
    }

    if (is_linked_list_empty(linked_list)) {
        puts("There is no node in the given Linked List.");
        return;
    }

    if (linked_list->length == 1) {
        printf("The given Linked List has only one node as shown bellow:\n");
        printf("%d --> NULL\n", linked_list->front->key);
        return;
    }

    Node *nodeTemp = linked_list->front;

    printf("The given Linked List has %zu nodes and their key are:\n",
           linked_list->length);

    while (nodeTemp != NULL) {
        printf("%d --> ", nodeTemp->key);
        nodeTemp = nodeTemp->next;
    }

    printf("NULL\n");
}

bool push_front(Linked_List *linked_list, Node *node) {
    if (is_linked_list_null(linked_list)) {
        return false;
    }

    if (is_linked_list_empty(linked_list)) {
        linked_list->front = node;
        node->next = NULL;
        linked_list->length = 1;
        return true;
    }

    node->next = linked_list->front;

    linked_list->front = node;

    linked_list->length++;

    return true;
}

bool push_back(Linked_List *linked_list, Node *node) {
    if (is_linked_list_null(linked_list)) {
        return false;
    }

    if (is_linked_list_empty(linked_list)) {
        linked_list->front = node;
        linked_list->length = 1;
        return true;
    }

    Node *nodeTemp = linked_list->front;

    while (nodeTemp->next != NULL) {
        nodeTemp = nodeTemp->next;
    }

    node->next = NULL;

    nodeTemp->next = node;

    linked_list->length++;

    return true;
}

bool remove_front(Linked_List *linked_list) {
    if (is_linked_list_null(linked_list)) {
        return false;
    }

    if (is_linked_list_empty(linked_list)) {
        return false;
    }

    Node *front_node_temp = linked_list->front;

    linked_list->front = linked_list->front->next;

    free(front_node_temp);

    linked_list->length--;

    return true;
}

bool remove_back(Linked_List *linked_list) {
    if (is_linked_list_null(linked_list)) {
        return false;
    }

    if (is_linked_list_empty(linked_list)) {
        return false;
    }

    Node *second_last_node_temp = linked_list->front;

    while (second_last_node_temp->next->next != NULL) {
        second_last_node_temp = second_last_node_temp->next;
    }

    free(second_last_node_temp->next);
    
    second_last_node_temp->next = NULL;
    linked_list->length--;

    return true;
}

void remove_all_nodes(Linked_List *linked_list) {
    if (is_linked_list_null(linked_list)) {
        return;
    }

    if (is_linked_list_empty(linked_list)) {
        return;
    }

    Node *nodeTemp = linked_list->front;
    Node *nodeToBeRemoved;

    while (nodeTemp != NULL) {
        nodeToBeRemoved = nodeTemp;
        nodeTemp = nodeTemp->next;  
        free(nodeToBeRemoved);
    }

    linked_list->front = NULL;
    linked_list->length = 0;
}


Node *search_by_key(Linked_List *linked_list, Key key) {
    if (is_linked_list_null(linked_list)) {
        return NULL;
    }

    if (is_linked_list_empty(linked_list)) {
        return NULL;
    }

    Node *nodeTemp = linked_list->front;

    while (nodeTemp != NULL) {
        if (nodeTemp->key == key) {
            return nodeTemp;
        }
        nodeTemp = nodeTemp->next;
    }

    return NULL;
}

bool is_linked_list_null(Linked_List *linked_list) {
    return linked_list == NULL;
}

bool is_linked_list_empty(Linked_List *linked_list) {
    if (is_linked_list_null(linked_list)) {
        puts("ERROR! `linked_list` parameter is NULL.");
        // TODO
    }

    return linked_list->front == NULL;
}
