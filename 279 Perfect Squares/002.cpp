class Solution {
public:
    int numSquares(int n) {
        int *dp = new int [n + 1];
        fill(dp, dp + n + 1, INT_MAX - 1);
        dp[0] = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= sqrt(i + 0.1); j++)
                dp[i] = min(dp[i], dp[i - j * j] + 1);
        return dp[n];
    }
};