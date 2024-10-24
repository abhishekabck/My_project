# include <stdio.h>
# include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct CircularLList{
    struct node* head;
    struct node* tail;

    //  Function pointers
    void (*append)(struct CircularLList*, int);
    void (*insertAtBeg)(struct CircularLList*, int);
    void (*traverse)(struct CircularLList*);

};



struct node* __newNode__(int data){
    struct node* otp = (struct node*)malloc(sizeof(struct node));
    otp->data = data;
    otp->next = NULL;
    return otp;
}


void traverse(struct CircularLList* list) {
    if (list->head == NULL) {
        printf("Linked list is empty\n");
        return;
    }
    struct node* temp = list->head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != list->head);
    printf("(back to head)\n");
}

void insertAtBeg(struct CircularLList* list, int data) {
    struct node* newNode = __newNode__(data);
    if (list->head == NULL) {
        list->head = newNode;
        list->tail = newNode;
        newNode->next = newNode; // Point to itself
    } else {
        newNode->next = list->head;
        list->head = newNode;
        list->tail->next = list->head; // Update the tail's next
    }
}

void append(struct CircularLList* list, int data) {
    struct node* newNode = __newNode__(data);
    if (list->tail == NULL) {
        list->head = newNode;
        list->tail = newNode;
        newNode->next = newNode; // Point to itself
    } else {
        list->tail->next = newNode;
        newNode->next = list->head; // Point to head
        list->tail = newNode; // Update tail
    }
}


struct CircularLList* create_CLL() {
    struct CircularLList* list = (struct CircularLList*)malloc(sizeof(struct CircularLList));
    list->head = NULL;
    list->tail = NULL;
    list->append = append;
    list->insertAtBeg = insertAtBeg;
    list->traverse = traverse;
    return list;
}

// int main(){
//     // Initialize
//     struct node* head = NULL;
//     struct node* tail = NULL;
//     append(&head, &tail, 235);
//     append(&head, &tail, 452);
//     append(&head, &tail, 453);
//     insertAtBeg(&head, &tail, 4523);
//     append(&head, &tail, 435);
//     append(&head, &tail, 523);
//     insertAtBeg(&head, &tail, 9712);
//     traverse(head);
//     return 0;
// }

int main() {
    // Create circular linked list
    struct CircularLList* list = create_CLL();
    
    // Use the methods
    list->append(list, 235);
    list->append(list, 452);
    list->insertAtBeg(list, 9712);
    list->append(list, 453);
    list->insertAtBeg(list, 4523);
    list->traverse(list);
    
    // Free memory (optional, but recommended for larger programs)
    free(list); // Add proper memory management for nodes if necessary
    
    return 0;
}