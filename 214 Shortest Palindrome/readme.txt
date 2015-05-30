001.cpp (8ms):

Use Manacher's Algorithm first. Then check which palindromic substring is the longest one starting with the 0-th element. At last, we can just added the unmatched character to the front of the string in a reverse order.


002.cpp (4ms):

Inspired from the prefix function in KMP. Reverse the string first. And check the length of the prefix of original string, which should be the suffix of the reversed string. 
