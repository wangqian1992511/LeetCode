class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        int ans = 0;
        int n = grid.size();
        if (!n)
            return 0;
        int m = grid[0].size();
        if (!m)
            return 0;

        int** tot = new int* [n];
        for (int i = 0; i < n; i++) {
            tot[i] = new int [m];
            fill(tot[i], tot[i] + m, 0);
            int p = 0, q, k;
            while (p < m) {
                while ((p < m) && (grid[i][p] == 'W'))
                    p++;
                q = p;
                k = 0;
                while ((q < m) && (grid[i][q] != 'W')) {
                    k += (grid[i][q] == 'E');
                    q++;
                }
                while (p < q) {
                    if (grid[i][p] != 'E')
                        tot[i][p] += k;
                    p++;
                }
            }
        }

        for (int j = 0; j < m; j++) {
            int p = 0, q, k;
            while (p < n) {
                while ((p < n) && (grid[p][j] == 'W'))
                    p++;
                q = p;
                k = 0;
                while ((q < n) && (grid[q][j] != 'W')) {
                    k += (grid[q][j] == 'E');
                    q++;
                }
                while (p < q) {
                    if (grid[p][j] != 'E')
                        tot[p][j] += k;
                    ans = max(ans, tot[p][j]);
                    p++;
                }
            }
        }

        return ans;
    }
};
