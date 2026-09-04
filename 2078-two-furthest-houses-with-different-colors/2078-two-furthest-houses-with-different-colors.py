class Solution:
    def maxDistance(self, colors: List[int]) -> int:
        n = len(colors)
        ans = 0

        # Compare first house with all houses
        for i in range(1, n):
            if colors[i] != colors[0]:
                ans = max(ans, i)

        # Compare last house with all houses
        for i in range(n - 1):
            if colors[i] != colors[n - 1]:
                ans = max(ans, n - 1 - i)

        return ans