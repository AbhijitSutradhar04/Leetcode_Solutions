class Solution:
    def remainingMethods(self, n: int, k: int, invocations: List[List[int]]) -> List[int]:
        graph = [[] for _ in range(n)]

        for a, b in invocations:
            graph[a].append(b)

        suspicious = set()
        stack = [k]

        while stack:
            method = stack.pop()

            if method in suspicious:
                continue

            suspicious.add(method)

            for nxt in graph[method]:
                if nxt not in suspicious:
                    stack.append(nxt)

        # Check if any non-suspicious method calls a suspicious method
        for a, b in invocations:
            if a not in suspicious and b in suspicious:
                return list(range(n))

        return [i for i in range(n) if i not in suspicious]