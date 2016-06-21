class Solution {
public:
    bool isScramble(string s1, string s2) {
        int n = s1.size();
        if (!n) return true;

        bool*** dp = new bool** [n + 1];

        dp[1] = new bool* [n];
        for (int i = 0; i < n; i++) {
            dp[1][i] = new bool [n];
            for (int j = 0; j < n; j++)
                dp[1][i][j] = (s1[i] == s2[j]);
        }

        for (int len = 2; len <= n; len++) {
            dp[len] = new bool* [n];
            for (int i = 0; i < n; i++) {
                dp[len][i] = new bool [n];
                fill(dp[len][i], dp[len][i] + n, false);
                for (int j = 0; j < n; j++)
                    for (int k = 1; k < min(len, n - i); k++)
                        dp[len][i][j] = dp[len][i][j] ||
                                        ((j + k < n) && dp[k][i][j] && dp[len - k][i + k][j + k]) ||
                                        ((j + len - k < n) && dp[k][i][j + len - k] && dp[len - k][i + k][j]);
            }
        }

        return dp[n][0][0];
    }
};
