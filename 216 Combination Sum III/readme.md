# Problem

Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.


Example 1:

Input: k = 3, n = 7

Output:

```
[[1,2,4]]
```

Example 2:

Input: k = 3, n = 9

Output:

```
[[1,2,6], [1,3,5], [2,3,4]]
```

# Solution

Use DFS to cover all the possible cases. The terminal condition is when we have tried k numbers or the least candidate is more than the remaining need.

# Running Time

- cpp version: 0 ms (001.cpp)
