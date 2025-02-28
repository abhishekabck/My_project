#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

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

// Function to get precedence of operators
int getPrecedence(char x) {
    if (x == '(' || x == ')') {
        return 4;
    } else if (x == '^') {
        return 3;
    } else if (x == '*' || x == '/') {
        return 2;
    } else if (x == '+' || x == '-') {
        return 1;
    }
    return 0;
}

// Function to check if a character is an operator
int isOperator(char x) {
    return (x == '+' || x == '-' || x == '*' || x == '/' || x == '^' || x == '(' || x == ')');
}

// Function to convert infix expression to postfix
char* infixToPostfix(const char* expression) {
    int expLength = strlen(expression);
    char* result = (char*)malloc(expLength + 1);
    struct Node* operatorStack = createStack();
    int j = 0;

    for (int i = 0; i < expLength; i++) {
        char currentChar = expression[i];

        // If operand, add to result
        if (!isOperator(currentChar)) {
            result[j++] = currentChar;
        } 
        // If opening bracket, push to stack
        else if (currentChar == '(') {
            push(&operatorStack, currentChar);
        } 
        // If closing bracket, pop till '('
        else if (currentChar == ')') {
            while (!isEmpty(operatorStack) && peek(operatorStack) != '(') {
                result[j++] = pop(&operatorStack);
            }
            pop(&operatorStack); // Remove '('
        } 
        // Operator case
        else {
            while (!isEmpty(operatorStack) && getPrecedence(peek(operatorStack)) >= getPrecedence(currentChar)) {
                result[j++] = pop(&operatorStack);
            }
            push(&operatorStack, currentChar);
        }
    }

    // Pop remaining operators
    while (!isEmpty(operatorStack)) {
        result[j++] = pop(&operatorStack);
    }
    
    result[j] = '\0'; // Null-terminate string
    return result;
}

int main() {
    char expression[] = "A+B*C";  // Use double quotes for string literals
    char* result = infixToPostfix(expression);
    printf("Postfix Expression: %s\n", result);
    free(result);  // Free allocated memory
    return 0;
}
