# include <stdio.h>

int main(){
    int num,sum = 0;
    scanf("%d",&num);
    while (num>=10){
        sum = 0;
        while (num!=0){
            sum = sum + num%10;
            num = num/10;
        }
        num = sum;
    }
    printf("%d\n",num);
    return 0;
}