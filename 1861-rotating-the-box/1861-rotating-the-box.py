class Solution:
    def rotateTheBox(self, boxGrid: List[List[str]]) -> List[List[str]]:
        m = len(boxGrid)
        n = len(boxGrid[0])

        # Apply gravity to each row
        for i in range(m):
            empty = n - 1

            for j in range(n - 1, -1, -1):
                if boxGrid[i][j] == '*':
                    empty = j - 1

                elif boxGrid[i][j] == '#':
                    boxGrid[i][j] = '.'
                    boxGrid[i][empty] = '#'
                    empty -= 1

        # Rotate 90 degrees clockwise
        ans = [['.' for _ in range(m)] for _ in range(n)]

        for i in range(m):
            for j in range(n):
                ans[j][m - 1 - i] = boxGrid[i][j]

        return ans