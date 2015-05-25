class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        int n = grid.size();
        if (!n) return 0;
        int m = grid[0].size();
        if (!m) return 0;
        
        int *dp[2];
        dp[0] = new int [m];
        dp[1] = new int [m];
        for (int j = 0; j < m; j++)
            dp[0][j] = dp[1][j] = INT_MAX;
            
        bool ansP = false;
        dp[0][0] = grid[0][0];
        for (int j = 1; j < m; j++)
            dp[0][j] = dp[0][j-1] + grid[0][j];
        
        for (int i = 1; i < n; i++) {
            ansP = !ansP;
            dp[ansP][0] = dp[!ansP][0] + grid[i][0];
            for (int j = 1; j < m; j++)
                dp[ansP][j] = min(dp[ansP][j-1], dp[!ansP][j]) + grid[i][j];
        }
        return dp[ansP][m-1];
    }
};
