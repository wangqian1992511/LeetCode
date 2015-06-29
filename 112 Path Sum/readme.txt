001.cpp (12ms):

Recursion is used to solve the problem. 

hasPath[r, s] = hasPath[r.left, s-r.val] OR hasPath[r.right, s-r.val]