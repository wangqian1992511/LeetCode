001.cpp (32ms):

Use the binary search. Notice the fact that as long as we know the median is the k-th element in any array, we can know the number of element smaller than the median in the other array. Keep searching for this "k" in both arrays. The time complexity is O(log(n) + log(m)).
