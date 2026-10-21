int diagonalSum(int** mat, int matSize, int* matColSize) {
    int sum = 0;
    int n = matSize;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j || (i + j) == (n - 1)) {
                sum += mat[i][j];
            }
        }
    }

    return sum;
}
