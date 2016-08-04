# Problem

Given an unsorted array of integers, find the length of longest increasing subsequence.

For example,
Given [10, 9, 2, 5, 3, 7, 101, 18],
The longest increasing subsequence is [2, 3, 7, 101], therefore the length is 4. Note that there may be more than one LIS combination, it is only necessary for you to return the length.

Your algorithm should run in O(n2) complexity.

Follow up: Could you improve it to O(n log n) time complexity?

# Solution

The O(n<sup>2</sup>) approach is naive. It is a DP solution with the transitive function:

```
dp[i] = max{dp[j] + 1} (j < i AND nums[j] < nums[i])
```

A better solution makes good use of the property of the increasing sequences. Suppose we have two increasing sequences with the small length, but different ending numbers. Then, it is obvious that the one with the smaller ending number will have a higher chance to generate a longer increasing sequence.

Thus, we should maintain an array, so that lenMin[i] is the smallest ending number for all the possible increasing sequences with length of i. Notice that lenMin itself will also be an increasing sequence. Hence, given any new number x, we can use binary search to find an index i, such that:

```
lenMin[i] < x <= lenMin[i + 1]
```

After that, we can update lenMin[i + 1] to x.

# Running Time

- cpp version: 100 ms (001.cpp)
- cpp version: 4 ms (002.cpp)
