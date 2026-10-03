class Solution:
    def longestValidParentheses(self, s: str) -> int:
        res = left = right = 0

        for ch in s:
            if ch == '(':
                left += 1
            else:
                right += 1
            if left == right:
                res = max(res, 2 * right)
            elif right > left:
                left = right = 0

        left = right = 0
        for ch in reversed(s):
            if ch == ')':
                right += 1
            else:
                left += 1
            if left == right:
                res = max(res, 2 * left)
            elif left > right:
                left = right = 0

        return res
