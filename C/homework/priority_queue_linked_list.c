# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

/*Code of Priority Queue According to the priority
where the Higher Priority data remains at top and
lower Priority data remains as last element.
*/

// Defining the Node structure for priority Queue
struct Node{
    int data;
    int priority;
    struct Node* next;
};

// Defining the newnode function to generate newnode
struct Node* newnode(int data, int priority){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->priority = priority;
    temp->next = NULL;
    return temp;
}

// Defining Enqueue Function for insertion according to Priority
void enqueue(struct Node** front, int data, int priority){
    struct Node** temp = front;
    struct Node* temp2 = newnode(data, priority);
    // Checking is the front is NULL
    if ((*temp) == NULL || (*temp)->priority<=priority){
        temp2->next = *front;
        *front = temp2;
    }
}

int main(){
    struct Node* Queue = NULL;
    enqueue(&Queue, 53, 14);
    printf("\n%d", Queue->data);
    return 0;
}