class Solution:
    def mapWordWeights(self, words: List[str], weights: List[int]) -> str:
        ans = ""

        for word in words:
            total = 0

            # calculate word weight
            for ch in word:
                total += weights[ord(ch) - ord('a')]

            # reverse alphabet mapping
            idx = total % 26
            ans += chr(ord('z') - idx)

        return ans