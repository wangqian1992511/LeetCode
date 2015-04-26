001.cpp (3ms):

Pascal triangle is one of the most efficient way to calculate the combination. Here, we use the rolling array to decrease the space complexity. But actually, for this problem, this operation may not be necessary. Since we should store 32-bit integer in the vector returned. That is to say, the Pascal triangle cannot be more than 40 rows. The time complexity is O(n^2).
