# Problem

Given two arrays, write a function to compute their intersection.

```
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].
```

Note:

- Each element in the result must be unique.
- The result can be in any order.

# Solution

Put all the elements in num1 into one set. Then check whether the elements in nums2 are in this set, one by one. If we are using Python, we can directly call the function to get intersection of sets.

# Running Time

- cpp version: 12 ms
- python version: 48 ms