# include <bits/stdc++.h>

using namespace std;


int total_subarrays(vector<int> &nums, int k) {
    unordered_set<int> records;
    records.insert(0);
    int count = 0;
    // Finding prefix Sum
    for (int i = 1; i < nums.size(); i++) {
        nums[i] = nums[i] + nums[i-1];
    }

    // Using set to count the subarrays
    for (int it : nums) {
        if (records.find(it%k) != records.end()) count++;
        records.insert(it%k);
    }
    return count;
}
int main() {
    vector<int> nums = {4, 6, 0, -3, -1, 1, 5};
    int k = 6;
    int answer = total_subarrays(nums, k);
    cout<< answer;
    return 0;
}