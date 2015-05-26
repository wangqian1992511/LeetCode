001.cpp (12ms):

Combine "binary search" and "divide and conquer" together. If the middle element is not equal to the target value, we perform the binary search. If it is equal to the target value, we can perform the divide and conquer to both sides of this element. Only at most two intervals will be processed at the same time, so the time complexity can still be exactly O(log(n)).
