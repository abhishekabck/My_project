#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int data[MAX];
    int size;
} PriorityQueue;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void initializePriorityQueue(PriorityQueue *pq) {
    pq->size = 0;
}

void heapifyUp(PriorityQueue *pq, int index) {
    if (index && pq->data[(index - 1) / 2] > pq->data[index]) {
        swap(&pq->data[(index - 1) / 2], &pq->data[index]);
        heapifyUp(pq, (index - 1) / 2);
    }
}

void heapifyDown(PriorityQueue *pq, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < pq->size && pq->data[left] < pq->data[smallest]) {
        smallest = left;
    }

    if (right < pq->size && pq->data[right] < pq->data[smallest]) {
        smallest = right;
    }

    if (smallest != index) {
        swap(&pq->data[smallest], &pq->data[index]);
        heapifyDown(pq, smallest);
    }
}

void insert(PriorityQueue *pq, int element) {
    if (pq->size < MAX) {
        pq->data[pq->size] = element;
        heapifyUp(pq, pq->size);
        pq->size++;
    }
}

int extractMin(PriorityQueue *pq) {
    if (pq->size == 0) {
        return -1; // Priority queue is empty
    }
    int root = pq->data[0];
    pq->data[0] = pq->data[--pq->size];
    heapifyDown(pq, 0);
    return root;
}

bool deleteElement(PriorityQueue *pq, int element) {
    int index = -1;
    for (int i = 0; i < pq->size; i++) {
        if (pq->data[i] == element) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        return false; // Element not found
    }

    pq->data[index] = pq->data[--pq->size];
    heapifyDown(pq, index);
    return true;
}

#endif // PRIORITY_QUEUE_H
