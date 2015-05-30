class Solution {
public:
    string longestPalindrome(string s) {
        bool dp[1001][1001];
        int n = s.size();
        if (!n) return "";
        int st = 0, l = 1;
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
            dp[i+1][i] = true;
        }
        for (int k = 1; k < n; k++)
            for (int i = 0; i < n-k; i++) 
                if (dp[i][i+k] = dp[i+1][i+k-1] && (s[i] == s[i+k])) {
                    st = i;
                    l = k+1;
                }
        return s.substr(st,l);
    }
};
