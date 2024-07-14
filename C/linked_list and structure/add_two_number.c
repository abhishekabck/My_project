# include <stdio.h>
# include <stdlib.h>
# define null NULL

struct node{
    int val;
    struct node* next;
};

struct node* create_ll(){
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->val = NULL;
    new_node->next = NULL;
    return new_node;
}

void append(struct node* ll,int val){
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->val = val;
    new_node->next = NULL;
    if (ll == null){
        ll->val = val;
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

struct node* addTwoNumbers(struct node* l1, struct node* l2) {
    struct node* l3 = (struct node*)malloc(sizeof(struct node));
    struct node* temp = l3;
    while (l1 != NULL || l2 != NULL){
        int rem = 0;
        if (l1 == NULL){
            temp->val = (l2->val + rem)%10;
            rem = (l2->val + rem)/10;
            l2 = l2->next;
        }
        else if (l2 == NULL){
            temp->val = (l1->val + rem)%10;
            rem = (l1->val + rem)/10;
            l1 = l1->next;
        }
        else {
            temp->val = (l1->val + l2->val + rem)%10;
            rem = (l1->val + l2->val + rem)/10;
            l1 = l1->next;
            l2 = l2->next;
        }
        temp = temp->next = (struct node*)malloc(sizeof(struct node));

    }
    temp = null;
    return l3;
}

void display(struct node* start){
    if (start == NULL){
        printf("Linked list is Empty");
    }
    else {
        do {
            printf("%d --> ",start->val);
            start = start->next;
        }
        while (start != NULL);
        printf("Null");
    }
}

int main(){
    struct node* l1 = create_ll();
    struct node* l2 = create_ll();
    int a1[3] = {2,4,3};
    int a2[3] = {5,6,4};
    for (int i = 0; i<3; i++){
        append(l1,a1[i]);
    }
    for (int i = 0; i<3; i++){
        append(l2,a2[i]);
    }
    struct node* l3 = addTwoNumbers(l1,l2);
    display(l1);
    display(l2);
    display(l3);
    return 0;
}