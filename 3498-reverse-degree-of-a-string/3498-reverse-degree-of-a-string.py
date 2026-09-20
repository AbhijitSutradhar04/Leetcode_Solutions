class Solution:
    def reverseDegree(self, s: str) -> int:
        ans = 0

        for i, ch in enumerate(s):
            # reverse alphabet position
            value = 26 - (ord(ch) - ord('a'))

            # 1-indexed position
            ans += value * (i + 1)

        return ans