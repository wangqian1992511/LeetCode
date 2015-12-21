001.cpp (40ms):

Use dp[i][j] to indicate the maximum value when we have nums[i..j] and cannot burst the balloons at index i and index j.

dp[i][j] = max{dp[i][k] + dp[k][j] + nums[i] * nums[k] * num[j]}

k is the last balloon to be burst. 
