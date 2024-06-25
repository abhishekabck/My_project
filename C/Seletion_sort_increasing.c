# include <stdio.h>
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void array_input(int *array,int n){
    int i;
    for (i=0; i<n; i++){
        printf("\nEnter element:- ");
        scanf("%d",(array+i));
    }
}

int main(){
    int n_elm,*ptr;
    printf("\nEnter the size of array:- ");
    scanf("%d",&n_elm);
    int a[n_elm];
    array_input(a, n_elm);
    int n = sizeof(a)/sizeof(a[0]);
    int i , j, min;
    for (i = 0; i<=n-2; i++){
        min = i;
        for (j = i; j<n; j++){
            if (a[j]<a[min]) min = j;
        }
        swap(&a[i],&a[min]);
        
    }
    printf("\nSorted Array is Given as:-");
    for (i = 0; i<n; i++){
        printf("%d, ", a[i]);
    }
    return 0;
}
