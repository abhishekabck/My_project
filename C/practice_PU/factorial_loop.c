# include <stdio.h>

int main(){
    int num;
    printf("Enter your Number:- ");
    scanf("%d",&num);
    unsigned long fact = 1;
    while (num>=1){
        fact *= num;
        num--;
    }
    printf("Factorial :- %lu",fact);
}