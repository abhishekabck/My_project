#ifndef CYCLIC_LINKEDLIST_H
#define CYCLIC_LINKEDLIST_H

struct node {
    int data;
    struct node* next;
};

struct CircularLList {
    struct node* head;
    struct node* tail;
    // Function pointers
    void (*append)(struct CircularLList*, int);
    void (*insertAtBeg)(struct CircularLList*, int);
    void (*traverse)(struct CircularLList*);
};

struct CircularLList* create_CLL();

#endif // CYCLIC_LINKEDLIST_H
