/*
C program that calculates both the sum and the difference of two integers entered by the
user:
*/

#include <stdio.h>

int main() {
int num1, num2, sum, difference;

// Prompt the user to enter the first number
printf("Enter the first number: ");
scanf("%d", &num1);

// Prompt the user to enter the second number
printf("Enter the second number: ");

scanf("%d", &num2);

// Calculate sum
sum = num1 + num2;

// Calculate difference
difference = num1 - num2;

// Display the results
printf("Sum: %d\n", sum);
printf("Difference: %d\n", difference);

return 0;
}