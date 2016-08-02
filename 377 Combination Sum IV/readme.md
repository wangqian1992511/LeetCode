# Problem

Given an integer array with all positive numbers and no duplicates, find the number of possible combinations that add up to a positive integer target.

Example:

```
nums = [1, 2, 3]
target = 4

The possible combination ways are:
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)

Note that different sequences are counted as different combinations.

Therefore the output is 7.
```
Follow up:
What if negative numbers are allowed in the given array?

How does it change the problem?

What limitation we need to add to the question to allow negative numbers?

# Solution

A DP problem with the transition function:

```
dp[i] = \sum_{x<=i AND x \in list}dp[i-x]
```

If the negative number is allowed, then there may be infinite number of different sequences. Thus, we can add limitation to the maximum length of one sequence.

# Running Time

- cpp version: 4 ms (001.cpp)
