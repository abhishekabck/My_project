# include <bits/stdc++.h>
using namespace std;
bool using_map(string s1, string s2){
    unordered_map<char, int> us;
    for (char it:s1) {
        us[it]++;
    }
    for (char it:s2){
        us[it]--;
    }
    for (auto it: us) {
        if (it.second != 0){
            return false;
        }
    }
    return true;
}
int main(){
    string s1 = "anagram", s2 = "nagar`m";
    cout<<using_map(s1, s2);
    return 0;
}