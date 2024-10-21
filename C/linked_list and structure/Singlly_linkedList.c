#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct node {
    int data;
    struct node* next;
};

// Function to create an empty node
struct node* __emptyNode__() {
    struct node* emNode = (struct node*)malloc(sizeof(struct node));
    if (emNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    emNode->data = 0;
    emNode->next = NULL;
    return emNode;
}

// Function to create a new node with given data
struct node* __newNode__(int data) {
    struct node* newNode = __emptyNode__();
    newNode->data = data;
    return newNode;
}

// Function to append a node at the end of the list
struct node* append(struct node* head, int data) {
    struct node* newNode = __newNode__(data);

    if (head == NULL) {
        return newNode;
    }

    struct node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;

    return head;
}

// Function to insert a node at the beginning
struct node* insertAtBeg(struct node* head, int data) {
    struct node* newNode = __newNode__(data);
    newNode->next = head;
    return newNode;
}

// Function to insert at a desired position
struct node* insert(struct node* head, int data, int position) {
    if (position < 1) {
        printf("Incorrect Position %d\n", position);
        exit(1);
    } else if (position == 1 || head == NULL) {
        return insertAtBeg(head, data);
    } else {
        struct node* current = head;
        struct node* previous = NULL;
        while (current != NULL && position > 1) {
            previous = current;
            current = current->next;
            position--;
        }
        struct node* newNode = __newNode__(data);
        previous->next = newNode;
        newNode->next = current;
        return head;
    }
}

// Function to insert new node after a specific value
void insertAfter(struct node* head, int data, int valueBefore) {
    if (head == NULL) {
        return;
    }
    struct node* current = head;
    while (current != NULL && current->data != valueBefore) {
        current = current->next;
    }
    if (current == NULL) {
        // Value does not exist
        return;
    }
    struct node* newNode = __newNode__(data);
    newNode->next = current->next;
    current->next = newNode;
}

// Function to print the list
void printList(struct node* head) {
    struct node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Function to free the list
void freeList(struct node* head) {
    struct node* current = head;
    struct node* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

int main() {
    struct node* head = NULL;

    head = append(head, 24);
    head = append(head, 42);
    head = append(head, 56);
    head = insertAtBeg(head, 454);
    head = insert(head, 45, 2);
    insertAfter(head, 'g', 24);  // Example for insertAfter

    printList(head);

    // Free the allocated memory
    freeList(head);

    return 0;
}
