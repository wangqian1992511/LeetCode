class Solution {
public:
    void rotate(vector<vector<int>> &matrix) {
        int n = matrix.size();
        for (int i = 0; i < n / 2; i++)
            for (int j = 0; j < (n + 1) / 2; j++) {
                int x = i, y = j, tmp = matrix[i][j];
                int nx, ny, nt;
                for (int k = 0; k < 4; k++) {
                    nx = y;
                    ny = n - 1 - x;
                    nt = matrix[nx][ny];
                    matrix[nx][ny] = tmp;
                    tmp = nt;
                    x = nx;
                    y = ny;
                }
            }
    }
};