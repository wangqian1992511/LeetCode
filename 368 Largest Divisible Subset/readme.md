# Problem

Given a set of distinct positive integers, find the largest subset such that every pair (Si, Sj) of elements in this subset satisfies: Si % Sj = 0 or Sj % Si = 0.

If there are multiple solutions, return any subset is fine.

Example 1:

```
nums: [1,2,3]
Result: [1,2] (of course, [1,3] will also be ok)
```
Example 2:

```
nums: [1,2,4,8]
Result: [1,2,4,8]
```

# Solution

First sort all the elements from the smallest to the largest. Then conduct the O(n<sup>2</sup>) DP solution. 

```
dp[i] = dp[j] + 1 if nums[i] % nums[j] == 0
```

# Running Time

- cpp version: 52 ms (001.cpp)
