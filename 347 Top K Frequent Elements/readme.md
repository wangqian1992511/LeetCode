# Problem

Given a non-empty array of integers, return the k most frequent elements.

For example,

Given [1,1,1,2,2,3] and k = 2, return [1,2].

Note: 

You may assume k is always valid, 1 ≤ k ≤ number of unique elements.

Your algorithm's time complexity must be better than O(n log n), where n is the array's size.

# Solution

The general idea is to use the bucket sort. Get the number of apperance for each element in the beginning. The number of buckets is at most the length of the input. The time complexity is O(n). 

We can also use BST instead of bucket. There are at most O(\sqrt{n}) different numbers of appearance. Therefore, the time complexity is O(nlog(n)). But this is the extreme case. So, the actual performance is not worse than the bucket sort solution.

# Running Time

- cpp version: 40 ms (001.cpp)
- cpp version: 36 ms (001.cpp)