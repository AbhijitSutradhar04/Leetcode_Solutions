class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mini = *min_element(nums.begin(), nums.end());

        long long sum = 0;

        for (int x : nums) {
            sum += x - mini;
        }

        return (int)sum;
    }
};