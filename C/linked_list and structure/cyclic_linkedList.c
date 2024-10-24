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

void insertAtBeg(struct node** head, int data){
    struct node* t1 = __newNode__(data);
    if (*head == NULL){
        *head = t1;
        t1->next = t1;
        return;
    }
    else if ((*head)->next == *head){
        t1->next = *head;
        (*head)->next = t1;
        *head = t1;
    }
    else {
        struct node* temp = *head;
        while (temp->next!=*head){
            temp = temp->next;
        }
        temp->next = t1;
        t1->next = *head;
        *head = t1;
    }
}

void 

int main(){
    // Initialize
    struct node* head = NULL;
    insertAtBeg(&head, 235);
    insertAtBeg(&head, 452);
    insertAtBeg(&head, 453);
    insertAtBeg(&head, 4523);
    insertAtBeg(&head, 435);
    insertAtBeg(&head, 523);
    traverse(head);
    return 0;
}