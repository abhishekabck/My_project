#include <bits/stdc++.h>
using namespace std;

int main() {
    int T, N, a, b, c;
    cin>> T;
    vector<int> floors;
    while (T--){
        cin>>N>>a>>b>>c;
        int cases[] = {-1, -1, -1};

        for (int i = 0; i<N; i++) {
            int temp;
            cin>> temp;
            floors.push_back(temp);
            
            if (temp == a) cases[0] = 0;
            else if (temp > a) {
                if (cases[1] == -1) cases[1] = temp - a;
                else cases[1] = (cases[1]<temp-a)?cases[1]:temp-a;
            }
            else if (temp < a){
                if (cases[2] == -1) cases[2] = temp - a;
                else cases[2] = (cases[2]<temp-a)?cases[2]:temp-a;
            }
        }
        
        int result;
        if ((cases[0] == 0) || (b > a && cases[1] != -1) || (b < a && cases[2] != -1)){
            cout<<abs(b-a) + c<<endl;
        }
        else if (b >  a && cases[1] == -1) {
            cout<<cases[2] + b + a + c<<endl;
        }
        else {
            cout<<cases[1] + b +a + c<<endl;
        }
        
    }
}
