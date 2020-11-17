#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void insertFirst(Node** head, int data) {
    // Allocate memory to a node
     Node* newNode = (Node*)malloc(sizeof(Node));

    // insert the data
    newNode->data = data;
    newNode->next = (*head);

    // Move head to new node
    (*head) = newNode;
}

// Insert a node after a node
void insertAfter(Node* node, int data) {
    if (node == NULL) {
        printf("Impossible. Cannot add after an inexistant Node.");
        return;
    }

    Node* newNode = ( Node*)malloc(sizeof( Node));
    newNode->data = data;
    newNode->next = node->next;
    node->next = newNode;
}

void insertEnd(Node** head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    Node* last = *head;

    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    while (last->next != NULL)
        last = last->next;

    last->next = newNode;
    return;
}
