class Solution:
    def isGood(self, nums: List[int]) -> bool:

        n = max(nums)

        # length should be n+1
        if len(nums) != n + 1:
            return False

        count = [0] * (n + 1)

        for x in nums:
            if x > n:
                return False
            count[x] += 1

        # Check 1 to n-1 occur once
        for i in range(1, n):
            if count[i] != 1:
                return False

        # n should occur twice
        if count[n] != 2:
            return False

        return True