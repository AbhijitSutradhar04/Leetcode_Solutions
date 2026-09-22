class Solution:
    def resultArray(self, nums, k):
        ans = [0] * k
        
        # dp[r] = number of subarrays ending at previous index
        # with product % k == r
        dp = [0] * k
        
        for num in nums:
            new_dp = [0] * k
            
            rem = num % k
            
            # Start new subarray containing only num
            new_dp[rem] += 1
            
            # Extend previous subarrays
            for r in range(k):
                if dp[r]:
                    new_rem = (r * rem) % k
                    new_dp[new_rem] += dp[r]
            
            # Add all subarrays ending here to final answer
            for r in range(k):
                ans[r] += new_dp[r]
            
            dp = new_dp
        
        return ans