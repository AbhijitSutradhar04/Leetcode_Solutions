
class Solution:
    def removeOuterParentheses(self, s: str) -> str:
        ans = ""
        count = 0

        for ch in s:
            if ch == '(':
                if count > 0:
                    ans += ch
                count += 1
            else:
                count -= 1
                if count > 0:
                    ans += ch

        return ans
