# Problem

Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:

1. Only one letter can be changed at a time
2. Each intermediate word must exist in the word list
For example,

Given:

beginWord = "hit"

endWord = "cog"

wordList = ["hot","dot","dog","lot","log"]

As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog", return its length 5.

Note:

- Return 0 if there is no such transformation sequence.
- All words have the same length.
- All words contain only lowercase alphabetic characters.
- 
# Solution

Use BFS to generate the depth of one word until the depth of endWord is determined.

The time complexity is O(n + m), which is equal to O(n + 26kn), when k is the length of the word. As a meaningful English word, a word should be expected to have a length of 5 to 7. Thus, the overall time complexity is O(k<sup>3</sup>n)

# Running Time

- cpp version: 220 ms (001.cpp)