class Solution:
    def totalNQueens(self, n: int) -> int:
        mask = (1 << n) - 1

        def backtrack(cols, diag1, diag2):
            if cols == mask:
                return 1

            count = 0
            available = mask & ~(cols | diag1 | diag2)

            while available:
                pos = available & -available
                available -= pos

                count += backtrack(
                    cols | pos,
                    ((diag1 | pos) << 1) & mask,
                    (diag2 | pos) >> 1
                )

            return count

        return backtrack(0, 0, 0)