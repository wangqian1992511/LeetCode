# Problem

Given a nested list of integers, return the sum of all integers in the list weighted by their depth.

Each element is either an integer, or a list -- whose elements may also be integers or other lists.

Different from the previous question where weight is increasing from root to leaf, now the weight is defined from bottom up. i.e., the leaf level integers have weight 1, and the root level integers have the largest weight.

Example 1:
Given the list [[1,1],2,[1,1]], return 8. (four 1's at depth 1, one 2 at depth 2)

Example 2:
Given the list [1,[4,[6]]], return 17. (one 1 at depth 3, one 4 at depth 2, and one 6 at depth 1; 1 * 3 + 4 * 2 + 6 * 1 = 17)

# Solution

Use two pass DFS (001.cpp). The first pass is used to find the maximum depth of this tree:

```
dep[root] = max{dep[root.left], dep[root.right]} + 1
```

Then, during the second pass, we can add the weighted sum together:

```
ans += \sum_{root is integer} root * dep[root]
```

We can design an one pass DFS solution (002.cpp). In this version, we will first calculate the sum on each level and the maximum depth. Then, the summation will be conducted in the end.

# Running Time

- cpp version: 3 ms (001.cpp)
- cpp version: 3 ms (002.cpp)