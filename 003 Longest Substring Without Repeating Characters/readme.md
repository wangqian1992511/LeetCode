# Problem

Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.

# Solution

Maintain two pointers p and q, so that st[p..q-1] is always valid. Keep moving pointer p, as long as we find that st[q] is used. Keep moving pointer q, as long as we find that st[q] is not used yet. The time complexity is O(n).

# Running Time

- cpp version: 16 ms (001.cpp)