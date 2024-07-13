# include <stdio.h>

int main(){
    unsigned long int m = 2,n = 2,k,ungliness = 0;
    k = m*n;
    while (k--){
        // f(k)
        for (int i = 0; i<=k/(m-1); i++){
            ungliness += (k>m*(i+1))?0:
        }
    }
}