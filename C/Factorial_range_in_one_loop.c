# include <stdio.h>

int main() {
    int num,fact = 1,i = 1;
    char choice;
    printf("Enter the number whose Factorial You wish to print:- ");
    scanf("%d",&num);
    do {
        fact *= i++;
        if (i == num+1){
            printf("\nFactorial of %d is %d.",num,fact);
            fact = 1,i = 1;
            choice = 'n';
            printf("\nTo Find Another Factorial Enter: Y/y -->>:- ");
            fflush(stdin);
            scanf("%c",&choice);
            if (choice == 'y'|| choice == 'Y') {
                printf("\nEnter the number whose Factorial you wish to print:- ");
                scanf("%d",&num);
            }
            else {
                printf("Wrong Choice");
            }
        }
    }
    while (1);
}