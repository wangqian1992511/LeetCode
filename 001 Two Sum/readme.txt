001.cpp (16ms):

We use a hash table to store the elements that has already been checked. When we check an element "x", we can look up the hash table to see whether "target - x" has been checked or not. The time complexity is O(n).

It is not interesting to implement a sort and search or search and two-pointer scan algorithm in this problem. The reason is that this problem requires to return the index instead the data, and the time complexity for these kinds of algorithms is O(nlog(n)).
