class Solution:
    def countCommas(self, n: int) -> int:
        ans = 0

        # Numbers with at least 4 digits
        if n >= 1000:
            ans += n - 1000 + 1

        # Numbers with at least 7 digits
        if n >= 1000000:
            ans += n - 1000000 + 1

        # Numbers with at least 10 digits
        if n >= 1000000000:
            ans += n - 1000000000 + 1

        return ans