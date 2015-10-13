001.cpp (4ms):

The naive implementation of string matching algorithm. I used the Sunday improved KMP.

The last loop is the matching part. We always attempt to match "text[i]" and "pattern[j]". When they are not match, we should notice that "text[nP - j + i]" must be used in the next matching window, no matter how long we shift this window. For example "c" and "b" are not matching, then the "m" must always be used in the next matching.

e.g.
ababa{c}aefh[m]
  aba{b}defg

If there is no character at the position of "m", the matching is over. If "m" never appears in the pattern, diretly shift the starting character of the pattern, so that "pattern[0]" is align with "text[nP - j + i + 1]".

If "m" appears in the pattern, then we will shift the string based on the prefix function "pi". Here, "pi[i]" means the length of the longest prefix of the pattern, as a suffix for the first "i" characters of the pattern. Or, let's say, if we mismatch at "str[i]", then we should try "str[p[i]]".

e.g.
str: a x a y a x a x a
 i : 0 1 2 3 4 5 6 7 8
 pi: 0 0 0 1 0 1 2 3 2

When we are conducting the matching, if we find that "pattern[i]" is not matched with a certain character, then we should shift the matching window and try "pattern[p[i]]".

The second for-loop is building up this prefix function. In fact, this is a process of self-matching, implemented as the naive KMP.
