class Solution:
    def shortestBeautifulSubstring(self, s: str, k: int) -> str:
        n = len(s)

        count = 0
        left = 0
        ans = ""

        for right in range(n):
            if s[right] == '1':
                count += 1

            while count == k:
                curr = s[left:right + 1]

                if (ans == "" or 
                    len(curr) < len(ans) or 
                    (len(curr) == len(ans) and curr < ans)):
                    ans = curr

                if s[left] == '1':
                    count -= 1
                left += 1

        return ans