# Problem

Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

For example,
Given [3,2,1,5,6,4] and k = 2, return 5.

Note: 
You may assume k is always valid, 1 ≤ k ≤ array's length.

# Solution

Edit the traditional quick sort. Get an O(n) solution based on Master's theorem.

```
T(n) = aT(n/b) + O(n^{d})
a = b^d ==> O(n^{d}log(n))
a < b^d ==> O(n^{d})
a > b^d ==> O(n^{log_{b}(a)})
```

# Running Time

- cpp version: 12 ms (001.cpp)
- python version: 52 ms (001.py)
