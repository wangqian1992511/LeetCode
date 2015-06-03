001.cpp (16ms):

Use a DP solution. Suppose that dp[i][j] is the length of one side of the square whose right bottom corner is matrix[i][j]; len[i][j] is the length of 1's ended with matrix[i][j]; height[i][j] is the height of 1's ended with matrix[i][j]. The we have:

dp[i][j] = min{dp[i-1, j-1] + 1, len[i][j], height[i][j]}