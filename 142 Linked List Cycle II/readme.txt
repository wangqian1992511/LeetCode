001.cpp (12ms):

Use two pointers, a fast one and a slow one. They will meet in the cycle, if there is one. Then make all the nodes in this cycle point to NULL. Scan from the head again to reach the starting point of this cycle.
