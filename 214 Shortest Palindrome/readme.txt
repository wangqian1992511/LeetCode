001.cpp (76ms):

Use Manacher's Algorithm first. Then check which palindromic substring is the longest one starting with the 0-th element. At last, we can just added the unmatched character to the front of the string in a reverse order.
