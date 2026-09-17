class Solution:
    def separateDigits(self, nums: List[int]) -> List[int]:
        ans = []

        for num in nums:
            digits = str(num)

            for d in digits:
                ans.append(int(d))

        return ans