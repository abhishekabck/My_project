# include <stdio.h>
# include <math.h>
# include <stdbool.h>

bool is_prime(int n){
    if (n<2) return false;
    for (int i = 2; i<=sqrt(n); i++){
        if (n%i==0) return false;
    }
    return true;
}

int main(){
    int start, end;
    printf("Enter the range of for Prime Number:- ");
    scanf("%d %d",&start, &end);
    while (start<=end){
        if (is_prime(start)) printf("%d, ",start);
        start++;
    }
    return 0;
}