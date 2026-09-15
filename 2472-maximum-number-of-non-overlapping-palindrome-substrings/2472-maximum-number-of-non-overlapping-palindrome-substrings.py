class Solution:
    def maxPalindromes(self, s: str, k: int) -> int:
        n = len(s)

        # palindrome check
        pal = [[False] * n for _ in range(n)]

        for i in range(n - 1, -1, -1):
            for j in range(i, n):
                if s[i] == s[j] and (j - i < 2 or pal[i+1][j-1]):
                    pal[i][j] = True

        ans = 0
        end = -1

        # scan by ending position
        for j in range(n):
            for i in range(j - k + 1, -1, -1):
                if pal[i][j] and i > end:
                    ans += 1
                    end = j
                    break

        return ans