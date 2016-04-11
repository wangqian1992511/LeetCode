001.cpp (976ms):

Generally, the length of a word should not be too long. Thus, we use the following O(nm^2) instead of the naive O(n^2) one. Consider the following possible cases:

(1) “” + palindrome
(2) palindrome + “”
(3) string + reverse(part of string)
(4) reverse(part of string) + string
(5) string + reverse(string)

No other cases should be discussed to avoid duplicates. 