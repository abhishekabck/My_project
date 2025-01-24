#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>

int front = -1;
int rear = -1;
int _size = 0;
int* queue = NULL;

void Queue(int size) {
    queue = (int*)malloc(sizeof(int) * size);
    _size = size;
    front = 0;
    rear = 0;
}

int is_empty() {
    return front == rear;
}

int is_full() {
    return (rear + 1) % _size == front;
}

void enqueue(int value) {
    if (is_full()) {
        printf("Queue is full\n");
    } else {
        queue[rear] = value;
        rear = (rear + 1) % _size;
    }
}

int dequeue() {
    if (is_empty()) {
        printf("Queue is empty\n");
        return -1; // Or some other error value
    } else {
        int value = queue[front];
        front = (front + 1) % _size;
        return value;
    }
}

void display_queue() {
    if (is_empty()) {
        printf("Queue is empty\n");
    } else {
        int i = front;
        printf("Queue: ");
        while (i != rear) {
            printf("%d ", queue[i]);
            i = (i + 1) % _size;
        }
        printf("\n");
    }
}

#endif // QUEUE_H
