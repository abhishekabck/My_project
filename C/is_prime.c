# include <stdio.h>
# include <math.h>
# include <stdlib.h>

int main(){
    int num;
    printf("Enter Your number:- ");
    scanf("%d",&num);
    if (num<2) {
        printf("Not Prime..");
        exit(0);
    }
    for (int i = 2; i<=sqrt(num); i++){
        if (num%i == 0) {
            printf("NOt Prime..");
            exit(0);
        }
    }
    printf("Prime No..");
    return(0);
}