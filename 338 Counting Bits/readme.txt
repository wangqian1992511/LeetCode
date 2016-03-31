001.cpp (128ms):

DP solution with transition function of:

dp[i] = dp[i & 1] + dp[i >> 1]