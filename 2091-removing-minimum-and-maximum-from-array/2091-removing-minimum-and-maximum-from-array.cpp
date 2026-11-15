class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int minIdx = 0;
        int maxIdx = 0;
        
        // Locate the indices of the minimum and maximum elements
        for (int i = 1; i < n; ++i) {
            if (nums[i] < nums[minIdx]) minIdx = i;
            if (nums[i] > nums[maxIdx]) maxIdx = i;
        }
        
        // Order the indices so 'left' is closer to the front and 'right' is closer to the back
        int left = min(minIdx, maxIdx);
        int right = max(minIdx, maxIdx);
        
        // Calculate the 3 possible removal strategies
        int deleteFromFront = right + 1;
        int deleteFromBack = n - left;
        int deleteFromBothEnds = (left + 1) + (n - right);
        
        return min({deleteFromFront, deleteFromBack, deleteFromBothEnds});
    }
};