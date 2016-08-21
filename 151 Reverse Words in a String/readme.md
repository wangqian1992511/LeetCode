# Problem

Given an input string, reverse the string word by word.

For example,
Given s = "the sky is blue",
return "blue is sky the".

# Solution

Use one string to record the current single word. Use the other one to record the current result. We can construct them by iteratively scanning all the characters in the input (001.cpp) ot using a string stream (002.cpp).

# Running Time

- cpp version: 16 ms (001.cpp)
- cpp version: 12 ms (001.cpp)