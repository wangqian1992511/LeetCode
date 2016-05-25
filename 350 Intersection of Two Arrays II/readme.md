# Problem

Given two arrays, write a function to compute their intersection.

```
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2, 2].
```

Note:

- Each element in the result should appear as many times as it shows in both arrays.
- The result can be in any order.

Follow up:

- What if the given array is already sorted? How would you optimize your algorithm?
- What if nums1's size is small compared to num2's size? Which algorithm is better?
- What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?

# Solution

If the two arrays are both sorted, we should use two pointers strategy. This idea is similar to the implementation of merge join in database systems (001.cpp). Since they are not sorted in this problem, the time complexity should be O(nlogn).

If nums1 is small enough to fit the memory, but num2 is to large to fit the memory, we can store all the elements in nums1 in the memory as a hash map. After that, we can process the elements in nums2 one by one. This idea is similar to the implementation of index join or hash join in database systems (002.cpp). The time complexity is O(n).

# Running Time

- cpp version: 8 ms (001.cpp)
- cpp version: 12 ms (002.cpp)
