001.cpp (60ms):

Solve the problem recursively. Suppose we have the preorder traversal and inorder traversal for a certain tree. Then it is obvious that the first element in the preorder traversal is the value of the root in this sub-tree. Give this value, it is not difficult to divide the inorder traversal into three parts:

{inorder for left sub-tree; root value; inorder for right sub-tree}

Then, since we know the length of the left and right sub-tree, we can divide the preorder traversal into three parts as well:

{root value; preorder for left sub-tree; preorder for right sub-tree}

By know, we can call the same function for both left and right sub-tree. We need O(n) time to find the root value. So, by Master Theorem, the average time complexity is O(nlog(n)), and the worst time complexity is O(n^2).
