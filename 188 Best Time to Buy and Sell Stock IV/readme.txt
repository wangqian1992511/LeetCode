001.cpp (8ms):

DP solution with time complexity of O(n^2). The memory complexity for this solution is O(n). The transfer function is 

buy[i,k] = max{buy[i-1, k], sell[i-1, k - 1] - prices[i]}
sell[i,k] = max{sell[i-1, k], buy[i-1, k] + prices[i]}

A trick point is that when "k >= n/2", we can turn this problem to problem 122. Thus, the time complexity for this case will become O(n). In other case, the time complexity is supposed to be O(kn). But, because this limit to k, the time complexity is reduced to O(n ^ 2).

This solution is also acceptable for problem 123.

002.cpp (8ms)

From the discussion above, we find that it is better to reduce the memory cost by half, though this will not change the memory complexity. From the transfer function, we find that we can make it.
