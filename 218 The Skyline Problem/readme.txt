001.cpp (832ms):

A heap is used to maintain the largest height at each x-coordinate. Whenever we found that this height changes, we should push it into the answer vector.

First, we should sort all the vertical line according to their x-coordinate, whether it is at the left of one building and y-coordinate. Then perform the linear scanning for each vertical line. If it is the left line, we should push it to the heap. Otherwise, we should pop it from the heap. 

The deletion of elements in heap is not supported directly in C++. Therefore, I use a vector to mark whether an element is deleted or not.

The time complexity for this solution is O(nlog(n)).