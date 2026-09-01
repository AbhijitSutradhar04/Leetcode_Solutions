class Solution:
    def findDegrees(self, matrix: List[List[int]]) -> List[int]:
        n = len(matrix)
        ans = []

        for i in range(n):
            ans.append(sum(matrix[i]))

        return ans