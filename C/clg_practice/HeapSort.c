# include <stdio.h>

void makeheap(int [], int);
void heapsort(int [], int);

int main() {
    int arr[10] = {11, 2, 9, 13, 57, 25, 17, 1, 90, 3};
    int i = 0;
    printf("Heap Sort:\n");
    makeheap(arr, 10);
    heapsort(arr, 10);
    for(int i = 0; i < 10; i++) {
        printf("%d, ", arr[i]);
    }
    return 0;
}

void makeheap(int x[], int n) {
    int i, val, s, f;
    for (i = 1; i < n; i++) {
        s = i;
        val = x[i];
        f = (s-1)/2;
        while (s > 0 && x[f] < val) {
            x[s] = x[f];
            s = f;
            f = (s - 1)/2;
        }
        x[s] = val;
    }
}

void heapsort(int x[], int n) {
    int i, s, f, val;
    for (i = n-1; i >0; i--) {
        val = x[i];
        x[i] = x[0];
        f = 0;
        if (i == 1) s = -1;
        else s = 1;
        
        if ( i > 2 && x[2] > x[1]) s = 2;
        while (s >= 0 && val < x[s]) {
            x[f] = x[s];
            f = s;
            s = 2 * f + 1;
            if (s + 1 <= i-1 && x[s] < x[s + 1])
                s++;
            if (s > i - 1) {
                s = -1;
            }
        }
        x[f] = val;
    

        for(int j = 0; j < n; j++){
            printf("%d ", x[j]);
        }
        printf("\n");
    }
}