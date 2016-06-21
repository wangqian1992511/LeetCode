class Solution {
public:
    bool isScramble(string s1, string s2) {
        n = s1.size();
        if (!n) return true;
        this->s1 = s1;
        this->s2 = s2;
        dp = new bool** [n + 1];
        vis = new bool** [n + 1];
        for (int len = 0; len <= n; len++) {
            dp[len] = new bool* [n];
            vis[len] =  new bool* [n];
            for (int i = 0; i < n; i++) {
                dp[len][i] = new bool [n];
                vis[len][i] = new bool [n];
                fill(dp[len][i], dp[len][i] + n, false);
                fill(vis[len][i], vis[len][i] + n, false);
            }
        }
        return helper(n, 0, 0);
    }
private:
    int n;
    bool ***dp, ***vis;
    string s1, s2;
    bool helper(int len, int sta, int stb) {
        if (! vis[len][sta][stb]) {
            vis[len][sta][stb] = true;
            if (len == 1)
                dp[1][sta][stb] = (s1[sta] == s2[stb]);
            else {
                int cnt[256] = {0};
                for (int i = 0; i < len; i++) {
                    cnt[s1[sta+i]]++;
                    cnt[s2[stb+i]]--;
                }
                for (int i = 0; i < 256; i++)
                    if (cnt[i]) {
                        dp[len][sta][stb] = false;
                        return dp[len][sta][stb];
                    }
                for (int i = 1; i < len; i++)
                    dp[len][sta][stb] = dp[len][sta][stb] ||
                                        (helper(i, sta, stb) && helper(len - i, sta+i, stb+i)) ||
                                        (helper(i, sta, stb+len-i) && helper(len - i, sta+i, stb));
            }
        }
        return dp[len][sta][stb];
    }
};
