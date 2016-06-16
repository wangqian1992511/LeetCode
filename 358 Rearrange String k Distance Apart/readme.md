# Problem

Given a non-empty string str and an integer k, rearrange the string such that the same characters are at least distance k from each other.

All input strings are given in lowercase letters. If it is not possible to rearrange the string, return an empty string "".

Example 1:

```
str = "aabbcc", k = 3

Result: "abcabc"

The same letters are at least distance 3 from each other.
```
Example 2:

```
str = "aaabc", k = 3 

Answer: ""

It is not possible to rearrange the string.
```
Example 3:

```
str = "aaadbbcc", k = 2

Answer: "abacabcd"

Another possible answer is: "abcabcda"

The same letters are at least distance 2 from each other.
```

# Solution

Arrange the letters from the most frequent ones to the least. Place the letters into the index of 0, k, 2k, 3k, etc. If the end is reached, we should then fill the index of 1, 1+k, 1+2k, etc. After this process, we should get a valid answer. 

The case when there is no solution is that, we cannot guarantee the least distance requirement, even if the letters are arranged as evenly as possible. If the following inequality is true for any letter "ch", then there is no solution:

```
k * (cnt[ch] - 1) + tot[cnt[ch]] > len(str)
```

# Running Time

- cpp version: 28 ms (001.cpp)
