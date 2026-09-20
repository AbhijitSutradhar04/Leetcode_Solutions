class Solution:
    def minDepth(self, root: Optional[TreeNode]) -> int:

        if root is None:
            return 0

        # If left child is missing
        if root.left is None:
            return self.minDepth(root.right) + 1

        # If right child is missing
        if root.right is None:
            return self.minDepth(root.left) + 1

        # Both children exist
        return min(self.minDepth(root.left),
                   self.minDepth(root.right)) + 1