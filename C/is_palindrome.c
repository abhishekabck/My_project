# include <stdio.h>
# include <stdbool.h>

bool is_palindrome(int n){
    if (n < 0) return false;
    else if (n<10) return true;
    int num,x;
    x = n;
    while (n!=0){
        num = num*10 + n%10;
        n = n/10;
    }
    if (x == num) return true;
    return false;
}

int main() {
    int num;
    printf("Enter number:- ");
    scanf("%d", &num);
    if (is_palindrome(num)) printf("Palindrome..");
    else printf("Not Palindrome..");
    return 0;
}