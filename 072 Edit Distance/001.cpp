class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        
        int **dp;
        dp = new int* [2];
        dp[0] = new int [m+1];
        dp[1] = new int [m+1];
        
        bool ansP = false;
        for (int j = m; j >= 0; j--)
            dp[ansP][j] = m - j;
        for (int i = n-1; i >= 0; i--) {
            ansP = !ansP;
            dp[ansP][m] = dp[!ansP][m] + 1;
            for (int j = m-1; j >= 0; j--) {
                dp[ansP][j] = dp[!ansP][j+1] + (word1[i] != word2[j]);
                dp[ansP][j] = min(dp[ansP][j], dp[!ansP][j] + 1);
                dp[ansP][j] = min(dp[ansP][j], dp[ansP][j+1] + 1);
            }
        }
        return dp[ansP][0];
    }
};