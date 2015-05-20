class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++) {
            vector<int> tmp;
            for (int j = 0; j < n; j++)
                tmp.push_back(0);
            ans.push_back(tmp);
        }
        int t = 1, x = 0, y = -1, k = 0, s = n * n;
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};
        while (t <= s) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            while ((nx < 0) || (ny < 0) || (nx >= n) || (ny >= n) || ans[nx][ny]) {
                k++;
                k &= 3;
                nx = x + dx[k];
                ny = y + dy[k];
            }
            ans[x = nx][y = ny] = t++;
        }
        return ans;
    }
};