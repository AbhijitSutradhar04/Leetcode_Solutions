class Solution:
    def minBitFlips(self, start: int, goal: int) -> int:
        x = start ^ goal
        return x.bit_count()