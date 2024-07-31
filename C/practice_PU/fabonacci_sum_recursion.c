# include <stdio.h>

int fibonacci(int n){
    if (n == 0 || n == 1)
        return n;
    return fibonacci(n - 1) + fibonacci(n-2);
}
int fibonacci_sum(int terms){
    if (terms == 0 || terms == 1) {
        return terms;
    }
    return fibonacci(terms) + fibonacci_sum(terms - 1);
}

int main() {
    int num;
    printf("Enter number:- ");
    scanf("%d",&num);
    printf("Fibonacci Sum:- %d",fibonacci_sum(num));
    return 0;
}