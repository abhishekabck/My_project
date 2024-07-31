# include <stdio.h>

int print_fab(int n, int i){
    if (i == n){
        return 0;
    }else if(i == 0){
        printf("0 ");
        return 0;
    }
    else if (i == 1){
        printf("1 ");\
        return 1;
    }
    else {
        int fib = print_fab(n, i - 1) + print_fab(n , i - 2);
        printf("%d ",fib);
        return fib;
    }
}

int main(){
    int num = 5;
    print_fab(num, 0);
    return 0;
}