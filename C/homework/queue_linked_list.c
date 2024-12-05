# include <stdio.h>
# include <stdlib.h>

// defining Node Structure
struct Node{
    int data;
    struct Node* next;
}

struct Queue{
    struct Node* front;
    struct Node* rear;
    int length;
    void (*enqueue)(struct Queue*, int);
    void (*dequeue)(struct Queue*);
    void (*IsEmpty)(struct Queue*);
    void (*IsFull)(struct Queue*);
    void ()

}

struct no