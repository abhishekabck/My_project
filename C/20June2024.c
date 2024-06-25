// Reverse a Queue using stack
# include <stdio.h>
# define size 100
int queue[size];
int stack[size];
int front = -1, rear = -1, top = -1;

void push(int data){
    if (top == size-1){
        printf("\nOverflow");
    }
    top++;
    stack[top]= data;
}

int pop(){
    if (top == -1){
        printf("\nUnderflow");
    }
    return stack[top--];
    
}

void enqueue(int x){
    if (rear == size-1){
        printf("Overflow\n");
    }
    else {
        rear++; // rear = 0
        queue[rear] = x;
        if (front == -1){
            front++;
        }
    }
}

void dequeue(){
    if (front == -1 && front>rear){
        printf("\nUnderflow");
        front = -1;
        rear = -1;
    }
    else {
    	int data = queue[front];
    	push(data);
        front++;
    }
}




int main(){
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(50);
    enqueue(52);
    enqueue(63);
    enqueue(78);
    printf("Transfer all elements of queue into stack\n");
    for (int i = front; i <= rear; i++){
        dequeue();
    }
    
    for (int i = top; i>=0; i--){
        enqueue(pop());
    }
    
    printf("Printing Elements of queue\n");
    for (int i = front; i <= rear; i++){
    	printf("%d\n",queue[i]);
	}

    return 0;
}