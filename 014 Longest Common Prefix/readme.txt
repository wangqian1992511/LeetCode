001.cpp (8ms):

Suppose that there are n strings and there are m characters in the shortest string. The first algorithm cost the time complexity of O(mn). We just check character by character. As long as we find a difference, the checking process can be ended, and the length of the common prefix is determined.

002.cpp (8ms):

We can improve the time complexity by performing the binary search on the length of the longest common prefix. Then the time complexity is O(nlog(m)), if we suppose that the time complexity for string comparasion is O(1). But we should call the "substr" method frequently and I'm not sure about the implementation of string comparasion, the improvement may not be obvious enough. But it is a good practice to try binary search.
