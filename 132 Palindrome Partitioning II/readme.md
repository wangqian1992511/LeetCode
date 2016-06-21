# Problem

Given a string s, partition s such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.

For example, given s = "aab",
Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.

# Solution

Conduct DP twice. 

The first DP is to judge whether the substring s[i ... i + len] is a palindrome or not. The transition function is:

```
isPalin[i][len] = isPalin[i + 1][len - 2]
isPalin[i][0] = true
isPalin[i][i + 1] = (s[i] == s[i + 1])
```

The second DP is to determine the minimum cut number to partition the prefix s[0 ... i]. The transtion function is:

```
dp[i] = 0 if isPalin[0][i]
dp[i] = min{dp[j - 1] + 1} if isPalin[j][i - j]
```

The time complexity is obviously O(n<sup>2</sup>).

# Running Time

- cpp version: 24 ms (001.cpp)
