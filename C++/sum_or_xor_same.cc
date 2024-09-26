# include <bits/stdc++.h>
using namespace std;

long sumXor(long n) {
    int zeroBits = 0;
    while (n > 0) {
        if ((n & 1) == 0) {
            zeroBits++;
        }
        n >>= 1;
    }
    return 1L<<zeroBits;
}

int main(){
    cout<<sumXor(5);
    return 0;
}