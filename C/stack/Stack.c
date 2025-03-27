# include <stdio.h>
# include <stdlib.h>

struct Node {
    char data;
    struct Node* next;
};

// Function to create a new stack
struct Node* createStack() {
    return NULL; // Empty stack
}

// Push function
void push(struct Node** top, char x) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = *top;
    *top = temp; // Update the top pointer
}

// Pop function
char pop(struct Node** top) {
    if (*top == NULL) {
        printf("Stack Underflow\n");
        return '\0';
    }
    struct Node* temp = *top;
    char val = temp->data;
    *top = (*top)->next;
    free(temp);
    return val;
}

// Peek function
char peek(struct Node* top) {
    return (top != NULL) ? top->data : '\0';
}

// Check if stack is empty
int isEmpty(struct Node* top) {
    return (top == NULL);
}