# Problem

Given a non-empty 2D matrix matrix and an integer k, find the max sum of a rectangle in the matrix such that its sum is no larger than k.

Example:

```
Given matrix = [
  [1,  0, 1],
  [0, -2, 3]
]
k = 2
```

The answer is 2. Because the sum of rectangle [[0, 1], [-2, 3]] is 2 and 2 is the max number no larger than k (k = 2).

Note:

1. The rectangle inside the matrix must have an area > 0.
2. What if the number of rows is much larger than the number of columns?

# Solution

Consider the one dimensional situation. To find the maximum sum of a subarray not larger than k, we should make use of the information about cumulative sum. 

If the cumulative sum from a[0] to a[i] is s[i], then we should check whether there is a cumulative sum from a[0] to a[j] (j < i), such that s[i] - s[j] is not larger than k. To make this value larger, we should find the smallest s[j] larger than s[i] - k.

In this two dimensional situation, we should take O(n<sup>2</sup>) to compress the matrix to an array. The overall time complexity is O(n<sup>2</sup>mlog(m)).

# Running Time

- cpp version: 1020 ms (001.cpp)
