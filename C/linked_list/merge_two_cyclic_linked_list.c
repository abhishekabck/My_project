# include <stdio.h>
# include <stdlib.h>


struct node{
    int val;
    struct node *next;
};

struct node* create_node(){
    struct node* head = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter 1 value of your node:-");
    scanf("%d",&head->val);
    head->next = head; // Connecting itself
    return head;
}

void append(struct node* head,int data){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp = head->next;
    while (temp->next != head){
        temp->val = data;
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
        temp =  temp->next;
    }
    while (temp->next!=head);
    printf("%d -> Null",head->val);
}

int max(struct node* head){
    if (head->next = head){
        return head->val;
    }
    int max = INT_MIN;
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    while (temp->next != head){
        max = (temp->val>max)?temp->val:max;
        temp = temp->next;
    }
    max = (temp->val > max)?(temp->val):max;
    return max;
}

int main(){
    struct node *cll1,*cll2;
    int data;
    printf("\nInsert Values in First Cyclic Linked List:-");
    cll1 = create_node(); // First Cyclic Linked List
    // Inserting Values in First Cyclic Linked List 
    for (int i = 1; i<5; i++){
        printf("\nEnter the %d value of your Cyclic Linked list:- ",i+1);
        scanf("%d",&data);
        append(cll1,data);
    }
    printf("\nInsert Values in Second Cyclic Linked List:- ");
    cll2 = create_node(); // Second Cyclic Linked List
    // Inserting Vlaues in Second Cyclic Linked List  
    for (int i = 1; i<5; i++){
        printf("\nEnter the %d value of your Cyclic Linked list:- ",i+1);
        scanf("%d",&data);
        append(cll2,data);
    }

    //Max of cll1
    int max1,max2;
    max1 = max(cll1);
    max2 = max(cll2);
    printf("Max Element of First cyclic LInked list:- %d\nMax Element of Second cyclic LInked list:-%d",max1,max2);
    show(cll1);
    printf("\n");
    show(cll2);
    return 0;

}