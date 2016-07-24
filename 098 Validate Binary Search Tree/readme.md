# Problem

Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.

Example 1:

```
    2
   / \
  1   3
```

Binary tree [2,1,3], return true.
Example 2:

```
    1
   / \
  2   3
```
Binary tree [1,2,3], return false.

# Solution

Use a structure to record whether a subtree is valid and the minimum/maximum value in this subtree. Use DFS to recursively update this structure for each node:

```
root.min = rootHasLeft ? left.min : root.val;
root.max = rootHasRight ? right.max : root.val;
root.isValid = left.isValid AND right.isValid AND left.max < root.val < right.min
```
The time complexity is O(n).

# Running Time

- cpp version: 16 ms (001.cpp)
