001.cpp (28ms):

Use a vector to maintain the latest visited node for each level. So, when we visit a node on these level, we can directly conduct the connection. The time complexity is O(n). An O(log(n)) vector is needed.

002.cpp (26ms):

Since the tree is a perfect binary tree, we can deal with the left sub-tree and the right sub-tree first. Then, connect the rightmost nodes in the left sub-tree to the leftmost nodes in the right sub-tree. 
