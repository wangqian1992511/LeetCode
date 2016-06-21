class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        bool **f = new bool* [n];
        int *dp = new int [n];

        for (int i = 0; i < n; i++) {
            f[i] = new bool [n];
            f[i][i] = true;
            f[i][i+1] = (i != n-1) && (s[i] == s[i+1]);
        }
        for (int len = 3; len <= n; len++)
            for (int i = 0; i <= n - len; i++)
                f[i][i+len-1] = f[i+1][i+len-2] && (s[i] == s[i+len-1]);

        dp[0] = 0;
        for (int i = 1; i < n; i++) {
            if (f[0][i]) {
                dp[i] = 0;
                continue;
            }
            dp[i] = INT_MAX;
            for (int j = 0; j < i; j++)
                if (f[j + 1][i])
                    dp[i] = min(dp[i], dp[j] + 1);
        }

        return dp[n-1];
    }
};
