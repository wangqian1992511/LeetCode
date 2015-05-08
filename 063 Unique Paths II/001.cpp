class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
            int m = obstacleGrid.size();
            if (!m) return 0;
            int n = obstacleGrid[0].size();
            if (!n) return 0;
            if (obstacleGrid[0][0] || obstacleGrid[m-1][n-1]) return 0;

            int* c[2];
            bool ans = false;
            c[0] = new int [n + 1];
            c[1] = new int [n + 1];
            for (int i = 0; i <= n; i++)
                c[0][i] = c[1][i] = 0;
            c[ans][1] = 1;
            
            for (int i = 0; i < m; i++) {
                ans = !ans;
                for (int j = 1; j <= n; j++)
                    if (!obstacleGrid[i][j-1])
                        c[ans][j] = c[ans][j - 1] + c[!ans][j];
                    else
                        c[ans][j] = 0;
            }
                    
            return c[ans][n];
    }
};