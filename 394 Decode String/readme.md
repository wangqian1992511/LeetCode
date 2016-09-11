# Problem

Given an encoded string, return it's decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.

You may assume that the input string is always valid; No extra white spaces, square brackets are well-formed, etc.

Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there won't be input like 3a or 2[4].

Examples:

```
s = "3[a]2[bc]", return "aaabcbc".
s = "3[a2[c]]", return "accaccacc".
s = "2[abc]3[cd]ef", return "abcabccdcdcdef".
```

# Solution

Stack is obviously needed for the nested structure. Actually, we use two stacks here. One is for the number, one is for the string. When there is a '[', we should push a new level to both strings. When there is a ']', we should pop a level from both stack. Append the newly constructed substring to the top of the string stack.

# Running Time

- cpp version: 0 ms (001.cpp)