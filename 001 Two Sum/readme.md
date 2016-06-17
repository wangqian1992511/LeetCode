# Problem

Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution.

```
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9, return [0, 1].
```

# Solution

We use a hash table to store the elements that have already been checked. When we are checking an element "x", we can look up the hash table to see whether "target - x" has been checked or not. The time complexity is O(n).

It is not interesting to implement a "sort and binary search" or "sort and two-pointer scan" in this problem. The reason is that this problem requires to return the index instead the data, and the time complexity for these kinds of algorithms is O(nlog(n)).

# Running Time

- cpp version: 16 ms (001.cpp)
- python version: 48 ms (001.py)