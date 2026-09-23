class Solution:
    def minOperations(self, nums: List[int], x: int) -> int:
        total = sum(nums)
        target = total - x
        
        # If we need the whole array removed
        if target == 0:
            return len(nums)
        
        left = 0
        curr = 0
        max_len = -1
        
        for right in range(len(nums)):
            curr += nums[right]
            
            while curr > target and left <= right:
                curr -= nums[left]
                left += 1
            
            if curr == target:
                max_len = max(max_len, right - left + 1)
        
        if max_len == -1:
            return -1
        
        return len(nums) - max_len