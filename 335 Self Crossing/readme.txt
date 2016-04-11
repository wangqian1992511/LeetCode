001.cpp (0ms):

Actually, let’s call this problem self “meeting”!!! Solve step by step.

If there are less than 4 line, there is no possibility to cross.

At first, we should keep ignoring the spiral with strictly increasing radius.

Suppose we are pausing at the p-th line, we should check whether x[p] + x[p-4] is smaller than x[p - 2]. If not, we should cut the (p-1)-th line for the following discussion to avoid self crossing. The following test cases can help illustrating this point:

[2,2,4,4,3]
[2,2,4,4,1]

In the end, we should keep ignoring the spiral with strictly increasing radius.
