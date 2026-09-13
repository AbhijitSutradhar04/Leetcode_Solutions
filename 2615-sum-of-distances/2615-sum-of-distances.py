class Solution:
    def distance(self, nums: List[int]) -> List[int]:
        d = {}
        ans = [0] * len(nums)

        for i, x in enumerate(nums):
            if x not in d:
                d[x] = [0, 0]

            count, total = d[x]
            ans[i] += i * count - total

            d[x][0] += 1
            d[x][1] += i

        d.clear()

        for i in range(len(nums) - 1, -1, -1):
            x = nums[i]

            if x not in d:
                d[x] = [0, 0]

            count, total = d[x]
            ans[i] += total - i * count

            d[x][0] += 1
            d[x][1] += i

        return ans