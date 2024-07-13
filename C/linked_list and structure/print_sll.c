#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* create_ll(){
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = NULL;
    new_node->next = NULL;
    return new_node;
}

