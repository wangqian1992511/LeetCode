# Problem

Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

Note:
You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2. The number of elements initialized in nums1 and nums2 are m and n respectively.

# Solution

To implement an in-place algorithm, we should merge the two lists from the largest element to the smallest.

# Running Time

- cpp version: 4 ms (001.cpp)
