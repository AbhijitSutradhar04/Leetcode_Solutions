class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        // Assign a connected component ID to each node
        vector<int> comp(n, 0);
        int currentComp = 0;
        
        for (int i = 1; i < n; ++i) {
            // Since nums is sorted, a gap > maxDiff breaks connectivity
            if (nums[i] - nums[i - 1] > maxDiff) {
                ++currentComp;
            }
            comp[i] = currentComp;
        }
        
        // Answer each query in O(1) time
        vector<bool> ans;
        ans.reserve(queries.size());
        
        for (const auto& q : queries) {
            ans.push_back(comp[q[0]] == comp[q[1]]);
        }
        
        return ans;
    }
};
