class Solution {
public:
    int integerBreak(int n) {
        int *dp = new int [n + 1];
        dp[1] = 1;
        for (int k = 2; k <= n; k++) {
            dp[k] = 1;
            for (int i = 1; i <= k / 2; i++)
                dp[k] = max(dp[k], max(i, dp[i]) * max(k - i, dp[k - i]));
        }
        return dp[n];
    }
};