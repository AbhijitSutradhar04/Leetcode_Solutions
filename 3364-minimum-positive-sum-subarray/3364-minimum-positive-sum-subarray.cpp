using namespace std;

class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int minSum = INT_MAX;
        int n = nums.size();

        // Check every valid subarray length from l to r
        for (int k = l; k <= r; ++k) {
            // Calculate the sum of the initial window of size k
            int currentSum = accumulate(nums.begin(), nums.begin() + k, 0);
            
            if (currentSum > 0) {
                minSum = min(minSum, currentSum);
            }

            // Slide the window across the rest of the array
            for (int i = k; i < n; ++i) {
                currentSum += nums[i] - nums[i - k];
                if (currentSum > 0) {
                    minSum = min(minSum, currentSum);
                }
            }
        }

        return (minSum == INT_MAX) ? -1 : minSum;
    }
};