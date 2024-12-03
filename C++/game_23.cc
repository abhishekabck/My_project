# include <bits/stdc++.h>

using namespace std;

int count_factor(int number){
    if (number == 0 || number == 1){
        return 0;
    }
    int count = 0;
    while (number%2 == 0 || number%3 == 0){
        number = (number%2 == 0)?(count++, number/2): number;
        number = (number%3 == 0)?(count++, number/3) : number;
    }
    if (number != 1) return -1;
    return count;
}

int main(){
    int n, m;
    cin>>n>>m;
    if (m%n != 0){
        cout<<-1;
        return 0;
    }
    cout<<count_factor(m/n);
    return 0;
}