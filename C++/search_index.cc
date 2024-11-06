# include <bits/stdc++.h>
using namespace std;

int search_ins_pos(vector<int>& nums, int target){
    int low = 0, high = nums.size() - 1;
    while (low <= high){
        int mid = low + (high - low)/2;
        if (nums[mid] == target){
            return mid;
        }
        else if (nums[mid] > target){
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return low;
}

int main(){
    vector<int> nums = {1,3,5,6};
    int target = 0;
    cout<<search_ins_pos(nums, target);
    return 0;
}