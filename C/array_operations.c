# include <stdio.h>

void insert(int* arr, int key, int* size, int capacity){
    if (*size == capacity) return;
    int j = *size;
    while (j > 0 && key<arr[j-1]){
        arr[j] = arr[j-1];
        j--;
    }
    *size += 1;
    arr[j] = key;
}

void deleteByIndex(int *arr, int index, int* size) {
    if (index > *size) index = *size - 1;
    do {
        arr[index] = arr[index+1];
        index++;
    } while (index < *size);
    *size -= 1;
}

void deleteByKey(int *arr, int key, int* size) {
    int i;
    for (i = 0; i < *size; i++) {
        if (arr[i] == key) {
            break;
        }
    }
    if (i>=*size) return;
    deleteByIndex(arr, i, size);
}

int sorted_merge(int* arr1, int* arr2, int size1, int size2, int* returnArray){
    // arr1 and arr2 must be sorted
    int i = 0, j = 0, k = 0;
    while (i < size1 && j < size2) {
        if (arr1[i]<arr2[j]){
            returnArray[k++] = arr1[i++];
        }
        else {

            returnArray[k++] = arr2[j++];
        }
    }

    while (i < size1) {
        returnArray[k++] = arr1[i++];
    }
    while (j < size2) {
        returnArray[k++] = arr2[j++];
    }
    return k;
}

int merge(int* arr1, int* arr2, int size1, int size2, int* returnArray){
    // arr1 and arr2 must be sorted
    int i = 0, j = 0, k = 0;
    while (i < size1) {
        returnArray[k++] = arr1[i++];
    }
    while (j < size2) {
        returnArray[k++] = arr2[j++];
    }
    return k;
}
void append(int* arr, int key,  int* size, int capacity) {
    if (*size >= capacity) return;
    arr[*size] = key;
    *size += 1;
}

void print(int* arr, int size) {
    for (int i = 0; i < size; i++) printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    // int arr[8] = {};
    // int capacity = 8;
    // int size = 0;
    // insert(arr, 5, &size, capacity);
    // insert(arr, 3, &size, capacity);
    // insert(arr, 25, &size, capacity);
    // print(arr, size);
    // insert(arr, 524, &size, capacity);
    // insert(arr, -4534, &size, capacity);
    // deleteByKey(arr, 83, &size);
    // print(arr, size);
    // return 0;

    int arr1[4] = {3,5,6,75};
    int arr2[5] = {0,34,645};
    int size1 = 4, size2 = 3;
    int result[9];
    int size = merge(arr1, arr2, size1, size2, result);
    append(result, 53, &size, 9);
    append(result, 53, &size, 9);
    append(result, 53, &size, 9);
    append(result, 53, &size, 9);
    print(result, size);

}