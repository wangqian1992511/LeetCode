# Problem

Merge k sorted linked lists and return it as one sorted list.

# Solution

A heap with the size of "k" is used to maintain the smallest element in each list to be added to the result list (001.cpp).

We can also make use of the merge tree to merge the lists two by two. That is to say, merge the 1st and the 2nd list, the 3rd and the 4th list, etc. Then repeat this process recursively, until we get only one list.

The time complexity for both solutions is the same as O(klog(n)). But operation on heap may cost more constant time.

# Running Time

- cpp version: 44 ms (001.cpp)
- cpp version: 32 ms (002.cpp)
