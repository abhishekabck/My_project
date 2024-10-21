#include <stdio.h>
#include <stdlib.h>

int* merge(int arr1[], int arr2[], int size1, int size2) {
    int* result = (int*)malloc((size1 + size2) * sizeof(int));
    int i = 0, j = 0, k = 0;
    while (i < size1 && j < size2) {
        if (arr1[i] < arr2[j]) {
            result[k++] = arr1[i++];
        } else {
            result[k++] = arr2[j++];
        }
    }
    while (i < size1) {
        result[k++] = arr1[i++];
    }
    while (j < size2) {
        result[k++] = arr2[j++];
    }

    return result;
}

int main() {
    int A[] = {4, 9, 13, 17, 25, 30};
    int B[] = {10, 11, 15, 20, 23, 39, 40, 42};
    int* result = merge(A, B, 6, 8);

    for (int i = 0; i < 14; i++) {
        printf("%d, ", result[i]);
    }

    free(result);
    return 0;
}
