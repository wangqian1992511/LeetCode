class NumMatrix {
public:
    NumMatrix(vector<vector<int>> &matrix) {
        n = matrix.size();
        if (!n) return;
        m = matrix[0].size();
        data = new int* [n];
        c = new int* [n + 1];
        for (int i = 0; i < n; i++) {
            data[i] = new int [m];
            c[i] = new int [m + 1];
            fill(c[i], c[i] + m + 1, 0);
        }
        c[n] = new int [m + 1];
        fill(c[n], c[n] + m + 1, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                data[i][j] = matrix[i][j];
                add(i + 1, j + 1, data[i][j]);
            }
        }
    }
    
    void update(int row, int col, int val) {
        int delta = val - data[row][col];
        data[row][col] = val;
        add(row + 1, col + 1, delta);
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return sum(row2 + 1, col2 + 1) -
        sum(row2 + 1, col1) +
        sum(row1, col1) -
        sum(row1, col2 + 1);
    }
private:
    int **data, **c;
    int n, m;
    int lowbit(int x) {
        return x & -x;
    }
    void add(int x, int y, int delta) {
        while (x <= n) {
            int t = y;
            while (t <= m) {
                c[x][t] += delta;
                t += lowbit(t);
            }
            x += lowbit(x);
        }
    }
    int sum(int x, int y) {
        int ans = 0;
        while (x) {
            int t = y;
            while (t) {
                ans += c[x][t];
                t -= lowbit(t);
            }
            x -= lowbit(x);
        }
        return ans;
    }
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.update(1, 1, 10);
// numMatrix.sumRegion(1, 2, 3, 4);