# Problem

Given two strings s and t, write a function to determine if t is an anagram of s.

For example,
s = "anagram", t = "nagaram", return true.
s = "rat", t = "car", return false.

Note:
You may assume the string contains only lowercase alphabets.

Follow up:
What if the inputs contain unicode characters? How would you adapt your solution to such case?

# Solution

Use a counter to count the appearance of a particular character in each string. The difference should be zero.

# Running Time

- cpp version: 44 ms (001.cpp)
- python version: 84 ms (001.py)