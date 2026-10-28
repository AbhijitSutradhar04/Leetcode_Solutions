class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        const int X = 1024;

        vector<vector<bitset<X>>> dp(m, vector<bitset<X>>(n));
        dp[0][0].set(grid[0][0]);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) continue;

                auto update = [&](const bitset<X>& prev) {
                    for (int x = 0; x < X; x++) {
                        if (prev[x])
                            dp[i][j].set(x ^ grid[i][j]);
                    }
                };

                if (i > 0) update(dp[i - 1][j]);
                if (j > 0) update(dp[i][j - 1]);
            }
        }

        for (int x = 0; x < X; x++) {
            if (dp[m - 1][n - 1][x])
                return x;
        }

        return 0;
    }
};