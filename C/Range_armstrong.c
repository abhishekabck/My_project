#include <stdio.h>
#include <math.h>

void is_armstrong(int num) {
    int temp, length = 0;
    temp = num;
    
    // To Get the length of number
    while (length++,temp/=10,temp>0);
    
    // Getting The Sum of power of number of digits
    int sum = 0;
    temp = num;
    while (temp>0){
        sum += pow(temp = temp%10,length);
    }
    if (num == sum) printf("%d ", num);

}

int main(){
    int a,b;
    scanf("%d %d",&a, &b);
    (a<b)?(a):(a = a +b,b = a -b,a = a -b);
    for (a; a<=b; a++){
        is_armstrong(a);
    }
    return 0;
}
