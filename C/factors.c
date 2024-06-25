# include <stdio.h>
# include <math.h>
// hashing hash table , map, stack, queue

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(){
    int n = 1000;
    int p = 15,ind = 0;
    int arr[1000] = {0};
    for (int i=1; i<=sqrt(n); i++) 
    { 
        if (n%i == 0) 
        { 
            // If divisors are equal, print only one 
            if (n/i == i) 
                arr[ind++] = i;
  
            else // Otherwise print both 
                arr[ind++] = i;
                arr[ind++] = n/i;
        }
    }
    int j;
    for (int i =0; i<ind; i++){
        j = i;
        while (j>0 && arr[j-1]>arr[j]){
            swap(&arr[j-1],&arr[j]);
            j--;
        }
    }
    
    // for (int i = 0; i<ind;i++){
    //     printf("%d, ",arr[i]);
    // }
    // return 0;
    printf("%d",arr[p-1]);
}
