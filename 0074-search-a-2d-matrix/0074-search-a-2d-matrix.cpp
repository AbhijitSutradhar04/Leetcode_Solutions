class Solution {
public:
    bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        // Imagine the 2D matrix is flattened into a 1D array of size m * n
        int left = 0;
        int right = (m * n) - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            // Map the 1D index back to 2D coordinates
            int row = mid / n;
            int col = mid % n;
            
            int current_val = matrix[row][col];
            
            if (current_val == target) {
                return true;
            } else if (current_val < target) {
                left = mid + 1; 
            } else {
                right = mid - 1; 
            }
        }
        
        return false;
    }
};