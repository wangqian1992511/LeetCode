001.cpp (0ms):

A DFS problem with several observations to decrease the running time.

1. If we remove ‘(’ at index “i”, then we should also remove the following consecutive ‘(’ to avoid duplicate solution.

2. Then same principle works for ‘)’.

3. To get the longest valid string, we should try not delete a certain character first.

4. During the DFS, if we observe that the string to be obtained without removing any more characters is shorter than the max length of the solution, we should stop searching.

A counter is use the indicate the difference between the number of ‘(’ and ‘)’.

5. We can use ‘)’ only when the counter is larger than 0.

6. We can use ‘(’ only when the remaining ‘)’ is more than the counter.

7. We can ignore ‘)’ only when the the remaining ‘)’ is not less than the counter.