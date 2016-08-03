class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        n = matrix.size();
        if (!n) return 0;
        len = new int* [n];
        deg = new int* [n];

        m = matrix[0].size();
        if (!m) return 0;
        for (int i = 0; i < n; i++) {
            len[i] = new int [m];
            deg[i] = new int [m];
            fill(len[i], len[i] + m, 1);
            fill(deg[i], deg[i] + m, 0);
        }


        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, 1, -1};
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                for (int k = 0; k < 4; k++) {
                    int x = i + dx[k];
                    int y = j + dy[k];
                    if (isValid(x, y) && (matrix[i][j] > matrix[x][y]))
                        deg[i][j]++;
                }
                if (!deg[i][j])
                    q.push({i, j});
            }

        ans = 0;
        while (!q.empty()) {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            ans = max(ans, len[i][j]);
            for (int k = 0; k < 4; k++) {
                int x = i + dx[k];
                int y = j + dy[k];
                if (isValid(x, y) && (matrix[i][j] < matrix[x][y])) {
                    deg[x][y]--;
                    len[x][y] = max(len[x][y], len[i][j] + 1);
                    if (!deg[x][y])
                        q.push({x, y});
                }
            }
        }

        return ans;
    }
private:
    queue<pair<int, int>> q;
    int **len, **deg, n, m, ans;

    bool isValid(int x, int y) {
        if (x < 0) return false;
        if (y < 0) return false;
        if (x >= n) return false;
        if (y >= m) return false;
        return true;
    }
};
