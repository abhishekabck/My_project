# include <stdio.h>
# include <stdlib.h>

// Creating structure for Node
struct node{
    int data;
    struct node* next;
}

struct node* __newNode__(int data){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int main(){
    struct node* newNode1 = __newNode__(56);
    return 0;
}