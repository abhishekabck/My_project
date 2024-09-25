# include <bits/stdc++.h>
# include "merge_sort.cc"

bool is_double_exits(vector<int>& array, int size) {
    merge_sort(array, 0, size-1);
    for (int i = 0; i< size - 1; i++){
        if (array[i] == array[i+1]){
            return true;
        }
    }
    return false;
}

bool using_map(vector<int>& array) {
    unordered_map<int, int> um;
    for (int it: array) {
        if (um.find(it) != um.end()){
            return true;
        }
        um[it]++;
    }
    return false;
}

bool using_set(vector<int>& array) {
    unordered_set<int> us;
    int size = 0;
    for (int it:array) {
        us.insert(it);
        if (us.size() != size+1){
            return true;
        }
        size++;
    }
    return false;
}


int main(){
    vector<int> array = {1,2,3,3};
    cout<<is_double_exits(array, 4)<<endl;
    cout<<using_map(array)<<endl;
    cout<<using_set(array)<<endl;
    return 0;
}