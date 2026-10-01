class Solution:
    def numIdenticalPairs(self, nums: list[int]) -> int:
        count = {}
        ans = 0

        for x in nums:
            if x in count:
                ans += count[x]
            count[x] = count.get(x, 0) + 1

        return ans