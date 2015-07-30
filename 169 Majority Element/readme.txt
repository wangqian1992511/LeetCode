001.cpp (44ms):

This is a very straightforward solution. Since we know that the majority element will appear for more than [n/2] times, if we sort the whole list of elements, the one in the middle must be the majority element. However, the time complexity of O(nlog(n)) is not optimized.

002.cpp (57ms):

We can use the hash table to count the number of appearance of each number. The time complexity should be O(n). But due to the frequent calling of the unordered_map STL, the actual running time may not be short enough. The disadvantage is that it requires O(n) extra memory.

001.py (64ms):

Randomly pick an element in the array to check if it is the majority element. We can expect two picks are enough.
