# include <stdio.h>

int fibonacci(int n){
    if (n == 0 || n == 1)
        return n;
    return fibonacci(n - 1) + fibonacci(n-2);
}

int main() {
    int num;
    printf("Enter number:- ");
    scanf("%d",&num);
    printf("%d",fibonacci(num));
}