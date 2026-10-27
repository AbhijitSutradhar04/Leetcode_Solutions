class Solution {
public:
    std::vector<std::string> createGrid(int m, int n) {
        // Initialize an m x n grid filled entirely with obstacles ('#')
        std::vector<std::string> grid(m, std::string(n, '#'));
        
        // 1. Open up the entire first row (row 0)
        grid[0] = std::string(n, '.');
        
        // 2. Open up the entire last column (column n - 1)
        for (int i = 0; i < m; ++i) {
            grid[i][n - 1] = '.';
        }
        
        return grid;
    }
};
