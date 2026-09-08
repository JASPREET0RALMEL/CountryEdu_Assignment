#include <iostream>
#include <vector>
#include <string>

using namespace std;

string isMatch(string P, string Q) {
    int n = P.length();
    int m = Q.length();

    // 1. Syntax Validation
    if (m == 0 || Q[0] == '+') return "Invalid Pattern";
    for (int j = 1; j < m; ++j) {
        if (Q[j] == '+' && Q[j - 1] == '+') {
            return "Invalid Pattern";
        }
    }

    // 2. DP Table
    vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
    dp[0][0] = true; // Base case: Empty string matches empty pattern

    for (int i = 0; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (Q[j - 1] == '+') {
                char prevChar = Q[j - 2];
                
                // Option A: Treat '+' as 1 occurrence (requires dp[i][j-1])
                bool oneOccurrence = dp[i][j - 1];
                
                // Option B: Treat '+' as >1 occurrence (requires P[i-1] == prevChar && dp[i-1][j])
                bool multiOccurrence = (i > 0 && P[i - 1] == prevChar) && dp[i - 1][j];
                
                dp[i][j] = oneOccurrence || multiOccurrence;
            } else {
                if (i > 0 && P[i - 1] == Q[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
            }
        }
    }

    return dp[n][m] ? "True" : "False";
}

int main() {
    cout << isMatch("AAAB", "A+B") << endl; // Output: True
    cout << isMatch("AABA", "AA") << endl;  // Output: False
    cout << isMatch("AAB", "+A") << endl;   // Output: Invalid Pattern
    return 0;
}
