# Problem

Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
the contiguous subarray [4,-1,2,1] has the largest sum = 6.

# Solution

Notice that:

```
\Sigma_{i}^{j} = S[j] - S[i-1]
```

Thus, to find the maximum sum of the subarray ended with ``a[j]``, we should find the minimum ``S[i-1]``. Use a variable to record the current cumulative sum and the other variable to record the current minimum cumulative sum.

# Running Time

- cpp version: 13 ms (001.cpp)
