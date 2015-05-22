001.cpp (0ms):

DP problem with the time complexity of O(n) and constant extra memmory.

dp[i] = max{dp[i-1], num[i] + dp[i-2]}
dp[0] = num[0]
dp[1] = max(num[0], num[1])

dp[i] means the optimized solution until the i-th day. It is determined by the maximum of dp[i-1] (no robbery conducted on this day) and num[i] + dp[i-2] (the robbery conducted on this day).
