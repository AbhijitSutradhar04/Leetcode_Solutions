using namespace std;

class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        vector<int> gain(n, 1); // Start with 1 (the purchased item itself)
        int min_price = 1e9;

        // 1. Precompute total items gained from the FIRST purchase of each item
        for (int i = 0; i < n; ++i) {
            min_price = min(min_price, items[i][1]);
            for (int j = 0; j < n; ++j) {
                if (i != j && items[j][0] % items[i][0] == 0) {
                    gain[i]++;
                }
            }
        }

        // 2. 0/1 Knapsack for buying at most 1 copy of each item
        vector<int> dp(budget + 1, 0);
        for (int i = 0; i < n; ++i) {
            int price = items[i][1];
            int val = gain[i];
            // Iterate backwards for 0/1 knapsack
            for (int b = budget; b >= price; --b) {
                dp[b] = max(dp[b], dp[b - price] + val);
            }
        }

        // 3. Spend any leftover budget on the cheapest item available
        int ans = 0;
        for (int b = 0; b <= budget; ++b) {
            int extra_copies = (budget - b) / min_price;
            ans = max(ans, dp[b] + extra_copies);
        }

        return ans;
    }
};