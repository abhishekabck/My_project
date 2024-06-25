# include <stdio.h>
                                    // Binary SEarching MEthond 
                                    // Requirement --> Sorted Arrary

int main(){
    int array[] = {1,3,4,5,5,5,5,5,6,7},mid,data = 5;
    int size = sizeof(array)/sizeof(array[0]);
    int low = 0;
    int high = size - 1;
    int flag = 0;
    while (low<=high){
        mid = (low + high)/2;
        if (array[mid] == data) {
            if (array[mid - 1]<data) {
                flag = 1;
                break;
                }
            if (!flag) high = mid - 1;
            else low = mid + 1;
        }

        else if (!flag && array[mid]>data) high = mid - 1;
        else if (!flag && array[mid]<data) low = mid + 1;

    }
    printf("data is at =%d --> %d ", mid, array[mid]);
    return 0;
}

