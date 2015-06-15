001.cpp (12ms):

The memorized searching is used here. 

dp[sta][stb][len] = dp[sta][stb][len] | (dp[sta, stb, i] & dp[sta+i, stb+i, len-i]) | (dp[sta, stb+len-i, i] & dp[sta+i, stb, len-i])
for all 1 <= i < len

Here, dp[sta][stb][len] means whether the substrings with the length of len, starting at sta in s1 and at stb in s2, are scramble strings. The time complexity for the helper function is O(n). It is called for at most n^3 times, so the total time complexity is O(n^4). A cutting condition with time complexity O(n) will not hurt the whole complexity. Hence, as long as we should find the value for dp[sta][stb][len], we check if the number of apperance of every character is the same in the two substrings under discussion.