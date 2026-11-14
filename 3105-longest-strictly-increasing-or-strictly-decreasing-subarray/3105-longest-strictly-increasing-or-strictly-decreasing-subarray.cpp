using namespace std;

class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int ans = 1; // Minimum possible subarray length is 1
        int inc = 1; // Tracks current strictly increasing subarray length
        int dec = 1; // Tracks current strictly decreasing subarray length

        for (size_t i = 1; i < nums.size(); ++i) {
            if (nums[i] > nums[i - 1]) {
                inc++;
                dec = 1; // Reset decreasing run
            } else if (nums[i] < nums[i - 1]) {
                dec++;
                inc = 1; // Reset increasing run
            } else {
                // Equal adjacent elements break strict monotonicity
                inc = 1;
                dec = 1;
            }
            ans = max({ans, inc, dec});
        }

        return ans;
    }
};