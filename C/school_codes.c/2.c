// Sum and average of n Natural Numbers.

# include <stdio.h>

int main() {
    int temp,n,i,sum = 0;
    printf("Enter number of numbers you wish to enter:-");
    scanf("%d",&n);
    for (i;i<n;++i) {
        printf("Enter number %d :-",i+1);
        scanf("%d",&temp);
        sum += temp;
    }
    printf("\nSum of n numbers:-%d",sum);
    printf("\nAverage of n numbers:- %.2f",(float)sum/n);
    return 0;
}