# include <bits/stdc++.h>
# include "merge_sort.cc"
using namespace std;

int kth_largest_element(vector<int>& nums, int k) {
    merge_sort(nums, 0, nums.size()-1);
    return nums[nums.size()-k];
}

int kth_largest_element_without_sorting(vector<int>& nums, int k){
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for (int i = 0; i < nums.size(); i++){
        minHeap.push(nums[i]);
        if (minHeap.size() > k) {
            minHeap.pop();
        }
    }
    return minHeap.top();
}

int main(){
    vector<int> array = {3,2,3,1,2,4,5,5,6};
    cout<<kth_largest_element(array, 4);
    return 0;
}