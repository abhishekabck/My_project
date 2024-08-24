# include <bits/stdc++.h>
using namespace std;

void bits(int num) {
    if (num == 0){
        return;
    }
    bits(num/2);
    cout<<num%2;
}

int main() {
    int num = 10;
    bits(num);
    return 0;
}