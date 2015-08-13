001.cpp (214ms):

Use the heap to maintain the cache. When we "set" or "get" a particular key value, we should add or sink it to the deepest level of this heap. We also need to use the STL map to maintain the data in this cache. Since the capacity is limited, a common mistake is ignoring to erase an useless data from the map.

002.cpp (89ms):
001.py (232ms):

The solution mentioned above requires an average time complexity of O(logn) due to the heap updating. Since the cache is based on LRU (least recently used), it may be natural to think of using a priority queue, such as heap at first. However, if we store the whole data structure (the node in a linked list with key and value), instead of only the value in the map, we may use a double linked list to implementation this cache. Since the deletion operation is required, a double linked list with the help of hash can make us "find" and "delete" a node from this list with an average time complexity of O(1).

The common mistake may still be ignoring to erase an useless data from the map or carelessly misoperating the double linked list. Moreover, remember that as long as we do not need to maintain the order of the elements in the hash map, we'd better use "unordered_map", since it is faster.

