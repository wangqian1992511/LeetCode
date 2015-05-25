001.cpp (84ms):

The time complexity must be O(mn). Not difficult to find a solution with O(n+m) memory complexity. If we want to get an O(1) memory complexity solution, we can try to consider this matrix as a (m-1)-by-(n-1) matrix first. Then we can use the 0-th row and 0-th column as the O(n+m) extra memory in the original problem. This row and this column should be processed separately.
