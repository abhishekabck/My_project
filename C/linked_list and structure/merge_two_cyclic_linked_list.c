# include <stdio.h>
# include <stdlib.h>
# define null NULL

struct node{
    int val;
    struct node *next;
};

struct node* create_node(){
    struct node* head = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter 1 value of your Cyclic Linked List:-");
    scanf("%d",&head->val);
    head->next = head; // Connecting itself
    return head;
}

void show(struct node* head){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp = head;
    do {
        printf("%d --> ",temp->val);
        temp =  temp->next;
    }
    while (temp->next!=head);
    printf("%d -->NULL",temp->val);
}

struct node* maxll(struct node* head){
    if (head->next == head){
        return head;
    }
    struct node* max = head;
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp = head;
    while (temp->next != head){
        max = ((temp->val) > (max->val))?temp:max;
        temp = temp->next;
    }
    max = ((temp->val) > (max->val))?temp:max;
    return max;
}

void append(struct node* head,int data){
    if (head == null){
        head->val = data;
        head->next = head;
    }
    struct node* temp = head;
    while (temp->next != head){
        temp=temp->next;
    }
    struct node* temp1 = (struct node*)malloc(sizeof(struct node));
    temp1->val = data;
    temp1->next = head;
    temp->next = temp1;
}



int main(){
    struct node *cll1;
    append(cll1,56);
    show(cll1);
    return 0;
}