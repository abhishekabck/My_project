# include <stdio.h>
# include <stdlib.h>


struct node {
    int data;
    struct node* next;
};

void display(struct node* start){
    if (start == NULL){
        printf("Linked list is Empty");
    }
    else {
        do {
            printf("%d --> ",start->data);
            start = start->next;
        }
        while (start != NULL);
        printf("Null");
    }
}
/*
int main(){
    struct node* start = NULL;
    display(start);
    printf("\n");
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    start = newnode;
    newnode->data = 123;
    newnode->next = NULL;
    display(start);
    printf("\n");
    newnode = newnode->next = (struct node*)malloc(sizeof(struct node));
    newnode->data = 353;
    newnode->next = NULL;
    display(start);
    printf("\n");
    return 0;
}

*/


int main(){
    // struct node* start = NULL, *newnode;
    // int choice = 1;
    // start = newnode;
    // while (choice){
    //     newnode = (struct node*)malloc(sizeof(struct node));
    //     printf("\n Enter Your data:-");
    //     scanf("%d",&newnode->data);
    //     newnode->next = NULL;
    //     printf("Do you wish to Create Node:-(1,0)");
    //     scanf("%d",&choice);
    //     if (choice){
    //         newnode = newnode->next = (struct node*)malloc(sizeof(struct node));
    //     }
    // }
    // display(start);
    struct node* start = 0, *newnode,*temp,*temp1;
    temp = (struct node*)malloc(sizeof(struct node));
    int choice;
    while (choice){
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("\nEnter the data:- ");
        scanf("%d",&newnode->data);
        if (start == 0){
            start = newnode = temp;
        }
        else {
            temp->next = newnode;
            temp = newnode;
        }
        printf("Do You wish to create new node- (0,1)? ::");
        scanf("%d",&choice);
    }
    temp1 = start;
    while (temp1!=0){
        printf("%d -> ",temp1->data);
        temp1 = temp1->next;
    }
    return 0;
}
