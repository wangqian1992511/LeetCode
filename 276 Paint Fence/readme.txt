001.cpp (0ms):

dp[i] = (k-1) * dp[i-1] + (k-1) * dp[i-2]

If the i-th post have the different from the (i-1)-th post, then there are (k-1) * dp[i-1] ways. If they have the same color, then the i-th post must have a different color from the (i-2)-th one.
