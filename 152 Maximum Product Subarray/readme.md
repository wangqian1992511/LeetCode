# Problem

Find the contiguous subarray within an array (containing at least one number) which has the largest product.

For example, given the array [2,3,-2,4],
the contiguous subarray [2,3] has the largest product = 6.

# Solution

Since a negative number can change the sign of product, we should keep the current minimum and maximum at the same time. It is a DP problem. Let min[i] be the minimum subarray product ended with a[i] and max[i] be the maximum subarray product ended with a[i]:

```
min[i] = min(a[i], min(a[i] * min[i-1], a[i] * max[i-1]))
max[i] = max(a[i], max(a[i] * min[i-1], a[i] * max[i-1]))
```

# Running Time

- cpp version: 6 ms (001.cpp)
