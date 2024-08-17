// Fibonacci Series up to N terms.

# include <stdio.h>

int main(){
    int n,n1=0,n2=1,n12,i;
    printf("Enter number of terms you do wish to print:-");
    scanf("%d",&n);
    printf("%d,%d",n1,n2);
    for (i;i<=n-2;++i){
        n12 = n1 + n2;
        n1 = n2;
        n2 = n12;
        printf(",%d",n12);
    }
    return(0);
}