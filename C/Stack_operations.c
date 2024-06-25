#include <stdio.h>
#include <stdlib.h>

# define size 5
int stack[size], top = -1;

// Function Prototypes
void push();
void pull();
void traverse();
void peek();

void push() {
    if (top == size - 1) {
        printf("\nOverflow of elements.");
        return;
    }
    int element;
    top++;
    printf("\nEnter The Element you wish to enter in stack:-");
    scanf("%d", &element);
    stack[top] = element;
    printf("\nElement Insertion Successful");
}

void pull() {
    if (top == -1) {
        printf("\nUnderflow..");
        return;
    }
    top--;
    printf("\nOperation Successful");
}

void traverse() {
    if (top == -1) {
        printf("\nStack is empty.");
        printf("\nPlease add elements in stack.");
        return;
    }
    int i;
    printf("\n Stack Elements are:-");
    for (i = top; i >= 0; i--) {
        printf("%d, ", stack[i]);
    }
}

void peek() {
    if (top == -1) {
        printf("\nStack is Empty:- ");
        return;
    }
    printf("\nTop Elements of stack :- %d", stack[top]);
}

int main() {
    int choice;
    char ch;
    do {
        printf("\nStack Operations:- ");
        printf("\n1. Push..  \n2. Pull.. \n3. Traverse.. \n4. Peek \n5. Exit\n");
        printf("Enter your choice-->");
        scanf("%d", &choice);
        switch (choice) {
            case 1: push(); break;
            case 2: pull(); break;
            case 3: traverse(); break;
            case 4: peek(); break;
            case 5: exit(0);
            default: printf("\nInvalid choice. Please try again.");
        }

        printf("\nDo you wish to perform actions again (y/n)? ");
        fflush(stdin);
        scanf(" %c", &ch);
        fflush(stdin);
    } while (ch == 'y' || ch == 'Y');
    return 0;
}
