# include <stdio.h>
# include <stdlib.h>
# define true 1
# define false 0

// swap function
void swap(int* first, int* second) {
    int temp = *second;
    *second = *first;
    *first = temp;
}

void print(int* arr, int size){
    for (int i = 0; i<size; i++){
        printf("%d,", arr[i]);
    }
    printf("\n");
}


// Bubble Sort
void Bubble_sort(int* arr, int size){
    for (int i = size; i > 1; i--) {
        for (int j = 1; j < i; j++) {
            if (arr[j-1]>arr[j]){
                swap(arr + j, arr + j - 1);
            }
        }
    }
}
// Optimized Bubble Sort
void Bubble_sort_op(int* arr, int size){
    int swapped;
    for (int i = size; i > 1; i--) {
        swapped = false;
        for (int j = 1; j < i; j++) {
            if (arr[j-1] > arr[j]){
                swap(arr + j, arr + j - 1);
                swapped = true;
            }
        }
        if (swapped == false){
            break;
        }
    }
}

int* copy(int* arr, int size){
    int* copied = calloc(size, sizeof(int));
    for (int i = 0; i<size; i++){
        copied[i] = arr[i];
    }
    return copied;
}

// insertion sort
void insertion_sort(int* arr, int size){
    for (int i = 1; i<size; i++){
        int key = arr[i], j = i - 1;
        while (j>=0 && arr[j]>key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}


// Merge Sort
void merge_array(int* arr, int low, int mid, int high){
    int size1 = mid - low + 1, size2 = high - mid;
    int* A = (int*)malloc(sizeof(int) * size1);
    int* B = (int*)malloc(sizeof(int) * size2);
    if (A == NULL || B == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    for (int i = 0; i<size1; i++) A[i] = arr[i+low];
    for (int i = 0; i<size2; i++) B[i] = arr[i+mid+1];
    int k = 0, i = 0, j = 0;
    while (i < size1 && j < size2){
        if (A[i]<=B[j]) arr[low + k++] = A[i++];
        else arr[low + k++] = B[j++];
    }
    while (i < size1) arr[low + k++] = A[i++];
    while (j < size2) arr[low + k++] = B[j++];
    free(A), free(B);
}

void merge_sort(int* arr, int low, int high) {
    if (low < high){
        int mid = (low+high)/2;
        merge_sort(arr, low, mid);
        merge_sort(arr, mid + 1, high);
        merge_array(arr, low, mid, high);
    }
}

int min(int* arr, int start, int end){
    int min_index = start;  // Initialize min_index to start
    if (start >= end) return -1;
    for (int i = start + 1; i < end; i++){
        if (arr[i] < arr[min_index]) {  // Compare values in array
            min_index = i;  // Update min_index
        }
    }
    return min_index;  // Return the index of the minimum element
}

// Selection sort
void selection_sort(int* arr, int size){
    for (int i = 0; i < size; i++){
        int index = min(arr, i, size);
        if (index != i){  // Change to != to ensure proper comparison
            swap(arr + i, arr + index);
        }
    }
}





int main(){
    int arr[] = {3,5,3,1,4,23,53,23,53,4};
    int size = sizeof(arr)/sizeof(arr[0]);
    int* arr2 = copy(arr, size);
    insertion_sort(arr, size);
    merge_sort(arr2, 0, size-1);
    print(arr2, size);
    print(arr, size);
    return 0;
}
