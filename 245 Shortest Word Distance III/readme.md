# Problem

This is a follow up of [Problem 244](../244%20Shortest%20Word%20Distance%20II). The only difference is now word1 could be the same as word2.

Given a list of words and two words word1 and word2, return the shortest distance between these two words in the list.

word1 and word2 may be the same and they represent two individual words in the list.

For example, assume that words = ["practice", "makes", "perfect", "coding", "makes"].

Given word1 = “makes”, word2 = “coding”, return 1.
Given word1 = "makes", word2 = "makes", return 3.

Note:
You may assume word1 and word2 are both in the list.

# Solution

Add a new private method to the original solution. It will deal with the special case when word1 and word2 are the same.

# Running Time

- cpp version: 16 ms (001.cpp)
