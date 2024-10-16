# include <stdio.h>
# include <stdlib.h>
# include <string.h>


int size(int* arr){
    int size = sizeof(arr)/sizeof(arr[0]);
    return size;
}

int size(float* arr) {
    int size = sizeof(arr)/sizeof(arr[0]);
    return size;
}

int size(char* arr) {
    int size = sizeof(arr)/sizeof(arr[0]);
    return size;
}

void swap(int* first, int* second) {
    int temp = *first;
    *first = *second;
    *second = temp;
}

void stringSwap(char* first, char* second) {
    // To Swap String you must have an equal size string
    int size1 = size(&first), size2 = size(&second);
    char* temp = (char*)calloc(size1, sizeof(char));
    strcpy(&temp, &first);
    strcpy(&first, &second);
    strcpy(&second, &temp);
}


int sfind(int* arr, int element){
    int size = size(&arr);
    int low = 0, high = size - 1;
    while (low <= high) {
        int mid = low + (high - low)/2;
        if (arr[mid] == element) {
            return mid;
        }
        else if (arr[mid]>element) {
            high = mid - 1;
        }
        else low = mid + 1;
    }
    return -1;
}
int lfind(int* arr, int element) {
    int size = size(&arr);
    for (int i = 0; i < size; i++) {
        if (arr[i] == element){
            return i;
        }
    }
    return -1;
}

/*
Algorithm:- Sorting Techniques
*/

// Bubble Sort
void BubbleSort(int* arr) {
    /*
    :: Time Complexity::
    :: Worst case:- O(n^2)
    :: Average Case:- O(n^2)
    :: Best Case:- O(n)
    :: Space Complexity ::
    :: Worst, Best, Average Case :- O(1) ::
    */
    int Size = size(&arr);
    int swaps;
    for (int i = Size - 1; i > 0; i--) {
        swaps = 0;
        for (int j = 0; j < i; j++) {
            if (arr[j]>arr[j+1]) {
                swaps++;
                swap(&arr[j], &arr[j+1]);
            }
        }
        if (swaps == 0) break;
    }
}

void insertionSort(int* arr){
    /*
    :: Time Complexity::
    :: Worst case:- O(n^2)
    :: Average Case:- O(n^2)
    :: Best Case:- O(n)
    :: Space Complexity ::
    :: Worst, Best, Average Case :- O(1) ::
    */
    int Size = 0;
}