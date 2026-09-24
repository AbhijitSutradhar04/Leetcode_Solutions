class Solution:
    def smallestIndex(self, nums: List[int]) -> int:
        
        def digit_sum(n):
            s = 0
            while n > 0:
                s += n % 10
                n //= 10
            return s
        
        for i, num in enumerate(nums):
            if digit_sum(num) == i:
                return i
        
        return -1