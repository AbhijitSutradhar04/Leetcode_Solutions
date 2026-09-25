class Solution:
    def sumOfLeftLeaves(self, root: Optional[TreeNode]) -> int:
        
        if not root:
            return 0
        
        ans = 0
        
        # Check left child
        if root.left:
            if root.left.left is None and root.left.right is None:
                ans += root.left.val
            else:
                ans += self.sumOfLeftLeaves(root.left)
        
        # Check right subtree
        ans += self.sumOfLeftLeaves(root.right)
        
        return ans