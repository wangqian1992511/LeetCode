001.cpp (0ms):

First check the naive case, where the length or the character does not match. Then solve it with the DP transfer function of 

dp[i][j] = dp[i][j+1] AND (s3[i+j] == s2[j]) OR dp[i+1][j] AND (s3[i+j] == s1[i])