class Solution:
    def subsetXORSum(self, nums: list[int]) -> int:
        ans = 0

        for x in nums:
            ans |= x

        return ans << (len(nums) - 1)