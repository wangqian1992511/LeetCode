001.cpp (20ms):

A dp problem with the transfer function of:

dp[i][j] = min(dp[i+1][j+1] + (a[i] != b[j]), dp[i+1][j] + 1, dp[i][j+1] + 1)