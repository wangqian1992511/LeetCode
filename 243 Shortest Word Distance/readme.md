# Problem

Given a list of words and two words word1 and word2, return the shortest distance between these two words in the list.

For example, assume that words = ["practice", "makes", "perfect", "coding", "makes"].

Given word1 = “coding”, word2 = “practice”, return 3.

Given word1 = "makes", word2 = "coding", return 1.

Note:
You may assume that word1 does not equal to word2, and word1 and word2 are both in the list.

# Solution

Maintain two index for both input words. We should find the initial nearest apperance of these words at the beginning. Then keep updating the index and the current minimum gap while linearly scanning the given vector.

# Running Time

- cpp version: 19 ms (001.cpp)
