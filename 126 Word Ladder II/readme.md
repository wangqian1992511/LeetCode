# Problem

Given two words (beginWord and endWord), and a dictionary's word list, find all shortest transformation sequence(s) from beginWord to endWord, such that:

Only one letter can be changed at a time
Each intermediate word must exist in the word list
For example,

Given:

beginWord = "hit"

endWord = "cog"

wordList = ["hot","dot","dog","lot","log"]

Return

```
  [
   ["hit","hot","dot","dog","cog"], 
   ["hit","hot","lot","log","cog"]
  ]
```

Note:
All words have the same length.
All words contain only lowercase alphabetic characters.

# Solution

Use BFS to generate the length of one valid path and the direction between two words. Use DFS to generate the paths. Since all the paths are required, we should expand the BFS tree level by level, instead of node by node.

The time complexity is O(n + m), which is equal to O(n + 26kn), when k is the length of the word. As a meaningful English word, a word should be expected to have a length of 5 to 7. Thus, the overall time complexity is O(k<sup>3</sup>n)

# Running Time

- cpp version: 436 ms (001.cpp)