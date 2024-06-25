# include <stdio.h>
                                    // Binary SEarching MEthond 
                                    // Requirement --> Sorted Arrary

int main(){
    int array[] = {1,3,4,5,5,5,5,5,6,7},mid,data = 5;
    int size = sizeof(array)/sizeof(array[0]);
    int low = 0, high = size - 1, i, result;
    while (low<=high && !(array[size + i]<array[size + i + 1])){
        mid = (low + high)/2;
        i = mid - size;
        if (array[mid] == data) {
            if (array[mid - 1]<data) {
                result = mid;
                }
            high = mid -1;
        }

        else if (array[mid]>data) high = mid - 1;
        else low = mid + 1;


    }
    printf("First Occurance is at %d\nLast Occurance is at %d",result,i);
    return 0;
}

