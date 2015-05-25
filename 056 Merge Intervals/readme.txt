001.cpp (591ms):

First perform the sorting, then merge and check for overlapping. The time complexity is O(nlog(n)). It seems that C++ is slower in this problem. But still not clear about the reason.

In this problem, I also learnt the concept of "strict weak ordering". For this concept, one of the most important properties is irreflexivity. That is to say, op(x, x) is always false.
