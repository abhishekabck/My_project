# include <bits/stdc++.h>
using namespace std;

double findMaxAverage(vector<int>& nums, int k){
    int n = nums.size();
    double maxavg = INT_MIN;
    for(int i = 0; i <= n-k; i++){
        int sum = 0;
        for(int j = 0; j < k; j++){
            sum+= nums[i+j];
        }
        maxavg = max(maxavg, sum/k);
    }
    return maxavg;
}


double findMaxAverage(vector<int>& nums, int k){
    int n = nums.size();
    vector<double> prefsum(n);
    prefsum[0] = nums[0];
    for(int i = 1; i<n; i++){
        prefsum[i] = prefsum[i-1]+nums[i];
    }
    double maxavg = prefsum[k-1]/k;
    for(int i = 0; i <= n-k; i++){
        double sum = prefsum[i+k-1]-prefsum[i-1];
        maxavg = max(maxavg, sum/k);
    }
    return maxavg;
}

/*
rabin-karp
horspool's algo
boyer-moore algo
finite automaton
knuth-morris-pratt algo
*/