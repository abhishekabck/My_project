// Sequential Linear Search
# include <stdio.h>
# include <stdlib.h>

struct index{
    int element;
    int ind;
}

int index_sequential_search(int* arr, int k; int size){
    int l;
    int GN = 3; // GN is group number that is number if elements in a group
    struct index indArr[GN];
    int i, set = 0;
    int j = 0, ind = 0, start, end;
    for (i = 0; i < n; i += 3) {
        // storing element
        indArr[ind].element = arr[i];

        // storing the index
        storing[ind].ind = i;
        ind++;
    }
    printf("Index Array");
    for (l = 0; l < GN; l++){
        printf("\n %d", indArr[l].element);
    }

    if (k < arr[0] || k > arr[size-1]){
        printf("Not Found");
        exit(0);
    }else {
        for (i = l; l<=ind; i++){
            if (k <= indArr[i].element) {
                start = indArr[i - 1].ind;
                end = indArr[i].ind;
                set = 1;
            }
        }
        if (set == 0){
            start = indArr[GN -1].ind;
            end = GN;
        }
        for (i = start; i<= end; i++){
            if (k == arr[i]){
                break;
            }
        }
        if (j == 1) printf("Found at index %d", i);
        else printf("Not Found");
    }
}