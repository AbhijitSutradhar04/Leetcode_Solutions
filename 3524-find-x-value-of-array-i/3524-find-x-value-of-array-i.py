class Solution:
    def resultArray(self, nums: List[int], k: int) -> List[int]:
        ans = [0] * k
        
        # dp[r] = number of subarrays ending at previous index
        # whose product % k == r
        dp = [0] * k
        
        for num in nums:
            new_dp = [0] * k
            
            # Start a new subarray with only num
            new_dp[num % k] += 1
            
            # Extend previous subarrays
            for r in range(k):
                if dp[r]:
                    new_dp[(r * num) % k] += dp[r]
            
            # Add all subarrays ending here to the answer
            for r in range(k):
                ans[r] += new_dp[r]
            
            dp = new_dp
        
        return ans