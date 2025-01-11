#include <bits/stdc++.h>
using namespace std;

// Function to calculate the required value
long answer(int a, int b, int c){
    return (a^b) + (b^c) + (c^a);
}

void solve(int t){
    for (int i = 0; i < t; i++){
        int l, r;
        cin >> l >> r;

        // If the difference between l and r is 2, we can directly output the values
        if ((r - l) == 2) {
            cout << l << " " << l + 1 << " " << r << endl;
            continue;
        }

        long max_ans = answer(l, l + 1, l + 2);  // Initial best answer with the first three numbers
        int x = l, y = l + 1, z = l + 2;  // Initialize the solution variables
        
        // Try every combination of (a, b, c) within the range
        for (int a = l; a <= r - 2; a++){
            for (int b = a + 1; b <= r - 1; b++){
                for (int c = b + 1; c <= r; c++){
                    long current_ans = answer(a, b, c);
                    if (current_ans > max_ans){
                        max_ans = current_ans;
                        x = a;
                        y = b;
                        z = c;
                    }
                }
            }
        }
        // Output the results
        cout << x << " " << y << " " << z << endl;
    }
}

int main(){
    int t;
    cin >> t;  // Take the number of test cases
    solve(t);  // Solve the problem for t test cases
    return 0;
}
