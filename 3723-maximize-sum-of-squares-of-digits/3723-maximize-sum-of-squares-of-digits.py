class Solution:
    def maxSumOfSquares(self, num: int, sum: int) -> str:
        if sum > 9 * num:
            return ""

        digits = [0] * num

        for i in range(num):
            digits[i] = min(9, sum)
            sum -= digits[i]

        if sum > 0:
            return ""

        return ''.join(map(str, digits))