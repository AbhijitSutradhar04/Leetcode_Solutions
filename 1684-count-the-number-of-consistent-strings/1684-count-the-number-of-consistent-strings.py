class Solution:
    def countConsistentStrings(self, allowed: str, words: List[str]) -> int:
        allowed = set(allowed)
        count = 0

        for word in words:
            if all(ch in allowed for ch in word):
                count += 1

        return count