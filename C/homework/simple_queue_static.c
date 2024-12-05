# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# define maxSize 10 // Defining the maxSize as 10 (Globally)
int front = -1, Rear = -1;
int queue[maxSize];  // Defining queue of maxSize Globally

// Defining methods
bool IsEmpty(){
    if (front == -1 && Rear == -1)
        return true;
    return false;
}

bool IsFull(){
    if (Rear>=maxSize - 1)
        return true;
    return false;
}

void Enqueue(int data){
    if (IsFull()){
        printf("\nOverFlow %d", data);
    }else {
        if (front==-1 && Rear == -1){
            front = 0;
            Rear = 0;
            queue[Rear] = data;
        }else{
            Rear++;
            queue[Rear] = data;
        }
    }
}

int dequeue(){
    if (IsEmpty()){
        printf("\nUnderFlow");
        return -1;
    }else {
        int data;
        if (front == Rear){
            data = queue[front];
            front = -1;
            Rear = -1;
        }else {
            data = queue[front];
            front++;
        }
        return data;
    }
}

int GetFront(){
    if (IsEmpty()){
        printf("\nUnderflow");
    }else {
        return queue[front];
    }
}

int GetRear(){
    if (IsEmpty()){
        printf("\nUnderFlow");
    }else {
        return queue[Rear];
    }
}

int numberOfItems(){
    if (IsEmpty()){
        return 0;
    }else{
        return Rear - front + 1;
    }
}

void traverse(){
    printf("\n");
    for (int i = front; i <= Rear; i++){
        printf("%d ", queue[i]);
    }
}

int main(){
    Enqueue(5);
    Enqueue(234);
    Enqueue(63);
    Enqueue(235);
    Enqueue(5);
    Enqueue(234);
    Enqueue(63);
    Enqueue(235);
    Enqueue(5);
    Enqueue(234);
    Enqueue(63);
    Enqueue(235);
    printf("\nRear Element:- %d", GetRear());
    traverse();
    // for (int i = 0; i<10; i++)
    // printf("\n Element Removed:- %d", dequeue());
    printf("\nNumber of Items:- %d", numberOfItems());
    return 0;
}