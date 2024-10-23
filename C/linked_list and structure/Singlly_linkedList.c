#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct node {
    int data;
    struct node* next;
};

// Function used to raise error
void __raise__(const char* statement){
    fprintf(stderr, "Error: %s\n", statement);
    exit(1);
}

// Function to create an empty node
struct node* __emptyNode__() {
    struct node* emNode = (struct node*)malloc(sizeof(struct node));
    if (emNode == NULL) {
        __raise__("Memory Allocation Error");
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

// Function to count number of nodes in linked list
int length(struct node* head) {
    int length = 0;
    struct node* current = head;
    while (current != NULL) {
        length++;
        current = current->next;
    }
    return length;
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
        __raise__("Incorrect Position");
    }
    if (position == 1 || head == NULL) {
        return insertAtBeg(head, data);
    }
    
    struct node* current = head;
    while (current != NULL && position > 2) {
        current = current->next;
        position--;
    }

    if (current == NULL) {
        __raise__("Position exceeds list length");
    }

    struct node* newNode = __newNode__(data);
    newNode->next = current->next;
    current->next = newNode;
    return head;
}

// Function to insert new node after a specific value
struct node* insertAfter(struct node* head, int data, int valueBefore) {
    struct node* current = head;
    while (current != NULL && current->data != valueBefore) {
        current = current->next;
    }
    if (current == NULL) {
        __raise__("Value does not exist in the list");
    }
    struct node* newNode = __newNode__(data);
    newNode->next = current->next;
    current->next = newNode;
    return head;
}

// Delete Functions

// Function to delete last node
struct node* pop(struct node* head) {
    if (head == NULL) {
        __raise__("Linked List is Empty");
    }
    if (head->next == NULL) {
        free(head);
        return NULL;
    }
    struct node* current = head;
    while (current->next->next != NULL) {
        current = current->next;
    }
    free(current->next);
    current->next = NULL;
    return head;
}

// Function to delete node from beginning
struct node* deleteBeg(struct node* head) {
    if (head == NULL) {
        __raise__("Linked List is Empty");
    }
    struct node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

// Function to delete at any position
struct node* deleteAt(struct node* head, int position) {
    if (head == NULL) {
        __raise__("Linked List is Empty");
    }
    if (position < 1 || position > length(head)) {
        __raise__("Incorrect Position");
    }

    if (position == 1) {
        return deleteBeg(head);
    }

    struct node* current = head;
    while (position > 2 && current->next != NULL) {
        current = current->next;
        position--;
    }

    struct node* toDelete = current->next;
    current->next = toDelete->next;
    free(toDelete);
    return head;
}

// Function to delete first occurrence of given element
struct node* removeElement(struct node* head, int data) {
    if (head == NULL) {
        __raise__("Linked List is Empty");
    }
    if (head->data == data) {
        struct node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    struct node* current = head->next;
    struct node* previous = head;
    while (current != NULL && current->data != data) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        __raise__("Element Does not Exist");
    } else {
        previous->next = current->next;
        free(current);
    }
    return head;
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


// Reversing Linked list

int main() {
    struct node* head = NULL;
    head = insertAtBeg(head, 65);
    head = append(head, 24);
    head = append(head, 42);
    head = append(head, 56);
    head = insertAtBeg(head, 454);
    head = insert(head, 45, 2);
    head = insertAfter(head, 99, 24);  // Fixed integer value

    printList(head);
    printf("Length: %d\n", length(head));

    freeList(head);
    return 0;
}
