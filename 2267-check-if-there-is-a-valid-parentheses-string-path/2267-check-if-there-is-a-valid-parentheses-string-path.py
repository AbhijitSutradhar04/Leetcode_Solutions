class Solution:
    def hasValidPath(self, grid: list[list[str]]) -> bool:
        m, n = len(grid), len(grid[0])

        # Total length must be even
        if (m + n - 1) % 2 == 1:
            return False

        from functools import lru_cache

        @lru_cache(None)
        def dfs(i, j, balance):
            # Invalid balance
            if balance < 0:
                return False

            # Destination reached
            if i == m - 1 and j == n - 1:
                return balance == 0

            # Move Down
            if i + 1 < m:
                new_balance = balance + (1 if grid[i+1][j] == '(' else -1)
                if dfs(i + 1, j, new_balance):
                    return True

            # Move Right
            if j + 1 < n:
                new_balance = balance + (1 if grid[i][j+1] == '(' else -1)
                if dfs(i, j + 1, new_balance):
                    return True

            return False

        # Start with first cell
        start = 1 if grid[0][0] == '(' else -1

        return dfs(0, 0, start)