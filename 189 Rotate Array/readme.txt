001.cpp (28ms):

It is not interesting to solve it with O(n) memory complexity.

This problem reminded me of a similar problem in Wang Jiande's blue book. The e.g. 3.1 in that book proposes a similar scenario. Similarly, in this problem, we can imagine that there are "n" players sitting in a circle and passing the balls to the k-th player clockwisely and continuously. Suppose that "n" is 8, and "k" is 6, then two passing routes may be:

1 - 7 - 5 - 3 - 1 - 7 - ......
2 - 8 - 6 - 4 - 2 - 8 - ......

Four players are involved in each route, because 4 * 6 = 8t, where "t" is an arbitrary integer. Obviously, 4 = 8 / gcd(6, 8). From this example, we can see that gcd(k, n) is always the number of different passing routes. Thus, we derive a solution with O(1) memory complexity.
