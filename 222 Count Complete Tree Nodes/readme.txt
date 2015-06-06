001.cpp (88ms):

Use the binary search. The time complexity is O(log(n)log(n)). For each root, check the height of the left sub-tree and the right sub-tree. If there are the same, we should continue checking the right sub-tree. Otherwise, we continue checking the left sub-tree.