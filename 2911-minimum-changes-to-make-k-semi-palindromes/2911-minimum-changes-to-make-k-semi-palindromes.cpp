using namespace std;

class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.length();
        
        // 1. Precompute all proper divisors d (1 <= d < len) for every possible length
        vector<vector<int>> divisors(n + 1);
        for (int len = 2; len <= n; ++len) {
            for (int d = 1; d * d <= len; ++d) {
                if (len % d == 0) {
                    divisors[len].push_back(d);
                    if (d != 1 && d * d != len) {
                        divisors[len].push_back(len / d);
                    }
                }
            }
        }

        // 2. Precompute cost[i][j]: min changes to make substring s[i..j] a semi-palindrome
        vector<vector<int>> cost(n, vector<int>(n, 1e9));
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int len = j - i + 1;
                for (int d : divisors[len]) {
                    int changes = 0;
                    // Check each of the d modulo groups
                    for (int mod = 0; mod < d; ++mod) {
                        int left = i + mod;
                        int right = j - (d - 1 - mod);
                        while (left < right) {
                            if (s[left] != s[right]) {
                                changes++;
                            }
                            left += d;
                            right -= d;
                        }
                    }
                    cost[i][j] = min(cost[i][j], changes);
                }
            }
        }

        // 3. DP to partition the prefix of length i into j semi-palindromes
        // dp[i][j] = min changes to partition s[0..i-1] into j substrings
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 1e9));
        dp[0][0] = 0;

        for (int j = 1; j <= k; ++j) {
            // Each semi-palindrome must have length >= 2, so i >= 2 * j
            for (int i = 2 * j; i <= n; ++i) {
                // Try every valid split point p for the last substring s[p..i-1]
                for (int p = 2 * (j - 1); p <= i - 2; ++p) {
                    if (dp[p][j - 1] != 1e9) {
                        dp[i][j] = min(dp[i][j], dp[p][j - 1] + cost[p][i - 1]);
                    }
                }
            }
        }

        return dp[n][k];
    }
};