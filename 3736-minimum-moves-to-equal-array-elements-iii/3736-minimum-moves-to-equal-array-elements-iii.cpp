class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mx = *max_element(nums.begin(), nums.end());
        int ans = 0;

        for (int num : nums) {
            ans += mx - num;
        }

        return ans;
    }
};