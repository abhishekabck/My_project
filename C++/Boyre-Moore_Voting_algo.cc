# include <bits/stdc++.h>

using namespace std;

int ElmentMoreThanhalf(int* arr, int size) {
    int candidate = arr[0], count = 0;
    for (int i = 0; i < size; i++) {
        if (count == 0) {
            candidate = arr[i];
        }
        if (candidate == arr[i]) count++;
        else count--;
    }
    return candidate;
}

int main(){
    int arr[] = {2,2,3,2,4,4,5,5,2,2,2,4};
    printf("%d",ElmentMoreThanhalf(arr, sizeof(arr)/sizeof(arr[0])));
    return 0;
}