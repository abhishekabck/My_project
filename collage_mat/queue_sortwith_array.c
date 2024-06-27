#include <stdio.h>
#define size 100

int queue[size];
int front = -1, rear = -1;

void enqueue(int data) {
    if (rear >= size - 1) {
        printf("Overflow\n");
        return;
    }
    if (front == -1) {
        front++;
    }
    rear++;
    queue[rear] = data;
}

int dequeue() {
    if (front == -1 || front > rear) {
        printf("Underflow\n");
        return -1;  // Return a value indicating the queue is empty
    } else {
        return queue[front++];
    }
}

int main() {
    int n, data;
    printf("Enter the number of elements you wish to enter: ");
    scanf("%d", &n);
    int arr[n];

    // Inserting the data into queue
    printf("Please enter the values to be sorted: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        enqueue(data);
    }

    // Retrieving values from queue
    for (int i = 0; i < n; i++) {
        arr[i] = dequeue();
    }

    // Bubble sort
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
    }

    // Enqueue the sorted elements back into the queue
    front = -1;
    rear = -1;
    for (int i = 0; i < n; i++) {
        enqueue(arr[i]);
    }

    // Traversing the queue
    printf("Your sorted elements are: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", dequeue());
    }
    printf("\n");

    return 0;
}
