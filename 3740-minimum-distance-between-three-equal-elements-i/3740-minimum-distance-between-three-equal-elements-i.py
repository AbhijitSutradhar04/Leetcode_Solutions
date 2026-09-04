class Solution:
    def minimumDistance(self, nums: List[int]) -> int:
        pos = {}
        ans = float('inf')

        for i, x in enumerate(nums):
            if x in pos:
                pos[x].append(i)
            else:
                pos[x] = [i]

            if len(pos[x]) >= 3:
                ans = min(ans, 2 * (pos[x][-1] - pos[x][-3]))

        return -1 if ans == float('inf') else ans