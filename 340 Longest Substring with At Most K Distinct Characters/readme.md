# Problem

Given a string, find the length of the longest substring T that contains at most k distinct characters.

For example, Given s = “eceba” and k = 2,

T is "ece" which its length is 3.

# Solution

Use two pointers to indicate the starting and ending index of a valid substring. A hash map is used as the counter.

It is possible that the string is too long to it the memory. In this case, we should conduct the one-pass algorithm. A BST is maintained to record the rightmost index of one character. If we find an invalid substring, we should remove the character with the leftmost rightmost index.

# Running Time

- cpp version: 86 ms (001.cpp)
- cpp version: 143 ms (002.cpp)