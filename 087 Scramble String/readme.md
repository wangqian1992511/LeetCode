# Problem

Given a string s1, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.

Below is one possible representation of s1 = "great":

```
    great
   /    \
  gr    eat
 / \    /  \
g   r  e   at
           / \
          a   t
```

To scramble the string, we may choose any non-leaf node and swap its two children.

For example, if we choose the node "gr" and swap its two children, it produces a scrambled string "rgeat".

```
    rgeat
   /    \
  rg    eat
 / \    /  \
r   g  e   at
           / \
          a   t
```

We say that "rgeat" is a scrambled string of "great".

Similarly, if we continue to swap the children of nodes "eat" and "at", it produces a scrambled string "rgtae".

```
    rgtae
   /    \
  rg    tae
 / \    /  \
r   g  ta  e
       / \
      t   a
```

We say that "rgtae" is a scrambled string of "great".

Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1.

# Solution

The idea to perform DP is that, two strings are scramble to each other only when:

1. The left part of s1 is scramble to the left part of s2; the right part of s1 is scramble to the right part of s2.
2. Or, the left part of s1 is scramble to the right part of s2; the right part of s1 is scramble to the left part of s2.

The transition function dp[len][sta][stb] means that the substring starting from index sta in s1 is scramble to the substring starting from index stb in s2, with the length of len. Of course, the remaining parts in both string should be scramble to each other as well. Thus, the transtion function is:

```
dp[len][sta][stb] = 
dp[k][i][j] AND dp[len - k][i + k][j + k] OR 
dp[k][i][j + len - k] AND dp[len - k][i + k][j]
```

The possibility to prune the search tree indicates the advantage of memoization. Notice that s1 and s2 cannot be scramble to each, if the count of a letter c in s1 is not equal to that in s2. That is to say, many states are in fact useless.

# Running Time

- cpp version: 104 ms (001.cpp)
- cpp version: 16 ms (001.cpp)
