class Solution:
    def maximumWeight(self, intervals: List[List[int]]) -> List[int]:
        n = len(intervals)

        # Add original index
        arr = [(l, r, w, i) for i, (l, r, w) in enumerate(intervals)]

        # Sort by ending position
        arr.sort(key=lambda x: x[1])

        ends = [x[1] for x in arr]

        # dp[k][i] = best result using first i intervals with at most k intervals
        dp = [[(0, ()) for _ in range(n + 1)] for _ in range(5)]

        import bisect

        for k in range(1, 5):
            for i in range(1, n + 1):
                # Don't choose current interval
                best_score, best_indices = dp[k][i - 1]

                l, r, w, idx = arr[i - 1]

                # Find last interval whose end < current start
                j = bisect.bisect_left(ends, l, 0, i - 1)

                prev_score, prev_indices = dp[k - 1][j]

                new_score = prev_score + w
                new_indices = tuple(sorted(prev_indices + (idx,)))

                # Choose better score
                if new_score > best_score:
                    best_score = new_score
                    best_indices = new_indices

                # If same score, choose lexicographically smaller indices
                elif new_score == best_score and new_indices < best_indices:
                    best_indices = new_indices

                dp[k][i] = (best_score, best_indices)

        return list(dp[4][n][1])