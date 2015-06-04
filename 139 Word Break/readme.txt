001.cpp(12ms):

The dp transaction function is:

dp[i] = dp[i] or (dp[j] and (str[j+1, i] in dict)) or (str[0, i] in dict)
for all j < i
