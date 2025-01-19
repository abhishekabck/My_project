# include <bits/stdc++.h>
using namespace std;
bool is_craft_possible(vector<int> a, vector<int> b) {
    for(int i = 0; i < b.size(); i++){
        a[i] -= b[i];
    }
    sort(a.begin(), a.end());
    if(a[0] >= 0) return true;
    if(a[0] < 0 && a[1] >= abs(a[0])) return true;
    return false;
}

int main(){
    int t;
    cin>>t;
    for(int i = 0; i<t; i++){
        int n;
        cin>>n;
        vector<int>a;
        vector<int>b;
        for(int i = 0; i<n; i++){
            int num;
            cin>>num;
            a.push_back(num);
        }
        for(int i = 0; i<n; i++){
            int num;
            cin>>num;
            b.push_back(num);
        }
        if(is_craft_possible(a, b) == true) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}