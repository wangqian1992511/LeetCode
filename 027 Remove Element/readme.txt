001.cpp (6ms):

Since there is no requirement on the stability, we can arbitrarily swap any two elements in the array. We check the whole array one element by one. As long as we find an element appeared before, we should delete it by swapping it with the element in the end, and deduce the length of the array by one. Of course, we don't need to really "swap" them. This operation is just like the deletion operation in the heap. The time complexity is O(n).
