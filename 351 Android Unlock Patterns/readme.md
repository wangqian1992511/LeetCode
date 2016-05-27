# Problem

Given an Android 3x3 key lock screen and two integers m and n, where 1 ≤ m ≤ n ≤ 9, count the total number of unlock patterns of the Android lock screen, which consist of minimum of m keys and maximum n keys.

Rules for a valid pattern:

1. Each pattern must connect at least m keys and at most n keys.
2. All the keys must be distinct.
3. If the line connecting two consecutive keys in the pattern passes through any other keys, the other keys must have previously selected in the pattern. No jumps through non selected key is allowed.
4. The order of keys used matters.

![](001.png)

# Solution

By symmetry, we know that we only have to check the cases where the first key chosen is 1, 2 or 5. Then the total number of valid solution is

```
ans = ans(1) * 4 + ans(2) * 4 + ans(5)
```

The key strategy is DFS. Since there are only a small number of nodes in one searching path, we are enabled to use bit manipulation to record visited nodes. 

Please refer to [problem 37 Sudoku Solver](https://github.com/wangqian1992511/LeetCode/tree/master/037%20Sudoku%20Solver) for a detailed instruction about bit manipulation in small-scale DFS.

# Running Time

- cpp version: 80 ms (001.cpp)
