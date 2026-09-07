class Solution:
    def distinctSubseqII(self, s: str) -> int:
        MOD = 10**9 + 7

        n = len(s)
        dp = [0] * (n + 1)

        # dp[i] = number of distinct non-empty subsequences
        # using the first i characters
        dp[0] = 0

        last = {}

        for i in range(1, n + 1):
            ch = s[i - 1]

            # Add the new character to:
            # - every existing subsequence
            # - the empty subsequence -> creates ch
            dp[i] = (2 * dp[i - 1] + 1) % MOD

            # Remove duplicates caused by previous occurrence
            if ch in last:
                dp[i] = (dp[i] - dp[last[ch] - 1] - 1) % MOD

            last[ch] = i

        return dp[n]