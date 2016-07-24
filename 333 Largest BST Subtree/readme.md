# Problem

Given a binary tree, find the largest subtree which is a Binary Search Tree (BST), where largest means subtree with largest number of nodes in it.

Note:
A subtree must include all of its descendants.
Here's an example:

```
    10
    / \
   5  15
  / \   \ 
 1   8   7
```
The Largest BST Subtree in this case is the highlighted one. 
The return value is the subtree's size, which is 3.

# Solution

Similar to [problem 98](../098%20Validate%20Binary%20Search%20Tree), we should add one more field "size" to the structure we defined.

```
root.min = rootHasLeft ? left.min : root.val;
root.max = rootHasRight ? right.max : root.val;
root.isValid = left.isValid AND right.isValid AND left.max < root.val < right.min
root.size = root.isValid ? left.size + 1 + right.size : max(left.size, right.size)
```
The time complexity is O(n).

# Running Time

- cpp version: 12 ms (001.cpp)
