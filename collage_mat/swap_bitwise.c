
 //Using Bitwise XOR

#include <stdio.h>

int main() {
int a = 10, b = 20;

printf("Before swapping: a = %d, b = %d\n", a, b);

// Swapping
a = a ^ b; // Step 1
b = a ^ b; // Step 2
a = a ^ b; // Step 3

printf("After swapping: a = %d, b = %d\n", a, b);

return 0;
}