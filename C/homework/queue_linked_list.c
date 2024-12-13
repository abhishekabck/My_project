# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

// defining Node Structure
struct Node{
    int data;
    struct Node* next;
};

struct Node* newnode(){
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    if (node == NULL){
        return NULL;
    }
    node->next = NULL;
    return node;
};

struct Queue{
    struct Node* front;
    struct Node* rear;
    int length;
    void (*enqueue)(struct Queue*, int);
    void (*dequeue)(struct Queue*);
    bool (*IsEmpty)(struct Queue*);
    bool (*IsFull)(struct Queue*);
    void (*traverse)(struct Queue*);
    void (*GetFront)(struct Queue*);
    void (*GetRear)(struct Queue*);
};

bool IsEmpty(struct Queue* q){
    // return (q.length == 0);
    return q->front == NULL;
}

bool IsFull(struct Queue* q){
    struct Node* node = newnode();
    if (node == NULL){
        return true;
    }
    free(node);
    return false;
}

void enqueue(struct Queue* q, int data){
    if (q->IsFull(q)){
        printf("\nOverflow");
    }else {
        struct Node* node = newnode();
        node->data = data;
        if (q->front == NULL){
            q->front = q->rear = node;
        }else {
            q->rear->next = node;
            q->rear = node;
        }
        q->length++;
    }
}

void dequeue(struct Queue* q){
    if (q->IsEmpty(q)){
        printf("UnderFlow");
        return;
    }else {
        struct Node* temp = q->front;
        q->front = q->front->next;
        if (q->front == NULL){
            q->rear = NULL;
        }
        q->length--;
        free(temp);
    }
}

void traverse(struct Queue* q){
    struct Node* temp = q->front;
    while (temp != NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
}

int getFront(struct Queue* q){
    // Checking whether the q is empty or not
    if (q->front == NULL){
        return -1;
    }else {
        return q->front->data;
    }
}

int getRear(struct Queue* q){
    if (q->rear == NULL){
        return -1;
    }else {
        return q->rear->data;
    }
}

// Defining the functions for constructor
struct Queue* create_D_queue(){
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = NULL;
    queue->rear = NULL;
    queue->length = 0;
    queue->traverse = traverse;
    queue->enqueue = enqueue;
    queue->dequeue = dequeue;
    queue->IsEmpty = IsEmpty;
    queue->IsFull = IsFull;
    return queue;
};

int main(){
    struct Queue* q = create_D_queue();
    q->enqueue(q, 53);
    q->enqueue(q, 23);
    q->enqueue(q, 64);
    q->enqueue(q, 34);
    q->traverse(q);
    return 0;
}