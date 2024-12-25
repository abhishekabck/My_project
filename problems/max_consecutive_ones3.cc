# include <bits/stdc++.h>

int longestOnes(vector<int>& nums, int k){
    int n = nums.size();
    vector<int> streaks;
    int len = 0;
    for(int i = 0; i <n; i++){
        if(nums[i] == 1) len++;
        else {
            streaks.push_back(len);
            len = 0;
        }
    }
    streaks.push_back(len);
    // number of zeros in nums is <= k
    if (streaks.size() <= k+1){
        return n;
    }
    int maxsum = k;
    for (int i = 0; i <= k; i++){
        maxsum += streaks[i];
    }

    // slide the windows in streaks of length k - 1
    for(int i = 1; i+k < streaks.size(); i++){
        
    }
}