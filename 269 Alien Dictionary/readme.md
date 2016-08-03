# Problem

There is a new alien language which uses the latin alphabet. However, the order among letters are unknown to you. You receive a list of words from the dictionary, where words are sorted lexicographically by the rules of this new language. Derive the order of letters in this language.

For example,
Given the following words in dictionary,

```
[
  "wrt",
  "wrf",
  "er",
  "ett",
  "rftt"
]
```
The correct order is: "wertf".

Note:
You may assume all letters are in lowercase.
If the order is invalid, return an empty string.
There may be multiple valid order of letters, return any one of them is fine.

# Solution

Use the topological sort with respect to the letters. For every two adjacent words, s and t, we should scan from the left to the right, in order to find the first pair of different letters. Do not forget those letters, which have not been touched in this stage. They should also be included in the final answer.

# Running Time

- cpp version: 12 ms (001.cpp)
