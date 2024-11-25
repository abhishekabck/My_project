#include <stdio.h>
#include <stdlib.h>
#include "cyclic_linkedList.h"

static struct node* __newNode__(int data) {
    struct node* otp = (struct node*)malloc(sizeof(struct node));
    if (otp == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    otp->data = data;
    otp->next = NULL;
    return otp;
}

static void traverse(struct CircularLList* list) {
    if (list->head == NULL) {
        printf("Linked list is empty\n");
        return;
    }
    struct node* temp = list->head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != list->head);
    printf("(back to head)\n");
}

static void insertAtBeg(struct CircularLList* list, int data) {
    struct node* newNode = __newNode__(data);
    if (list->head == NULL) {
        list->head = newNode;
        list->tail = newNode;
        newNode->next = newNode;
    } else {
        newNode->next = list->head;
        list->head = newNode;
        list->tail->next = newNode;
    }
}

static void append(struct CircularLList* list, int data) {
    struct node* newNode = __newNode__(data);
    if (list->tail == NULL) {
        list->head = newNode;
        list->tail = newNode;
        newNode->next = newNode;
    } else {
        list->tail->next = newNode;
        newNode->next = list->head;
        list->tail = newNode;
    }
}

struct CircularLList* create_CLL() {
    struct CircularLList* list = (struct CircularLList*)malloc(sizeof(struct CircularLList));
    if (list == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    list->head = NULL;w
    list->tail = NULL;
    list->append = append;
    list->insertAtBeg = insertAtBeg;
    list->traverse = traverse;
    return list;
}
