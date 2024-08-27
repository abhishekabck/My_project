# include <stdio.h>
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(){
    int a[] = {9,45,23,4,2,4,55,31};
    int n = sizeof(a)/sizeof(a[0]);
    int i , j;
    for (i =0; i<n; i++){
        j = i;
        while (j>0 && a[j-1]>a[j]){
            swap(&a[j-1],&a[j]);
            j--;
        }
    }

    printf("\nSorted Array is Given as:- ");
    for (i = 0; i<n; i++){
        printf("%d, ", a[i]);
    }
    return 0;
}
