# include <stdio.h>
# include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* __newNode__(int data){
    struct node* otp = (struct node*)malloc(sizeof(struct node));
    otp->data = data;
    otp->next = NULL;
    return otp;
}

struct node* last(struct node* head){
    if (head == NULL){
        return NULL;
    }
    struct node* temp = head;
    while (temp->next != head){
        temp = temp->next;
    }
    return temp;
}


void traverse(struct node* head){
    if (head == NULL){
        printf("Linked is EMpty");
        return;
    }
    struct node* temp = head;
    while (temp->next != head){
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("%d",temp->data);
}