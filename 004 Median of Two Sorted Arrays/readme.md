# Problem

There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

Example 1:

```
nums1 = [1, 3]
nums2 = [2]

The median is 2.0
```

Example 2:

```
nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5
```

# Solution

If we merge the array A and B into a single sorted array, we can derive the "idx" of the median easily. Now, the idea is that, if the median is at "idxA" of array A, then we know that:

```
B[idx - 1 - idxA] <= A[idxA] <= B[idx - idxA]
```

Thus, we can perform the binary search on "idxA". If B[idx - 1 - idxA] is too large (or out of boundary), then move "idxA" to the right. Otherwise, move "idxA" to the left.

The time complexity is O(log(m)+log(n)).

# Running Time

- cpp version: 44 ms (001.cpp)
