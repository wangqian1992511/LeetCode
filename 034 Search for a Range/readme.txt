001.cpp (12ms):

Combine "binary search" and "divide and conquer" together. If the middle element is not equal to the target value, we perform the binary search. If it is equal to the target value, we can perform the divide and conquer to both sides of this element. Only at most two intervals will be processed at the same time, so the time complexity can still be exactly O(log(n)).

002.cpp(12ms):

Use binary search twice to determine the left boundary and the right boundary. Pay attention to the way for determining the middle pointer and the moving pointer when a[m] is equal to target.

003.cpp(12ms):

Or we can simply use the build-in STL.
