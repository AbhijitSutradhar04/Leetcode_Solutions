class Solution:
    def findTheDifference(self, s: str, t: str) -> str:
        ans = 0
        
        for ch in s + t:
            ans ^= ord(ch)
        
        return chr(ans)