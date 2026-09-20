class Solution:
    def hasPathSum(self, root: Optional[TreeNode], targetSum: int) -> bool:

        if root is None:
            return False

        # Check if leaf node
        if root.left is None and root.right is None:
            return targetSum == root.val

        # Check left and right subtree
        return (self.hasPathSum(root.left, targetSum - root.val) or
                self.hasPathSum(root.right, targetSum - root.val))