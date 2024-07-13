# include <stdio.h>
# include <math.h>

void give(unsigned long x){
    x = x/2;
    int i = 0;
    while (1){
        if (pow(2,i)>x){
            printf("%d\n",x*4 - (pow(2,i)*2));
            break;
        }
        i++;
    }
}

int main(){
    unsigned long x,t;
    while (t--){
        scanf("%ld",&x);
        give(x);
    }
    return 0;
}