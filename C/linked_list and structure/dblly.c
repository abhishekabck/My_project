/*
This File Only Contains Operations for Doublly Linked List
::Referenced Doble Linked Linked List
struct Dubll{
    struct Dubll* previous;
    int val;
    struct DUbll* next
};

::-->> Operations are as Follows<<--::
1. new()-> Create a Doublly Linked list and returns head location
2. In_beg(int val)-> used to Insert the val at the beginning of linked list
3. In_end(int val)-> Used to Insert the val at the end of linked list
4. Append(int val)-> Same as In_end(int val)
5. Display()
*/

# include <stdio.h>

struct dubll{
    struct dubll* previous;
    int val;
    struct dubll* next;
};

struct dubll* new(int val){
    struct dubll* new_node = (struct dubll*)malloc(sizeof(struct dubll));
    if (new_node == NULL){
        return NULL;
    }
    new_node->previous = new_node->next = NULL;
    new_node->val = val;
    return new_node;
}

struct dubll* insertAtBeg(struct dubll* head, int val){
    if (head == NULL){
        head = new(val);
        return head;
    }
    struct dubll* temp = head;
    while (temp->previous != NULL){
        temp = temp->previous;
    }
    struct dubll* nn = new(val);
    temp->previous = nn;
    nn->next = temp;
    return nn;
}

struct dubll* insertAtEnd(struct dubll* head, int val){
    if (head == NULL){
        return new(val);
    }
    else {
        struct dubll* temp = head;
        while (temp->next != NULL){
            temp = temp->next;
        }
        struct dubll* nn = new(val);
        temp->next = nn;
        nn->previous = temp;
        return head;
    }
}

void traverse_inOrder(struct dubll* head){
    struct dubll* temp = head;
    while (temp->previous != NULL){
        temp = temp->previous;
    }
    while(temp != NULL){
        printf("%d -> ", temp->val);
    }
    printf("NULL");
}

void traverse_reverse(struct dubll* head){
    struct dubll* temp = head;
    while (temp->next != NULL){
        temp = temp->next;
    }
    while (temp != NULL){
        printf("%d <- ", temp->val);
    }
    printf(NULL);
}

