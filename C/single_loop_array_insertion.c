# include <stdio.h>

// Single Loop 2-d Array INsertion
int main(){
    int m = 2,n=4;
    int arr[m][n];
    int k = m*n;
    int i = 0,j = 0;
    while (k){
        if (j >= n){
            i++;
            j = 0;
            continue;;
        }
        printf("\n%d %d",i,j);
        arr[i][j] = 1;
        j++;
        k--;  
    }
    return 0;
}