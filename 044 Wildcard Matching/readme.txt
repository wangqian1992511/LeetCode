001.cpp (392ms):

The dp solution is straight forward. The transfer function should be 

f(i,j) = f(i+1, j+1) if s[i] == p[j] OR p[j] == '?'
f(i,j) = f(i, j+1) OR f(i+1, j) if p[j] == '*'
f(i,j) = (i == n) if j == m

Here, "n" is the length of "s", and "m" is the length of "p". If we calculate all the states f(i,j), we will get a TLE. Thus, we use the memorizable searching to avoid visiting unnecessary states.

A cutting condition can be applied. Suppose we want to match "s[i]" with "p[j]". If there are more than "n-i" non-star characters in substring "s[j..m-1]", then we directly know that this matching is not valid.

To avoid MLE, we use a hash table instead of a two dimensional array to store the states.

The time complexity of this algorithm is O(nm).

002.cpp (24ms):

The key factor to solve this problem is the position of "*". If "p" does not start or end with "*", we can easily know that the first and last several characters in "s" and "p" must match with each other.

After checking this condition, we can always simplify "s" and "p". By now, "p" should have the form of "*...*...*...*". That is to say, the stars will divide "p" into several smaller sub-patterns.

Obviously, the matching works only when we can match all these sub-patterns in "s" with their original order but without overlapping with each other. This can be achieved from iterative KMP, matching every sub-pattern as early as possible in a greedy way. 