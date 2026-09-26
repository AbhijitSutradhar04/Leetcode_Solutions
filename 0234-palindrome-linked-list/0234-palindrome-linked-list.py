class Solution:
    def isPalindrome(self, head: ListNode | None) -> bool:
        # Store values of linked list
        vals = []
        
        while head:
            vals.append(head.val)
            head = head.next
        
        # Check palindrome
        return vals == vals[::-1]