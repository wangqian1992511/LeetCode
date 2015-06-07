class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        if (!n) return 0;
        int m = matrix[0].size();
        if (!m) return 0;
        int ans = 0;
        
        int **dp = new int* [n];
        int **len = new int* [n];
        int ** height = new int* [n];
        for (int i = 0; i < n; i++) {
            dp[i] = new int [m];
            len[i] = new int [m];
            height[i] = new int [m];
        }
        
        for (int i = 0; i < n; i++) {
            len[i][0] = (matrix[i][0] == '1');
            dp[i][0] = len[i][0];
            ans = max(ans, dp[i][0]);
            for (int j = 1; j < m; j++)
                if (matrix[i][j] == '1')
                    len[i][j] = len[i][j-1] + 1;
                else
                    len[i][j] = 0;
        }
        
        for (int j = 0; j < m; j++) {
            height[0][j] = (matrix[0][j] == '1');
            dp[0][j] = height[0][j];
            ans = max(ans, dp[0][j]);
            for (int i = 1; i < n; i++)
                if (matrix[i][j] == '1')
                    height[i][j] = height[i-1][j] + 1;
                else
                    height[i][j] = 0;
        }
        
        for (int i = 1; i < n; i++)
            for (int j = 1; j < m; j++) {
                dp[i][j] = min(dp[i-1][j-1] + 1, min(len[i][j], height[i][j]));
                ans = max(ans, dp[i][j]);
            }
        
        return ans * ans;
    }
};