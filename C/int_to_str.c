# include <stdio.h>

int main(){
    int num, num1 = 0;
    scanf("%d", &num);
    char* st_array[10] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    
    // Reversing the Number
    while (num>0){
        num1 = num1*10 + num%10;
        num /= 10;
    }
    
    //Printing by extracting one by one variable
    while (num1>0){
        printf("%s ", st_array[num1%10]);
        num1 = num1/10;
    }
    return 0;
}