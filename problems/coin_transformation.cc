#include <iostream>
#include <cmath>
using namespace std;

long long maxCoins(long long n) {
    if (n <= 3) {
        return 1; // No transformation possible for n <= 3
    }
    // Calculate floor(log4(n)) = floor(log2(n) / 2)
    int k = static_cast<int>(log2(n) / 2);
    return (1LL << k); // 2^k
}

int main() {
    int t;
    cin >> t; // Number of test cases
    while (t--) {
        long long n;
        cin >> n; // Input value for each test case
        cout << maxCoins(n) << endl;
    }
    return 0;
}
