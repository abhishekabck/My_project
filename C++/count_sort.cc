# include<bits/stdc++.h>
# include "merge_sort.cc"
using namespace std;


void max_min_array(vector<int>& arr, vector<int>& arr1){
    int max = INT_MIN;
    int min = INT_MAX;
    for (auto it: arr) {
        max = (max<it)?it:max;
        min = (min>it)?it:min;
    }
    arr1.push_back(min);
    arr1.push_back(max);
}


void count_sort(vector<int>& array) {
    int n = array.size();
    
    // Evaluating the maximum and minimum of the array
    vector<int> arr;
    max_min_array(array,arr);
    int t_size = arr[1] - arr[0] + 1;  // Size of the temporary array
    // Assigning the array in heap
    int* freq = (int*)calloc(t_size, sizeof(int));

    // Counting frequency
    for (int it: array){
        freq[it-arr[0]]++;
    }

    // assigning the values to original array
    for (int i = 0, j = 0; i < n; i++) {
        while (freq[i]>0) array[i++] = freq[j]--;
    }
}



int main()
{
    vector<int> arr = {4,5,3,1,5,4,3,54,6,5,64,32,4,5,4,23,32253};
    count_sort(arr);
    print_vector(arr);
    return 0;
}
