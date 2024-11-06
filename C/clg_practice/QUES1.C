#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* NewNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory can't be allocated\n");
        exit(0);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int find_ef(struct node* head, int key) {
    struct node* temp = head;
    int count = 0;
    while (temp != NULL) {
        count += (temp->data == key) ? 1 : 0;
        temp = temp->next;
    }
    return (count == 0) ? -1 : count;
}

void traverse(struct node* head) {
    struct node* temp = head;
    while (temp != NULL) {
        printf("%d --> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

struct node* appendList(struct node* head1, struct node* head2) {
    // case 1: Both lists are empty
    if (head1 == NULL && head2 == NULL) {
        return NULL;
    }
    // case 2: Either List1 or List2 is empty
    if (head1 == NULL) {
        return head2;
    }
    if (head2 == NULL) {
        return head1;
    }
    // case 3: Both lists are non-empty
    struct node* temp = head1;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = head2;
    return head1;
}

void swap(struct node* a, struct node* b) {
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
    }
void bubbleSort(struct node* head) {
    int swapped;
    struct node* ptr1;
    struct node* lptr = NULL;
    // Checking for empty list
    if (head == NULL) return;
    do {
    swapped = 0;
    ptr1 = head;
    while (ptr1->next != lptr) {
    if (ptr1->data > ptr1->next->data) {
    swap(ptr1, ptr1->next);
    swapped = 1;
    }
    ptr1 = ptr1->next;
    }
    lptr = ptr1;
    }
    while (swapped);
}

struct node* traverse_circular(struct node* head){
    int count = 0;
    struct node* temp = head;
    while (temp != head) {
        printf("%d --> ", temp->data);
        temp = temp->next;
    }
    printf("head");
    printf("Total Number of Nodes are %d", count);
}

int main() {
    struct node* head = NULL;
    head = NewNode(24);
    head->next = NewNode(53);
    head->next->next = NewNode(53);
    head->next->next->next = NewNode(23);
    printf("List1 goes as:\n");
    traverse(head);

    // List 2
    struct node* head1 = NULL;
    head1 = NewNode(5);
    head1->next = NewNode(7-3);
    head1->next->next = NewNode(5+3);
    head1->next->next->next = NewNode(2*3);
    printf("List2 goes as:\n");
    traverse(head1);

    struct node* both = appendList(head, head1);
    printf("Combined list goes as:\n");
    traverse(both);
    bubbleSort(both);
    traverse(both);
    return 0;
}
