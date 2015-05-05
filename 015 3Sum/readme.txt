001.cpp (66ms):

The k-sum problems can be solved in a similar way with the time complexity of O(n^(k-1)). First, sort the whole array. Then, perform a (k-2)-layer looping to determine (k-2) candidates. At last, conduct a double-ended linear scan to determine the remaining two candidates. Pay attention to the duplicates.
