class Solution:
    def firstStableIndex(self, nums: List[int], k: int) -> int:
        n = len(nums)

        for i in range(n):
            left_max = max(nums[:i + 1])
            right_min = min(nums[i:])

            if left_max - right_min <= k:
                return i

        return -1