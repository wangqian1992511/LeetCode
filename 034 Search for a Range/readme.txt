001.cpp (12ms):

Combine "binary search" and "divide and conquer" together. If the middle element is not equal to the target value, we perform the binary search. If it is equal to the target value, we can perform the divide and conquer to both sides of this element. Only at most two intervals will be processed at the same time, so the time complexity can still be exactly O(log(n)). The tricky point for me to get an O(log(n)) time complexity, instead of O(nlog(n)), is the instruction "if ((nums[st] == target) && (nums[en] == target))".

For example, if we'd like to search the range for 2 in the array 
{1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3}.

In the first round, we divide the array into two parts:
{1, 2, 2, 2, 2, 2, 2, [2], 2, 2, 2, 2, 2, 2, 3}

We now have two sub-arrays to further perform binary search, in the second round.
{1, 2, 2, [2], 2, 2, 2} [2] {2, 2, 2, [2], 2, 2, 3}

By now, it seems that we have four sub-arrays to deal with. But in fact, notice that we don't need to really search in the two sub-arrays in the middle. This means that the while loop in the binary search will always be performed on at most two sub-arrays. This is how I get an O(log(n)) time complexity instead of O(nlog(n))

{1, 2, 2} [2] {2, 2, 2} [2] {2, 2, 2} [2] {2, 2, 3}
         ---------------------------------
            while loop doesn't run here

002.cpp(12ms):

Use binary search twice to determine the left boundary and the right boundary. Pay attention to the way for determining the middle pointer and the moving pointer when a[m] is equal to target.

003.cpp(12ms):

Or we can simply use the build-in STL.
