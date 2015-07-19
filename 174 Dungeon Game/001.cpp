class Solution {
public:
    int calculateMinimumHP(vector<vector<int> > &dungeon) {
        int n = dungeon.size();
        int m = dungeon[0].size();
        int *dp[2];
        dp[0] = new int [m];
        dp[1] = new int [m];
        
        bool ansP = false;
        dp[ansP][m-1] = max(1, 1 - dungeon[n-1][m-1]);
        for (int j = m-2; j >= 0; j--)
            dp[ansP][j] = max(1, dp[ansP][j+1] - dungeon[n-1][j]);
        for (int i = n-2; i >= 0; i--) {
            ansP = !ansP;
            dp[ansP][m-1] = max(1, dp[!ansP][m-1] - dungeon[i][m-1]);
            for (int j = m-2; j >= 0; j--)
                dp[ansP][j] = max(1, min(dp[ansP][j+1], dp[!ansP][j]) - dungeon[i][j]);
        }
        return dp[ansP][0];
    }
};