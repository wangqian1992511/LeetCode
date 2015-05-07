001.cpp (18ms):

We should modify the code of problem 055. For this problem, we should not keep updating "dist" with a for-loop. Instead, we must record the furtherest index after the i-th jump. Hence, a while-loop is necessary. 

After the i-th jump is completed, if we still haven't reach the last index, we know that one more jump is needed. Check all the index reachable to the i-th jump to get the furtherest index reachable to the (i+1)-th jump.
