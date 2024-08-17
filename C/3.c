// 3.	Factorial of a Number.

# include <stdio.h>

int main() {
    int num;
    printf("Enter number:-");
    scanf("%d",&num);
    long long int fact = 1;
    while (num>=1) {
        fact = fact * num;
        --num;
    }
    printf("Factorial:-%lld",fact);
    return(0);
}