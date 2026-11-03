class Solution {
public:
    const int MOD = 1e9 + 7;

    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();

        vector<vector<int>> dp(n, vector<int>(n, -1));
        vector<vector<int>> ways(n, vector<int>(n, 0));

        dp[n - 1][n - 1] = 0;
        ways[n - 1][n - 1] = 1;

        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {

                if (board[i][j] == 'X' ||
                    (i == n - 1 && j == n - 1)) {
                    continue;
                }

                int best = -1;
                int count = 0;

                // Down
                if (i + 1 < n && dp[i + 1][j] != -1) {
                    best = max(best, dp[i + 1][j]);
                }

                // Right
                if (j + 1 < n && dp[i][j + 1] != -1) {
                    best = max(best, dp[i][j + 1]);
                }

                // Diagonal
                if (i + 1 < n && j + 1 < n &&
                    dp[i + 1][j + 1] != -1) {
                    best = max(best, dp[i + 1][j + 1]);
                }

                if (best == -1) {
                    continue;
                }

                // Count paths achieving the maximum score
                if (i + 1 < n && dp[i + 1][j] == best) {
                    count = (count + ways[i + 1][j]) % MOD;
                }

                if (j + 1 < n && dp[i][j + 1] == best) {
                    count = (count + ways[i][j + 1]) % MOD;
                }

                if (i + 1 < n && j + 1 < n &&
                    dp[i + 1][j + 1] == best) {
                    count = (count + ways[i + 1][j + 1]) % MOD;
                }

                int value = (board[i][j] == 'E' ||
                             board[i][j] == 'S')
                                ? 0
                                : board[i][j] - '0';

                dp[i][j] = best + value;
                ways[i][j] = count;
            }
        }

        if (dp[0][0] == -1) {
            return {0, 0};
        }

        return {dp[0][0], ways[0][0]};
    }
};