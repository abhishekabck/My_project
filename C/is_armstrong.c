# include <stdio.h>
# include <math.h>
# include <stdbool.h>

int digits(int n){
    return floor(log10(abs(n)) + 1);
}
bool is_armstrong(int n) {
    if (n<=0) return false;
    int length = digits(n),num, sum = 0;
    if (length == 1) return true;
    num = n;
    while (num!=0){
        sum = sum + pow(num%10,length);
        num = num/10;
    }
    if (sum == n) return true;
    else return false;
}

int main(){
    int num;
    printf("Enter Number:- ");
    scanf("%d",&num);
    if (is_armstrong(num)) {
        printf("Armstrong..");
    }
    else printf("Not Armstrong..");
    return 0;

}

