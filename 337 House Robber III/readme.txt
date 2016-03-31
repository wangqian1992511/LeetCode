001.cpp (12ms):

Solve by post-order dfs with the transition function of:

dp[1, node] = val + dp[0, left] + dp[0, right]
dp[0, node] = max(dp[.., left]) + max(dp[.., right])