#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>

int top = -1;
int _size = 0;
int* stack = NULL;

void Stack(int size) {
    stack = (int*)malloc(sizeof(int) * size);
    _size = size;
    top = -1;
}

int is_empty() {
    return top == -1;
}

int is_full() {
    return top == _size - 1;
}

void push(int value) {
    if (is_full()) {
        printf("Stack is full\n");
    } else {
        stack[++top] = value;
    }
}

int pop() {
    if (is_empty()) {
        printf("Stack is empty\n");
        return -1; // Or some other error value
    } else {
        return stack[top--];
    }
}

void display_stack() {
    if (is_empty()) {
        printf("Stack is empty\n");
    } else {
        printf("Stack: ");
        for (int i = 0; i <= top; i++) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

#endif // STACK_H
