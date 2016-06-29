# Problem

Assume you have an array of length n initialized with all 0's and are given k update operations.

Each operation is represented as a triplet: [startIndex, endIndex, inc] which increments each element of subarray A[startIndex ... endIndex] (startIndex and endIndex inclusive) with inc.

Return the modified array after all k operations were executed.

Example:

```
Given:

    length = 5,
    updates = [
        [1,  3,  2],
        [2,  4,  3],
        [0,  2, -2]
    ]
    
Output:

    [-2, 0, 3, 5, 3]
```
Explanation:

```
Initial state:
[ 0, 0, 0, 0, 0 ]

After applying operation [1, 3, 2]:
[ 0, 2, 2, 2, 0 ]

After applying operation [2, 4, 3]:
[ 0, 2, 5, 5, 3 ]

After applying operation [0, 2, -2]:
[-2, 0, 3, 5, 3 ]
```

# Solution

Our final purpose is to maintain the cumulative increase of an element, when constructing the resulted list. 

Thus, we should build a list inc, such that:

$$ a[k] = \sum_{i = 0}^{k}inc[i] $$

Given one update rule [l,r,v], we should conduct:

```
inc[l] = inc[l] + v
inc[r] = inc[r + 1] - v
```

We can use O(n) extra space to obtain O(n+k) time complexity, as shown in 001.cpp. If k is much smaller than n and the space requirement is strict, we can use O(k) extra space to obtain O(n + klog(k)) time complexity, as shown in 002.cpp.

# Running Time

- cpp version: 168 ms (001.cpp)
- cpp version: 192 ms (002.cpp)
