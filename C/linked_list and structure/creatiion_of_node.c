# include <stdio.h>
# include <stdlib.h>

struct node{
    int val;
    struct node* next;
};



int main(){
    struct node* start;
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    int flag = 1;
    temp->next = NULL;
    int choice = 1;
    while (choice){
        struct node* newNode = (struct node*)malloc(sizeof(struct node));
        printf("\nEnter Value:- ");
        scanf("%d",&newNode->val);
        temp->next = newNode;
        temp = newNode;
        if (flag){
            start = newNode;
            flag = 0;
        }
        printf("Do you wish to enter new node:- ");
        scanf("%d",&choice);
    }
    temp = start;
    while (temp->next != NULL){
        printf("%d -> ",temp->val);
        temp = temp->next;
    }
    return 0;
}
