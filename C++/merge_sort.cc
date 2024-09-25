# include <bits/stdc++.h>
# include <vector>
# include <math.h>
using namespace std;

void merge_array(vector<int>& array, int low, int mid, int high) {
    vector<int> left;
    vector<int> right;
    int nl = mid - low + 1, nr = high - mid;
    for (int i = 0; i<nl; i++) left.push_back(array[low + i]);
    for (int i = 0; i<nr; i++) right.push_back(array[mid + 1 +i]);
    int i = 0, j = 0, k = low;
    while (i<nl && j<nr){
        if (left[i]<right[j]) array[k++] = left[i++];
        else array[k++] = right[j++];
    }
    while (i<nl) array[k++] = left[i++];
    while (j<nr) array[k++] = right[j++];
}

void print_vector(vector<int> &arr ) {
    for (auto it: arr){
        cout<<it<<", ";
    }
}
void merge_sort(vector<int>& array, int low, int high){
    if (low < high){
        int mid = floor((low+high)/2);
        merge_sort(array, low, mid);
        merge_sort(array, mid+1, high);
        merge_array(array, low, mid, high);
    }
}
