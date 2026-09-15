class Solution:
    def minOperations(self, grid: List[List[int]], x: int) -> int:
        nums = []

        # Flatten grid
        for row in grid:
            for val in row:
                nums.append(val)

        # Check possibility
        rem = nums[0] % x
        for num in nums:
            if num % x != rem:
                return -1

        # Median minimizes operations
        nums.sort()
        median = nums[len(nums) // 2]

        ans = 0

        for num in nums:
            ans += abs(num - median) // x

        return ans