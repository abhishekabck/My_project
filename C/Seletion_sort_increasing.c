#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void array_input(int **array, int n) {
    *array = (int*)calloc(n, sizeof(int));
    for (int i = 0; i < n; i++) {
        printf("\nEnter element: ");
        scanf("%d", (*array) + i);
    }
}

void selection_sort(int* a, int n) {
    int i, j, min;
    for (i = 0; i < n - 1; i++) {
        min = i;
        for (j = i + 1; j < n; j++) {
            if (a[j] < a[min]) min = j;
        }
        swap(&a[i], &a[min]);
    }
}

int main() {
    int n_elm, *a;
    printf("\nEnter the size of the array: ");
    scanf("%d", &n_elm);
    array_input(&a, n_elm);
    selection_sort(a, n_elm);
    printf("\nSorted Array: ");
    for (int i = 0; i < n_elm; i++) {
        printf("%d, ", a[i]);
    }
    free(a); // Don't forget to free the allocated memory
    return 0;
}
