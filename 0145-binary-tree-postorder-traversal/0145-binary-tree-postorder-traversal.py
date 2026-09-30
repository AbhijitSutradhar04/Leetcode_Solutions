class Solution:
    def postorderTraversal(self, root: TreeNode | None) -> list[int]:
        
        ans = []

        def dfs(node):
            if not node:
                return
            
            # Left subtree
            dfs(node.left)
            
            # Right subtree
            dfs(node.right)
            
            # Root
            ans.append(node.val)

        dfs(root)

        return ans