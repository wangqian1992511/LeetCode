001.cpp (244ms):

Use DP with the transfer function of:

dp[i] = min{dp[i], dp[i - coins[j]]}