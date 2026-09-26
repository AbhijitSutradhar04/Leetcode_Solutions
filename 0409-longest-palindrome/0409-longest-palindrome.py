class Solution:
    def longestPalindrome(self, s: str) -> int:
        count = {}
        
        # Count frequency of each character
        for ch in s:
            count[ch] = count.get(ch, 0) + 1
        
        length = 0
        odd = False
        
        # Use pairs
        for freq in count.values():
            length += (freq // 2) * 2
            
            if freq % 2 == 1:
                odd = True
        
        # One odd character can be placed in the center
        if odd:
            length += 1
        
        return length