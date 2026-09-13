class Solution:
    def countCompleteComponents(self, n: int, edges: List[List[int]]) -> int:
        graph = [[] for _ in range(n)]

        for u, v in edges:
            graph[u].append(v)
            graph[v].append(u)

        visited = [False] * n
        ans = 0

        for i in range(n):
            if not visited[i]:
                stack = [i]
                visited[i] = True
                nodes = 0
                edge_count = 0

                while stack:
                    u = stack.pop()
                    nodes += 1
                    edge_count += len(graph[u])

                    for v in graph[u]:
                        if not visited[v]:
                            visited[v] = True
                            stack.append(v)

                edge_count //= 2

                if edge_count == nodes * (nodes - 1) // 2:
                    ans += 1

        return ans