001.cpp (4ms):

The DP problem with the transfer function of:

dp[i] = dp[i+1] * isValid(s[i]) + dp[i+2] * isValid(s[i..i+1]) 