001.cpp (4ms):

Use divide and conquer to solve the problem. To find the time complexity, since we have

T(1) = 1
T(n) = Sum_{i=1}^{n-1}T(i)T(n-i)

It is obvious that the time complexity should be O(C_{n}), where "C_{n}" is the n-th Catalan number. In fact, this problem is a general senario for Catalan number.