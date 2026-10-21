class Solution {
public:
    std::vector<std::vector<int>> matrixReshape(std::vector<std::vector<int>>& mat, int r, int c) {
        int m = mat.size();
        int n = mat[0].size();

        if (m * n != r * c) {
            return mat;
        }
        std::vector<std::vector<int>> reshaped(r, std::vector<int>(c, 0));

        for (int i = 0; i < m * n; i++) {
            int src_row = i / n;
            int src_col = i % n;

            int dest_row = i / c;
            int dest_col = i % c;

            reshaped[dest_row][dest_col] = mat[src_row][src_col];
        }
        return reshaped;
    }
};
