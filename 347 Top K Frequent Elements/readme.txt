001.cpp (36ms):

One unordered map is used as a hash table to record the number of appearance for one give number. One ordered map is used as a BST to record the list of numbers appearing for a certain time, in a descending order. Traverse the BST to extract k numbers. The total time complexity is O(n + klogn).
