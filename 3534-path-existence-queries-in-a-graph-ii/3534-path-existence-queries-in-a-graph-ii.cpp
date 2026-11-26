class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        // 1. Sort node indices by their values in nums
        vector<int> order(n);
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&](int a, int b) {
            return nums[a] < nums[b];
        });

        // Map each original node ID to its position in the sorted array
        vector<int> pos(n);
        for (int i = 0; i < n; ++i) {
            pos[order[i]] = i;
        }

        // 2. Two-pointer sweep to find farthest index reachable in 1 hop (2^0)
        int maxLog = 0;
        while ((1 << maxLog) <= n) ++maxLog;

        vector<vector<int>> up(maxLog, vector<int>(n));
        int right = 0;
        for (int left = 0; left < n; ++left) {
            while (right + 1 < n && nums[order[right + 1]] - nums[order[left]] <= maxDiff) {
                ++right;
            }
            up[0][left] = right;
        }

        // 3. Build the Binary Lifting table: up[k][i] = farthest index in 2^k hops
        for (int k = 1; k < maxLog; ++k) {
            for (int i = 0; i < n; ++i) {
                up[k][i] = up[k - 1][up[k - 1][i]];
            }
        }

        // 4. Answer each query in O(log n) time
        vector<int> ans;
        ans.reserve(queries.size());

        for (const auto& q : queries) {
            int u = pos[q[0]];
            int v = pos[q[1]];

            if (u == v) {
                ans.push_back(0);
                continue;
            }
            if (u > v) swap(u, v); // Always jump left-to-right

            // Greedily take the largest power-of-2 jumps that stay strictly before v
            int hops = 0;
            for (int k = maxLog - 1; k >= 0; --k) {
                if (up[k][u] < v) {
                    u = up[k][u];
                    hops += (1 << k);
                }
            }

            // Check if one final single hop reaches or passes v
            if (up[0][u] >= v) {
                ans.push_back(hops + 1);
            } else {
                ans.push_back(-1);
            }
        }

        return ans;
    }
};
