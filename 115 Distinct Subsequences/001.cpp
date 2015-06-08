class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        if (!n) return 0;
        int m = t.size();
        if (!m) return 0;
        
        int *dp[2];
        dp[0] = new int [m];
        dp[1] = new int [m];
        fill(dp[false], dp[false] + m, 0);
        dp[false][0] = (s[0] == t[0]);
            
        bool ansP = false;
        for (int j = 1; j < n; j++) {
            ansP = !ansP;
            dp[ansP][0] = dp[!ansP][0] + (s[j] == t[0]);
            for (int i = 1; i < m; i++){
                dp[ansP][i] = dp[!ansP][i];
                if (s[j] == t[i])
                    dp[ansP][i] += dp[!ansP][i-1];
            }
        }
        return dp[ansP][m-1];
    }
};