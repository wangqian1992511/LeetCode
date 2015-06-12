001.cpp (12ms):

We can analyze one bit first. We'd like to count how many times one appears in this bit. We define three states, "00", "01" and "10", to indicate the remainder of the time of appearance mod 3. Then the K-map to this state transfer table can be defined as following:

A  a  b  na nb
0  0  0  0  0
0  0  1  0  1
0  1  0  1  0
0  1  1  X  X
1  0  0  0  1
1  0  1  1  0
1  1  0  0  0
1  1  1  X  X

Then the k-map can be built for "na".

   00  01  11  10
0  0   0   X   1 
1  0   1   X   0

So "na = A[i] & b | ~A[i] & a" can be derived. A boolean equation for "nb" can be obtained in the same way.
