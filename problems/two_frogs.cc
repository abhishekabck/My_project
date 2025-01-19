# include <bits/stdc++.h>
using namespace std;

bool is_alice_won(int a, int b) {
    int diff = abs(a - b);
    // Absolute Loss
    if(diff == 1){
        return false;
    }
    // Variant Loss
    if(diff%2 == 0){
        return true;
    }
    return false;
}

int main(){
    int t;
    cin>>t;
    for(int i = 0; i < t; i++) {
        int n, a, b;
        cin>>n>>a>>b;
        if(is_alice_won(a, b) == true){
            cout<<"YES"<<endl;
        }else cout<<"NO"<<endl;
    }
    return 0;
}