class Solution {
public:
    int numSquares(int n) {
        dp = new int [n + 1];
        fill(dp, dp + n + 1, INT_MAX - 1);
        dp[0] = 0;
        return get(n);
    }
private:
    int *dp;
    int get(int n) {
        if (dp[n] != INT_MAX - 1)
            return dp[n];
        int x = 1;
        while (x <= n / x) {
            dp[n] = min(dp[n], get(n - x * x) + 1);
            x++;
        }
        return dp[n];
    }
};
