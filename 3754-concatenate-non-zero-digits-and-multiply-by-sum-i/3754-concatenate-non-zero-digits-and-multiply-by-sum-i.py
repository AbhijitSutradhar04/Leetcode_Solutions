class Solution:
    def sumAndMultiply(self, n: int) -> int:
        # Get non-zero digits
        digits = ""
        
        for ch in str(n):
            if ch != '0':
                digits += ch
        
        # If no non-zero digits
        if digits == "":
            return 0
        
        # Convert x
        x = int(digits)
        
        # Sum of digits
        total = sum(int(c) for c in digits)
        
        return x * total