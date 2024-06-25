/*
To swap two numbers in C without using a third variable, you can use arithmetic
operations (like addition and subtraction) or bitwise XOR. Here's how you can do it
using both methods:
*/

//           Using Arithmetic Operations**

#include <stdio.h>

int main() {
int a = 10, b = 20;

printf("Before swapping: a = %d, b = %d\n", a, b);

// Swapping
a = a + b; // a now becomes 30
b = a - b; // b becomes 10
a = a - b; // a becomes 20

printf("After swapping: a = %d, b = %d\n", a, b);

return 0;
}

