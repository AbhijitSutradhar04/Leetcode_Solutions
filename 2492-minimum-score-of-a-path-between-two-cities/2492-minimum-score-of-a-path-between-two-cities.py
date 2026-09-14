class Solution:
    def minScore(self, n: int, roads: List[List[int]]) -> int:

        graph = [[] for _ in range(n + 1)]

        # Build graph
        for a, b, d in roads:
            graph[a].append((b, d))
            graph[b].append((a, d))

        visited = set()
        ans = float('inf')

        def dfs(city):
            nonlocal ans

            visited.add(city)

            for nxt, dist in graph[city]:

                # update minimum road distance
                ans = min(ans, dist)

                if nxt not in visited:
                    dfs(nxt)

        dfs(1)

        return ans