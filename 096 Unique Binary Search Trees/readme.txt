001.cpp (0ms):

Use a DP solution:

dp[i] = sum(dp[k] * dp[i-1-k]) for all 0 <= k <= i-1
dp[0] = dp[1] = 1

Time complexity is O(n^2)