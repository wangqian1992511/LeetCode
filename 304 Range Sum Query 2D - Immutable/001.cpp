class NumMatrix {
public:
    NumMatrix(vector<vector<int>> &matrix) {
        int n = matrix.size();
        if (!n) return;
        int m = matrix[0].size();
        sum = new int* [n];
        for (int i = 0; i < n; i++) {
            sum[i] = new int [m];
            for (int j = 0; j < m; j++)
            sum[i][j] = matrix[i][j] + getSum(i - 1, j) + getSum(i, j - 1) - getSum(i - 1, j - 1);
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return getSum(row2, col2) + getSum(row1 - 1, col1 - 1) -
        getSum(row1 - 1, col2) - getSum(row2, col1 - 1);
    }
private:
    int **sum;
    int getSum(int i, int j) {
        if (i < 0 || j < 0)
        return 0;
        return sum[i][j];
    }
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);