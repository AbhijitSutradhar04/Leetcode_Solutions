class Solution:
    def maxRotateFunction(self, nums: List[int]) -> int:
        n = len(nums)

        total = sum(nums)

        # Calculate F(0)
        curr = 0
        for i in range(n):
            curr += i * nums[i]

        ans = curr

        # Calculate F(1)...F(n-1)
        for k in range(1, n):
            curr = curr + total - n * nums[n - k]
            ans = max(ans, curr)

        return ans