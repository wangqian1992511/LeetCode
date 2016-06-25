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

Use the two-directional BFS. The beginword and the endword are pushed into the forward and backward BFS queue seperately, in the beginning.

Since we are required to record all the valid solutions, we should use a rolling queue to expand all the nodes in a certain level. But still, a node can only be pushed into the queue once. That is to say, we need two boolean mapping to record:

1. whether a node can be expanded in a certain level
2. whether a node can be pushed into the queue for the next level

When expanding all the direct children of a node, we should construct a new word by replacing one of the characters in this original word. Then, check whether this new word can be expanded or pushed into the queue.

The time complexity is O(n + m), which is equal to O(n + 26kn), when k is the length of the word. As a meaningful English word, a word should be expected to have a length of 5 to 7. Thus, the overall time complexity is O(k<sup>3</sup>n)

# Running Time

- cpp version: 328 ms (001.cpp)