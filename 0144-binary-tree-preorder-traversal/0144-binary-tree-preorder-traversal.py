class Solution:
    def preorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        
        ans = []

        def dfs(node):
            if not node:
                return
            
            # Root
            ans.append(node.val)
            
            # Left
            dfs(node.left)
            
            # Right
            dfs(node.right)

        dfs(root)

        return ans