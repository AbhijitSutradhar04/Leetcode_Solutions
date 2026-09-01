class Solution:
    def findValidElements(self, nums: List[int]) -> List[int]:
        ans = []

        for i in range(len(nums)):
            if nums[i] > max(nums[:i], default=-float('inf')) or \
               nums[i] > max(nums[i+1:], default=-float('inf')):
                ans.append(nums[i])

        return ans