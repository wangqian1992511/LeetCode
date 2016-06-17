# Problem

Given a non-negative integer n, count all numbers with unique digits, x, where 0 ≤ x < 10<sup>n</sup>.

Example:

```
Given n = 2, return 91. 
(excluding [11,22,33,44,55,66,77,88,99])
```

# Solution

When "n" is larger than 1, the count of the numbers with exactly "n" different digits is:

```
9 * 9 * 8 * ... * (10 - n + 1)
``` 

# Running Time

- cpp version: 0 ms (001.cpp)
