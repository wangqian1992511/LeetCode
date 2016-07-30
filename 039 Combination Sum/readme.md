# Problem

Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:
All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
For example, given candidate set [2, 3, 6, 7] and target 7, 
A solution set is: 
```
[
  [7],
  [2, 2, 3]
]
```

# Solution

First, use the method sort(), unique() and erase() to remove the duplicates from the given vector. Then, use DFS to find the valid solution one by one.

# Running Time

- cpp version: 20 ms (001.cpp)
