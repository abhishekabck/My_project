# include <stdio.h>
# include <stdlib.h>

struct node{
    int val;
    struct node *next; //8-bytes
};

struct node* createll(int n){
    if (n<1){
        printf("N should be atleast 1");
        return NULL;
    }
    struct node* head = (struct node*)malloc(sizeof(struct node));
    printf("Enter val of 1 node =");
    scanf("%d",&head->val);
    struct node*temp = head;
    for (int i = 2; i<=n; i++){
        struct node*nextnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter val of %d node = ",i);
        scanf("%d",&nextnode -> val);
        temp->next = nextnode;
        temp = nextnode;
    }
    temp->next = NULL;
    return head;
}

struct node* insert(struct node* head,int data, int index){
    if (index == 0){
        struct node* temp = (struct node*)malloc(sizeof(struct node));
        temp->val = data;
        temp->next = head;
        return temp;
    }
    int count = 0, flag = 0;
    struct node *temp = head;
    while (temp){
        if (count == index-1){
            flag = 1;
            struct node* newnode = (struct node*)malloc(sizeof(struct node));
            newnode->val = data;
            newnode->next = temp->next;
            temp->next = newnode;
            break;
        }
        temp = temp->next;
        count++;
    }
    if (flag == 0){
        printf("\nDue to index being Out of range->> Value insertion at end is executed..");
        struct node* newnode = (struct node*)malloc(sizeof(struct node));
        newnode->val = data;
        temp->next = newnode;
        newnode->next = NULL;
    }
    return head;
    
}

void show(struct node* head){
    while (head->next){
        printf("%d ->",head->val);
        head = head->next;
    }
    printf("%d ",head->val);
    
}



int main(){
    int n;
    printf("\nEnter no of nodes you wish to create:- ");
    scanf("%d",&n);
    struct node* head = createll(n);
    printf("\nShowing your Linked List:- ");
    show(head);
    printf("\nInsertiong position:-");
    int pos;
    scanf("%d",&pos);
    head = insert(head,6,pos);
    show(head);
    
}