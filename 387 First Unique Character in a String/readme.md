# Problem

Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

Examples:

```
s = "leetcode"
return 0.

s = "loveleetcode",
return 2.
```

# Solution

A hash map is used to record the index. The index of any duplicate elements is always INT_MAX. The minimum of the index is the answer. 

# Running Time

- cpp version: 282 ms (001.cpp)