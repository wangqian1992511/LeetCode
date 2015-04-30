001.cpp (15ms):

Merging two sorted list is a basic operation in merge sort. The time complexity is O(n). To make the whole process easier, we could introduce the super-head. From this problem, we can see that when we are merging two sorted list, there is no need to require extra space. But it is not convenient to swap two elements in a linked list. This is why we would like to use merge sort, instead of quick sort, to sort a linked list, and vice versa for an array.

