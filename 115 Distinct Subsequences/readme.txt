001.cpp (9ms):

A dp problem with the transation function of:

dp[i][j] = dp[i-1][j] + dp[i-1][j-1] (if s[i] == t[j])
dp[i][j] = dp[i-1][j] (if s[i] != t[j])
dp[0][0] = (s[0] == t[0])
dp[0][i] = 0 (if i > 0)
dp[i][0] = dp[0][i-1] + (s[i] == t[0]) (if i > 0)

From these we can find that the time complexity is O(nm) and the extra memmory complexity can be reduced to O(m). Here, dp[i][j] is the number of distinct subsquences for two substring s[0..i] and t[0..j]
