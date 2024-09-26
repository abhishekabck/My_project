# include <bits/stdc++.h>
# include "merge_sort.cc"

using namespace std;

int partition(vector<int>& array, int low, int high) {
        int i = high, j = high;
        int pivot = array[low];
        while (low < i) {
            if (array[i] >= pivot) {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
                j--;
            }
            i--;
        }
        array[low] = array[j];
        array[j] = pivot;
        return j;
}

void quick_sort(vector<int>& arr, int left, int right){
    if (right > left) {
        int mid = partition(arr, left, right);
        quick_sort(arr, left, mid-1);
        quick_sort(arr, mid+1, right);
    }
}

int main(){
    vector<int> array = {7, 9, 3, 4, 8, 7, 1, 2, 5, 10};
    quick_sort(array, 0, array.size()-1);
    print_vector(array);
    return 0;
}
