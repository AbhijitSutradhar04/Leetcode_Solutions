class Solution:
    def minSumOfLengths(self, arr: List[int], target: int) -> int:
        n = len(arr)

        # best[i] = minimum length subarray with target sum ending at or before i
        best = [float('inf')] * n

        prefix = 0
        seen = {0: -1}

        min_len = float('inf')
        ans = float('inf')

        for i in range(n):
            prefix += arr[i]

            # Check if subarray with target sum exists
            if prefix - target in seen:
                start = seen[prefix - target]
                length = i - start

                # Combine with previous best before this subarray
                if start >= 0 and best[start] != float('inf'):
                    ans = min(ans, length + best[start])

                min_len = min(min_len, length)

            # Store best length up to current index
            if i > 0:
                best[i] = min(best[i-1], min_len)
            else:
                best[i] = min_len

            seen[prefix] = i

        return -1 if ans == float('inf') else ans