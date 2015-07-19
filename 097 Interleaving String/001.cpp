class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size();
        int m = s2.size();
        if (n + m != s3.size()) return false;
        
        int cnt[256] = {0};
        for (int i = 0; i < n; i++) 
            cnt[s1[i]]++;
        for (int i = 0; i < m; i++) 
            cnt[s2[i]]++;
        for (int i = 0; i < n+m; i++) 
            cnt[s3[i]]--;
        for (int i = 0; i < 256; i++)
            if (cnt[i])
                return false;
        
        bool *dp[2], ansP = false;
        dp[0] = new bool [m+1];
        dp[1] = new bool [m+1];
        dp[ansP][m] = true;
        for (int j = m-1; j >= 0; j--)
            dp[ansP][j] = dp[ansP][j+1] && (s3[n+j] == s2[j]);
        for (int i = n-1; i >= 0; i--) {
            ansP = !ansP;
            dp[ansP][m] = dp[!ansP][m] && (s3[i+m] == s1[i]);
            for (int j = m-1; j >= 0; j--)
                dp[ansP][j] = dp[ansP][j+1] && (s3[i+j] == s2[j]) || dp[!ansP][j] && (s3[i+j] == s1[i]);
        }
        return dp[ansP][0];
    }
};