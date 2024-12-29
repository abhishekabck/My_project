#include <iostream>
#include <string>
using namespace std;

// Function to check if we can form t by using x and y substrings
bool can_form_t(const string& t, const string& x, const string& y) {
    int i = 0;
    int m = t.length();
    
    // Try to match x or y greedily
    while (i < m) {
        if (i + x.length() <= m && t.substr(i, x.length()) == x) {
            i += x.length(); // Move by length of x
        } else if (i + y.length() <= m && t.substr(i, y.length()) == y) {
            i += y.length(); // Move by length of y
        } else {
            return false; // If neither matches, return false
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T; // Number of test cases

    while (T--) {
        int n, m;
        cin >> n >> m; // Lengths of s and t
        
        string s, t;
        cin >> s >> t; // Strings s and t
        
        string result = "";
        
        // Try all splits (x, y) of s
        for (int i = 1; i < n; ++i) {
            string x = s.substr(0, i); // prefix of length i
            string y = s.substr(i);    // suffix of length n-i
            
            if (can_form_t(t, x, y)) {
                result += '1';
            } else {
                result += '0';
            }
        }
        
        cout << result << "\n"; // Output the result for this test case
    }

    return 0;
}
