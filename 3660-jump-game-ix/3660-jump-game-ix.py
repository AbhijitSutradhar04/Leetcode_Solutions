class Solution:
    def maxValue(self, nums: List[int]) -> List[int]:
        n = len(nums)

        ans = [0] * n

        # Maximum value from 0 to i
        pre_max = [nums[0]] * n
        for i in range(1, n):
            pre_max[i] = max(pre_max[i - 1], nums[i])

        # Minimum value to the right
        suf_min = float('inf')

        # Process from right to left
        for i in range(n - 1, -1, -1):
            if i == n - 1:
                ans[i] = pre_max[i]
            elif pre_max[i] > suf_min:
                ans[i] = ans[i + 1]
            else:
                ans[i] = pre_max[i]

            suf_min = min(suf_min, nums[i])

        return ans