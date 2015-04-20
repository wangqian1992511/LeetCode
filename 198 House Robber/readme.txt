001.cpp (3ms):

DP problem with the time complexity of O(n) and constant extra memmory.

dp[i] = max{dp[i-1], num[i] + dp[i-2]}
