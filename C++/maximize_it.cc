
# include <bits/stdc++.h>
# define ll long long
# define vll vector<ll>

using namespace std;
int main(){
    ll k = 3, m = 100;
    vector<vll> vec {
        {1,4,5},
        {2,3,4,5},
        {3,6,7}
    };
    vll store(36,0);
    vll ars={1,3,12,36};
  
    for (int i = 0; i<k; i++){
        int c = vec[i].size();
        for (int j = 0; j<36/ars[i]; j++){
            for (int k = 0; k<ars[i]; k++){
                store[j*ars[i]+k] += pow(vec[i][j%c],2LL);
            }
        }
        }
    ll Max = 0;
    for (int i = 0; i<36; i++){
        store[i] = store[i]%m;
        Max = max(store[i],Max);
    }
    cout<<Max;
}
