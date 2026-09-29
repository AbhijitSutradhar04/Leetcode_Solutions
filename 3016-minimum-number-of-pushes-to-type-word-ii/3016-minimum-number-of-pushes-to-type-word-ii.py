class Solution:
    def minimumPushes(self, word: str) -> int:
        freq = [0] * 26

        for ch in word:
            freq[ord(ch) - ord('a')] += 1

        freq.sort(reverse=True)

        ans = 0

        for i, f in enumerate(freq):
            if i < 8:
                cost = 1
            elif i < 16:
                cost = 2
            elif i < 24:
                cost = 3
            else:
                cost = 4

            ans += f * cost

        return ans