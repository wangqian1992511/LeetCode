001.cpp (20ms):

Use the DFS to find the kth element during the preorder traversal. The time complexity is O(k).

As mentioned in the problem description, if we frequently modify the BST and ask for the kth smallest element in it, we could use an SBT instead of general BST. Then the time complexity will be O(log(n)).
