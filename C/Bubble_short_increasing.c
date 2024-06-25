# include <stdio.h>
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(){
    int a[] = {1,2,3,4,5,6 };
    int n = sizeof(a)/sizeof(a[0]);
    int i , j, didswap;
    for (i = n-1; i>0; i--){
        didswap = 0;
        for (j = 0; j<i; j++){
            if (a[j]>a[j+1]){
                swap(&a[j], &a[j+1]);
                didswap = 1;
            }
        }
        if (didswap == 0){
            break;
        }
        printf("\nRuns");
    }

    printf("\nSorted Array is Given as:- ");
    for (i = 0; i<n; i++){
        printf("%d, ", a[i]);
    }
    return 0;
}
