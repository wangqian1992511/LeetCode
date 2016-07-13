# Problem

You are given two integer arrays nums1 and nums2 sorted in ascending order and an integer k.

Define a pair (u,v) which consists of one element from the first array and one element from the second array.

Find the k pairs (u1,v1),(u2,v2) ...(uk,vk) with the smallest sums.

Example 1:

```
Given nums1 = [1,7,11], nums2 = [2,4,6],  k = 3

Return: [1,2],[1,4],[1,6]

The first 3 pairs are returned from the sequence:
[1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]
```
Example 2:

```
Given nums1 = [1,1,2], nums2 = [1,2,3],  k = 2

Return: [1,1],[1,1]

The first 2 pairs are returned from the sequence:
[1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]
```
Example 3:

```
Given nums1 = [1,2], nums2 = [3],  k = 3 

Return: [1,3],[2,3]

All possible pairs are returned from the sequence:
[1,3],[2,3]
```
# Solution

This problem is similar to [Problem 23](../023%20Merge%20k%20Sorted%20Lists), when there are m elements in each list. The j-th element in the i-th sorted list can be constructed by:

```
a[i][j] = nums1[i] + nums2[j]
```

Maintain n nodes in a heap. One node have three attributes: the presentative index of nums1 (idx1), the presentative index of nums2 (idx2), the key value (key = nums1[idx1] + nums2[idx2]).

When a node is popped from the heap, we should increase its idx2 by 1, modify its key and push it back to the heap.

The time complexity is O(n+klog(n)).

# Running Time

- cpp version: 16 ms (001.cpp)
