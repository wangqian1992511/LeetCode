001.cpp (52ms):

Use a BST with at most k elements. When we are dealing with an element "nums[i]", we should check whether there is an element in this BST, such that it is not smaller than "nums[i] - t" and not larger than "nums[i] + t". We do not need to implement the BST entirely, since there are many STL containers implemented as a BST. In this problem, multi-set is a nice option. It enables us to delete an element, insert an element, and search for the extreme value of a certain range within O(log(k)) time. The total time complexity is O(nlog(k)).

001.py (88ms):

Use the bucket sort. The length of each buchet is "t", then we need to check at most three buckets for each elements. The time complexity is O(n).
