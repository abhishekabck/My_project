# include <stdio.h>
# include <stdlib.h>
# include <time.h>


// Swap function
void swap(int* a, int* b){
    int t = *a;
    *a = *b;
    *b = t;
}

// Normal Quick Sort Algorithm
// Choosing lowest or the fist element as pivot element.
int partition(int* arr, int high, int low){
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++){
        if (arr[j] <= pivot){
            i++;
            swap(&arr[j], &arr[i]);
        }
    }
    swap(&arr[i+1], &arr[high]);
    return (i+1);
}