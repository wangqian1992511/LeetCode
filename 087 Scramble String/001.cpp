class Solution {
public:
    bool isScramble(string s1, string s2) {
        n = s1.size();
        if (!n) return true;
        dp = new int** [n+1];
        for (int i = 0; i <= n; i++) {
            dp[i] = new int* [n+1];
            for (int j = 0; j <= n; j++) {
                dp[i][j] = new int [n+1];
                fill(dp[i][j], dp[i][j] + n + 1, -1);
            }
        }
        return helper(s1, 0, s2, 0, n);
    }
private:
    int ***dp, n;
    int helper(string &s1, int sta, string &s2, int stb, int len) {
        if (dp[sta][stb][len] == -1) 
            if (len == 1)
                dp[sta][stb][1] = (s1[sta] == s2[stb]);
            else {
                int cnt[256] = {0};
                for (int i = 0; i < len; i++) {
                    cnt[s1[sta+i]]++;
                    cnt[s2[stb+i]]--;
                }
                for (int i = 0; i < 256; i++)
                    if (cnt[i]) {
                        dp[sta][stb][len] = 0;
                        return dp[sta][stb][len];
                    }
                for (int i = 1; i < len; i++) 
                    if (dp[sta][stb][len] != 1) 
                        dp[sta][stb][len] = (helper(s1, sta, s2, stb, i) & helper(s1, sta+i, s2, stb+i, len-i)) |
                                            (helper(s1, sta, s2, stb+len-i, i) & helper(s1, sta+i, s2, stb, len-i));
                    else
                        break;
            }
        return dp[sta][stb][len];
    }
};