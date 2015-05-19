class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int n = matrix.size();
        if (!n) return ans;
        int m = matrix[0].size();
        if (!m) return ans;
        bool **vis = new bool* [n];
        for (int i = 0; i < n; i++) {
            vis[i] = new bool [m];
            for (int j = 0; j < m; j++)
                vis[i][j] = false;
        }
        int x = 0, y = -1, t = n * m, k = 0;
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};
        for (int i = 0; i < t; i++) {
            int nx = x + dx[k], ny = y + dy[k];
            while ((nx < 0) || (ny < 0) || (nx >= n) || (ny >= m) || (vis[nx][ny])) {
                k++;
                k &= 3;
                nx = x + dx[k];
                ny = y + dy[k];
            }
            ans.push_back(matrix[x = nx][y = ny]);
            vis[x][y] = true;
        }
        return ans;
    }
};