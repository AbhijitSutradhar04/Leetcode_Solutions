class Solution:
    def shiftGrid(self, grid: List[List[int]], k: int) -> List[List[int]]:
        m = len(grid)
        n = len(grid[0])
        
        k %= m * n
        
        arr = []
        for row in grid:
            arr.extend(row)
        
        arr = arr[-k:] + arr[:-k]
        
        return [arr[i*n:(i+1)*n] for i in range(m)]