001.cpp (0ms):

dp[i] = dp[i-4]

Since dp[1,2,3] is true, dp[4] is false, we can derive that dp[i] = i % 4 
