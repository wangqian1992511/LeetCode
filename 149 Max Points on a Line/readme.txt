001.cpp (88ms):

The time complexity is O(n^2). Every time, we fix a point and calculate the slope between any other point and this fixed point. Use a hash table to count the number of slops, and use a variable to count the number of points with the same coordinate as this fixed one.