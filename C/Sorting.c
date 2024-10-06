# include <stdio.h>

void swap(int* var1, int* var2) {
    int temp = *var2;
    *var2 = *var1;
    *var1 = temp;
}

void Bubble_sort(int* arr, int size){
    int swapped = 1;
    for (int i = size - 1; i>0; i--) {
        if (swapped == 0){
            return;
        }
        swapped = 0;
        for (int j = 0; j<i; j++){
            if (arr[j] > arr[j+1]){
                swap(&arr[j], &arr[j+1]);
                swapped = 1;
            }
        }
    }
}

void SelectionSort(int* arr, int size) {
    for (int i = 0; i < size; i--){
        int min = arr[];
        for (int j = 1)
    }
}

void traverse(int* arr, int size){
    for (int i = 0; i<size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(){
    int arr[] = {2,3,4,5,45,64,75};
    int size = sizeof(arr)/sizeof(arr[0]);
    Bubble_sort(arr, size);
    traverse(arr, size);
    return 0;
}