# include <stdio.h>
# include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

int main(){
    struct node* head = (struct node*)malloc(sizeof(struct node));
    head->next = (struct node*)malloc(sizeof(struct node));
    head->data = 45;
    head->next->data = 432;
    head->next->next = NULL;
    do{
        printf("%d ",head->data);
    }
    while ((head = head->next) != NULL);
    return 0;
}