from math import gcd

class Solution:
    def gcdSum(self, nums: list[int]) -> int:
        prefixGcd = []
        mx = 0

        for x in nums:
            mx = max(mx, x)
            prefixGcd.append(gcd(x, mx))

        prefixGcd.sort()

        ans = 0
        left = 0
        right = len(prefixGcd) - 1

        while left < right:
            ans += gcd(prefixGcd[left], prefixGcd[right])
            left += 1
            right -= 1

        return ans