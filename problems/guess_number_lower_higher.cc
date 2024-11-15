# include <bits/stdc++.h>
using namespace std;

int target = 0;
int guess(int num){
    if (num == target) return 0;
    else if (num > target) return -1;
    else return 1;
}

int main(){
    int n = 10;
    target = 6;
    // main code
    int low = 0, high = n;
    while (low <= high){
        int mid = low + (high-low)/2;
        if (guess(mid) == 0){
            cout<<mid;
            break;
        }
        else if (guess(mid) == -1){
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

}