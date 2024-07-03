# include <stdio.h>
# include <stdlib.h>

struct node{
    int val;
    struct node *next;
};
struct node* create_node(){
    struct node* head = (struct node*)malloc(sizeof(struct node));
    printf("Enter 1 value of your node:-");
    scanf("%d",&head->val);
    head->next = head; // Connecting itself
    return head;
}

void append(struct node* head,int data){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp = head->next;
    while (temp->next != head){
        temp=temp->next;
    }
    struct node* temp1 = (struct node*)malloc(sizeof(struct node));
    temp1->val = data;
    temp1->next = head;
    temp->next = temp1;
}

void show(struct node* head){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp = head;
    do {
        printf("%d --> ",temp->val);
    }
    while (temp->next=head);
    printf("%d",head->val);
}


int main(){
    struct node* head;
    head = create_node();
    for (int i = 1;i<5;i++){
        int data;
        scanf("%d",&data);
        append(head,data);
    }
    printf("\nPrinting the data:-");
    show(head);
}