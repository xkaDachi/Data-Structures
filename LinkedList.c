#include <stdio.h>
#include <stdlib.h>

//Node Structure Definition
typedef struct Node {
    int data;
    struct Node* next;
} Node;

//--------------------------------------------------

/*
*                   -----------------
*                   |   P R I N T   |
*                   -----------------
*/

//Print the List
void printList(Node* head) {
    if (head == NULL){
        printf("List is Empty.");
        return;
    }
    while (head != NULL) {
        printf("%d --> ", head->data);
        head = head->next;
    }
    printf("\n");
}

//Print the List in reverse order
void printReverse(Node* head) 
{ 
    // Base case   
    if (head == NULL) {
        //printf("List is Empty.");
        return; 
    } else {  
    printReverse(head->next); 
    printf("%d --> ", head->data); 
    }
}

//--------------------------------------------------

/*
*                   -----------------
*                   |  I N S E R T  |
*                   -----------------
*/

//Insert a Node at start of the List
void insertFirst(Node** head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

//Insert a Node after another Node
void insertAfter(Node* node, int data) {
    if (node == NULL) {
        printf("Impossible. Cannot add after an inexistant Node.");
        return;
    }
    Node* newNode = (Node*)malloc(sizeof( Node));
    newNode->data = data;
    newNode->next = node->next;
    node->next = newNode;
}

//Insert a Node at the end of the List
void insertEnd(Node** head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    Node* last = *head;
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    while (last->next != NULL){
        last = last->next;
    }
    
    last->next = newNode;
    return;
}

//--------------------------------------------------

/*
*                   -----------------
*                   |  R E M O V E  |
*                   -----------------
*/

//Remove the first Node of the List, and returns its data
int removeFirst(Node** head){
    int returnData = -1;
    Node* nextNode = NULL;
    
    if (*head == NULL){
        return -1;
    }
    
    nextNode = (*head)->next;
    returnData = (*head)->data;
    free(*head);
    (*head) = nextNode;
    
    return returnData;
}

//Remove the first Node occurence of the List with input data
void removeNode(Node** head, int data) {
    Node* temp = *head; 
    Node* prev;

    if (temp != NULL && temp->data == data) {
        *head = temp->next;
        free(temp);
        return;
    }
    
    while (temp != NULL && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) 
        return;
  
    prev->next = temp->next;
    free(temp);
}

//Remove the last Node of the List, nd returns its data
int removeLast(Node* head){
    int returnData = -1;
    
    if(head->next == NULL){
        returnData = head->data;
        free(head);
        return returnData;
    }
    
    Node* current = head;
    while (current->next->next != NULL){
        current = current->next;
    }
    
    returnData = current->next->data;
    free(current->next);
    current->next = NULL;
    return returnData;
}

//Clear the contents of the List
void clearList(Node** head){
    Node* current = *head;
    Node* next;
    
    while(current != NULL){
        next = current->next;
        free(current);
        current = next;
    }
    *head = NULL;
}

//--------------------------------------------------

/*
*                   -----------------
*                   |    M I S C.   |
*                   -----------------
*/

//Get the Length of the List
int getLength(Node* head){
    int length = 0;
    Node* current = head;
    while (current != NULL){
        length++;
        current = current->next;
    }
    return length;
}

//Finds if List contains input data
bool contains(Node* head, int data){
    Node* current = head;
    while (current != NULL) 
    { 
        if (current->data == data)
            return true; 
        current = current->next; 
    } 
    return false;
}

//Returns the data of the Node at index
int getNode(Node* head, int index){

    Node* current = head;
 
    int count = 0;
    while (current != NULL) {
        if (count == index)
            return (current->data);
        count++;
        current = current->next;
    }
    return -1;
}

//Reverse the contents of the List
void reverse(Node** head){
    Node* prev = NULL;
    Node* current = *head;
    Node* next = NULL;
    while (current != NULL) {
        // Store next
        next = current->next;
        
        current->next = prev;
 
        prev = current;
        current = next;
    }
    *head = prev;
}

//Removes Nodes in the Odd Indexes from the List
void deleteOdd(Node *head) 
{ 
    if (head == NULL) 
        return; 
  
    Node* prev = head; 
    Node* node = head->next; 
  
    while (prev != NULL && node != NULL) { 
        prev->next = node->next; 
  
        free(node); 
        
        prev = prev->next; 
        if (prev != NULL) 
            node = prev->next; 
    } 
} 

//Checks if two Lists are identical
int compareList(Node* a, Node* b) 
{ 
    while (a != NULL && b != NULL) 
    { 
        if (a->data != b->data) 
            return -1; 
        
        a = a->next; 
        b = b->next; 
    } 
    return 1; 
} 

//Returns the middle Node of the List
int getMiddle(Node* head) { 
    Node *slowPointer = head; 
    Node *fastPointer = head; 
 
    if (head != NULL) 
    { 
        while (fastPointer != NULL && fastPointer->next != NULL) 
        { 
            fastPointer = fastPointer->next->next; 
            slowPointer = slowPointer->next; 
        } 
        return slowPointer->data; 
    }
}

//Returns the number of occurence of a data in a List
int count(Node* head, int data) { 
    Node* current = head; 
    int count = 0; 
    while (current != NULL) { 
        if (current->data == data) 
            count++; 
        current = current->next; 
    } 
    return count; 
}
