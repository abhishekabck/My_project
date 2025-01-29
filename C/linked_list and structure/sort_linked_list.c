# include <stdio.h>
# include <stdlib.h>

// Defining the structure of the linked list
struct node{
    int data;
    struct node* next;
};

typedef struct node node;

node* CreateNode(int data) {
    node* newnode = (node*)malloc(sizeof(node));
    if (newnode == NULL){
        printf("Memory Allocation Failed..");
        exit(0);
    }
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

node* test1(){
    node* head = CreateNode(4);
    head->next = CreateNode(2);
    head->next->next = CreateNode(1);
    head->next->next->next = CreateNode(3);
    return head;
}

void SwapNodeValue(node* first, node* second){
    int temp = first->data;
    first->data = second->data;
    second->data = temp;
}

void BubbleSortLL(node* head){
    if (head == NULL || head->next == NULL){
        return;
    }
    node* temp = NULL;
    int swapped;
    do {
        swapped = 0;
        node* t1 = head;
        while (t1->next != temp) {
            node* t2 = t1->next;
            if (t1->data > t2->data){
                SwapNodeValue(t1, t2);
                swapped = 1;
            }
            t1 = t1->next;
        }
        temp = t1;
    }
    while (swapped);
}

void printLL(node* head){
    if (head == NULL) return;
    node* temp = head;
    while (temp!=NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }printf("NULL");
}


int main() {
    node* head = test1();
    printLL(head);
    printf("\n");
    BubbleSortLL(head);
    printLL(head);
    return 0;
}