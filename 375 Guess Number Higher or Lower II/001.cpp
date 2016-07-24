class Solution {
public:
    int getMoneyAmount(int n) {
        int **dp = new int* [n + 2];
        for (int i = 0; i <= n; i++)
            dp[i] = new int [n + 2];

        for (int i = n; i >= 1; i--) {
            dp[i][i] = 0;
            dp[i][i + 1] = i;
            for (int j = i + 2; j <= n; j++) {
                dp[i][j] = min(i + dp[i + 1][j], dp[i][j - 1] + j);
                for (int k = i + 1; k < j; k++)
                    dp[i][j] = min(dp[i][j], k + max(dp[i][k - 1], dp[k + 1][j]));
            }
        }

        return dp[1][n];
    }
};
