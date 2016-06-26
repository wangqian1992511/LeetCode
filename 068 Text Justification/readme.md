# Problem

Given an array of words and a length L, format the text such that each line has exactly L characters and is fully (left and right) justified.

You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly L characters.

Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.

For the last line of text, it should be left justified and no extra space is inserted between words.

For example,

words: ["This", "is", "an", "example", "of", "text", "justification."]

L: 16.

Return the formatted lines as:

```
[
   "This    is    an",
   "example  of text",
   "justification.  "
]
```
Note: Each word is guaranteed not to exceed L in length.

# Solution

Construct the result line by line. For each line, we first try to separate the words by single spaces. If there is still some empty space to fill, we try to fill them from left to right evenly. Pay attention to the special case when the line under discussion is the final line or there is only one word in a line.

# Running Time

- cpp version: 0 ms (001.cpp)
