# include <bits/stdc++.h>
using namespace std;

int tuniform_changed(vector<vector<int>> &array) {
    int result = 0; // Stores the total number of host changes uniform
    unordered_map<int, int> count_colors;
    // Counting the frequency of the Guest Colors
    for (auto unicode : array){
        count_colors[unicode[1]]++;
    }
    
    for (auto unicode:array){
        if (count_colors.find(unicode[0]) != count_colors.end()){
            result += count_colors[unicode[0]];
        }
    }
    return result;
}

int main(){
    int n;
    vector<vector<int>> array;
    cin>>n;
    for (int x = 0; x < n; x++){
        int h, a;
        cin>>h>>a;
        vector<int> unicode = {h, a};
        array.push_back(unicode);
    }
    cout<<tuniform_changed(array);
    return 0;
}