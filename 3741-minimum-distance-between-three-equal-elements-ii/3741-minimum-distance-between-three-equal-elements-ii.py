class Solution:
    def minimumDistance(self, nums: List[int]) -> int:
        pos = {}
        ans = float('inf')

        for i, x in enumerate(nums):
            if x in pos and len(pos[x]) >= 2:
                ans = min(ans, 2 * (i - pos[x][-2]))

            pos.setdefault(x, []).append(i)

            if len(pos[x]) > 2:
                pos[x].pop(0)

        return -1 if ans == float('inf') else ans