class Solution:
    def sumGame(self, num: str) -> bool:
        n = len(num)

        left_sum = 0
        right_sum = 0
        left_q = 0
        right_q = 0

        for i in range(n // 2):
            if num[i] == '?':
                left_q += 1
            else:
                left_sum += int(num[i])

        for i in range(n // 2, n):
            if num[i] == '?':
                right_q += 1
            else:
                right_sum += int(num[i])

        # Odd number of ? means Alice can always win
        if (left_q + right_q) % 2 == 1:
            return True

        # Bob can win only if sums can be made equal
        return (left_sum - right_sum) != 9 * (right_q - left_q) // 2