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

struct dubll new(int val){
    struct dubll* new_node = (struct dubll*)malloc(sizeof(struct dubll));
    new_node->previous = new_node->next = NULL;
    new_node->val = val;
    return new_node;
}

void in_beg(struct dubll* head, int val){
    struct dubll* temp = head;
    while (temp->previous != NULL){
        temp->pervious = temp;
    }
    new(val)->next = temp->previous;
    return head;
}

int main(){
    struct dubll* head = new();
    in_beg
}