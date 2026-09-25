class Solution:
    def braceExpansionII(self, expression: str) -> List[str]:

        def union(a, b):
            return a | b

        def multiply(a, b):
            res = set()
            for x in a:
                for y in b:
                    res.add(x + y)
            return res

        def dfs(i):
            curr = {""}
            ans = set()

            while i < len(expression) and expression[i] != '}':
                
                if expression[i] == '{':
                    temp, i = dfs(i + 1)
                
                else:
                    temp = {expression[i]}
                    i += 1

                # concatenate current part
                curr = multiply(curr, temp)

                # union after comma
                if i < len(expression) and expression[i] == ',':
                    ans |= curr
                    curr = {""}
                    i += 1

            ans |= curr

            return ans, i + 1

        return sorted(dfs(0)[0])