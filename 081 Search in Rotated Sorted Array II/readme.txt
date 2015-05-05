001.cpp (12ms):

Modify the solution to problem 033 slightly. First, think about the influence of the duplicates. We know that there must be a monotomic part on the left or right hand side of the middle element. However, we cannot determine the exact side directly. For example, we may face such a situation:

{3, ......, 3, ...... 3} = {3, 0, 1, 3, 3, 3, 3, 3} or {3, 3, 3, 3, 3, 4, 5, 3} 

The strategy is to remove the useless duplicates on the two ends. Then, we can determine the monotomic side and repeat what we do in problem 033.
