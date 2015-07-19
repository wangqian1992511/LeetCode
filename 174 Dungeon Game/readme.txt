001.cpp (12ms):

DP problem with the transfer function of 

dp[i][j] = max(1, min(dp[i][j+1], dp[i+1][j]) - dungeon[i][j])