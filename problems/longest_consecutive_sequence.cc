# include <bits/stdc++.h>
using namespace std;

int longest_consecutive(vector<int>& nums) {
    unordered_set<int> s;
    int max_cons = 0;
    for (int it: nums){
        s.insert(it);
    }
    int count = 0;
    int start = nums[0];
    for (int it: s) {
        int count = 0,p = 1, n = 1;
        while (s.find(it+p) != s.end() || s.find(it-n) != s.end()){
            if (s.find(it + p) != s.end()) {
                count++;
                p++;
                s.erase(start+p);
                
            }
            if (s.find(start-n) != s.end()){
                count++;
                n++;
                s.erase(start-n);
            }
        }
        max_cons = (max_cons > count)? max_cons:count;
    }
    return max_cons;
}

int main() {
    vector<int> nums = {100, 4, 200, 3, 2, 1};
    cout<<longest_consecutive(nums);
    return 0;
}