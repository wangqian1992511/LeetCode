001.cpp (3ms):

A review of Cantor's Expansion with time complexity of O(n^2). For a permutation {a[n], a[n-1], ..., a[1], a[0]}, we can define:

X = b[n] * n! + b[n-1] * (n-1)! + ... + b[0] * 0!

Here, b[i] is the number of smaller elements than a[i] in {a[0], a[1], ..., a[i-1]}. In the equation above, b[n] can be derived from (X div n!). The whole permutation can be dirived digit by digit.
