# include <stdio.h>
# include <stdlib.h>
# define null NULL

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

struct node* ins_at_beg(struct node* ll,int data){
    //Insertes the value of data in main node if ll->data have Null value otherwise insertes a new node
    if (ll->data == NULL){
        ll->data = data;
        return ll;
    }
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = ll;
    return new_node;
}

void append(struct node* ll,int data){
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    if (ll == null){
        ll->data = data;
        ll->next = null;
    }
    else if (ll->next == NULL){
        ll->next = new_node;
        return;
    }
    while (ll->next != null){
        ll = ll->next;
    }
    ll->next = new_node;
}

void show(struct node* ll){
    if (ll->next == null){
        printf("%d --> null",ll->data);
        return;
    }
    struct node* temp = ll;
    while (temp->next){
        printf("%d --> ",temp->data);
        temp = temp->next;
    }
    printf("%d --> null",temp->data);
}

int main(){
    struct node* head = (struct node*)malloc(sizeof(struct node));
    head = create_ll();
    int N;
    scanf("%d",&N);
    for (int i = 0; i<N ;i++{
        if 
    })
}